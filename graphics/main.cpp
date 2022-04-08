#include "widget.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //新建场景
    QGraphicsScene scene ;
    //创建矩形图形项
    QGraphicsRectItem *item = new QGraphicsRectItem(0,0,100,100);

    scene.addItem(item);
    qDebug()<<scene.itemAt(50,50,QTransform());

    QGraphicsView view(&scene);

    view.setForegroundBrush(QColor(0,0,0,100));

    view.resize(400,300);
    view.show();

    return a.exec();
}
