// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: game.proto

#include "game.pb.h"
#include "game.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace game {

static const char* Authorization_method_names[] = {
  "/game.Authorization/Login",
  "/game.Authorization/Registration",
};

std::unique_ptr< Authorization::Stub> Authorization::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Authorization::Stub> stub(new Authorization::Stub(channel, options));
  return stub;
}

Authorization::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Login_(Authorization_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Registration_(Authorization_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Authorization::Stub::Login(::grpc::ClientContext* context, const ::game::LoginRequest& request, ::game::LoginResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::game::LoginRequest, ::game::LoginResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Login_, context, request, response);
}

void Authorization::Stub::async::Login(::grpc::ClientContext* context, const ::game::LoginRequest* request, ::game::LoginResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::game::LoginRequest, ::game::LoginResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Login_, context, request, response, std::move(f));
}

void Authorization::Stub::async::Login(::grpc::ClientContext* context, const ::game::LoginRequest* request, ::game::LoginResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Login_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::game::LoginResponse>* Authorization::Stub::PrepareAsyncLoginRaw(::grpc::ClientContext* context, const ::game::LoginRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::game::LoginResponse, ::game::LoginRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Login_, context, request);
}

::grpc::ClientAsyncResponseReader< ::game::LoginResponse>* Authorization::Stub::AsyncLoginRaw(::grpc::ClientContext* context, const ::game::LoginRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncLoginRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Authorization::Stub::Registration(::grpc::ClientContext* context, const ::game::RegisterRequest& request, ::game::RegisterResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::game::RegisterRequest, ::game::RegisterResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Registration_, context, request, response);
}

void Authorization::Stub::async::Registration(::grpc::ClientContext* context, const ::game::RegisterRequest* request, ::game::RegisterResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::game::RegisterRequest, ::game::RegisterResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Registration_, context, request, response, std::move(f));
}

void Authorization::Stub::async::Registration(::grpc::ClientContext* context, const ::game::RegisterRequest* request, ::game::RegisterResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Registration_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::game::RegisterResponse>* Authorization::Stub::PrepareAsyncRegistrationRaw(::grpc::ClientContext* context, const ::game::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::game::RegisterResponse, ::game::RegisterRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Registration_, context, request);
}

::grpc::ClientAsyncResponseReader< ::game::RegisterResponse>* Authorization::Stub::AsyncRegistrationRaw(::grpc::ClientContext* context, const ::game::RegisterRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRegistrationRaw(context, request, cq);
  result->StartCall();
  return result;
}

Authorization::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Authorization_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Authorization::Service, ::game::LoginRequest, ::game::LoginResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Authorization::Service* service,
             ::grpc::ServerContext* ctx,
             const ::game::LoginRequest* req,
             ::game::LoginResponse* resp) {
               return service->Login(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Authorization_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Authorization::Service, ::game::RegisterRequest, ::game::RegisterResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Authorization::Service* service,
             ::grpc::ServerContext* ctx,
             const ::game::RegisterRequest* req,
             ::game::RegisterResponse* resp) {
               return service->Registration(ctx, req, resp);
             }, this)));
}

Authorization::Service::~Service() {
}

::grpc::Status Authorization::Service::Login(::grpc::ServerContext* context, const ::game::LoginRequest* request, ::game::LoginResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Authorization::Service::Registration(::grpc::ServerContext* context, const ::game::RegisterRequest* request, ::game::RegisterResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* Lobby_method_names[] = {
  "/game.Lobby/LobbyFunc",
};

std::unique_ptr< Lobby::Stub> Lobby::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Lobby::Stub> stub(new Lobby::Stub(channel, options));
  return stub;
}

Lobby::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_LobbyFunc_(Lobby_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::ClientReaderWriter< ::game::LobbyRequests, ::game::LobbyResponses>* Lobby::Stub::LobbyFuncRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::game::LobbyRequests, ::game::LobbyResponses>::Create(channel_.get(), rpcmethod_LobbyFunc_, context);
}

void Lobby::Stub::async::LobbyFunc(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::game::LobbyRequests,::game::LobbyResponses>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::game::LobbyRequests,::game::LobbyResponses>::Create(stub_->channel_.get(), stub_->rpcmethod_LobbyFunc_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::game::LobbyRequests, ::game::LobbyResponses>* Lobby::Stub::AsyncLobbyFuncRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::game::LobbyRequests, ::game::LobbyResponses>::Create(channel_.get(), cq, rpcmethod_LobbyFunc_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::game::LobbyRequests, ::game::LobbyResponses>* Lobby::Stub::PrepareAsyncLobbyFuncRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::game::LobbyRequests, ::game::LobbyResponses>::Create(channel_.get(), cq, rpcmethod_LobbyFunc_, context, false, nullptr);
}

Lobby::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Lobby_method_names[0],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< Lobby::Service, ::game::LobbyRequests, ::game::LobbyResponses>(
          [](Lobby::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::game::LobbyResponses,
             ::game::LobbyRequests>* stream) {
               return service->LobbyFunc(ctx, stream);
             }, this)));
}

Lobby::Service::~Service() {
}

::grpc::Status Lobby::Service::LobbyFunc(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::game::LobbyResponses, ::game::LobbyRequests>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* PokerGame_method_names[] = {
  "/game.PokerGame/GameFunc",
};

std::unique_ptr< PokerGame::Stub> PokerGame::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< PokerGame::Stub> stub(new PokerGame::Stub(channel, options));
  return stub;
}

PokerGame::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GameFunc_(PokerGame_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::ClientReaderWriter< ::game::GameRequests, ::game::GameResponses>* PokerGame::Stub::GameFuncRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::game::GameRequests, ::game::GameResponses>::Create(channel_.get(), rpcmethod_GameFunc_, context);
}

void PokerGame::Stub::async::GameFunc(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::game::GameRequests,::game::GameResponses>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::game::GameRequests,::game::GameResponses>::Create(stub_->channel_.get(), stub_->rpcmethod_GameFunc_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::game::GameRequests, ::game::GameResponses>* PokerGame::Stub::AsyncGameFuncRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::game::GameRequests, ::game::GameResponses>::Create(channel_.get(), cq, rpcmethod_GameFunc_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::game::GameRequests, ::game::GameResponses>* PokerGame::Stub::PrepareAsyncGameFuncRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::game::GameRequests, ::game::GameResponses>::Create(channel_.get(), cq, rpcmethod_GameFunc_, context, false, nullptr);
}

PokerGame::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      PokerGame_method_names[0],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< PokerGame::Service, ::game::GameRequests, ::game::GameResponses>(
          [](PokerGame::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::game::GameResponses,
             ::game::GameRequests>* stream) {
               return service->GameFunc(ctx, stream);
             }, this)));
}

PokerGame::Service::~Service() {
}

::grpc::Status PokerGame::Service::GameFunc(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::game::GameResponses, ::game::GameRequests>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace game
