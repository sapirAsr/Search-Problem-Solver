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

public:
    FileCacheManager(int cap);
    bool isResolved(string problem);
    string popSolution(string problem);
    void saveSolution(string problem, string solution);
};


#endif //EX4_1_FILECACHEMANAGER_H
