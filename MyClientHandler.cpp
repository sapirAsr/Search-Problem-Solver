//
// Created by michal on 24/01/2020.
//

#include "MyClientHandler.h"
#include "AStar.h"

void MyClientHandler::handleClient(int input) {
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

MyClientHandler::MyClientHandler(CacheManager *cache, Solver<Searchable<Position>*,
        vector<State<Position>*>>* solver) {
    this->cacheManager = cache;
    this->solver = solver;
}

vector<vector<double>> MyClientHandler::createMatrix(deque<string> mat) {
    vector<vector<double>> matrix;
    string line;
    while (!mat.empty()) {
        line = mat.back();
        mat.pop_back();
        vector<double> row;
        int len = line.length();
        string sub;
        for (int i = 0; i < len; ++i) {
            if (line[i] == ',') {
                row.push_back(stod(sub));
                sub = "";
            } else {
                sub += line[i];
            }
        }
        row.push_back(stod(sub));
        matrix.push_back(row);
    }
    return matrix;
}

Position MyClientHandler::createPosition(string line) {
    string x;
    string y;
    int flag = 0;
    int len = line.length();
    for (int i = 0; i < len; ++i) {
        if (line[i] != ',' && flag == 0) {
            x += line[i];
        } else if (line[i] == ',') {
            flag = 1;
        } else if (line[i] != ',' && flag == 1) {
            y += line[i];
        }
    }
    return Position(stoi(x), stoi(y));
}

bool MyClientHandler::Find(string str) {
    int len = str.length();
    for (int i = 0; i < len - 2; ++i) {
        if (str[i] == 'e' && str[i + 1] == 'n' && str[i + 2] == 'd') {
            return true;
        }
    }
    return false;
}

string MyClientHandler::stringMatrix(deque<string> mat) {
    string matrix;
    while (!mat.empty()) {
        matrix += mat.back();
        mat.pop_back();
    }
    return matrix;
}

string MyClientHandler::toStringSolution( vector<State<Position>*> path) {
    string pathPlusCost;
    State<Position>* vertex;
    State<Position>* next;
    int len = path.size();
    int cost = 0;
    for (int i = 0; i < len - 1; ++i) {
        vertex = path.at(i);
        next = path.at(i + 1);
        //next is on the right or the left
        if (vertex->getState().getRow() == next->getState().getRow()) {
            //right
            if (vertex->getState().getCol() == next->getState().getCol() - 1) {
                pathPlusCost += "Right (" + to_string((int)(vertex->getCost() + next->getCost()) + cost) + "), ";
            } else if (vertex->getState().getCol() == next->getState().getCol() + 1) {
                pathPlusCost += "Left (" + to_string((int)(vertex->getCost() + next->getCost()) + cost) + "), ";
            }
        } //next is down or up
        else if (vertex->getState().getCol() == next->getState().getCol()) {
            //up
            if (vertex->getState().getRow() == next->getState().getRow() + 1) {
                pathPlusCost += "Up (" + to_string((int)(vertex->getCost() + next->getCost()) + cost) + "), ";
            } else if (vertex->getState().getRow() == next->getState().getRow() - 1) {
                pathPlusCost += "Down (" + to_string((int)(vertex->getCost() + next->getCost()) + cost) + "), ";
            }
        }
        cost += (int)(vertex->getCost());
    }
    return pathPlusCost;
}

ClientHandler* MyClientHandler::clone() {
    return new MyClientHandler(this->cacheManager, solver->clone());
}