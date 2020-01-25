//
// Created by michal on 14/01/2020.
//

#ifndef EX4_1_FILECACHEMANAGER_H
#define EX4_1_FILECACHEMANAGER_H

#include "CacheManager.h"

class FileCacheManager : public CacheManager {
private:
    fstream file;
    unordered_map<string, int> strings;
    hash<string> hasher;

public:
    bool isResolved(string problem);
    string popSolution(string problem, string name);
    void saveSolution(string problem, string solution, string name);
    int problemKeyString(string mat) {
        return 0;
    }
};


#endif //EX4_1_FILECACHEMANAGER_H
