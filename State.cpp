//
// Created by michal on 19/01/2020.
//

#include "State.h"

template <class T>
State<T>::State(T s) {
    this->state = s;
}

template <class T>
bool State<T>::Equals (T state) {
    return state.equal(this->state);
}

template <class T>
void State<T>::setCost(double c) {
    this->cost = c;
}

template <class T>
void State<T>::setFather(State<T> f) {
    this->cameFrom = f;
}