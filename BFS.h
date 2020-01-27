//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_BFS_H
#define MILESTONE2_BFS_H

#include "Searcher.h"
#include <iterator>
#include <list>

template <class T>
class BFS: public Searcher<T,vector<State<T>*>> {
private:
    list<State<T>*> openList;
    int evaluate = 0;
    double cost = 0;
public:
    vector<State<T>*> search(Searchable<T>* s) {
        s->setVisit();
        openList.push_back(s->getInitialState());
        while (!openList.empty()) {
            State<T> *n = openList.front();
            openList.pop_front();
            evaluate++;
            vector<State<T>*> neighbours = s->getAllPossibleStates(n);
            for (State<T>* state : neighbours) {
                bool visited = state->getVisit();
                if (!visited && !isInList(openList, state)) {
                    state->setVisit();
                    state->setFather(n);
                    openList.push_back(state);
                }
            }
            if (n->equals(s->getGoalState())) {
                vector<State<T>*> path;
                while (n->getFather() != nullptr) {
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
        }
    }
    /**
      vector<State<T>*> search(Searchable<T>* s) {
        openList.push_back(s->getInitialState());
        s->setVisit();
        vector<State<T>*> path;
        while (openList.size() > 0) {
            State<T>* n = openList.front();
            openList.pop_front();
            evaluate++;
            if (n->equals(s->getGoalState())) {
                while (n->getFather() != nullptr) {
                    path.push_back(n);
                    cost += n->getCost();
                    n = n->getFather();
                }
                cost += n->getCost();
                path.push_back(n);
                vector<State<T> *> back;
                for (int i = path.size() - 1; i >= 0; i--) {
                    back.push_back(path.at(i));
                }
                return back;
            }
            vector<State<T> *> neighbors = s->getAllPossibleStates(n);
            for (State<T> *state : neighbors) {
                bool visited = state->getVisit();
                if (!visited) {
                    state->setVisit();
                    state->setFather(n);
                    openList.push_back(state);
                    s->setCurr(state);
                }
            }
        }
    }*/
    bool isInList(list<State<T>*> lst, State<T>* val) {
        for (State<T>* state : lst) {
            if ((val->getState().getRow() == state->getState().getRow()) &&
            (val->getState().getCol() == state->getState().getCol())) {
                return true;
            }
        }
        return false;
    }

    int getNumberOfNodesEvaluated(){
        return this->evaluate;
    }

    string getClassName(){
        return "BFS";
    }

    Searcher<T, vector<State<T>*>>* clone() {
        return new BFS<T>();
    }
};


#endif //MILESTONE2_BFS_H
