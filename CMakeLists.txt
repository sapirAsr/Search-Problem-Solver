cmake_minimum_required(VERSION 3.15)
project(milestone2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(milestone2 State.cpp State.h Server.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.cpp Solver.h CacheManager.cpp CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h Main.h Main.cpp Searcher.cpp Searcher.h Searchable.cpp Searchable.h BFS.cpp BFS.h Mat.cpp Mat.h BestFirstSearch.cpp BestFirstSearch.h DFS.cpp DFS.h Comper.cpp Comper.h AStar.cpp AStar.h Position.cpp Position.h OA.cpp OA.h MatCacheManager.cpp MatCacheManager.h MyParallelServer.cpp MyParallelServer.h MyClientHandler.cpp MyClientHandler.h)