#ifndef CUSTOMSQLTABLEMODEL_H
#define CUSTOMSQLTABLEMODEL_H

#include <QObject>
#include <QSqlTableModel>

class CustomSqlTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit CustomSqlTableModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

#endif // CUSTOMSQLTABLEMODEL_H
