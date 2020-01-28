//
// Created by michal on 20/01/2020.
//

#ifndef MILESTONE2_ASTAR_H
#define MILESTONE2_ASTAR_H

#include "Searcher.h"
template <class T>
/**
 * this class is an algorithm to solve the problem of finding the cheapest path. This algorithm uses
 * the searcher interface
 * @tparam T a generic parameter.
 */
class AStar : public Searcher<T,vector<State<T>*>>{
private:
    // comparator
    class Cmp {
    public:
        bool operator()(State<T>* left, State<T>* right) {
            return (left->getH()) > (right->getH());
        }
    };
    priority_queue<State<T>*,vector<State<T>*>,Cmp> open;
    unordered_set<State<T>*> finished;
    int evaluate = 0;
    double cost = 0;

public:
    /**
     * this func returns the path organize according to priority.
     * @param queueOpen a type of container designed such that the first element of the queue is the
     * greatest of all elements in the queue and elements are in non increasing order.
     * @return priority queue.
     */
    priority_queue<State<T>*,vector<State<T>*>,Cmp> updateQueue(priority_queue<State<T>*, vector<State<T>*>, Cmp> &queueOpen) {
        priority_queue<State<T>*,vector<State<T>*>,Cmp> temp;
        while (!queueOpen.empty()) {
            State<T>* node = queueOpen.top();
            temp.push(node);
            queueOpen.pop();
        }
        return temp;
    }

    /**
     * This func finds the cheapest path from the initial state to the goal state.
     * @param s a searchable to run over him the algorithm.
     * @return the cheapest path.
     */
    vector<State<T>*> search(Searchable<T> *s) {
        open.push(s->getInitialState());
        vector<State<T>*> path;
        while (!open.empty()) {
            State<T> *n = open.top();
            // Remove this vertex from the open list
            open.pop();
            evaluate++;
            // Add this vertex to the finished list
            n->setVisit();
            finished.insert(n);
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
                if (!exist && finished.count(adj) != 1) {
                    adj->setVisit();
                    adj->setH(s->calcHValue(adj));
                    open.push(adj);
                    adj->setDistance(n->getDistance() + adj->getCost());
                } else if (adj->getDistance() > n->getDistance() + adj->getCost()) {
                    adj->setDistance(n->getDistance() + adj->getCost());
                    adj->setH(s->calcHValue(adj));
                    open = updateQueue(open);
                }
            }
        }
    }

    /**
     * this func checks if a given state is in the priority queue.
     * @param o priority queue.
     * @param state the given state we want to check if he is in the queue.
     * @return true/ false.
     */
    bool isExist( priority_queue<State<T> *, vector<State<T> *>, Cmp> o, State<T> *state) {
        while (!o.empty()) {
            if (state->equals(o.top())) {
                return true;
            }
            o.pop();
        }
        return false;
    }

    /**
     * @return the number of vertices.
     */
    int getNumberOfNodesEvaluated(){
        return evaluate;
    }

    /**
     * @return the name of the class.
     */
    string getClassName(){
        return "AStar";
    }

    /**
     * @return a clone of Astar.
     */
    Searcher<T, vector<State<T>*>>* clone() {
        return new AStar<T>();
    }
};

#endif //MILESTONE2_ASTAR_H