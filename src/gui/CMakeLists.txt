cmake_minimum_required(VERSION 3.22.1)
project(PokiRock LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DQT_NO_FOREACH")


add_link_options(-fsanitize=address,undefined)
add_compile_options(-g -fsanitize=address,undefined)

find_package(Boost REQUIRED)
find_package(Threads REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(OpenSSL REQUIRED)

#for LIMA
#add_executable(PokiRock client.cpp server.cpp game.cpp win_check.cpp ../main.cpp)

#all project with graphic
#add_executable(PokiRock  ../server/DataBase_connector.cpp ../client/Client.cpp ../server/Server.cpp ../server/Game.cpp ../server/Win_check.cpp Registration_window.cpp Game.cpp  Main_menu.cpp  First_window.cpp Authorization_window.cpp  main.cpp)

#only logic
#add_executable(PokiRock  ../server/DataBase_connector.cpp ../client/client.cpp ../server/Game.cpp ../server/Server.cpp ../server/Win_check.cpp  ../server/Card.cpp ../main.cpp)

#only graphic
add_executable(PokiRock main_menu.cpp first_window.cpp authorization_window.cpp registration_window.cpp game.cpp main.cpp labels.qrc other.qrc cover.qrc clubs.qrc spades.qrc diamonds.qrc hearts.qrc)

#only main
#add_executable(PokiRock  ../server/DataBase_connector.cpp ../main.cpp)

#testing file
#add_executable(PokiRock ../TEMPORARY_TEMP_FILE.cpp)

target_include_directories(PokiRock PRIVATE
        ${BOOST_INCLUDE_DIRS}
        ${Qt5Widgets_INCLUDE_DIRS}
        ${PQXX_INCLUDE_DIRS}
        ${OPENSSL_INCLUDE_DIR}
)

target_link_libraries(PokiRock
        ${Boost_LIBRARIES}
        Threads::Threads
        Qt5::Widgets
        ${PQXX_LIB}
        OpenSSL::Crypto
)
