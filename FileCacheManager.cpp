//
// Created by michal on 14/01/2020.
//

#include "FileCacheManager.h"
FileCacheManager::FileCacheManager(int capacity) {
    this->size = capacity;
}

bool FileCacheManager::isResolved(string problem) {
    return !(myCache.find(problem) == myCache.end());
}



string FileCacheManager::popSolution(string problem) {
    string solution = myCache[problem].first;
    saveSolution(problem, solution);
    return solution;
}

void FileCacheManager::saveSolution(string problem, string solution) {
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
    // update reference
    keys.push_front(problem);
    myCache[problem].first = solution;
    myCache[problem].second = keys.begin();
}
