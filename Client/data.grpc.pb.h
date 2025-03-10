// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: data.proto
#ifndef GRPC_data_2eproto__INCLUDED
#define GRPC_data_2eproto__INCLUDED

#include "data.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

//
// 客户端发送MyRequest,服务端接收到后返回MyResponse
class Myservice final {
 public:
  static constexpr char const* service_full_name() {
    return "Myservice";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status MyMethod(::grpc::ClientContext* context, const ::MyRequest& request, ::MyResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::MyResponse>> AsyncMyMethod(::grpc::ClientContext* context, const ::MyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::MyResponse>>(AsyncMyMethodRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::MyResponse>> PrepareAsyncMyMethod(::grpc::ClientContext* context, const ::MyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::MyResponse>>(PrepareAsyncMyMethodRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void MyMethod(::grpc::ClientContext* context, const ::MyRequest* request, ::MyResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void MyMethod(::grpc::ClientContext* context, const ::MyRequest* request, ::MyResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::MyResponse>* AsyncMyMethodRaw(::grpc::ClientContext* context, const ::MyRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::MyResponse>* PrepareAsyncMyMethodRaw(::grpc::ClientContext* context, const ::MyRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status MyMethod(::grpc::ClientContext* context, const ::MyRequest& request, ::MyResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::MyResponse>> AsyncMyMethod(::grpc::ClientContext* context, const ::MyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::MyResponse>>(AsyncMyMethodRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::MyResponse>> PrepareAsyncMyMethod(::grpc::ClientContext* context, const ::MyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::MyResponse>>(PrepareAsyncMyMethodRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void MyMethod(::grpc::ClientContext* context, const ::MyRequest* request, ::MyResponse* response, std::function<void(::grpc::Status)>) override;
      void MyMethod(::grpc::ClientContext* context, const ::MyRequest* request, ::MyResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::MyResponse>* AsyncMyMethodRaw(::grpc::ClientContext* context, const ::MyRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::MyResponse>* PrepareAsyncMyMethodRaw(::grpc::ClientContext* context, const ::MyRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_MyMethod_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status MyMethod(::grpc::ServerContext* context, const ::MyRequest* request, ::MyResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_MyMethod : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_MyMethod() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_MyMethod() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status MyMethod(::grpc::ServerContext* /*context*/, const ::MyRequest* /*request*/, ::MyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestMyMethod(::grpc::ServerContext* context, ::MyRequest* request, ::grpc::ServerAsyncResponseWriter< ::MyResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_MyMethod<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_MyMethod : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_MyMethod() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::MyRequest, ::MyResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::MyRequest* request, ::MyResponse* response) { return this->MyMethod(context, request, response); }));}
    void SetMessageAllocatorFor_MyMethod(
        ::grpc::MessageAllocator< ::MyRequest, ::MyResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::MyRequest, ::MyResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_MyMethod() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status MyMethod(::grpc::ServerContext* /*context*/, const ::MyRequest* /*request*/, ::MyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* MyMethod(
      ::grpc::CallbackServerContext* /*context*/, const ::MyRequest* /*request*/, ::MyResponse* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_MyMethod<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_MyMethod : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_MyMethod() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_MyMethod() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status MyMethod(::grpc::ServerContext* /*context*/, const ::MyRequest* /*request*/, ::MyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_MyMethod : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_MyMethod() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_MyMethod() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status MyMethod(::grpc::ServerContext* /*context*/, const ::MyRequest* /*request*/, ::MyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestMyMethod(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_MyMethod : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_MyMethod() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->MyMethod(context, request, response); }));
    }
    ~WithRawCallbackMethod_MyMethod() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status MyMethod(::grpc::ServerContext* /*context*/, const ::MyRequest* /*request*/, ::MyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* MyMethod(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_MyMethod : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_MyMethod() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::MyRequest, ::MyResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::MyRequest, ::MyResponse>* streamer) {
                       return this->StreamedMyMethod(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_MyMethod() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status MyMethod(::grpc::ServerContext* /*context*/, const ::MyRequest* /*request*/, ::MyResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedMyMethod(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::MyRequest,::MyResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_MyMethod<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_MyMethod<Service > StreamedService;
};


#endif  // GRPC_data_2eproto__INCLUDED
