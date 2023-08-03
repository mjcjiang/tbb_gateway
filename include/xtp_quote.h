#pragma once
#include "xtp_quote_api.h"

using namespace XTP::API;

class MyQuoteSpi : public QuoteSpi
{
 public:
	MyQuoteSpi();
	~MyQuoteSpi();

	virtual void OnDisconnected(int reason);
    virtual void OnQueryAllTickers(XTPQSI* ticker_info, XTPRI *error_info, bool is_last);

	void SetUserAPI(XTP::API::QuoteApi* pApi) { pQuoteApi = pApi; }
    bool IsErrorRspInfo(XTPRI *pRspInfo);
 private:
	XTP::API::QuoteApi* pQuoteApi;
};
