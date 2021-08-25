#include "dialog.h"
#include "ui_dialog.h"


#include <QPushButton>
#include <QInputDialog>
#include <QDebug>
#include <QHBoxLayout>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    QHBoxLayout * hlayout = new QHBoxLayout;
    QPushButton *btn1,*btn2,*btn3,*btn4,*btn5;;
    btn1 = new QPushButton("getDouble",this);
    btn2 = new QPushButton("getInt",this);
    btn3 = new QPushButton("getItem",this);
    btn4 = new QPushButton("getMultiLineText",this);
    btn5 = new QPushButton("getText",this);

    hlayout->addWidget(btn1);
    hlayout->addWidget(btn2);
    hlayout->addWidget(btn3);
    hlayout->addWidget(btn4);
    hlayout->addWidget(btn5);

    this->setLayout(hlayout);

    connect(btn1,&QPushButton::clicked,[=](){
        double ret = QInputDialog::getDouble(this,"获取一个double","double",0.00);
        qDebug()<<ret;

    });

    connect(btn2,&QPushButton::clicked,[=](){
        int ret = QInputDialog::getInt(this,"输入你的年龄","年龄",0,0,120,1,0);

        qDebug()<<ret;

    });

    connect(btn3,&QPushButton::clicked,[=](){
        QStringList str;
        str<<"green"<<"red"<<"balck";
         QString ret= QInputDialog::getItem(this,"你最喜欢的颜色","颜色",str,0,false,0,Qt::Dialog,Qt::ImhHiddenText);
        qDebug()<<ret;
    });

    connect(btn4,&QPushButton::clicked,[=](){
        QString text("111\n2222\n4334444\n");
        QString ret= QInputDialog::getMultiLineText(this,"你想对世界说的话","吧唧一下",text,0);
        qDebug()<<ret;
    });
    connect(btn5,&QPushButton::clicked,[=](){
        QString ret= QInputDialog::getText(this,"你最喜欢的颜色","颜色",QLineEdit::Password,"颜色");
        qDebug()<<ret;
    });


}

Dialog::~Dialog()
{
    delete ui;
}

