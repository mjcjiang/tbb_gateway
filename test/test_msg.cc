#include "message.h"
#include "error_table.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::cout << LogMsg::gen_login_msg("hello", "zhangjiang", MsgType::Login) << std::endl;
    std::vector<std::string> subs_insts {"abs", "zhangbs", "zhu"};
    std::cout << SubsMsg::gen_subscribe_msg("hjiang", subs_insts, MsgType::Subscribe) << std::endl;
    std::cout << ServerRsp::gen_response_msg(ErrorCode::NO_ERROR, "zhang jiang", MsgType::LoginRsp) << std::endl;
    return 0;
}
