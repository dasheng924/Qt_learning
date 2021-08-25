#include "mybutton.h"

#include <QPainter>

MyButton::MyButton(QWidget *parent) : QWidget(parent)
{


}

void MyButton::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    p.load(":/img/(136).png");
    update();
    this->resize(p.size());

    //如果还需要执行默认的动作，可以再执行一遍父类的虚函数
    //QWidget::enterEvent(event);
}

void MyButton::leaveEvent(QEvent *event)
{
     Q_UNUSED(event);
    p.load(":/img/(137).png");
    update();
    this->resize(p.size());
}

void MyButton::mousePressEvent(QMouseEvent *event)
{
     Q_UNUSED(event);
    p.load(":/img/(138).png");
    update();
    this->resize(p.size());

    emit clicked(); //发送自定义的信号，在MyWidget的构造函数里面，connect一下
}

void MyButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter pp(this);
    pp.drawPixmap(rect(),p);

}
