#include "ctp_market.h"
#include "date/date.h"
#include "message.h"
#include "custome_time.h"

void MdHandler::OnFrontConnected() {
    SPDLOG_INFO("Market front mechine connection finish!");
    send_signal();
}

void MdHandler::OnHeartBeatWarning(int nTimeLapse) {
    SPDLOG_INFO("{} passed, no message received from front end...", nTimeLapse);
}

void MdHandler::OnFrontDisconnected(int nReason) {
    switch (nReason) {
    case 0x1001:
        SPDLOG_WARN("OnFrontDisconnected, reason: network read failed");
        break;
    case 0x1002:
        SPDLOG_WARN("OnFrontDisconnected, reason: network write failed");
        break;
    case 0x2001:
        SPDLOG_WARN("OnFrontDisconnected, reason: receive heartbeat timeout");
        break;
    case 0x2002:
        SPDLOG_WARN("OnFrontDisconnected, reason: send heartbeat timeout");
        break;
    case 0x2003:
        SPDLOG_WARN("OnFrontDisconnected, reason: recv dataframe error");
        break;
    default:
        SPDLOG_WARN("OnFrontDisconnected, reason: unknow");
        break;
    }
}

void MdHandler::ReqUserLogin(const AccountInfo& account_info) {
    CThostFtdcReqUserLoginField reqUserLogin = {0};
    memcpy(reqUserLogin.BrokerID, account_info.broker_id.c_str(), account_info.broker_id.size());
    memcpy(reqUserLogin.UserID, account_info.account_id.c_str(), account_info.account_id.size());
    memcpy(reqUserLogin.Password, account_info.password.c_str(), account_info.password.size());
    if (get_connect_status()) {
        m_Api->ReqUserLogin(&reqUserLogin, m_RequestId);
        m_RequestId++;
    }
}

//void MdHandler::ReqUserLogout(const std::string &broker_id, const std::string &user_id) {
void MdHandler::ReqUserLogout(const AccountInfo& account_info) {
    CThostFtdcUserLogoutField reqUserLogout = {0};
    memcpy(reqUserLogout.BrokerID, account_info.broker_id.c_str(), account_info.broker_id.size());
    memcpy(reqUserLogout.UserID, account_info.account_id.c_str(), account_info.account_id.size());
    if (get_connect_status()) {
        m_Api->ReqUserLogout(&reqUserLogout, m_RequestId);
        m_RequestId++;
    }
}

void MdHandler::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
                               CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                               bool bIsLast) {
    SPDLOG_INFO("<OnRspUserLogin>");
    if (pRspUserLogin) {
        SPDLOG_INFO("TradingDay: {}", pRspUserLogin->TradingDay);
        SPDLOG_INFO("LoginTime: {}", pRspUserLogin->LoginTime);
        SPDLOG_INFO("BrokerID: {}", pRspUserLogin->BrokerID);
        SPDLOG_INFO("UserID: {}", pRspUserLogin->UserID);
        SPDLOG_INFO("SystemName: {}", pRspUserLogin->SystemName);
        SPDLOG_INFO("MaxOrderRef: {}", pRspUserLogin->MaxOrderRef);
        SPDLOG_INFO("SHFETime: {}", pRspUserLogin->SHFETime);
        SPDLOG_INFO("DCETime: {}", pRspUserLogin->DCETime);
        SPDLOG_INFO("CZCETime: {}", pRspUserLogin->CZCETime);
        SPDLOG_INFO("FFEXTime: {}", pRspUserLogin->FFEXTime);
        SPDLOG_INFO("INETime: {}", pRspUserLogin->INETime);
        SPDLOG_INFO("FrontID: {}", pRspUserLogin->FrontID);
        SPDLOG_INFO("SessionID: {}", pRspUserLogin->SessionID);
    }

    if (pRspInfo) {
        SPDLOG_INFO("ErrorMsg: {}", pRspInfo->ErrorMsg);
        SPDLOG_INFO("ErrorID: {}", pRspInfo->ErrorID);
    }

    SPDLOG_INFO("nRequestID {}", nRequestID);
    SPDLOG_INFO("bIsLast {}", bIsLast);
    SPDLOG_INFO("</OnRspUserLogin>");
    if (pRspInfo->ErrorID != 0) {
        //Failed to login, client do some error processing...
    }

    //用户登陆成功,状态设置
    set_logging_status(true);
    send_signal();
}

