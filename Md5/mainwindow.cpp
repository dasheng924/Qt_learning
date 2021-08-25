#include "mainwindow.h"

#include <QCryptographicHash>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QByteArray data = "hello world";
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(data);

    QByteArray ret = hash.result();
    qDebug()<<ret<<"\n"<<ret.toHex();

    QByteArray rr = QCryptographicHash::hash(data,QCryptographicHash::Md5);
    qDebug()<<rr.toHex();

    //base64
    //编码
    QByteArray base = "你好,世界!";
    base = base.toBase64();
    qDebug()<<"old"<<base;

    //解码
    base = QByteArray::fromBase64(base);
    qDebug()<<"new"<<base.data();


}

MainWindow::~MainWindow()
{
}

