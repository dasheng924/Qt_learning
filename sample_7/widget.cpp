#include "widget.h"
#include "ui_widget.h"

#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
//    ui->dateTimeEdit->setDisplayFormat("yyyy 年 MM 月 dd 日 ddd HH 时 mm 分 ss 秒 ap");





}

Widget::~Widget()
{
    delete ui;
}


