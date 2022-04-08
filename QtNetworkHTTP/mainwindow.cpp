#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    file = new QFile("/Users/sunguosheng/Downloads/index.html");

    manager = new QNetworkAccessManager(this);

    QNetworkRequest quest;
    quest.setUrl(QUrl("http://www.baidu.com"));
    manager->get(quest);

    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::replyFinish);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete file;
    file = nullptr;
}

void MainWindow::replyFinish(QNetworkReply *reply)
{
    QString all = reply->readAll();
    //qDebug("%s\n",qPrintable(all));
    qDebug("%ukb\n",all.size());
    if(!file->open(QFile::WriteOnly|QFile::Truncate))
    {
        file->close();
        delete file;
        file = nullptr;
        return;
    }

    file->write(qPrintable(all));
    file->close();
    reply->deleteLater();
}

