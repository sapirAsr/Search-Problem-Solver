//
// Created by michal on 19/01/2020.
//

#include "string"
#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

using namespace std;

/**
 * this class will identify each vertex in our problem- the matrix problem.
 * @tparam T a generic type.
 */
template <typename T> class State {
private:
    T state;
    double  cost = 0;
    double distance = 0;
    State<T>* cameFrom = nullptr;
    bool visited = false;
    double h = 0;

public:

    /**
     * constructor.
     * @param s the generic type.
     */
    State(T s): state(s) {
        this->state = s;
    }

    /**
     * this func will set the cost of every vertex in the matrix.
     * @param c the cost of the vertex.
     */
    void setCost(double c) {
        this->cost = c;
    }

    /**
     * this func will declare the father of every vertex in the matrix.
     * @param f the father vertex of this vertex.
     */
    void setFather(State<T>* f) {
        this->cameFrom = f;
    }

    /**
     * @return the generic type of our vertex.
     */
    T getState() {
        return this->state;
    }

    /**
     * @return the father of this vertex.
     */
    State<T>* getFather() {
        return this->cameFrom;
    }

    /**
     * @return true or false if we got to this vertex already.
     */
    bool getVisit() {
        return this->visited;
    }

    /**
     * declare that we traverse this vertex already.
     */
    void setVisit() {
        this->visited = true;
    }

    /**
     * @return the cost of every vertex.
     */
    double getCost() {
        return this->cost;
    }

    /**
     * this func sets the distance of this vertex from the goal vertex.
     * @param dis the distance between the goal vertex and the current vertex.
     */
    void setDistance(double dis) {
        this->distance = dis;
    }

    /**
     * @return the distance between the goal vertex and the current vertex.
     */
    double getDistance() {
        return this->distance;
    }

    /**
     * this func declare the heuristic distance between the current vertex to the goal vertex.
     * @param he the heuristic value.
     */
    void setH(double he) {
        this->h = he;
    }

    /**
     * @return the heuristic distance between the current vertex to the goal vertex.
     */
    double getH() {
        return this->h;
    }

    /**
     * @param s vertex.
     * @return true/ false if the two verteces are the same.
     */
    bool equals(State<T>* s) {
        return this->state.equals(s->state);
    }
};

#endif //MILESTONE2_STATE_H