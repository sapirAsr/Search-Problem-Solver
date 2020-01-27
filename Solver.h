//
// Created by michal on 14/01/2020.
//

#ifndef EX4_1_SOLVER_H
#define EX4_1_SOLVER_H

#include <iostream>
#include "Searcher.h"

using namespace std;

template <class T, class S>class Solver {
public:
    S virtual solve(T problem) = 0;
    virtual string getClassName() = 0;
    virtual Solver* clone() = 0;
    virtual int getSearcherNodes() = 0;

    };



#endif //EX4_1_SOLVER_H
