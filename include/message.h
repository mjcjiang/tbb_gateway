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

// the login message type, client send to server
struct LogMsg {
    std::string user_name;
    std::string user_passwd;

    static std::string gen_login_msg(const std::string& name, const std::string& passwd, MsgType type) {
        nlohmann::json j;
        j["msg_type"] = type;
        j["user_name"] = name;
        j["user_passwd"] = passwd;
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

    static std::string gen_response_msg(int code, const std::string& msg, MsgType type) {
        nlohmann::json j;
        j["msg_type"] = type;
        j["error_code"] = code;
        j["error_msg"] = msg;
        return j.dump();
    }
 };

#endif //MESSAGE_H
