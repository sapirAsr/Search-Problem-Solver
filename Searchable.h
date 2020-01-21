//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H

#include "State.h"
#include <vector>
#include <string>
using namespace std;

template <class T> class Searchable {
protected:
    int size = 0;
    State<T>* curr;
    State<T>* initial;
    State<T>* goal;
public:
    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getGoalState() = 0;
    virtual vector<State<T>*> getAllPossibleStates(State<T>* possibility) = 0;
    //virtual bool isGoalState(State<T>* s) = 0;
    //virtual void setSize(int s) = 0;
    virtual int getSize() = 0;
    virtual void setVisit() = 0;
    virtual void setCurr(State<T>* state) = 0;
    virtual State<T>* getCurr() = 0;
    //virtual double calcHValue(State<T>* cur) = 0;
};


#endif //MILESTONE2_SEARCHABLE_H
