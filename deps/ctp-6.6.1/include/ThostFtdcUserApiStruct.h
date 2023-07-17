
#if !defined(THOST_FTDCSTRUCT_H)
#define THOST_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "ThostFtdcUserApiDataType.h"

struct CThostFtdcDisseminationField
{
	TThostFtdcSequenceSeriesType	SequenceSeries;
	TThostFtdcSequenceNoType	SequenceNo;
};

struct CThostFtdcReqUserLoginField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcPasswordType	Password;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcProductInfoType	InterfaceProductInfo;
	TThostFtdcProtocolInfoType	ProtocolInfo;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcPasswordType	OneTimePassword;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcLoginRemarkType	LoginRemark;
	TThostFtdcIPPortType	ClientIPPort;
	TThostFtdcIPAddressType	ClientIPAddress;
};

struct CThostFtdcRspUserLoginField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcTimeType	LoginTime;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcSystemNameType	SystemName;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcOrderRefType	MaxOrderRef;
	TThostFtdcTimeType	SHFETime;
	TThostFtdcTimeType	DCETime;
	TThostFtdcTimeType	CZCETime;
	TThostFtdcTimeType	FFEXTime;
	TThostFtdcTimeType	INETime;
};

struct CThostFtdcUserLogoutField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
};

struct CThostFtdcForceUserLogoutField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
};

struct CThostFtdcReqAuthenticateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcAuthCodeType	AuthCode;
	TThostFtdcAppIDType	AppID;
};

struct CThostFtdcRspAuthenticateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcAppIDType	AppID;
	TThostFtdcAppTypeType	AppType;
};

struct CThostFtdcAuthenticationInfoField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcAuthInfoType	AuthInfo;
	TThostFtdcBoolType	IsResult;
	TThostFtdcAppIDType	AppID;
	TThostFtdcAppTypeType	AppType;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcIPAddressType	ClientIPAddress;
};

struct CThostFtdcRspUserLogin2Field
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcTimeType	LoginTime;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcSystemNameType	SystemName;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcOrderRefType	MaxOrderRef;
	TThostFtdcTimeType	SHFETime;
	TThostFtdcTimeType	DCETime;
	TThostFtdcTimeType	CZCETime;
	TThostFtdcTimeType	FFEXTime;
	TThostFtdcTimeType	INETime;
	TThostFtdcRandomStringType	RandomString;
};

struct CThostFtdcTransferHeaderField
{
	TThostFtdcVersionType	Version;
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcTradeSerialType	TradeSerial;
	TThostFtdcFutureIDType	FutureID;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBrchID;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcRecordNumType	RecordNum;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcRequestIDType	RequestID;
};

struct CThostFtdcTransferBankToFutureReqField
{
	TThostFtdcAccountIDType	FutureAccount;
	TThostFtdcFuturePwdFlagType	FuturePwdFlag;
	TThostFtdcFutureAccPwdType	FutureAccPwd;
	TThostFtdcMoneyType	TradeAmt;
	TThostFtdcMoneyType	CustFee;
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

struct CThostFtdcTransferBankToFutureRspField
{
	TThostFtdcRetCodeType	RetCode;
	TThostFtdcRetInfoType	RetInfo;
	TThostFtdcAccountIDType	FutureAccount;
	TThostFtdcMoneyType	TradeAmt;
	TThostFtdcMoneyType	CustFee;
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

struct CThostFtdcTransferFutureToBankReqField
{
	TThostFtdcAccountIDType	FutureAccount;
	TThostFtdcFuturePwdFlagType	FuturePwdFlag;
	TThostFtdcFutureAccPwdType	FutureAccPwd;
	TThostFtdcMoneyType	TradeAmt;
	TThostFtdcMoneyType	CustFee;
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

struct CThostFtdcTransferFutureToBankRspField
{
	TThostFtdcRetCodeType	RetCode;
	TThostFtdcRetInfoType	RetInfo;
	TThostFtdcAccountIDType	FutureAccount;
	TThostFtdcMoneyType	TradeAmt;
	TThostFtdcMoneyType	CustFee;
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

struct CThostFtdcTransferQryBankReqField
{
	TThostFtdcAccountIDType	FutureAccount;
	TThostFtdcFuturePwdFlagType	FuturePwdFlag;
	TThostFtdcFutureAccPwdType	FutureAccPwd;
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

struct CThostFtdcTransferQryBankRspField
{
	TThostFtdcRetCodeType	RetCode;
	TThostFtdcRetInfoType	RetInfo;
	TThostFtdcAccountIDType	FutureAccount;
	TThostFtdcMoneyType	TradeAmt;
	TThostFtdcMoneyType	UseAmt;
	TThostFtdcMoneyType	FetchAmt;
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

struct CThostFtdcTransferQryDetailReqField
{
	TThostFtdcAccountIDType	FutureAccount;
};

struct CThostFtdcTransferQryDetailRspField
{
	TThostFtdcDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcTradeSerialNoType	FutureSerial;
	TThostFtdcFutureIDType	FutureID;
	TThostFtdcFutureAccountType	FutureAccount;
	TThostFtdcTradeSerialNoType	BankSerial;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBrchID;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcCertCodeType	CertCode;
	TThostFtdcCurrencyCodeType	CurrencyCode;
	TThostFtdcMoneyType	TxAmount;
	TThostFtdcTransferValidFlagType	Flag;
};

struct CThostFtdcRspInfoField
{
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
};

struct CThostFtdcExchangeField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcExchangeNameType	ExchangeName;
	TThostFtdcExchangePropertyType	ExchangeProperty;
};

struct CThostFtdcProductField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcProductNameType	ProductName;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcProductClassType	ProductClass;
	TThostFtdcVolumeMultipleType	VolumeMultiple;
	TThostFtdcPriceType	PriceTick;
	TThostFtdcVolumeType	MaxMarketOrderVolume;
	TThostFtdcVolumeType	MinMarketOrderVolume;
	TThostFtdcVolumeType	MaxLimitOrderVolume;
	TThostFtdcVolumeType	MinLimitOrderVolume;
	TThostFtdcPositionTypeType	PositionType;
	TThostFtdcPositionDateTypeType	PositionDateType;
	TThostFtdcCloseDealTypeType	CloseDealType;
	TThostFtdcCurrencyIDType	TradeCurrencyID;
	TThostFtdcMortgageFundUseRangeType	MortgageFundUseRange;
	TThostFtdcOldInstrumentIDType	reserve2;
	TThostFtdcUnderlyingMultipleType	UnderlyingMultiple;
	TThostFtdcInstrumentIDType	ProductID;
	TThostFtdcInstrumentIDType	ExchangeProductID;
};

struct CThostFtdcInstrumentField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentNameType	InstrumentName;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcOldInstrumentIDType	reserve3;
	TThostFtdcProductClassType	ProductClass;
	TThostFtdcYearType	DeliveryYear;
	TThostFtdcMonthType	DeliveryMonth;
	TThostFtdcVolumeType	MaxMarketOrderVolume;
	TThostFtdcVolumeType	MinMarketOrderVolume;
	TThostFtdcVolumeType	MaxLimitOrderVolume;
	TThostFtdcVolumeType	MinLimitOrderVolume;
	TThostFtdcVolumeMultipleType	VolumeMultiple;
	TThostFtdcPriceType	PriceTick;
	TThostFtdcDateType	CreateDate;
	TThostFtdcDateType	OpenDate;
	TThostFtdcDateType	ExpireDate;
	TThostFtdcDateType	StartDelivDate;
	TThostFtdcDateType	EndDelivDate;
	TThostFtdcInstLifePhaseType	InstLifePhase;
	TThostFtdcBoolType	IsTrading;
	TThostFtdcPositionTypeType	PositionType;
	TThostFtdcPositionDateTypeType	PositionDateType;
	TThostFtdcRatioType	LongMarginRatio;
	TThostFtdcRatioType	ShortMarginRatio;
	TThostFtdcMaxMarginSideAlgorithmType	MaxMarginSideAlgorithm;
	TThostFtdcOldInstrumentIDType	reserve4;
	TThostFtdcPriceType	StrikePrice;
	TThostFtdcOptionsTypeType	OptionsType;
	TThostFtdcUnderlyingMultipleType	UnderlyingMultiple;
	TThostFtdcCombinationTypeType	CombinationType;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcInstrumentIDType	ProductID;
	TThostFtdcInstrumentIDType	UnderlyingInstrID;
};

struct CThostFtdcBrokerField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcBrokerAbbrType	BrokerAbbr;
	TThostFtdcBrokerNameType	BrokerName;
	TThostFtdcBoolType	IsActive;
};

struct CThostFtdcTraderField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcPasswordType	Password;
	TThostFtdcInstallCountType	InstallCount;
	TThostFtdcBrokerIDType	BrokerID;
};

struct CThostFtdcInvestorField
{
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorGroupID;
	TThostFtdcPartyNameType	InvestorName;
	TThostFtdcIdCardTypeType	IdentifiedCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcBoolType	IsActive;
	TThostFtdcTelephoneType	Telephone;
	TThostFtdcAddressType	Address;
	TThostFtdcDateType	OpenDate;
	TThostFtdcMobileType	Mobile;
	TThostFtdcInvestorIDType	CommModelID;
	TThostFtdcInvestorIDType	MarginModelID;
};

struct CThostFtdcTradingCodeField
{
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBoolType	IsActive;
	TThostFtdcClientIDTypeType	ClientIDType;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcBizTypeType	BizType;
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

struct CThostFtdcPartBrokerField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcBoolType	IsActive;
};

struct CThostFtdcSuperUserField
{
	TThostFtdcUserIDType	UserID;
	TThostFtdcUserNameType	UserName;
	TThostFtdcPasswordType	Password;
	TThostFtdcBoolType	IsActive;
};

struct CThostFtdcSuperUserFunctionField
{
	TThostFtdcUserIDType	UserID;
	TThostFtdcFunctionCodeType	FunctionCode;
};

struct CThostFtdcInvestorGroupField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorGroupID;
	TThostFtdcInvestorGroupNameType	InvestorGroupName;
};

struct CThostFtdcTradingAccountField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcMoneyType	PreMortgage;
	TThostFtdcMoneyType	PreCredit;
	TThostFtdcMoneyType	PreDeposit;
	TThostFtdcMoneyType	PreBalance;
	TThostFtdcMoneyType	PreMargin;
	TThostFtdcMoneyType	InterestBase;
	TThostFtdcMoneyType	Interest;
	TThostFtdcMoneyType	Deposit;
	TThostFtdcMoneyType	Withdraw;
	TThostFtdcMoneyType	FrozenMargin;
	TThostFtdcMoneyType	FrozenCash;
	TThostFtdcMoneyType	FrozenCommission;
	TThostFtdcMoneyType	CurrMargin;
	TThostFtdcMoneyType	CashIn;
	TThostFtdcMoneyType	Commission;
	TThostFtdcMoneyType	CloseProfit;
	TThostFtdcMoneyType	PositionProfit;
	TThostFtdcMoneyType	Balance;
	TThostFtdcMoneyType	Available;
	TThostFtdcMoneyType	WithdrawQuota;
	TThostFtdcMoneyType	Reserve;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcMoneyType	Credit;
	TThostFtdcMoneyType	Mortgage;
	TThostFtdcMoneyType	ExchangeMargin;
	TThostFtdcMoneyType	DeliveryMargin;
	TThostFtdcMoneyType	ExchangeDeliveryMargin;
	TThostFtdcMoneyType	ReserveBalance;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcMoneyType	PreFundMortgageIn;
	TThostFtdcMoneyType	PreFundMortgageOut;
	TThostFtdcMoneyType	FundMortgageIn;
	TThostFtdcMoneyType	FundMortgageOut;
	TThostFtdcMoneyType	FundMortgageAvailable;
	TThostFtdcMoneyType	MortgageableFund;
	TThostFtdcMoneyType	SpecProductMargin;
	TThostFtdcMoneyType	SpecProductFrozenMargin;
	TThostFtdcMoneyType	SpecProductCommission;
	TThostFtdcMoneyType	SpecProductFrozenCommission;
	TThostFtdcMoneyType	SpecProductPositionProfit;
	TThostFtdcMoneyType	SpecProductCloseProfit;
	TThostFtdcMoneyType	SpecProductPositionProfitByAlg;
	TThostFtdcMoneyType	SpecProductExchangeMargin;
	TThostFtdcBizTypeType	BizType;
	TThostFtdcMoneyType	FrozenSwap;
	TThostFtdcMoneyType	RemainSwap;
};

