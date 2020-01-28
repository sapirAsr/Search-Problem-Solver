//
// Created by michal on 14/01/2020.
//

#include "MyTestClientHandler.h"
#include "AStar.h"

/**
 * this func handles with the input we got from the client.
 * @param input an int we pass to the read method.
 */
void MyTestClientHandler::handleClient(int input) {
    char buffer[1024] = {0};
    read(input, buffer, 1024);
    while (strcmp(buffer, "end\r\n")) {
        string buff = buffer;
        string msg;
        if (this->cacheManager->isResolved(buff, solver->getClassName())) {
            msg = this->cacheManager->popSolution(buff, solver->getClassName());
        } else {
            msg = this->solver->solve(buff);
            this->cacheManager->saveSolution(buff, msg, solver->getClassName());
        }
        //writing back to client
        send(input, msg.c_str(), strlen(msg.c_str()), 0);
        memset(buffer, 0, 1024);
        read(input, buffer, 1024);
        buff = buffer;
    }
    cout<<"end of communication"<<endl;
    close(input);
}

/**
 * constructor
 * @param cache that we will save the solutions inside.
 * @param solver a solver that will solve the matrix problem.
 */
MyTestClientHandler::MyTestClientHandler(CacheManager *cache, Solver<string, string>* solver) {
    this->cacheManager = cache;
    this->solver = solver;
}

/**
 * @return a clone of my test client handler.
 */
ClientHandler* MyTestClientHandler::clone() {
    return new MyTestClientHandler(this->cacheManager, solver->clone());
}
