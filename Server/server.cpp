#include <grpcpp/grpcpp.h>
#include <fstream>
#include <iostream>
#include "data.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using namespace std;

class MyserviceImpl final : public Myservice::Service {
    grpc::Status MyMethod(ServerContext* context, const MyRequest* request, MyResponse* response) override {
        // 获取客户端发送的数据
        string count = request->count();
        string name = request->name();
        string step = request->step();
        string description = request->description();

        // 将数据存储到本地文件（ANSI 编码）
        ofstream outfile("data.txt", ios::app); // 以追加模式打开文件
        if (outfile.is_open()) {
            // 使用 u8 前缀强制 UTF-8 编码
            outfile << u8"编号: " << count << u8", 名称: " << name
                << u8", 工步类型: " << step << u8", 描述: " << description << endl;
            outfile.close();
            cout << "输入成功" << endl;
            response->set_message("Data saved successfully");
        }
        else {
            response->set_message("Failed to save data");
        }

        return Status::OK;
    }
};

void RunServer() {
    string server_address("0.0.0.0:50051");
    MyserviceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    unique_ptr<Server> server(builder.BuildAndStart());
    cout << "Server listening on " << server_address << endl;
    server->Wait();
}

int main() {
    RunServer();
    return 0;
}