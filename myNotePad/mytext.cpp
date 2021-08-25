#include "mytext.h"

#include <QDebug>
#include <QMimeData>
#include <QFile>

Mytext::Mytext(QWidget *parent) : QPlainTextEdit(parent)
{

}

void Mytext::dropEvent(QDropEvent *e)
{
    const QMimeData * md = e->mimeData();
    QMimeData * mmd = const_cast<QMimeData*>(md);
    QString filePath = mmd->text();
//    qDebug()<<filePath;//"file:///Users/sunguosheng/Downloads/QTextEdit.txt"
    QString realFilePath = filePath.remove(0,strlen("file://"));
    //qDebug()<<realFilePath;
    QFile file(realFilePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"open file fail!";
        return;
    }
    QString line;
    while(!file.atEnd())
    {
        line = file.readLine();
        this->appendPlainText(line);
    }
    file.close();
}


