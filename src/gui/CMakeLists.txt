cmake_minimum_required(VERSION 3.22)
project(PokiRock LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Werror")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DQT_NO_FOREACH")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

#set(LIBPQXX /opt/homebrew/Cellar)
#set(PQ /opt/homebrew/Cellar)

#find_library(LIBPQXX_LIB pqxx)
#find_library(PQ_LIB pq)


include_directories(${Qt6Widgets_INCLUDE_DIRS})
include_directories(${PQXX_INCLUDE_DIRS})

find_package(Threads REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(PkgConfig REQUIRED)

#find_library(PQXX_LIB pqxx)
#find_library(PQ_LIB pq)
#link_directories(${libpqxx_LIBRARY_DIR})


#add_executable(PokiRock  qt_files/Main_menu.cpp  qt_files/First_window.cpp qt_files/Authorization_window.cpp  qt_files/main.cpp)
add_executable(PokiRock ../client/Client.cpp ../server/Server.cpp ../server/Game.cpp ../server/Win_check.cpp ../main.cpp)
target_link_libraries(PokiRock Qt${QT_VERSION}::Widgets)
target_link_libraries(PokiRock ${LIBPQXX_LIB})
