//
// Created by michal on 14/01/2020.
//

#ifndef EX4_1_MYTESTCLIENTHANDLER_H
#define EX4_1_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
private:
CacheManager* cacheManager;
Solver<string, string>* solver;
public:
    MyTestClientHandler(CacheManager* cache, Solver<string, string>* solver);
    void handleClient(int input);

};


#endif //EX4_1_MYTESTCLIENTHANDLER_H
