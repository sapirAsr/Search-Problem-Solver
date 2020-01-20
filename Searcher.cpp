//
// Created by michal on 19/01/2020.
//

#include "Searcher.h"

template<class T>
int Searcher<T>::getNumberOfNodesEvaluated() {
    return evaluatedNodes;
}

//template<class T>
/**State<T> Searcher<T>::popPriorityQ() {
    evaluatedNodes++;
    State<T> top = this->priorityQ.top();
    this->priorityQ.pop();
    return top;
}**/
