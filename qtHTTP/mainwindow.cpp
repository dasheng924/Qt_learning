#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include <QFile>
#include <QFileInfo>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    ui->progressBar->hide();


    //开始点击下载按钮,出触发的操作
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        url = ui->lineEdit->text();
        QFileInfo info(url.path());
        qDebug()<<url.path();
        QString fileName = info.fileName();
        if(fileName.isEmpty())
            fileName = "index.html";

        qDebug()<<fileName;
        file = new QFile(fileName);
        if(!file->open(QIODevice::WriteOnly|QIODevice::Truncate))
        {
            delete  file;
            file = nullptr;
            return;
        }

        startRequest(url);
        ui->progressBar->setValue(0);
        ui->progressBar->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startRequest(const QUrl url)
{
    reply = manager->get(QNetworkRequest(url));
    connect(reply,&QNetworkReply::readyRead,this,&MainWindow::httpReadyRead);
    connect(reply,&QNetworkReply::downloadProgress,this,&MainWindow::updateDataReadProgress);
    connect(reply,&QNetworkReply::finished,this,&MainWindow::httpFinished);
}

void MainWindow::httpReadyRead()
{
    if(file)
        file->write(reply->readAll());
}

void MainWindow::updateDataReadProgress(qint64 readBytes, qint64 allBytes)
{
    ui->progressBar->setMaximum(allBytes);
    ui->progressBar->setValue(readBytes);
}

void MainWindow::httpFinished()
{
    ui->progressBar->hide();
    if(file)
    {
        file->close();
        delete file;
        file = nullptr;
    }
    reply->deleteLater();
    reply = nullptr;
}

