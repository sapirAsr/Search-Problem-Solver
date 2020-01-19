//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H

#include "State.h"
#include <list>
using namespace std;

template <class T> class Searchable {
public:
    State<T> getInitialState() = 0;
    bool isGoalState(State<T>) = 0;
    list<T> getAllPossibleStates(State<T>) = 0;
};


#endif //MILESTONE2_SEARCHABLE_H
