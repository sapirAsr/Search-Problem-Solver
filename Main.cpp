//
// Created by michal on 14/01/2020.
//

#include "Main.h"
#include "AStar.h"
#include "MatCacheManager.h"
#include "MyClientHandler.h"

int boot::Main::main(int port) {
    /**vector<vector<double >> ss;
    vector<double > a;
    for (int j = 0; j < 37; ++j) {
        a.push_back(j);
    }
    for (int i = 0; i < 37; ++i) {
        ss.push_back(a);
    }
    Position d = Position(0,0);
    State<Position>* init = new State<Position>(d);
    State<Position>* goal = new State<Position>(Position(36, 36));
    Searchable<Position> *m = new Mat(ss,init,goal,37,37);
    Searcher<Position, vector<State<Position>*>> *n = new AStar<Position>;
    vector<State<Position>*> v = n->search(m);

ClientHandler* MyTestClientHandler::clone() {
    return new MyTestClientHandler(this->cacheManager, solver->clone());
}
    cout<<n->getNumberOfNodesEvaluated()<<endl;**/
    server_side::Server *s = new MySerialServer;
    CacheManager* cacheManager = new FileCacheManager;

    Solver<string, string>* solver = new StringReverser;
    //Searcher<Position, vector<State<Position>*>> *n = new AStar<Position>;
    //Solver<Searchable<Position>*, vector<State<Position>*>> *solver =
    //        new OA<Position, vector<State<Position>*>>(n);
    ClientHandler* c = new MyTestClientHandler(cacheManager,solver);
    s->open(port, c);
    return 0;
}