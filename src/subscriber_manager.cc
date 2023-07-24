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
    auto it = sock_table_.find(user_name);
    if (it != sock_table_.end()) {        
        return ErrorCode::ALREADY_LOGIN;
    } else {
        SockControlBlock ctl_block;
        sock_table_.insert({user_name, ctl_block});
    }
    return ErrorCode::NO_ERROR;
}

int SubscriberManager::delete_user(const std::string& user_name) {
    return 0;
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
    
