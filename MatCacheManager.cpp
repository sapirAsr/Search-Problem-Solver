//
// Created by michal on 24/01/2020.
//

#include "MatCacheManager.h"

bool MatCacheManager::isResolved(string problem, string name) {
    int val = hasher(problem);
    string fileName = name + to_string(val) + ".txt";
    fromFile.open(fileName, ios::in);
    if (fromFile) {
        fromFile.close();
        return true;
    } else {
        return false;
    }
}

string MatCacheManager::popSolution(string problem, string name) {
    string solution;
    string temp;
    int key = hasher(problem);
    string fileName = name + to_string(key) + ".txt";
    fromFile.open(fileName);
    if (!fromFile.is_open()) {
        throw "file doesn't exist";
    } else {
        while (!fromFile.eof()) {
            fromFile >> temp;
            solution += temp;
            temp = "";
        }
    }
    fromFile.close();
    //solution += "\r\n";
    return solution;
}

void MatCacheManager::saveSolution(string problem, string solution, string name) {
    int val = hasher(problem);
    // writing to file
    //example of a file name : Astar 4
    string fileName = name + to_string(val) + ".txt";
    toFile.open(fileName);
    if (!toFile) {
        cout<<"failed to open file"<<endl;
        return;
    }
    toFile<<solution;
    toFile.close();
}

int MatCacheManager::problemKeyString(string mat) {
    int val;
    if (this->matrices.find(mat) != this->matrices.end()) {
        val = this->matrices[mat];
    } else { // if the problem not in hash map
        val = -1;
    }
    return val;
}