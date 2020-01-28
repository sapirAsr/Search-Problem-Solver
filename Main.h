//
// Created by michal on 14/01/2020.
//

#ifndef EX4_1_MAIN_H
#define EX4_1_MAIN_H
#include "Mat.h"
#include "Searcher.h"
#include "BFS.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "Searchable.h"
#include "MySerialServer.h"
#include "Server.h"
#include "Solver.h"
#include "StringReverser.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "OA.h"
#include "MyParallelServer.h"
#include "Main.h"
#include "AStar.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "DFS.h"
#include "MatCacheManager.h"
#include "MyClientHandler.h"


namespace boot {
    class Main {
    public:
        int main(int port) {
            server_side::Server *s = new MyParallelServer;
            CacheManager *cacheManager = new MatCacheManager;
            Searcher<Position, vector<State<Position> *>> *n = new AStar<Position>;
            Solver<Searchable<Position> *, vector<State<Position> *>> *solver = new OA<Position,
            vector<State<Position> *>>(n);
            ClientHandler *c = new MyClientHandler(cacheManager, solver);
            s->open(port, c);
            return 0;
        }
    };
}


#endif //EX4_1_MAIN_H
