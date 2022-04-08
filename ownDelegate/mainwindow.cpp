#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTableView>
#include <QStandardItemModel>

#include "spinboxdelegate.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel *model = new QStandardItemModel(5,6,this);
    for(int row = 0;row<5;++row)
    {
        for(int column = 0;column < 6;++column)
        {
            QStandardItem *item = new QStandardItem(QString("%1").arg(row*4+column));
            model->setItem(row,column,item);
        }
    }

    tableView = new QTableView(this);
    tableView->setModel(model);
    setCentralWidget(tableView);
    resize(700,300);
    setWindowTitle("TableView1");

    spinBoxDelegate *spinDelegate = new spinBoxDelegate(this);
    tableView->setItemDelegate(spinDelegate);




}

MainWindow::~MainWindow()
{
    delete ui;
}

