//
// Created by michal on 24/01/2020.
//

#include "MatCacheManager.h"

/**
 * This func check if we already have a solution to a prblem we solved before.
 * @param problem
 * @param name the name of the class.
 * @return true/ false.
 */
bool MatCacheManager::isResolved(string problem, string name) {
    int val = hasher(problem);
    string fileName = name + to_string(val) + ".txt";
    fromFile.open(fileName, ios::in);
    if (fromFile) {
        fromFile.close();
        return true;
    } else {
        return false;
    }
}

/**
 * this func returns the solution of the problem we already solved.
 * @param problem
 * @param name the name of the class.
 * @return string of the solution.
 */
string MatCacheManager::popSolution(string problem, string name) {
    string solution;
    string temp;
    int key = hasher(problem);
    string fileName = name + to_string(key) + ".txt";
    fromFile.open(fileName);
    if (!fromFile.is_open()) {
        throw "file doesn't exist";
    } else {
        while (!fromFile.eof()) {
            fromFile >> temp;
            solution += temp;
            temp = "";
        }
    }
    fromFile.close();
    //solution += "\r\n";
    return solution;
}

/**
 * this func writes to files the solution to the problems we solved.
 * @param problem
 * @param solution
 * @param name of class.
 */
void MatCacheManager::saveSolution(string problem, string solution, string name) {
    int val = hasher(problem);
    // writing to file
    //example of a file name : Astar 4
    string fileName = name + to_string(val) + ".txt";
    toFile.open(fileName);
    if (!toFile) {
        cout<<"failed to open file"<<endl;
        return;
    }
    toFile<<solution;
    toFile.close();
}

/**
 * this func checks if we already solved a given matrix problem.
 * @param mat a given matrix we want to check if we solved.
 * @return
 */
int MatCacheManager::problemKeyString(string mat) {
    int val;
    if (this->matrices.find(mat) != this->matrices.end()) {
        val = this->matrices[mat];
    } else { // if the problem not in hash map
        val = -1;
    }
    return val;
}