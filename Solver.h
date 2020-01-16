//
// Created by michal on 14/01/2020.
//

#ifndef EX4_1_SOLVER_H
#define EX4_1_SOLVER_H

template <class Problem, class Solution>class Solver {
public:
Solution virtual solve(Problem problem) = 0;
};



#endif //EX4_1_SOLVER_H
