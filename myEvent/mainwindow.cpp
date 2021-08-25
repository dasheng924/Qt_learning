#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mylabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyLabel * mylabel = new MyLabel(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

