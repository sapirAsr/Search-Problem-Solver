//
// Created by michal on 20/01/2020.
//

#include "Position.h"

/**
 * constructor.
 * @param r the row index.
 * @param c the column index.
 */
Position::Position(int r, int c) {
    this->row = r;
    this->col = c;
}

/**
 * set the row index.
 * @param r the row index.
 */
void Position::setRow(int r) {
    this->row = r;
}

/**
 * sets the column index.
 * @param c the column index.
 */
void Position::setCol(int c) {
    this->col = c;
}

/**
 * @return the row index.
 */
int Position::getRow() {
    return this->row;
}

/**
 * @return ths column index.
 */
int Position::getCol() {
    return this->col;
}

/**
 * this func checks if two verteces are at the same place in the matrix.
 * @param s vertex.
 * @return trueq false
 */
bool Position::equals(Position s) {
    return (this->row == s.getRow() && this->col == s.getCol());
}