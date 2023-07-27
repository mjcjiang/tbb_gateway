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
                login_rsp_msg.push_address = j.at("pish_address").get<std::string>();
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

    static bool from_message(const std::string &msg_str, SusbcribeMsg &subs_msg) {
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

    static bool from_message(const std::string &msg_str, SusbcribeRspMsg &subs_rsp_msg) {
        try {
            nlohmann::json j = nlohmann::json::parse(msg_str);
            if (j.at("msg_type").get<MsgType>() == MsgType::LogoutRsp) {
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

    static bool from_message(const std::string &msg_str, UnsusbcribeMsg &unsubs_msg) {
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

    static bool from_message(const std::string &msg_str, UnsusbcribeRspMsg &unsubs_rsp_msg) {
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

#endif //MESSAGE_H
