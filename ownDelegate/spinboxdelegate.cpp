#include "spinboxdelegate.h"
#include <QSpinBox>
#include <QDebug>

spinBoxDelegate::spinBoxDelegate(QObject *parent):QItemDelegate(parent)
{

}



//创建编辑器,没有在构造中创建编辑器是为了在需要使用编辑器的时候再去创建
//当视图需要一个编辑器时,它会告知委托创建一个编辑器部件
//不需要为编辑器保持一个指针,视图会在不需要编辑器时,对编辑器进行销毁
QWidget *spinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)

    QSpinBox *edit = new QSpinBox(parent);
    edit->setMinimum(0);
    edit->setMaximum(100);
    return edit;
}


//委托需要将模型中的数据复制到编辑器中
//可能需要为不同的数据提供不同的编辑器,所以内部会对这个edit进行准换
void spinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);

    int value = index.model()->data(index,Qt::EditRole).toInt();
    int v = index.data(Qt::EditRole).toInt();
    qDebug()<<value<<"  "<<v;
    spinBox->setValue(value);

}

//当用户完成编辑的时候,视图会调用setModelData()函数告知委托将编辑好的数据存储到模型中
void spinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();//确保获取的是spinBox最近一次更新的数值
    //获取编辑器中的值设置到模型中对应的项目
    int value = spinBox->value();
    model->setData(index,value,Qt::EditRole);
}

void spinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)
    //QStyleOptionViewItem 对象提供布局所需要的信息
    editor->setGeometry(option.rect);//使用矩形作为编辑框的几何布局

}










