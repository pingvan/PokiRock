cmake_minimum_required(VERSION 3.22)
project(PokiRock LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DQT_NO_FOREACH")
set(OPENSSL_ROOT_DIR /opt/homebrew/Cellar/openssl@3/3.1.0)

add_link_options(-fsanitize=address,undefined)
add_compile_options(-fsanitize=address,undefined)

#TODO::downloading libs for client (if not installed)
include_directories(${Qt6Widgets_INCLUDE_DIRS})
include_directories(${PQXX_INCLUDE_DIRS})
#include_directories(${OPENSSL_CRYPTO_LIBRARY})
#include_directories(${OPENSSL_INCLUDE_DIR})

find_package(Threads REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(OpenSSL REQUIRED)

#add_executable(PokiRock client.cpp server.cpp game.cpp win_check.cpp ../main.cpp) #for my Linux

#add_executable(PokiRock  ../server/DataBase_connector.cpp ../client/Client.cpp ../server/Server.cpp ../server/Game.cpp ../server/Win_check.cpp ../qt_files/Main_menu.cpp  ../qt_files/First_window.cpp ../qt_files/Authorization_window.cpp  ../qt_files/main.cpp)
add_executable(PokiRock  ../rename_later.cpp ../server/DataBase_connector.cpp ../client/Client.cpp ../server/Game.cpp ../server/Server.cpp ../server/Win_check.cpp ../main.cpp)
#add_executable(PokiRock  ../qt_files/Main_menu.cpp  ../qt_files/First_window.cpp ../qt_files/Authorization_window.cpp  ../qt_files/main.cpp)
#add_executable(PokiRock ../main.cpp)
target_link_libraries(PokiRock Qt${QT_VERSION}::Widgets)
target_link_libraries(PokiRock ${PQXX_LIB})
target_link_libraries(PokiRock OpenSSL::Crypto)