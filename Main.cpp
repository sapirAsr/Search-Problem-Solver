//
// Created by michal on 14/01/2020.
//

#include "Main.h"
#include "MySerialServer.h"
#include "Server.h"
#include "Solver.h"
#include "StringReverser.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "Mat.h"

int boot::Main::main(int port) {
    vector<Position> s;
    s.push_back("sapir");
    vector<string> s2;
    s2.push_back("michal");
    vector<vector<string>> ss;
    ss.push_back(s);
    Mat *m = new Mat(ss);
    vector<int> v1 = {1,2,3};
    vector<int> v2;
    for (int i = 1; i <= 5; i++)
        v2.push_back(i);
    for (auto i = v1.begin(); i != v1.end(); ++i)
        cout << *i << " ";

    //server_side::Server *s = new MySerialServer;
    //CacheManager* cacheManager = new FileCacheManager(5);
    //Solver<string, string> *solver = new StringReverser;
    //ClientHandler* c = new MyTestClientHandler(cacheManager,solver);
    //s->open(port, c);
    return 0;
}