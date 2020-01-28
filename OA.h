//
// Created by michal on 23/01/2020.
//

#ifndef MILESTONE2_OA_H
#define MILESTONE2_OA_H

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"

template <class T, class S>
/**
 * this class implements the solver interface.
 * @tparam T generic type
 * @tparam S generic type
 */

class OA :public Solver<Searchable<T>*, S> {
private:
    Searchable<T>* searchable;
    Searcher<T,S>* searcher;

public:

    /**
     * constructor
     * @param algo the algorithm we will use to search in the searchable.
     */
    OA(Searcher<T,S>* algo){
        this->searcher = algo;
    }

    /**
     * this func will solve the problem.
     * @param problem we want to solve.
     * @return solution of the problem.
     */
    S solve(Searchable<T>* problem){
        this->searchable = problem;
        return this->searcher->search(this->searchable);
    }

    /**
     * @return the string of the class name.
     */
    string getClassName() {
        return this->searcher->getClassName();
    }

    /**
     * @return number of nodes we traversed.
     */
    int getSearcherNodes() {
        return this->searcher->getNumberOfNodesEvaluated();
    }

    /**
     * @return a clone of the object adapter.
     */
    Solver<Searchable<T>*, vector<State<T>*>>* clone() {
        Searcher<T, S>* searcherClone = this->searcher->clone();
        return new OA(searcherClone);
    }
};


#endif //MILESTONE2_OA_H
