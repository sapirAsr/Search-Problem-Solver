//
// Created by michal on 24/01/2020.
//

#ifndef MILESTONE2_MYPARALLELSERVER_H
#define MILESTONE2_MYPARALLELSERVER_H

#include "Server.h"

class MyParallelServer : public server_side::Server{
private:
    bool stopLoop = false;
public:
    void open(int port, ClientHandler *c);
    void stop(int socketfd);
    void loop(int socketfd,sockaddr_in address, ClientHandler* c);
    void clientTheard(int socketfd, ClientHandler* c);
};


#endif //MILESTONE2_MYPARALLELSERVER_H
