/**
 * @file config_fetch.h
 * @brief read system config from json file(s)
 *
 * As the running system need some configs to work, we store
 * all the configs in json files. This this the interface to
 * read or write this json files.
 *
 * @date 2023-07-18
 */

#ifndef CTP_MARKET_H
#define CTP_MARKET_H

#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

#include "semaphore.h"
#include "spdlog/spdlog.h"
#include "config_fetch.h"
#include "ThostFtdcMdApi.h"
#include "subscriber_manager.h"

constexpr int INSTS_BUFF_SIZE = 60000;           //限制最多发送产品个数
constexpr int INSTS_SEND_CHUNCK_SIZE = 500;      //限制最大的订阅单位

class MdHandler : public CThostFtdcMdSpi {
public:
    //constructor, need a valid pointer to CThostFtdcMdApi
    MdHandler(CThostFtdcMdApi *pMdApi, SubscriberManager *pSubsMng) : m_Api(pMdApi), m_Subsmng(pSubsMng) {}

    ~MdHandler() {}

    //reload from CThostFtdcMdSpi, when connect to front mechine finished
    virtual void OnFrontConnected();

    //reload from CThostFtdcMdSpi, when timeout/2 passed, no front message recved
    virtual void OnHeartBeatWarning(int nTimeLapse);
    
    //reload from CThostFtdcMdSpi, when disconnect from front mechine
    virtual void OnFrontDisconnected(int nReason);

    //request login
    void ReqUserLogin(const AccountInfo& account_info);

    //request logout
    void ReqUserLogout(const AccountInfo& account_info);
    
    //reload from CThostFtdcMdSpi, when user login replyed
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    //reload from CThostFtdcMdSpi, when user logout replyed
    virtual void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

    //subscribe market data of multiple instruments
    void SubscribeMarketData(const std::vector<std::string>& instruments);

    //unsubscribe market data of multiple instruments
    void UnSubscribeMarketData(const std::vector<std::string>& instruments);

    //the callback when subscribe market data
    virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    //the callback when unsubscribe market data
    virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    //the callback when market data comming
    virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

    //set frontend connect status
    void set_connect_status(bool status);

    //get frontend connect status
    bool get_connect_status();
    
    //set logging status
    void set_logging_status(bool status);

    //get logging status
    bool get_logging_status();

    //signal send(use semaphore)
    void send_signal();
private:
    CThostFtdcMdApi *m_Api = nullptr;
    SubscriberManager *m_Subsmng = nullptr;
    bool isFrontConnected_ = false;
    bool isLogged_ = false;
    std::mutex mutex_;
    int m_RequestId = 1;
};

#endif // CTP_MARKET_H
