//
// Created by michal on 24/01/2020.
//

#include "MyClientHandler.h"
#include "AStar.h"

/**
 * this func handles with the input we got from the client.
 * @param input an int we pass to the read method.
 */
void MyClientHandler::handleClient(int input) {
    vector<vector<double >> newMat;
    deque<string> messages;
    char buffer[1024] = {0};
    read(input, buffer, 1024);
    string buff = buffer;
    // reading from the client.
    while (!Find(buff)) {
        memset(buffer, 0 , 1024);
        read(input, buffer, 1024);
        buff += buffer;
    }
    string msg;
    int len = buff.length();
    string str;
    //separate the input from the client to lines.
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
    //create a string of the matrix
    string stringMat = this->stringMatrix(messages);
    // if we have a solution we will pop it else we will write it down to a file.
    if (this->cacheManager->isResolved(stringMat, solver->getClassName())) {
        msg = this->cacheManager->popSolution(stringMat, solver->getClassName());
    } else {
        vector<State<Position>*> res = this->solver->solve(matrixSearch);
        msg = this->toStringSolution(res);
        this->cacheManager->saveSolution(stringMat, msg, solver->getClassName());
    }
    send(input, msg.c_str(), strlen(msg.c_str()), 0);
}

/**
 * constructor
 * @param cache that we will save the solutions inside.
 * @param solver a solver that will solve the matrix problem.
 */
MyClientHandler::MyClientHandler(CacheManager *cache, Solver<Searchable<Position>*,
        vector<State<Position>*>>* solver) {
    this->cacheManager = cache;
    this->solver = solver;
}

/**
 * @param mat the lines of the matrix.
 * @return a vector of vectors with all the costs of the edges.
 */
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

/**
 * @param line a string of a vertex in the mat.
 * @return Position of the vertex.
 */
Position MyClientHandler::createPosition(string line) {
    string x;
    string y;
    int flag = 0;
    int len = line.length();
    for (int i = 0; i < len; ++i) {
        //before comma
        if (line[i] != ',' && flag == 0) {
            x += line[i];
        } else if (line[i] == ',') {
            flag = 1;
        } // after comma
        else if (line[i] != ',' && flag == 1) {
            y += line[i];
        }
    }
    return Position(stoi(x), stoi(y));
}

/**
 * @param str string we want to check if contains the word end so we can stop reading from client.
 * @return true/ false.
 */
bool MyClientHandler::Find(string str) {
    int len = str.length();
    for (int i = 0; i < len - 2; ++i) {
        if (str[i] == 'e' && str[i + 1] == 'n' && str[i + 2] == 'd') {
            return true;
        }
    }
    return false;
}

/**
 * @param mat all the lines of the matrix.
 * @return a string of the matrix.
 */
string MyClientHandler::stringMatrix(deque<string> mat) {
    string matrix;
    while (!mat.empty()) {
        matrix += mat.back();
        mat.pop_back();
    }
    return matrix;
}

/**
 * this func returns a string of the path with the cheapest cost.
 * @param path the path we want to create a string for it.
 * @return the string og the path.
 */
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
    pathPlusCost = pathPlusCost.erase(pathPlusCost.length() - 2, 1);
    return pathPlusCost;
}

/**
 * @return a clone of my client handler.
 */
ClientHandler* MyClientHandler::clone() {
    return new MyClientHandler(this->cacheManager, solver->clone());
}