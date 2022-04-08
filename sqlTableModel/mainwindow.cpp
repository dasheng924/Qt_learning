#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRelationalTableModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new CustomSqlTableModel(this);
    model->setTable("student");
    model->select();

    //设置编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);//所有的改变放到缓存,最后调用submitAll() 进行一次性提交

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列自适应
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//行自适应
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:skyblue}");
    ui->tableView->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:skyblue}");

    ui->tableView->setModel(model);

    //提交修改
    connect(ui->commitBtn,&QPushButton::clicked,this,[=](){
        //开始事务
        model->database().transaction();

        if(model->submitAll())
        {
            //可以一次性提交成功
            if(model->database().commit())
            {
                QMessageBox::information(this,"SqlTableModel","数据提交成功!");
            }
        }
        else
        {
            //没有提交成功
            model->database().rollback();//回滚
            QMessageBox::critical(this,"SqlTableModel","提交数据失败,已经回退!");
        }
    });

    //撤销
    connect(ui->revertBtn,&QPushButton::clicked,this,[=](){
        model->revertAll();
    });


    //添加记录
    connect(ui->addRowBtn,&QPushButton::clicked,this,[=](){
       //获得表的行数
       int rowNum = model->rowCount();
       int lastId = model->index(rowNum-1,0).data(Qt::DisplayRole).toInt();
       //添加一行
       model->insertRow(rowNum);
       model->setData(model->index(rowNum,0),++lastId);
       model->submitAll();
    });

    //删除记录
    connect(ui->remmoveRowBtn,&QPushButton::clicked,this,[=](){
        //获取当前行
        int row = ui->tableView->currentIndex().row();
        model->removeRow(row);
        int ok = QMessageBox::question(this,"删除当前行","你确定删除当前行吗?",QMessageBox::Yes,QMessageBox::No);
        if(ok == QMessageBox::No)
            model->revertAll();
        else
            model->submitAll();
    });

    //按照ID升序
    connect(ui->ascendingOrderBtn,&QPushButton::clicked,this,[=](){
        model->sort(0,Qt::AscendingOrder);
        model->select();
    });

    //按照ID降序
    connect(ui->descendingOrderBtn,&QPushButton::clicked,this,[=](){
        model->sort(0,Qt::DescendingOrder);
        model->select();
    });

    connect(ui->selectBtn,&QPushButton::clicked,this,[=](){
        QString name = ui->lineEdit->text();
        model->setFilter(QString("name = '%1'").arg(name));
        model->select();
    });

    connect(ui->showAllBtn,&QPushButton::clicked,this,[=](){
        flushTableView();
    });



    QWidget *widget = new QWidget;
    widget->resize(600,500);
    widget->setWindowTitle("RelationalTable");
    widget->move(800,800);


    QGridLayout *glayout2 = new QGridLayout;
    QGridLayout *topLayout = new QGridLayout;
    QGridLayout *bottomLayout = new QGridLayout;
    glayout2->addLayout(topLayout,0,0,Qt::AlignCenter);
    glayout2->addLayout(bottomLayout,1,0,Qt::AlignCenter);

    widget->setLayout(glayout2);

    QSqlRelationalTableModel *relationModel = new QSqlRelationalTableModel(widget);
    relationModel->setTable("student");
    //studen表的第二列字段course关联到表course表的id字段,给用户展现的是course表的name信息
    //2 student中标号为2的列
    relationModel->setRelation(2,QSqlRelation("course","id","name"));
    relationModel->select();
    QTableView *vieww = new QTableView(widget);
    vieww->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列自适应
    vieww->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//行自适应
    topLayout->addWidget(vieww);
    vieww->setModel(relationModel);


    QSqlTableModel *tableModel = new QSqlTableModel(widget);
    tableModel->setTable("course");
    tableModel->select();
    QTableView *view2 = new QTableView(widget);
    view2->setModel(tableModel);
    view2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列自适应
    view2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//行自适应
    bottomLayout->addWidget(view2);


    connect(ui->otherBtn,&QPushButton::clicked,this,[=](){
        widget->show();
    });

    connect(widget,&QWidget::destroyed,this,[=](){
        widget->deleteLater();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::flushTableView()
{
    model->setTable("student");
    model->select();
}

