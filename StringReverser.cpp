//
// Created by michal on 14/01/2020.
//

#include "StringReverser.h"

string StringReverser::solve(string str) {
    int len = str.length();
    string reverse;
    //reverse(str.begin(), str.end());
    for (int i = len - 1; i >= 0 ; --i) {
        reverse += str[i];
    }
    reverse += "\r\n";
    return reverse;
}

string StringReverser::getClassName() {
    return "String Reverser";
}

Solver<string, string> *StringReverser::clone() {
    return new StringReverser;
}
int StringReverser::getSearcherNodes(){
    return 0;
}