struct CThostFtdcInvestorPositionField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcPosiDirectionType	PosiDirection;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcPositionDateType	PositionDate;
	TThostFtdcVolumeType	YdPosition;
	TThostFtdcVolumeType	Position;
	TThostFtdcVolumeType	LongFrozen;
	TThostFtdcVolumeType	ShortFrozen;
	TThostFtdcMoneyType	LongFrozenAmount;
	TThostFtdcMoneyType	ShortFrozenAmount;
	TThostFtdcVolumeType	OpenVolume;
	TThostFtdcVolumeType	CloseVolume;
	TThostFtdcMoneyType	OpenAmount;
	TThostFtdcMoneyType	CloseAmount;
	TThostFtdcMoneyType	PositionCost;
	TThostFtdcMoneyType	PreMargin;
	TThostFtdcMoneyType	UseMargin;
	TThostFtdcMoneyType	FrozenMargin;
	TThostFtdcMoneyType	FrozenCash;
	TThostFtdcMoneyType	FrozenCommission;
	TThostFtdcMoneyType	CashIn;
	TThostFtdcMoneyType	Commission;
	TThostFtdcMoneyType	CloseProfit;
	TThostFtdcMoneyType	PositionProfit;
	TThostFtdcPriceType	PreSettlementPrice;
	TThostFtdcPriceType	SettlementPrice;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcMoneyType	OpenCost;
	TThostFtdcMoneyType	ExchangeMargin;
	TThostFtdcVolumeType	CombPosition;
	TThostFtdcVolumeType	CombLongFrozen;
	TThostFtdcVolumeType	CombShortFrozen;
	TThostFtdcMoneyType	CloseProfitByDate;
	TThostFtdcMoneyType	CloseProfitByTrade;
	TThostFtdcVolumeType	TodayPosition;
	TThostFtdcRatioType	MarginRateByMoney;
	TThostFtdcRatioType	MarginRateByVolume;
	TThostFtdcVolumeType	StrikeFrozen;
	TThostFtdcMoneyType	StrikeFrozenAmount;
	TThostFtdcVolumeType	AbandonFrozen;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcVolumeType	YdStrikeFrozen;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcMoneyType	PositionCostOffset;
	TThostFtdcVolumeType	TasPosition;
	TThostFtdcMoneyType	TasPositionCost;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcInstrumentMarginRateField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcRatioType	LongMarginRatioByMoney;
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	TThostFtdcBoolType	IsRelative;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcInstrumentCommissionRateField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcRatioType	OpenRatioByMoney;
	TThostFtdcRatioType	OpenRatioByVolume;
	TThostFtdcRatioType	CloseRatioByMoney;
	TThostFtdcRatioType	CloseRatioByVolume;
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcBizTypeType	BizType;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcDepthMarketDataField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcPriceType	LastPrice;
	TThostFtdcPriceType	PreSettlementPrice;
	TThostFtdcPriceType	PreClosePrice;
	TThostFtdcLargeVolumeType	PreOpenInterest;
	TThostFtdcPriceType	OpenPrice;
	TThostFtdcPriceType	HighestPrice;
	TThostFtdcPriceType	LowestPrice;
	TThostFtdcVolumeType	Volume;
	TThostFtdcMoneyType	Turnover;
	TThostFtdcLargeVolumeType	OpenInterest;
	TThostFtdcPriceType	ClosePrice;
	TThostFtdcPriceType	SettlementPrice;
	TThostFtdcPriceType	UpperLimitPrice;
	TThostFtdcPriceType	LowerLimitPrice;
	TThostFtdcRatioType	PreDelta;
	TThostFtdcRatioType	CurrDelta;
	TThostFtdcTimeType	UpdateTime;
	TThostFtdcMillisecType	UpdateMillisec;
	TThostFtdcPriceType	BidPrice1;
	TThostFtdcVolumeType	BidVolume1;
	TThostFtdcPriceType	AskPrice1;
	TThostFtdcVolumeType	AskVolume1;
	TThostFtdcPriceType	BidPrice2;
	TThostFtdcVolumeType	BidVolume2;
	TThostFtdcPriceType	AskPrice2;
	TThostFtdcVolumeType	AskVolume2;
	TThostFtdcPriceType	BidPrice3;
	TThostFtdcVolumeType	BidVolume3;
	TThostFtdcPriceType	AskPrice3;
	TThostFtdcVolumeType	AskVolume3;
	TThostFtdcPriceType	BidPrice4;
	TThostFtdcVolumeType	BidVolume4;
	TThostFtdcPriceType	AskPrice4;
	TThostFtdcVolumeType	AskVolume4;
	TThostFtdcPriceType	BidPrice5;
	TThostFtdcVolumeType	BidVolume5;
	TThostFtdcPriceType	AskPrice5;
	TThostFtdcVolumeType	AskVolume5;
	TThostFtdcPriceType	AveragePrice;
	TThostFtdcDateType	ActionDay;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcPriceType	BandingUpperPrice;
	TThostFtdcPriceType	BandingLowerPrice;
};

struct CThostFtdcInstrumentTradingRightField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcTradingRightType	TradingRight;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcBrokerUserField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcUserNameType	UserName;
	TThostFtdcUserTypeType	UserType;
	TThostFtdcBoolType	IsActive;
	TThostFtdcBoolType	IsUsingOTP;
	TThostFtdcBoolType	IsAuthForce;
};

struct CThostFtdcBrokerUserPasswordField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcPasswordType	Password;
	TThostFtdcDateTimeType	LastUpdateTime;
	TThostFtdcDateTimeType	LastLoginTime;
	TThostFtdcDateType	ExpireDate;
	TThostFtdcDateType	WeakExpireDate;
};

struct CThostFtdcBrokerUserFunctionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcBrokerFunctionCodeType	BrokerFunctionCode;
};

struct CThostFtdcTraderOfferField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcPasswordType	Password;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	OrderLocalID;
	TThostFtdcTraderConnectStatusType	TraderConnectStatus;
	TThostFtdcDateType	ConnectRequestDate;
	TThostFtdcTimeType	ConnectRequestTime;
	TThostFtdcDateType	LastReportDate;
	TThostFtdcTimeType	LastReportTime;
	TThostFtdcDateType	ConnectDate;
	TThostFtdcTimeType	ConnectTime;
	TThostFtdcDateType	StartDate;
	TThostFtdcTimeType	StartTime;
	TThostFtdcDateType	TradingDay;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcTradeIDType	MaxTradeID;
	TThostFtdcReturnCodeType	MaxOrderMessageReference;
};

struct CThostFtdcSettlementInfoField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcContentType	Content;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcInstrumentMarginRateAdjustField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcRatioType	LongMarginRatioByMoney;
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	TThostFtdcBoolType	IsRelative;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcExchangeMarginRateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcRatioType	LongMarginRatioByMoney;
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcExchangeMarginRateAdjustField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcRatioType	LongMarginRatioByMoney;
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	TThostFtdcRatioType	ExchLongMarginRatioByMoney;
	TThostFtdcMoneyType	ExchLongMarginRatioByVolume;
	TThostFtdcRatioType	ExchShortMarginRatioByMoney;
	TThostFtdcMoneyType	ExchShortMarginRatioByVolume;
	TThostFtdcRatioType	NoLongMarginRatioByMoney;
	TThostFtdcMoneyType	NoLongMarginRatioByVolume;
	TThostFtdcRatioType	NoShortMarginRatioByMoney;
	TThostFtdcMoneyType	NoShortMarginRatioByVolume;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcExchangeRateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcCurrencyIDType	FromCurrencyID;
	TThostFtdcCurrencyUnitType	FromCurrencyUnit;
	TThostFtdcCurrencyIDType	ToCurrencyID;
	TThostFtdcExchangeRateType	ExchangeRate;
};

struct CThostFtdcSettlementRefField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
};

struct CThostFtdcCurrentTimeField
{
	TThostFtdcDateType	CurrDate;
	TThostFtdcTimeType	CurrTime;
	TThostFtdcMillisecType	CurrMillisec;
	TThostFtdcDateType	ActionDay;
};

struct CThostFtdcCommPhaseField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcCommPhaseNoType	CommPhaseNo;
	TThostFtdcSystemIDType	SystemID;
};

struct CThostFtdcLoginInfoField
{
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcDateType	LoginDate;
	TThostFtdcTimeType	LoginTime;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcProductInfoType	InterfaceProductInfo;
	TThostFtdcProtocolInfoType	ProtocolInfo;
	TThostFtdcSystemNameType	SystemName;
	TThostFtdcPasswordType	PasswordDeprecated;
	TThostFtdcOrderRefType	MaxOrderRef;
	TThostFtdcTimeType	SHFETime;
	TThostFtdcTimeType	DCETime;
	TThostFtdcTimeType	CZCETime;
	TThostFtdcTimeType	FFEXTime;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcPasswordType	OneTimePassword;
	TThostFtdcTimeType	INETime;
	TThostFtdcBoolType	IsQryControl;
	TThostFtdcLoginRemarkType	LoginRemark;
	TThostFtdcPasswordType	Password;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcLogoutAllField
{
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcSystemNameType	SystemName;
};

struct CThostFtdcFrontStatusField
{
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcDateType	LastReportDate;
	TThostFtdcTimeType	LastReportTime;
	TThostFtdcBoolType	IsActive;
};

struct CThostFtdcUserPasswordUpdateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcPasswordType	OldPassword;
	TThostFtdcPasswordType	NewPassword;
};

struct CThostFtdcInputOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	OrderRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	TThostFtdcDirectionType	Direction;
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	TThostFtdcPriceType	LimitPrice;
	TThostFtdcVolumeType	VolumeTotalOriginal;
	TThostFtdcTimeConditionType	TimeCondition;
	TThostFtdcDateType	GTDDate;
	TThostFtdcVolumeConditionType	VolumeCondition;
	TThostFtdcVolumeType	MinVolume;
	TThostFtdcContingentConditionType	ContingentCondition;
	TThostFtdcPriceType	StopPrice;
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	TThostFtdcBoolType	IsAutoSuspend;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBoolType	UserForceClose;
	TThostFtdcBoolType	IsSwapOrder;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	OrderRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	TThostFtdcDirectionType	Direction;
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	TThostFtdcPriceType	LimitPrice;
	TThostFtdcVolumeType	VolumeTotalOriginal;
	TThostFtdcTimeConditionType	TimeCondition;
	TThostFtdcDateType	GTDDate;
	TThostFtdcVolumeConditionType	VolumeCondition;
	TThostFtdcVolumeType	MinVolume;
	TThostFtdcContingentConditionType	ContingentCondition;
	TThostFtdcPriceType	StopPrice;
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	TThostFtdcBoolType	IsAutoSuspend;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcOrderLocalIDType	OrderLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	TThostFtdcSequenceNoType	NotifySequence;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcOrderSourceType	OrderSource;
	TThostFtdcOrderStatusType	OrderStatus;
	TThostFtdcOrderTypeType	OrderType;
	TThostFtdcVolumeType	VolumeTraded;
	TThostFtdcVolumeType	VolumeTotal;
	TThostFtdcDateType	InsertDate;
	TThostFtdcTimeType	InsertTime;
	TThostFtdcTimeType	ActiveTime;
	TThostFtdcTimeType	SuspendTime;
	TThostFtdcTimeType	UpdateTime;
	TThostFtdcTimeType	CancelTime;
	TThostFtdcTraderIDType	ActiveTraderID;
	TThostFtdcParticipantIDType	ClearingPartID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcBoolType	UserForceClose;
	TThostFtdcUserIDType	ActiveUserID;
	TThostFtdcSequenceNoType	BrokerOrderSeq;
	TThostFtdcOrderSysIDType	RelativeOrderSysID;
	TThostFtdcVolumeType	ZCETotalTradedVolume;
	TThostFtdcBoolType	IsSwapOrder;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcOldIPAddressType	reserve3;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcExchangeOrderField
{
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	TThostFtdcDirectionType	Direction;
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	TThostFtdcPriceType	LimitPrice;
	TThostFtdcVolumeType	VolumeTotalOriginal;
	TThostFtdcTimeConditionType	TimeCondition;
	TThostFtdcDateType	GTDDate;
	TThostFtdcVolumeConditionType	VolumeCondition;
	TThostFtdcVolumeType	MinVolume;
	TThostFtdcContingentConditionType	ContingentCondition;
	TThostFtdcPriceType	StopPrice;
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	TThostFtdcBoolType	IsAutoSuspend;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcOrderLocalIDType	OrderLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	TThostFtdcSequenceNoType	NotifySequence;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcOrderSourceType	OrderSource;
	TThostFtdcOrderStatusType	OrderStatus;
	TThostFtdcOrderTypeType	OrderType;
	TThostFtdcVolumeType	VolumeTraded;
	TThostFtdcVolumeType	VolumeTotal;
	TThostFtdcDateType	InsertDate;
	TThostFtdcTimeType	InsertTime;
	TThostFtdcTimeType	ActiveTime;
	TThostFtdcTimeType	SuspendTime;
	TThostFtdcTimeType	UpdateTime;
	TThostFtdcTimeType	CancelTime;
	TThostFtdcTraderIDType	ActiveTraderID;
	TThostFtdcParticipantIDType	ClearingPartID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcExchangeOrderInsertErrorField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	OrderLocalID;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
};

struct CThostFtdcInputOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	OrderActionRef;
	TThostFtdcOrderRefType	OrderRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcPriceType	LimitPrice;
	TThostFtdcVolumeType	VolumeChange;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	OrderActionRef;
	TThostFtdcOrderRefType	OrderRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcPriceType	LimitPrice;
	TThostFtdcVolumeType	VolumeChange;
	TThostFtdcDateType	ActionDate;
	TThostFtdcTimeType	ActionTime;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	OrderLocalID;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	TThostFtdcUserIDType	UserID;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcExchangeOrderActionField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcPriceType	LimitPrice;
	TThostFtdcVolumeType	VolumeChange;
	TThostFtdcDateType	ActionDate;
	TThostFtdcTimeType	ActionTime;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	OrderLocalID;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	TThostFtdcUserIDType	UserID;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcExchangeOrderActionErrorField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	OrderLocalID;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
};

struct CThostFtdcExchangeTradeField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTradeIDType	TradeID;
	TThostFtdcDirectionType	Direction;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcTradingRoleType	TradingRole;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcOffsetFlagType	OffsetFlag;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcPriceType	Price;
	TThostFtdcVolumeType	Volume;
	TThostFtdcDateType	TradeDate;
	TThostFtdcTimeType	TradeTime;
	TThostFtdcTradeTypeType	TradeType;
	TThostFtdcPriceSourceType	PriceSource;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcOrderLocalIDType	OrderLocalID;
	TThostFtdcParticipantIDType	ClearingPartID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcTradeSourceType	TradeSource;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

struct CThostFtdcTradeField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	OrderRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTradeIDType	TradeID;
	TThostFtdcDirectionType	Direction;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcTradingRoleType	TradingRole;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcOffsetFlagType	OffsetFlag;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcPriceType	Price;
	TThostFtdcVolumeType	Volume;
	TThostFtdcDateType	TradeDate;
	TThostFtdcTimeType	TradeTime;
	TThostFtdcTradeTypeType	TradeType;
	TThostFtdcPriceSourceType	PriceSource;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcOrderLocalIDType	OrderLocalID;
	TThostFtdcParticipantIDType	ClearingPartID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcSequenceNoType	BrokerOrderSeq;
	TThostFtdcTradeSourceType	TradeSource;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

