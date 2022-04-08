#include "mainwindow.h"
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QLabel *label  = new QLabel(this);
    label->setText(tr("hello world"));
    label->show();


}

MainWindow::~MainWindow()
{
}

