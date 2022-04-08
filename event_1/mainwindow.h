#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mylineedit.h"
#include <QKeyEvent>
#include <QEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    void keyPressEvent(QKeyEvent *event) override;
public:
    bool eventFilter(QObject *obj,QEvent *event) override ;

private:
    Ui::MainWindow *ui;
    MyLineEdit *lineEdit;
};
#endif // MAINWINDOW_H
