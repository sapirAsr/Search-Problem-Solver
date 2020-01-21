//
// Created by michal on 20/01/2020.
//

#include "AStar.h"
template<class T>
bool AStar<T>::isExist(priority_queue<State<T> *, vector<State<T> *>, Comper<T>> openQ, State<T> *state) {
    while (!openQ.empty()) {
        if (state->equals(openQ.top())) {
            return true;
        }
        openQ.pop();
    }
    return false;

}

template<class T>
priority_queue<State<T> *, vector<State<T> *>, Comper<T>>
AStar<T>::updateQueue(priority_queue<State<T> *, vector<State<T> *>, Comper<T>> &queueOpen) {
    priority_queue<State<T> *, vector<State<T> *>, Comper<T>> temp;
    while (!queueOpen.empty()) {
        State<T> *node = queueOpen.top();
        temp.push(node);
        queueOpen.pop();
    }
    return temp;
}

template<class T>
vector<State<T> *> AStar<T>::search(Searchable<T> *s) {
    open.push(s->getInitialState());
    vector<State<T> *> path;
    while (!open.empty()) {
        State<T> *n = open.top();

        // Remove this vertex from the open list
        open.pop();
        evaluate++;
        // Add this vertex to the closed list
        n->setVisited();
        closed.insert(n);
        if (n->equals(s->getGoalState())) {
            //evaluated++;
            path.push_back(n);
            while (!n->equals(s->getInitialState())) {
                path.push_back(n->getFather());
                cost += n->getCost();
                n = n->getFather();
            }
            cost += n->getCost();
            vector<State<T> *> back;
            for (unsigned long  i = path.size() - 1; i >= 0; i--) {
                back.push_back(path.at(i));
            }
            return back;
        }
        list<State<T> *> neighbors = s->getAllPossibleStates(n, 'b');
        for (State<T> *adj : neighbors) {
            bool exist = isExist(open, adj);
            if (!exist && closed.count(adj) != 1) {
                adj->setFather(n);
                //todo
                adj->setHeur(s->calculateHValue(adj));
                open.push(adj);
                adj->setDistance(n->getDistance() + adj->getCost());
            } else if (adj->getDistance() > n->getDistance() + adj->getCost()) {
                adj->setDistance(n->getDistance() + adj->getCost());
                adj->setFather(n);
                //todo
                adj->setHeur(s->calculateHValue(adj));
                open = updateQueue(open);
            }
        }
    }

}
