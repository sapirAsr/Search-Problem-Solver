//
// Created by michal on 14/01/2020.
//

#include "MyTestClientHandler.h"
#include "AStar.h"

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

MyTestClientHandler::MyTestClientHandler(CacheManager *cache, Solver<string, string>* solver) {
    this->cacheManager = cache;
    this->solver = solver;
}

bool MyTestClientHandler::Find(string str) {
    int len = str.length();
    for (int i = 0; i < len - 2; ++i) {
        if (str[i] == 'e' && str[i + 1] == 'n' && str[i + 2] == 'd') {
            return true;
        }
    }
    return false;
}

ClientHandler* MyTestClientHandler::clone() {
    return new MyTestClientHandler(this->cacheManager, solver->clone());
}
