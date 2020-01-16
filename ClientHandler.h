//
// Created by michal on 14/01/2020.
//

#ifndef EX4_1_CLIENTHANDLER_H
#define EX4_1_CLIENTHANDLER_H
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include "fstream"
#include "iostream"
#include "ostream"
using namespace std;

class ClientHandler {
public:
    virtual void handleClient(int input) = 0;
};


#endif //EX4_1_CLIENTHANDLER_H
