cmake_minimum_required(VERSION 3.25)
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


#[[set(SOURCES_server
        ../server/grpc_server.cpp
        ../server/DataBase_connector.cpp
        ../proto/game.grpc.pb.cc
        ../proto/game.pb.cc
        )


set(SOURCES_client
        ../server/grpc_client.cpp
        ../proto/game.grpc.pb.cc
        ../proto/game.pb.cc
        )]]

#add_link_options(-fsanitize=address,undefined)
#add_compile_options(-g -fsanitize=address,undefined)

#set(PQXX /usr/local/include/pqxx)

#find_library(PQXX_LIB pqxx)
#find_library(PQ_LIB pq)


find_package(Boost REQUIRED)
find_package(Threads REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)


#for LIMA
#add_executable(PokiRock client.cpp server.cpp game.cpp win_check.cpp ../main.cpp)

#all project with graphic
#add_executable(PokiRock  ../server/DataBase_connector.cpp ../client/Client.cpp ../server/Server.cpp ../server/Game.cpp ../server/Win_check.cpp ../qt_files/Registration_window.cpp ../qt_files/game.cpp  ../qt_files/Main_menu.cpp  ../qt_files/First_window.cpp ../qt_files/Authorization_window.cpp  ../qt_files/main.cpp)

#only logic
#add_executable(PokiRock  ../server/DataBase_connector.cpp ../client/client.cpp ../server/Game.cpp ../server/Server.cpp ../server/Win_check.cpp  ../server/Card.cpp ../main.cpp)

#only graphic
#add_executable(PokiRock  ../qt_files/Main_menu.cpp  ../qt_files/First_window.cpp ../qt_files/Authorization_window.cpp  ../qt_files/main.cpp)

#only main
#add_executable(PokiRock   ../main.cpp)

#add_executable(PokiRock ../server/grpc_server.cpp ../server/grpc_server_main.cpp ../server/DataBase_connector.cpp ../server/Game.cpp ../server/grpc_client.cpp)

add_executable(PokiRock ../server/grpc_server_main.cpp  ../server/grpc_server.cpp ../server/DataBase_connector.cpp ../proto/game.grpc.pb.cc ../proto/game.pb.cc)

#add_executable(PokiRock ../proto/game.grpc.pb.cc ../proto/game.pb.cc)


#add_library(server OBJECT ${SOURCES_server})

#add_library(client OBJECT ${SOURCES_client})

target_include_directories(PokiRock PRIVATE
        ${BOOST_INCLUDE_DIRS}
        ${Qt6Widgets_INCLUDE_DIRS}
        ${PQXX_INCLUDE_DIRS}
        ${OPENSSL_CRYPTO_LIBRARY}
        ${OPENSSL_INCLUDE_DIR}
        ${PROTOBUF_INCLUDE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        )

target_link_libraries(PokiRock
        ${Boost_LIBRARIES}
        Threads::Threads
        Qt${QT_VERSION}::Widgets
        ${PQXX_LIB}
        OpenSSL::Crypto
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
        )


#[[target_include_directories(ser PRIVATE
        ${BOOST_INCLUDE_DIRS}
        ${Qt6Widgets_INCLUDE_DIRS}
        ${PQ_INCLUDE_DIRS}
        ${OPENSSL_CRYPTO_LIBRARY}
        ${OPENSSL_INCLUDE_DIR}
        ${PROTOBUF_INCLUDE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        )

target_link_libraries(ser
        ${Boost_LIBRARIES}
        Threads::Threads
        Qt${QT_VERSION}::Widgets
        ${PQXX_LIB}
        OpenSSL::Crypto
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
        )]]
