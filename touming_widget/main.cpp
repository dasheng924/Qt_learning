#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowFlag(Qt::FramelessWindowHint) ; //去掉标题栏
    w.setAttribute(Qt::WA_TranslucentBackground) ;//设置背景透明
    //w.setStyleSheet("backgroup-image:uri(:/image/(127).png),background-repeat:no-repeat;");



    w.show();
    return a.exec();
}
