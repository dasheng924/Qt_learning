#include "mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //需要一个manager对象，发送一个post或者get请求
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    //准备工作,组装一个请求头
    //QNetworkRequest *request = new QNetworkRequest(QUrl("www.baidu.com"));
    QNetworkRequest req;
    QString agent = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.101 Safari/537.36 Edg/91.0.864.48";
    req.setHeader(QNetworkRequest::UserAgentHeader,agent);
    req.setUrl(QUrl("http://www.baidu.com/"));

    //发送请求
    //QNetworkReply *reply = manager->post(req,"");
    QNetworkReply *reply = manager->get(req);

    //发送成功后，获取接受到的数据
    //这里的信号也可以换成 readyread
    connect(reply,&QNetworkReply::finished,this,[=](){
        QByteArray data = reply->readAll();
        //readAll 读的服务器给你回发的数据，头的部分需要单独用reply->header获取头部信息
        qDebug()<<data;
        //获取对应头的数据
        QVariant variant = reply->header(QNetworkRequest::LocationHeader);
        if(variant.isValid()){
            qDebug()<<variant.toString();
        }

    });




}

MainWindow::~MainWindow()
{
}

