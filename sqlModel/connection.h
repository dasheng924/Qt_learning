#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QVariantList>
#include <QFile>
#include <QDebug>


bool connect()
{
    QFile file("/Users/sunguosheng/Downloads/model.db");
    bool ret = file.remove();
    if(ret)
        qDebug()<<"原始文件已经清除";


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/sunguosheng/Downloads/model.db");



    if(!db.open())
    {
        QMessageBox::critical(nullptr,"open dataBase",QString("%1").arg(db.lastError().text()),QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;


    //---------------------------创建student表----------------------------------------
    query.exec("create table student(id int primary key,name varchar(20),course int)");


    query.prepare("insert into student values(?,?,?)");
    QVariantList ids,names,courses;
    ids<<0<<1<<2<<3;
    names<<"高明"<<"张贺"<<"刘欢"<<"杨样";
    courses<<11<<11<<12<<13;

    query.addBindValue(ids);
    query.addBindValue(names);
    query.addBindValue(courses);

    if(!query.execBatch())
    {
        QMessageBox::critical(nullptr,"execBatch error",QString("%1").arg(query.lastError().text()),QMessageBox::Cancel);
        return false;
    }

    //---------------------------创建course表----------------------------------------
    query.exec("create table course(id int primary key,name varchar(20),techar varchar(20))");


    query.prepare("insert into course values(?,?,?)");
    QVariantList idds,namees,teachers;
    idds<<10<<11<<12<<13;
    namees<<"数学"<<"英语"<<"政治"<<"物理";
    teachers<<"张老师"<<"刘老师"<<"王老师"<<"秦老师";

    query.addBindValue(idds);
    query.addBindValue(namees);
    query.addBindValue(teachers);

    if(!query.execBatch())
    {
        QMessageBox::critical(nullptr,"execBatch error",QString("%1").arg(query.lastError().text()),QMessageBox::Cancel);
        return false;
    }

    return true;
}









#endif // CONNECTION_H
