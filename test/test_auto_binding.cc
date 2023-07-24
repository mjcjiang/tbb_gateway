#include <zmq.hpp>
#include <string>
#include <iostream>

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PUSH);

    try {
        // Bind the socket to a local address with an automatically assigned port
        socket.bind("tcp://*:0");
        std::string boundAddress = socket.get(zmq::sockopt::last_endpoint);
        std::cout << "Socket bound to: " << boundAddress << std::endl;   
    } catch (const zmq::error_t& ex) {
        std::cerr << "Error binding socket: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
