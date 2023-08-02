#include "xtp_trader_api.h"
#include "config_fetch.h"
#include <spdlog/spdlog.h>
#include <iostream>

int main() {
    XtpInfo xtp_info;
    bool res = get_xtp_info("./configs/xtp.json", xtp_info);
    if (!res) {
        SPDLOG_INFO("Load config failed...");
        return -1;
    }
    
    XTP::API::TraderApi* pUserApi = XTP::API::TraderApi::CreateTraderApi(xtp_info.client_id, ".", XTP_LOG_LEVEL_DEBUG);
    if (!pUserApi) {
        SPDLOG_INFO("Failed to create trader api, please check input parameter...");
        return -1;
    }

    pUserApi->SubscribePublicTopic(XTP_TERT_QUICK); //只传输登陆后的公有流
    pUserApi->SetSoftwareVersion("1.0.0");          //设置软件版本号
    pUserApi->SetSoftwareKey(xtp_info.key.c_str()); //设置开发key
    pUserApi->SetHeartBeatInterval(10);             //设置心跳检查时间

    
    
    return 0;
}
