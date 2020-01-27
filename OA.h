//
// Created by michal on 23/01/2020.
//

#ifndef MILESTONE2_OA_H
#define MILESTONE2_OA_H

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"
template <class T, class S>
class OA :public Solver<Searchable<T>*, S> {
private:
    Searchable<T>* searchable;
    Searcher<T,S>* searcher;
public:
    OA(Searcher<T,S>* algo){
        this->searcher = algo;
    }
    S solve(Searchable<T>* problem){
        this->searchable = problem;
        return this->searcher->search(this->searchable);
    }

    string getClassName() {
        return this->searcher->getClassName();
    }

    int getSearcherNodes() {
        return this->searcher->getNumberOfNodesEvaluated();
    }

    Solver<Searchable<T>*, vector<State<T>*>>* clone() {
        Searcher<T, S>* searcherClone = this->searcher->clone();
        return new OA(searcherClone);
    }
};


#endif //MILESTONE2_OA_H
