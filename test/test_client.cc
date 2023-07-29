#include <thread>
#include <chrono>
#include <nlohmann/json.hpp>
#include "message.h"
#include "spdlog/spdlog.h"
#include "zmq.hpp"
#include "custome_socket.h"

using json = nlohmann::json;

void send_request(zmq::socket_t& socket, const std::string &msg) {
    zmq::message_t rsp_msg(msg.size());
    memcpy(rsp_msg.data(), msg.data(), msg.size());
    socket.send(rsp_msg, zmq::send_flags::none);
}

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::req);
    socket.connect("tcp://localhost:5566");

    std::string user_name = "zhangjiang";
    std::string user_passwd = "never_stop_learning";

    //登陆
    std::string login_msg = LoginMsg::gen_login_msg(user_name, user_passwd);
    SPDLOG_INFO("Client send login request: {}", login_msg);
    send_request(socket, login_msg);

    //接收登陆响应
    zmq::message_t response;
    zmq::recv_result_t recv_res = socket.recv(response, zmq::recv_flags::none);
    std::string receivedMsg(static_cast<char*>(response.data()), response.size());

    LoginRspMsg loginRsp;
    bool parse_res = LoginRspMsg::from_message(receivedMsg, loginRsp);
    if (parse_res) {
        SPDLOG_INFO("error_code: {}, error_msg: {}, push_address: {}",
                    static_cast<int>(loginRsp.error_code),
                    loginRsp.error_msg,
                    loginRsp.push_address);
        if (loginRsp.error_code != ErrorCode::NO_ERROR) {
            return 1;
        }
    }

    //行情订阅
    std::vector<std::string> insts = {"IF2308"};
    std::string subs_msg = SubscribeMsg::gen_subscribe_msg(user_name, user_passwd, insts);
    SPDLOG_INFO("Client send subscribe request: {}", subs_msg);
    send_request(socket, subs_msg);

    //行情订阅响应
    zmq::message_t subs_response;
    zmq::recv_result_t recv_subs_res = socket.recv(subs_response, zmq::recv_flags::none);
    std::string receivedSubsMsg(static_cast<char*>(subs_response.data()), subs_response.size());

    SubscribeRspMsg subsRsp;
    SubscribeRspMsg::from_message(receivedSubsMsg, subsRsp);
    SPDLOG_INFO("error_code: {}, error_msg: {}", static_cast<int>(subsRsp.error_code), subsRsp.error_msg);

    //定时向服务端发送心跳
    std::thread hb_send([&socket, &user_name]() {
        while (true) {
            std::string hb_str = HeartbeatMsg::gen_heartbeat_msg(user_name);
            send_request(socket, hb_str);

            zmq::message_t hbRsp;
            zmq::recv_result_t recv_res = socket.recv(hbRsp, zmq::recv_flags::none);
            std::string hbRspStr(static_cast<char*>(hbRsp.data()), hbRsp.size());

            HeartbeatRspMsg hb_rsp_msg;
            HeartbeatRspMsg::from_message(hbRspStr, hb_rsp_msg);
            if (hb_rsp_msg.error_code != ErrorCode::NO_ERROR) {
                SPDLOG_WARN("HeartBeat Rsponse with error code: {}", static_cast<int>(hb_rsp_msg.error_code));
            }
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    });
    
    //开始接收行情
    if (subsRsp.error_code == ErrorCode::NO_ERROR) {
        CustomPullSocket pull_socket(loginRsp.push_address);
        if (pull_socket.connect()) {
            while (true) {
                std::string recv_msg = pull_socket.recv();
                if (recv_msg == "") {
                    continue;
                } else {
                    SPDLOG_INFO("recv_msg: {}", recv_msg);
                }
            }
        }
    }

    hb_send.join();
}
