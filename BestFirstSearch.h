//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"

template <class T>
class BestFirstSearch: public Searcher<T,vector<State<T>*>>{
private:
    class Cmp {
    public:
        bool operator()(State<T>* left, State<T>* right) {
            return (left->getDistance()) > (right->getDistance());
        }
    };
    priority_queue<State<T>*, vector<State<T>*>, Cmp> open;
    unordered_set<State<T>*> closed;
    int evaluate = 0;
    double cost = 0;



public:
    bool isExist( priority_queue<State<T> *, vector<State<T> *>, Cmp> open, State<T> *state) {
        while (!open.empty()) {
            if (state->equals(open.top())) {
                return true;
            }
            open.pop();
        }
        return false;
    }
    priority_queue<State<T>*,vector<State<T>*>,Cmp> updateQueue(priority_queue<State<T>*, vector<State<T>*>, Cmp> &queueOpen) {
        priority_queue<State<T>*,vector<State<T>*>,Cmp> temp;
        while (!queueOpen.empty()) {
            State<T>* node = queueOpen.top();
            temp.push(node);
            queueOpen.pop();
        }
        return temp;
    }

    vector<State<T>*> search(Searchable<T>* searchable) override {
        open.push(searchable->getInitialState());
        vector<State<T>*> path;
        while (!open.empty()) {
            evaluate++;
            State<T>* n = open.top();
            open.pop();
            closed.insert(n);
            if (n->equals(searchable->getGoalState())) {
                path.push_back(n);
                while (!n->equals(searchable->getInitialState())) {
                    path.push_back(n->getFather());
                    cost += n->getCost();
                    n = n->getFather();
                }
                cost += n->getCost();
                vector<State<T>*> back;
                for (int i = path.size() - 1; i >= 0 ; i--) {
                    back.push_back(path.at(i));
                }
                return back;
            }
            vector<State<T> *> adjacent;
            adjacent = searchable->getAllPossibleStates(n);

            for (State<T>* adj : adjacent) { ;
                bool exist = isExist(open, adj);
                if (!exist && closed.count(adj) != 1) {
                    adj->setFather(n);
                    adj->setDistance(n->getDistance() +adj->getCost()) ;
                    open.push(adj);
                } else if (adj->getDistance() > n->getDistance() + adj->getCost()) {
                    bool inOpen = isExist(open, adj);
                    adj->setDistance(n->getDistance() + adj->getCost());
                    adj->setFather(n);
                    open = updateQueue(open);
                }
            }
        }
        return path;
    }
    int getNumberOfNodesEvaluated(){
        return evaluate;
    }
    string getClassName(){
        return "BestFirstSearch";
    }
    Searcher<T, vector<State<T>*>>* clone() {
        return new BestFirstSearch<T>();
    }
};



#endif //MILESTONE2_BESTFIRSTSEARCH_H
