#include "mainwindow.h"

#include <QApplication>//应用程序类

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //一个程序只能有且只有一个QApplication 类及其子类
    MainWindow w; //窗口类对象

    //设置窗口的大小
//    w.setMaximumSize(600,600); //设置窗口最大尺寸
//    w.setMinimumSize(200,200);  //设置窗口最小尺寸
    w.setFixedSize(600,600);
    w.setWindowTitle("第一个窗口"); //设置窗口标题
    w.setStyleSheet("background:green") ; //设置背景颜色
    w.move(100,100); //移动窗口，相对位置为屏幕的左上角

    //w.setWindowFlag(Qt::FramelessWindowHint) ;//去掉标题栏
    //w.setWindowFlag(Qt::WindowCloseButtonHint) ; //添加关闭按钮
    w.setWindowFlag(Qt::WindowMinMaxButtonsHint);//添加最小 最大化按钮







    w.show(); //show（）函数，可以以模态的形式显示窗口


    a.setWindowIcon(QIcon(":/new/prefix1/image/(136).png")) ;
    return a.exec(); //进入主事件循环，捕捉事件，分发到对应的目标对象上，调用对应的事件处理函数
}
