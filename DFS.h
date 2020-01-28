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
/**
 * this class is an algorithm to solve the problem of finding the cheapest path. This algorithm uses
 * the searcher interface
 * @tparam T a generic parameter.
 */
 class DFS: public Searcher<T, vector<State<T>*>>{
private:
    int evaluate = 0;
    double cost;
public:

     /**
      * This func finds the cheapest path from the initial state to the goal state.
      * @param s a searchable to run over him the algorithm.
      * @return the cheapest path.
      */
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
      * @return the number of vertices.
      */
    int getNumberOfNodesEvaluated(){
        return evaluate;
    }

     /**
      * @return the name of the class.
      */
    string getClassName(){
        return "DFS";
    }

     /**
      * @return a clone of DFS.
      */
    Searcher<T, vector<State<T>*>>* clone() {
        return new DFS<T>();
    }

};


#endif //MILESTONE2_DFS_H
