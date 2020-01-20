//
// Created by michal on 19/01/2020.
//

#include "BFS.h"

template <class T>
vector<State<T> *> BFS<T>::search(Searchable<T>* s) {
    openList.push_back(s->getInitialState());
    evaluate++;
    s->setVisit();
    vector<State<T>*> path;
    while (openList.size() > 0){
        State<T>* n = openList.front();
        openList.pop_front();
        if(n->equals(s->getGoalState())){
            evaluate++;
            while (n->getFather()!= nullptr) {
                path.push_back(n);
                cost += n->getCost();
                n = n->getFather();
            }
            cost += n->getCost();
            path.push_back(n);
            vector<State<T>*> back;
            for (int i = path.size() - 1; i >= 0 ; i--) {
                back.push_back(path.at(i));
            }
            return back;
        }
        list<State<T>*> neighbors = s->getAllPossibleStates(n);
        for (State<T>* state : neighbors){
            bool visited = state->getVisit();
            if(!visited) {
                state->setVisit();
                state->setFather(n);
                openList.push_back(state);
                evaluate++;
                s->setCurr(state);
            }
        }
    }
}