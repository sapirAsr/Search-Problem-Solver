//
// Created by michal on 14/01/2020.
//

#include "FileCacheManager.h"
FileCacheManager::FileCacheManager(int capacity) {
    this->size = capacity;
}

bool FileCacheManager::isResolved(string problem, string name) {
    if (myCache.find(problem) == myCache.end()) {
        in_file.open(name + problem, ios::in | ios::binary);
        return !!in_file;
    } else {
        return true;
    }
}

string FileCacheManager::popSolution(string problem, string name) {
    string solution;
    // not in cache
    if (myCache.find(problem) == myCache.end()) {
        int key = this->problems[problem];
        in_file.open(name + to_string(key), ios::in | ios::binary);
        if (!in_file) {
            throw "key not found in cache";
        } else {
            in_file.read((char*)&solution, solution.size());
            in_file.close();
            //update reference
            saveSolution(problem, solution, name);
            return solution;
        }
    } else {
        solution = myCache[problem].first;
        //update reference
        saveSolution(problem, solution, name);
        return solution;
    }
}

void FileCacheManager::saveSolution(string problem, string solution, string name) {
    // not present in cache
    if (myCache.find(problem) == myCache.end()) {
        // cache is full
        if (keys.size() == (unsigned) size) {
            // delete least recently used element
            string last = keys.back();
            // Pops the last element
            keys.pop_back();
            // Erase the last
            myCache.erase(last);
        }
    } // present in cache
    else {
        myCache.erase(problem);
        keys.remove(problem);
    }
    // hashmap from problem to int
    int key;
    // if the problem is in hash map
    if (this->problems.find(problem) != this->problems.end()) {
        key = this->problems[problem];
    } else { // if the problem not in hash map
        key = this->problems.size();
        this->problems.insert({problem, this->problems.size()});
    }
    // update reference
    keys.push_front(problem);
    myCache[problem].first = solution;
    myCache[problem].second = keys.begin();
    // writing to file
    in_file.open(name + to_string(key), ios::out | ios::binary);
    if (!in_file) {
        throw "File open Error";
    }
    in_file.write((char*)&solution, sizeof(solution));
    in_file.close();
}