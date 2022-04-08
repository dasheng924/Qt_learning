#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QtXml>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //构建XML
    QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml","version = \"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction); //添加XML说明

    //添加根元素
    // <书库></书库>
    QDomElement rootElement = doc.createElement("书库");
    doc.appendChild(rootElement);// 添加根元素

    //添加第一个元素及其子元素
    QDomElement book = doc.createElement("图书");
    QDomAttr id = doc.createAttribute("编号");
    QDomElement title = doc.createElement("书名");
    QDomElement author = doc.createElement("作者");

    // <图书 编号=1>    </t图书>
    id.setValue("1");
    book.setAttributeNode(id);


    QDomText text;
    //  <title>Qt</title>
    text = doc.createTextNode("Qt");
    title.appendChild(text);

    //<author>sungs</author>
    text = doc.createTextNode("sungs");
    author.appendChild(text);


    //构建出来层次关系
    book.appendChild(title);
    book.appendChild(author);
    rootElement.appendChild(book);

    //------------------添加第二个图书元素及其子元素--------------------
    book = doc.createElement("图书");
    id = doc.createAttribute("编号");
    title = doc.createElement("书名");
    author = doc.createElement("作者");

    id.setValue("2");
    book.setAttributeNode(id);

    text = doc.createTextNode("Linux");
    title.appendChild(text);
    text = doc.createTextNode("yafei");
    author.appendChild(text);

    book.appendChild(title);
    book.appendChild(author);
    rootElement.appendChild(book);


    QFile file("/Users/sunguosheng/Downloads/QtXml2.xml");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return;
    QTextStream stream(&file);
    doc.save(stream,4);
    file.close();

    connect(ui->findBtn,&QPushButton::clicked,this,[=](){
        doXml("find");

    });

    connect(ui->removeBtn,&QPushButton::clicked,this,[=](){
        doXml("delete");
    });

    connect(ui->updateBtn,&QPushButton::clicked,this,[=](){
        doXml("update");
    });

    connect(ui->addBtn,&QPushButton::clicked,this,[=](){
        ui->listWidget->clear();
        ui->listWidget->addItem("无法添加!");//如果添加失败就会显示

        QFile file("/Users/sunguosheng/Downloads/QtXml2.xml");
        if(!file.open(QIODevice::ReadOnly))
            return;
        QDomDocument doc;
        if(!doc.setContent(&file))
        {
            file.close();
            return;
        }
        file.close();

        QDomElement root = doc.documentElement();
        QDomElement book = doc.createElement("图书");
        QDomAttr id = doc.createAttribute("编号");
        QDomElement title = doc.createElement("书名");
        QDomElement author = doc.createElement("作者");

        //获取最后一个孩子的编号
        QString lastId = root.lastChild().toElement().attribute("编号");
        int count = lastId.toInt()+1;
        id.setValue(QString::number(count));
        book.setAttributeNode(id);


        QDomText text;
        text = doc.createTextNode(ui->bookNameLineEdit->text());
        title.appendChild(text);
        text = doc.createTextNode(ui->authorLineEdit->text());
        author.appendChild(text);

        book.appendChild(title);
        book.appendChild(author);
        root.appendChild(book);

        if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
            return ;

         QTextStream stream(&file);
         doc.save(stream,4);
         file.close();
         ui->listWidget->clear();
         ui->listWidget->addItem("添加成功!");



    });

    connect(ui->showAllBtn,&QPushButton::clicked,this,[=](){
        //先清空显示
        ui->listWidget->clear();
        //记载XML文件,显示出来
        QFile file;
        file.setFileName("/Users/sunguosheng/Downloads/QtXml2.xml");
        if(!file.open(QIODevice::ReadOnly))
            return;

        QDomDocument doc;
        if(!doc.setContent(&file))
        {
            file.close();
            return;
        }
        file.close();

        //获取XML说明
        QDomElement rootElement = doc.documentElement();//根元素
        //获取根元素的第一个节点
        QDomNode n = rootElement.firstChild();

        while(!n.isNull())
        {
            if(n.isElement())
            {
                QDomElement element = n.toElement();
                ui->listWidget->addItem(element.tagName() + element.attribute("编号"));

                QDomNodeList list = element.childNodes();
                for(int i = 0;i<list.count();++i)
                {
                    QDomNode node = list.at(i);
                    if(node.isElement())
                    {
                        ui->listWidget->addItem("   "+node.toElement().tagName()+":"+node.toElement().text());
                    }
                }

            }
            n = n.nextSibling();
        }
    });








}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doXml(const QString operate)
{

    ui->listWidget->clear();
    ui->listWidget->addItem("没有找见相关内容!");

    QFile file("/Users/sunguosheng/Downloads/QtXml2.xml");
    if(!file.open(QIODevice::ReadWrite))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomNodeList list = doc.elementsByTagName("图书");
    //qDebug()<<"图书的节点数量:"<<list.count(); //图书的节点数量: 2
    for(int i = 0;i<list.count();++i)
    {
        QDomNode node = list.at(i);
        QDomElement element = node.toElement();//转化为元素

        if(element.attribute("编号") == ui->bookIdLineEdit->text())
        {
            if(operate == "delete")
            {
                //如果是删除操作
                QDomElement root = doc.documentElement(); //获取根节点
                root.removeChild(node);
                QFile file("/Users/sunguosheng/Downloads/QtXml2.xml");
                if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
                    return;
                QTextStream stream(&file);

                doc.save(stream,4);
                file.close();
                ui->listWidget->clear();
                ui->listWidget->addItem("删除成功!");
            }
            else if(operate == "update")
            {
                QDomNodeList child = node.childNodes(); //判断出来图书节点下面的子节点
                //qDebug()<<"图书节点下面的子节点的个数为:"<<child.count();
                //将它子节点的首个子节点进行更新值
                child.at(0).toElement().firstChild().setNodeValue(ui->bookNameLineEdit->text());
                child.at(1).toElement().firstChild().setNodeValue(ui->authorLineEdit->text());
                QFile file("/Users/sunguosheng/Downloads/QtXml2.xml");
                if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
                    return;
                QTextStream stream(&file);
                doc.save(stream,4);
                file.close();
                ui->listWidget->clear();
                ui->listWidget->addItem("更新成功!");
            }
            else if(operate == "find")
            {
                ui->listWidget->clear();
                ui->listWidget->addItem(element.tagName()+element.attribute("编号"));

                QDomNodeList list = element.childNodes();
                for(int i = 0;i<list.count();++i)
                {
                    QDomNode n = list.at(i);
                    if(n.isElement())
                    {
                        ui->listWidget->addItem("   "+n.toElement().tagName()+n.toElement().text());
                    }
                }

            }
        }
    }
}

