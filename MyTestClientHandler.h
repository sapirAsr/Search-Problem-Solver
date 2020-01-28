//
// Created by michal on 14/01/2020.
//

#ifndef EX4_1_MYTESTCLIENTHANDLER_H
#define EX4_1_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"

/**
 * this class implement the client handler interface.
 */
class MyTestClientHandler : public ClientHandler {
private:
CacheManager* cacheManager;
Solver<string, string>* solver;
public:
    MyTestClientHandler(CacheManager* cache, Solver<string, string>* solver);
    void handleClient(int input);
    ClientHandler *clone();

};


#endif //EX4_1_MYTESTCLIENTHANDLER_H
