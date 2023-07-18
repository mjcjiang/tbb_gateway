#include <iostream>
#include <string>
#include <memory>
#include "ThostFtdcMdApi.h"

class MdHandler : public CThostFtdcMdSpi {
public:
    //constructor, need a valid pointer to CThostFtdcMdApi
    MdHandler(CThostFtdcMdApi *pMdApi) : m_Api(pMdApi) {}
    ~MdHandler() {}
private:
    CThostFtdcMdApi *m_Api = nullptr;
    int m_RequestId;
};
