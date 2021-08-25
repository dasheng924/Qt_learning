#include "mainwindow.h"

#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QSlider>
#include <QMessageBox>
#include <QDebug>
#include <QSpinBox>


int interval = 300;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //设置一个按钮，按钮按下，开始计数，再按下停止计数，还有一个重置按钮



    //按钮
    QPushButton * btn = new QPushButton(QIcon(":/image/(171).png"),"开始",this);
    btn->setFixedSize(80,30);
    btn->setIconSize(QSize(80,30));
    btn->move(60,50);

    //标签
    QLabel *label = new QLabel(this);
    label->setFixedSize(100,100);
    label->setText("显示数字");
    label->move(10,50);

    //滑块条
    QSlider * slider = new QSlider(this);
    slider->move(100,250);
    slider->setMinimum(0);
    slider->setMaximum(10);
    slider->setOrientation(Qt::Horizontal);  // 水平方向
    slider->setSingleStep(1);  // 步长

    //微调框
    QSpinBox * spinbox = new QSpinBox(this);
    spinbox->move(100,200);
    spinbox->setFixedSize(80,30);
    spinbox->setMinimum(0);
    spinbox->setMaximum(10);
    spinbox->setSingleStep(1);




    //定时器
    QTimer * timer = new QTimer(this);
    //timer->setTimerType(Qt::PreciseTimer);

/*
参数:
    - Qt::PreciseTimer -> 精确的精度, 毫秒级
    - Qt::CoarseTimer  -> 粗糙的精度, 和1毫秒的误差在5%的范围内, 默认精度
    - Qt::VeryCoarseTimer -> 非常粗糙的精度, 精度在1秒左右
*/
    int num = 0;
    QString numm;
    bool isOK = true;//是否按下

    //滑块和微调框关联
    connect(spinbox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    connect(slider,SIGNAL(valueChanged(int)),spinbox,SLOT(setValue(int)));


    //滑块滑动，改变数字变化的速度
    connect(slider,&QSlider::valueChanged,this,[=]()mutable{
        interval = 300;
        //qDebug()<<slider->value();
        interval -= slider->value() * 25;
        //qDebug()<<interval;
        //QMessageBox::information(this,"info",QString::number(interval));
        timer->start(interval);
    });

    //滑块和按钮的关联变化
    connect(slider,&QSlider::sliderMoved,this,[=]()mutable{
        if(isOK){
            qDebug()<<QString::number(interval);
            btn->setText("停止");
            isOK = false;
        }
    });

     //定时器的变化，改变num值
    connect(timer,&QTimer::timeout,this,[=]()mutable{
        numm.setNum(num);
        label->setText(numm);
        num++;
    });


    //按钮控制定时器的执行和停止
    connect(btn,&QPushButton::clicked,this,[=]()mutable{
        if(isOK){
            qDebug()<<QString::number(interval);
            btn->setText("停止");
            isOK = false;
            timer->start(interval);
        }
        else{
            timer->stop();
            btn->setText("开始");
            isOK = true;
        }
    });



}

MainWindow::~MainWindow()
{
}

