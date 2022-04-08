#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QGridLayout>
#include <QStandardItemModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("select * from student"); //参数二可以指定使用的数据库的连接
    model->setHeaderData(0,Qt::Horizontal,"序号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"课程");

    QTableView *view = new QTableView(this);

    QGridLayout *glayout = new QGridLayout;
    glayout->addWidget(view);
    centralWidget()->setLayout(glayout);

    view->setModel(model);
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列的宽度自适应
    view->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//行的宽度自适应
    view->horizontalHeader()->setStyleSheet("QHeaderView::section:pressed{background-color:blue}");
    view->setAlternatingRowColors(true);//间隔使用不同的颜色标识
    QFont font = view->font();
    font.setStyleStrategy(QFont::PreferAntialias);//字体抗锯齿
    view->setFont(font);
    view->show();


    //-------------------问题---------------------------
    //1.无法居中显示获取的结果集中的内容
    //2.需要对QSqlQueryModel进行重写data(),来进行自定义样式和居中




    //---------------------其他函数--------------
    qDebug()<<"记录条数"<<model->rowCount();
    qDebug()<<"字段个数"<<model->columnCount();


    qDebug()<<"第二条记录的信息如下:";
    QSqlRecord record = model->record(1);
    for (int i = 0;i<record.count();++i) {
        QSqlField field = record.field(i);
        switch (i) {
        case 1:
            qDebug()<<"字段名称:"<<field.name()<<",字段值:"<<field.value().toString();
            break;
        default:
            qDebug()<<"字段名称:"<<field.name()<<",字段值:"<<field.value().toInt();

        }
    }

    //获取模型对应的QSqlQuery对象
    QSqlQuery query = model->query();

    //清空结果集
    model->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

