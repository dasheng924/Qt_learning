#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDebug>
#include <QIODevice>
#include <QLabel>
#include <QGridLayout>
#include <QFileInfo>
#include <QDataStream>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#if 0
//普通文件的操作

    QFile file("/Users/sunguosheng/Documents/MorkDown/大小端.md")  ;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"open file fail!";
        return;
    }
    else{
        qDebug()<<"open ok!";
        while(!file.atEnd())
        {
            qDebug()<<file.readLine();
        }
    }

    QFileInfo info(file);
    qDebug()<<info.completeSuffix();
    qDebug()<<info.completeBaseName();
    qDebug()<<info.path();
    qDebug()<<info.baseName();
    qDebug()<<info.isExecutable();

#endif

#if 0
    //二进制流的形式
    QFile file("/Users/sunguosheng/Downloads/test_dataStream.txt");

//    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
//    {
//        qDebug()<<"open file fail!";
//        return;
//    }
//    QDataStream out(&file);
//    out<<QString("hello");
//    out<<qint32(1200);
//    file.close();



    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    QString str;
    qint32 num;
    in>>str>>num;
    qDebug()<<str<<"    "<<num;
    file.close();



#endif

    QFile file("/Users/sunguosheng/Downloads/test_TextStream.txt");
//    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
//    {
//        qDebug()<<"open file fail!";
//        return;
//    }

//    QTextStream out(&file);
//    out<<QString("hello world");
//    out<<qint16('1');

//    file.close();

    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString str;
    qint16 ch;
    in>>str;
    in>>ch;
    qDebug()<<str;
    qDebug()<<ch;
    file.close();






}

MainWindow::~MainWindow()
{
    delete ui;
}

