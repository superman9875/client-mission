#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include<grpcpp/grpcpp.h>
#include<data.grpc.pb.h>
#include "ui_Client.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();
private slots:
    void onAddButtonClicked();
private:
    Ui::ClientClass ui;
    std::unique_ptr<Myservice::Stub> stub_;
};
