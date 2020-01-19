cmake_minimum_required(VERSION 3.15)
project(milestone2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(milestone2 Server.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.cpp Solver.h CacheManager.cpp CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h Main.h Main.cpp main.cpp)