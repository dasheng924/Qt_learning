#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QSortFilterProxyModel>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    centralWidget()->layout()->setContentsMargins(5,0,5,0);
    ui->widget->layout()->setContentsMargins(5,0,5,0);
    ui->widget_3->layout()->setContentsMargins(5,0,5,0);
    ui->groupBox->layout()->setContentsMargins(5,0,5,0);
    ui->pushButton->setText("过滤");

    QStringListModel *listModle = new QStringListModel(this);
    QStringList list;
    list<<"aaa"<<"bbb"<<"ccc";
    listModle->setStringList(list);

    proxyModle = new QSortFilterProxyModel(this);
    proxyModle->setSourceModel(listModle);//为代理模型设置源数据模型

    ui->listView->setModel(proxyModle);//为视图设置模型

    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        QString filters = ui->lineEdit->text();
        QRegExp exp(filters);
        proxyModle->setFilterRegExp(exp); //每当条件改变时都会自动更新视图
    });












}

MainWindow::~MainWindow()
{
    delete ui;
}

