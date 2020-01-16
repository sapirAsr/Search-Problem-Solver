//
// Created by michal on 14/01/2020.
//

#ifndef EX4_1_SOLVER_H
#define EX4_1_SOLVER_H

#include <iostream>
using namespace std;

template <class Problem, class Solution>class Solver {
public:
    Solution virtual solve(Problem problem) = 0;
    virtual string getClassName() = 0;
};



#endif //EX4_1_SOLVER_H
