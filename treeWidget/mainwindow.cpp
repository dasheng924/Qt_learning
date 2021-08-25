#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //树控件

    //设置表头
    ui->treeWidget->setHeaderLabels(QStringList()<<"Group"<<"Name"<<"Sex"<<"Score"<<
                                    "Excellent");

    //设置表头的背景颜色
    ui->treeWidget->setStyleSheet("QHeaderView::section{background:rgb(85, 181, 200);}");

    //设置表头的前景色
    QBrush brush;
    brush.setColor(QColor(255,200,0));
    brush.setStyle(Qt::SolidPattern); //Qt::SolidPattern 统一颜色
    ui->treeWidget->headerItem()->setForeground(0,brush);

    //隐藏某一列
    ui->treeWidget->hideColumn(4);

    //设置列宽
    ui->treeWidget->setColumnWidth(1,150);

    //设置表头的字体大小
    QFont font = ui->treeWidget->headerItem()->font(0);
    font.setBold(true);
    font.setPointSize(20);
    ui->treeWidget->headerItem()->setFont(0,font);

    //清除QTreeWidget的数据
    ui->treeWidget->clear();

    //添加根节点
    for(int i = 0;i<3;++i)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(QStringList()<<QString("group%1").arg(i));
        ui->treeWidget->addTopLevelItem(item);
    }

    //子节点
    QList<QTreeWidgetItem*> list;

    for(int i = 0;i<4;++i)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(QStringList()<<QString::number(i)
                                                                  <<QString("name%1").arg(i)
                                                                  <<QString("%1").arg(i%2==0?"girl":"boy")
                                                                  <<QString::number(qrand()%100+60));
        list.push_back(item);
    }

    ui->treeWidget->topLevelItem(0)->addChildren(list);

    //=============
    QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList()<<"99"<<
                                                                  "孙悟空"<<"boy"<<"9999");
    ui->treeWidget->topLevelItem(1)->addChild(item2);


    //=============
    QTreeWidgetItem *item3 = new QTreeWidgetItem();
    item3->setText(0,"1");
    item3->setText(1,"牛魔王");
    item3->setText(2,"boy");
    item3->setText(3,"100");
    ui->treeWidget->topLevelItem(2)->addChild(item3);


    //定位节点
    //第一个主节点的第三个子节点
    QTreeWidgetItem *item4 = ui->treeWidget->topLevelItem(0)->child(2);
    ui->treeWidget->scrollToItem(item4);//滚轮定位到这个节点


    //单击获取信息
    connect(ui->treeWidget,&QTreeWidget::itemClicked,this,[=](){
       //获取信息

       QTreeWidgetItem *item = ui->treeWidget->currentItem();
       int column = ui->treeWidget->currentColumn();

       //判断不是主节点，才有parent()


       if( (item != ui->treeWidget->topLevelItem(0)) &&  (item != ui->treeWidget->topLevelItem(1)) && (item != ui->treeWidget->topLevelItem(2)))
       {
           //qDebug()<<QString("%1主").arg(ui->treeWidget->indexOfTopLevelItem(item));

           qDebug()<<"主节点顺序数"<<ui->treeWidget->indexOfTopLevelItem(item->parent())+1
                    <<"子节点顺序数"<<item->parent()->indexOfChild(item)+1
                    <<"子节点列数"<<column;
       }

    });








}

MainWindow::~MainWindow()
{
    delete ui;
}

