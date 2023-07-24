/**
 * @file subsciber_manager.h
 * @brief define class and tools to management market_data 
 * subscribers, use sigleton design pattern
 *
 * @date 2023-07-24
 */

#ifndef SUBSCRIBE_MANAGER_H
#define SUBSCRIBE_MANAGER_H

#include <string>
#include "custome_socket.h"
#include "oneapi/tbb/concurrent_map.h"
#include "oneapi/tbb/concurrent_vector.h"

using namespace oneapi::tbb;

using SocketTable = concurrent_map<std::string, CustomPushSocket>;
using SubscribeTable = concurrent_map<std::string, concurrent_vector<std::string>>;

class SubscriberManager {
 public:
    int add_user(const std::string& user_name);
    int delete_user(const std::string& user_name);
    int get_push_address(const std::string& user_name, std::string& push_address);
 private:
    SocketTable sock_table_;
    SubscribeTable subs_table_;
};

#endif //SUBSCRIBE_MANAGER_H

