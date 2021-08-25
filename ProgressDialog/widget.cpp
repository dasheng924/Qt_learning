#include "widget.h"
#include "ui_widget.h"

#include <QProgressDialog>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QMessageBox>
#include <QThread>
#include <QLabel>
#include <QSpacerItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout * vlayout = new QVBoxLayout;
    QHBoxLayout * hlayout = new QHBoxLayout;

    QProgressDialog * progressDialog = new QProgressDialog("正在拷贝数据...","取消拷贝",0,100);
    QLabel * label = new QLabel;


    hlayout->addWidget(progressDialog);
    hlayout->addWidget(label);


    vlayout->addLayout(hlayout);

    this->setLayout(vlayout);
    this->resize(270,150);
    //初始化窗口
    this->setWindowTitle("请稍后...");
    progressDialog->setWindowModality(Qt::WindowModal);

    //更新值
    static int num;
    QTimer * timer = new QTimer(this);

    connect(timer,&QTimer::timeout,progressDialog,[=](){
        progressDialog->setValue(num) ;
        num++;
        label->setText(QString::number(num)+"%");
        if(num == progressDialog->maximum()){

            timer->stop();
            QMessageBox::information(this,"info","拷贝完成");
            delete progressDialog;
            delete timer;
            QCoreApplication::quit();
        }
    });

    connect(progressDialog,&QProgressDialog::canceled,this,[=](){
        timer->stop();
        progressDialog->setLabelText("正在撤销...");
        while(1){
            num--;
            label->setText(QString::number(num)+"%");
            progressDialog->setValue(num);
            if(num == progressDialog->minimum()){
                break;
            }
            QThread::msleep(230);
        }
        num = 0;
        delete progressDialog;
        delete timer;
        QCoreApplication::quit();
    });

      timer->start(100);











}

Widget::~Widget()
{
    delete ui;
}

