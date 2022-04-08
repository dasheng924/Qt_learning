#include "widget.h"
#include "ui_widget.h"
#include <QStyleFactory>
#include <QDebug>
#include <QPalette>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList styleList = QStyleFactory::keys();

    qDebug()<<styleList;
//    setStyle(QStyleFactory::create("Fusion"));
//    setStyle(QStyleFactory::create("Windows"));
//    setStyle(QStyleFactory::create("Macintosh"));
    ui->pushButton->setStyle(QStyleFactory::create("Windows"));

    QPalette palette1 = ui->pushButton->palette();
    //设置按钮文本的颜色为绿色
    palette1.setColor(QPalette::ButtonText,Qt::green);
    //按钮的背景色设置为灰色
    palette1.setColor(QPalette::Button,Qt::gray);
    //设置修改完成之后的调色板palette1对象
    ui->pushButton->setPalette(palette1);

    //设置spinBox为不可用状态
    ui->spinBox->setDisabled(true);
    QPalette palette2 = ui->spinBox->palette();
    //设置SpinBox不可用的背景色为蓝色
    palette2.setColor(QPalette::Disabled,QPalette::Base,Qt::blue);
    ui->spinBox->setPalette(palette2);

}

Widget::~Widget()
{
    delete ui;
}

