/**
 * @file message.h
 * @brief structs of message used by server and client
 *
 * @date 2023-07-21
 */

#ifndef MESSAGE_H
#define MESSAGE_H

#include <vector>
#include <string>
#include <map>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include "error_table.h"
#include "custome_time.h"

constexpr int INSTRUMENT_ID_LEN = 32;
constexpr int PRODUCT_ID_LEN = 32;
constexpr int DATE_LEN = 9;
constexpr int EXCHANGE_ID_LEN = 9;

enum class MsgType : int {
    Login = 100,
    LoginRsp = 101,
    Logout = 102,
    LogoutRsp = 103,
    Subscribe = 104,
    SubscribeRsp = 105,
    Unsubscribe = 106,
    UnsubscribeRsp = 107,
    HeartBeat = 108,
    HeartBeatRsp = 109,
    Tick = 110
};

enum class InstrumentType: int8_t {
    Unknown = 0,   //未知
    Stock,         //普通股票
    Future,        //期货
    Bond,          //债券
    StockOption,   //股票期权
    Fund,          //基金
    TechStock,     //科创板股票
    Index,         //指数
    Repo           //回购
};

// 登陆消息
struct LoginMsg {
    std::string user_name;
    std::string user_passwd;

    static std::string gen_login_msg(const std::string& name, const std::string& passwd) {
        nlohmann::json j;
        j["msg_type"] = MsgType::Login;
        j["user_name"] = name;
        j["user_passwd"] = passwd;
        return j.dump();
    }

    static bool from_message(const std::string &msg_str, LoginMsg &login_msg) {
        try {
            nlohmann::json j = nlohmann::json::parse(msg_str);
            if (j.at("msg_type").get<MsgType>() == MsgType::Login) {
                login_msg.user_name = j.at("user_name").get<std::string>();
                login_msg.user_passwd = j.at("user_passwd").get<std::string>();
            } else {
                SPDLOG_WARN("nlohmann::json parse message type error...");
                return false;
            }
        } catch (const std::exception &e) {
            SPDLOG_WARN("nlohmann::json parse message string failed...{}", e.what());
            return false;
        }
        return true;
    }
};

//登陆响应消息
struct LoginRspMsg {
    ErrorCode error_code;
    std::string error_msg;
    std::string push_address;

    static std::string gen_login_rsp_msg(ErrorCode error_code, const std::string& error_msg, const std::string& push_address) {
        nlohmann::json j;
        j["msg_type"] = MsgType::LoginRsp;
        j["error_code"] = error_code;
        j["error_msg"] = error_msg;
        j["push_address"] = push_address;
        return j.dump();
    }

    static bool from_message(const std::string &msg_str, LoginRspMsg &login_rsp_msg) {
        try {
            nlohmann::json j = nlohmann::json::parse(msg_str);
            if (j.at("msg_type").get<MsgType>() == MsgType::LoginRsp) {
                login_rsp_msg.error_code = j.at("error_code").get<ErrorCode>();
                login_rsp_msg.error_msg = j.at("error_msg").get<std::string>();
                login_rsp_msg.push_address = j.at("push_address").get<std::string>();
            } else {
                SPDLOG_WARN("nlohmann::json parse message type error...");
                return false;
            }
        } catch (const std::exception &e) {
            SPDLOG_WARN("nlohmann::json parse message string failed...{}", e.what());
            return false;
        }
        return true;
    }
};

//登出消息
struct LogoutMsg {
    std::string user_name;
    std::string user_passwd;

    static std::string gen_logout_msg(const std::string& name, const std::string& passwd) {
        nlohmann::json j;
        j["msg_type"] = MsgType::Logout;
        j["user_name"] = name;
        j["user_passwd"] = passwd;
        return j.dump();
    }

    static bool from_message(const std::string &msg_str, LogoutMsg &logout_msg) {
        try {
            nlohmann::json j = nlohmann::json::parse(msg_str);
            if (j.at("msg_type").get<MsgType>() == MsgType::Logout) {
                logout_msg.user_name = j.at("user_name").get<std::string>();
                logout_msg.user_passwd = j.at("user_passwd").get<std::string>();
            } else {
                SPDLOG_WARN("nlohmann::json parse message type error...");
                return false;
            }
        } catch (const std::exception &e) {
            SPDLOG_WARN("nlohmann::json parse message string failed...{}", e.what());
            return false;
        }
        return true;
    }
};

//登出响应消息
struct LogoutRspMsg {
    ErrorCode error_code;
    std::string error_msg;

    static std::string gen_logout_rsp_msg(ErrorCode error_code, const std::string& error_msg) {
        nlohmann::json j;
        j["msg_type"] = MsgType::LogoutRsp;
        j["error_code"] = error_code;
        j["error_msg"] = error_msg;
        return j.dump();
    }

