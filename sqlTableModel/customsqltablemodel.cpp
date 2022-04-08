#include "customsqltablemodel.h"

#include <QColor>

CustomSqlTableModel::CustomSqlTableModel(QObject *parent):QSqlTableModel(parent)
{

}

QVariant CustomSqlTableModel::data(const QModelIndex &idx, int role) const
{
    QVariant value = QSqlTableModel::data(idx,role);
//    if(value.isValid())
//    {
//        if(idx.column()==0)
//        {
//            return value.toString().prepend('#');
//        }
//        else if(idx.column() ==1 )
//        {
//            return value.toString().prepend('[').append(']');
//        }
//    }

    if(role == Qt::TextAlignmentRole)
    {
        value = Qt::AlignCenter;
        return value;
    }

    if(role == Qt::ForegroundRole && idx.column() == 0)
    {
        if(idx.data().toInt()%2== 0)
            return QVariant::fromValue(QColor(Qt::red));
        else
            return QVariant::fromValue(QColor(Qt::green));
    }

    return value;
}

QVariant CustomSqlTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if(orientation == Qt::Horizontal)
        return QString("列%1").arg(section);
    else
        return QString("行%1").arg(section);
}
