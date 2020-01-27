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
    this->curr->setCost(this->matrix.at(init->getState().getRow()).at(init->getState().getCol()));
    this->goal->setCost(this->matrix.at(goal->getState().getRow()).at(goal->getState().getCol()));
}

State<Position>* Mat::getInitialState() {
    return this->initial;
}

State<Position>* Mat::getGoalState() {
    return this->goal;
}

State<Position> *Mat::getVisitedNode(int row1, int col1) {
    for (State<Position>* state : visitedNodes) {
        Position p = state->getState();
        if ((p.getRow() == row1) && (p.getCol() == col1)) {
            return state;
        }
    }
    return nullptr;
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
    Position p = possibility->getState();
    if (getVisitedNode(p.getRow(), p.getCol()) == nullptr) {
        this->visitedNodes.push_back(possibility);
    }
    if (row1 != -1) {
        if (getVisitedNode(row1, stateCol) == nullptr) {
            newState = new State<Position>(Position(row1, stateCol));
            newState->setFather(possibility);
            newState->setCost(this->matrix.at(row1).at(stateCol));
            if(newState->getCost() != -1) {
                neighbours.push_back(newState);
            }
        } else {
            if((getVisitedNode(row1, stateCol))->getCost() != -1) {
                neighbours.push_back(getVisitedNode(row1, stateCol));
            }
        }
    } if (row2 != this->matrix.size()) {
        if (getVisitedNode(row2, stateCol) == nullptr) {
            newState = new State<Position>(Position(row2, stateCol));
            newState->setFather(possibility);
            newState->setCost(this->matrix.at(row2).at(stateCol));
            if(newState->getCost() != -1) {
                neighbours.push_back(newState);
            }
        } else {
            if((getVisitedNode(row2, stateCol))->getCost() != -1) {
                neighbours.push_back(getVisitedNode(row2, stateCol));
            }
        }
    } if (col1 != -1) {
        if (getVisitedNode(stateRow, col1) == nullptr) {
            newState = new State<Position>(Position(stateRow, col1));
            newState->setFather(possibility);
            newState->setCost(this->matrix.at(stateRow).at(col1));
            if(newState->getCost() != -1) {
                neighbours.push_back(newState);
            }
        } else {
            if(getVisitedNode(stateRow, col1)->getCost() != -1) {
                neighbours.push_back(getVisitedNode(stateRow, col1));
            }
        }
    } if (col2 != this->matrix.at(0).size()) {
        if (getVisitedNode(stateRow, col2) == nullptr) {
            newState = new State<Position>(Position(stateRow, col2));
            newState->setFather(possibility);
            newState->setCost(this->matrix.at(stateRow).at(col2));
            if(newState->getCost() != -1) {
                neighbours.push_back(newState);
            }
        } else {
            if (getVisitedNode(stateRow, col2)->getCost() != -1) {
                neighbours.push_back(getVisitedNode(stateRow, col2));
            }
        }
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

double Mat::calcHValue(State<Position> *cur) {
    int xCur = cur->getState().getRow();
    int yCur = cur->getState().getCol();
    int xGoal = this->getGoalState()->getState().getRow();
    int yGoal = this->getGoalState()->getState().getCol();
    double disMan = abs (xCur - xGoal) +
                    abs (yCur - yGoal);
    double total = disMan + cur->getCost() + cur->getFather()->getDistance();
    return total;
}