//
// Created by michal on 20/01/2020.
//

#ifndef MILESTONE2_POSITION_H
#define MILESTONE2_POSITION_H

#include "string"
using namespace std;

/**
 * this class holds the indeces of every vertex in the matrix.
 */
class Position {
private:
    int row;
    int col;
public:
    Position(int r, int c);
    void setRow(int r);
    void setCol(int c);
    int getRow();
    int getCol();
    bool equals(Position s);
    };


#endif //MILESTONE2_POSITION_H
