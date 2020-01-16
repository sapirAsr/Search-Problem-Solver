//
// Created by michal on 14/01/2020.
//

#include "StringReverser.h"

string StringReverser::solve(string str) {
    int len = str.length();
    string reverse;
    for (int i = len - 1; i >= 0 ; --i) {
        reverse += str[i];
    }
    return reverse;
}