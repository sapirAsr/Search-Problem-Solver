//
// Created by michal on 24/01/2020.
//

#ifndef MILESTONE2_MYCLIENTHANDLER_H
#define MILESTONE2_MYCLIENTHANDLER_H


#include "ClientHandler.h"

/**
 * this class implements the client handler intrface.
 */
class MyClientHandler : public ClientHandler {
private:
    CacheManager* cacheManager;
    Solver<Searchable<Position>*, vector<State<Position>*>>* solver;
public:
    MyClientHandler(CacheManager* cache, Solver<Searchable<Position>*, vector<State<Position>*>>* solver);
    void handleClient(int input);
    Position createPosition(string line);
    vector<vector<double>> createMatrix(deque<string> mat);
    bool Find(string str);
    string stringMatrix(deque<string> mat);
    string toStringSolution(vector<State<Position>*> path);
    ClientHandler *clone();

};



#endif //MILESTONE2_MYCLIENTHANDLER_H
