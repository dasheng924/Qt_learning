#include "shapewidget.h"

#include <QPixmap>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QPaintEvent>
#include <QDesktopWidget>
#include <QtMath>
#include <qapplication.h>

ShapeWidget::ShapeWidget(QWidget *parent) : QWidget(parent)
{
    //新建一个QPixmap的对象
    QPixmap p;
    //加载图片
    p.load(":/(155).png");
    //将窗口大小固定为图片大小
    this->setFixedSize(p.size());
    //窗口去边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags() );
    //设置背景透明
    setAttribute(Qt::WA_TranslucentBackground);

    startTimer(100);

}

//设置鸭子移动的路径和模式
void ShapeWidget::goMove()
{
    double stepX = log2f(rand()%10+1);

    double stepY = log2(rand()%15+1);

    double curX = geometry().topLeft().x() + stepX;
    double curY = geometry().topLeft().y() + stepY;

    QDesktopWidget * dw = QApplication::desktop();
    if(curX > dw->screenGeometry().right())
    {
        curX = dw->screenGeometry().left();
    }

    if(curY > dw->screenGeometry().bottom())
    {
        curY = dw->screenGeometry().top();
    }

    move(curX,curY);
}

void ShapeWidget::mousePressEvent(QMouseEvent *event)
{
    //求出窗口移动执之前的位置
    if(event->button() == Qt::LeftButton)
    {
        //求出窗口移动执之前需要记录的位置
        m_pos = event->globalPos()-this->geometry().topLeft();
        qDebug()<<"鼠标左键:"<<m_pos;
    }
    if(event->button() == Qt::RightButton)
    {
        //关闭窗口
        this->close();
    }
}

void ShapeWidget::mouseMoveEvent(QMouseEvent *event)
{
//      update();
      this->move(event->globalPos()-m_pos);

}

void ShapeWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter pp(this);
    pp.drawPixmap(rect(),QPixmap("/Users/sunguosheng/Pictures/ttt.png"));
}

void ShapeWidget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    goMove();
    update();
}





