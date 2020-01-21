//
// Created by michal on 20/01/2020.
//

#ifndef MILESTONE2_POSITION_H
#define MILESTONE2_POSITION_H


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
