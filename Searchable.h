//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H

#include "State.h"
#include <vector>
using namespace std;

template <class T> class Searchable {
protected:
    int size;
    bool visited = false;
public:
    virtual State<T> getInitialState() = 0;
    virtual State<T> getGoalState() = 0;
    virtual vector<State<T>> getAllPossibleStates(State<T> possibility) = 0;
    virtual void setSize(int s) = 0;
    virtual int getSize() = 0;
    virtual void setVisit() = 0;
};




#endif //MILESTONE2_SEARCHABLE_H