#include "mysax.h"
#include <QtXml>
#include <QListWidget>
#include <QDebug>

MySAX::MySAX()
{
    list = new QListWidget;
    list->show();
}

MySAX::~MySAX()
{
    delete list;
}

bool MySAX::readFile(const QString &filename)
{
    QFile file(filename);
    //读取文件内容,为SAX解析器提供数据
    QXmlInputSource inputSource(&file);
    //建立QXmlSimpleReader对象
    QXmlSimpleReader reader;
    //设置内容处理器
    reader.setContentHandler(this);//this表明使用本类作为时间处理器
    //设置错误处理器
    reader.setErrorHandler(this);
    //解析文件
    return reader.parse(inputSource);
}


//已经解析完一个元素的起始标签
bool MySAX::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts)
{
    Q_UNUSED(namespaceURI)
    Q_UNUSED(localName)
    if(qName ==  "library")
        list->addItem(qName);
    else if (qName == "book") {
        list->addItem("     "+qName+atts.value("id"));
    }
    return true;

}
//已经解析完一个元素的结束标签
bool MySAX::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
    Q_UNUSED(namespaceURI)
    Q_UNUSED(localName)

    if(qName == "title" || qName == "author")
        list->addItem("     "+qName+":"+currentText);
    return true;
}

bool MySAX::characters(const QString &ch)
{
    currentText = ch;
    return true;
}

bool MySAX::fatalError(const QXmlParseException &exception)
{
    qDebug()<<exception.message();
    return false;
}