    static bool from_message(const std::string &msg_str, LogoutRspMsg &logout_rsp_msg) {
        try {
            nlohmann::json j = nlohmann::json::parse(msg_str);
            if (j.at("msg_type").get<MsgType>() == MsgType::LogoutRsp) {
                logout_rsp_msg.error_code = j.at("error_code").get<ErrorCode>();
                logout_rsp_msg.error_msg = j.at("error_msg").get<std::string>();
            } else {
                SPDLOG_WARN("nlohmann::json parse message type error...");
                return false;
            }
        } catch (const std::exception &e) {
            SPDLOG_WARN("nlohmann::json parse message string failed...{}", e.what());
            return false;
        }
        return true;
    }
};

//行情订阅请求
struct SubscribeMsg {
    std::string user_name;
    std::string user_passwd;
    std::vector<std::string> insts;

    static std::string gen_subscribe_msg(const std::string& name, const std::string& passwd, const std::vector<std::string>& insts) {
        nlohmann::json j;
        j["msg_type"] = MsgType::Subscribe;
        j["user_name"] = name;
        j["user_passwd"] = passwd;
        j["insts"] = nlohmann::json::array();
        for (auto &inst : insts) {
          j["insts"].push_back(inst);
        }
        return j.dump();
    }

    static bool from_message(const std::string &msg_str, SubscribeMsg &subs_msg) {
        try {
            nlohmann::json j = nlohmann::json::parse(msg_str);
            if (j.at("msg_type").get<MsgType>() == MsgType::Subscribe) {
                subs_msg.user_name = j.at("user_name").get<std::string>();
                subs_msg.user_passwd = j.at("user_passwd").get<std::string>();
                for (auto &inst : j.at("insts")) {
                    subs_msg.insts.push_back(inst.get<std::string>());
                }
            } else {
                SPDLOG_WARN("nlohmann::json parse message type error...");
                return false;
            }
        } catch (const std::exception &e) {
            SPDLOG_WARN("nlohmann::json parse message string failed...{}", e.what());
            return false;
        }
        return true;
    }
};

//行情订阅响应
struct SubscribeRspMsg {
    ErrorCode error_code;
    std::string error_msg;

    static std::string gen_subscribe_rsp_msg(ErrorCode error_code, const std::string& error_msg) {
        nlohmann::json j;
        j["msg_type"] = MsgType::SubscribeRsp;
        j["error_code"] = error_code;
        j["error_msg"] = error_msg;
        return j.dump();
    }

    static bool from_message(const std::string &msg_str, SubscribeRspMsg &subs_rsp_msg) {
        try {
            nlohmann::json j = nlohmann::json::parse(msg_str);
            if (j.at("msg_type").get<MsgType>() == MsgType::SubscribeRsp) {
                subs_rsp_msg.error_code = j.at("error_code").get<ErrorCode>();
                subs_rsp_msg.error_msg = j.at("error_msg").get<std::string>();
            } else {
                SPDLOG_WARN("nlohmann::json parse message type error...");
                return false;
            }
        } catch (const std::exception &e) {
            SPDLOG_WARN("nlohmann::json parse message string failed...{}", e.what());
            return false;
        }
        return true;
    }
};

//订阅取消请求
struct UnsubscribeMsg {
    std::string user_name;
    std::string user_passwd;
    std::vector<std::string> insts;

    static std::string gen_unsubscribe_msg(const std::string& name, const std::string& passwd, const std::vector<std::string>& insts) {
        nlohmann::json j;
        j["msg_type"] = MsgType::Unsubscribe;
        j["user_name"] = name;
        j["user_passwd"] = passwd;
        j["insts"] = nlohmann::json::array();
        for (auto &inst : insts) {
          j["insts"].push_back(inst);
        }
        return j.dump();
    }

    static bool from_message(const std::string &msg_str, UnsubscribeMsg &unsubs_msg) {
        try {
            nlohmann::json j = nlohmann::json::parse(msg_str);
            if (j.at("msg_type").get<MsgType>() == MsgType::Unsubscribe) {
                unsubs_msg.user_name = j.at("user_name").get<std::string>();
                unsubs_msg.user_passwd = j.at("user_passwd").get<std::string>();
                for (auto &inst : j.at("insts")) {
                    unsubs_msg.insts.push_back(inst.get<std::string>());
                }
            } else {
                SPDLOG_WARN("nlohmann::json parse message type error...");
                return false;
            }
        } catch (const std::exception &e) {
            SPDLOG_WARN("nlohmann::json parse message string failed...{}", e.what());
            return false;
        }
        return true;
    }
};

//订阅取消响应
struct UnsubscribeRspMsg {
    ErrorCode error_code;
    std::string error_msg;

    static std::string gen_unsubscribe_rsp_msg(ErrorCode error_code, const std::string& error_msg) {
        nlohmann::json j;
        j["msg_type"] = MsgType::UnsubscribeRsp;
        j["error_code"] = error_code;
        j["error_msg"] = error_msg;
        return j.dump();
    }

