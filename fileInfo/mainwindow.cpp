#include "mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QtDebug>
#include <QLabel>
#include <QMovie>
#include <QPixmap>
#include <QLineEdit>
#include <QCompleter>
#include <QStringList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    //1.打开文件对话框，选择文件
//    QString defaultFilePath = "/Users/sunguosheng/Downloads/";
//    QString str = QFileDialog::getOpenFileName(this,"选择文件",defaultFilePath);

//    QFileInfo info(str);
//    qDebug()<<"文件大小:"<<info.size();
//    qDebug()<<"文件后缀:"<<info.suffix();
//    qDebug()<<info.dir();
//    qDebug()<<info.path();
//    qDebug()<<info.baseName();


    //QLabel显示链接
    QLabel * label = new QLabel(this);
    label->setText("hello world");
    label->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
    label->setOpenExternalLinks(true);


    //QLabel 显示GIF
    QLabel * label2 = new QLabel(this);
    QMovie * movie = new QMovie("/Users/sunguosheng/Downloads/test.gif");
    movie->start();
    label2->setMovie(movie);
    label2->move(300,300);
    label2->resize(200,200);
    movie->setScaledSize(label2->size());

    //QLabel显示图片
    QPixmap p("/Users/sunguosheng/Pictures/QQ20201028-0.jpg");
    QLabel *label3 = new QLabel(this);
    label3->move(500,100);
    label3->setPixmap(p.scaled(500,500));
    label3->resize(500,500);


    //QLineEdit
    QLineEdit * lineEdit = new QLineEdit(this);
    //lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    lineEdit->resize(500,30);
    lineEdit->move(200,20);
    //lineEdit->setTextMargins(10,0,0,0);//设置距离边框的像素值

    //设置输入提示
    QStringList list;
    list<<"hello world"<<"hood"<<"hog"<<"hpple"<<"very good";
    QCompleter * completer = new QCompleter(list,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);//不区分大小写
    completer->setFilterMode(Qt::MatchContains); //设置字符串其中某一部分匹配

    lineEdit->setCompleter(completer);


















}

MainWindow::~MainWindow()
{
}

