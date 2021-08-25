#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //qDebug()<<QSqlDatabase::drivers();//支持的数据库驱动
    //("QSQLITE", "QMYSQL", "QMYSQL3", "QPSQL", "QPSQL7")
    test_modelSql();

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test_mysql()
{
    //添加mysql数据库
    //参数二用来区分多个数据库
    QSqlDatabase my_mysql = QSqlDatabase::addDatabase("QMYSQL","testdb");
    //连接数据库
    my_mysql.setHostName("127.0.0.1");
    my_mysql.setUserName("root");
    my_mysql.setPassword("dasheng5299");
    my_mysql.setDatabaseName("Qtmysql");
    if(!my_mysql.open())
    {
        QMessageBox::critical(this,"数据库连接失败！",my_mysql.lastError().text());
        return;
    }

    QSqlQuery query(my_mysql);
    query.exec("use Qtmysql;");
    query.exec("insert into student values(1,\"Lucy\",22);"); //一次性插入一个

    //query.exec("alter table student drop name");
    query.exec("alter table student add name varchar(255) not null default ' ' after id;");
    //批量插入
    query.prepare("insert into student (id,name,age) values(?,?,?);");

    QVariantList id;
    id<<7<<6<<5;
    query.addBindValue(id);

    QVariantList names;
    names<<"name1"<<"name2"<<"name3";
    query.addBindValue(names);

    QVariantList age;
    age<<33<<23<<19;
    query.addBindValue(age);

    if(!query.execBatch()) //批量的执行
    {
        QMessageBox::critical(this,"error",query.lastError().text());
    }

    query.exec("select * from student;");
    //如果存在查询结果，QSqlQuery::next()会返回 true，直到到达结果最末，返回 false，说明遍历结束
    while(query.next()) //遍历查询的结果，前提是要存在查询结果
    {
        qDebug()<<query.value(0);
        qDebug()<<query.value(1);
    }

}

void MainWindow::test_modelSql()
{
    //先创建一个数据库的对象
    QSqlDatabase db_mysql1 =  QSqlDatabase::addDatabase("QMYSQL","mysql1");
    //关联数据库
    db_mysql1.setHostName("127.0.0.1");
    db_mysql1.setUserName("root");
    db_mysql1.setPassword("dasheng5299");
    db_mysql1.setDatabaseName("Qtmysql");

    //打开数据库
    if(!db_mysql1.open())
    {
        QMessageBox::critical(this,"打开数据库错误",db_mysql1.lastError().text());
        return;
    }

    //开始操作数据库


    QSqlTableModel model(this,db_mysql1);//实例化模型
    model.setTable("student");
    model.setFilter("age>20 and name != ' '");

    if(model.select())
    {
        for(int i = 0;i<model.rowCount();++i)
        {
            QSqlRecord record = model.record(i);
            QString name = record.value("name").toString();
            int age = record.value("age").toInt();
            qDebug()<<name<<"    "<<age;
        }
    }

}
