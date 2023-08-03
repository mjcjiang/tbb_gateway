#include "xtp_quote_api.h"
#include "xtp_quote.h"
#include "config_fetch.h"
#include <spdlog/spdlog.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

int main() {
    XtpInfo xtp_info;
    int request_id = 1; 
    bool res = get_xtp_info("./configs/xtp.json", xtp_info);
    if (!res) {
        SPDLOG_INFO("Load config failed...");
        return -1;
    }
    
    XTP::API::QuoteApi* pUserApi = XTP::API::QuoteApi::CreateQuoteApi(xtp_info.client_id, ".", XTP_LOG_LEVEL_DEBUG);
    if (!pUserApi) {
        SPDLOG_INFO("Failed to create quote api, please check input parameter...");
        return -1;
    }
    pUserApi->SetHeartBeatInterval(10);             //设置心跳检查时间

    MyQuoteSpi* pUserSpi = new MyQuoteSpi();
    if(!pUserSpi) {
        SPDLOG_WARN("Failed to create quote spi...");
    }

    pUserApi->RegisterSpi(pUserSpi);
    pUserSpi->SetUserAPI(pUserApi);

    //登陆交易主机前台
    pUserApi->Login(xtp_info.md_address.c_str(),
                    xtp_info.md_port,
                    xtp_info.user.c_str(),
                    xtp_info.login_password.c_str(),
                    XTP_PROTOCOL_TCP);
    
    SPDLOG_INFO("{} login quote front success...", xtp_info.user);

    //查询上交所全量的期权合约
    /*
    XTPQueryOptionAuctionInfoReq auction_req;
    auction_req.market = XTP_MARKET_TYPE::XTP_MKT_SH_A;
    memcpy(auction_req.ticker, "10005647", 8);
    res = pUserApi->QueryOptionAuctionInfo(&auction_req, session_id, request_id);
    if(res != 0) {
        SPDLOG_WARN("QueryOptionAuctionInfo Failed...");
    }
    
    request_id++;
    */
    int q_res = pUserApi->QueryAllTickers(XTP_EXCHANGE_TYPE::XTP_EXCHANGE_SH);
    if (q_res != 0) {
        SPDLOG_WARN("QueryAllTickers Failed...");
    }

    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    return 0;
}
