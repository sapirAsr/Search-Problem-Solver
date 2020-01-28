//
// Created by michal on 14/01/2020.
//

#include "StringReverser.h"

/**
 * this func creates the reversed string.
 * @param str the string we want to reverse.
 * @return reversed string.
 */
string StringReverser::solve(string str) {
    int len = str.length();
    string reverse;
    for (int i = len - 1; i >= 0 ; --i) {
        reverse += str[i];
    }
    reverse += "\r\n";
    return reverse;
}

/**
 * @return a string of the class name.
 */
string StringReverser::getClassName() {
    return "String Reverser";
}

/**
 * @return a clone of the string reverser.
 */
Solver<string, string> *StringReverser::clone() {
    return new StringReverser;
}

/**
 * @return 0 because there are no verteces in this problem.
 */
int StringReverser::getSearcherNodes(){
    return 0;
}