#include "widget.h"
#include "ui_widget.h"

#include <QDir>
#include <QFileSystemWatcher>
#include <QGridLayout>
#include <QListWidget>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //监控对象的初始化
    QFileSystemWatcher *fileWatcher = new QFileSystemWatcher(this);
    connect(fileWatcher,&QFileSystemWatcher::directoryChanged,this,[=](const QString &path){
        qDebug()<<"目录被修改"<<path;
    });

    connect(fileWatcher,&QFileSystemWatcher::fileChanged,this,[=](const QString &path){
        qDebug()<<"文件被修改"<<path;
    });


    //界面的初始化
    QGridLayout *gLayout = new QGridLayout;
    QListWidget *listWidget = new QListWidget(this);
    listWidget->setStyleSheet("QListWidget::item:selected:active { background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #6a6ea9, stop: 1 #888dd9);}");
    gLayout->addWidget(listWidget);
    setLayout(gLayout);



    //构建目录对象
    QDir dir("/Users/sunguosheng/Downloads/");

    //添加一个目录到上面的dir
    dir.mkdir("testWatcher");
    dir.cd("testWatcher");
    //把目录加入监视
    bool ret = fileWatcher->addPath(dir.absolutePath());
    qDebug()<<"加入目录监视:"<<ret;


    //创建文件加入监视
    QFile file(dir.absolutePath()+"/test_watcher.txt");
    if(!file.open(QFile::WriteOnly))
        return;
    QString date = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");
    file.write(date.toUtf8());
    file.close();
    QFileInfo info(file);
    listWidget->addItem("文件"+info.absoluteFilePath()+"加入监控");

    fileWatcher->addPath(info.absoluteFilePath());

}

Widget::~Widget()
{
    delete ui;
}

