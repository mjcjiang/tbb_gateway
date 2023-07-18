#include <iostream>
#include <string>
#include <memory>
#include "semaphore.h"
#include "spdlog/spdlog.h"
#include "ThostFtdcMdApi.h"

class MdHandler : public CThostFtdcMdSpi {
public:
    //constructor, need a valid pointer to CThostFtdcMdApi
    MdHandler(CThostFtdcMdApi *pMdApi) : m_Api(pMdApi) {}
    ~MdHandler() {}

    //reload from CThostFtdcMdSpi, when connect to front mechine finished
    virtual void OnFrontConnected() {
        SPDLOG_INFO("Market front mechine connection finish!");
        Semaphore& sem = Semaphore::GetInstance();
        sem.Signal();
    }

    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
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
        
        Semaphore& sem = Semaphore::GetInstance();
        sem.Signal();
    };

  private:
    CThostFtdcMdApi *m_Api = nullptr;
    int m_RequestId;
};
