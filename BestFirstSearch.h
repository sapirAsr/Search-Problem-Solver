//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"

template <class T>
class BestFirstSearch: public Searcher<T> {
private:
    priority_queue<State<T>*,vector<State<T>*>,Comper<T>> open;
    unordered_set<State<T>*> closed;
    int evaluate = 0;
    double cost = 0;

public:
    vector<State<T>*> search(Searchable<T> s);
    int getNumberOfNodesEvaluated();
    bool isExist( priority_queue<State<T> *, vector<State<T> *>,Comper<T>> open, State<T> *state);
    priority_queue<State<T>*,vector<State<T>*>,Comper<T>> updateQueue(priority_queue<State<T>*, vector<State<T>*>,Comper<T>> &queueOpen);
        //State<T> popPriorityQ();
};



#endif //MILESTONE2_BESTFIRSTSEARCH_H
