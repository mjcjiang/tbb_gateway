#include <iostream>
#include <thread>
#include <chrono>
#include <zmq.hpp>

zmq::context_t context(1);

void send_thread() {
    zmq::socket_t sender(context, zmq::socket_type::push);
    sender.bind("inproc://my-channel");
    while (true) {
        std::string message("hello, tomorrow!");
        sender.send(zmq::buffer(message), zmq::send_flags::none);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void recv_thread() {
    zmq::socket_t receiver(context, zmq::socket_type::pull);
    receiver.connect("inproc://my-channel");

    while (true) {
        zmq::message_t message;
        receiver.recv(message, zmq::recv_flags::none);
        std::string receivedMessage = std::string(static_cast<char*>(message.data()), message.size());
        std::cout << receivedMessage << std::endl;
    }
}

int main() {
    std::thread send(send_thread);
    std::thread recv(recv_thread);
    send.join();
    recv.join();
    return 0;
}
