//
// Created by sapir on 19/01/2020.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "Searchable.h"
class BestFirstSearch : public class Searcher {
public:
    T search(Searchable searchable);
};


#endif //MILESTONE2_BESTFIRSTSEARCH_H