void MdHandler::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
    SPDLOG_INFO("<OnRspUserLogout>");
    if (pUserLogout) {
        SPDLOG_INFO("BrokerID: {}", pUserLogout->BrokerID);
        SPDLOG_INFO("UserID: {}", pUserLogout->UserID);
    }

    if (pRspInfo && pRspInfo->ErrorID) {
        SPDLOG_INFO("ErrorMsg: {}", pRspInfo->ErrorMsg);
        SPDLOG_INFO("ErrorID: {}", pRspInfo->ErrorID);
    }

    SPDLOG_INFO("nRequestID {}", nRequestID);
    SPDLOG_INFO("bIsLast {]", bIsLast);
    SPDLOG_INFO("</OnRspUserLogout>");
    send_signal();
}

void MdHandler::SubscribeMarketData(const std::vector<std::string>& instruments) {
    int md_num = 0;
    char **ppInstrumentID = new char*[INSTS_BUFF_SIZE];

    //如果一次订阅太多产品的行情，要将这些产品分批发送请求
    for (int count1 = 0; count1 <= instruments.size() / INSTS_SEND_CHUNCK_SIZE; count1++) {
        if (count1 < instruments.size() / INSTS_SEND_CHUNCK_SIZE) {
            int a = 0;
            for (a; a < INSTS_SEND_CHUNCK_SIZE; a++) {
                ppInstrumentID[a] = const_cast<char *>(instruments.at(md_num).c_str());
                md_num++;
            }

            int result = m_Api->SubscribeMarketData(ppInstrumentID, a);
            if (result == 0) {
                SPDLOG_INFO("market subcribe request 1... send success...");
                for(int i = 0; i < a; i++) {
                    m_Subsmng->initialize_subscribe_table(ppInstrumentID[i]);
                }
            } else {
                SPDLOG_INFO("market subcribe request 1... send failed, error code = {}", result);
            }
        }
        else if (count1 == instruments.size() / INSTS_SEND_CHUNCK_SIZE) {
            int count2 = 0;
            for (count2; count2 < instruments.size() % INSTS_SEND_CHUNCK_SIZE; count2++) {
                ppInstrumentID[count2] = const_cast<char *>(instruments.at(md_num).c_str());
                md_num++;
            }

            int result = m_Api->SubscribeMarketData(ppInstrumentID, count2);
            if (result == 0) {
                SPDLOG_INFO("market subcribe request 2... send success...");
                for(int i = 0; i < count2; i++) {
                    m_Subsmng->initialize_subscribe_table(ppInstrumentID[i]);
                }
            } else {
                SPDLOG_INFO("market subcribe request 2... send failed, error code = {}", result);
            }
        }
    }
}

void MdHandler::UnSubscribeMarketData(const std::vector<std::string>& instruments) {
    int md_num = 0;
    char **ppInstrumentID = new char*[INSTS_BUFF_SIZE];

    //如果一次订阅太多产品的行情，要将这些产品分批发送请求
    for (int count1 = 0; count1 <= instruments.size() / INSTS_SEND_CHUNCK_SIZE; count1++) {
        if (count1 < instruments.size() / INSTS_SEND_CHUNCK_SIZE) {
            int a = 0;
            for (a; a < INSTS_SEND_CHUNCK_SIZE; a++) {
                ppInstrumentID[a] = const_cast<char *>(instruments.at(md_num).c_str());
                md_num++;
            }

            int result = m_Api->UnSubscribeMarketData(ppInstrumentID, a);
            if (result == 0) {
                SPDLOG_INFO("market unsubcribe request 1... send success...");
            } else {
                SPDLOG_INFO("market unsubcribe request 1... send failed, error code = {}", result);
            }
        }
        else if (count1 == instruments.size() / INSTS_SEND_CHUNCK_SIZE) {
            int count2 = 0;
            for (count2; count2 < instruments.size() % INSTS_SEND_CHUNCK_SIZE; count2++) {
                ppInstrumentID[count2] = const_cast<char *>(instruments.at(md_num).c_str());
                md_num++;
            }

            int result = m_Api->UnSubscribeMarketData(ppInstrumentID, count2);
            if (result == 0) {
                SPDLOG_INFO("market unsubcribe request 2... send success...");
            } else {
                SPDLOG_INFO("market unsubcribe request 2... send failed, error code = {}", result);
            }
        }
    }
}

void MdHandler::set_connect_status(bool status) {
    std::lock_guard<std::mutex> lock_(mutex_);
    isFrontConnected_ = status;
}

bool MdHandler::get_connect_status() {
    std::lock_guard<std::mutex> lock_(mutex_);
    return isFrontConnected_;
}

