//
// Created by michal on 19/01/2020.
//

#include "Mat.h"
Mat::Mat(vector<vector<State<Position>*>*> mat) {
    this->matrix = mat;
}

State<Position>* Mat::getInitialState() {
    auto* s = (string *) "0,0";
    this->currrr->setState(s);
    double cost = stoi(this->matrix.at(0).at(0));
    currrr->setCost(cost);
    currrr->setDistance(cost);
    currrr->setFather(nullptr);
    return currrr;
    /**
    State<string> state = State<string>("0,0");
    double cost = stoi(this->matrix.at(0).at(0));
    state.setCost(cost);
    state.setDistance(cost);
    state.setFather(nullptr);
    return state;
    */
}

State<Position>* Mat::getGoalState() {
    long sizee = matrix.size() - 1;
    long sizeRow = matrix.at(0).size() - 1;
    string state = this->matrix.at(sizee).at(sizeRow);
    State<string>* s = new State<string>(state);
    return s;
}

vector<State<Position>*> Mat::getAllPossibleStates(State<Position>* possibility) {
    vector<State<string>> neighbours;
    string* state = possibility->getState();
    int len = state.length();
    string row;
    string col;
    int flag = 0 ;
    for (int i = 0; i < len; ++i) {
        if (state[i] != ',' && flag == 0) {
            row += state[i];
        } else if (state[i] == ',') {
            flag = 1;
        } else if (state[i] != ',' && flag == 1) {
            col += state[i];
        }
    }
    int row1 = stoi(row) - 1;
    int row2 = stoi(row) + 1;
    int col1 = stoi(col) - 1;
    int col2 = stoi(col) + 1;
    if (row1 != -1) {
        string place = to_string(row1) + "," + col;
        State<string> newState = State<string>(place);
        newState.setFather(state);
        newState.setCost(stod(this->matrix.at(row1).at(stoi(col))));
        neighbours.push_back(newState);
    } if (row2 != this->matrix.size()) {
        string place = to_string(row2) + "," + col;
        State<string> newState = State<string>(place);
        newState.setFather(state);
        newState.setCost(stod(this->matrix.at(row2).at(stoi(col))));
        neighbours.push_back(newState);
    } if (col1 != -1) {
        string place = row + "," + to_string(col1);
        State<string> newState = State<string>(place);
        newState.setFather(state);
        newState.setCost(stod(this->matrix.at(stoi(row)).at(col1)));
        neighbours.push_back(newState);
    } if (col2 != this->matrix.at(0).size()) {
        string place = row + "," + to_string(col2);
        State<string> newState = State<string>(place);
        newState.setFather(state);
        newState.setCost(stod(this->matrix.at(stoi(row)).at(col2)));
        neighbours.push_back(newState);
    }
    return neighbours;
}

void Mat::setSize() {
    this->size = this->matrix.size() * this->matrix.at(0).size();
}

int Mat::getSize() {
    return this->size;
}

void Mat::setVisit() {
    this->currrr->setVisit();
}

void Mat::setCurr(State<string> *c) {
    this->currrr = c;
}

State<string>* Mat::getCurr() {
    return this->currrr;
}

double Mat::calcHValue(State<string> *cur) {
    /**
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
     */
    return 0;
}
void Mat::setSize(int s){
    this->size = 0;
}

bool Mat::equals(string *s) {
    return this->curr->getState() == s;
}
