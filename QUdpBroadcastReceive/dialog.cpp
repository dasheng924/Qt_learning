#include "dialog.h"
#include "ui_dialog.h"

#include <QUdpSocket>
#include <QDebug>
#include <QNetworkDatagram>



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    receive = new QUdpSocket(this);

    //bind() 绑定IP和端口,IP地址默认支持所有的IPV4,最后的一个参数代表绑定模式
    //ShareAddress 允许其他服务器绑定到相同的地址和端口上
    receive->bind(44444,QUdpSocket::ShareAddress);

    //每当有数据来的时候,QUdpSocket会发出readyRead信号
    connect(receive,&QUdpSocket::readyRead,this,[=](){
        while(receive->hasPendingDatagrams()) //判断是否还有等待数据的读取
        {
            QByteArray data;
            //data的大小为等待处理的数据大小,这样才能接受完全的数据
            data.resize(receive->pendingDatagramSize());
//            qDebug()<<"等待处理的数据大小"<<receive->pendingDatagramSize();
//            //接受数据
//            receive->readDatagram(data.data(),data.size());
//            ui->label->setText(data);

            QNetworkDatagram datagram = receive->receiveDatagram(data.size());
            qDebug()<<"发送者的IP:"<<datagram.senderAddress().toString();
            qDebug()<<"发送者的PORT:"<<datagram.senderPort();
            ui->label->setText(datagram.data());
        }
    });




}

Dialog::~Dialog()
{
    delete ui;
}

