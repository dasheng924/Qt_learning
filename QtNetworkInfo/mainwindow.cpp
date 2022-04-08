#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostInfo>
#include <QDebug>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QFile>
#include <QXmlStreamWriter>
#include <QDnsLookup>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    {
//    //-----------------fromName-------------------
//    QString hostName = QHostInfo::localHostName();
//    //QString domain = QHostInfo::localDomainName(); //本地域名

//    qDebug()<<hostName;
//    QHostInfo info = QHostInfo::fromName(hostName);
//    //获取IP列表
//    qDebug()<<info.addresses(); // QList<QHostAddress>类型的返回值

//    //取出其中的IPV4地址
//    foreach(QHostAddress address,info.addresses())
//    {
//        if(address.protocol() == QAbstractSocket::IPv4Protocol)
//        {
//            QString out = address.toString();
//            if(!out.contains("127.0.0.1")) //排除掉回环地址
//                qDebug()<<address.toString();
//        }
//    }

//    //--------------------------lookupHost()--------------------------
//    //[static] int QHostInfo::lookupHost(const QString &name, QObject *receiver, const char *member)

//    int ret = QHostInfo::lookupHost("4.2.2.1",this,&MainWindow::lookedUp);

//    //QHostInfo::abortHostLookup(ret);//终止查找,因为lookupHost是异步的


//    //如果参数1输入的是ip,查找对应的域名
    }



    {
//    QFile file("/Users/sunguosheng/Downloads/allInterfaces.xml");
//    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
//    {
//        file.close();
//        return;
//    }

//    QXmlStreamWriter stream(&file);
//    stream.setAutoFormatting(true);//自动缩进和换行
//    stream.writeStartDocument();//添加xml的说明
//    stream.writeStartElement("Interfaces");

//    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
//    static int num = 0;
//    static int i = 0;
//    foreach(QNetworkInterface interface,list) //遍历每一个接口信息
//    {
//        qDebug()<<"--------------------------------------------";
//        qDebug()<<"接口名称:"<<interface.name();
//        qDebug()<<"硬件地址:"<<interface.hardwareAddress();

//        stream.writeStartElement(interface.name());
//        stream.writeAttribute("id",QString::number(i++));

//        stream.writeTextElement("硬件地址",interface.hardwareAddress());


//         num= 0;
//        //获取IP地址条目列表,每一个条目包括IP地址,子网掩码,广播地址
//        QList<QNetworkAddressEntry> entryList = interface.addressEntries();

//        foreach(QNetworkAddressEntry entry,entryList)
//        {

//            stream.writeStartElement(QString("序列%1").arg(num++));
//            qDebug()<<"***************************";
//            //Ip地址
//            qDebug()<<"IP地址:"<<entry.ip().toString();
//            stream.writeTextElement("IP地址",entry.ip().toString());
//            //子网掩码
//            qDebug()<<"Netmask:"<<entry.netmask().toString();
//            stream.writeTextElement("子网掩码",entry.netmask().toString());
//            //广播地址
//            qDebug()<<"Broadcast:"<<entry.broadcast().toString();
//            stream.writeTextElement("广播地址",entry.broadcast().toString());
//            qDebug()<<"***************************";
//            stream.writeEndElement();
//        }

//        qDebug()<<"--------------------------------------------";

//        stream.writeEndElement();
//    }

//    stream.writeEndDocument();
//    file.close();
    }

    QDnsLookup *dns = new QDnsLookup(this);
    dns->setType(QDnsLookup::CNAME);
    dns->setName("www.baidu.com");
    dns->lookup();

    connect(dns,&QDnsLookup::finished,this,[=](){
        if(dns->error() != QDnsLookup::NoError)
        {
            qWarning("DNS lookUp failed!");
            dns->deleteLater();
            return ;
        }

        foreach(const QDnsDomainNameRecord &record,dns->canonicalNameRecords())
        {
            qDebug()<<record.name()<<" "<<record.value();
        }
    });





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lookedUp(const QHostInfo &host)
{
    if(host.error() != QHostInfo::NoError)
    {
        qDebug()<<"Lookup failed:"<<host.errorString();
    }
    foreach(const QHostAddress &address,host.addresses())
        qDebug()<<address.toString();

    qDebug()<<host.hostName();



}