struct CThostFtdcUserSessionField
{
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcDateType	LoginDate;
	TThostFtdcTimeType	LoginTime;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcProductInfoType	InterfaceProductInfo;
	TThostFtdcProtocolInfoType	ProtocolInfo;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcLoginRemarkType	LoginRemark;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryMaxOrderVolumeField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcDirectionType	Direction;
	TThostFtdcOffsetFlagType	OffsetFlag;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcVolumeType	MaxVolume;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcSettlementInfoConfirmField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcDateType	ConfirmDate;
	TThostFtdcTimeType	ConfirmTime;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcSyncDepositField
{
	TThostFtdcDepositSeqNoType	DepositSeqNo;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcMoneyType	Deposit;
	TThostFtdcBoolType	IsForce;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcBoolType	IsFromSopt;
	TThostFtdcPasswordType	TradingPassword;
};

struct CThostFtdcSyncFundMortgageField
{
	TThostFtdcDepositSeqNoType	MortgageSeqNo;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcCurrencyIDType	FromCurrencyID;
	TThostFtdcMoneyType	MortgageAmount;
	TThostFtdcCurrencyIDType	ToCurrencyID;
};

struct CThostFtdcBrokerSyncField
{
	TThostFtdcBrokerIDType	BrokerID;
};

struct CThostFtdcSyncingInvestorField
{
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorGroupID;
	TThostFtdcPartyNameType	InvestorName;
	TThostFtdcIdCardTypeType	IdentifiedCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcBoolType	IsActive;
	TThostFtdcTelephoneType	Telephone;
	TThostFtdcAddressType	Address;
	TThostFtdcDateType	OpenDate;
	TThostFtdcMobileType	Mobile;
	TThostFtdcInvestorIDType	CommModelID;
	TThostFtdcInvestorIDType	MarginModelID;
};

struct CThostFtdcSyncingTradingCodeField
{
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBoolType	IsActive;
	TThostFtdcClientIDTypeType	ClientIDType;
};

struct CThostFtdcSyncingInvestorGroupField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorGroupID;
	TThostFtdcInvestorGroupNameType	InvestorGroupName;
};

struct CThostFtdcSyncingTradingAccountField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcMoneyType	PreMortgage;
	TThostFtdcMoneyType	PreCredit;
	TThostFtdcMoneyType	PreDeposit;
	TThostFtdcMoneyType	PreBalance;
	TThostFtdcMoneyType	PreMargin;
	TThostFtdcMoneyType	InterestBase;
	TThostFtdcMoneyType	Interest;
	TThostFtdcMoneyType	Deposit;
	TThostFtdcMoneyType	Withdraw;
	TThostFtdcMoneyType	FrozenMargin;
	TThostFtdcMoneyType	FrozenCash;
	TThostFtdcMoneyType	FrozenCommission;
	TThostFtdcMoneyType	CurrMargin;
	TThostFtdcMoneyType	CashIn;
	TThostFtdcMoneyType	Commission;
	TThostFtdcMoneyType	CloseProfit;
	TThostFtdcMoneyType	PositionProfit;
	TThostFtdcMoneyType	Balance;
	TThostFtdcMoneyType	Available;
	TThostFtdcMoneyType	WithdrawQuota;
	TThostFtdcMoneyType	Reserve;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcMoneyType	Credit;
	TThostFtdcMoneyType	Mortgage;
	TThostFtdcMoneyType	ExchangeMargin;
	TThostFtdcMoneyType	DeliveryMargin;
	TThostFtdcMoneyType	ExchangeDeliveryMargin;
	TThostFtdcMoneyType	ReserveBalance;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcMoneyType	PreFundMortgageIn;
	TThostFtdcMoneyType	PreFundMortgageOut;
	TThostFtdcMoneyType	FundMortgageIn;
	TThostFtdcMoneyType	FundMortgageOut;
	TThostFtdcMoneyType	FundMortgageAvailable;
	TThostFtdcMoneyType	MortgageableFund;
	TThostFtdcMoneyType	SpecProductMargin;
	TThostFtdcMoneyType	SpecProductFrozenMargin;
	TThostFtdcMoneyType	SpecProductCommission;
	TThostFtdcMoneyType	SpecProductFrozenCommission;
	TThostFtdcMoneyType	SpecProductPositionProfit;
	TThostFtdcMoneyType	SpecProductCloseProfit;
	TThostFtdcMoneyType	SpecProductPositionProfitByAlg;
	TThostFtdcMoneyType	SpecProductExchangeMargin;
	TThostFtdcMoneyType	FrozenSwap;
	TThostFtdcMoneyType	RemainSwap;
};

struct CThostFtdcSyncingInvestorPositionField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcPosiDirectionType	PosiDirection;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcPositionDateType	PositionDate;
	TThostFtdcVolumeType	YdPosition;
	TThostFtdcVolumeType	Position;
	TThostFtdcVolumeType	LongFrozen;
	TThostFtdcVolumeType	ShortFrozen;
	TThostFtdcMoneyType	LongFrozenAmount;
	TThostFtdcMoneyType	ShortFrozenAmount;
	TThostFtdcVolumeType	OpenVolume;
	TThostFtdcVolumeType	CloseVolume;
	TThostFtdcMoneyType	OpenAmount;
	TThostFtdcMoneyType	CloseAmount;
	TThostFtdcMoneyType	PositionCost;
	TThostFtdcMoneyType	PreMargin;
	TThostFtdcMoneyType	UseMargin;
	TThostFtdcMoneyType	FrozenMargin;
	TThostFtdcMoneyType	FrozenCash;
	TThostFtdcMoneyType	FrozenCommission;
	TThostFtdcMoneyType	CashIn;
	TThostFtdcMoneyType	Commission;
	TThostFtdcMoneyType	CloseProfit;
	TThostFtdcMoneyType	PositionProfit;
	TThostFtdcPriceType	PreSettlementPrice;
	TThostFtdcPriceType	SettlementPrice;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcMoneyType	OpenCost;
	TThostFtdcMoneyType	ExchangeMargin;
	TThostFtdcVolumeType	CombPosition;
	TThostFtdcVolumeType	CombLongFrozen;
	TThostFtdcVolumeType	CombShortFrozen;
	TThostFtdcMoneyType	CloseProfitByDate;
	TThostFtdcMoneyType	CloseProfitByTrade;
	TThostFtdcVolumeType	TodayPosition;
	TThostFtdcRatioType	MarginRateByMoney;
	TThostFtdcRatioType	MarginRateByVolume;
	TThostFtdcVolumeType	StrikeFrozen;
	TThostFtdcMoneyType	StrikeFrozenAmount;
	TThostFtdcVolumeType	AbandonFrozen;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcVolumeType	YdStrikeFrozen;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcMoneyType	PositionCostOffset;
	TThostFtdcVolumeType	TasPosition;
	TThostFtdcMoneyType	TasPositionCost;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcSyncingInstrumentMarginRateField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcRatioType	LongMarginRatioByMoney;
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	TThostFtdcBoolType	IsRelative;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcSyncingInstrumentCommissionRateField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcRatioType	OpenRatioByMoney;
	TThostFtdcRatioType	OpenRatioByVolume;
	TThostFtdcRatioType	CloseRatioByMoney;
	TThostFtdcRatioType	CloseRatioByVolume;
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcSyncingInstrumentTradingRightField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcTradingRightType	TradingRight;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcTimeType	InsertTimeStart;
	TThostFtdcTimeType	InsertTimeEnd;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryTradeField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTradeIDType	TradeID;
	TThostFtdcTimeType	TradeTimeStart;
	TThostFtdcTimeType	TradeTimeEnd;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryInvestorPositionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryTradingAccountField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcBizTypeType	BizType;
	TThostFtdcAccountIDType	AccountID;
};

struct CThostFtdcQryInvestorField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
};

struct CThostFtdcQryTradingCodeField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcClientIDTypeType	ClientIDType;
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

struct CThostFtdcQryInvestorGroupField
{
	TThostFtdcBrokerIDType	BrokerID;
};

struct CThostFtdcQryInstrumentMarginRateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryInstrumentCommissionRateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryInstrumentTradingRightField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryBrokerField
{
	TThostFtdcBrokerIDType	BrokerID;
};

struct CThostFtdcQryTraderField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcTraderIDType	TraderID;
};

struct CThostFtdcQrySuperUserFunctionField
{
	TThostFtdcUserIDType	UserID;
};

struct CThostFtdcQryUserSessionField
{
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
};

struct CThostFtdcQryPartBrokerField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcParticipantIDType	ParticipantID;
};

struct CThostFtdcQryFrontStatusField
{
	TThostFtdcFrontIDType	FrontID;
};

struct CThostFtdcQryExchangeOrderField
{
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

struct CThostFtdcQryOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcExchangeIDType	ExchangeID;
};

struct CThostFtdcQryExchangeOrderActionField
{
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTraderIDType	TraderID;
};

struct CThostFtdcQrySuperUserField
{
	TThostFtdcUserIDType	UserID;
};

struct CThostFtdcQryExchangeField
{
	TThostFtdcExchangeIDType	ExchangeID;
};

struct CThostFtdcQryProductField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcProductClassType	ProductClass;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	ProductID;
};

struct CThostFtdcQryInstrumentField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcOldInstrumentIDType	reserve3;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcInstrumentIDType	ProductID;
};

struct CThostFtdcQryDepthMarketDataField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryBrokerUserField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
};

struct CThostFtdcQryBrokerUserFunctionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
};

struct CThostFtdcQryTraderOfferField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcTraderIDType	TraderID;
};

struct CThostFtdcQrySyncDepositField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcDepositSeqNoType	DepositSeqNo;
};

struct CThostFtdcQrySettlementInfoField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcDateType	TradingDay;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcQryExchangeMarginRateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryExchangeMarginRateAdjustField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryExchangeRateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcCurrencyIDType	FromCurrencyID;
	TThostFtdcCurrencyIDType	ToCurrencyID;
};

struct CThostFtdcQrySyncFundMortgageField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcDepositSeqNoType	MortgageSeqNo;
};

struct CThostFtdcQryHisOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcTimeType	InsertTimeStart;
	TThostFtdcTimeType	InsertTimeEnd;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcOptionInstrMiniMarginField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcMoneyType	MinMargin;
	TThostFtdcValueMethodType	ValueMethod;
	TThostFtdcBoolType	IsRelative;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcOptionInstrMarginAdjustField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcRatioType	SShortMarginRatioByMoney;
	TThostFtdcMoneyType	SShortMarginRatioByVolume;
	TThostFtdcRatioType	HShortMarginRatioByMoney;
	TThostFtdcMoneyType	HShortMarginRatioByVolume;
	TThostFtdcRatioType	AShortMarginRatioByMoney;
	TThostFtdcMoneyType	AShortMarginRatioByVolume;
	TThostFtdcBoolType	IsRelative;
	TThostFtdcRatioType	MShortMarginRatioByMoney;
	TThostFtdcMoneyType	MShortMarginRatioByVolume;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcOptionInstrCommRateField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcRatioType	OpenRatioByMoney;
	TThostFtdcRatioType	OpenRatioByVolume;
	TThostFtdcRatioType	CloseRatioByMoney;
	TThostFtdcRatioType	CloseRatioByVolume;
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	TThostFtdcRatioType	StrikeRatioByMoney;
	TThostFtdcRatioType	StrikeRatioByVolume;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcOptionInstrTradeCostField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcMoneyType	FixedMargin;
	TThostFtdcMoneyType	MiniMargin;
	TThostFtdcMoneyType	Royalty;
	TThostFtdcMoneyType	ExchFixedMargin;
	TThostFtdcMoneyType	ExchMiniMargin;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryOptionInstrTradeCostField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcPriceType	InputPrice;
	TThostFtdcPriceType	UnderlyingPrice;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryOptionInstrCommRateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcIndexPriceField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcPriceType	ClosePrice;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcInputExecOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	ExecOrderRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcVolumeType	Volume;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOffsetFlagType	OffsetFlag;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcActionTypeType	ActionType;
	TThostFtdcPosiDirectionType	PosiDirection;
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcInputExecOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	ExecOrderActionRef;
	TThostFtdcOrderRefType	ExecOrderRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcExecOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	ExecOrderRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcVolumeType	Volume;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOffsetFlagType	OffsetFlag;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcActionTypeType	ActionType;
	TThostFtdcPosiDirectionType	PosiDirection;
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	TThostFtdcSequenceNoType	NotifySequence;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	TThostFtdcDateType	InsertDate;
	TThostFtdcTimeType	InsertTime;
	TThostFtdcTimeType	CancelTime;
	TThostFtdcExecResultType	ExecResult;
	TThostFtdcParticipantIDType	ClearingPartID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcUserIDType	ActiveUserID;
	TThostFtdcSequenceNoType	BrokerExecOrderSeq;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcOldIPAddressType	reserve3;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcExecOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	ExecOrderActionRef;
	TThostFtdcOrderRefType	ExecOrderRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcDateType	ActionDate;
	TThostFtdcTimeType	ActionTime;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	TThostFtdcUserIDType	UserID;
	TThostFtdcActionTypeType	ActionType;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryExecOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	TThostFtdcTimeType	InsertTimeStart;
	TThostFtdcTimeType	InsertTimeEnd;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcExchangeExecOrderField
{
	TThostFtdcVolumeType	Volume;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOffsetFlagType	OffsetFlag;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcActionTypeType	ActionType;
	TThostFtdcPosiDirectionType	PosiDirection;
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	TThostFtdcSequenceNoType	NotifySequence;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	TThostFtdcDateType	InsertDate;
	TThostFtdcTimeType	InsertTime;
	TThostFtdcTimeType	CancelTime;
	TThostFtdcExecResultType	ExecResult;
	TThostFtdcParticipantIDType	ClearingPartID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryExchangeExecOrderField
{
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

struct CThostFtdcQryExecOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcExchangeIDType	ExchangeID;
};

struct CThostFtdcExchangeExecOrderActionField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcDateType	ActionDate;
	TThostFtdcTimeType	ActionTime;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	TThostFtdcUserIDType	UserID;
	TThostFtdcActionTypeType	ActionType;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcVolumeType	Volume;
	TThostFtdcIPAddressType	IPAddress;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

struct CThostFtdcQryExchangeExecOrderActionField
{
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTraderIDType	TraderID;
};

struct CThostFtdcErrExecOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	ExecOrderRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcVolumeType	Volume;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOffsetFlagType	OffsetFlag;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcActionTypeType	ActionType;
	TThostFtdcPosiDirectionType	PosiDirection;
	TThostFtdcExecOrderPositionFlagType	ReservePositionFlag;
	TThostFtdcExecOrderCloseFlagType	CloseFlag;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryErrExecOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
};

