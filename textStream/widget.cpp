#include "widget.h"
#include "ui_widget.h"

#include <QTextStream>
#include <QDataStream>
#include <QFile>
#include <QDebug>
#include <QTextCodec>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QFile file("/Users/sunguosheng/Downloads/testWatcher/test_watcher.txt");
//    if(!file.open(QIODevice::ReadWrite))
//        return;
//    qDebug()<<file.size();
//    QTextStream s(&file);

//    QString name = "sungs";
//    int age = 26;
//    s.setFieldAlignment(QTextStream::AlignCenter);
//    s<<name<<qSetFieldWidth(10)<<age;

//    while(!s.atEnd())
//    {
//        char ch; ;
//        s>>ch;
//        qDebug()<<ch;
//    }

//    file.close();

   // s.setCodec(QTextCodec::codecForName("GBK"));

//    QFile f("/Users/sunguosheng/Downloads/file.txt");
//    f.open(QIODevice::WriteOnly|QIODevice::Truncate);
//    QDataStream ss(&f);
//    //串行化字符串
//    ss<<QString("apple");
//    //串行化整数
//    ss<<(qint32)111;


//    f.open(QIODevice::ReadOnly);
//    QDataStream in(&f);
//    QString out1;
//    qint32 out2;
//    in>>out1>>out2;
//    qDebug()<<out1<<"       "<<out2;
//    f.close();


    //--------------
    QFile ff("file.xxx");
#if 0
    ff.open(QIODevice::WriteOnly);
    QDataStream ss(&ff);
    //写入幻数和版本号
    ss<<(qint32)0xA0B0C0DD;
    ss<<(qint32)1234;
    ss.setVersion(QDataStream::Qt_4_0);//设置硬解码
    ss<<QString("hello"); //写入数据
    ff.close();
#else
    ff.open(QIODevice::ReadOnly);
    QDataStream ss(&ff);
    //读取幻数
    qint32 magic;
    ss>>magic;

    if(magic != qint32(0xA0B0C0DD))
    {
        qDebug()<<"BAD_FILE_FORMAT";
    }
    //读取版本
    qint32 version;
    ss>>version;
    if(version<100)
    {
        qDebug()<<"BAD_FILE_TOO_OLD";
    }
    else if(version > 123)
    {
        qDebug()<<"BAD_FILE_TOOL_NEW";
    }


    if(version<= 110)
        ss.setVersion(QDataStream::Qt_3_1);
    else
        ss.setVersion(QDataStream::Qt_4_0);

    QString out;
    ss>>out;
    qDebug()<<out;


#endif

}

Widget::~Widget()
{
    delete ui;
}

