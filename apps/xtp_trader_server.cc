#include "xtp_trader_api.h"
#include "xtp_trader.h"
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

    MyTraderSpi* pUserSpi = new MyTraderSpi();
    if(!pUserSpi) {
        SPDLOG_WARN("Failed to create trader spi...");
    }

    pUserApi->RegisterSpi(pUserSpi);
    pUserSpi->SetUserAPI(pUserApi);
    
    uint64_t session_id = pUserApi->Login(xtp_info.td_address.c_str(),
                                          xtp_info.td_port,
                                          xtp_info.user.c_str(),
                                          xtp_info.login_password.c_str(),
                                          XTP_PROTOCOL_TCP);
    
    if(session_id > 0) {
        SPDLOG_INFO("{} login trader front success...", xtp_info.user);
    } else {
        XTPRI* error_info = pUserApi->GetApiLastError();
        SPDLOG_WARN("{} login to server error, error id: {}, error_msg: {}",
                    xtp_info.user,
                    error_info->error_id,
                    error_info->error_msg);
    }
    
    return 0;
}