struct CThostFtdcErrExecOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	ExecOrderActionRef;
	TThostFtdcOrderRefType	ExecOrderRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryErrExecOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
};

struct CThostFtdcOptionInstrTradingRightField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcDirectionType	Direction;
	TThostFtdcTradingRightType	TradingRight;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryOptionInstrTradingRightField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcDirectionType	Direction;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcInputForQuoteField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	ForQuoteRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcForQuoteField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	ForQuoteRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOrderLocalIDType	ForQuoteLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcDateType	InsertDate;
	TThostFtdcTimeType	InsertTime;
	TThostFtdcForQuoteStatusType	ForQuoteStatus;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcUserIDType	ActiveUserID;
	TThostFtdcSequenceNoType	BrokerForQutoSeq;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve3;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryForQuoteField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTimeType	InsertTimeStart;
	TThostFtdcTimeType	InsertTimeEnd;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcExchangeForQuoteField
{
	TThostFtdcOrderLocalIDType	ForQuoteLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcDateType	InsertDate;
	TThostFtdcTimeType	InsertTime;
	TThostFtdcForQuoteStatusType	ForQuoteStatus;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryExchangeForQuoteField
{
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

struct CThostFtdcInputQuoteField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	QuoteRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcPriceType	AskPrice;
	TThostFtdcPriceType	BidPrice;
	TThostFtdcVolumeType	AskVolume;
	TThostFtdcVolumeType	BidVolume;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOffsetFlagType	AskOffsetFlag;
	TThostFtdcOffsetFlagType	BidOffsetFlag;
	TThostFtdcHedgeFlagType	AskHedgeFlag;
	TThostFtdcHedgeFlagType	BidHedgeFlag;
	TThostFtdcOrderRefType	AskOrderRef;
	TThostFtdcOrderRefType	BidOrderRef;
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
	TThostFtdcOrderSysIDType	ReplaceSysID;
};

struct CThostFtdcInputQuoteActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	QuoteActionRef;
	TThostFtdcOrderRefType	QuoteRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	QuoteSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQuoteField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	QuoteRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcPriceType	AskPrice;
	TThostFtdcPriceType	BidPrice;
	TThostFtdcVolumeType	AskVolume;
	TThostFtdcVolumeType	BidVolume;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOffsetFlagType	AskOffsetFlag;
	TThostFtdcOffsetFlagType	BidOffsetFlag;
	TThostFtdcHedgeFlagType	AskHedgeFlag;
	TThostFtdcHedgeFlagType	BidHedgeFlag;
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcSequenceNoType	NotifySequence;
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcOrderSysIDType	QuoteSysID;
	TThostFtdcDateType	InsertDate;
	TThostFtdcTimeType	InsertTime;
	TThostFtdcTimeType	CancelTime;
	TThostFtdcOrderStatusType	QuoteStatus;
	TThostFtdcParticipantIDType	ClearingPartID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcOrderSysIDType	AskOrderSysID;
	TThostFtdcOrderSysIDType	BidOrderSysID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcUserIDType	ActiveUserID;
	TThostFtdcSequenceNoType	BrokerQuoteSeq;
	TThostFtdcOrderRefType	AskOrderRef;
	TThostFtdcOrderRefType	BidOrderRef;
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcOldIPAddressType	reserve3;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
	TThostFtdcOrderSysIDType	ReplaceSysID;
};

struct CThostFtdcQuoteActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	QuoteActionRef;
	TThostFtdcOrderRefType	QuoteRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	QuoteSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcDateType	ActionDate;
	TThostFtdcTimeType	ActionTime;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	TThostFtdcUserIDType	UserID;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryQuoteField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	QuoteSysID;
	TThostFtdcTimeType	InsertTimeStart;
	TThostFtdcTimeType	InsertTimeEnd;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcExchangeQuoteField
{
	TThostFtdcPriceType	AskPrice;
	TThostFtdcPriceType	BidPrice;
	TThostFtdcVolumeType	AskVolume;
	TThostFtdcVolumeType	BidVolume;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOffsetFlagType	AskOffsetFlag;
	TThostFtdcOffsetFlagType	BidOffsetFlag;
	TThostFtdcHedgeFlagType	AskHedgeFlag;
	TThostFtdcHedgeFlagType	BidHedgeFlag;
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcSequenceNoType	NotifySequence;
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcOrderSysIDType	QuoteSysID;
	TThostFtdcDateType	InsertDate;
	TThostFtdcTimeType	InsertTime;
	TThostFtdcTimeType	CancelTime;
	TThostFtdcOrderStatusType	QuoteStatus;
	TThostFtdcParticipantIDType	ClearingPartID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcOrderSysIDType	AskOrderSysID;
	TThostFtdcOrderSysIDType	BidOrderSysID;
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryExchangeQuoteField
{
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

struct CThostFtdcQryQuoteActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcExchangeIDType	ExchangeID;
};

struct CThostFtdcExchangeQuoteActionField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	QuoteSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcDateType	ActionDate;
	TThostFtdcTimeType	ActionTime;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryExchangeQuoteActionField
{
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTraderIDType	TraderID;
};

struct CThostFtdcOptionInstrDeltaField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcRatioType	Delta;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcForQuoteRspField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	TThostFtdcTimeType	ForQuoteTime;
	TThostFtdcDateType	ActionDay;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcStrikeOffsetField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcMoneyType	Offset;
	TThostFtdcStrikeOffsetTypeType	OffsetType;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryStrikeOffsetField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcInputBatchOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	OrderActionRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcBatchOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	OrderActionRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcDateType	ActionDate;
	TThostFtdcTimeType	ActionTime;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	TThostFtdcUserIDType	UserID;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcExchangeBatchOrderActionField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcDateType	ActionDate;
	TThostFtdcTimeType	ActionTime;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryBatchOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcExchangeIDType	ExchangeID;
};

struct CThostFtdcCombInstrumentGuardField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcRatioType	GuarantRatio;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryCombInstrumentGuardField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcInputCombActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	CombActionRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcDirectionType	Direction;
	TThostFtdcVolumeType	Volume;
	TThostFtdcCombDirectionType	CombDirection;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcCombActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	CombActionRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcDirectionType	Direction;
	TThostFtdcVolumeType	Volume;
	TThostFtdcCombDirectionType	CombDirection;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderActionStatusType	ActionStatus;
	TThostFtdcSequenceNoType	NotifySequence;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcOldIPAddressType	reserve3;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcTradeIDType	ComTradeID;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryCombActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcExchangeCombActionField
{
	TThostFtdcDirectionType	Direction;
	TThostFtdcVolumeType	Volume;
	TThostFtdcCombDirectionType	CombDirection;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderActionStatusType	ActionStatus;
	TThostFtdcSequenceNoType	NotifySequence;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcTradeIDType	ComTradeID;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryExchangeCombActionField
{
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

struct CThostFtdcProductExchRateField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcCurrencyIDType	QuoteCurrencyID;
	TThostFtdcExchangeRateType	ExchangeRate;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	ProductID;
};

struct CThostFtdcQryProductExchRateField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	ProductID;
};

struct CThostFtdcQryForQuoteParamField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcForQuoteParamField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcPriceType	LastPrice;
	TThostFtdcPriceType	PriceInterval;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcMMOptionInstrCommRateField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcRatioType	OpenRatioByMoney;
	TThostFtdcRatioType	OpenRatioByVolume;
	TThostFtdcRatioType	CloseRatioByMoney;
	TThostFtdcRatioType	CloseRatioByVolume;
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	TThostFtdcRatioType	StrikeRatioByMoney;
	TThostFtdcRatioType	StrikeRatioByVolume;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryMMOptionInstrCommRateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcMMInstrumentCommissionRateField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcRatioType	OpenRatioByMoney;
	TThostFtdcRatioType	OpenRatioByVolume;
	TThostFtdcRatioType	CloseRatioByMoney;
	TThostFtdcRatioType	CloseRatioByVolume;
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryMMInstrumentCommissionRateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcInstrumentOrderCommRateField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcRatioType	OrderCommByVolume;
	TThostFtdcRatioType	OrderActionCommByVolume;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcRatioType	OrderCommByTrade;
	TThostFtdcRatioType	OrderActionCommByTrade;
};

struct CThostFtdcQryInstrumentOrderCommRateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcTradeParamField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcTradeParamIDType	TradeParamID;
	TThostFtdcSettlementParamValueType	TradeParamValue;
	TThostFtdcMemoType	Memo;
};

struct CThostFtdcInstrumentMarginRateULField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcRatioType	LongMarginRatioByMoney;
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcFutureLimitPosiParamField
{
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcVolumeType	SpecOpenVolume;
	TThostFtdcVolumeType	ArbiOpenVolume;
	TThostFtdcVolumeType	OpenVolume;
	TThostFtdcInstrumentIDType	ProductID;
};

struct CThostFtdcLoginForbiddenIPField
{
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcIPListField
{
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcBoolType	IsWhite;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcInputOptionSelfCloseField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	OptionSelfCloseRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcVolumeType	Volume;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcInputOptionSelfCloseActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	OptionSelfCloseActionRef;
	TThostFtdcOrderRefType	OptionSelfCloseRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcOptionSelfCloseField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	OptionSelfCloseRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcVolumeType	Volume;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	TThostFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	TThostFtdcSequenceNoType	NotifySequence;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	TThostFtdcDateType	InsertDate;
	TThostFtdcTimeType	InsertTime;
	TThostFtdcTimeType	CancelTime;
	TThostFtdcExecResultType	ExecResult;
	TThostFtdcParticipantIDType	ClearingPartID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcUserIDType	ActiveUserID;
	TThostFtdcSequenceNoType	BrokerOptionSelfCloseSeq;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcOldIPAddressType	reserve3;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcOptionSelfCloseActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	OptionSelfCloseActionRef;
	TThostFtdcOrderRefType	OptionSelfCloseRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcDateType	ActionDate;
	TThostFtdcTimeType	ActionTime;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	TThostFtdcUserIDType	UserID;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryOptionSelfCloseField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	TThostFtdcTimeType	InsertTimeStart;
	TThostFtdcTimeType	InsertTimeEnd;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcExchangeOptionSelfCloseField
{
	TThostFtdcVolumeType	Volume;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	TThostFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	TThostFtdcSequenceNoType	NotifySequence;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	TThostFtdcDateType	InsertDate;
	TThostFtdcTimeType	InsertTime;
	TThostFtdcTimeType	CancelTime;
	TThostFtdcExecResultType	ExecResult;
	TThostFtdcParticipantIDType	ClearingPartID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryOptionSelfCloseActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcExchangeIDType	ExchangeID;
};

struct CThostFtdcExchangeOptionSelfCloseActionField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	OptionSelfCloseSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcDateType	ActionDate;
	TThostFtdcTimeType	ActionTime;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	OptionSelfCloseLocalID;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	TThostFtdcUserIDType	UserID;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcOptSelfCloseFlagType	OptSelfCloseFlag;
	TThostFtdcIPAddressType	IPAddress;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

struct CThostFtdcSyncDelaySwapField
{
	TThostFtdcDepositSeqNoType	DelaySwapSeqNo;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcCurrencyIDType	FromCurrencyID;
	TThostFtdcMoneyType	FromAmount;
	TThostFtdcMoneyType	FromFrozenSwap;
	TThostFtdcMoneyType	FromRemainSwap;
	TThostFtdcCurrencyIDType	ToCurrencyID;
	TThostFtdcMoneyType	ToAmount;
	TThostFtdcBoolType	IsManualSwap;
	TThostFtdcBoolType	IsAllRemainSetZero;
};

struct CThostFtdcQrySyncDelaySwapField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcDepositSeqNoType	DelaySwapSeqNo;
};

struct CThostFtdcInvestUnitField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcPartyNameType	InvestorUnitName;
	TThostFtdcInvestorIDType	InvestorGroupID;
	TThostFtdcInvestorIDType	CommModelID;
	TThostFtdcInvestorIDType	MarginModelID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcQryInvestUnitField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

struct CThostFtdcSecAgentCheckModeField
{
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcAccountIDType	BrokerSecAgentID;
	TThostFtdcBoolType	CheckSelfAccount;
};

struct CThostFtdcSecAgentTradeInfoField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAccountIDType	BrokerSecAgentID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcMarketDataField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcPriceType	LastPrice;
	TThostFtdcPriceType	PreSettlementPrice;
	TThostFtdcPriceType	PreClosePrice;
	TThostFtdcLargeVolumeType	PreOpenInterest;
	TThostFtdcPriceType	OpenPrice;
	TThostFtdcPriceType	HighestPrice;
	TThostFtdcPriceType	LowestPrice;
	TThostFtdcVolumeType	Volume;
	TThostFtdcMoneyType	Turnover;
	TThostFtdcLargeVolumeType	OpenInterest;
	TThostFtdcPriceType	ClosePrice;
	TThostFtdcPriceType	SettlementPrice;
	TThostFtdcPriceType	UpperLimitPrice;
	TThostFtdcPriceType	LowerLimitPrice;
	TThostFtdcRatioType	PreDelta;
	TThostFtdcRatioType	CurrDelta;
	TThostFtdcTimeType	UpdateTime;
	TThostFtdcMillisecType	UpdateMillisec;
	TThostFtdcDateType	ActionDay;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

struct CThostFtdcMarketDataBaseField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcPriceType	PreSettlementPrice;
	TThostFtdcPriceType	PreClosePrice;
	TThostFtdcLargeVolumeType	PreOpenInterest;
	TThostFtdcRatioType	PreDelta;
};

struct CThostFtdcMarketDataStaticField
{
	TThostFtdcPriceType	OpenPrice;
	TThostFtdcPriceType	HighestPrice;
	TThostFtdcPriceType	LowestPrice;
	TThostFtdcPriceType	ClosePrice;
	TThostFtdcPriceType	UpperLimitPrice;
	TThostFtdcPriceType	LowerLimitPrice;
	TThostFtdcPriceType	SettlementPrice;
	TThostFtdcRatioType	CurrDelta;
};

struct CThostFtdcMarketDataLastMatchField
{
	TThostFtdcPriceType	LastPrice;
	TThostFtdcVolumeType	Volume;
	TThostFtdcMoneyType	Turnover;
	TThostFtdcLargeVolumeType	OpenInterest;
};

