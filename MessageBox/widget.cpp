#include "widget.h"
#include "ui_widget.h"


#include <QPushButton>
#include <QErrorMessage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    pm1 = new QMessageBox;
    pm1->setText("text has beeen changed");
    pm1->setInformativeText("Do you want to save?");
    pm1->setDetailedText("AAAAAAAA\nBBBBBBBB\nCCCCCC\nDDDDDDD");
    pm1->setStandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    pm1->setIcon(QMessageBox::Question);
    pm1->setWindowModality(Qt::NonModal);//设置为非模态
    pm1->setTextFormat(Qt::RichText);


    //QMessageBox   的静态函数
    QMessageBox::about(this,"请查看","这个是关于未来的对话框！");
    QMessageBox::critical(this,"错误","这是一个过于过去的事情",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,QMessageBox::Cancel);

    QPushButton * bbtn = new QPushButton("show err",this);
    ui->verticalLayout->addWidget(bbtn);

    connect(bbtn,&QPushButton::clicked,this,[=](){
        QErrorMessage *err = new QErrorMessage;
        err->setWindowTitle("Err");
        err->showMessage("AAA","D");
        err->showMessage("CCC","D");
        err->showMessage("EEE","D");
        err->showMessage("D","E");
        err->showMessage("EEE");
        //同类型的，只会显示一次（去掉钩之后）
    });


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_showBtn_clicked()
{
    pm1->show();
}

void Widget::on_execBtn_clicked()
{
    pm1->exec();
}
