#include "xtp_quote.h"
#include <iostream>

using namespace std;

MyQuoteSpi::MyQuoteSpi() {
}

MyQuoteSpi::~MyQuoteSpi() {
}

void MyQuoteSpi::OnDisconnected(int reason) {
}

void MyQuoteSpi::OnQueryAllTickers(XTPQSI* ticker_info, XTPRI *error_info, bool is_last) {
    std::cout << ticker_info->ticker << " : " << ticker_info->ticker_name << std::endl;
}

bool MyQuoteSpi::IsErrorRspInfo(XTPRI *pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	bool bResult = ((pRspInfo) && (pRspInfo->error_id != 0));
	if (bResult)
		cout << "--->>> ErrorID=" << pRspInfo->error_id << ", ErrorMsg=" << pRspInfo->error_msg << endl;
	return bResult;
}

