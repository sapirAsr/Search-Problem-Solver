//
// Created by michal on 19/01/2020.
//

#include "State.h"

template <class T>
State<T>::State(T* s, double c) {
    this->state = s;
    this->cost = c;
}

template <class T>
bool State<T>::equals (T* s) {
    return s->equals(this->state);
}

template <class T>
void State<T>::setCost(double c) {
    this->cost = c;
}

template <class T>
void State<T>::setFather(T* f) {
    this->cameFrom = f;
}

template<class T>
T* State<T>::getState() {
    return this->state;
}

template<class T>
State<T>* State<T>::getFather() {
    return this->cameFrom;
}

template<class T>
bool State<T>::getVisit() {
    return this->visited;
}

template<class T>
void State<T>::setVisit() {
    this->visited = true;
}

template<class T>
double State<T>::getCost() {
    return this->cost;
}

template<class T>
void State<T>::setDistance(double dis) {
    this->distance = dis;
}

template<class T>
double State<T>::getDistance() {
    return this->distance;
}

template<class T>
void State<T>::setH(double he) {
    this->h = he;

}

template<class T>
double State<T>::getH() {
    return this->h;
}

template<class T>
State<T> & State<T>::operator=(State<T> *s) {
    this = s;
    return *this;
}

template<class T>
void State<T>::setState(T* s) {
    this = s;
}


