#include "widget.h"
#include "ui_widget.h"


#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QCoreApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QDialog * dialog = new QDialog;
//    dialog->setWindowTitle("dialog");


//    //3.设置此属性为true，对话框将以应用程序模式显示，该函数通常与show()一起使用
//    dialog->setModal(true);
//    dialog->show();
//    qDebug()<<dialog->isModal(); //true-->模态对话框


//    dialog->exec();//1.应用程序式的对话框
//    dialog->open();//2.窗口模式对话框，并立即返回

//    dialog->windowModality(Qt::NonModal)//非模态窗口
//    dialog->windowModality(Qt::WindowModal)//窗口模式
//    dialog->windowModality(Qt::ApplicationModal)//应用程序式
    //切换需要先隐藏再显示出来


    dialog  = new Dialog;
    //调用accept()产生信号accepted
    connect(dialog,&Dialog::accepted,this,[=](){

        QMessageBox::information(this,"info","调用了accept()产生了信号accepted");
    });

    dialog->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(dialog,&Dialog::destroyed,this,[=](){
        QMessageBox::information(this,"info","对话框关闭，触发信号destroyed") ;
    });




}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_showDialogBtn_clicked()
{

    int ret = dialog->exec();
    //可以根据这个返回值得倒不同的使用场景
    if(ret == QDialog::Accepted)
    {
        qDebug()<<"accept"<<ret;
    }
    else if(ret == QDialog::Rejected)
    {
        qDebug()<<"reject"<<ret;
    }
    else{
        qDebug()<<"done"<<ret;
    }
    QCoreApplication::quit();//退出程序，0 成功
//    QCoreApplication::exit();//-->0 成功，该函数会使程序离开主事件循环，并返回到调用QCoreApplication::exec()处

}
