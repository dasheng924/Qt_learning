#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lineEdit = new MyLineEdit;

    QWidget *widget = new QWidget;
    QGridLayout *gLayout = new QGridLayout;
    gLayout->addWidget(lineEdit);
    widget->setLayout(gLayout);
    this->setCentralWidget(widget);

    lineEdit->installEventFilter(this);//在widget上为lineEdit安装事件过滤器












}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == lineEdit)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            qDebug()<<"eventFilter widget 按下了键盘"<<keyEvent->key();
        }
    }
    return QWidget::eventFilter(obj,event);

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event)
    qDebug()<<"widget 按下了键盘";
}



