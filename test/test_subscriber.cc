#include "subscriber_manager.h"
#include <vector>

int main() {
    SubscriberManager mng;
    mng.add_user("user_a");
    mng.add_user("user_b");

    std::vector<std::string> user_a_subs = {"IF2308", "IF2309"}; 
    mng.process_subscribe("user_a", user_a_subs);

    std::vector<std::string> user_b_subs = {"IF2308", "IF2309"}; 
    mng.process_subscribe("user_b", user_b_subs);

    std::vector<std::string> user_c_subs = {"IF2308", "IF2309"}; 
    mng.process_subscribe("user_c", user_b_subs);

    mng.tell_subscriber_info();

    std::vector<std::string> user_b_unsubs = {"IF2309"};
    mng.process_unsubscribe("user_b", user_b_unsubs);
    
    mng.tell_subscriber_info();

    mng.delete_user("user_a");
    mng.tell_subscriber_info();
    return 0;
}
