//
// Created by michal on 19/01/2020.
//

#ifndef MILESTONE2_MAT_H
#define MILESTONE2_MAT_H

#include "Searchable.h"
#include <vector>
#include <string>
class Mat : public Searchable<string> {
private:
    vector<vector<string>> matrix;

public:
    Mat(vector<vector<string>> mat);
    State<string> getInitialState();
    State<string> getGoalState();
    vector<State<string>> getAllPossibleStates(State<string> possibility);
    void setSize(int s);
    int getSize();
    void setVisit();

};


#endif //MILESTONE2_MAT_H
