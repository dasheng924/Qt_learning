#ifndef SPINBOXDELEGATE_H
#define SPINBOXDELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include <QWidget>

class spinBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit  spinBoxDelegate(QObject *parent = nullptr);
    //创建编辑器
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    //设置编辑器的数据:将模型中的数据复制到编辑器中
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    //编辑器的数据同步到模型上
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    //更新编辑器的几何布局
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
s

};

#endif // SPINBOXDELEGATE_H
