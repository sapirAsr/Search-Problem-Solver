cmake_minimum_required(VERSION 3.15)
project(ex4_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(ex4_1 Main.cpp Server.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.cpp Solver.h CacheManager.cpp CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h Main.cpp Main.h Main.cpp Main.h main.cpp)