#include "widget.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
//    //这样设置完，关闭窗口不会终止程序
//    w.setAttribute(Qt::WA_QuitOnClose,false);
    w.show();
    return a.exec();
}
