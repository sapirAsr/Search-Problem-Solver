//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_BFS_H
#define MILESTONE2_BFS_H

#include "Searcher.h"
#include <iterator>
#include <list>

template <class T>
class BFS: public Searcher<T> {
private:
    list<State<T>*> openList;
    int evaluate = 0;
    double cost;
public:
    vector<State<T>> search(Searchable<T>* s);
};


#endif //MILESTONE2_BFS_H
