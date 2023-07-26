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
#include "error_table.h"
#include "custome_time.h"

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
    HeartBeatRsp = 109
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
};

//行情订阅请求
struct SusbcribeMsg {
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
};

//行情订阅响应
struct SusbcribeRspMsg {
    ErrorCode error_code;
    std::string error_msg;

    static std::string gen_subscribe_rsp_msg(ErrorCode error_code, const std::string& error_msg) {
        nlohmann::json j;
        j["msg_type"] = MsgType::SubscribeRsp;
        j["error_code"] = error_code;
        j["error_msg"] = error_msg;
        return j.dump();
    }
};

//订阅取消请求
struct UnsusbcribeMsg {
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
};

//订阅取消响应
struct UnsusbcribeRspMsg {
    ErrorCode error_code;
    std::string error_msg;

    static std::string gen_unsubscribe_rsp_msg(ErrorCode error_code, const std::string& error_msg) {
        nlohmann::json j;
        j["msg_type"] = MsgType::UnsubscribeRsp;
        j["error_code"] = error_code;
        j["error_msg"] = error_msg;
        return j.dump();
    }
};

//心跳消息
struct HeartbeatMsg {
  int64_t stamp;

  static std::string gen_heartbeat_msg() {
    nlohmann::json j;
    j["msg_type"] = MsgType::HeartBeat;
    j["stamp"] = TimeProc::get_timestamp_in_seconds();
    return j.dump();
  }
};

//心跳响应消息
struct HeartbeatRspMsg {
    int64_t stamp;

    static std::string gen_heartbeat_msg() {
        nlohmann::json j;
        j["msg_type"] = MsgType::HeartBeatRsp;
        j["stamp"] = TimeProc::get_timestamp_in_seconds();
        return j.dump();
    }
};


struct SubsMsg {
    std::string user_name;
    std::vector<std::string> instruments;

    static std::string gen_subscribe_msg(const std::string& user_name, const std::vector<std::string>& insts, MsgType type) {
        nlohmann::json j;
        j["msg_type"] = type;
        j["user_name"] = user_name;
        j["instruments"] = nlohmann::json::array();
        for(auto& inst : insts) {
            j["instruments"].push_back(inst);
        }
        return j.dump();
    }
};

struct ServerRsp {
    int error_code;
    std::string error_msg;

    static std::string gen_response_msg(ErrorCode code, const std::string& msg, MsgType type) {
        nlohmann::json j;
        j["msg_type"] = type;
        j["error_code"] = code;
        j["error_msg"] = msg;
        return j.dump();
    }
 };

#endif //MESSAGE_H
