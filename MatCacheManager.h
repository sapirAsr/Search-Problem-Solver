//
// Created by michal on 24/01/2020.
//

#ifndef MILESTONE2_MATCACHEMANAGER_H
#define MILESTONE2_MATCACHEMANAGER_H


#include "CacheManager.h"

using namespace std;

class MatCacheManager : public CacheManager {
private:
    fstream file;
    unordered_map<string, int> matrices;
    hash<string> hasher;
public:
    bool isResolved(string problem);
    string popSolution(string problem, string name);
    void saveSolution(string problem, string solution, string name);
    int problemKeyString(string mat);
    };


#endif //MILESTONE2_MATCACHEMANAGER_H
