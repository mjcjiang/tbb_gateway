#include "subscriber_manager.h"
#include "custome_time.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <boost/interprocess/sync/file_lock.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>

SockControlBlock::SockControlBlock(const std::string& sock_addr)
    :push_sock_(std::make_shared<CustomPushSocket>(sock_addr, zmq::send_flags::dontwait)),
     sock_addr_(sock_addr) {
}

void SockControlBlock::set_msg_stamp(uint64_t stamp) {
    last_msg_stamp_ = stamp;
}

uint64_t SockControlBlock::get_msg_stamp() {
    return last_msg_stamp_;
}

bool SockControlBlock::bind() {
    if (!is_binded) {
        //如果sockets还没有绑定，先绑定
        is_binded = true;
        return push_sock_->bind();
    }
    return true;
}

bool SockControlBlock::send(const std::string &message) {
    return push_sock_->send(message);
}

std::string SockControlBlock::get_bind_addr() {
    return push_sock_->get_bind_address();
}

ErrorCode SubscriberManager::add_user(const std::string& user_name) {
    SocketControlTable::accessor a;
    bool isFound = sock_table_.find(a, user_name);

    if (isFound) {
        return ErrorCode::ALREADY_LOGIN;
    } else {
        const auto itemIsNew = sock_table_.insert(a, user_name);
        if (itemIsNew) {
            //创建通信控制模块实体
            a->second = SockControlBlock();

            //zeromq socket地址绑定
            bool bindRes = a->second.bind();
            if (!bindRes) {
                SPDLOG_INFO("Socket bind failed... Delete control block");
                sock_table_.erase(a);
                return ErrorCode::BINDING_FAIL;
            }

            //设置保活时间戳
            a->second.set_msg_stamp(TimeProc::get_timestamp_in_seconds());
        }
    }
    return ErrorCode::NO_ERROR;
}

ErrorCode SubscriberManager::delete_user(const std::string& user_name) {
    SocketControlTable::accessor a;
    bool isFound = sock_table_.find(a, user_name);
    if (isFound) {
        //删除通信控制表中相应用户的信息
        bool eraseRes = sock_table_.erase(a);
        if (!eraseRes)
            return ErrorCode::ERASE_FAIL;

        //如果订阅者列表中有该用户信息，也删除
        for(auto& users_it: subs_table_) {
            UserList::accessor u;
            bool isSubscribed = users_it.second.find(u, user_name);
            if (isSubscribed) {
                bool eraseRes = users_it.second.erase(u);
                if (!eraseRes)
                    return ErrorCode::ERASE_FAIL;
            }
        }
    } else {
        return ErrorCode::INVALID_USER;
    }

    return ErrorCode::NO_ERROR;
}

ErrorCode SubscriberManager::get_sock_address(const std::string& user_name, std::string& push_address) {
    SocketControlTable::accessor a;
    bool isFound = sock_table_.find(a, user_name);

    if (isFound) {
        push_address = a->second.get_bind_addr();
    } else {
        return ErrorCode::INVALID_USER;
    }
    
    return ErrorCode::NO_ERROR;
}

SockControlBlock* SubscriberManager::get_control_block(const std::string& user_name) {
    SocketControlTable::accessor a;
    bool isFound = sock_table_.find(a, user_name);

    if (isFound) {
        return &a->second;
    }    
    return nullptr;
}

ErrorCode SubscriberManager::initialize_subscribe_table(const std::string& inst) {
    SubscribeTable::accessor s;
    bool isSubscribed = subs_table_.find(s, inst);
    if (!isSubscribed) {
        //表中不存在对该产品的订阅
        const auto itemIsNew = subs_table_.insert(s, inst);
        if (itemIsNew) {
            s->second = UserList();
        }
    }
    return ErrorCode::NO_ERROR;
}
 
ErrorCode SubscriberManager::process_subscribe(const std::string &user_name, const std::vector<std::string> &insts) {
    SocketControlTable::accessor a;
    bool isLogin = sock_table_.find(a, user_name);
    if (isLogin) {
        //用户已经登陆
        for (auto &inst : insts) {
            SubscribeTable::accessor b;
            bool isSubscribed = subs_table_.find(b, inst);
            if (isSubscribed) {
                //已经存在该产品行情的用户订阅
                UserList::accessor u;
                bool isBooked = b->second.find(u, user_name);
                if (!isBooked) {
                    b->second.insert({user_name, 1});
                }
            } else {
                //不存在该产品行情的用户订阅,添加新的用户订阅
                const auto itemIsNew = subs_table_.insert(b, inst);
                if (itemIsNew) {
                    b->second = UserList();
                    b->second.insert({user_name, 1});
                }
            }
        }
    } else {
        //用户尚未登陆
        SPDLOG_WARN("user {} have not logged in...", user_name);
        return ErrorCode::INVALID_USER;
    }

    return ErrorCode::NO_ERROR;
}

ErrorCode SubscriberManager::process_unsubscribe(const std::string& user_name, const std::vector<std::string>& insts) {
    SocketControlTable::accessor a;
    bool isLogin = sock_table_.find(a, user_name);
    if (isLogin) {
        //用户已经登陆
        for (auto &inst : insts) {
            SubscribeTable::accessor b;
            bool isSubscribed = subs_table_.find(b, inst);
            if (isSubscribed) {
                //该产品存在订阅用户
                UserList::accessor u;
                bool isBooked = b->second.find(u, user_name);
                if (isBooked) {
                    //确认该用户已经订阅了该产品, 删除订阅记录
                    bool eraseRes = b->second.erase(u);
                    if (!eraseRes) {
                      return ErrorCode::ERASE_FAIL;
                    }
                }
            }
        }
    }
    return ErrorCode::NO_ERROR;
}

