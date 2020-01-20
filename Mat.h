//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_MAT_H
#define MILESTONE2_MAT_H

#include "Searchable.h"
#include <vector>
#include <string>
#include "Position.h"

class Mat : public Searchable<Position> {
private:
    vector<vector<State<Position>*>*> matrix;
    int size;
    //State<string>* currrr;
public:
    Mat(vector<vector<State<Position>*>*> mat);
    State<Position>* getInitialState();
    State<Position>* getGoalState();
    vector<State<Position>*> getAllPossibleStates(State<Position>* possibility);
    void setSize(int s);
    int getSize();
    void setVisit();
    void setCurr(State<Position> *curr);
    State<Position>* getCurr();
    double calcHValue(State<Position>* cur);
    bool equals(Position* s);

};


#endif //MILESTONE2_MAT_H
