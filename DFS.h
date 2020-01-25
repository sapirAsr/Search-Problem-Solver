//
// Created by michal on 20/01/2020.
//

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H

#include "Searcher.h"
#include <iterator>
#include <list>

template <class T>
class DFS: public Searcher<T, vector<State<T>*>>{
private:
    int evaluate = 0;
    double cost;
public:
    vector<State<T>*> search(Searchable<T>* s) {
        s->getCurr()->setVisit();
        vector<State<T> *> trace;
        this->helpSearch(s, s->getInitialState(), trace);
        return trace;
    }

    int helpSearch(Searchable<T>* s, State<T>* curr, vector<State<T>*> &trace) {
        if (curr->equals(s->getGoalState())) {
            this->evaluate++;
            while (curr->getFather() != nullptr) {
                trace.push_back(curr);
                cost += curr->getCost();
                curr = curr->getFather();
            }
            cost += curr->getCost();
            trace.push_back(curr);
            vector<State<T>*> back;
            for (int i = trace.size() - 1; i >= 0 ; i--) {
                back.push_back(trace.at(i));
            }
            trace = back;
            return 1;
        }
        curr->setVisit();
        this->evaluate++;
        s->setCurr(curr);
        vector<State<T>*> neighbours = s->getAllPossibleStates(curr);
        for (State<T>* state : neighbours) {
            bool visited = state->getVisit();
            if (!visited) {
                state->setFather(curr);
                if (helpSearch(s, state, trace) == 1) {
                    return 1;
                }
            }
        }
    }

    int getNumberOfNodesEvaluated(){
        return evaluate;
    }
    string getClassName(){
        return "DFS";
    }

};


#endif //MILESTONE2_DFS_H
