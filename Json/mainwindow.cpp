#include "mainwindow.h"

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
#if 0
    //创建JSON对象
    QJsonObject obj;
    //创建JSON子对象
    QJsonObject sub;
    sub.insert("ip",QJsonValue("127.0.0.1"));
    sub.insert("port",QJsonValue(9999));
    sub.insert("name",QJsonValue("Alex"));
    obj.insert("server",QJsonValue(sub));


    //内存中的数据写到文件
    QJsonDocument doc(obj);//得倒document对象
    //将json对象转化为字符串
    QByteArray data = doc.toJson();
    //把字符串写入文件
    QFile file("/Users/sunguosheng/Downloads/temp.json");
    file.open(QIODevice::WriteOnly);
    file.write(data);
    file.close();
#else
    QFile file("/Users/sunguosheng/Downloads/temp.json");
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if(doc.isObject())
    {
        QJsonObject obj = doc.object();
        QJsonValue value = obj.value("server");
        if(value.isObject())
        {
            QJsonObject sub = value.toObject();
            QString ip = sub.value("ip").toString();
            int port = sub.value("port").toInt();
            qDebug()<<ip<<port;
        }

    }


#endif

}

MainWindow::~MainWindow()
{
}

