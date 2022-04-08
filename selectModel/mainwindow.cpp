#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QTableView>
#include <QDebug>
#include <QGridLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel *model = new QStandardItemModel(7,4,this); //7行,4列,父级为this
    for(int i = 0;i<model->rowCount();++i)
    {
        for(int j = 0;j<model->columnCount();++j)
        {
            QStandardItem *item = new QStandardItem(QString("%1").arg(i*4+j));
            model->setItem(i,j,item);//给模型中的每个项目进行赋值
        }
    }


    QGridLayout *gLayout = new QGridLayout;

    tableView  = new QTableView;
    tableView->setModel(model);

    gLayout->addWidget(tableView);
    centralWidget()->setLayout(gLayout);

    setWindowTitle("TableView1");
    resize(400,300);

    //获取视图的选择模型
    QItemSelectionModel *selectionModel = tableView->selectionModel();
    //定义左上角和右下角的索引,根据这两个索引创建选择
    QModelIndex topLeft;
    QModelIndex bottomRight;
    topLeft = model->index(1,1,QModelIndex());
    bottomRight = model->index(5,2,QModelIndex());
    QItemSelection select(topLeft,bottomRight);
    //使用指定的选择模式来选择项目
    selectionModel->select(select,QItemSelectionModel::Select);//表明所有指定的索引都将被选择


    QMenu * menu = ui->menubar->addMenu("选择模型");
    QAction *currentItem = menu->addAction("获取当前项目");
    QAction *toggleItem = menu->addAction("切换选择");
    QAction *allItem = menu->addAction("全部选择");
    QAction *rowItem = menu->addAction("行选择");
    QAction *columnItem = menu->addAction("列选择");
    connect(currentItem,&QAction::triggered,this,&MainWindow::getCurrentItemData);
    connect(toggleItem,&QAction::triggered,this,&MainWindow::toggleSelection);
    connect(allItem,&QAction::triggered,this,[=](){
        tableView->selectAll();
    });

    connect(rowItem,&QAction::triggered,this,[=](){

        int row = tableView->selectionModel()->currentIndex().row();
        tableView->selectRow(row);
    });

    connect(columnItem,&QAction::triggered,this,[=](){
        int column = tableView->selectionModel()->currentIndex().column();
        tableView->selectColumn(column);
    });


    //选择的项目改变时会发出信号,包含新选择的项目和先前选择的项目deselected
    connect(selectionModel,&QItemSelectionModel::selectionChanged,this,&MainWindow::updateSelection);
    //在当前项发生改变时发射,包含新的当前项的索引和先前当前项的索引
    connect(selectionModel,&QItemSelectionModel::currentChanged,this,&MainWindow::changeCurrent);

    tableView2 = new QTableView;
    tableView2->setWindowTitle("TableView2");
    tableView2->resize(400,300);
    tableView2->setModel(model);
    tableView2->setSelectionModel(selectionModel);
    tableView2->show();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete tableView2;

}

void MainWindow::getCurrentItemData()
{
    qDebug()<<"当前项目的内容:"<<tableView->selectionModel()->currentIndex().data().toString();
}

void MainWindow::toggleSelection()
{
    QModelIndex topLeft = tableView->model()->index(0,0,QModelIndex());
    QModelIndex bottomRight = tableView->model()->index(tableView->model()->rowCount(QModelIndex()) -1,
                                                        tableView->model()->columnCount(QModelIndex()) - 1,QModelIndex());

    QItemSelection select(topLeft,bottomRight);
    tableView->selectionModel()->select(select,QItemSelectionModel::Toggle);
}

void MainWindow::updateSelection(const QItemSelection &selection, const QItemSelection &deselected)
{
    //获取当前选择模型中的模型索引列表
    QModelIndexList indexList = selection.indexes();

    //为现在选择的项目填充值
    QModelIndex index;
    foreach (index, indexList) {
        QString text = QString("%1,%2").arg(index.row()).arg(index.column());
        tableView->model()->setData(index,text);
    }
    //清空上一次选择的项目内容
    indexList = deselected.indexes();
    foreach (index, indexList) {
        tableView->model()->setData(index,"");
    }
}

void MainWindow::changeCurrent(const QModelIndex &current, const QModelIndex &previous)
{
    qDebug()<<tr("move(%1,%2) to (%3,%4)").arg(previous.row()).arg(previous.column()).arg(current.row()).arg(current.column());
}

