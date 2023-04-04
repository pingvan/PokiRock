cmake_minimum_required(VERSION 3.22)
project(PokiRock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)



add_executable(main main.cpp client/Client.cpp server/Server.cpp server/Win_check.cpp)
