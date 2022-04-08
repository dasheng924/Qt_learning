#include "widget.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    Dialog d;
    if(d.exec() == QDialog::Accepted)
    {
        Widget w;
        w.show();
        return a.exec();
    }
    else {
        return 0;
    }

    //return a.exec();
}
