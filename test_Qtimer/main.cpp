#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/image/(127).png"));
    MainWindow w;
    //w.setFixedSize(300,300);
    //w.move(300,300);
    w.setWindowTitle("测试QTimer");
    w.show();
    return a.exec();
    return 0;
}
