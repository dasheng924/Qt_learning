#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "shapewidget.h"
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showFullScreen();

    ShapeWidget * sWidget = nullptr;
    QVector<ShapeWidget*> v;
    for(int i = 0;i<10;++i)
    {
        sWidget = new ShapeWidget(this);
        v.push_back(sWidget);
        sWidget->move(width()/20+i*100,height()/20+i*010);
        sWidget->show();
    }




}

MainWindow::~MainWindow()
{
    delete ui;
}

