#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QApplication>
#include <QContextMenuEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //方法一：实现鼠标右键
    //void mousePressEvent(QMouseEvent *event) override;

    //方法二：实现鼠标右键
     void contextMenuEvent(QContextMenuEvent *event) override;
    //QApplication::setOverrideCursor(Qt::WhatsThisCursor);
    //QApplication::restoreOverrideCursor();
    //setCursor(Qt::ForbiddenCursor) ;//取消之前使用setOverrideCursor()设置的光标

     void way_3();
     void way_4();
};
#endif // WIDGET_H
