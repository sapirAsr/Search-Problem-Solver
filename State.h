//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H


template <class T> class State {
private:
    T* state;
    double  cost;
    double distance;
    State<T>* cameFrom;
    bool visited = false;
    double h = 0;
public:
    State(T* s, double c);
    void setState(T* s);
    bool equals (T* s);
    void setCost(double c);
    double getCost();
    void setFather(T* f);
    T* getState();
    void setVisit();
    bool getVisit();
    State<T>* getFather();
    void setDistance(double dis);
    double getDistance();
    void setH(double he);
    double getH();
    State& operator = (State<T>* s);
};



#endif //MILESTONE2_STATE_H
