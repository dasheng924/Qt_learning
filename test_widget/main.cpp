#include "widget.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(500,500);
    QRect size = w.frameGeometry();//这个包括边框
    qDebug()<<size.topLeft()<<"\t"<<size.bottomRight();
    qDebug()<<"width = "<<size.width()<<"heigth = "<<size.height();

    QRect ssize = w.geometry();
    qDebug()<<ssize.topLeft()<<"\t"<<ssize.bottomRight();
    qDebug()<<"width = "<<ssize.width()<<"heigth = "<<ssize.height();

    w.setWindowTitle("Widget");



    w.show();
    return a.exec();
}
