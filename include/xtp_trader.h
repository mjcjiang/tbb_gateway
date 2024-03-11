#pragma once
#include "xtp_trader_api.h"
#include <fstream>

using namespace XTP::API;

class MyTraderSpi : public TraderSpi
{
 public:
	MyTraderSpi();
	~MyTraderSpi();

	virtual void OnDisconnected(uint64_t session_id, int reason);
	virtual void OnQueryOptionAuctionInfo(XTPQueryOptionAuctionInfoRsp *option_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	void SetUserAPI(XTP::API::TraderApi* pApi) { pUserApi = pApi; }
    bool IsErrorRspInfo(XTPRI *pRspInfo);
 private:
	XTP::API::TraderApi* pUserApi;
};
