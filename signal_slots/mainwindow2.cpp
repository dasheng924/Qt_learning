#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    this->setWindowTitle("我是第二个窗口");
//    this->setStyleSheet("background:blue");
//    this->setFixedSize(QSize(500,500));

    this->setWindowFlag(Qt::FramelessWindowHint);//去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground,true); //设置背景头透明

    //background-image:uri 添加图片
    //background-repeat：no-repeat 不平铺
    this->setStyleSheet("background-image:url(:/new/prefix1/image/(130).png),background-repeat:repeat;");




}

MainWindow2::~MainWindow2()
{
    delete ui;
}
