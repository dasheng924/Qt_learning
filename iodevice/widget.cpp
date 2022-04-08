#include "widget.h"
#include "ui_widget.h"

#include <QIODevice>
#include <QFile>
#include <QDebug>
#include <QTcpSocket>
#include <QFileInfo>
#include <QDir>
#include <QStandardPaths>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    QFile file;
    file.setFileName(QDir::currentPath()+"/show.txt");
    qDebug()<<QCoreApplication::applicationDirPath();
    qDebug()<<QDir::currentPath();
    qDebug()<<QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    qDebug()<<QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation);
    qDebug()<<QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
    qDebug()<<QStandardPaths::standardLocations(QStandardPaths::ApplicationsLocation);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) //Text 模式下，\n会转化为\r\n
    {
        qDebug()<<file.errorString();
    }

    file.write("hello \nMy world!");
    file.close();








































}

Widget::~Widget()
{
    delete ui;
}

