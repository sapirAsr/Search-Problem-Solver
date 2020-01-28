//
// Created by michal on 14/01/2020.
//

#ifndef EX4_1_CACHEMANAGER_H
#define EX4_1_CACHEMANAGER_H
#include <string>
#include<iostream>
#include<string>
#include <map>
#include<iterator>
#include <bits/stdc++.h>
#include "fstream"

using namespace std;

/**
 * This is the cache manager interface.
 */
class CacheManager {

public:
    virtual bool isResolved(string problem, string name) = 0;
    string virtual popSolution(string problem, string name) = 0;
    void virtual saveSolution(string problem, string solution, string name) = 0;
    virtual int problemKeyString(string mat) = 0;
};


#endif //EX4_1_CACHEMANAGER_H
