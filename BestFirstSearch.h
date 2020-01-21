//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"

template <class T>
class BestFirstSearch: public Searcher<T,vector<State<T>*>>{
private:
    priority_queue<State<T>*,vector<State<T>*>,Comper<T>> open;
    unordered_set<State<T>*> closed;
    int evaluate = 0;
    double cost = 0;

public:
    vector<State<T>*> search(Searchable<T> s) {
        open.push(s.getInitialState());
        vector<State<T>*> path;
        while (!open.empty()) {
            evaluate++;
            State<T>* n = open.top();
            open.pop();
            closed.insert(n);
            if (n->equals(s.getGoalState())) {
                path.push_back(n);
                while (!n->equals(s.getInitialState())) {
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
            list<State<T> *> neighbors;
            try {
                neighbors = s.getAllPossibleStates(n);
            } catch (exception &e) {
                cout << "exception";
            }
            for (State<T>* adj : neighbors) { ;
                bool exist = isExist(open, adj);
                if (!exist && closed.count(adj) != 1) {
                    adj->setFather(n);
                    ///todo
                    adj->setDistance(n->getDistance() +adj->getCost()) ;
                    open.push(adj);
                } else if (adj->getDistance() > n->getDistance() + adj->getCost()) {
                    adj->setDistance(n->getDistance() + adj->getCost());
                    adj->setParent(n);
                    open = updateQueue(open);
                }
            }
        }
        return path;
    }

    int getNumberOfNodesEvaluated() {
        return this->evaluate;
    }

    bool isExist(priority_queue<State<T> *, vector<State<T> *>, Comper<T>> open, State<T> *state) {
        while (!open.empty()) {
            if (state->equals(open.top())) {
                return true;
            }
            open.pop();
        }
        return false;}

    priority_queue<State<T> *, vector<State<T> *>,Comper<T>> updateQueue(priority_queue<State<T> *,
            vector<State<T> *>, Comper<T>> &queueOpen) {
        priority_queue<State<T>*,vector<State<T>*>> temp;
        while (!queueOpen.empty()) {
            State<T>* node = queueOpen.top();
            temp.push(node);
            queueOpen.pop();
        }
        return temp;
    }
};



#endif //MILESTONE2_BESTFIRSTSEARCH_H
