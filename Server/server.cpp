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
        // ��ȡ�ͻ��˷��͵�����
        string count = request->count();
        string name = request->name();
        string step = request->step();
        string description = request->description();

        // �����ݴ洢�������ļ���ANSI ���룩
        ofstream outfile("data.txt", ios::app); // ��׷��ģʽ���ļ�
        if (outfile.is_open()) {
            // ʹ�� u8 ǰ׺ǿ�� UTF-8 ����
            outfile << u8"���: " << count << u8", ����: " << name
                << u8", ��������: " << step << u8", ����: " << description << endl;
            outfile.close();
            cout << "����ɹ�" << endl;
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