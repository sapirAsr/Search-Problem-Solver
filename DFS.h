//
// Created by michal on 20/01/2020.
//

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H

#include "Searcher.h"
#include <iterator>
#include <list>
#include <stack>

template <class T>
class DFS: public Searcher<T, vector<State<T>*>>{
private:
    int evaluate = 0;
    double cost;
public:

    vector<State<T>*> search(Searchable<T>* s) {
        s->getCurr()->setVisit();
        stack<State<T>*> path;
        State<T>* cur;
        path.push(s->getInitialState());
        while (!path.empty()) {
            cur = path.top();
            path.pop();
            evaluate++;
            vector<State<T>*> neighbours = s->getAllPossibleStates(cur);
            for (State<T>* state : neighbours) {
                bool visited = state->getVisit();
                if (!visited) {
                    state->setVisit();
                    state->setFather(cur);
                    path.push(state);
                }
            }
            if (cur->equals(s->getGoalState())) {
                while (cur->getFather() != nullptr) {
                    path.push(cur);
                    cost += cur->getCost();
                    cur = cur->getFather();
                }
                cost += cur->getCost();
                path.push(cur);
                vector<State<T>*> back;
                for (int i = path.size() - 1; i >= 0 ; i--) {
                    back.push_back(path.top());
                    path.pop();
                }
                return back;
            }
        }
    }

/**
    vector<State<T>*> search(Searchable<T>* s) {
        s->getCurr()->setVisit();
        vector<State<T>*> trace;
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
    */


    int getNumberOfNodesEvaluated(){
        return evaluate;
    }
    string getClassName(){
        return "DFS";
    }
    Searcher<T, vector<State<T>*>>* clone() {
        return new DFS<T>();
    }

};


#endif //MILESTONE2_DFS_H
