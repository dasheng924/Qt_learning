#include "widget.h"

#include <QPushButton>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //所有窗口和控件的基类
    //可以单独显示，不内嵌，也可以内嵌显示（指定不指定父对象的问题）
//    QWidget * w2 = new QWidget;
    QWidget * w3 = new QWidget(this);
    w3->setStyleSheet("background:red");

//    w2->show();
    w3->show();
    //w3->setEnabled(false);// 是否可用
    //w3->setDisabled(false);// 是否可用
    //w3->setVisible(false);//是否可见


    QWidget * obj = w3->parentWidget();
    this->setObjectName(QStringLiteral("MyWidget"));
    qDebug()<<obj->objectName();



    // 给窗口设置策略: Qt::DefaultContextMenu
    // 在窗口中按下鼠标右键, 这个事件处理器函数被qt框架调用 QWidget::contextMenuEvent()
    //方法2
    //setContextMenuPolicy(Qt::DefaultContextMenu);


    //方法3:
    //way_3();














}

Widget::~Widget()
{
}

void Widget::way_3()
{
    //macos not can
    setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction* act1  = new QAction("C++");
    QAction* act2 = new QAction("Java");
    QAction* act3  = new QAction("Python");

    this->addAction(act1);
    this->addAction(act2);
    this->addAction(act3);

    connect(act1,&QAction::triggered,this,[=](){

        QMessageBox::information(this,"info","C++");
    });
}

/*
 * 方法1:
void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        QMenu menu;
        QAction * action1 = menu.addAction("C++");
        connect(action1,&QAction::triggered,this,[=](){
            QMessageBox::information(this,"info","你选中了C++");
        });

        QAction * action2 =menu.addAction("java");
        connect(action2,&QAction::triggered,this,[=](){
            QMessageBox::information(this,"info","你选中了java");
        });
        QAction * action3 =menu.addAction("Python");
        qDebug()<<action3->text();
        connect(action3,&QAction::triggered,this,[=](){
            QMessageBox::information(this,"info","你选中了Python");
        });
        menu.exec(QCursor::pos());// 右键菜单被模态显示出来了
        //QCursor::pos() 光标在屏幕中的位置

    }
}
*/

#if 0
//方法2
void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    // 弹出一个菜单, 菜单项是 QAction 类型
    QMenu menu;
    QAction* act = menu.addAction(QIcon(":/image/(131).png"),"C++");
    connect(act, &QAction::triggered, this, [=]()
    {
        QMessageBox::information(this, "title", "您选择的是C++...");
    });
    menu.addAction(QIcon(":/image/(133).png"),"Java");

    menu.addAction(QIcon(":/image/(131).png"),"Python");
    menu.exec(QCursor::pos());	// 右键菜单被模态显示出来了
}

#endif



