//
// Created by michal on 20/01/2020.
//
/**
#include "DFS.h"

template <class T>
vector<State<T>*> DFS<T>::search(Searchable<T>* s) {
    s->getCurr().setVisit();
    vector<State<T> *> trace;
    this->helpSearch(s, s->getInitialState(), trace);
    return trace;
}

template <class T>
int DFS<T>::helpSearch(Searchable<T>* s, State<T>* curr, vector<State<T>*> &trace) {
    if (s->getCurr().Equals(s->getGoalState())) {
        this->evaluate++;
        while (s->getCurr().getFather() != nullptr) {
            trace.push_back(s->getCurr());
            cost += s->getCurr().getCost();
            s->setCurr(s->getCurr().getFather());
        }
        cost += s->getCurr().getCost();
        trace.push_back(s->getCurr());
        vector<State<T>*> back;
        for (int i = trace.size() - 1; i >= 0 ; i--) {
            back.push_back(trace.at(i));
        }
        trace = back;
        return 1;
    }
    s->getCurr().setVisit();
    this->evaluate++;
    s->setCurr(s->getCurr());
    list<State<T>*> neighbours = s->getAllPossibleStates(s->getCurr());
    for (State<T>* state : neighbours) {
        bool visited = state->getVisited();
        if (!visited) {
            state->setFather(s->getCurr());
            if (helpSearch(s, state, trace) == 1) {
                return 1;
            }
        }
    }
    return trace;
}
 */