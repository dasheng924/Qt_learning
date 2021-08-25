#include "widget.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("自定义小控件");
    w.show();
    a.setWindowIcon(QIcon(":/(53).png"));
    return a.exec();
}
