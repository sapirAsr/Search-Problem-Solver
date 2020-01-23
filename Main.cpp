//
// Created by michal on 14/01/2020.
//

#include "Main.h"

int boot::Main::main(int port) {
    vector<double > a = {1,2,3};
    vector<double > b = {1,2,3};
    vector<double > c = {1,2,3};
    vector<vector<double >> ss;
    ss.push_back(a);
    ss.push_back(b);
    ss.push_back(c);
    Position d = Position(0,0);
    State<Position>* init = new State<Position>(d);
    State<Position>* goal = new State<Position>(Position(2,2));
    Searchable<Position> *m = new Mat(ss,init,goal,3,3);
    Searcher<Position, vector<State<Position>*>> *n = new BFS<Position>;
    vector<State<Position>*> v = n->search(m);
    cout<<n->getNumberOfNodesEvaluated()<<endl;
    //server_side::Server *s = new MySerialServer;
    //CacheManager* cacheManager = new FileCacheManager(5);
    //Solver<string, string> *solver = new StringReverser;
    //ClientHandler* c = new MyTestClientHandler(cacheManager,solver);
    //s->open(port, c);
    return 0;
}