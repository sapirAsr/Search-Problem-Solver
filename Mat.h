//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_MAT_H
#define MILESTONE2_MAT_H

#include "Searchable.h"
#include "Position.h"

/**
 * this class implement the interface searchable
 */
class Mat : public Searchable<Position> {
private:
    vector<vector<double>> matrix;
    int row;
    int col;
    vector<State<Position>*> visitedNodes;
public:
    Mat(vector<vector<double >> mat, State<Position>* init, State<Position>* goal, int r,int c);
    State<Position>* getInitialState();
    State<Position>* getGoalState();
    vector<State<Position>*> getAllPossibleStates(State<Position>* possibility);
    int getSize();
    void setVisit();
    void setCurr(State<Position> *curr);
    State<Position>* getCurr();
    State<Position>* getVisitedNode(int row1, int col1);
    double calcHValue(State<Position>* cur);
};


#endif //MILESTONE2_MAT_H
