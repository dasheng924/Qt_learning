#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include <QWidget>
#include "mainwindow2.h"

class MainWindow : public QMainWindow //继承自QMainWindow,
{
    Q_OBJECT //meta_object 该宏的提供支持MOC，这样才可以使用信号与槽，对象树等一系列特性，访问权限为priva

public:
    MainWindow(QWidget *parent = nullptr); //构造函数
    ~MainWindow();
protected:
    //鼠标按下
    void mousePressEvent(QMouseEvent *e);

    //鼠标移动
    void mouseMoveEvent(QMouseEvent *e);

    //鼠标释放
    void mouseReleaseEvent(QMouseEvent *e) ;
private:
    QPushButton *closeBtn;
    QPoint last;
    QPushButton *showBtn_mianWindow2;
    MainWindow2 w2;
};
#endif // MAINWINDOW_H
