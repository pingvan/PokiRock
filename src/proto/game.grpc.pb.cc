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

static const char* all_types_of_calls_method_names[] = {
  "/game.all_types_of_calls/PokerFunc",
};

std::unique_ptr< all_types_of_calls::Stub> all_types_of_calls::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< all_types_of_calls::Stub> stub(new all_types_of_calls::Stub(channel, options));
  return stub;
}

all_types_of_calls::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_PokerFunc_(all_types_of_calls_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::ClientReaderWriter< ::game::all_requests, ::game::all_responses>* all_types_of_calls::Stub::PokerFuncRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::game::all_requests, ::game::all_responses>::Create(channel_.get(), rpcmethod_PokerFunc_, context);
}

void all_types_of_calls::Stub::async::PokerFunc(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::game::all_requests,::game::all_responses>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::game::all_requests,::game::all_responses>::Create(stub_->channel_.get(), stub_->rpcmethod_PokerFunc_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::game::all_requests, ::game::all_responses>* all_types_of_calls::Stub::AsyncPokerFuncRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::game::all_requests, ::game::all_responses>::Create(channel_.get(), cq, rpcmethod_PokerFunc_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::game::all_requests, ::game::all_responses>* all_types_of_calls::Stub::PrepareAsyncPokerFuncRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::game::all_requests, ::game::all_responses>::Create(channel_.get(), cq, rpcmethod_PokerFunc_, context, false, nullptr);
}

all_types_of_calls::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      all_types_of_calls_method_names[0],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< all_types_of_calls::Service, ::game::all_requests, ::game::all_responses>(
          [](all_types_of_calls::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::game::all_responses,
             ::game::all_requests>* stream) {
               return service->PokerFunc(ctx, stream);
             }, this)));
}

all_types_of_calls::Service::~Service() {
}

::grpc::Status all_types_of_calls::Service::PokerFunc(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::game::all_responses, ::game::all_requests>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* lobby_method_names[] = {
  "/game.lobby/Login",
  "/game.lobby/Register",
  "/game.lobby/FindGame",
  "/game.lobby/MakeGame",
};

std::unique_ptr< lobby::Stub> lobby::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< lobby::Stub> stub(new lobby::Stub(channel, options));
  return stub;
}

lobby::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Login_(lobby_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Register_(lobby_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_FindGame_(lobby_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_MakeGame_(lobby_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  {}

::grpc::Status lobby::Stub::Login(::grpc::ClientContext* context, const ::game::login_request& request, ::game::login_response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::game::login_request, ::game::login_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Login_, context, request, response);
}

void lobby::Stub::async::Login(::grpc::ClientContext* context, const ::game::login_request* request, ::game::login_response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::game::login_request, ::game::login_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Login_, context, request, response, std::move(f));
}

void lobby::Stub::async::Login(::grpc::ClientContext* context, const ::game::login_request* request, ::game::login_response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Login_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::game::login_response>* lobby::Stub::PrepareAsyncLoginRaw(::grpc::ClientContext* context, const ::game::login_request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::game::login_response, ::game::login_request, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Login_, context, request);
}

::grpc::ClientAsyncResponseReader< ::game::login_response>* lobby::Stub::AsyncLoginRaw(::grpc::ClientContext* context, const ::game::login_request& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncLoginRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status lobby::Stub::Register(::grpc::ClientContext* context, const ::game::register_request& request, ::game::register_response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::game::register_request, ::game::register_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Register_, context, request, response);
}

void lobby::Stub::async::Register(::grpc::ClientContext* context, const ::game::register_request* request, ::game::register_response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::game::register_request, ::game::register_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Register_, context, request, response, std::move(f));
}

void lobby::Stub::async::Register(::grpc::ClientContext* context, const ::game::register_request* request, ::game::register_response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Register_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::game::register_response>* lobby::Stub::PrepareAsyncRegisterRaw(::grpc::ClientContext* context, const ::game::register_request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::game::register_response, ::game::register_request, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Register_, context, request);
}

::grpc::ClientAsyncResponseReader< ::game::register_response>* lobby::Stub::AsyncRegisterRaw(::grpc::ClientContext* context, const ::game::register_request& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRegisterRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status lobby::Stub::FindGame(::grpc::ClientContext* context, const ::game::search_a_game_request& request, ::game::search_a_game_response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::game::search_a_game_request, ::game::search_a_game_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_FindGame_, context, request, response);
}

void lobby::Stub::async::FindGame(::grpc::ClientContext* context, const ::game::search_a_game_request* request, ::game::search_a_game_response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::game::search_a_game_request, ::game::search_a_game_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_FindGame_, context, request, response, std::move(f));
}

void lobby::Stub::async::FindGame(::grpc::ClientContext* context, const ::game::search_a_game_request* request, ::game::search_a_game_response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_FindGame_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::game::search_a_game_response>* lobby::Stub::PrepareAsyncFindGameRaw(::grpc::ClientContext* context, const ::game::search_a_game_request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::game::search_a_game_response, ::game::search_a_game_request, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_FindGame_, context, request);
}

