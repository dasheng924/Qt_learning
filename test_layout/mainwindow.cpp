#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLayout>

#include <QWidget>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#if 1
    QWidget * widget = new QWidget;

    QPushButton *btn1 = new QPushButton("btn1");
    QPushButton *btn2 = new QPushButton("btn2");
    QPushButton *btn3 = new QPushButton("btn3");
    QPushButton *btn4 = new QPushButton("btn4");
    QPushButton *btn5 = new QPushButton("btn5");
    QPushButton *btn6 = new QPushButton("btn6");

    QVBoxLayout * vLayout  = new QVBoxLayout;

    vLayout->addWidget(btn1);
    vLayout->addWidget(btn2);
    vLayout->addWidget(btn3);
    vLayout->addWidget(btn4);
    vLayout->addWidget(btn5);
    vLayout->addWidget(btn6);

    widget->setLayout(vLayout);
    widget->show();



#endif


#if 0

    // 创建符窗口对象
    QWidget *window = new QWidget;
    // 创建若干个子窗口对象
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    // 创建水平布局对象
    QHBoxLayout *layout = new QHBoxLayout;
    // 将子窗口添加到布局中
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);

    // 将水平布局设置给父窗口对象
    window->setLayout(layout);
    // 显示父窗口
    window->show();
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}

