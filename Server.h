//
// Created by michal on 14/01/2020.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include "ClientHandler.h"

/**
 * this is the server interface.
 */
namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler *c) = 0;
        virtual void stop(int socketfd) = 0;
    };
}

#endif //EX4_SERVER_H
