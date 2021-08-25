#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>
#include <QDebug>
#include <QPushButton>
#include <QSignalMapper>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //给中央的窗口加一个网格布局
    QGridLayout *gLayout = new QGridLayout;
    this->centralWidget()->setLayout(gLayout);

    //根据按钮的名字创造出对应按钮
    QString str="Button1,Button2,Button3,Button4,Button5,Button6,Button7";
    QStringList strlist = str.split(",");
    //信号映射
    QSignalMapper * pMapper = new QSignalMapper(this);

    for(int i = 0;i<strlist.size();++i)
    {
        //qDebug()<<strlist[i];
        QPushButton *pBtn = new QPushButton(this);
        pBtn->setText(strlist[i]);

        //1.按钮按下的信息和信号集进行映射
        connect(pBtn,SIGNAL(clicked()),pMapper,SLOT(map()));
        //2.在信号集里面用按钮的名字做区分
        pMapper->setMapping(pBtn,pBtn->text());

        //把生成的每一个按钮添加到布局中
        gLayout->addWidget(pBtn,i,0);
    }

    QLineEdit *line = new QLineEdit;
    //3.信号集会发出信号，对应的参数会被传出
    connect(pMapper,SIGNAL(mapped(QString)),line,SLOT(setText(QString)));
    gLayout->addWidget(line,0,1);



}

MainWindow::~MainWindow()
{
    delete ui;
}

