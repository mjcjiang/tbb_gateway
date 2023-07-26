#include "subscriber_manager.h"
#include "custome_time.h"
#include <algorithm>
#include <iostream>

SockControlBlock::SockControlBlock()
    :push_sock_(std::make_shared<CustomPushSocket>()) {
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
