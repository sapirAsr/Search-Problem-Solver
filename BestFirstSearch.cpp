//
// Created by michal on 19/01/2020.
//

#include "BestFirstSearch.h"
template<class T>
T BestFirstSearch<T>::search(Searchable<T> s) {
    priority_queue.push(s.getInitialState());
}