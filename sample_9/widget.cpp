#include "widget.h"
#include "ui_widget.h"

#include <QLineEdit>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //验证分裂器的使用

    //分裂器和普通的布局相比，对于控件的纵向长度是可以拉伸的

    QLineEdit *lineEdit = new QLineEdit("test");


    QLabel *label = new QLabel(this);
    label->setText("按钮(&P)");
    label->setBuddy(ui->pushButton);
    ui->horizontalLayout->addWidget(label);
    ui->horizontalLayout->addWidget(lineEdit);






}

Widget::~Widget()
{
    delete ui;
}

