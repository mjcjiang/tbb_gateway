#include "xtp_trader.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#ifndef _WIN32
#include <sys/time.h>
#include <unistd.h>
#else
#include <windows.h>
#endif
#include <sstream>
#include <map>

using namespace std;


MyTraderSpi::MyTraderSpi()
{
}

MyTraderSpi::~MyTraderSpi()
{
}

void MyTraderSpi::OnDisconnected(uint64_t session_id, int reason)
{
}

void MyTraderSpi::OnQueryOptionAuctionInfo(XTPQueryOptionAuctionInfoRsp * option_info, XTPRI * error_info, int request_id, bool is_last, uint64_t session_id)
{
    
}

bool MyTraderSpi::IsErrorRspInfo(XTPRI *pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	bool bResult = ((pRspInfo) && (pRspInfo->error_id != 0));
	if (bResult)
		cout << "--->>> ErrorID=" << pRspInfo->error_id << ", ErrorMsg=" << pRspInfo->error_msg << endl;
	return bResult;
}
