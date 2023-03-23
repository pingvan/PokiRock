cmake_minimum_required(VERSION 3.22)
project(PokiRock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_link_options(-fsanitize=address,undefined)
add_compile_options(-fsanitize=address,undefined)

add_executable(test doctest_main.cpp server/test_win_check.cpp ../src/server/win_check.cpp)
