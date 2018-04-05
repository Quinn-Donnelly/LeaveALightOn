/**
 * Simple subscriber that will await a message from the SUBSCRIPTION_URI
 * then print to screen and exit
 */

#include <zmq.hpp>
#include <iostream>
#include <sstream>

#define SUBSCRIPTION_URI "tcp://localhost:5556"

int main()
{
  zmq::context_t context (1);

  std::cout << "Awaiting the message Sir!\n" << std::endl;
  zmq::socket_t subscriber (context, ZMQ_SUB);
  subscriber.connect(SUBSCRIPTION_URI);

  subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);
  zmq::message_t alert(2);

  subscriber.recv(&alert);

  std::cout << "AH SHIT WE'RE HIT SIR!\n" << std::endl;

  return 0;
}
