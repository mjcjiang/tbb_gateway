#include <thread>
#include <nlohmann/json.hpp>
#include "message.h"
#include "spdlog/spdlog.h"
#include "zmq.hpp"

using json = nlohmann::json;

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::req);
    socket.connect("tcp://localhost:5566");

    //登陆
    std::string login_msg = LoginMsg::gen_login_msg("hjiang", "never_stop_learning");
    zmq::message_t login_request(login_msg.size());
    memcpy(login_request.data(), login_msg.data(), login_msg.size());
    SPDLOG_INFO("Client send login request: {}", login_msg);
    zmq::send_result_t send_res = socket.send(login_request, zmq::send_flags::none);

    //接收登陆响应
    zmq::message_t response;
    zmq::recv_result_t recv_res = socket.recv(response, zmq::recv_flags::none);
    std::string receivedMsg(static_cast<char*>(response.data()), response.size());
    
    json j = json::parse(receivedMsg);
    if (j.contains("msg_type")) {
        MsgType msg_type = j.at("msg_type").get<MsgType>();
        if (msg_type == MsgType::LoginRsp) {
            auto error_code = j.at("error_code").get<ErrorCode>();
            auto error_msg = j.at("error_msg").get<std::string>();
            auto push_address = j.at("push_address").get<std::string>();
            SPDLOG_INFO("error_code: {}, error_msg: {}, push_address: {}", static_cast<int>(error_code), error_msg, push_address);
        }
    }
}
