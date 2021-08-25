#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_manager = new QNetworkAccessManager(this);
    getmsuic("刘德华");




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::getmsuic(const QString msuic)
{

    QNetworkRequest request;

    QString url = QString(""
                          "");
    request.setUrl(QUrl(url));
    request.setRawHeader("Content-Type","application/x-www-form-urlencoded");

    QString data = QString("types=search&count=20&source=netease&page=1&name=%1").arg(msuic);

    QNetworkReply *reply = m_manager->post(request,data.toUtf8());

    connect(reply,&QNetworkReply::finished,this,[=](){

        QByteArray redata = reply->readAll();
        qDebug()<<redata.data();
    });

}

