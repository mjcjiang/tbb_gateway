#include "custome_socket.h"
#include <spdlog/spdlog.h>
#include <thread>
#include <chrono>
#include <iostream>

int main() {
    CustomPushSocket sock("tcp://0.0.0.0:5666", zmq::send_flags::dontwait);
    sock.bind();
    SPDLOG_INFO("bind address...{}", sock.get_bind_address());

    while(1) {
        sock.send("This is a pushing message...");
        std::cout << "push a message out" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
    return 0;
}
