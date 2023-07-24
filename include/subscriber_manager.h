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
#include <memory>
#include "custome_socket.h"
#include "error_table.h"
#include "oneapi/tbb/concurrent_hash_map.h"
#include "oneapi/tbb/concurrent_vector.h"

using namespace oneapi::tbb;

//socket control block
class SockControlBlock {
public:
    SockControlBlock();
    ~SockControlBlock() = default;
    void set_msg_stamp(uint64_t stamp);
    uint64_t get_msg_stamp();

    bool bind();
    bool send(const std::string& message);
    std::string get_bind_addr();
private:
    std::shared_ptr<CustomPushSocket> push_sock_;
    uint64_t last_msg_stamp_;
};

using NameString = std::basic_string<char, std::char_traits<char>, oneapi::tbb::tbb_allocator<char>>;
using SocketControlTable = concurrent_hash_map<NameString, SockControlBlock>;
using SubscribeTable = concurrent_hash_map<NameString, concurrent_vector<std::string>>;

class SubscriberManager {
public:
    ErrorCode add_user(const std::string& user_name);
    ErrorCode delete_user(const std::string& user_name);

    int process_subscribe(const std::string& user_name, const std::vector<std::string>& insts);
    int process_unsubscribe(const std::string& user_name, const std::vector<std::string>& insts);
    
    int get_push_address(const std::string& user_name, std::string& push_address);
private:
    SocketControlTable sock_table_;
    SubscribeTable subs_table_;
};

#endif //SUBSCRIBE_MANAGER_H

