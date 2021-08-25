#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "paintedwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PaintedWidget * pW = new PaintedWidget(this);
    pW->show();



}

MainWindow::~MainWindow()
{
    delete ui;
}

