#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QDebug>
#include <QDir>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlField>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/sunguosheng/Downloads/test_record.db");

    if(!db.open())
    {
        QMessageBox::critical(this,"open dataBase",QString("%1").arg(db.lastError().text()),QMessageBox::Cancel);
        return ;
    }

    QSqlQuery query(db);
    query.exec("insert into student values(0,'sungs',26)");
    query.exec("insert into student values(1,'alex',25)");
    query.exec("insert into student values(2,'lucy',20)");
    query.exec("insert into student values(3,'apir',21)");
    query.exec("insert into student values(4,'grass',10)");
    query.exec("insert into student values(5,'lubu',99)");

    //-------------------名称绑定----------------
    query.prepare("insert into student values(:id,:name,:age)");
    int p_id = 6;
    QString p_name = "alex";
    int p_age = 33;
    query.bindValue(":id",p_id);
    query.bindValue(":name",p_name);
    query.bindValue(":age",p_age);
    query.exec();

    //-------------------位置绑定-----------------
    query.prepare("insert into student values(?,?,?)");
    int idd = 7;
    QString namee = "glass";
    int agee = 99;

    query.addBindValue(idd);
    query.addBindValue(namee);
    query.addBindValue(agee);
    query.exec();
    //-----------------批处理----------------------
    QVariantList ids,names,ages;
    ids<<8<<9<<10;
    names<<"good"<<"food"<<"cool";
    ages<<55<<63<<10;

    query.prepare("insert into student values(?,?,?) ");
    query.addBindValue(ids);
    query.addBindValue(names);
    query.addBindValue(ages);
    query.execBatch();
    //------------------事务---------------------------
    //先检测当前的驱动是否支持事务
    if(!db.driver()->hasFeature(QSqlDriver::Transactions))
    {
        qDebug()<<"Transaction error!";
    }
    qDebug()<<"Transactions Feature ok!";
    qDebug()<<"----------->begin transactions";

    //开启事务
    db.transaction();

    bool ret = query.exec("select * from student where name = 'AAA" );
    if(!ret)
    {
        //说明不存在这个name
        ret = query.exec("insert into student(name,age) values(11,'AAA',999)" );
        if(!ret)//插入失败就回滚到初始状态
        {
            db.rollback();
            qDebug()<<"ready to rollback";
        }
        else //插入成功就提交
        {
            db.commit();
            qDebug()<<"----------->deal transactions over";
        }
    }
    //-------------------------------------------------

    query.exec("select * from student");

    while (query.next()) {
        qDebug()<<query.value(0).toInt()<<" "<<query.value(1).toString()<<" "<<query.value(2).toInt();
    }



    int rowNum = 0;
    //判断数据库驱动是否支持size()获取结果集的总行数
    if(db.driver()->hasFeature(QSqlDriver::QuerySize))
    {
        qDebug()<<"size feature ok!";
        rowNum = query.size();
    }
    else
    {
        qDebug()<<"size feature error !";
        query.last(); //最后一条结果集
        rowNum = query.at()+1; //最后一条结果集的索引+1
    }

    qDebug()<<"row num = "<<rowNum;

    //指向第二条记录
    query.seek(1);
    //返回当前的索引
    qDebug()<<"current index:"<<query.at();
    //获取当前行的记录
    QSqlRecord record = query.record();
    //根据这条记录,取出对应的值
    int id = record.value("id").toInt();
    QString name = record.value("name").toString();
    int age = record.value("age").toInt();

    qDebug()<<"id = "<<id<<",name="<<name<<",age="<<age;


    //对上面的那条记录获取索引为1的字段值,也就是name
    QSqlField field = record.field(1);
    //输出字段名称和字段值
    qDebug()<<"field name="<<field.name()<<",field value="<<field.value().toString();



    QString dbname;
    {
       dbname  = db.databaseName();
       qDebug()<<dbname;
    }
    db.close();
    db.removeDatabase(dbname);

}

MainWindow::~MainWindow()
{
    delete ui;
}

