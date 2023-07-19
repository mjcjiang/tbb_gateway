#include "ctp_market.h"

void MdHandler::OnFrontConnected() {
    SPDLOG_INFO("Market front mechine connection finish!");
    send_signal();
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
