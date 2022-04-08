#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);





}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {
        if(event->key() == Qt::Key_M)
            setWindowState(Qt::WindowFullScreen);
        else
            QWidget::keyPressEvent(event);
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    qDebug()<<"键盘被释放了";
}

