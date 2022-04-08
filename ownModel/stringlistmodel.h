#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QModelIndex>
#include <QTableView>


class QTableView;

class StringListModel : public QAbstractListModel
{
    Q_OBJECT
public:



    //列表初始化
    StringListModel(const QStringList &strings,QObject *parent = 0):QAbstractListModel(parent),stringList(strings){};
    int rowCount(const QModelIndex &parent = QModelIndex()) const; //返回模型的行数
    QVariant data(const QModelIndex &index,int role) const;//指定模型索引的数据项
    QVariant headerData(int section,Qt::Orientation orientation,int role = Qt::DisplayRole) const;//标头

    virtual Qt::ItemFlags flags(const QModelIndex &index) const;//告知委托这个项目可编辑
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);//设置数据


    //增加行
    virtual bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    //删除行
    virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());



private:
    QStringList stringList;//QAbstractItemModel本身不存储数据,仅提供接口给视图进行访问
    QTableView *tableView;



};

#endif // STRINGLISTMODEL_H
