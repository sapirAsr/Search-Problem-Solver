//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H

#include <iostream>
#include <queue>
#include "State.h"
#include "Searchable.h"

template <class T> class Searcher {
private:
    queue<State<T>> priorityQ;
    int evaluatedNodes = 0;
public:
    T search(Searchable<T> s) = 0;
    int getNumberOfNodesEvaluated();
    State<T> popPriorityQ();
};




#endif //MILESTONE2_SEARCHER_H
