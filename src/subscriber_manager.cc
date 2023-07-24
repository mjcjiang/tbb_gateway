#include "subscriber_manager.h"
#include "error_table.h"

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
    return push_sock_->bind();
}

bool SockControlBlock::send(const std::string &message) {
    return push_sock_->send(message);
}

std::string SockControlBlock::get_bind_addr() {
    return push_sock_->get_bind_address();
}

ErrorCode SubscriberManager::add_user(const std::string& user_name) {
    SocketControlTable::accessor a;
    bool res = sock_table_.find(a, user_name);
    if (res) {
        //already have the key in hash table
        return ErrorCode::ALREADY_LOGIN;
    } else {
        sock_table_.insert(user_name, SockControlBlock());
        bool res = sock_table_[user_name].bind();
        if (!res) {
            SPDLOG_INFO("Socket bind failed... Delete control block");
            sock_table_.erase(user_name);
        }
    }
    return ErrorCode::NO_ERROR;
}

ErrorCode SubscriberManager::delete_user(const std::string& user_name) {
    auto it = sock_table_.find(user_name);
    if (it != sock_table_.end()) {   
        sock_table_.erase(user_name);
    } else {
        return ErrorCode::INVALID_USER;
    }
    return ErrorCode::NO_ERROR;
}

int SubscriberManager::get_push_address(const std::string& user_name, std::string& push_address) {
    return 0;
}

int SubscriberManager::process_subscribe(const std::string &user_name, const std::vector<std::string> &insts) {
    return 0;
}

int SubscriberManager::process_unsubscribe(const std::string& user_name, const std::vector<std::string>& insts) {
    return 0;
}
    
