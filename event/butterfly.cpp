#include "butterfly.h"

#include <QPainter>
#include <QDebug>
#include <QDesktopWidget> //获取屏幕对象，QApplication::desktop()
#include <QApplication>
#include <QMenu>
#include <QAction>




ButterFly::ButterFly(QWidget *parent) : QWidget(parent)
{
    //加载图片
    m_p.load(":/1.jpeg");
    setFixedSize(m_p.size());

    startTimer(200); //100ms 触发一次定时器事件

}

void ButterFly::fly()
{
    if(index >= 2)
    {
        index =1;
    }
    else{
        index++;
    }

    QString str = QString(":/%1.jpeg").arg(index);
    m_p.load(str);

    int stepX = rand()%20+11;
    int stepY = rand()%20+11;

    int curX = this->geometry().topLeft().x() + stepX;
    int curY = this->geometry().topLeft().y()+stepY;

    QDesktopWidget * desk = QApplication::desktop(); //获得屏幕的对象
    if(curX > desk->screenGeometry().right() ) //right() 屏幕最右边的边
    {
        curX = desk->screenGeometry().left();
    }
    if(curY > desk->screenGeometry().bottom())
    {
        curY = desk->screenGeometry().top();
    }

    move(curX,curY);
}

void ButterFly::fly(int min,int max)
{
    if(index >= 2)
    {
        index =1;
    }
    else{
        index++;
    }

    QString str = QString(":/%1.jpeg").arg(index);
    m_p.load(str);

    int stepX = rand()%min+max;

    int stepY = rand()%min+max;

    int curX = this->geometry().topLeft().x() + stepX;
    int curY = this->geometry().topLeft().y()+stepY;

    QDesktopWidget * desk = QApplication::desktop(); //获得屏幕的对象
    if(curX > desk->screenGeometry().right() ) //right() 屏幕最右边的边
    {
        curX = desk->screenGeometry().left();
    }
    if(curY > desk->screenGeometry().bottom())
    {
        curY = desk->screenGeometry().top();
    }

    move(curX,curY);

}


void ButterFly::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(rect(),m_p);

}

void ButterFly::timerEvent(QTimerEvent *event) //切换图片，并绘制图片，刷新窗口
{
    fly();
    update(); //调用重绘事件函数
}

void ButterFly::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //这个算出鼠标和蝴蝶父窗口左上角之间的距离（全局坐标）
        //点击鼠标之后，这一次的这个距离是固定的
        m_pos = event->globalPos() - this->geometry().topLeft();

//        qDebug()<<"m_pos = "<<m_pos;
//        qDebug()<<"globalPos="<<event->globalPos();

//        //------------
//        //这个表示和父窗口左上角的距离
//        qDebug()<<this->x()<<" "<<this->y();
//        qDebug()<<"geometry.topLeft()="<<this->geometry().topLeft();

//        //-------------
//        //点击鼠标的位置相对于父窗口的位置
//        qDebug()<<"localPos="<<event->localPos();
//        qDebug()<<"pos="<<event->pos();
//        qDebug()<<"x= "<<event->x()<<"\ty= "<<event->y();
//        //-------------


//        qDebug()<<"screenPos="<<event->screenPos();

    }
    else if(event->button() == Qt::RightButton)
    {
        QMenu menu;
        QAction * action = menu.addAction("关闭");


        connect(action,&QAction::triggered,this,[=](){
            this->parentWidget()->close();
        }) ;

        menu.exec(QCursor::pos()); //关键的步骤
    }


}

void ButterFly::mouseMoveEvent(QMouseEvent *event)
{
//    if(event->button() & Qt::LeftButton) //鼠标左键参与了
//    {
//        move(event->pos() - m_pos);
//    }
    move(event->globalPos() - m_pos);

}

void ButterFly::enterEvent(QEvent *event)
{
z
    fly(-200,200);

}
