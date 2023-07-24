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

class CustomPushSocket {
public:
    CustomPushSocket():context(1), socket(context, ZMQ_PUSH) {}

    bool bind() {
        try {
            socket.bind("tcp://*:0");
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
            auto res = socket.send(zmqMessage, zmq::send_flags::none);
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
};

class CustomPullSocket {
public:
    CustomPullSocket(const std::string& conn_addr):context(1), socket(context, ZMQ_PULL), conn_addr(conn_addr) {}

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
        auto res = socket.recv(receivedMessage, zmq::recv_flags::none);
        if (!res.has_value()) {
            SPDLOG_INFO("socket(PULL) recv failed...");
            return "";
        }
        std::string message(static_cast<char*>(receivedMessage.data()), receivedMessage.size());
        return message;
    }
private:
    zmq::context_t context;
    zmq::socket_t socket;
    std::string conn_addr;
};

#endif //CUSTOME_SOCKET_H
