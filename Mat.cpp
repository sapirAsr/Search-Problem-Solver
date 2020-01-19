//
// Created by michal on 19/01/2020.
//

#include "Mat.h"
Mat::Mat(vector<vector<string>> mat) {
    this->matrix = mat;
}

State<string> Mat::getInitialState() {
    State<string> state = State<string>("0,0");
    state.setCost(stoi(this->matrix.at(0).at(0)));
    state.setFather(nullptr);
    return state;
}

State<string> Mat::getGoalState() {
    long size = matrix.size() - 1;
    long sizeRow = matrix.at(0).size() - 1;
    return this->matrix.at(size).at(sizeRow);
}

vector<State<string>> Mat::getAllPossibleStates(State<string> possibility) {
    vector<State<string>> neighbours;
    string state = possibility.getState();
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

void Mat::setSize(int s) {
    this->size = this->matrix.size() * this->matrix.at(0).size();
}

int Mat::getSize() {
    return this->size;
}

void Mat::setVisit() {
    this->visited = true;
}
