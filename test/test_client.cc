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

    while (1) {
        std::string login_msg = LoginMsg::gen_login_msg("hjiang", "never_stop_learning");
        zmq::message_t login_request(login_msg.size());
        memcpy(login_request.data(), login_msg.data(), login_msg.size());
        SPDLOG_INFO("Will send request: {}", login_msg);
        socket.send(login_request);
        
        zmq::message_t response;
        socket.recv(response);
        std::string receivedMsg(static_cast<char*>(response.data()), response.size());
        SPDLOG_INFO("Received response: {}", receivedMsg);

        json j = json::parse(receivedMsg);
        if (j.contains("msg_type")) {
            MsgType msg_type = j.at("msg_type").get<MsgType>();

            switch (msg_type) {
            case MsgType::LoginRsp: {
                int error_no = j.at("error_code").get<int>();
                if (error_no == 0) {
                    SPDLOG_INFO("Client login success...");
                } else {
                    std::string error_msg = j.at("error_msg").get<std::string>();
                    SPDLOG_INFO("Client login failed, error msg {}", error_msg);
                }
            }
            break;
            default:
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}
