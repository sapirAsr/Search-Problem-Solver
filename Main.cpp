//
// Created by michal on 14/01/2020.
//

#include "Main.h"
#include "AStar.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "DFS.h"
#include "MatCacheManager.h"
#include "MyClientHandler.h"



int boot::Main::main(int port) {
    /**vector<vector<double >> ss;
    vector<double > a = {1,2,3};
    for (int i = 0; i < 3; ++i) {
        ss.push_back(a);
    }
    Position d = Position(0,0);
    State<Position>* init = new State<Position>(d);
    State<Position>* goal = new State<Position>(Position(2, 2));
    Searchable<Position> *m = new Mat(ss,init,goal,3,3);
    Searcher<Position, vector<State<Position>*>> *n = new BFS<Position>;
    vector<State<Position>*> v = n->search(m);
    cout<<n->getNumberOfNodesEvaluated()<<endl;**/
    server_side::Server *s = new MyParallelServer;
    CacheManager* cacheManager = new MatCacheManager;
    Searcher<Position, vector<State<Position>*>> *n = new DFS<Position>;
    Solver<Searchable<Position>*, vector<State<Position>*>> *solver = new OA<Position, vector<State<Position>*>>(n);
    ClientHandler* c = new MyClientHandler(cacheManager,solver);
    s->open(port, c);

    return 0;
}