#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //树控件
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");
    //加载顶层的节点
    QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem *item3 = new QTreeWidgetItem(QStringList()<<"智力");
    //加载上去（加载新的一行）
    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    ui->treeWidget->addTopLevelItem(item3);

    //子节点
    QTreeWidgetItem *item1_1 = new QTreeWidgetItem(QStringList()<<"头节点1的子节点1"<<"test_item1_1");
    QTreeWidgetItem *item1_2 = new QTreeWidgetItem(QStringList()<<"头节点1的子节点2"<<"test_item1_2");
    QTreeWidgetItem *item1_3 = new QTreeWidgetItem(QStringList()<<"头节点1的子节点3"<<"test_item1_3");

    QTreeWidgetItem *item2_1 = new QTreeWidgetItem(QStringList()<<"头节点2的子节点1"<<"test_item2_1");
    QTreeWidgetItem *item2_2 = new QTreeWidgetItem(QStringList()<<"头节点2的子节点2"<<"test_item2_2");
    QTreeWidgetItem *item2_3 = new QTreeWidgetItem(QStringList()<<"头节点2的子节点3"<<"test_item2_3");

    QTreeWidgetItem *item3_1 = new QTreeWidgetItem(QStringList()<<"头节点3的子节点1"<<"test_item3_1");
    QTreeWidgetItem *item3_2 = new QTreeWidgetItem(QStringList()<<"头节点3的子节点2"<<"test_item3_2");
    QTreeWidgetItem *item3_3 = new QTreeWidgetItem(QStringList()<<"头节点3的子节点3"<<"test_item3_3");

    item1->addChild(item1_1);
    item1->addChild(item1_2);
    item1->addChild(item1_3);

    QList<QTreeWidgetItem*> list1;

    list1.push_back(item2_1);
    list1.push_back(item2_2);
    list1.push_back(item2_3);

    item2->addChildren(list1);

    item3->addChild(item3_1);
    item3->addChild(item3_2);
    item3->addChild(item3_3);












}

MainWindow::~MainWindow()
{
    delete ui;
}

