//
// Created by michal on 20/01/2020.
//

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H

#include "Searcher.h"
#include <iterator>
#include <list>

template <class T>
class DFS: public Searcher<T> {
private:
    list<State<T>*> openList;
    int evaluate = 0;
    double cost;
public:
    vector<State<T> *> search(Searchable<T>* s);
    int helpSearch(Searchable<T>* s, State<T>* curr, vector<State<T>*> &trace);
};


#endif //MILESTONE2_DFS_H
