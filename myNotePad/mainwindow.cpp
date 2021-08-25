#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytext.h"

#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Mytext * mytext = new Mytext(this);
    mytext->resize(800,800);


}

MainWindow::~MainWindow()
{
    delete ui;
}

