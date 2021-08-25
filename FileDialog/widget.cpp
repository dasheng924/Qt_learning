#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFontDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout * vlayout = new QVBoxLayout;
    QPushButton * btn1,*btn2,*btn3,*btn4,*btn5;
    btn1 = new QPushButton("getExistingDirectory");
    btn2 = new QPushButton("getOpenFileName");
    btn3 = new QPushButton("getOpenFileNames");
    btn4 = new QPushButton("getSaveFileName");
    btn5 = new QPushButton("FontDialog");

    vlayout->addWidget(btn1);
    vlayout->addWidget(btn2);
    vlayout->addWidget(btn3);
    vlayout->addWidget(btn4);
    vlayout->addWidget(btn5);

    this->setLayout(vlayout);

    connect(btn1,&QPushButton::clicked,this,[=](){
        QString dir = QFileDialog::getExistingDirectory(this,"选择目录","/Users/sunguosheng/Downloads/");
        qDebug()<<dir;

    });

    connect(btn2,&QPushButton::clicked,this,[=](){
        QString arg("Text files (*.txt *.doc *.docx)");
        QString getOpenFileName = QFileDialog::getOpenFileName(this,"选择一个打开的文件","/Users/sunguosheng/Downloads/","Images (*.png *.jpg);;Text files (*.txt *.doc *.docx)",&arg);
        qDebug()<<getOpenFileName;

    });

    connect(btn3,&QPushButton::clicked,this,[=](){
        QString arg("Text files (*.txt *.doc *.docx)");
        QStringList getOpenFileNames = QFileDialog::getOpenFileNames(this,"一次性选多个文件","/Users/sunguosheng/Downloads/","Images (*.png *.jpg);;Text files (*.txt *.doc *.docx)",&arg);
        //qDebug()<<getOpenFileNames;
        for(auto i:getOpenFileNames)
            qDebug()<<i;

    });

    //如果文件不存在，不会创建文件，只会保存路径
    connect(btn4,&QPushButton::clicked,this,[=](){
        QString arg("Text files (*.txt *.doc *.docx)");
        QString getSaveFileName = QFileDialog::getSaveFileName(this,"一次性选多个文件","/Users/sunguosheng/Downloads/","Images (*.png *.jpg);;Text files (*.txt *.doc *.docx)",&arg);
        qDebug()<<getSaveFileName;
        if(!getSaveFileName.isEmpty()){
            QMessageBox::warning(this,"warning","保存文件成功");
        }




    });

    connect(btn5,&QPushButton::clicked,this,[=](){
        bool ok;
        QFont font = QFontDialog::getFont(&ok,QFont("微软雅黑", 12, QFont::Bold),this,
                             "选择字体",QFontDialog::DontUseNativeDialog);
        //QFontDialog::DontUseNativeDialog 使用Qt提供的标准字体选择框

        if(ok)
            this->setFont(font);

    });






}

Widget::~Widget()
{
    delete ui;
}

