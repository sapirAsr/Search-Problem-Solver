//
// Created by michal on 14/01/2020.
//

#include "FileCacheManager.h"

bool FileCacheManager::isResolved(string problem) {
    return this->strings.find(problem) == this->strings.end() ? false : true;
}

string FileCacheManager::popSolution(string problem, string name) {
    string solution;
    int key = this->strings[problem];
    file.open(name + to_string(key), ios::in | ios::binary);
    if (!file) {
        throw "file doesn't exist";
    } else {
        file.read((char *) &solution, solution.size());
        file.close();
    }
    return solution;
}

void FileCacheManager::saveSolution(string problem, string solution, string name) {
    int val = hasher(problem);
    this->strings.insert({problem, val});
    // writing to file
    //example of a file name : StringReverser 4
    file.open(name + to_string(val), ios::out | ios::binary);
    if (!file) {
        throw "File open Error";
    }
    file.write((char*)&solution, sizeof(solution));
    file.close();
}
