//
// Created by michal on 19/01/2020.
//

#include "Mat.h"
Mat::Mat(vector<vector<double >> mat, State<Position> *init, State<Position> *goal, int r,
        int c) {
    this->curr = init;
    this->col = c;
    this->row = r;
    this->matrix = mat;
    this->initial = init;
    this->goal = goal;
}

State<Position>* Mat::getInitialState() {
    return this->initial;
}

State<Position>* Mat::getGoalState() {
    return this->goal;
}

vector<State<Position>*> Mat::getAllPossibleStates(State<Position>* possibility) {
    vector<State<Position>*> neighbours;
    int stateRow = possibility->getState().getRow();
    int stateCol = possibility->getState().getCol();
    int row1 = stateRow - 1;
    int row2 = stateRow + 1;
    int col1 = stateCol - 1;
    int col2 = stateCol + 1;
    State<Position>* newState;
    if (row1 != -1) {
        newState = new State<Position>(Position(row1, stateCol));
        newState->setFather(possibility);
        newState->setCost(this->matrix.at(row1).at(stateCol));
        neighbours.push_back(newState);
    } if (row2 != this->matrix.size()) {
        Position p = Position(row2, stateCol);
        newState = new State<Position>(p);
        newState->setFather(possibility);
        newState->setCost(this->matrix.at(row2).at(stateCol));
        neighbours.push_back(newState);
    } if (col1 != -1) {
        Position p = Position(stateRow, col1);
        newState = new State<Position>(p);
        newState->setFather(possibility);
        newState->setCost(this->matrix.at(stateRow).at(col1));
        neighbours.push_back(newState);
    } if (col2 != this->matrix.at(0).size()) {
        Position p = Position(stateRow,col2);
        newState = new State<Position>(p);
        newState->setFather(possibility);
        newState->setCost(this->matrix.at(stateRow).at(col2));
        neighbours.push_back(newState);
    }
    return neighbours;
}

int Mat::getSize() {
    return this->size;
}

void Mat::setVisit() {
    this->curr->setVisit();
}

void Mat::setCurr(State<Position> *c) {
    this->curr = c;
}

State<Position>* Mat::getCurr() {
    return this->curr;
}

/**bool Mat::isGoalState(State<Position> *s) {
    return this->goal->operator==(s);
}**/

/**double Mat::calcHValue(State<string> *cur) {

    int xCur = cur->getState()->getX();
    int yCur = cur->getState()->getY();
    int xGoal = this->getGoalState()->getState()->getX();
    int yGoal = this->getGoalState()->getState()->getY();
    double disMan = abs (xCur - xGoal) +
                    abs (yCur - yGoal);
    double total = disMan + cur->getCost() + cur->getParent()->getDistance();
    //cur->setHeur(total);

    h = abs (cur->getState() – th.x) +
            abs (current_cell.y – goal.y)
    return total;

    return 0;
}*/