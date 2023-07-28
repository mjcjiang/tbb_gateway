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

constexpr int CLIENT_DELAY_MAX = 20;      //客户端心跳超时上限
constexpr int CLIENT_CHECK_INTERVAL = 5;  //检查客户端超时的时间间隔

//zeromq socket通信控制类
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
    bool is_binded = false;
};

//通信控制表,key是用户名,value是对该用户的通信控制模块
using SocketControlTable = concurrent_hash_map<std::string, SockControlBlock>;
//订阅用户列表
using UserList = concurrent_hash_map<std::string, int>;
//产品订阅管理表, key是产品名称，value是订阅用户列表
using SubscribeTable = concurrent_hash_map<std::string, UserList>;

class SubscriberManager {
public:
    //处理新用户登陆
    ErrorCode add_user(const std::string& user_name);
    //处理用户退出（主动或被动）
    ErrorCode delete_user(const std::string& user_name);
    //获取指定用户的通信控制模块
    SockControlBlock* get_control_block(const std::string& user_name);
    //初始化订阅表中某个产品的订阅列表
    ErrorCode initialize_subscribe_table(const std::string& inst);
    //处理用户行情订阅消息
    ErrorCode process_subscribe(const std::string& user_name, const std::vector<std::string>& insts);
    //处理用户行情退定消息
    ErrorCode process_unsubscribe(const std::string& user_name, const std::vector<std::string>& insts);
    //辅助函数：查看当前行情订阅情况
    void tell_subscriber_info();
    //获取zeromq push socket所绑定的地址信息
    ErrorCode get_sock_address(const std::string& user_name, std::string& push_address);
    //设置指定用户的保活时间戳
    ErrorCode set_live_stamp(const std::string& user_name);
    //用户活跃情况检查
    void check_user_alive();
    //根据instrument_id进行消息推送
    void push_message(const std::string& inst_id, const std::string& message);
private:
    SocketControlTable sock_table_;
    SubscribeTable subs_table_;
};

#endif //SUBSCRIBE_MANAGER_H

