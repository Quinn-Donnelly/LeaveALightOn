/**
 * This is a proof of concept that when run will await user intput
 * once recieved it will broadcast a message on the tcp port
 */

#include <zmq.hpp>
#include <iostream>
#include <string>

#define PUB_URI "tcp://*:5556"

int main()
{
  zmq::context_t context(1);
  zmq::socket_t publisher(context, ZMQ_PUB);
  publisher.bind(PUB_URI);

  char pauseChar;
  while(true) {
    zmq::message_t message(2);
    memcpy (message.data(), "D", 2);
    std::cout << "\nAwaiting the go ahead Sir!\n";
    std::cin.get(pauseChar);
    std::cout << "\nBLAST EM!!!\n";
    publisher.send(message);
  }

  return 0;
}
