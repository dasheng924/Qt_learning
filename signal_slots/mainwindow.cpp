#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) //初始化列表，先初始化父类，调用父类的构造函数；再构造子类
    : QMainWindow(parent)
{
    closeBtn = new QPushButton(QIcon(":/new/prefix1/image/(127).png"),"close",this) ;
    closeBtn->setFixedSize(60,20);
    closeBtn->setStyleSheet("background:yellow") ;
    closeBtn->move(300,300);
    connect(closeBtn,&QPushButton::clicked,[=](){
        this->close();
    });


    showBtn_mianWindow2 = new QPushButton(tr("显示第二个窗口"),this);
    showBtn_mianWindow2->move(100,200);

    //w2.setParent(this);
    QObject::connect(showBtn_mianWindow2,&QPushButton::clicked,[=](){

        w2.show();

    });
}

MainWindow::~MainWindow()
{
}

//鼠标按压获取鼠标位置
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();//globalPos()-->鼠标偏离电脑屏幕左上角（x=0,y=0）的位置；
    //pos() 获取widget窗口距离（0,0)的位置
    //子窗口的位置属性：setGeometry(QRect(x,y,w,h))


}

//鼠标移动
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    //获取两次鼠标移动的差值
    int dx = e->globalX() - last.x() ;
    int dy = e->globalY() - last.y() ;

    last = e->globalPos();
    this->move(last.x()+dx,last.y()+dy) ;
    qDebug()<<"x = "<<e->globalX()<<"\ty = "<<e->globalY();

}

//鼠标释放
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    //获取两次鼠标移动的差值
    int dx = e->globalX() - last.x() ;
    int dy = e->globalY() - last.y() ;

    last = e->globalPos();
    move(last.x()+dx,last.y()+dy) ;

}


