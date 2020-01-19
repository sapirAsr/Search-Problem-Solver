//
// Created by michal on 14/01/2020.
//

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int input) {
    queue<string> messages;
    char buffer[1024] = {0};
    read(input, buffer, 1024);
    string buff = buffer;
    string msg;
    int len = buff.length();
    string str;
    for (int i = 0; i < len; ++i) {
        if (buff[i] == '\n') {
            messages.push(str);
            str = "";
        } else {
            str += buff[i];
        }
    }
    while (!messages.empty()) {
        string line = messages.front();
        if (line != "end") {
            if (this->cacheManager->isResolved(line, solver->getClassName())) {
                msg = this->cacheManager->popSolution(line, solver->getClassName());
            } else {
                msg = this->solver->solve(line);
                this->cacheManager->saveSolution(line, msg, solver->getClassName());
            }
            messages.pop();
            //writing back to client
            send(input, msg.c_str(), strlen(msg.c_str()), 0);

        }
    }
    read(input, buffer, 1024);
    buff = buffer;
}

MyTestClientHandler::MyTestClientHandler(CacheManager *cache, Solver<string, string>* solver) {
    this->cacheManager = cache;
    this->solver = solver;
}

