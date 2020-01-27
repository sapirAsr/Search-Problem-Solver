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
#include "Solver.h"
#include "CacheManager.h"
#include <vector>
#include "Position.h"
#include "Searchable.h"
#include "Searcher.h"
#include "Mat.h"
using namespace std;

/**
 * This is the client Handler interface.
 */
class ClientHandler {

public:
    virtual void handleClient(int input) = 0;
    virtual ClientHandler *clone() = 0;
};


#endif //EX4_1_CLIENTHANDLER_H
