//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"
template <class T>
class BestFirstSearch: public Searcher<T> {
private:
    priority_queue<State<T>*,vector<State<T>*>> priority_queue;
public:
     T search(Searchable<T> s);
     int getNumberOfNodesEvaluated();
     State<T> popPriorityQ();
};



#endif //MILESTONE2_BESTFIRSTSEARCH_H
