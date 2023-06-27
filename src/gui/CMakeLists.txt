cmake_minimum_required(VERSION 3.25)
project(PokiRock LANGUAGES CXX)

include(FetchContent)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DQT_NO_FOREACH")

set(OPENSSL_ROOT_DIR /opt/homebrew/Cellar/openssl@1.1/1.1.1t)

find_package(Boost REQUIRED)
find_package(Threads REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(PkgConfig REQUIRED)
#find_package(PostgreSQL REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

set(PROTOS ../proto/game.grpc.pb.cc ../proto/game.pb.cc)

add_executable(server ${PROTOS} ../server/grpc_server_main.cpp  ../server/grpc_server.cpp ../server/DataBase_connector.cpp ../server/game_copy_for_server.cpp ../server/player.cpp ../server/Card.cpp ../server/Win_check.cpp)

add_executable(client ${PROTOS} ../client/grpc_client_main.cpp ../client/grpc_client.cpp ../client/salt_hash.cpp)

add_custom_target(PokiRock)
add_dependencies(PokiRock
    client
    server
)


target_include_directories(client PRIVATE
        ${Qt6Widgets_INCLUDE_DIRS}
        ${OPENSSL_CRYPTO_LIBRARY}
        ${OPENSSL_INCLUDE_DIR}
        ${PROTOBUF_INCLUDE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        )

target_link_libraries(client
        Threads::Threads
        Qt${QT_VERSION}::Widgets
        OpenSSL::Crypto
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
        )

target_link_options(server PRIVATE -L/opt/homebrew/Cellar/libpqxx/7.7.5/lib -lpqxx)

target_include_directories(server PRIVATE
        ${Qt6Widgets_INCLUDE_DIRS}
        ${PQXX_INCLUDE_DIRS}
        ${OPENSSL_CRYPTO_LIBRARY}
        ${OPENSSL_INCLUDE_DIR}
        ${PROTOBUF_INCLUDE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        )

target_link_libraries(server
        Threads::Threads
        Qt${QT_VERSION}::Widgets
        pqxx
        OpenSSL::Crypto
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
        )

