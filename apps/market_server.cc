#include <string>
#include <csignal>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include "zmq.hpp"
#include "config_fetch.h"
#include "ctp_market.h"
#include "ThostFtdcMdApi.h"
#include "message.h"

void signalHandler(int signal) {
    std::cout << "Ctrl+C signal received. Exiting..." << std::endl;
    exit(signal);
}

int main() {
    std::signal(SIGINT, signalHandler);
    
    AccountInfo acct_info;
    int res = get_account_info("./configs/account.json", acct_info);
    if (res) {
        SPDLOG_ERROR("Failed to fetch account.json");
    }
    
    Semaphore &sem = Semaphore::GetInstance();
    //建立和交易所行情前置机的联系
    CThostFtdcMdApi *pUserMdApi = CThostFtdcMdApi::CreateFtdcMdApi("", false, false);
    MdHandler md_handler(pUserMdApi);
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
    SPDLOG_INFO("Finish login...");

    /*
    std::vector<std::string> insts = {"IO2308-C-4000"};
    md_handler.SubscribeMarketData(insts);
    sem.Wait();
    SPDLOG_INFO("Subscribe finish...");
    */
    
    /*
    md_handler.UnSubscribeMarketData(insts);
    sem.Wait();
    SPDLOG_INFO("Unsubscribe finish...");
    */
    
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::rep);
    socket.bind("tcp://*:5555");
    
    while (true) {
        zmq::message_t request;
        socket.recv(request);

        std::string receivedMsg(static_cast<char*>(request.data()), request.size());
        std::cout << "Received request: " << receivedMsg << std::endl;

        nlohmann::json j = nlohmann::json::parse(receivedMsg);
        if (j.contains("msg_type")) {
            MsgType msg_type = j.at("msg_type").get<MsgType>();
            switch (msg_type) {
            case MsgType::Login: {
                SPDLOG_INFO("Recv login request...");
                std::string resp_msg = "Hello";
                zmq::message_t response(resp_msg.size());
                memcpy(response.data(), resp_msg.data(), resp_msg.size());
                socket.send(response, zmq::send_flags::none);
            } break;
            case MsgType::Logout:
                break;
            case MsgType::Subscribe:
                break;
            case MsgType::Unsubscribe:
                break;
            case MsgType::HeartBeat:
                break;
            default:
                break;
            }
        }
    }
    
    return 0;
}
