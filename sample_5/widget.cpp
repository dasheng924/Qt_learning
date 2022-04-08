#include "widget.h"
#include "ui_widget.h"
#include <QFrame>
#include <QLabel>
#include <QFontMetrics>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    ui->frame->setFrameShape(QFrame::Box);
//    ui->frame->setFrameShadow(QFrame::Sunken);

    ui->frame->setFrameStyle(QFrame::Box | QFrame::Sunken);
    ui->frame->setLineWidth(5);
    ui->frame->setMidLineWidth(10);

    //ui->MyLabel->setFont(QFont("黑体",20,12,true));
    QString string = "&abcdefghijklmnopqrstuvwxyz";
    QString str = ui->MyLabel->fontMetrics().elidedText(string,Qt::ElideRight,100,Qt::TextShowMnemonic);
    ui->MyLabel->setText(str);


    QFont font("times", 25);
    QFontMetrics fm(font);
    int pixelsWide = fm.width("What's the width of this text?");
    int pixelsHigh = fm.height();

    qDebug()<<pixelsWide<<"\t"<<pixelsHigh;

    ui->label2->setPixmap(QPixmap("/Users/sunguosheng/NewQt/build-sample_5-Desktop_x86_darwin_generic_mach_o_64bit-Debug/3.png"));









}

Widget::~Widget()
{
    delete ui;
}

