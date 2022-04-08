#include <QObject>
#include <QPushButton>
#include <QAbstractButton>
#include <QApplication>
#include <QDebug>
#include <QTimer>

int main(int argc,char *argv[])
{
    QApplication a(argc,argv);

    QObject *obj = new QPushButton;
    const char * name = obj->metaObject()->className();
    qDebug()<<name;

    int count = obj->metaObject()->classInfoCount();
    qDebug()<<count;


    QTimer *timer = new QTimer;
    qDebug()<<timer->inherits("QTimer");
    qDebug()<<timer->inherits("QObject");
    qDebug()<<timer->inherits("QAbstrctButton");



    Q_CLASSINFO("author","Sungs");
    Q_CLASSINFO("compay","OWN");
    Q_CLASSINFO("version","3.0.1");









    return a.exec() ;
}
