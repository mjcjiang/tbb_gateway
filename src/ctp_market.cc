#include "ctp_market.h"

void MdHandler::OnFrontConnected() {
    SPDLOG_INFO("Market front mechine connection finish!");
    Semaphore& sem = Semaphore::GetInstance();
    sem.Signal();
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
    
    Semaphore& sem = Semaphore::GetInstance();
    sem.Signal();
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

void MdHandler::set_logging_status(bool status) {
    std::lock_guard<std::mutex> lock_(mutex_);
    islogged_ = status;
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
        Semaphore &sem = Semaphore::GetInstance();
        sem.Signal();
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
        Semaphore &sem = Semaphore::GetInstance();
        sem.Signal();
    }
}
