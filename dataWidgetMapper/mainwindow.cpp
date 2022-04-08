#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDataWidgetMapper>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStandardItemModel *modle = new QStandardItemModel(3,2,this);

    modle->setItem(0,0,new QStandardItem("xiaoMing"));
    modle->setItem(0,1,new QStandardItem("23"));

    modle->setItem(1,0,new QStandardItem("liuMing"));
    modle->setItem(1,1,new QStandardItem("34"));

    modle->setItem(2,0,new QStandardItem("daWang"));
    modle->setItem(2,1,new QStandardItem("54"));

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(modle);

    //设置窗口部件和modle列的映射
    mapper->addMapping(ui->name,0);
    mapper->addMapping(ui->age,1);

    mapper->toFirst();//默认显示的是第一项

    connect(ui->upBtn,&QPushButton::clicked,this,[=](){
        mapper->toPrevious(); //上一个
    });

    connect(ui->downBtn,&QPushButton::clicked,this,[=](){
        mapper->toNext();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

