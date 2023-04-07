cmake_minimum_required(VERSION 3.22)
project(PokiRock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

add_link_options(-fsanitize=address,undefined)
add_compile_options(-fsanitize=address,undefined)

add_executable(test
        doctest_main.cpp
        server/test_card.cpp
        ../server/Card.cpp
        server/test_win_check.cpp
        ../server/Win_check.cpp
)
