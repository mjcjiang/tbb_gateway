#include <string>
#include <csignal>
#include <spdlog/spdlog.h>
#include "config_fetch.h"
#include "ctp_market.h"
#include "ThostFtdcMdApi.h"

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
    CThostFtdcMdApi *pUserMdApi = CThostFtdcMdApi::CreateFtdcMdApi("", false, false);
    MdHandler md_handler(pUserMdApi);

    pUserMdApi->RegisterSpi(&md_handler);
    pUserMdApi->RegisterFront(const_cast<char *>(acct_info.md_uri.c_str()));
    pUserMdApi->Init();
    
    SPDLOG_INFO("Wait front connection established...");
    sem.Wait();
    md_handler.set_connect_status(true);

    SPDLOG_INFO("Start login...");
    md_handler.ReqUserLogin(acct_info);
    sem.Wait();
    SPDLOG_INFO("Finish login...");

    /*
    SPDLOG_INFO("Start logout...");
    md_handler.ReqUserLogout(acct_info);
    sem.Wait();
    SPDLOG_INFO("Finish logout...");
    */
    
    // TODO: start to listen on some port, use zeromq, process user login and
    // subscribe
    std::vector<std::string> insts = {"IO2308-C-4000"};
    md_handler.SubscribeMarketData(insts);
    sem.Wait();
    SPDLOG_INFO("Subscribe finish...");
    
    /*
    md_handler.UnSubscribeMarketData(insts);
    sem.Wait();
    SPDLOG_INFO("Unsubscribe finish...");
    */

    while (true) {
        // Your program logic here
    }
    
    return 0;
}
