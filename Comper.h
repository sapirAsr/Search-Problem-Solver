//
// Created by michal on 20/01/2020.
//

#ifndef MILESTONE2_COMPER_H
#define MILESTONE2_COMPER_H

#include "State.h"
template <class T>
class Comper {
public:
    bool operator()(State<T>* left, State<T>* right) {
        return (left->getDistance()) > (right->getDistance());
    }
};


#endif //MILESTONE2_COMPER_H
