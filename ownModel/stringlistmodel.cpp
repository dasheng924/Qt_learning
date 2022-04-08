#include "stringlistmodel.h"


int StringListModel::rowCount(const QModelIndex &parent) const
{
    //因为是一个字符串列表,不存在父项
    Q_UNUSED(parent);

    return stringList.count();
}


//返回对应索引对应的数据项
QVariant StringListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) //无效索引
        return QVariant();
    if(index.row() == stringList.size())//超出索引范围
        return QVariant();

    if(role == Qt::DisplayRole || role == Qt::EditRole) //数据被渲染成文本,或者是可以编辑
        return stringList.at(index.row());
    else
        return QVariant();
}


//标头中显示行号和列号
QVariant StringListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if(orientation == Qt::Horizontal) //水平
        return QString("列%1").arg(section);
    else
        return QString("行%1").arg(section);
}

Qt::ItemFlags StringListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::ItemIsEnabled; //用户与项目可交互,但是不能编辑
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; //项目可以编辑
}

bool StringListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole) //有效索引同时可以编辑
    {
        stringList.replace(index.row(),value.toString());
        emit dataChanged(index,index);
        return true;
    }
    return false;
}

//在指定位置的前面添加指定数量的空字符串
bool StringListModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent)
    beginInsertRows(QModelIndex(),row,row+count-1);
    for(int i = 0;i<count;++i)
    {
        stringList.insert(row,""); //执行插入空行的操作
    }
    endInsertRows();
    return true;
}

bool StringListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent)
    beginRemoveRows(QModelIndex(),row,row+count-1);
    for(int i = 0;i<count;++i)
        stringList.removeAt(row);
    endRemoveRows();
    return true;
}








