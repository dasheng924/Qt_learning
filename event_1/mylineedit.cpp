#include "mylineedit.h"
#include <QDebug>


MyLineEdit::MyLineEdit(QWidget *parent):QLineEdit(parent)
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
//    Q_UNUSED(event)
    qDebug()<<"MyLineEdit 按下了键盘";
    QLineEdit::keyPressEvent(event);
    event->ignore();
}

bool MyLineEdit::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        qDebug()<<"event myLineEdit 按下了键盘";
    }
    return QLineEdit::event(event);
}