struct CThostFtdcMarketDataBestPriceField
{
	TThostFtdcPriceType	BidPrice1;
	TThostFtdcVolumeType	BidVolume1;
	TThostFtdcPriceType	AskPrice1;
	TThostFtdcVolumeType	AskVolume1;
};

struct CThostFtdcMarketDataBid23Field
{
	TThostFtdcPriceType	BidPrice2;
	TThostFtdcVolumeType	BidVolume2;
	TThostFtdcPriceType	BidPrice3;
	TThostFtdcVolumeType	BidVolume3;
};

struct CThostFtdcMarketDataAsk23Field
{
	TThostFtdcPriceType	AskPrice2;
	TThostFtdcVolumeType	AskVolume2;
	TThostFtdcPriceType	AskPrice3;
	TThostFtdcVolumeType	AskVolume3;
};

struct CThostFtdcMarketDataBid45Field
{
	TThostFtdcPriceType	BidPrice4;
	TThostFtdcVolumeType	BidVolume4;
	TThostFtdcPriceType	BidPrice5;
	TThostFtdcVolumeType	BidVolume5;
};

struct CThostFtdcMarketDataAsk45Field
{
	TThostFtdcPriceType	AskPrice4;
	TThostFtdcVolumeType	AskVolume4;
	TThostFtdcPriceType	AskPrice5;
	TThostFtdcVolumeType	AskVolume5;
};

struct CThostFtdcMarketDataUpdateTimeField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcTimeType	UpdateTime;
	TThostFtdcMillisecType	UpdateMillisec;
	TThostFtdcDateType	ActionDay;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcMarketDataBandingPriceField
{
	TThostFtdcPriceType	BandingUpperPrice;
	TThostFtdcPriceType	BandingLowerPrice;
};

struct CThostFtdcMarketDataExchangeField
{
	TThostFtdcExchangeIDType	ExchangeID;
};

struct CThostFtdcSpecificInstrumentField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcInstrumentStatusField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcSettlementGroupIDType	SettlementGroupID;
	TThostFtdcOldInstrumentIDType	reserve2;
	TThostFtdcInstrumentStatusType	InstrumentStatus;
	TThostFtdcTradingSegmentSNType	TradingSegmentSN;
	TThostFtdcTimeType	EnterTime;
	TThostFtdcInstStatusEnterReasonType	EnterReason;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryInstrumentStatusField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOldExchangeInstIDType	reserve1;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

struct CThostFtdcInvestorAccountField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcPositionProfitAlgorithmField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcAlgorithmType	Algorithm;
	TThostFtdcMemoType	Memo;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcDiscountField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcRatioType	Discount;
};

struct CThostFtdcQryTransferBankField
{
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBrchID;
};

struct CThostFtdcTransferBankField
{
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBrchID;
	TThostFtdcBankNameType	BankName;
	TThostFtdcBoolType	IsActive;
};

struct CThostFtdcQryInvestorPositionDetailField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcInvestorPositionDetailField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcDirectionType	Direction;
	TThostFtdcDateType	OpenDate;
	TThostFtdcTradeIDType	TradeID;
	TThostFtdcVolumeType	Volume;
	TThostFtdcPriceType	OpenPrice;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcTradeTypeType	TradeType;
	TThostFtdcOldInstrumentIDType	reserve2;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcMoneyType	CloseProfitByDate;
	TThostFtdcMoneyType	CloseProfitByTrade;
	TThostFtdcMoneyType	PositionProfitByDate;
	TThostFtdcMoneyType	PositionProfitByTrade;
	TThostFtdcMoneyType	Margin;
	TThostFtdcMoneyType	ExchMargin;
	TThostFtdcRatioType	MarginRateByMoney;
	TThostFtdcRatioType	MarginRateByVolume;
	TThostFtdcPriceType	LastSettlementPrice;
	TThostFtdcPriceType	SettlementPrice;
	TThostFtdcVolumeType	CloseVolume;
	TThostFtdcMoneyType	CloseAmount;
	TThostFtdcVolumeType	TimeFirstVolume;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcSpecPosiTypeType	SpecPosiType;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcInstrumentIDType	CombInstrumentID;
};

struct CThostFtdcTradingAccountPasswordField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcMDTraderOfferField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcPasswordType	Password;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	OrderLocalID;
	TThostFtdcTraderConnectStatusType	TraderConnectStatus;
	TThostFtdcDateType	ConnectRequestDate;
	TThostFtdcTimeType	ConnectRequestTime;
	TThostFtdcDateType	LastReportDate;
	TThostFtdcTimeType	LastReportTime;
	TThostFtdcDateType	ConnectDate;
	TThostFtdcTimeType	ConnectTime;
	TThostFtdcDateType	StartDate;
	TThostFtdcTimeType	StartTime;
	TThostFtdcDateType	TradingDay;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcTradeIDType	MaxTradeID;
	TThostFtdcReturnCodeType	MaxOrderMessageReference;
};

struct CThostFtdcQryMDTraderOfferField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcTraderIDType	TraderID;
};

struct CThostFtdcQryNoticeField
{
	TThostFtdcBrokerIDType	BrokerID;
};

struct CThostFtdcNoticeField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcContentType	Content;
	TThostFtdcSequenceLabelType	SequenceLabel;
};

struct CThostFtdcUserRightField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcUserRightTypeType	UserRightType;
	TThostFtdcBoolType	IsForbidden;
};

struct CThostFtdcQrySettlementInfoConfirmField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcLoadSettlementInfoField
{
	TThostFtdcBrokerIDType	BrokerID;
};

struct CThostFtdcBrokerWithdrawAlgorithmField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAlgorithmType	WithdrawAlgorithm;
	TThostFtdcRatioType	UsingRatio;
	TThostFtdcIncludeCloseProfitType	IncludeCloseProfit;
	TThostFtdcAllWithoutTradeType	AllWithoutTrade;
	TThostFtdcIncludeCloseProfitType	AvailIncludeCloseProfit;
	TThostFtdcBoolType	IsBrokerUserEvent;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcRatioType	FundMortgageRatio;
	TThostFtdcBalanceAlgorithmType	BalanceAlgorithm;
};

struct CThostFtdcTradingAccountPasswordUpdateV1Field
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcPasswordType	OldPassword;
	TThostFtdcPasswordType	NewPassword;
};

struct CThostFtdcTradingAccountPasswordUpdateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	OldPassword;
	TThostFtdcPasswordType	NewPassword;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcQryCombinationLegField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcLegIDType	LegID;
	TThostFtdcOldInstrumentIDType	reserve2;
	TThostFtdcInstrumentIDType	CombInstrumentID;
	TThostFtdcInstrumentIDType	LegInstrumentID;
};

struct CThostFtdcQrySyncStatusField
{
	TThostFtdcDateType	TradingDay;
};

struct CThostFtdcCombinationLegField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcLegIDType	LegID;
	TThostFtdcOldInstrumentIDType	reserve2;
	TThostFtdcDirectionType	Direction;
	TThostFtdcLegMultipleType	LegMultiple;
	TThostFtdcImplyLevelType	ImplyLevel;
	TThostFtdcInstrumentIDType	CombInstrumentID;
	TThostFtdcInstrumentIDType	LegInstrumentID;
};

struct CThostFtdcSyncStatusField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcDataSyncStatusType	DataSyncStatus;
};

struct CThostFtdcQryLinkManField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
};

struct CThostFtdcLinkManField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcPersonTypeType	PersonType;
	TThostFtdcIdCardTypeType	IdentifiedCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcPartyNameType	PersonName;
	TThostFtdcTelephoneType	Telephone;
	TThostFtdcAddressType	Address;
	TThostFtdcZipCodeType	ZipCode;
	TThostFtdcPriorityType	Priority;
	TThostFtdcUOAZipCodeType	UOAZipCode;
	TThostFtdcInvestorFullNameType	PersonFullName;
};

struct CThostFtdcQryBrokerUserEventField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcUserEventTypeType	UserEventType;
};

struct CThostFtdcBrokerUserEventField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcUserEventTypeType	UserEventType;
	TThostFtdcSequenceNoType	EventSequenceNo;
	TThostFtdcDateType	EventDate;
	TThostFtdcTimeType	EventTime;
	TThostFtdcUserEventInfoType	UserEventInfo;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryContractBankField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBrchID;
};

struct CThostFtdcContractBankField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBrchID;
	TThostFtdcBankNameType	BankName;
};

struct CThostFtdcInvestorPositionCombineDetailField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcDateType	OpenDate;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcTradeIDType	ComTradeID;
	TThostFtdcTradeIDType	TradeID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcDirectionType	Direction;
	TThostFtdcVolumeType	TotalAmt;
	TThostFtdcMoneyType	Margin;
	TThostFtdcMoneyType	ExchMargin;
	TThostFtdcRatioType	MarginRateByMoney;
	TThostFtdcRatioType	MarginRateByVolume;
	TThostFtdcLegIDType	LegID;
	TThostFtdcLegMultipleType	LegMultiple;
	TThostFtdcOldInstrumentIDType	reserve2;
	TThostFtdcTradeGroupIDType	TradeGroupID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcInstrumentIDType	CombInstrumentID;
};

struct CThostFtdcParkedOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	OrderRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	TThostFtdcDirectionType	Direction;
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	TThostFtdcPriceType	LimitPrice;
	TThostFtdcVolumeType	VolumeTotalOriginal;
	TThostFtdcTimeConditionType	TimeCondition;
	TThostFtdcDateType	GTDDate;
	TThostFtdcVolumeConditionType	VolumeCondition;
	TThostFtdcVolumeType	MinVolume;
	TThostFtdcContingentConditionType	ContingentCondition;
	TThostFtdcPriceType	StopPrice;
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	TThostFtdcBoolType	IsAutoSuspend;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBoolType	UserForceClose;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParkedOrderIDType	ParkedOrderID;
	TThostFtdcUserTypeType	UserType;
	TThostFtdcParkedOrderStatusType	Status;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcBoolType	IsSwapOrder;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcParkedOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	OrderActionRef;
	TThostFtdcOrderRefType	OrderRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcPriceType	LimitPrice;
	TThostFtdcVolumeType	VolumeChange;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcParkedOrderActionIDType	ParkedOrderActionID;
	TThostFtdcUserTypeType	UserType;
	TThostFtdcParkedOrderStatusType	Status;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryParkedOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryParkedOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcRemoveParkedOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcParkedOrderIDType	ParkedOrderID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

struct CThostFtdcRemoveParkedOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcParkedOrderActionIDType	ParkedOrderActionID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

struct CThostFtdcInvestorWithdrawAlgorithmField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcRatioType	UsingRatio;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcRatioType	FundMortgageRatio;
};

struct CThostFtdcQryInvestorPositionCombineDetailField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	CombInstrumentID;
};

struct CThostFtdcMarketDataAveragePriceField
{
	TThostFtdcPriceType	AveragePrice;
};

struct CThostFtdcVerifyInvestorPasswordField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcPasswordType	Password;
};

struct CThostFtdcUserIPField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcIPAddressType	IPAddress;
	TThostFtdcIPAddressType	IPMask;
};

struct CThostFtdcTradingNoticeInfoField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcTimeType	SendTime;
	TThostFtdcContentType	FieldContent;
	TThostFtdcSequenceSeriesType	SequenceSeries;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

struct CThostFtdcTradingNoticeField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcSequenceSeriesType	SequenceSeries;
	TThostFtdcUserIDType	UserID;
	TThostFtdcTimeType	SendTime;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcContentType	FieldContent;
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

struct CThostFtdcQryTradingNoticeField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

struct CThostFtdcQryErrOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
};

struct CThostFtdcErrOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	OrderRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	TThostFtdcDirectionType	Direction;
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	TThostFtdcPriceType	LimitPrice;
	TThostFtdcVolumeType	VolumeTotalOriginal;
	TThostFtdcTimeConditionType	TimeCondition;
	TThostFtdcDateType	GTDDate;
	TThostFtdcVolumeConditionType	VolumeCondition;
	TThostFtdcVolumeType	MinVolume;
	TThostFtdcContingentConditionType	ContingentCondition;
	TThostFtdcPriceType	StopPrice;
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	TThostFtdcBoolType	IsAutoSuspend;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcBoolType	UserForceClose;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcBoolType	IsSwapOrder;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcErrorConditionalOrderField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcOrderRefType	OrderRef;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOrderPriceTypeType	OrderPriceType;
	TThostFtdcDirectionType	Direction;
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	TThostFtdcPriceType	LimitPrice;
	TThostFtdcVolumeType	VolumeTotalOriginal;
	TThostFtdcTimeConditionType	TimeCondition;
	TThostFtdcDateType	GTDDate;
	TThostFtdcVolumeConditionType	VolumeCondition;
	TThostFtdcVolumeType	MinVolume;
	TThostFtdcContingentConditionType	ContingentCondition;
	TThostFtdcPriceType	StopPrice;
	TThostFtdcForceCloseReasonType	ForceCloseReason;
	TThostFtdcBoolType	IsAutoSuspend;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcOrderLocalIDType	OrderLocalID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcOldExchangeInstIDType	reserve2;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderSubmitStatusType	OrderSubmitStatus;
	TThostFtdcSequenceNoType	NotifySequence;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcOrderSourceType	OrderSource;
	TThostFtdcOrderStatusType	OrderStatus;
	TThostFtdcOrderTypeType	OrderType;
	TThostFtdcVolumeType	VolumeTraded;
	TThostFtdcVolumeType	VolumeTotal;
	TThostFtdcDateType	InsertDate;
	TThostFtdcTimeType	InsertTime;
	TThostFtdcTimeType	ActiveTime;
	TThostFtdcTimeType	SuspendTime;
	TThostFtdcTimeType	UpdateTime;
	TThostFtdcTimeType	CancelTime;
	TThostFtdcTraderIDType	ActiveTraderID;
	TThostFtdcParticipantIDType	ClearingPartID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcBoolType	UserForceClose;
	TThostFtdcUserIDType	ActiveUserID;
	TThostFtdcSequenceNoType	BrokerOrderSeq;
	TThostFtdcOrderSysIDType	RelativeOrderSysID;
	TThostFtdcVolumeType	ZCETotalTradedVolume;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcBoolType	IsSwapOrder;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcOldIPAddressType	reserve3;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryErrOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
};

struct CThostFtdcErrOrderActionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOrderActionRefType	OrderActionRef;
	TThostFtdcOrderRefType	OrderRef;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcFrontIDType	FrontID;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOrderSysIDType	OrderSysID;
	TThostFtdcActionFlagType	ActionFlag;
	TThostFtdcPriceType	LimitPrice;
	TThostFtdcVolumeType	VolumeChange;
	TThostFtdcDateType	ActionDate;
	TThostFtdcTimeType	ActionTime;
	TThostFtdcTraderIDType	TraderID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcOrderLocalIDType	OrderLocalID;
	TThostFtdcOrderLocalIDType	ActionLocalID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcClientIDType	ClientID;
	TThostFtdcBusinessUnitType	BusinessUnit;
	TThostFtdcOrderActionStatusType	OrderActionStatus;
	TThostFtdcUserIDType	UserID;
	TThostFtdcErrorMsgType	StatusMsg;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcBranchIDType	BranchID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcOldIPAddressType	reserve2;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryExchangeSequenceField
{
	TThostFtdcExchangeIDType	ExchangeID;
};

struct CThostFtdcExchangeSequenceField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcInstrumentStatusType	MarketStatus;
};

struct CThostFtdcQryMaxOrderVolumeWithPriceField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcDirectionType	Direction;
	TThostFtdcOffsetFlagType	OffsetFlag;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcVolumeType	MaxVolume;
	TThostFtdcPriceType	Price;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryBrokerTradingParamsField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcAccountIDType	AccountID;
};

struct CThostFtdcBrokerTradingParamsField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcMarginPriceTypeType	MarginPriceType;
	TThostFtdcAlgorithmType	Algorithm;
	TThostFtdcIncludeCloseProfitType	AvailIncludeCloseProfit;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcOptionRoyaltyPriceTypeType	OptionRoyaltyPriceType;
	TThostFtdcAccountIDType	AccountID;
};

struct CThostFtdcQryBrokerTradingAlgosField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcBrokerTradingAlgosField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcHandlePositionAlgoIDType	HandlePositionAlgoID;
	TThostFtdcFindMarginRateAlgoIDType	FindMarginRateAlgoID;
	TThostFtdcHandleTradingAccountAlgoIDType	HandleTradingAccountAlgoID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQueryBrokerDepositField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcExchangeIDType	ExchangeID;
};

struct CThostFtdcBrokerDepositField
{
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcMoneyType	PreBalance;
	TThostFtdcMoneyType	CurrMargin;
	TThostFtdcMoneyType	CloseProfit;
	TThostFtdcMoneyType	Balance;
	TThostFtdcMoneyType	Deposit;
	TThostFtdcMoneyType	Withdraw;
	TThostFtdcMoneyType	Available;
	TThostFtdcMoneyType	Reserve;
	TThostFtdcMoneyType	FrozenMargin;
};

struct CThostFtdcQryCFMMCBrokerKeyField
{
	TThostFtdcBrokerIDType	BrokerID;
};

struct CThostFtdcCFMMCBrokerKeyField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcDateType	CreateDate;
	TThostFtdcTimeType	CreateTime;
	TThostFtdcSequenceNoType	KeyID;
	TThostFtdcCFMMCKeyType	CurrentKey;
	TThostFtdcCFMMCKeyKindType	KeyKind;
};

struct CThostFtdcCFMMCTradingAccountKeyField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcSequenceNoType	KeyID;
	TThostFtdcCFMMCKeyType	CurrentKey;
};

struct CThostFtdcQryCFMMCTradingAccountKeyField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
};

struct CThostFtdcBrokerUserOTPParamField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOTPVendorsIDType	OTPVendorsID;
	TThostFtdcSerialNumberType	SerialNumber;
	TThostFtdcAuthKeyType	AuthKey;
	TThostFtdcLastDriftType	LastDrift;
	TThostFtdcLastSuccessType	LastSuccess;
	TThostFtdcOTPTypeType	OTPType;
};

struct CThostFtdcManualSyncBrokerUserOTPField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOTPTypeType	OTPType;
	TThostFtdcPasswordType	FirstOTP;
	TThostFtdcPasswordType	SecondOTP;
};

struct CThostFtdcCommRateModelField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	CommModelID;
	TThostFtdcCommModelNameType	CommModelName;
};

struct CThostFtdcQryCommRateModelField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	CommModelID;
};

struct CThostFtdcMarginModelField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	MarginModelID;
	TThostFtdcCommModelNameType	MarginModelName;
};

struct CThostFtdcQryMarginModelField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	MarginModelID;
};

struct CThostFtdcEWarrantOffsetField
{
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcDirectionType	Direction;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcVolumeType	Volume;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryEWarrantOffsetField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryInvestorProductGroupMarginField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	ProductGroupID;
};

struct CThostFtdcInvestorProductGroupMarginField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcMoneyType	FrozenMargin;
	TThostFtdcMoneyType	LongFrozenMargin;
	TThostFtdcMoneyType	ShortFrozenMargin;
	TThostFtdcMoneyType	UseMargin;
	TThostFtdcMoneyType	LongUseMargin;
	TThostFtdcMoneyType	ShortUseMargin;
	TThostFtdcMoneyType	ExchMargin;
	TThostFtdcMoneyType	LongExchMargin;
	TThostFtdcMoneyType	ShortExchMargin;
	TThostFtdcMoneyType	CloseProfit;
	TThostFtdcMoneyType	FrozenCommission;
	TThostFtdcMoneyType	Commission;
	TThostFtdcMoneyType	FrozenCash;
	TThostFtdcMoneyType	CashIn;
	TThostFtdcMoneyType	PositionProfit;
	TThostFtdcMoneyType	OffsetAmount;
	TThostFtdcMoneyType	LongOffsetAmount;
	TThostFtdcMoneyType	ShortOffsetAmount;
	TThostFtdcMoneyType	ExchOffsetAmount;
	TThostFtdcMoneyType	LongExchOffsetAmount;
	TThostFtdcMoneyType	ShortExchOffsetAmount;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcInstrumentIDType	ProductGroupID;
};

struct CThostFtdcQueryCFMMCTradingAccountTokenField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcInvestUnitIDType	InvestUnitID;
};

struct CThostFtdcCFMMCTradingAccountTokenField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcParticipantIDType	ParticipantID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcSequenceNoType	KeyID;
	TThostFtdcCFMMCTokenType	Token;
};

struct CThostFtdcQryProductGroupField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	ProductID;
};

struct CThostFtdcProductGroupField
{
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcOldInstrumentIDType	reserve2;
	TThostFtdcInstrumentIDType	ProductID;
	TThostFtdcInstrumentIDType	ProductGroupID;
};

struct CThostFtdcBulletinField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcDateType	TradingDay;
	TThostFtdcBulletinIDType	BulletinID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcNewsTypeType	NewsType;
	TThostFtdcNewsUrgencyType	NewsUrgency;
	TThostFtdcTimeType	SendTime;
	TThostFtdcAbstractType	Abstract;
	TThostFtdcComeFromType	ComeFrom;
	TThostFtdcContentType	Content;
	TThostFtdcURLLinkType	URLLink;
	TThostFtdcMarketIDType	MarketID;
};

struct CThostFtdcQryBulletinField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcBulletinIDType	BulletinID;
	TThostFtdcSequenceNoType	SequenceNo;
	TThostFtdcNewsTypeType	NewsType;
	TThostFtdcNewsUrgencyType	NewsUrgency;
};

struct CThostFtdcMulticastInstrumentField
{
	TThostFtdcInstallIDType	TopicID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInstallIDType	InstrumentNo;
	TThostFtdcPriceType	CodePrice;
	TThostFtdcVolumeMultipleType	VolumeMultiple;
	TThostFtdcPriceType	PriceTick;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryMulticastInstrumentField
{
	TThostFtdcInstallIDType	TopicID;
	TThostFtdcOldInstrumentIDType	reserve1;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcAppIDAuthAssignField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAppIDType	AppID;
	TThostFtdcDRIdentityIDType	DRIdentityID;
};

struct CThostFtdcReqOpenAccountField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcGenderType	Gender;
	TThostFtdcCountryCodeType	CountryCode;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcAddressType	Address;
	TThostFtdcZipCodeType	ZipCode;
	TThostFtdcTelephoneType	Telephone;
	TThostFtdcMobilePhoneType	MobilePhone;
	TThostFtdcFaxType	Fax;
	TThostFtdcEMailType	EMail;
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankAccTypeType	BankSecuAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcBankAccountType	BankSecuAcc;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcTIDType	TID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcReqCancelAccountField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcGenderType	Gender;
	TThostFtdcCountryCodeType	CountryCode;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcAddressType	Address;
	TThostFtdcZipCodeType	ZipCode;
	TThostFtdcTelephoneType	Telephone;
	TThostFtdcMobilePhoneType	MobilePhone;
	TThostFtdcFaxType	Fax;
	TThostFtdcEMailType	EMail;
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankAccTypeType	BankSecuAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcBankAccountType	BankSecuAcc;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcTIDType	TID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcReqChangeAccountField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcGenderType	Gender;
	TThostFtdcCountryCodeType	CountryCode;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcAddressType	Address;
	TThostFtdcZipCodeType	ZipCode;
	TThostFtdcTelephoneType	Telephone;
	TThostFtdcMobilePhoneType	MobilePhone;
	TThostFtdcFaxType	Fax;
	TThostFtdcEMailType	EMail;
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcBankAccountType	NewBankAccount;
	TThostFtdcPasswordType	NewBankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcTIDType	TID;
	TThostFtdcDigestType	Digest;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcReqTransferField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcFutureSerialType	FutureSerial;
	TThostFtdcUserIDType	UserID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcTradeAmountType	TradeAmount;
	TThostFtdcTradeAmountType	FutureFetchAmount;
	TThostFtdcFeePayFlagType	FeePayFlag;
	TThostFtdcCustFeeType	CustFee;
	TThostFtdcFutureFeeType	BrokerFee;
	TThostFtdcAddInfoType	Message;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankAccTypeType	BankSecuAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcBankAccountType	BankSecuAcc;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcTransferStatusType	TransferStatus;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcRspTransferField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcFutureSerialType	FutureSerial;
	TThostFtdcUserIDType	UserID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcTradeAmountType	TradeAmount;
	TThostFtdcTradeAmountType	FutureFetchAmount;
	TThostFtdcFeePayFlagType	FeePayFlag;
	TThostFtdcCustFeeType	CustFee;
	TThostFtdcFutureFeeType	BrokerFee;
	TThostFtdcAddInfoType	Message;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankAccTypeType	BankSecuAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcBankAccountType	BankSecuAcc;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcTransferStatusType	TransferStatus;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcReqRepealField
{
	TThostFtdcRepealTimeIntervalType	RepealTimeInterval;
	TThostFtdcRepealedTimesType	RepealedTimes;
	TThostFtdcBankRepealFlagType	BankRepealFlag;
	TThostFtdcBrokerRepealFlagType	BrokerRepealFlag;
	TThostFtdcPlateSerialType	PlateRepealSerial;
	TThostFtdcBankSerialType	BankRepealSerial;
	TThostFtdcFutureSerialType	FutureRepealSerial;
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcFutureSerialType	FutureSerial;
	TThostFtdcUserIDType	UserID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcTradeAmountType	TradeAmount;
	TThostFtdcTradeAmountType	FutureFetchAmount;
	TThostFtdcFeePayFlagType	FeePayFlag;
	TThostFtdcCustFeeType	CustFee;
	TThostFtdcFutureFeeType	BrokerFee;
	TThostFtdcAddInfoType	Message;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankAccTypeType	BankSecuAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcBankAccountType	BankSecuAcc;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcTransferStatusType	TransferStatus;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcRspRepealField
{
	TThostFtdcRepealTimeIntervalType	RepealTimeInterval;
	TThostFtdcRepealedTimesType	RepealedTimes;
	TThostFtdcBankRepealFlagType	BankRepealFlag;
	TThostFtdcBrokerRepealFlagType	BrokerRepealFlag;
	TThostFtdcPlateSerialType	PlateRepealSerial;
	TThostFtdcBankSerialType	BankRepealSerial;
	TThostFtdcFutureSerialType	FutureRepealSerial;
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcFutureSerialType	FutureSerial;
	TThostFtdcUserIDType	UserID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcTradeAmountType	TradeAmount;
	TThostFtdcTradeAmountType	FutureFetchAmount;
	TThostFtdcFeePayFlagType	FeePayFlag;
	TThostFtdcCustFeeType	CustFee;
	TThostFtdcFutureFeeType	BrokerFee;
	TThostFtdcAddInfoType	Message;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankAccTypeType	BankSecuAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcBankAccountType	BankSecuAcc;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcTransferStatusType	TransferStatus;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcReqQueryAccountField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcFutureSerialType	FutureSerial;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankAccTypeType	BankSecuAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcBankAccountType	BankSecuAcc;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcRspQueryAccountField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcFutureSerialType	FutureSerial;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankAccTypeType	BankSecuAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcBankAccountType	BankSecuAcc;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcTradeAmountType	BankUseAmount;
	TThostFtdcTradeAmountType	BankFetchAmount;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcFutureSignIOField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcDigestType	Digest;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
};

struct CThostFtdcRspFutureSignInField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcDigestType	Digest;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcPasswordKeyType	PinKey;
	TThostFtdcPasswordKeyType	MacKey;
};

struct CThostFtdcReqFutureSignOutField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcDigestType	Digest;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
};

struct CThostFtdcRspFutureSignOutField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcDigestType	Digest;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
};

struct CThostFtdcReqQueryTradeResultBySerialField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcSerialType	Reference;
	TThostFtdcInstitutionTypeType	RefrenceIssureType;
	TThostFtdcOrganCodeType	RefrenceIssure;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcTradeAmountType	TradeAmount;
	TThostFtdcDigestType	Digest;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcRspQueryTradeResultBySerialField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcSerialType	Reference;
	TThostFtdcInstitutionTypeType	RefrenceIssureType;
	TThostFtdcOrganCodeType	RefrenceIssure;
	TThostFtdcReturnCodeType	OriginReturnCode;
	TThostFtdcDescrInfoForReturnCodeType	OriginDescrInfoForReturnCode;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcTradeAmountType	TradeAmount;
	TThostFtdcDigestType	Digest;
};

