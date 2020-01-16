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

int boot::Main::main(int port) {
    server_side::Server *s = new MySerialServer;
    CacheManager* cacheManager = new FileCacheManager(5);
    Solver<string, string> *solver = new StringReverser;
    ClientHandler* c = new MyTestClientHandler(cacheManager,solver);
    s->open(port, c);
    return 0;
}