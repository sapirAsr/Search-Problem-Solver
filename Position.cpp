//
// Created by michal on 20/01/2020.
//

#include "Position.h"

Position::Position(int r, int c) {
    this->row = r;
    this->col = c;
}

void Position::setRow(int r) {
    this->row = r;
}

void Position::setCol(int c) {
    this->col = c;
}

int Position::getRow() {
    return this->row;
}

int Position::getCol() {
    return this->col;
}
