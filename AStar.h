//
// Created by michal on 20/01/2020.
//

#ifndef MILESTONE2_ASTAR_H
#define MILESTONE2_ASTAR_H


#include "Searcher.h"
template <class T>
class AStar : public Searcher<T>{
private:
    priority_queue<State<T>*,vector<State<T>*>,Comper<T>> open;
    unordered_set<State<T>*> closed;
    int evaluate = 0;
    double cost = 0;
public:
    bool isExist( priority_queue<State<T> *, vector<State<T> *>, Comper<T>> open, State<T> *state);
    priority_queue<State<T>*,vector<State<T>*>,Comper<T>> updateQueue(priority_queue<State<T>*, vector<State<T>*>, Comper<T>> &queueOpen);
    vector<State<T> *> search(Searchable<T> *searchable);
};




#endif //MILESTONE2_ASTAR_H
