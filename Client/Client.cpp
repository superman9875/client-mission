#include "Client.h"

Client::Client(QWidget* parent)
    : QMainWindow(parent) {
    ui.setupUi(this);

    // 初始化 gRPC 客户端
    auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    stub_ = Myservice::NewStub(channel);
    //输入内容，打开comboBox可编辑
    ui.comboBox->addItems({ "类型一","类型二","类型三"});
    ui.comboBox->setCurrentIndex(0);
    ui.comboBox->setEditable(true);
    // 连接按钮点击事件
    connect(ui.pushButton, &QPushButton::clicked, this, &Client::onAddButtonClicked);
}

Client::~Client() {}

void Client::onAddButtonClicked() {
    // 获取用户输入的数据
    QString count = ui.textEdit_1->toPlainText();
    QString name = ui.textEdit_2->toPlainText();
    QString step = ui.comboBox->currentText();
    QString description = ui.textEdit_3->toPlainText();

    // 准备 gRPC 请求
    MyRequest request;
    request.set_count(count.toStdString());
    request.set_name(name.toStdString());
    request.set_step(step.toStdString());
    request.set_description(description.toStdString());

    // 发送请求
    MyResponse response;
    grpc::ClientContext context;
    grpc::Status status = stub_->MyMethod(&context, request, &response);

    // 处理响应
    if (status.ok()) {
        // 成功响应，显示信息弹窗
        QMessageBox::information(this, "成功", QString::fromStdString(response.message()));
    }
    else {
        // 失败响应，显示错误弹窗
        QMessageBox::critical(this, "错误", QString::fromStdString(status.error_message()));
    }
}