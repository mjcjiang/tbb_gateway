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

void signalHandler(int signal) {
    std::cout << "Ctrl+C signal received. Exiting..." << std::endl;
    exit(signal);
}

void heartbeat_check(SubscriberManager *pManager) {
    while (true) {
        
    }
}

int main() {
    std::signal(SIGINT, signalHandler);
    
    AccountInfo acct_info;
    int res = get_account_info("./configs/account.json", acct_info);
    if (res) {
        SPDLOG_ERROR("Failed to fetch account.json");
    }

    //初始化订阅者管理器
    SubscriberManager subs_manager;

    //启动心跳检查线程
    std::thread hb_check(heartbeat_check, &subs_manager);
    
    Semaphore &sem = Semaphore::GetInstance();
    //建立和交易所行情前置机的联系
    CThostFtdcMdApi *pUserMdApi = CThostFtdcMdApi::CreateFtdcMdApi("", false, false);
    MdHandler md_handler(pUserMdApi, &subs_manager);
    pUserMdApi->RegisterSpi(&md_handler);
    pUserMdApi->RegisterFront(const_cast<char *>(acct_info.md_uri.c_str()));
    pUserMdApi->Init();
    
    sem.Wait();
    md_handler.set_connect_status(true);
    SPDLOG_INFO("Front mechine connection established...");

    //登陆行情前置机
    SPDLOG_INFO("Start login...");
    md_handler.ReqUserLogin(acct_info);
    sem.Wait();
    md_handler.set_logging_status(true);
    SPDLOG_INFO("Finish login...");
   
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
            case MsgType::Logout:
                {
                    //登陆和登出消息处理
                    auto user_name = j.at("user_name").get<std::string>();
                    auto user_password = j.at("user_passwd").get<std::string>();

                    //TODO: 账号合法性校验
                    if (msg_type == MsgType::Login) {
                        code = subs_manager.add_user(user_name);
                        if (code == ErrorCode::NO_ERROR) {
                            //成功添加用户
                            std::string push_address;
                            subs_manager.get_sock_address(user_name, push_address);
                            rsp_str = LoginRspMsg::gen_login_rsp_msg(code, error_table[code], push_address);
                        } else {
                            //添加用户失败
                            rsp_str = LoginRspMsg::gen_login_rsp_msg(code, error_table[code], "");
                        }
                    } else {
                        code = subs_manager.delete_user(user_name);
                        rsp_str = LogoutRspMsg::gen_logout_rsp_msg(code, error_table[code]);
                    }

                    zmq::message_t rsp_msg(rsp_str.size());
                    memcpy(rsp_msg.data(), rsp_str.data(), rsp_str.size());
                    socket.send(rsp_msg, zmq::send_flags::none);          
            } break;
            case MsgType::Subscribe:
            case MsgType::Unsubscribe:
                {
                    //订阅和取消订阅消息处理
                    auto user_name = j.at("user_name").get<std::string>();
                    auto user_password = j.at("user_passwd").get<std::string>();

                    std::vector<std::string> insts;
                    for(auto& inst : j.at("insts")) {
                        insts.push_back(inst.get<std::string>());
                    }    
                    
                    //TODO: 账号合法性校验
                    if (msg_type == MsgType::Subscribe) {
                        code = subs_manager.process_subscribe(user_name, insts);
                        rsp_str = SusbcribeRspMsg::gen_subscribe_rsp_msg(code, error_table[code]);
                    } else {
                        code = subs_manager.process_unsubscribe(user_name, insts);
                        rsp_str = UnsusbcribeRspMsg::gen_unsubscribe_rsp_msg(code, error_table[code]);
                    }

                    zmq::message_t rsp_msg(rsp_str.size());
                    memcpy(rsp_msg.data(), rsp_str.data(), rsp_str.size());
                    socket.send(rsp_msg, zmq::send_flags::none);
                }
                break;
            case MsgType::HeartBeat:
                {
                    //心跳消息处理
                    auto user_name = j.at("user_name").get<std::string>();
                    code = subs_manager.set_live_stamp(user_name);
                    rsp_str = HeartbeatRspMsg::gen_heartbeat_rsp_msg(code, error_table[code]);

                    zmq::message_t rsp_msg(rsp_str.size());
                    memcpy(rsp_msg.data(), rsp_str.data(), rsp_str.size());
                    socket.send(rsp_msg, zmq::send_flags::none);
                }
                break;
            default:
                break;
            }
        } else {
            //deal with wrong type messages
        }
    }

    hb_check.join();
    return 0;
}
