#include <QCoreApplication>
#include <QDebug>
#include <QtXml>
#include <QFile>

int main(int argc,char *argv[])
{
    QCoreApplication a(argc,argv);

    //新建QDomDocumnet对象,表示一个xml文档
    QDomDocument doc;

    QFile file("/Users/sunguosheng/Downloads/QtXml.xml");
    if(!file.open(QIODevice::ReadWrite))
        return 0;
    if( !doc.setContent(&file))
    {
        file.close();
        return 0;
    }

    //关闭文件
    file.close();

    //获取XML文件的第一个节点,也就是XML的说明
    QDomNode firstNode = doc.firstChild();
    //输出XML说明
    qDebug()<<qPrintable(firstNode.nodeName()); //nodeName为开始的"xml"
    qDebug()<<qPrintable(firstNode.nodeValue()); // nodeValue 为版本号和恩encoding

    //获取第一个元素,也就是根元素
    QDomElement docElement = doc.documentElement();
    qDebug()<<docElement.tagName();
    //返回根元素的第一个节点
    QDomNode n = docElement.firstChild();

    //如果n不为空
    while(!n.isNull())
    {
        //如果节点是元素
        if(n.isElement())
        {
            QDomElement e = n.toElement();//转换为元素
            //输出元素标记和ID的属性值
            qDebug()<<qPrintable(e.tagName())<<qPrintable(e.attribute("id"));

            //获取元素e的所有子节点列表
            QDomNodeList list = e.childNodes();

            for(int i = 0;i<list.count();++i)
            {
                QDomNode node = list.at(i);
                if(node.isElement())
                {
                    qDebug()<<" "<<qPrintable(node.toElement().tagName())<<qPrintable(node.toElement().text());
                }
            }
        }
        //转到下一个兄弟节点
        n = n.nextSibling();
    }

    return a.exec();
}
