#include "dialog.h"
#include "ui_dialog.h"
#include <QTcpSocket>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    setWindowTitle("客户端");
    ui->disconnectPushButton->setEnabled(false);

    socket = new QTcpSocket(this);

    //按下连接服务器按钮
    connect(ui->connectPushButton,&QPushButton::clicked,this,[=](){
        blockSize = 0;
        socket->abort();
        QString ip = ui->ipLineEdit->text();
        if(ip.isEmpty())
            ip = "127.0.0.1";
        QString port = ui->portLineEdit->text();
        socket->connectToHost(ip,(quint16)port.toInt());

    });

    //按下断开连接按钮
    connect(ui->disconnectPushButton,&QPushButton::clicked,this,[=](){
        socket->abort();
    });

    //连接上服务器后发送信号
    connect(socket,&QTcpSocket::connected,this,[=](){
        QString ip = ui->ipLineEdit->text();
        QString port = ui->portLineEdit->text();
        ui->messageTextEdit->append(QString("连接服务器成功:  %1:%2").arg(ip).arg(port));
        ui->connectPushButton->setEnabled(false);
        ui->disconnectPushButton->setEnabled(true);
    });

    //与服务器断开连接收到信号
    connect(socket,&QTcpSocket::disconnected,this,[=](){
        ui->messageTextEdit->append("与服务器已经断开连接!");
        ui->connectPushButton->setEnabled(true);
        ui->disconnectPushButton->setEnabled(false);
    });

    //有数据到来
    connect(socket,&QTcpSocket::readyRead,this,[=](){

        QByteArray str = socket->readAll();
        qDebug()<<str;
        ui->messageTextEdit->append("服务器say:"+str);
    });


    connect(ui->sendMessagepushButton,&QPushButton::clicked,this,[=](){

        QByteArray text = ui->sendInfoTextEdit->toPlainText().toUtf8();
        socket->write(text);
        ui->messageTextEdit->append("客户端say:"+text);
        ui->sendInfoTextEdit->clear();
    });


    //---------------信号的重载 方式1:
    typedef void (QTcpSocket::*p)(QAbstractSocket::SocketError);
    connect(socket,static_cast<p>(&QTcpSocket::error),this,[=](QAbstractSocket::SocketError){

        qDebug()<<socket->errorString();
    });
//    //---------------信号的重载 方式2:
//    connect(socket,static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketError)>(&QTcpSocket::error),this,[=](){

//    });

//    //---------------信号的重载 方式3:
//    void (QTcpSocket::*SP)(QAbstractSocket::SocketError) = &QTcpSocket::error;
//    connect(socket,SP,this,[=](){

//    });

}

Dialog::~Dialog()
{
    delete ui;
}

