//
// Created by michal on 14/01/2020.
//

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int input) {
    char buffer[1024] = {0};
    read(input, buffer, 1024);
    string buff = buffer;
    string msg;
    while (buff != "end") {
        if(this->cacheManager->isResolved(buff)){
            msg = this->cacheManager->popSolution(buff);
        } else {
            msg = this->solver->solve(buff);
            this->cacheManager->saveSolution(this->solver->solve(buff), msg);
        }
        //writing back to client
        send(input , msg.c_str() , strlen(msg.c_str()) , 0 );
        read(input, buffer, 1024);
        buff = buffer;
    }
}

MyTestClientHandler::MyTestClientHandler(CacheManager *cache, Solver<string, string>* solver) {
    this->cacheManager = cache;
    this->solver = solver;
}

