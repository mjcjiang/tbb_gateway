#include "subscriber_manager.h"
#include "custome_time.h"

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
        bool eraseRes = sock_table_.erase(a);
        if (!eraseRes) {
            return ErrorCode::ERASE_FAIL;
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
 
ErrorCode SubscriberManager::process_subscribe(const std::string &user_name, const std::vector<std::string> &insts) {
    //TODO: 处理订阅消息之前，判断用户是否已经登陆
    return ErrorCode::NO_ERROR;
}

ErrorCode SubscriberManager::process_unsubscribe(const std::string& user_name, const std::vector<std::string>& insts) {
    //TODO: 处理退订消息之前，判断用户是否已经登陆
    return ErrorCode::NO_ERROR;
}
