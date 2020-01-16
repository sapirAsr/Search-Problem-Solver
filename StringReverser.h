//
// Created by michal on 14/01/2020.
//

#ifndef EX4_1_STRINGREVERSER_H
#define EX4_1_STRINGREVERSER_H

#include "Solver.h"
#include <string>
using namespace std;

class StringReverser : public Solver <string, string> {
public:
    string solve(string str);
};



#endif //EX4_1_STRINGREVERSER_H
