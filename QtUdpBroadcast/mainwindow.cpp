#include "mainwindow.h"
#include "ui_mainwindow.h"



#include <QUdpSocket>
#include <QPushButton>
#include <QGridLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGridLayout *gLayout = new QGridLayout;
    QPushButton *btn = new QPushButton(this);
    btn->setText("广播");
    gLayout->addWidget(btn);
    centralWidget()->setLayout(gLayout);
    setWindowTitle("Udp 广播");

    sender = new QUdpSocket(this);

    connect(btn,&QPushButton::clicked,this,[=](){
        QByteArray data = "hello world";
        qint16 size = data.size();

        QString info = QString::number(size)+data;
        //参数1:发送的数据
        //参数2:发送数据的大小
        //要发送给那个终端
        //在那个端口接受数据

        /*Udp数据报总是作为一个整体写入,它的最大发送字节数是根据平台决定的,但是最好不要大于521字节,
         * 大于512字节的话,会在IP层进行分片
         */
        sender->writeDatagram(info.toUtf8(),info.size(),QHostAddress::Broadcast,44444);
    });

    connect(sender,&QUdpSocket::disconnected,sender,&QUdpSocket::deleteLater);










}

MainWindow::~MainWindow()
{
    delete ui;
}

