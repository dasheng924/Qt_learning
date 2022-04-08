#include "dialog.h"
#include "ui_dialog.h"
#include <QColorDialog>
#include <QDebug>
#include <QFileDialog>
#include <QThread>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QWizard>
#include <QLabel>
#include <QVBoxLayout>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


     errMsg = new QErrorMessage(this); //因为错误信息对话框有 "是否还要继续显式的对话框,所以这个要设置成堆上的变量"

    connect(ui->ColorBtn,&QPushButton::clicked,this,[=](){
        QColor MyColor = QColorDialog::getColor(Qt::red,this,"请选择你喜欢的颜色?",QColorDialog::ShowAlphaChannel);
        //默认的颜色,父窗口,对话框的标题,显式透明度的设置(1,不透明;0,透明)
        int red,green,blue,a;
        MyColor.getRgb(&red,&green,&blue,&a);
        qDebug()<<"你选中的喜欢的颜色为:"<<"红色="<<red<<",绿色="<<green<<",蓝色="<<blue<<",透明度="<<a;
    });

    connect(ui->FileBtn,&QPushButton::clicked,this,[=](){
        QString path = QFileDialog::getOpenFileName(this,"请选择你要打开的文件","/Users/sunguosheng/","文本文件(*.txt *.doc)");
        qDebug()<<"你选中的文件的路径为="<<path;

        QThread::sleep(3);

        QUrl fileName = QFileDialog::getOpenFileUrl(this,"选择文件的URL?",QUrl("/Users"),"文本文件(*.txt *.doc)");
        qDebug()<<fileName;

    });

    connect(ui->FontBtn,&QPushButton::clicked,this,[=](){


        bool ok;
        QFont MyFont = QFontDialog::getFont(&ok,this);
        if(ok)
            qDebug()<<"你选择的字体是="<<MyFont.family()<<"字体的字号="<<MyFont.weight()<<"字体是否加粗="<<MyFont.bold();
    });

    connect(ui->InputBtn,&QPushButton::clicked,this,[=](){
        bool ok;
        QString out = QInputDialog::getText(this,"输入字符串的对话框","请输入你的姓名",QLineEdit::Normal,"sungs",&ok);
        if(ok)
            qDebug()<<out;

        int outInt = QInputDialog::getInt(this,"输入整型对话框","请输入你的年龄",20,1,120,1,&ok);
        if(ok)
            qDebug()<<outInt;
        double outDouble = QInputDialog::getDouble(this,"输入浮点型对话框","请输入你的语文成绩",89.23,0.00,150.00,2,&ok);
        if(ok)
            qDebug()<<outDouble;

        QStringList items;
        items<<"米饭"<<"稀饭"<<"面条"<<"包子"<<"面包";
        QString outItem = QInputDialog::getItem(this,"输入条目对话框","请选择你喜欢吃的东西",items,0,false,&ok);
        if(ok)
            qDebug()<<"你喜欢吃的东西是:"<<outInt;

    });


    connect(ui->MsgBtn,&QPushButton::clicked,this,[=](){
        QMessageBox::aboutQt(this,"查看QT的相关信息");
    });

    connect(ui->ProcessBtn,&QPushButton::clicked,this,[=](){

        QProgressDialog dialog("文件复制进度条","取消",0,100,this);
        dialog.setWindowTitle("进度对话框");
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
//        dialog.exec();

        int i = 0;
        for(;i<50000;++i)
        {
            dialog.setValue(i);
            QApplication::processEvents();
            QThread::usleep(1800);
            if(dialog.wasCanceled())
            {
                break;
            }
        }
        dialog.setValue(50000);


    });

    connect(ui->ErrMsgBtn,&QPushButton::clicked,this,[=](){

        errMsg->setWindowTitle("错误信息对话框");
        errMsg->showMessage("拷贝文件出错");

    });

    connect(ui->WizardBtn,&QPushButton::clicked,this,[=](){

        QWizard wizard(this);
        wizard.setButtonText(QWizard::CustomButton1, tr("&Print"));
        wizard.setOption(QWizard::HaveCustomButton1, true);
        connect(&wizard, &QWizard::customButtonClicked,
                this, [=](){
                    qDebug()<<"打印成功!";
                });

        wizard.addPage(createPage1());
         wizard.addPage(createPage2());
          wizard.addPage(createPage3());

          wizard.exec();

    });






}

Dialog::~Dialog()
{
    delete ui;
}

QWizardPage *Dialog::createPage1()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("自我介绍");
    QLabel *label = new QLabel("This wizard will help you register you copy "
                               "of Super Product Two.");
    label->setWordWrap(true); //设置自动换行

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    page->setLayout(layout) ;



    return page;
}

QWizardPage *Dialog::createPage2()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("介绍");
    page->setSubTitle("这个是自我介绍");
    page->setPixmap(QWizard::WatermarkPixmap,QPixmap(":/2.png"));
    return page;
}

QWizardPage *Dialog::createPage3()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("介绍");
    page->setSubTitle("这个是自我介绍");
    page->setPixmap(QWizard::LogoPixmap,QPixmap(":/3.png"));
    return page;
}

