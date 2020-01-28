//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_BFS_H
#define MILESTONE2_BFS_H

#include "Searcher.h"
#include <iterator>
#include <list>

template <class T>
/**
 * this class is an algorithm to solve the problem of finding the cheapest path. This algorithm uses
 * the searcher interface
 * @tparam T a generic parameter.
 */
class BFS: public Searcher<T,vector<State<T>*>> {
private:
    list<State<T>*> openList;
    int evaluate = 0;
    double cost = 0;
public:

    /**
     * This func finds the cheapest path from the initial state to the goal state.
     * @param s a searchable to run over him the algorithm.
     * @return the cheapest path.
     */
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
     * this func checks if a given vertex is already in the list.
     * @param lst contains all the vertices we need to visit
     * @param val the given vertex we want to check if he is already in the list.
     * @return true/ false.
     */
    bool isInList(list<State<T>*> lst, State<T>* val) {
        for (State<T>* state : lst) {
            if ((val->getState().getRow() == state->getState().getRow()) &&
            (val->getState().getCol() == state->getState().getCol())) {
                return true;
            }
        }
        return false;
    }

    /**
    * @return the number of vertices.
    */
    int getNumberOfNodesEvaluated(){
        return this->evaluate;
    }

    /**
   * @return the name of the class.
   */
    string getClassName(){
        return "BFS";
    }

    /**
    * @return a clone of BFS.
    */
    Searcher<T, vector<State<T>*>>* clone() {
        return new BFS<T>();
    }
};


#endif //MILESTONE2_BFS_H
