#include "mainwindow.h"


#include <QRect>
#include <QPoint>
#include <QLine>
#include <QSize>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //直接验证矩形
    QRect r1(QPoint(10,20),QPoint(80,90));
    QRect r2(QPoint(30,20),QSize(30,50));
    QRect r3(10,20,30,40);
    QRect r4(QRect(20,30,40,50));

    qDebug()<<"左上角"<<r1.topLeft()<<"右上角"<<r1.topRight()<<"左下角"<<r1.bottomLeft()<<"右下角"<<r1.bottomRight();
    qDebug()<<"中心点坐标"<<r1.center();
    qDebug()<<"上"<<r1.y()<<"下"<<r1.bottom()<<"左"<<r1.left()<<"右"<<r1.right();
    qDebug()<<"高度"<<r1.height()<<"宽度"<<r1.width();
    qDebug()<<"尺寸"<<r1.size();



}

MainWindow::~MainWindow()
{
}