void MdHandler::set_logging_status(bool status) {
    std::lock_guard<std::mutex> lock_(mutex_);
    isLogged_ = status;
}

bool MdHandler::get_logging_status() {
    std::lock_guard<std::mutex> lock_(mutex_);
    return isLogged_;
}

void MdHandler::send_signal() {
    Semaphore& sem = Semaphore::GetInstance();
    sem.Signal();
}

void MdHandler::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument,
                        CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                        bool bIsLast) {
    SPDLOG_INFO("<OnRspSubMarketData>");
    if (pSpecificInstrument) {
        SPDLOG_INFO("InstrumentID {}", pSpecificInstrument->InstrumentID);
    }

	if (pRspInfo && pRspInfo->ErrorID) {
        SPDLOG_ERROR("ErrorMsg {}", pRspInfo->ErrorMsg);
        SPDLOG_ERROR("ErrorID {}", pRspInfo->ErrorID);
    }

    SPDLOG_INFO("nRequestID {}", nRequestID);
    SPDLOG_INFO("bIsLast {}", bIsLast);
    SPDLOG_INFO("</OnRspSubMarketData>");
    if (bIsLast) {
        send_signal();
    }
}

void MdHandler::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument,
    CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    SPDLOG_INFO("<OnRspUnSubMarketData>");
    if (pSpecificInstrument) {
        SPDLOG_INFO("InstrumentID {}", pSpecificInstrument->InstrumentID);
    }

	if (pRspInfo && pRspInfo->ErrorID) {
        SPDLOG_ERROR("ErrorMsg {}", pRspInfo->ErrorMsg);
        SPDLOG_ERROR("ErrorID {}", pRspInfo->ErrorID);
    }

    SPDLOG_INFO("nRequestID {}", nRequestID);
    SPDLOG_INFO("bIsLast {}", bIsLast);
    SPDLOG_INFO("</OnRspUnSubMarketData>");
    if (bIsLast) {
        send_signal();
    }
}

