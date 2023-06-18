protoc -I=. --grpc_out=. --plugin=protoc-gen-grpc=/opt/homebrew/bin/grpc_cpp_plugin game.proto

protoc --cpp_out=. game.proto