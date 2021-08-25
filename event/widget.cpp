#include "widget.h"
#include "ui_widget.h"
#include "butterfly.h"

#include <QMessageBox>
#include <QDebug>
#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    connect(ui->myButton,&MyButton::clicked,[=](){
//        QMessageBox::information(this,"提示","你点击了我自定义的按钮！");
//    });




    //去边框
    setWindowFlags( windowFlags()| Qt::FramelessWindowHint);
    //窗口透明
    setAttribute(Qt::WA_TranslucentBackground);
    //最大化
    showMaximized();
    for(int i = 0;i<100;++i)
    {
        ButterFly *b = new ButterFly(this);
        b->move((this->width() - b->width())/2*(i+1),(this->height() - b->height())/2*(i+1) ) ;
        b->show();
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<event->globalPos();
}

void Widget::keyPressEvent(QKeyEvent *event)//获取到按下的键
{
    QString key = event->text();
    qDebug()<<key;
}



void Widget::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this,"问题","是否要关闭窗口?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if(ret == QMessageBox::Yes)
    {
        event->accept();
    }
    else{
        event->ignore();
    }
}

