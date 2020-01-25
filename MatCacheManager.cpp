//
// Created by michal on 24/01/2020.
//

#include "MatCacheManager.h"

bool MatCacheManager::isResolved(string problem) {
    return this->matrices.find(problem) == this->matrices.end() ? false : true;
}

string MatCacheManager::popSolution(string problem, string name) {
    string solution;
    int key = this->matrices[problem];
    file.open(name + to_string(key), ios::in | ios::binary);
    if (!file) {
        throw "file doesn't exist";
    } else {
        file.read((char *) &solution, solution.size());
        file.close();
    }
    return solution;
}

void MatCacheManager::saveSolution(string problem, string solution, string name) {
    int val = hasher(problem);
    this->matrices.insert({problem, val});
    // writing to file
    //example of a file name : AStar 4
    file.open(name + to_string(val), ios::out | ios::binary);
    if (!file) {
        throw "File open Error";
    }
    file.write((char*)&solution, sizeof(solution));
    file.close();
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