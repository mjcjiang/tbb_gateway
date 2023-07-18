#include <spdlog/spdlog.h>
#include "config_fetch.h"
#include "ctp_market.h"
#include "ThostFtdcMdApi.h"

int main() {
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
    SPDLOG_INFO("RegisterFront {}", acct_info.md_uri);
    pUserMdApi->Init();
   
    //wait for signal
    SPDLOG_INFO("Wait front connection established...");
    sem.Wait();
    
    SPDLOG_INFO("Start login...");
    CThostFtdcReqUserLoginField reqUserLogin = { 0 };
    memcpy(reqUserLogin.BrokerID, acct_info.broker_id.c_str(), acct_info.broker_id.size()); 
    pUserMdApi->ReqUserLogin(&reqUserLogin, 2);

    sem.Wait();
    SPDLOG_INFO("Finish login...");
    //TODO: start to listen on some port, use zero mq, process user login and subscribe
    
    return 0;
}
