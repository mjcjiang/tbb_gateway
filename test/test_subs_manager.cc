#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include "subscriber_manager.h"

int main() {
    SubscriberManager mng;
    mng.add_user("first_user");

    std::string push_addr;
    mng.get_sock_address("first_user", push_addr);

    std::cout << "user_name: " << "first_user" << std::endl;
    std::cout << "push_addr: " << push_addr << std::endl;

    SockControlBlock *p_block = mng.get_control_block("first_user");
    if (p_block != nullptr) {
        while(1) {
            p_block->send("zhangjiang pudong");
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    return 0;
}
