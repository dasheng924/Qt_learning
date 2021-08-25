#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QColorDialog>
#include <QBrush>
#include <QPixmap>
#include <QDebug>
#include <QPainter>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton * btn = new QPushButton("ColorDialog");
    QLabel * label = new QLabel("显示选中的颜色");
    QVBoxLayout * vlayout = new QVBoxLayout;
    vlayout->addWidget(btn);
    vlayout->addWidget(label);

    this->setLayout(vlayout);

    QObject::connect(btn,&QPushButton::clicked,this,[=](){
        //QColorDialog::getColor(); //静态函数显示
        //各种函数
        QColorDialog pd(QColor(111,1,1),0);//设定一个初始颜色


        pd.setOptions(QColorDialog::ShowAlphaChannel);
        //pd.setOptions(QColorDialog::NoButtons);
        pd.exec();

        QColor curColor = pd.currentColor();
        qDebug()<<curColor.red()<<" "<<curColor.green()<<" "<<curColor.blue()<<" "<<curColor.alpha();

        QBrush brush(curColor);
        QRect rect(0,0,label->width(),label->height());
        QPixmap pixmap(rect.width(),rect.height());
        QPainter p(&pixmap);

        p.fillRect(rect,brush);
        label->setPixmap(pixmap);








    });





}

Widget::~Widget()
{
    delete ui;
}

