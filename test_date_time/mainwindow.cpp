#include "mainwindow.h"


#include <QDate>
#include <QDebug>
#include <QTime>
#include <QElapsedTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QDate curDate = QDate::currentDate();
    qDebug()<<curDate.toString("yyyy-MM-dd");
    /*MM-->06
     *MMM-->6月
     *MMMM-->六月
     *
     *dd-->17
     *ddd-->周四
     *dddd-->星期四
     */
    //得到对象中的年月日
    int year;
    int month;
    int day;
    year = curDate.year();
    month = curDate.month();
    day = curDate.day();
    qDebug()<<year<<" "<<month<<" "<<day;
    curDate.getDate(&year,&month,&day);
    qDebug()<<year<<" "<<month<<" "<<day;


    QTime curTime = QTime::currentTime();
    qDebug()<<curTime.toString("HH:mm:ss:zzz A");
    int hour;
    int min;
    int sec;
    int msec;
    hour = curTime.hour();
    min = curTime.minute();
    sec = curTime.second();
    msec = curTime.msec();

    qDebug()<<hour<<" "<<min<<" "<<sec<<" "<<msec;

#if 0
    QTime ok;
    ok.start();
    for(int i = 0;i<10000;++i)
    {
        qDebug()<<i+2;
    }
    int ok_msec = ok.elapsed();
    qDebug()<<ok_msec<<"ms";

    QElapsedTimer ook;
    ook.start();
    for(int i = 0;i<10000;++i)
    {
        qDebug()<<i+2;
    }
    int secc = ook.elapsed();
    qDebug()<<ok_msec<<"ms";
    qDebug()<<secc<<"ms";
#endif

    //得到当前日期时间
    QDateTime dateTime = QDateTime::currentDateTime();
    QDate datee = dateTime.date();
    QTime timee = dateTime.time();

    qDebug()<<datee.year()<<"-"<<datee.month()<<"-"<<datee.day()<<" "<<timee.hour()<<":"
             <<timee.minute()<<":"<<timee.second()<<"-"<<timee.msec();
















}

MainWindow::~MainWindow()
{
}

