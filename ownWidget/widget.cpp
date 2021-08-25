#include "widget.h"
#include "ui_widget.h"
#include "smallwidget.h"

#include <QGridLayout>
#include <QKeyEvent>
#include <QDebug>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QGridLayout * glayout = new QGridLayout(this);
//    SmallWidget * smallWidget = new SmallWidget(this);
//    glayout->addWidget(smallWidget);
//    this->setLayout(glayout);
      installEventFilter(this);
      //事件过滤器和被安装过滤器的组件必须在同一线程，否则，过滤器将不起作用。
      //另外，如果在安装过滤器之后，这两个组件到了不同的线程，那么，只有等到二者重新回到同一线程的时候过滤器才会有效。








}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{

    QString str;
    str.sprintf("<center><h1>Release: (%d, %d)</h1></center>",event->x(),event->y());
    this->setMouseTracking(true);//按下鼠标一次，其余的时候都可以追踪
    this->setWindowTitle(str);
}

bool Widget::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);//转化为键盘事件
        if(keyEvent->key() == Qt::Key_Tab)
        {
            qDebug()<<"你按下了Tab键"                    ;
        }
        return true;//事件已被处理返回true
    }
    return QWidget::event(event);//调用父类的event()函数继续转发，否则这个组件就只能处理我们定义的事件了
}

bool Widget::eventFilter(QObject *watch, QEvent *event)
{
    if(watch == this && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key() == Qt::Key_Tab)
        {
            qDebug()<<"eventFilter key_tab";
            return  true;//过滤掉了键盘按压事件
        }
        else{
            return false;
        }
    }
    return false;
}
