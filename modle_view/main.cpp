#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QStandardPaths>
#include <QModelIndex>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>

int main(int argc,char *argv[])
{
    QApplication a(argc,argv);

    //创建标准项模型
    QStandardItemModel model;
    //获取模型的根项,根项不可见
    QStandardItem *parentItem = model.invisibleRootItem();


    //自定义一个标准项
    QStandardItem *item0 = new QStandardItem;
    item0->setText("A");
    QPixmap pix(50,50);
    pix.fill(Qt::red);
    item0->setIcon(pix);
    item0->setToolTip("indexA");

    //将标准项作为父节点的子节点
    parentItem->appendRow(item0);


    //将创建的标准项再作为新的父项
    parentItem = item0;


    //创建新的标准项,作为item0的子项
    QStandardItem *item1 = new QStandardItem;
    item1->setText("B");
    QPixmap pix2(50,50);
    pix2.fill(Qt::blue);
    item1->setIcon(pix2);
    item1->setToolTip("indexB");
    parentItem->appendRow(item1);


    //创建新的标准项,使用新的方式设置项的相关属性
    QStandardItem *item2 = new QStandardItem;
    item2->setData("C",Qt::EditRole);
    item2->setData("indexC",Qt::ToolTipRole);
    QPixmap pix3(50,50);
    pix3.fill(Qt::yellow);
    item2->setData(QIcon(pix3),Qt::DecorationRole);//DecorationRole 数据被渲染为图标
    parentItem->appendRow(item2);


    //创建新的标准项,使用新的方式设置项的相关属性
    QStandardItem *item3 = new QStandardItem;
    item3->setData("D",Qt::EditRole);
    item3->setData("indexD",Qt::ToolTipRole);
    QPixmap pix4(50,50);
    pix4.fill(Qt::green);
    item3->setData(QIcon(pix4),Qt::DecorationRole);//DecorationRole 数据被渲染为图标
    model.invisibleRootItem()->appendRow(item3);


    //树视图中显示模型
    QTreeView treeView ;
    treeView.setModel(&model);
    treeView.show();

    //获取item0的索引
    QModelIndex itemA = model.index(0,0,QModelIndex());
    //输出A项的子项数目
    qDebug()<<"indexA row count:"<<model.rowCount(itemA);

    //输出B项的相关设置
    QModelIndex itemB = model.index(0,0,itemA);
    qDebug()<<"indexB text:"<<model.data(itemB,Qt::EditRole).toString()<<",indexB ToolTip:"<<model.data(itemB,Qt::ToolTipRole).toString();





    return a.exec();
}
