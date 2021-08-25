#include "mylabel.h"

#include <QDebug>

#include <QMenu>
#include <QAction>


MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    this->setToolTip("okokok!");
    this->resize(800,800);
    this->setText("hello world");

     mm= new QMovie("://test.gif");

    this->setMovie(mm);
    mm->start();

}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug()<<"你按下了左键";
    }
    else if(event->button() == Qt::MidButton)
    {
        qDebug()<<"你按下了鼠标中键";
    }
    else if(event->button() ==Qt::RightButton){
        qDebug()<<"你按下了鼠标右键";
        QMenu *menu = new QMenu(this);
        QString flag = "stop";
        if(mm->state() == QMovie::Running)
            flag = "stop";
        else if(mm->state() == QMovie::NotRunning)
            flag = "start";
        QAction * action_close = new QAction(flag);
        menu->addAction(action_close);
        connect(action_close,&QAction::triggered,this,[=](){
            if(mm->state() == QMovie::Running)
                mm->stop();
            else if(mm->state() == QMovie::NotRunning)
                mm->start();
        });
        menu->exec(QCursor::pos());
    }
}
