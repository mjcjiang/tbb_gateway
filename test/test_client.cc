#include <thread>
#include "message.h"
#include "spdlog/spdlog.h"
#include "zmq.hpp"

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::req);
    socket.connect("tcp://localhost:5555");

    while (1) {
        std::string login_msg = LogMsg::gen_login_msg("hjiang", "never_stop_learning", MsgType::Login);
        zmq::message_t login_request(login_msg.size());
        memcpy(login_request.data(), login_msg.data(), login_msg.size());
        SPDLOG_INFO("Will send request: {}", login_msg);
        socket.send(login_request);
        
        zmq::message_t response;
        socket.recv(response);
        std::string receivedMsg(static_cast<char*>(response.data()), response.size());
        SPDLOG_INFO("Received response: {}", receivedMsg);

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}