void SubscriberManager::tell_subscriber_info() {
    std::cout << "-----------subscribers infomation of mamager----------------\n"; 
    for(const auto& subs_it : subs_table_) {
        std::cout << "Inst: " << subs_it.first << std::endl;
        std::cout << "Subscriber: ";
        for (const auto& users_it: subs_it.second) {
            std::cout << users_it.first << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------------------------------------------\n"; 
}

ErrorCode SubscriberManager::set_live_stamp(const std::string &user_name) {
    SocketControlTable::accessor a;
    bool isLogin = sock_table_.find(a, user_name);
    if (isLogin) {
        a->second.set_msg_stamp(TimeProc::get_timestamp_in_seconds());
        SPDLOG_INFO("{} set_msg_stamp in {}", user_name, TimeProc::get_timestamp_in_seconds());
    } else {
        return ErrorCode::INVALID_USER;
    }
    return ErrorCode::NO_ERROR;
}

void SubscriberManager::check_user_alive() {
    std::vector<std::string> delayed_users;
    
    uint64_t cur_stamp = TimeProc::get_timestamp_in_seconds();
    for(auto& sock_it : sock_table_) {
        uint64_t prev_stamp = sock_it.second.get_msg_stamp();
        if ((cur_stamp - prev_stamp) > CLIENT_DELAY_MAX) {
            SPDLOG_WARN("User {} not alive anymore, cur_stamp:{}, prev_stamp: {}..., remove user",
                        sock_it.first, cur_stamp, prev_stamp);
            delayed_users.push_back(sock_it.first);
        } 
    }
    
    for (auto& user : delayed_users) {
        //删除通信控制表中的超时用户节点
        SocketControlTable::accessor a;

        std::cout << user << std::endl;
        auto isFind = sock_table_.find(a, user);
        if (isFind) {
            sock_table_.erase(a);
        }

        //删除订阅表中超时用户节点
        for(auto& subs_it : subs_table_) {
            UserList::accessor u;
            auto isFind = subs_it.second.find(u, user);
            if (isFind) {
                subs_it.second.erase(u);
            }
        }
        SPDLOG_INFO("{} deleted...", user);
    }
}

void SubscriberManager::push_message(const std::string& inst_id, const std::string& message) {
    SubscribeTable::accessor s;
    bool isSubscribed = subs_table_.find(s, inst_id);
    if (isSubscribed) {
        for(auto& users_it : s->second) {
            SocketControlTable::accessor c;
            bool isLogin = sock_table_.find(c, users_it.first);
            if (isLogin) {
                bool send_res = c->second.send(message);
                if (!send_res) {
                    SPDLOG_WARN("Fail send {} of {} to {}", message, inst_id, c->first);
                }
            }
        }
    }
}

void SubscriberManager::save_socket_and_subscribe_table(const std::string &path) {
    boost::interprocess::file_lock fileLock(path.c_str());
    if (fileLock.try_lock()) {
        std::ofstream file(path, std::ios::trunc);
        if (file.is_open()) {      
            nlohmann::json j;
            j["socket_table"] = nlohmann::json::object();
            for (auto &item : sock_table_) {
                j["socket_table"][item.first] = nlohmann::json::object();
                j["socket_table"][item.first]["push_addr"] = item.second.get_bind_addr();
                j["socket_table"][item.first]["live_stamp"] = item.second.get_msg_stamp();
            }

            j["subscribe_table"] = nlohmann::json::object();
            for (auto &item : subs_table_) {
                j["subscribe_table"][item.first] = nlohmann::json::array();
                for (auto &elem : item.second) {
                    j["subscribe_table"][item.first].push_back(elem.first);
                }
            }

            file << j.dump(4);
            file.close();
        } else {
            SPDLOG_WARN("Open file {} for write fail...", path);
        }
        fileLock.unlock();
    }
}

void SubscriberManager::load_socket_and_subscribe_table(const std::string &path) {
    sock_table_.clear();
    subs_table_.clear();
    
    boost::interprocess::file_lock fileLock(path.c_str());
    if (fileLock.try_lock()) {
        std::ifstream file(path);
        if (file.is_open()) {
            nlohmann::json j = nlohmann::json::parse(file);

            //加载通信路由表
            if (j.contains("socket_table")) {
                for (auto& el : j["socket_table"].items()) {
                    SocketControlTable::accessor s;
                    std::string user_name = el.key();
                    bool isLogin = sock_table_.find(s, user_name);
                    if (!isLogin) {
                        uint64_t live_stamp = el.value().at("live_stamp").get<uint64_t>();
                        std::string push_addr = el.value().at("push_addr").get<std::string>();
                        bool isNewItem = sock_table_.insert(s, user_name);
                        if (isNewItem) {
                            s->second = SockControlBlock(push_addr);

                            bool bindRes = s->second.bind();
                            if (!bindRes) {
                              SPDLOG_INFO(
                                  "Socket bind {} failed, Delete control block",
                                  push_addr);
                              sock_table_.erase(s);
                            }

                            s->second.set_msg_stamp(TimeProc::get_timestamp_in_seconds());
                        }
                    }
                }
            }

            //加载用户订阅表
            if (j.contains("subscribe_table")) {
                for (auto &el : j["subscribe_table"].items()) {
                    SubscribeTable::accessor s;
                    std::string inst = el.key();
                    bool isSubscribed = subs_table_.find(s, inst);
                    if (!isSubscribed) {
                        bool isNewItem = subs_table_.insert(s, inst);
                        if (isNewItem) {
                            s->second = UserList();
                            for (auto &user_name : el.value()) {
                                s->second.insert({user_name, 1});
                            }
                        }
                    }
                }
            }
        }
        fileLock.unlock();
    }
}
