//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H

#include <iostream>
#include <queue>
#include <unordered_set>
#include <list>
#include "Comper.h"
#include "State.h"
#include "Searchable.h"

template <class T, class S> class Searcher {
private:
    int evaluatedNodes = 0;
public:
    virtual S search(Searchable<T>* s) = 0;
    //virtual void addToOpenList(Searcher<T>) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
    //virtual State<T> popPriorityQ();
};




#endif //MILESTONE2_SEARCHER_H
