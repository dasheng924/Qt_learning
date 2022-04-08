#ifndef CONNECT_H
#define CONNECT_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>


bool createConnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//参数2指定数据库连接名,这里使用默认的数据库连接名
    db.setDatabaseName("memory.db");//sqlite3 的内存数据库,应用程序关闭,数据库自动销毁

    if(!db.open()) //打开失败
    {
        QMessageBox::critical(nullptr,"Connect open dataBase",QString("%1").arg(db.lastError().text()),QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;
    query.exec("create table student( "
               "id int primary key,"
               "name varchar(20) )" );
    query.exec("insert into student values(0,'LiMing')");
    query.exec("insert into student values(1,'ZhangSan')");
    query.exec("insert into student values(2,'LiSi')");
    query.exec("insert into student values(0,'LiuFei')");

    return true;
}

bool createConnection2()
{
    //初始化数据库连接对象
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE","connect1");
    db1.setDatabaseName("/Users/sunguosheng/NewQt/qtSql/test1.db");

    if(!db1.open())
    {
        //打开数据库失败
        QMessageBox::critical(nullptr,"open dataBase db1 fail!",QString("%1").arg(db1.lastError().text()),QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query1(db1);
    bool ret = query1.exec("create table info(id int primary key,name varchar(20),age int) ");

    if(ret)
        query1.exec("insert into info values(0,'sungs',26)");


//    //--------------------db1的连接创建了一个数据库,并且创建了一张表,往表里插入了一条数据


    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","connect2");
    db2.setDatabaseName("/Users/sunguosheng/NewQt/qtSql/test2.db");

    if(!db2.open())
    {
        //打开数据库失败
        QMessageBox::critical(nullptr,"open dataBase db1 fail!",QString("%1").arg(db1.lastError().text()),QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query2(db2);
    ret = query2.exec("create table info(id int primary key,name varchar(20),age int) ");
    if(ret)
        query2.exec("insert into info values(0,'laoWang',33)");

    return true;
}


bool connectMySql()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("");


    return true;
}












#endif // CONNECT_H
