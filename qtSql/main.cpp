#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include "connect.h"
#include <QVariant>
#include <QGuiApplication>

int main(int argc,char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);//启用高分屏的缩放
//    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);//启用高分屏的ICON


    QApplication a(argc,argv);

    QStringList sqlDrivers = QSqlDatabase::drivers();
    qDebug()<<"支持的数据库插件:";
    foreach(QString driver,sqlDrivers)
        qDebug()<<driver;


    if(!createConnection2())
    {
        qDebug()<<"连接失败!";
        return 1;
    }

    qDebug()<<"两个数据库连接成功,操作数据库也成功!";
    //查询整张表
    //通过连接名称返回数据库的连接
    QSqlDatabase db1;
    QSqlDatabase db2;
    {
        db1 = QSqlDatabase::database("connect1");
        db2 = QSqlDatabase::database("connect2");
    }


    //----------------db1----------------------------
    QSqlQuery query1(db1);
    bool ret = query1.exec("select * from info");
    if(!ret)
        qDebug()<<"执行命令失败,"<<query1.lastError().text();

    while(query1.next())
    {
        qDebug()<<"db1--->"<<"ID="<<query1.value(0).toInt()<<",NAME="<<query1.value(1).toString()<<",AGE="<<query1.value(2).toInt();
    }

    //------------------db2---------------------------

    QSqlQuery query2(db2);
    ret = query2.exec("select * from info");
    if(!ret)
        qDebug()<<"执行命令失败,"<<query2.lastError().text();
    while (query2.next()) {
        qDebug()<<"db2-->"<<"ID="<<query2.value(0).toInt()<<",NAME="<<query2.value(1).toString()<<",AGE="<<query2.value(2).toInt();
    }

    db1.close();
    db2.close();


    return a.exec();
}
