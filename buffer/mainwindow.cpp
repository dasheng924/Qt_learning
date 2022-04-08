#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBuffer>
#include <QByteArray>
#include <QPalette>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QByteArray array;
//#if 0
//    QBuffer buffer(&array);
//    buffer.open(QIODevice::WriteOnly);
//    QDataStream ss(&buffer);
//    ss<<QApplication::palette();
//#else
//    QBuffer buffer(&array);
//    buffer.open(QIODevice::ReadOnly);
//    QDataStream ss(&buffer);
//    QPalette palette;
//    ss>>palette;
//    qDebug()<<palette;
//#endif

    QByteArray array;

    QBuffer buffer(&array);
    if(!buffer.open(QIODevice::ReadWrite))
        return;

    struct NetInfo{
        QString ip;
        qint16 port;
    };

    NetInfo netInfo = {"192.168.134.88",6000};

    QDataStream s(&buffer);
    s<<netInfo.ip<<netInfo.port;

    buffer.close();


    QBuffer ff(&array);
    if(!ff.open(QIODevice::ReadOnly))
        return;
    QDataStream sss(&ff);
    QString ipp;
    qint16 portt;

    sss>>ipp;
    sss>>portt;

    qDebug()<<ipp<<"    "<<portt;

    ff.close();













}

MainWindow::~MainWindow()
{
    delete ui;
}