struct CThostFtdcReqDayEndFileReadyField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcFileBusinessCodeType	FileBusinessCode;
	TThostFtdcDigestType	Digest;
};

struct CThostFtdcReturnResultField
{
	TThostFtdcReturnCodeType	ReturnCode;
	TThostFtdcDescrInfoForReturnCodeType	DescrInfoForReturnCode;
};

struct CThostFtdcVerifyFuturePasswordField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcTIDType	TID;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcVerifyCustInfoField
{
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcVerifyFuturePasswordAndCustInfoField
{
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcDepositResultInformField
{
	TThostFtdcDepositSeqNoType	DepositSeqNo;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcMoneyType	Deposit;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcReturnCodeType	ReturnCode;
	TThostFtdcDescrInfoForReturnCodeType	DescrInfoForReturnCode;
};

struct CThostFtdcReqSyncKeyField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcAddInfoType	Message;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
};

struct CThostFtdcRspSyncKeyField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcAddInfoType	Message;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
};

struct CThostFtdcNotifyQueryAccountField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcFutureSerialType	FutureSerial;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankAccTypeType	BankSecuAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcBankAccountType	BankSecuAcc;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcTradeAmountType	BankUseAmount;
	TThostFtdcTradeAmountType	BankFetchAmount;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcTransferSerialField
{
	TThostFtdcPlateSerialType	PlateSerial;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcDateType	TradingDay;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcFutureAccTypeType	FutureAccType;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcFutureSerialType	FutureSerial;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcTradeAmountType	TradeAmount;
	TThostFtdcCustFeeType	CustFee;
	TThostFtdcFutureFeeType	BrokerFee;
	TThostFtdcAvailabilityFlagType	AvailabilityFlag;
	TThostFtdcOperatorCodeType	OperatorCode;
	TThostFtdcBankAccountType	BankNewAccount;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
};

struct CThostFtdcQryTransferSerialField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcBankIDType	BankID;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcNotifyFutureSignInField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcDigestType	Digest;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcPasswordKeyType	PinKey;
	TThostFtdcPasswordKeyType	MacKey;
};

struct CThostFtdcNotifyFutureSignOutField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcDigestType	Digest;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
};

struct CThostFtdcNotifySyncKeyField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcAddInfoType	Message;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcRequestIDType	RequestID;
	TThostFtdcTIDType	TID;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
};

struct CThostFtdcQryAccountregisterField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcAccountregisterField
{
	TThostFtdcTradeDateType	TradeDay;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcOpenOrDestroyType	OpenOrDestroy;
	TThostFtdcTradeDateType	RegDate;
	TThostFtdcTradeDateType	OutDate;
	TThostFtdcTIDType	TID;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcOpenAccountField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcGenderType	Gender;
	TThostFtdcCountryCodeType	CountryCode;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcAddressType	Address;
	TThostFtdcZipCodeType	ZipCode;
	TThostFtdcTelephoneType	Telephone;
	TThostFtdcMobilePhoneType	MobilePhone;
	TThostFtdcFaxType	Fax;
	TThostFtdcEMailType	EMail;
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankAccTypeType	BankSecuAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcBankAccountType	BankSecuAcc;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcTIDType	TID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcCancelAccountField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcGenderType	Gender;
	TThostFtdcCountryCodeType	CountryCode;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcAddressType	Address;
	TThostFtdcZipCodeType	ZipCode;
	TThostFtdcTelephoneType	Telephone;
	TThostFtdcMobilePhoneType	MobilePhone;
	TThostFtdcFaxType	Fax;
	TThostFtdcEMailType	EMail;
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcCashExchangeCodeType	CashExchangeCode;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcDeviceIDType	DeviceID;
	TThostFtdcBankAccTypeType	BankSecuAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcBankAccountType	BankSecuAcc;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcOperNoType	OperNo;
	TThostFtdcTIDType	TID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcChangeAccountField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcGenderType	Gender;
	TThostFtdcCountryCodeType	CountryCode;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcAddressType	Address;
	TThostFtdcZipCodeType	ZipCode;
	TThostFtdcTelephoneType	Telephone;
	TThostFtdcMobilePhoneType	MobilePhone;
	TThostFtdcFaxType	Fax;
	TThostFtdcEMailType	EMail;
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcBankAccountType	NewBankAccount;
	TThostFtdcPasswordType	NewBankPassWord;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcPwdFlagType	BankPwdFlag;
	TThostFtdcPwdFlagType	SecuPwdFlag;
	TThostFtdcTIDType	TID;
	TThostFtdcDigestType	Digest;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
	TThostFtdcLongIndividualNameType	LongCustomerName;
};

struct CThostFtdcSecAgentACIDMapField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcAccountIDType	BrokerSecAgentID;
};

struct CThostFtdcQrySecAgentACIDMapField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcUserRightsAssignField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcDRIdentityIDType	DRIdentityID;
};

struct CThostFtdcBrokerUserRightAssignField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcDRIdentityIDType	DRIdentityID;
	TThostFtdcBoolType	Tradeable;
};

struct CThostFtdcDRTransferField
{
	TThostFtdcDRIdentityIDType	OrigDRIdentityID;
	TThostFtdcDRIdentityIDType	DestDRIdentityID;
	TThostFtdcBrokerIDType	OrigBrokerID;
	TThostFtdcBrokerIDType	DestBrokerID;
};

struct CThostFtdcFensUserInfoField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcLoginModeType	LoginMode;
};

struct CThostFtdcCurrTransferIdentityField
{
	TThostFtdcDRIdentityIDType	IdentityID;
};

struct CThostFtdcLoginForbiddenUserField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryLoginForbiddenUserField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
};

struct CThostFtdcTradingAccountReserveField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcMoneyType	Reserve;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcQryLoginForbiddenIPField
{
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryIPListField
{
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryUserRightsAssignField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
};

struct CThostFtdcReserveOpenAccountConfirmField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcLongIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcGenderType	Gender;
	TThostFtdcCountryCodeType	CountryCode;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcAddressType	Address;
	TThostFtdcZipCodeType	ZipCode;
	TThostFtdcTelephoneType	Telephone;
	TThostFtdcMobilePhoneType	MobilePhone;
	TThostFtdcFaxType	Fax;
	TThostFtdcEMailType	EMail;
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcTIDType	TID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcPasswordType	Password;
	TThostFtdcBankSerialType	BankReserveOpenSeq;
	TThostFtdcTradeDateType	BookDate;
	TThostFtdcPasswordType	BookPsw;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
};

struct CThostFtdcReserveOpenAccountField
{
	TThostFtdcTradeCodeType	TradeCode;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankBrchIDType	BankBranchID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	TThostFtdcTradeDateType	TradeDate;
	TThostFtdcTradeTimeType	TradeTime;
	TThostFtdcBankSerialType	BankSerial;
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcSerialType	PlateSerial;
	TThostFtdcLastFragmentType	LastFragment;
	TThostFtdcSessionIDType	SessionID;
	TThostFtdcLongIndividualNameType	CustomerName;
	TThostFtdcIdCardTypeType	IdCardType;
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	TThostFtdcGenderType	Gender;
	TThostFtdcCountryCodeType	CountryCode;
	TThostFtdcCustTypeType	CustType;
	TThostFtdcAddressType	Address;
	TThostFtdcZipCodeType	ZipCode;
	TThostFtdcTelephoneType	Telephone;
	TThostFtdcMobilePhoneType	MobilePhone;
	TThostFtdcFaxType	Fax;
	TThostFtdcEMailType	EMail;
	TThostFtdcMoneyAccountStatusType	MoneyAccountStatus;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcPasswordType	BankPassWord;
	TThostFtdcInstallIDType	InstallID;
	TThostFtdcYesNoIndicatorType	VerifyCertNoFlag;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcDigestType	Digest;
	TThostFtdcBankAccTypeType	BankAccType;
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	TThostFtdcTIDType	TID;
	TThostFtdcReserveOpenAccStasType	ReserveOpenAccStas;
	TThostFtdcErrorIDType	ErrorID;
	TThostFtdcErrorMsgType	ErrorMsg;
};

struct CThostFtdcAccountPropertyField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcBankIDType	BankID;
	TThostFtdcBankAccountType	BankAccount;
	TThostFtdcInvestorFullNameType	OpenName;
	TThostFtdcOpenBankType	OpenBank;
	TThostFtdcBoolType	IsActive;
	TThostFtdcAccountSourceTypeType	AccountSourceType;
	TThostFtdcDateType	OpenDate;
	TThostFtdcDateType	CancelDate;
	TThostFtdcOperatorIDType	OperatorID;
	TThostFtdcDateType	OperateDate;
	TThostFtdcTimeType	OperateTime;
	TThostFtdcCurrencyIDType	CurrencyID;
};

struct CThostFtdcQryCurrDRIdentityField
{
	TThostFtdcDRIdentityIDType	DRIdentityID;
};

struct CThostFtdcCurrDRIdentityField
{
	TThostFtdcDRIdentityIDType	DRIdentityID;
};

struct CThostFtdcQrySecAgentCheckModeField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
};

struct CThostFtdcQrySecAgentTradeInfoField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAccountIDType	BrokerSecAgentID;
};

struct CThostFtdcReqUserAuthMethodField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
};

struct CThostFtdcRspUserAuthMethodField
{
	TThostFtdcCurrentAuthMethodType	UsableAuthMethod;
};

struct CThostFtdcReqGenUserCaptchaField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
};

struct CThostFtdcRspGenUserCaptchaField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcCaptchaInfoLenType	CaptchaInfoLen;
	TThostFtdcCaptchaInfoType	CaptchaInfo;
};

struct CThostFtdcReqGenUserTextField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
};

struct CThostFtdcRspGenUserTextField
{
	TThostFtdcUserTextSeqType	UserTextSeq;
};

struct CThostFtdcReqUserLoginWithCaptchaField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcPasswordType	Password;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcProductInfoType	InterfaceProductInfo;
	TThostFtdcProtocolInfoType	ProtocolInfo;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcLoginRemarkType	LoginRemark;
	TThostFtdcPasswordType	Captcha;
	TThostFtdcIPPortType	ClientIPPort;
	TThostFtdcIPAddressType	ClientIPAddress;
};

struct CThostFtdcReqUserLoginWithTextField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcPasswordType	Password;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcProductInfoType	InterfaceProductInfo;
	TThostFtdcProtocolInfoType	ProtocolInfo;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcLoginRemarkType	LoginRemark;
	TThostFtdcPasswordType	Text;
	TThostFtdcIPPortType	ClientIPPort;
	TThostFtdcIPAddressType	ClientIPAddress;
};

struct CThostFtdcReqUserLoginWithOTPField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcPasswordType	Password;
	TThostFtdcProductInfoType	UserProductInfo;
	TThostFtdcProductInfoType	InterfaceProductInfo;
	TThostFtdcProtocolInfoType	ProtocolInfo;
	TThostFtdcMacAddressType	MacAddress;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcLoginRemarkType	LoginRemark;
	TThostFtdcPasswordType	OTPPassword;
	TThostFtdcIPPortType	ClientIPPort;
	TThostFtdcIPAddressType	ClientIPAddress;
};

struct CThostFtdcReqApiHandshakeField
{
	TThostFtdcCryptoKeyVersionType	CryptoKeyVersion;
};

struct CThostFtdcRspApiHandshakeField
{
	TThostFtdcHandshakeDataLenType	FrontHandshakeDataLen;
	TThostFtdcHandshakeDataType	FrontHandshakeData;
	TThostFtdcBoolType	IsApiAuthEnabled;
};

struct CThostFtdcReqVerifyApiKeyField
{
	TThostFtdcHandshakeDataLenType	ApiHandshakeDataLen;
	TThostFtdcHandshakeDataType	ApiHandshakeData;
};

struct CThostFtdcDepartmentUserField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcDepartmentRangeType	InvestorRange;
	TThostFtdcInvestorIDType	InvestorID;
};

struct CThostFtdcQueryFreqField
{
	TThostFtdcQueryFreqType	QueryFreq;
};

struct CThostFtdcAuthForbiddenIPField
{
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryAuthForbiddenIPField
{
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcSyncDelaySwapFrozenField
{
	TThostFtdcDepositSeqNoType	DelaySwapSeqNo;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcCurrencyIDType	FromCurrencyID;
	TThostFtdcMoneyType	FromRemainSwap;
	TThostFtdcBoolType	IsManualSwap;
};

struct CThostFtdcUserSystemInfoField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcSystemInfoLenType	ClientSystemInfoLen;
	TThostFtdcClientSystemInfoType	ClientSystemInfo;
	TThostFtdcOldIPAddressType	reserve1;
	TThostFtdcIPPortType	ClientIPPort;
	TThostFtdcTimeType	ClientLoginTime;
	TThostFtdcAppIDType	ClientAppID;
	TThostFtdcIPAddressType	ClientPublicIP;
	TThostFtdcClientLoginRemarkType	ClientLoginRemark;
};

struct CThostFtdcAuthUserIDField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAppIDType	AppID;
	TThostFtdcUserIDType	UserID;
	TThostFtdcAuthTypeType	AuthType;
};

struct CThostFtdcAuthIPField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAppIDType	AppID;
	TThostFtdcIPAddressType	IPAddress;
};

struct CThostFtdcQryClassifiedInstrumentField
{
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcInstrumentIDType	ProductID;
	TThostFtdcTradingTypeType	TradingType;
	TThostFtdcClassTypeType	ClassType;
};

struct CThostFtdcQryCombPromotionParamField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcCombPromotionParamField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	TThostFtdcDiscountRatioType	Xparameter;
};

struct CThostFtdcQryRiskSettleInvstPositionField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcInstrumentIDType	InstrumentID;
};

struct CThostFtdcQryRiskSettleProductStatusField
{
	TThostFtdcInstrumentIDType	ProductID;
};