void MdHandler::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) {
    if (pDepthMarketData) {
        TickData tick{};
        memcpy(tick.trading_day, pDepthMarketData->TradingDay, DATE_LEN);
        tick.update_time = TimeProc::get_timestamp_in_milliseconds();
        memcpy(tick.instrument_id, pDepthMarketData->InstrumentID, INSTRUMENT_ID_LEN);
        memcpy(tick.exchange_id, pDepthMarketData->ExchangeID, EXCHANGE_ID_LEN);
        //memcpy(tick.product_id, pDepthMarketData->)
        //std::cout << tick.to_string() << std::endl;
        m_Subsmng->push_message(tick.instrument_id, tick.to_string());
    }

    /*
    if (pDepthMarketData) {
        SPDLOG_INFO("</OnRtnDepthMarketData>");
        SPDLOG_INFO("TradingDay {}", pDepthMarketData->TradingDay);
        SPDLOG_INFO("InstrumentID {}", pDepthMarketData->InstrumentID);
        SPDLOG_INFO("ExchangeID {}", pDepthMarketData->ExchangeID);
        SPDLOG_INFO("ExchangeInstID {}", pDepthMarketData->ExchangeInstID);
        SPDLOG_INFO("UpdateTime {}", pDepthMarketData->UpdateTime);
        SPDLOG_INFO("ActionDay {}", pDepthMarketData->ActionDay);
        SPDLOG_INFO("Volume {}", pDepthMarketData->Volume);
        SPDLOG_INFO("UpdateMillisec {}", pDepthMarketData->UpdateMillisec);
        SPDLOG_INFO("BidVolume1 {}", pDepthMarketData->BidVolume1);
        SPDLOG_INFO("AskVolume1 {}", pDepthMarketData->AskVolume1);
        SPDLOG_INFO("BidVolume2 {}", pDepthMarketData->BidVolume2);
        SPDLOG_INFO("AskVolume2 {}", pDepthMarketData->AskVolume2);
        SPDLOG_INFO("BidVolume3 {}", pDepthMarketData->BidVolume3);
        SPDLOG_INFO("AskVolume3 {}", pDepthMarketData->AskVolume3);
        SPDLOG_INFO("BidVolume4 {}", pDepthMarketData->BidVolume4);
        SPDLOG_INFO("AskVolume4 {}", pDepthMarketData->AskVolume4);
        SPDLOG_INFO("BidVolume5 {}", pDepthMarketData->BidVolume5);
        SPDLOG_INFO("AskVolume5 {}", pDepthMarketData->AskVolume5);
        SPDLOG_INFO("LastPrice {}", (pDepthMarketData->LastPrice > 10000000) ? 0 : pDepthMarketData->LastPrice);
        SPDLOG_INFO("PreSettlementPrice {}", (pDepthMarketData->PreSettlementPrice > 10000000) ? 0 : pDepthMarketData->PreSettlementPrice);
        SPDLOG_INFO("PreClosePrice {}", (pDepthMarketData->PreClosePrice > 10000000) ? 0 : pDepthMarketData->PreClosePrice);
        SPDLOG_INFO("PreOpenInterest {}", (pDepthMarketData->PreOpenInterest > 10000000) ? 0 : pDepthMarketData->PreOpenInterest);
        SPDLOG_INFO("OpenPrice {}", (pDepthMarketData->OpenPrice > 10000000) ? 0 : pDepthMarketData->OpenPrice);
        SPDLOG_INFO("HighestPrice {}", (pDepthMarketData->HighestPrice > 10000000) ? 0 : pDepthMarketData->HighestPrice);
        SPDLOG_INFO("LowestPrice {}", (pDepthMarketData->LowestPrice > 10000000) ? 0 : pDepthMarketData->LowestPrice);
        SPDLOG_INFO("Turnover {}", (pDepthMarketData->Turnover > 10000000) ? 0 : pDepthMarketData->Turnover);
        SPDLOG_INFO("OpenInterest {}", (pDepthMarketData->OpenInterest > 10000000) ? 0 : pDepthMarketData->OpenInterest);
        SPDLOG_INFO("ClosePrice {}", (pDepthMarketData->ClosePrice > 10000000) ? 0 : pDepthMarketData->ClosePrice);
        SPDLOG_INFO("SettlementPrice {}", (pDepthMarketData->SettlementPrice > 10000000) ? 0 : pDepthMarketData->SettlementPrice);
        SPDLOG_INFO("UpperLimitPrice {}", (pDepthMarketData->UpperLimitPrice > 10000000) ? 0 : pDepthMarketData->UpperLimitPrice);
        SPDLOG_INFO("LowerLimitPrice {}", (pDepthMarketData->LowerLimitPrice > 10000000) ? 0 : pDepthMarketData->LowerLimitPrice);
        SPDLOG_INFO("PreDelta {}", (pDepthMarketData->PreDelta > 10000000) ? 0 : pDepthMarketData->PreDelta);
        SPDLOG_INFO("CurrDelta {}", (pDepthMarketData->CurrDelta > 10000000) ? 0 : pDepthMarketData->CurrDelta);
        SPDLOG_INFO("BidPrice1 {}", (pDepthMarketData->BidPrice1 > 10000000) ? 0 : pDepthMarketData->BidPrice1);
        SPDLOG_INFO("AskPrice1 {}", (pDepthMarketData->AskPrice1 > 10000000) ? 0 : pDepthMarketData->AskPrice1);
        SPDLOG_INFO("BidPrice2 {}", (pDepthMarketData->BidPrice2 > 10000000) ? 0 : pDepthMarketData->BidPrice2);
        SPDLOG_INFO("AskPrice2 {}", (pDepthMarketData->AskPrice2 > 10000000) ? 0 : pDepthMarketData->AskPrice2);
        SPDLOG_INFO("BidPrice3 {}", (pDepthMarketData->BidPrice3 > 10000000) ? 0 : pDepthMarketData->BidPrice3);
        SPDLOG_INFO("AskPrice3 {}", (pDepthMarketData->AskPrice3 > 10000000) ? 0 : pDepthMarketData->AskPrice3);
        SPDLOG_INFO("BidPrice4 {}", (pDepthMarketData->BidPrice4 > 10000000) ? 0 : pDepthMarketData->BidPrice4);
        SPDLOG_INFO("AskPrice4 {}", (pDepthMarketData->AskPrice4 > 10000000) ? 0 : pDepthMarketData->AskPrice4);
        SPDLOG_INFO("BidPrice5 {}", (pDepthMarketData->BidPrice5 > 10000000) ? 0 : pDepthMarketData->BidPrice5);
        SPDLOG_INFO("AskPrice5 {}", (pDepthMarketData->AskPrice5 > 10000000) ? 0 : pDepthMarketData->AskPrice5);
        SPDLOG_INFO("AveragePrice {}", (pDepthMarketData->AveragePrice > 10000000) ? 0 : pDepthMarketData->AveragePrice);
        SPDLOG_INFO("</OnRtnDepthMarketData>");
    }
    */
}