    static bool from_message(const std::string &msg_str, UnsubscribeRspMsg &unsubs_rsp_msg) {
        try {
            nlohmann::json j = nlohmann::json::parse(msg_str);
            if (j.at("msg_type").get<MsgType>() == MsgType::UnsubscribeRsp) {
                unsubs_rsp_msg.error_code = j.at("error_code").get<ErrorCode>();
                unsubs_rsp_msg.error_msg = j.at("error_msg").get<std::string>();
            } else {
                SPDLOG_WARN("nlohmann::json parse message type error...");
                return false;
            }
        } catch (const std::exception &e) {
            SPDLOG_WARN("nlohmann::json parse message string failed...{}", e.what());
            return false;
        }
        return true;
    }
};

//心跳消息
struct HeartbeatMsg {
    std::string user_name;
    static std::string gen_heartbeat_msg(const std::string& user_name) {
        nlohmann::json j;
        j["msg_type"] = MsgType::HeartBeat;
        j["user_name"] = user_name;
        return j.dump();
    }

    static bool from_message(const std::string &msg_str, HeartbeatMsg &hb_msg) {
        try {
            nlohmann::json j = nlohmann::json::parse(msg_str);
            if (j.at("msg_type").get<MsgType>() == MsgType::HeartBeat) {
                hb_msg.user_name = j.at("user_name").get<std::string>();
            } else {
                SPDLOG_WARN("nlohmann::json parse message type error...");
                return false;
            }
        } catch (const std::exception &e) {
            SPDLOG_WARN("nlohmann::json parse message string failed...{}", e.what());
            return false;
        }
        return true;
    }
};

//心跳响应消息
struct HeartbeatRspMsg {
    ErrorCode error_code;
    std::string error_msg;

    static std::string gen_heartbeat_rsp_msg(ErrorCode error_code, const std::string& error_msg) {
        nlohmann::json j;
        j["msg_type"] = MsgType::HeartBeatRsp;
        j["error_code"] = error_code;
        j["error_msg"] = error_msg;
        return j.dump();
    }

    static bool from_message(const std::string &msg_str, HeartbeatRspMsg &hb_rsp_msg) {
        try {
            nlohmann::json j = nlohmann::json::parse(msg_str);
            if (j.at("msg_type").get<MsgType>() == MsgType::HeartBeatRsp) {
                hb_rsp_msg.error_code = j.at("error_code").get<ErrorCode>();
                hb_rsp_msg.error_msg = j.at("error_msg").get<std::string>();
            } else {
                SPDLOG_WARN("nlohmann::json parse message type error...");
                return false;
            }
        } catch (const std::exception &e) {
            SPDLOG_WARN("nlohmann::json parse message string failed...{}", e.what());
            return false;
        }
        return true;
    }
};

struct TickData {
    char trading_day[DATE_LEN];                 //交易日
    uint64_t update_time;                       //数据生成时间
    char instrument_id[INSTRUMENT_ID_LEN];      //合约ID
    char exchange_id[EXCHANGE_ID_LEN];          //交易所ID
    char product_id[PRODUCT_ID_LEN];
    double last_price;                          //最新价
    double pre_settlement_price;                //昨结价
    double pre_close_price;                     //昨收价
    double pre_open_interest;                   //昨持仓量
    double open_price;                          //今开盘
    double high_price;                          //最高价
    double low_price;                           //最低价
    int64_t volume;                             //数量
    double turnover;                            //成交金额
    double open_interest;                       //持仓量
    double close_price;                         //收盘价
    double settlement_price;                    //结算价
    double upper_limit_price;                   //涨停板价
    double lower_limit_price;                   //跌停板价

    double bid_price[5];                        //申买价
    double ask_price[5];                        //申卖价
    int64_t bid_volume[5];                      //申买量
    int64_t ask_volume[5];                      //申卖量
    
    double mark_price = 0;
    double mark_iv = 0;
    double underlying_price = 0;
    double bid_iv = 0;
    double ask_iv = 0;
    double delta = 0;
    double gamma = 0;
    double theta = 0;
    double vega = 0;
    InstrumentType instrument_type;
    
    std::string to_string() const {
        nlohmann::json j;
        j["msg_type"] = MsgType::Tick;
        j["trading_day"] = trading_day;
        j["update_time"] = update_time;
        j["instrument_id"] = instrument_id;
        j["exchange_id"] = exchange_id;
        j["product_id"] = product_id;
        j["last_price"] = last_price;
        j["open_price"] = open_price;
        j["high_price"] = high_price;
        j["low_price"] = low_price;
        j["volume"] = volume;
        j["turnover"] = turnover;
        j["open_interest"] = open_interest;
        j["bid_price_1"] = bid_price[0];
        j["ask_price_1"] = ask_price[0];
        j["bid_volume_1"] = bid_volume[0];
        j["ask_volume_1"] = ask_volume[0];
        j["mark_price"] = mark_price;
        j["instrument_type"] = instrument_type;
        if (instrument_type == InstrumentType::StockOption) {
            j["mark_iv"] = mark_iv;
            j["underlying_price"] = underlying_price;
            j["bid_iv"] = bid_iv;
            j["ask_iv"] = ask_iv;
            j["delta"] = delta;
            j["gamma"] = gamma;
            j["theta"] = theta;
            j["vega"] = vega;
        }
        return j.dump();
    }
};

#endif //MESSAGE_H
