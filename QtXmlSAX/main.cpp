#include <QApplication>
#include "mysax.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MySAX sax;
    sax.readFile("/Users/sunguosheng/Downloads/QtXml.xml");

    return a.exec();
}
