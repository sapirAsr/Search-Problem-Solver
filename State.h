//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H


template <class T> class State {
private:
    T state;
    double  cost;
    State<T> cameFrom;
public:
    State(T s);
    bool Equals (T state);
    void setCost(double c);
    void setFather(State<T> f);
};


#endif //MILESTONE2_STATE_H
