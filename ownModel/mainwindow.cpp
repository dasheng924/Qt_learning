#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "stringlistmodel.h"
#include <QListView>
#include <QTableView>

#include <QGridLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QGridLayout *gLayout = new QGridLayout;
    QVBoxLayout *vLayout1 = new QVBoxLayout;
    QVBoxLayout *vLayout2 = new QVBoxLayout;


    gLayout->addLayout(vLayout1,0,0);
    gLayout->addLayout(vLayout2,1,0);
    centralWidget()->setLayout(gLayout);





    QStringList stringList;
    stringList<<"aa"<<"bb"<<"cc"<<"dd";
    StringListModel *model = new StringListModel(stringList,this);


    QListView *listView = new QListView(this);
    listView->setModel(model);
    vLayout1->addWidget(listView);

    QTableView *tableView = new QTableView(this);
    tableView->setModel(model);
    vLayout2->addWidget(tableView);

    model->insertRows(2,1);
    model->removeRows(1,2);








}

MainWindow::~MainWindow()
{
    delete ui;
}

