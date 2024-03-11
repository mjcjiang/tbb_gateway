/**
 * @file custome_socket.h
 * @brief define some custome socket class
 *
 * @date 2023-07-24
 */

#ifndef CUSTOME_SOCKET_H
#define CUSTOME_SOCKET_H

#include <zmq.hpp>
#include <string>
#include <spdlog/spdlog.h>

class CustomRepSocket {
public:
    CustomRepSocket(const std::string &bind_addr = "tcp://*:0",
                    const zmq::recv_flags& recv_flags = zmq::recv_flags::none,
                    const zmq::send_flags& send_flags = zmq::send_flags::dontwait)
        :context(1), socket(context, ZMQ_REP), bind_addr(bind_addr), recv_flags(recv_flags), send_flags(send_flags) {
    }

    bool bind() {
        try {
            socket.bind(bind_addr);
            bind_addr = socket.get(zmq::sockopt::last_endpoint);
            SPDLOG_INFO("socket(REP) bind to {}", bind_addr);
            return true;
        } catch (const zmq::error_t &ex) {
            SPDLOG_INFO("socket(REP) bind failed...");
            return false;
        }
    }

    //bool recv() {}
private:
    zmq::context_t context;
    zmq::socket_t socket;
    std::string bind_addr;
    zmq::send_flags send_flags;
    zmq::recv_flags recv_flags;
};

class CustomPushSocket {
public:
    //默认让zmq自动绑定地址，当系统恢复时，可以手动传入特定地址
    //默认发送flags是none
    CustomPushSocket(const std::string& bind_addr = "tcp://*:0", const zmq::send_flags& flag = zmq::send_flags::none)
        :context(1), socket(context, ZMQ_PUSH), bind_addr(bind_addr), send_flags(flag) {}

    bool bind() {
        try {
            socket.bind(bind_addr);
            bind_addr = socket.get(zmq::sockopt::last_endpoint);
            SPDLOG_INFO("socket(PUSH) bind to {}", bind_addr);
            return true;
        } catch (const zmq::error_t& ex) {
            SPDLOG_INFO("socket(PUSH) bind failed...");
            return false;
        }
    }

    bool send(const std::string& message) {
        try {
            zmq::message_t zmqMessage(message.size());
            memcpy(zmqMessage.data(), message.data(), message.size());
            auto res = socket.send(zmqMessage, send_flags);
            if (!res.has_value()) {
                SPDLOG_INFO("socket(PUSH) send failed...");
                return false;
            }
            return true;
        } catch (const zmq::error_t& ex) {
            return false;
        }
    }

    std::string get_bind_address() {
        return bind_addr;
    }
private:
    zmq::context_t context;
    zmq::socket_t socket;
    std::string bind_addr;
    zmq::send_flags send_flags;
};

class CustomPullSocket {
public:
    CustomPullSocket(const std::string& conn_addr, const zmq::recv_flags& recv_flags = zmq::recv_flags::none):
        context(1), socket(context, ZMQ_PULL), conn_addr(conn_addr), recv_flags(recv_flags) {}

    bool connect() {
        try {
            socket.connect(conn_addr.c_str());
            SPDLOG_INFO("socket(PULL) connect to {}", conn_addr);
            return true;
        } catch (const zmq::error_t& ex) {
            SPDLOG_INFO("socket(PULL) connect failed...");
            return false;
        }
    }

    std::string recv() {
        zmq::message_t receivedMessage;
        auto res = socket.recv(receivedMessage, recv_flags);
        if (!res.has_value()) {
            return "";
        }
        std::string message(static_cast<char*>(receivedMessage.data()), receivedMessage.size());
        return message;
    }
private:
    zmq::context_t context;
    zmq::socket_t socket;
    std::string conn_addr;
    zmq::recv_flags recv_flags;
};

#endif //CUSTOME_SOCKET_H
