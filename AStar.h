//
// Created by michal on 20/01/2020.
//

#ifndef MILESTONE2_ASTAR_H
#define MILESTONE2_ASTAR_H

#include "Searcher.h"
template <class T>
class AStar : public Searcher<T,vector<State<T>*>>{
private:
    class Cmp {
    public:
        bool operator()(State<T>* left, State<T>* right) {
            return (left->getH()) > (right->getH());
        }
    };
    priority_queue<State<T>*,vector<State<T>*>,Cmp> open;
    unordered_set<State<T>*> closed;
    int evaluate = 0;
    double cost = 0;

public:
    priority_queue<State<T>*,vector<State<T>*>,Cmp> updateQueue(priority_queue<State<T>*, vector<State<T>*>, Cmp> &queueOpen) {
        priority_queue<State<T>*,vector<State<T>*>,Cmp> temp;
        while (!queueOpen.empty()) {
            State<T>* node = queueOpen.top();
            temp.push(node);
            queueOpen.pop();
        }
        return temp;
    }

    vector<State<T>*> search(Searchable<T> *s) {
        open.push(s->getInitialState());
        vector<State<T> *> path;
        while (!open.empty()) {
            State<T> *n = open.top();
            // Remove this vertex from the open list
            open.pop();
            evaluate++;
            // Add this vertex to the closed list
            n->setVisit();
            closed.insert(n);
            if (n->equals(s->getGoalState())) {
                path.push_back(n);
                while (!n->equals(s->getInitialState())) {
                    path.push_back(n->getFather());
                    cost += n->getCost();
                    n = n->getFather();
                }
                cost += n->getCost();
                vector<State<T>*> back;
                for (int i = path.size() - 1; i >= 0; i--) {
                    back.push_back(path.at(i));
                }
                return back;
            }
            vector<State<T> *> adjacent = s->getAllPossibleStates(n);
            for (State<T> *adj : adjacent) {
                bool exist = isExist(open, adj);
                if (!exist && closed.count(adj) != 1) {
                    adj->setVisit();
                    //adj->setFather(n);
                    adj->setH(s->calcHValue(adj));
                    open.push(adj);
                    adj->setDistance(n->getDistance() + adj->getCost());
                } else if (adj->getDistance() > n->getDistance() + adj->getCost()) {
                    adj->setDistance(n->getDistance() + adj->getCost());
                    //adj->setFather(n);
                    adj->setH(s->calcHValue(adj));
                    open = updateQueue(open);
                }
            }
        }
    }

    bool isExist( priority_queue<State<T> *, vector<State<T> *>, Cmp> o, State<T> *state) {
        while (!o.empty()) {
            if (state->equals(o.top())) {
                return true;
            }
            o.pop();
        }
        return false;
    }
    int getNumberOfNodesEvaluated(){
        return evaluate;
    }

    string getClassName(){
        return "AStar";
    }
    Searcher<T, vector<State<T>*>>* clone() {
        return new AStar<T>();
    }
};

#endif //MILESTONE2_ASTAR_H