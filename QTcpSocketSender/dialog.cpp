#include "dialog.h"
#include "ui_dialog.h"

#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    server = new QTcpServer(this);
    setWindowTitle("服务器");
    connect(ui->startPushButton,&QPushButton::clicked,this,[=](){

        if(!server->listen(QHostAddress::Any,quint16(ui->portLineEdit->text().toInt())))
        {
            qDebug()<<server->errorString();
            server->disconnect();
            server->close();
            server->deleteLater();
            close();
        }
        ui->messageTextEdit->append("等待客户端连接......");
    });


    connect(server,&QTcpServer::newConnection,this,[=](){
        socket = server->nextPendingConnection();
        ui->messageTextEdit->append("成功和客户端建立了连接...");
        ui->startPushButton->setEnabled(false);

        QString ipInfo = "连接的IP:"+socket->peerAddress().toString();
        QString portInfo = "连接的Port:"+QString::number(socket->peerPort());

        ui->messageTextEdit->append(ipInfo);
        ui->messageTextEdit->append(portInfo);

        //检测客户端是否有数据发送过来
        connect(socket,&QTcpSocket::readyRead,this,[=](){
            //接受数据
            QByteArray data = socket->readAll();

            ui->messageTextEdit->append("客户端say:"+QString(data));
        });
        connect(socket,&QTcpSocket::disconnected,this,[=](){
            ui->messageTextEdit->append("客户端断开了连接!");
            socket->deleteLater();
            ui->startPushButton->setEnabled(true);
        });
    });


    connect(ui->sendMessagepushButton,&QPushButton::clicked,this,[=](){
        QByteArray data = ui->sendInfoTextEdit->toPlainText().toUtf8();
        ui->messageTextEdit->append("服务器say:"+data);
        socket->write(data);
        ui->sendInfoTextEdit->clear();

    });
}

Dialog::~Dialog()
{
    delete ui;
}

