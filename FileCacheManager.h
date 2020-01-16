//
// Created by michal on 14/01/2020.
//

#ifndef EX4_1_FILECACHEMANAGER_H
#define EX4_1_FILECACHEMANAGER_H

#include "CacheManager.h"

class FileCacheManager : public CacheManager {
private:
    unordered_map<string, pair<string, list<string>::iterator>> myCache;
    int size;
    list<string> keys;
    fstream in_file;
    map<string, int> problems;

public:
    FileCacheManager(int cap);
    bool isResolved(string problem, string name);
    string popSolution(string problem, string name);
    void saveSolution(string problem, string solution, string name);
};


#endif //EX4_1_FILECACHEMANAGER_H
