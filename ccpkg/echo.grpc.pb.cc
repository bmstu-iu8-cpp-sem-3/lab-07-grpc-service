// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: echo.proto

#include "echo.pb.h"
#include "echo.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace echo {

static const char* Echo_method_names[] = {
  "/echo.Echo/Hello",
};

std::unique_ptr< Echo::Stub> Echo::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Echo::Stub> stub(new Echo::Stub(channel));
  return stub;
}

Echo::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Hello_(Echo_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Echo::Stub::Hello(::grpc::ClientContext* context, const ::echo::HelloRequest& request, ::echo::HelloResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Hello_, context, request, response);
}

void Echo::Stub::experimental_async::Hello(::grpc::ClientContext* context, const ::echo::HelloRequest* request, ::echo::HelloResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Hello_, context, request, response, std::move(f));
}

void Echo::Stub::experimental_async::Hello(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::echo::HelloResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Hello_, context, request, response, std::move(f));
}

void Echo::Stub::experimental_async::Hello(::grpc::ClientContext* context, const ::echo::HelloRequest* request, ::echo::HelloResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Hello_, context, request, response, reactor);
}

void Echo::Stub::experimental_async::Hello(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::echo::HelloResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Hello_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::echo::HelloResponse>* Echo::Stub::AsyncHelloRaw(::grpc::ClientContext* context, const ::echo::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::echo::HelloResponse>::Create(channel_.get(), cq, rpcmethod_Hello_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::echo::HelloResponse>* Echo::Stub::PrepareAsyncHelloRaw(::grpc::ClientContext* context, const ::echo::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::echo::HelloResponse>::Create(channel_.get(), cq, rpcmethod_Hello_, context, request, false);
}

Echo::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Echo_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Echo::Service, ::echo::HelloRequest, ::echo::HelloResponse>(
          [](Echo::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::echo::HelloRequest* req,
             ::echo::HelloResponse* resp) {
               return service->Hello(ctx, req, resp);
             }, this)));
}

Echo::Service::~Service() {
}

::grpc::Status Echo::Service::Hello(::grpc::ServerContext* context, const ::echo::HelloRequest* request, ::echo::HelloResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace echo