::grpc::ClientAsyncResponseReader< ::game::search_a_game_response>* lobby::Stub::AsyncFindGameRaw(::grpc::ClientContext* context, const ::game::search_a_game_request& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncFindGameRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientReader< ::game::game_>* lobby::Stub::MakeGameRaw(::grpc::ClientContext* context, const ::game::game_parameters& request) {
  return ::grpc::internal::ClientReaderFactory< ::game::game_>::Create(channel_.get(), rpcmethod_MakeGame_, context, request);
}

void lobby::Stub::async::MakeGame(::grpc::ClientContext* context, const ::game::game_parameters* request, ::grpc::ClientReadReactor< ::game::game_>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::game::game_>::Create(stub_->channel_.get(), stub_->rpcmethod_MakeGame_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::game::game_>* lobby::Stub::AsyncMakeGameRaw(::grpc::ClientContext* context, const ::game::game_parameters& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::game::game_>::Create(channel_.get(), cq, rpcmethod_MakeGame_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::game::game_>* lobby::Stub::PrepareAsyncMakeGameRaw(::grpc::ClientContext* context, const ::game::game_parameters& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::game::game_>::Create(channel_.get(), cq, rpcmethod_MakeGame_, context, request, false, nullptr);
}

lobby::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      lobby_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< lobby::Service, ::game::login_request, ::game::login_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](lobby::Service* service,
             ::grpc::ServerContext* ctx,
             const ::game::login_request* req,
             ::game::login_response* resp) {
               return service->Login(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      lobby_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< lobby::Service, ::game::register_request, ::game::register_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](lobby::Service* service,
             ::grpc::ServerContext* ctx,
             const ::game::register_request* req,
             ::game::register_response* resp) {
               return service->Register(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      lobby_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< lobby::Service, ::game::search_a_game_request, ::game::search_a_game_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](lobby::Service* service,
             ::grpc::ServerContext* ctx,
             const ::game::search_a_game_request* req,
             ::game::search_a_game_response* resp) {
               return service->FindGame(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      lobby_method_names[3],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< lobby::Service, ::game::game_parameters, ::game::game_>(
          [](lobby::Service* service,
             ::grpc::ServerContext* ctx,
             const ::game::game_parameters* req,
             ::grpc::ServerWriter<::game::game_>* writer) {
               return service->MakeGame(ctx, req, writer);
             }, this)));
}

lobby::Service::~Service() {
}

::grpc::Status lobby::Service::Login(::grpc::ServerContext* context, const ::game::login_request* request, ::game::login_response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status lobby::Service::Register(::grpc::ServerContext* context, const ::game::register_request* request, ::game::register_response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status lobby::Service::FindGame(::grpc::ServerContext* context, const ::game::search_a_game_request* request, ::game::search_a_game_response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status lobby::Service::MakeGame(::grpc::ServerContext* context, const ::game::game_parameters* request, ::grpc::ServerWriter< ::game::game_>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* game_method_names[] = {
  "/game.game/MakeMove",
  "/game.game/make_async_move",
};

std::unique_ptr< game::Stub> game::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< game::Stub> stub(new game::Stub(channel, options));
  return stub;
}

game::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_MakeMove_(game_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_make_async_move_(game_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::Status game::Stub::MakeMove(::grpc::ClientContext* context, const ::game::make_move_request& request, ::game::make_move_response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::game::make_move_request, ::game::make_move_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_MakeMove_, context, request, response);
}

void game::Stub::async::MakeMove(::grpc::ClientContext* context, const ::game::make_move_request* request, ::game::make_move_response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::game::make_move_request, ::game::make_move_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_MakeMove_, context, request, response, std::move(f));
}

void game::Stub::async::MakeMove(::grpc::ClientContext* context, const ::game::make_move_request* request, ::game::make_move_response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_MakeMove_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::game::make_move_response>* game::Stub::PrepareAsyncMakeMoveRaw(::grpc::ClientContext* context, const ::game::make_move_request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::game::make_move_response, ::game::make_move_request, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_MakeMove_, context, request);
}

::grpc::ClientAsyncResponseReader< ::game::make_move_response>* game::Stub::AsyncMakeMoveRaw(::grpc::ClientContext* context, const ::game::make_move_request& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncMakeMoveRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientReaderWriter< ::game::move_request, ::game::move_response>* game::Stub::make_async_moveRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::game::move_request, ::game::move_response>::Create(channel_.get(), rpcmethod_make_async_move_, context);
}

void game::Stub::async::make_async_move(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::game::move_request,::game::move_response>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::game::move_request,::game::move_response>::Create(stub_->channel_.get(), stub_->rpcmethod_make_async_move_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::game::move_request, ::game::move_response>* game::Stub::Asyncmake_async_moveRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::game::move_request, ::game::move_response>::Create(channel_.get(), cq, rpcmethod_make_async_move_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::game::move_request, ::game::move_response>* game::Stub::PrepareAsyncmake_async_moveRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::game::move_request, ::game::move_response>::Create(channel_.get(), cq, rpcmethod_make_async_move_, context, false, nullptr);
}

game::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      game_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< game::Service, ::game::make_move_request, ::game::make_move_response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](game::Service* service,
             ::grpc::ServerContext* ctx,
             const ::game::make_move_request* req,
             ::game::make_move_response* resp) {
               return service->MakeMove(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      game_method_names[1],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< game::Service, ::game::move_request, ::game::move_response>(
          [](game::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::game::move_response,
             ::game::move_request>* stream) {
               return service->make_async_move(ctx, stream);
             }, this)));
}

game::Service::~Service() {
}

::grpc::Status game::Service::MakeMove(::grpc::ServerContext* context, const ::game::make_move_request* request, ::game::make_move_response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status game::Service::make_async_move(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::game::move_response, ::game::move_request>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace game