struct CThostFtdcRiskSettleInvstPositionField
{
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcPosiDirectionType	PosiDirection;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcPositionDateType	PositionDate;
	TThostFtdcVolumeType	YdPosition;
	TThostFtdcVolumeType	Position;
	TThostFtdcVolumeType	LongFrozen;
	TThostFtdcVolumeType	ShortFrozen;
	TThostFtdcMoneyType	LongFrozenAmount;
	TThostFtdcMoneyType	ShortFrozenAmount;
	TThostFtdcVolumeType	OpenVolume;
	TThostFtdcVolumeType	CloseVolume;
	TThostFtdcMoneyType	OpenAmount;
	TThostFtdcMoneyType	CloseAmount;
	TThostFtdcMoneyType	PositionCost;
	TThostFtdcMoneyType	PreMargin;
	TThostFtdcMoneyType	UseMargin;
	TThostFtdcMoneyType	FrozenMargin;
	TThostFtdcMoneyType	FrozenCash;
	TThostFtdcMoneyType	FrozenCommission;
	TThostFtdcMoneyType	CashIn;
	TThostFtdcMoneyType	Commission;
	TThostFtdcMoneyType	CloseProfit;
	TThostFtdcMoneyType	PositionProfit;
	TThostFtdcPriceType	PreSettlementPrice;
	TThostFtdcPriceType	SettlementPrice;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcMoneyType	OpenCost;
	TThostFtdcMoneyType	ExchangeMargin;
	TThostFtdcVolumeType	CombPosition;
	TThostFtdcVolumeType	CombLongFrozen;
	TThostFtdcVolumeType	CombShortFrozen;
	TThostFtdcMoneyType	CloseProfitByDate;
	TThostFtdcMoneyType	CloseProfitByTrade;
	TThostFtdcVolumeType	TodayPosition;
	TThostFtdcRatioType	MarginRateByMoney;
	TThostFtdcRatioType	MarginRateByVolume;
	TThostFtdcVolumeType	StrikeFrozen;
	TThostFtdcMoneyType	StrikeFrozenAmount;
	TThostFtdcVolumeType	AbandonFrozen;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcVolumeType	YdStrikeFrozen;
	TThostFtdcInvestUnitIDType	InvestUnitID;
	TThostFtdcMoneyType	PositionCostOffset;
	TThostFtdcVolumeType	TasPosition;
	TThostFtdcMoneyType	TasPositionCost;
};

struct CThostFtdcRiskSettleProductStatusField
{
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	ProductID;
	TThostFtdcProductStatusType	ProductStatus;
};

struct CThostFtdcSyncDeltaInfoField
{
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
	TThostFtdcSyncDeltaStatusType	SyncDeltaStatus;
	TThostFtdcSyncDescriptionType	SyncDescription;
	TThostFtdcBoolType	IsOnlyTrdDelta;
};

struct CThostFtdcSyncDeltaProductStatusField
{
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	ProductID;
	TThostFtdcProductStatusType	ProductStatus;
};

struct CThostFtdcSyncDeltaInvstPosDtlField
{
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcDirectionType	Direction;
	TThostFtdcDateType	OpenDate;
	TThostFtdcTradeIDType	TradeID;
	TThostFtdcVolumeType	Volume;
	TThostFtdcPriceType	OpenPrice;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcTradeTypeType	TradeType;
	TThostFtdcInstrumentIDType	CombInstrumentID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcMoneyType	CloseProfitByDate;
	TThostFtdcMoneyType	CloseProfitByTrade;
	TThostFtdcMoneyType	PositionProfitByDate;
	TThostFtdcMoneyType	PositionProfitByTrade;
	TThostFtdcMoneyType	Margin;
	TThostFtdcMoneyType	ExchMargin;
	TThostFtdcRatioType	MarginRateByMoney;
	TThostFtdcRatioType	MarginRateByVolume;
	TThostFtdcPriceType	LastSettlementPrice;
	TThostFtdcPriceType	SettlementPrice;
	TThostFtdcVolumeType	CloseVolume;
	TThostFtdcMoneyType	CloseAmount;
	TThostFtdcVolumeType	TimeFirstVolume;
	TThostFtdcSpecPosiTypeType	SpecPosiType;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaInvstPosCombDtlField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcDateType	OpenDate;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcTradeIDType	ComTradeID;
	TThostFtdcTradeIDType	TradeID;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcDirectionType	Direction;
	TThostFtdcVolumeType	TotalAmt;
	TThostFtdcMoneyType	Margin;
	TThostFtdcMoneyType	ExchMargin;
	TThostFtdcRatioType	MarginRateByMoney;
	TThostFtdcRatioType	MarginRateByVolume;
	TThostFtdcLegIDType	LegID;
	TThostFtdcLegMultipleType	LegMultiple;
	TThostFtdcTradeGroupIDType	TradeGroupID;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaTradingAccountField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcAccountIDType	AccountID;
	TThostFtdcMoneyType	PreMortgage;
	TThostFtdcMoneyType	PreCredit;
	TThostFtdcMoneyType	PreDeposit;
	TThostFtdcMoneyType	PreBalance;
	TThostFtdcMoneyType	PreMargin;
	TThostFtdcMoneyType	InterestBase;
	TThostFtdcMoneyType	Interest;
	TThostFtdcMoneyType	Deposit;
	TThostFtdcMoneyType	Withdraw;
	TThostFtdcMoneyType	FrozenMargin;
	TThostFtdcMoneyType	FrozenCash;
	TThostFtdcMoneyType	FrozenCommission;
	TThostFtdcMoneyType	CurrMargin;
	TThostFtdcMoneyType	CashIn;
	TThostFtdcMoneyType	Commission;
	TThostFtdcMoneyType	CloseProfit;
	TThostFtdcMoneyType	PositionProfit;
	TThostFtdcMoneyType	Balance;
	TThostFtdcMoneyType	Available;
	TThostFtdcMoneyType	WithdrawQuota;
	TThostFtdcMoneyType	Reserve;
	TThostFtdcDateType	TradingDay;
	TThostFtdcSettlementIDType	SettlementID;
	TThostFtdcMoneyType	Credit;
	TThostFtdcMoneyType	Mortgage;
	TThostFtdcMoneyType	ExchangeMargin;
	TThostFtdcMoneyType	DeliveryMargin;
	TThostFtdcMoneyType	ExchangeDeliveryMargin;
	TThostFtdcMoneyType	ReserveBalance;
	TThostFtdcCurrencyIDType	CurrencyID;
	TThostFtdcMoneyType	PreFundMortgageIn;
	TThostFtdcMoneyType	PreFundMortgageOut;
	TThostFtdcMoneyType	FundMortgageIn;
	TThostFtdcMoneyType	FundMortgageOut;
	TThostFtdcMoneyType	FundMortgageAvailable;
	TThostFtdcMoneyType	MortgageableFund;
	TThostFtdcMoneyType	SpecProductMargin;
	TThostFtdcMoneyType	SpecProductFrozenMargin;
	TThostFtdcMoneyType	SpecProductCommission;
	TThostFtdcMoneyType	SpecProductFrozenCommission;
	TThostFtdcMoneyType	SpecProductPositionProfit;
	TThostFtdcMoneyType	SpecProductCloseProfit;
	TThostFtdcMoneyType	SpecProductPositionProfitByAlg;
	TThostFtdcMoneyType	SpecProductExchangeMargin;
	TThostFtdcMoneyType	FrozenSwap;
	TThostFtdcMoneyType	RemainSwap;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaInitInvstMarginField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcMoneyType	LastRiskTotalInvstMargin;
	TThostFtdcMoneyType	LastRiskTotalExchMargin;
	TThostFtdcMoneyType	ThisSyncInvstMargin;
	TThostFtdcMoneyType	ThisSyncExchMargin;
	TThostFtdcMoneyType	RemainRiskInvstMargin;
	TThostFtdcMoneyType	RemainRiskExchMargin;
	TThostFtdcMoneyType	LastRiskSpecTotalInvstMargin;
	TThostFtdcMoneyType	LastRiskSpecTotalExchMargin;
	TThostFtdcMoneyType	ThisSyncSpecInvstMargin;
	TThostFtdcMoneyType	ThisSyncSpecExchMargin;
	TThostFtdcMoneyType	RemainRiskSpecInvstMargin;
	TThostFtdcMoneyType	RemainRiskSpecExchMargin;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaDceCombInstrumentField
{
	TThostFtdcInstrumentIDType	CombInstrumentID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcTradeGroupIDType	TradeGroupID;
	TThostFtdcHedgeFlagType	CombHedgeFlag;
	TThostFtdcDceCombinationTypeType	CombinationType;
	TThostFtdcDirectionType	Direction;
	TThostFtdcInstrumentIDType	ProductID;
	TThostFtdcDiscountRatioType	Xparameter;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaInvstMarginRateField
{
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcRatioType	LongMarginRatioByMoney;
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	TThostFtdcBoolType	IsRelative;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaExchMarginRateField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcRatioType	LongMarginRatioByMoney;
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaOptExchMarginField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcRatioType	SShortMarginRatioByMoney;
	TThostFtdcMoneyType	SShortMarginRatioByVolume;
	TThostFtdcRatioType	HShortMarginRatioByMoney;
	TThostFtdcMoneyType	HShortMarginRatioByVolume;
	TThostFtdcRatioType	AShortMarginRatioByMoney;
	TThostFtdcMoneyType	AShortMarginRatioByVolume;
	TThostFtdcRatioType	MShortMarginRatioByMoney;
	TThostFtdcMoneyType	MShortMarginRatioByVolume;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaOptInvstMarginField
{
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcRatioType	SShortMarginRatioByMoney;
	TThostFtdcMoneyType	SShortMarginRatioByVolume;
	TThostFtdcRatioType	HShortMarginRatioByMoney;
	TThostFtdcMoneyType	HShortMarginRatioByVolume;
	TThostFtdcRatioType	AShortMarginRatioByMoney;
	TThostFtdcMoneyType	AShortMarginRatioByVolume;
	TThostFtdcBoolType	IsRelative;
	TThostFtdcRatioType	MShortMarginRatioByMoney;
	TThostFtdcMoneyType	MShortMarginRatioByVolume;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaInvstMarginRateULField
{
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcRatioType	LongMarginRatioByMoney;
	TThostFtdcMoneyType	LongMarginRatioByVolume;
	TThostFtdcRatioType	ShortMarginRatioByMoney;
	TThostFtdcMoneyType	ShortMarginRatioByVolume;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaOptInvstCommRateField
{
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcRatioType	OpenRatioByMoney;
	TThostFtdcRatioType	OpenRatioByVolume;
	TThostFtdcRatioType	CloseRatioByMoney;
	TThostFtdcRatioType	CloseRatioByVolume;
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	TThostFtdcRatioType	StrikeRatioByMoney;
	TThostFtdcRatioType	StrikeRatioByVolume;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaInvstCommRateField
{
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcInvestorRangeType	InvestorRange;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcRatioType	OpenRatioByMoney;
	TThostFtdcRatioType	OpenRatioByVolume;
	TThostFtdcRatioType	CloseRatioByMoney;
	TThostFtdcRatioType	CloseRatioByVolume;
	TThostFtdcRatioType	CloseTodayRatioByMoney;
	TThostFtdcRatioType	CloseTodayRatioByVolume;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaProductExchRateField
{
	TThostFtdcInstrumentIDType	ProductID;
	TThostFtdcCurrencyIDType	QuoteCurrencyID;
	TThostFtdcExchangeRateType	ExchangeRate;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaDepthMarketDataField
{
	TThostFtdcDateType	TradingDay;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	TThostFtdcPriceType	LastPrice;
	TThostFtdcPriceType	PreSettlementPrice;
	TThostFtdcPriceType	PreClosePrice;
	TThostFtdcLargeVolumeType	PreOpenInterest;
	TThostFtdcPriceType	OpenPrice;
	TThostFtdcPriceType	HighestPrice;
	TThostFtdcPriceType	LowestPrice;
	TThostFtdcVolumeType	Volume;
	TThostFtdcMoneyType	Turnover;
	TThostFtdcLargeVolumeType	OpenInterest;
	TThostFtdcPriceType	ClosePrice;
	TThostFtdcPriceType	SettlementPrice;
	TThostFtdcPriceType	UpperLimitPrice;
	TThostFtdcPriceType	LowerLimitPrice;
	TThostFtdcRatioType	PreDelta;
	TThostFtdcRatioType	CurrDelta;
	TThostFtdcTimeType	UpdateTime;
	TThostFtdcMillisecType	UpdateMillisec;
	TThostFtdcPriceType	BidPrice1;
	TThostFtdcVolumeType	BidVolume1;
	TThostFtdcPriceType	AskPrice1;
	TThostFtdcVolumeType	AskVolume1;
	TThostFtdcPriceType	BidPrice2;
	TThostFtdcVolumeType	BidVolume2;
	TThostFtdcPriceType	AskPrice2;
	TThostFtdcVolumeType	AskVolume2;
	TThostFtdcPriceType	BidPrice3;
	TThostFtdcVolumeType	BidVolume3;
	TThostFtdcPriceType	AskPrice3;
	TThostFtdcVolumeType	AskVolume3;
	TThostFtdcPriceType	BidPrice4;
	TThostFtdcVolumeType	BidVolume4;
	TThostFtdcPriceType	AskPrice4;
	TThostFtdcVolumeType	AskVolume4;
	TThostFtdcPriceType	BidPrice5;
	TThostFtdcVolumeType	BidVolume5;
	TThostFtdcPriceType	AskPrice5;
	TThostFtdcVolumeType	AskVolume5;
	TThostFtdcPriceType	AveragePrice;
	TThostFtdcDateType	ActionDay;
	TThostFtdcPriceType	BandingUpperPrice;
	TThostFtdcPriceType	BandingLowerPrice;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaIndexPriceField
{
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcPriceType	ClosePrice;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};

struct CThostFtdcSyncDeltaEWarrantOffsetField
{
	TThostFtdcTradeDateType	TradingDay;
	TThostFtdcBrokerIDType	BrokerID;
	TThostFtdcInvestorIDType	InvestorID;
	TThostFtdcExchangeIDType	ExchangeID;
	TThostFtdcInstrumentIDType	InstrumentID;
	TThostFtdcDirectionType	Direction;
	TThostFtdcHedgeFlagType	HedgeFlag;
	TThostFtdcVolumeType	Volume;
	TThostFtdcActionDirectionType	ActionDirection;
	TThostFtdcSequenceNoType	SyncDeltaSequenceNo;
};



#endif
