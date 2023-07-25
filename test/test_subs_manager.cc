#include <string>
#include <iostream>
#include "subscriber_manager.h"

int main() {
    SubscriberManager mng;
    mng.add_user("first_user");

    std::string push_addr;
    mng.get_sock_address("first_user", push_addr);

    std::cout << "user_name: " << "first_user" << std::endl;
    std::cout << "push_addr: " << push_addr << std::endl;
    return 0;
}
