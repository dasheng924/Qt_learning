#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    QDialog w;

    QLabel label(&w);
    label.setText(QObject::tr("hello"));


    w.show();


    return a.exec();
}


