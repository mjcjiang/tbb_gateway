#include "custome_socket.h"
#include <spdlog/spdlog.h>
#include <thread>
#include <chrono>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        SPDLOG_ERROR("argc wrong");
        return 1;
    }

    std::thread th([]() {
        while (true) {
            std::cout << "In another thread" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    });

    CustomPullSocket socket(argv[1]);
    if (socket.connect()) {
        while(1) {
            std::string recv_msg = socket.recv();
            SPDLOG_INFO("recv msg: {}", recv_msg);
        }
    }
    return 0;
}
