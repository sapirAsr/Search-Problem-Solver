//
// Created by michal on 14/01/2020.
//

#include <iostream>

#include "Main.h"


using namespace std ;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        boot::Main().main(5600) ;
    } else {
        boot::Main().main(stoi(argv[1]));
    }
    return 0;
}