#include "custome_socket.h"
#include <spdlog/spdlog.h>
#include <thread>
#include <chrono>

int main() {
    CustomPushSocket sock;
    sock.bind();
    SPDLOG_INFO("bind address...{}", sock.get_bind_address());

    while(1) {
        sock.send("This is a pushing message...");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
