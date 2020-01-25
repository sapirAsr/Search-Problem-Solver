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
        if (this->cacheManager->isResolved(buff)) {
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
    vector<vector<double >> newMat;
    deque<string> messages;
    char buffer[1024] = {0};
    read(input, buffer, 1024);
    string buff = buffer;
    while (!Find(buff)) {
        memset(buffer, 0 , 1024);
        read(input, buffer, 1024);
        buff += buffer;
    }
    string msg;
    int len = buff.length();
    string str;
    for (int i = 0; i < len; ++i) {
        if (buff[i] == '\n') {
            messages.push_front(str);
            str = "";
        } else {
            str += buff[i];
        }
    }
    messages.pop_front(); // we pop the "end"
    string goal = messages.front();
    messages.pop_front();
    State<Position>* g = new State<Position>(createPosition(goal));
    string init = messages.front();
    messages.pop_front();
    State<Position>* i = new State<Position>(createPosition(init));
    newMat = this->createMatrix(messages);
    Searchable<Position>* matrixSearch = new Mat(newMat, i, g, newMat.size(),
            newMat.at(0).size());
    //vector<State<Position>*> res = solver->solve(matrixSearch);

    string stringMat = this->stringMatrix(messages);
    //int key = this->cacheManager->problemKeyString(stringMat);

    if (this->cacheManager->isResolved(stringMat)) {
        msg = this->cacheManager->popSolution(stringMat, solver->getClassName());
    } else {
        vector<State<Position>*> res = this->solver->solve(matrixSearch);
        //todo
        msg = this->toStringSolution(res);
        this->cacheManager->saveSolution(stringMat, msg, solver->getClassName());
    }
    //writing back to client
    send(input, msg.c_str(), strlen(msg.c_str()), 0);
     }
    */


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
