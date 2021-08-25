#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QTimer>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //menuBar() 如果不存在状态栏就自己创建一个状态栏
    QMenu * fileMenu = menuBar()->addMenu(tr("File"));


    QAction * action1,*action2,*action3;
    action1 = new QAction(QIcon(":/image/(127).png"),"新建文件",this);
    //action1->setShortcut(QKeySequence::New);
    //action1->setShortcut(QKeySequence(tr("Crtl+n")));
    action1->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    //action1->setStatusTip(tr("新建一个文件"));

    fileMenu->addSeparator();
    action2 = new QAction(QIcon(":/image/(148).png"),"保存",this);
    action2->setShortcut(QKeySequence::Save);
    //action2->setStatusTip(tr("保存一个文件"));

    fileMenu->addSeparator();
    action3 = new QAction(QIcon(":/image/(144).png"),"打开",this);
    action3->setShortcut(QKeySequence::Open);
    //action3->setStatusTip(tr("打开一个文件"));

    fileMenu->addAction(action1);
    fileMenu->addAction(action2);
    fileMenu->addAction(action3);

    connect(action1,&QAction::triggered,this,[=](){
        QString path = "/Users/sunguosheng/Downloads/";
        QString Filter = "Images (*.png *.xpm *.jpg);;Text files (*.txt *.doc *.docx)";
        QString FilterOnly ="Text files (*.txt *.doc *.docx)";
        QString fileName = QFileDialog::getOpenFileName(this," 新建文件",path,Filter,&FilterOnly);
        QMessageBox::information(this,"打开的文件的信息",fileName);
    });

    connect(action2,&QAction::triggered,[=](){
        QString path = "/Users/sunguosheng/Downloads/";
        QString Filter = "Images (*.png *.xpm *.jpg);;Text files (*.txt *.doc *.docx)";
        QString FilterOnly ="Text files (*.txt *.doc *.docx)";

        QString saveName  = QFileDialog::getSaveFileName(this,"保存文件",path,Filter,&FilterOnly);
        QMessageBox::information(this,"打开的文件的信息",saveName);
    });
    connect(action3,&QAction::triggered,this,[=](){
        QString path = "/Users/sunguosheng/Downloads/";
        QString Filter = "Images (*.png *.xpm *.jpg);;Text files (*.txt *.doc *.docx)";
        QString FilterOnly ="Text files (*.txt *.doc *.docx)";
        QString fileName = QFileDialog::getOpenFileName(this," 新建文件",path,Filter,&FilterOnly);
        QMessageBox::information(this,"打开的文件的信息",fileName);
    });


    //menuBar 只有添加了action 才会显示出来
    QMenu * toolMenu = menuBar()->addMenu(tr("Tool"));

    //“&”主要用于快捷键，就好比按下alt的时候我们使用的桌面程序也会有快捷键一样。而且这个快捷键与字符串的首字母有关，首字母是什么 快捷键就是 alt+什么。
    QAction * action4 = new QAction(QIcon(":/image/(137).png"),tr("&add action"),this);
    toolMenu->addSeparator();
    QAction * action5 = new QAction(QIcon(":/image/(139).png"),tr("&remove action"),this);


    toolMenu->addAction(action4);
    toolMenu->addAction(action5);

    connect(action4,&QAction::triggered,this,[=](){

        QMessageBox::warning(this,"warning","尝试一下tr(&xxx)的功能");
    });

    QToolBar * toolBar = new QToolBar("Tool",this);
    this->addToolBar(Qt::BottomToolBarArea,toolBar);

    QPushButton * btn1 = new QPushButton("牛皮的厉害");
    toolBar->addWidget(btn1);

    QStatusBar * statusBar = new QStatusBar(this);
    statusBar->showMessage("World",1000);
    QLabel * label  = new QLabel("WWorld");
    statusBar->addWidget(label);


    //盖住了这些按钮，需要手动操作显示,调用定时器的一次周期
    QTimer::singleShot(1001,this,[=](){
        label->show();
    });






















}

MainWindow::~MainWindow()
{
    delete ui;
}

