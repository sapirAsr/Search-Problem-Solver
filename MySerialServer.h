//
// Created by michal on 14/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include "Server.h"

class MySerialServer : public server_side::Server {
public:
    void open(int port, ClientHandler *c);
    void loop(int socketfd,sockaddr_in address, ClientHandler* c);
    void stop(int socketfd);
};


#endif //EX4_MYSERIALSERVER_H
