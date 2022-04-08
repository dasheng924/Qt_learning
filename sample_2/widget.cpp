#include "widget.h"
#include "dialog.h"


#include <QLabel>
#include <QDialog>
#include <QPushButton>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

# if 0
//下面的代码关于在堆上创建控件
//关于窗口的非模态显式和模态显示

//    QWidget *myWidget = new QWidget(0,Qt::Dialog/*|Qt::FramelessWindowHint*/) ;
//    QLabel *label  = new QLabel(0,Qt::SplashScreen/*|Qt::WindowStaysOnTopHint*/);
//    label->setText("hello");


////    qDebug("hello %s\n","sunguosheng");
//    myWidget->show();
//    label->show();

    //模态对话框和非模态对话框

    QDialog *dialog = new QDialog(this);
    //dialog->setModal(true);
    //dialog->setWindowModality(Qt::NonModal); //设置模态对话框要阻塞的窗口类型
    //Qt::NonModal //不阻塞任何窗口,相当于非阻塞
    //Qt::WindowModal //阻塞它的父窗口 所有祖先窗口和他们的子窗口
    //Qt::ApplicationModal //阻塞整个应用程序的所有窗口
    //setModal 的默认参数是Qt::ApplicationModal

    //也就是上面的 setModal() 和 setWindowModality() 的功能是相同的,可以给非模态窗口设置模态的属性,但是setWindowModality()更加的灵活

    dialog->show();

#endif




#if 1
//下面的代码,创建一个按钮,按钮,按下产生一个新的对话框

    QPushButton *btn = new QPushButton("OK",this);
    connect(btn,&QPushButton::clicked,this,&Widget::myShow);

    //加入一个按钮,可以返回上一个界面
    QPushButton *btn_bak = new QPushButton("返回上一个界面",this);
    btn_bak->move(100,200);
    connect(btn_bak,&QPushButton::clicked,this,[=](){

        close(); //先关闭主界面
        Dialog dd;
        if(dd.exec() == QDialog::Accepted) //dd.exec()  就会显示出来之前的界面
        {
            this->show();  //如果又按下了进入的按钮,就会进入主界面
        }
    });



#endif

}

Widget::~Widget()
{
}

void Widget::myShow()
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Win");
    dialog->setFixedSize(QSize(100,500));
    dialog->show();
}

