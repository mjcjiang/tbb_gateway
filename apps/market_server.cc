#include <string>
#include <csignal>
#include <thread>
#include <chrono>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include "zmq.hpp"
#include "config_fetch.h"
#include "ctp_market.h"
#include "ThostFtdcMdApi.h"
#include "message.h"
#include "error_table.h"
#include "subscriber_manager.h"
#include "custome_logger.h"

zmq::context_t inproc_context(1);

void signalHandler(int signal) {
    std::cout << "Ctrl+C signal received. Exiting..." << std::endl;
    exit(signal);
}

void heartbeat_check(SubscriberManager *pManager) {
    while (true) {
        pManager->check_user_alive();
        pManager->tell_subscriber_info();
        pManager->save_socket_and_subscribe_table();
        std::this_thread::sleep_for(std::chrono::seconds(CLIENT_CHECK_INTERVAL));
    }
}

void market_thread_func(SubscriberManager *pManager, AccountInfo *pAcctInfo) {
    zmq::socket_t reciever(inproc_context, zmq::socket_type::pull);
    reciever.connect("inproc://thread_channel");
    
    while (true) {
        //获取信号量单例
        Semaphore &sem = Semaphore::GetInstance();

        //建立和交易所行情前置机的联系
        CThostFtdcMdApi *pUserMdApi = CThostFtdcMdApi::CreateFtdcMdApi("", false, false);
        MdHandler md_handler(pUserMdApi, pManager, &inproc_context);
        pUserMdApi->RegisterSpi(&md_handler);
        pUserMdApi->RegisterFront(const_cast<char *>(pAcctInfo->md_uri.c_str()));
        pUserMdApi->Init();
    
        sem.Wait();
        md_handler.set_connect_status(true);
        SPDLOG_INFO("Front mechine connection established...");

        //登陆行情前置机
        SPDLOG_INFO("Start login...");
        md_handler.ReqUserLogin(*pAcctInfo);
        sem.Wait();
        md_handler.set_logging_status(true);
        SPDLOG_INFO("Finish login...");

        pManager->load_socket_and_subscribe_table();

        //行情订阅
        std::vector<std::string> insts = {"IF2308"};
        md_handler.SubscribeMarketData(insts);
        
        //等待会话断开的通知，否则一直堵塞在这个地方
        zmq::message_t message;
        zmq::recv_result_t res = reciever.recv(message, zmq::recv_flags::none);
        if (res.has_value()) {
            SPDLOG_WARN("Session Failed, relogin and subscribe...");
        }
    }
}

void send_response(zmq::socket_t& socket, const std::string &msg) {
    zmq::message_t rsp_msg(msg.size());
    memcpy(rsp_msg.data(), msg.data(), msg.size());
    socket.send(rsp_msg, zmq::send_flags::none);
}

int main() {
    std::signal(SIGINT, signalHandler);
    
    AccountInfo acct_info;
    int res = get_account_info("./configs/account.json", acct_info);
    if (res) {
        SPDLOG_ERROR("Failed to fetch account.json");
    }
    
    //落日志设置
    set_default_daily_logger("market_server");

    //初始化订阅者管理器
    SubscriberManager subs_manager;

    //启动心跳检查线程
    std::thread hb_check(heartbeat_check, &subs_manager);

    //启动行情接收线程
    std::thread market_thread(market_thread_func, &subs_manager, &acct_info);
    
    //处理客户端消息
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::rep);
    socket.bind("tcp://*:5566"); 
    while (true) {
        zmq::message_t request;
        zmq::recv_result_t res = socket.recv(request, zmq::recv_flags::none);
        std::string receivedMsg(static_cast<char*>(request.data()), request.size());
        nlohmann::json j = nlohmann::json::parse(receivedMsg);
        
        if (j.contains("msg_type")) {
            MsgType msg_type = j.at("msg_type").get<MsgType>();
            ErrorCode code = ErrorCode::NO_ERROR;
            std::string rsp_str;
            
            switch (msg_type) {
            case MsgType::Login:
                {
                    LoginMsg login_msg;
                    std::string push_addr = "";
                    
                    bool parse_res = LoginMsg::from_message(receivedMsg, login_msg);
                    if (parse_res) {
                        subs_manager.set_live_stamp(login_msg.user_name);
                        code = subs_manager.add_user(login_msg.user_name);
                        if (code == ErrorCode::NO_ERROR) {
                            subs_manager.get_sock_address(login_msg.user_name, push_addr);
                        }
                    } else {
                        code = ErrorCode::PARSE_FAIL;
                    }

                    rsp_str = LoginRspMsg::gen_login_rsp_msg(code, error_table[code], push_addr);
                    send_response(socket, rsp_str);
                }
                break;
            case MsgType::Logout:
                {
                    LogoutMsg logout_msg;
                    bool parse_res = LogoutMsg::from_message(receivedMsg, logout_msg);
                    if (parse_res) {
                        subs_manager.set_live_stamp(logout_msg.user_name);
                        code = subs_manager.delete_user(logout_msg.user_name);
                    } else {
                        code = ErrorCode::PARSE_FAIL;
                    }

                    rsp_str = LogoutRspMsg::gen_logout_rsp_msg(code, error_table[code]);
                    send_response(socket, rsp_str);
                }
                break;
            case MsgType::Subscribe:
                {
                    SubscribeMsg subs_msg;
                    bool parse_res = SubscribeMsg::from_message(receivedMsg, subs_msg);
                    if (parse_res) {
                        subs_manager.set_live_stamp(subs_msg.user_name);
                        code = subs_manager.process_subscribe(subs_msg.user_name, subs_msg.insts);
                    } else {
                        code = ErrorCode::PARSE_FAIL;
                    }

                    rsp_str = SubscribeRspMsg::gen_subscribe_rsp_msg(code, error_table[code]);
                    send_response(socket, rsp_str);
                }
                break;
            case MsgType::Unsubscribe:
                {
                    UnsubscribeMsg unsubs_msg;
                    bool parse_res = UnsubscribeMsg::from_message(receivedMsg, unsubs_msg);
                    if (parse_res) {
                        subs_manager.set_live_stamp(unsubs_msg.user_name);
                        code = subs_manager.process_unsubscribe(unsubs_msg.user_name, unsubs_msg.insts);
                    } else {
                        code = ErrorCode::PARSE_FAIL;
                    }

                    rsp_str = UnsubscribeRspMsg::gen_unsubscribe_rsp_msg(code, error_table[code]);
                    send_response(socket, rsp_str);
                }
                break;
            case MsgType::HeartBeat:
                {
                    HeartbeatMsg hb_msg;
                    bool parse_res = HeartbeatMsg::from_message(receivedMsg, hb_msg);
                    if (parse_res) {
                        code = subs_manager.set_live_stamp(hb_msg.user_name);
                    } else {
                        code = ErrorCode::PARSE_FAIL;
                    }
                    
                    rsp_str = HeartbeatRspMsg::gen_heartbeat_rsp_msg(code, error_table[code]);
                    send_response(socket, rsp_str);

                    SPDLOG_INFO("Send heartbeat rsp back to client {} in {}",
                                hb_msg.user_name,
                                TimeProc::get_timestamp_in_seconds());
                }
                break;
            default:
                SPDLOG_WARN("Unknown message type: {}", static_cast<int>(msg_type));
                break;
            }
        }
    }

    hb_check.join();
    market_thread.join();
    return 0;
}
