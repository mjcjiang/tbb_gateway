#include <iostream>
#include <string>
#include <memory>
#include "ThostFtdcMdApi.h"

class MdHandler : public CThostFtdcMdSpi {
public:
    //constructor, need a valid pointer to CThostFtdcMdApi
    MdHandler(CThostFtdcMdApi *pMdApi) : m_Api(pMdApi) {}
    ~MdHandler() {}

    //after establish connection to NGTS, do user login
    void OnFrontConnected() {
        CThostFtdcReqUserLoginField login_field;
        login_field.
            //m_api->ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;
    }
  private:
    std::unique_ptr<CThostFtdcMdApi> m_Api;
    int m_RequestId
};
