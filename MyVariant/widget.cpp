#include "widget.h"

#include <QVariant>
#include <QDebug>
#include <QTime>
#include <QDate>
#include <QDateTime>
#include <QTimer>
#include <QVector>
#include <QElapsedTimer>
#include <QList>
#include <QMenu>
#include <QAction>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

   // testVariant();

//   testDateTime();

   testTimer();




}

Widget::~Widget()
{

}

//验证QVariant的使用
void Widget::testVariant()
{
    //封装自定义类型QVariant
    Person p;
    p.name = "孙国盛";
    p.age = 25;

    QVariant v = QVariant::fromValue(p);

    if(v.canConvert<Person>())
    {
        Person pp = v.value<Person>();
        qDebug()<<"姓名："<<pp.name<<"\t年龄:"<<pp.age;
    }

    //1.Qvariant的构造方法
    QVariant v1(10);
    //2.成员方法 setValue
    QVariant v2;
    v2.setValue(QString("hello world"));
    //3.静态方法
    QVariant v3 = QVariant::fromValue(23.22);


    if(v1.type() == QVariant::Int)
    {
        qDebug()<<"Int";
    }
    if(v2.type() == QVariant::String)
    {
        qDebug()<<"String";
    }
    if(v3.type() == QVariant::Double)
    {
        qDebug()<<"Double";
    }
}

void Widget::testDateTime()
{
    //获取当前时间
    QTime currTime = QTime::currentTime();
    QString time = currTime.toString("HH:mm:ss:zzz");
    qDebug()<<"现在的时间:"<<time;
    qDebug()<<"小时:"<<currTime.hour();
    qDebug()<<"分钟:"<<currTime.minute();
    qDebug()<<"秒:"<<currTime.second();
    qDebug()<<"毫秒:"<<currTime.msec();

    //获取当前日期
    QDate currDate = QDate::currentDate();
    QString date = currDate.toString("yyyy-MM-dd");
    qDebug()<<"日期:"<<date;
}

void Widget::testTimer()
{
//    QTimer *timer = new QTimer;
//    timer->setTimerType(Qt::PreciseTimer);
//    timer->start(1000); //这里的单位是毫秒

    QTime *time = new QTime;
    time->start();
    QVector<int> v;
    int i = 0;
    for (i = 0;i<100000;++i) {
        v.push_back(i+1);
    }
    int s2 = time->elapsed(); //毫秒数
    qDebug()<<"vector 插入"<<i<<"次，经历的时间"<<s2<<"毫秒";

    QElapsedTimer * time2 = new QElapsedTimer;
    time2->start();
    int j = 0;
    QList<int> l;
    for (;j<100000;++j) {
        l.push_back(j+1);
    }
    int ss2 = time2->elapsed();
    qDebug()<<"list 插入"<<j<<"次，经历的时间"<<ss2<<"毫秒";





}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        QMenu * menu = new QMenu(this);
        QAction * action = new QAction("关闭");
        menu->addAction(action);
        connect(action,&QAction::triggered,this,[=](){
            this->close();
        });

        //QCursor::pos() 屏幕坐标
        menu->exec(QCursor::pos()); //右键菜单被模态显示出来
    }
}

