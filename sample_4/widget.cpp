#include "widget.h"
#include "ui_widget.h"

#include <QMetaClassInfo>
#include <QSpinBox>
#include <QDebug>
#include <QMetaProperty>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->BoyspinBox->setProperty("IsBoy",true);
    ui->GirlspinBox->setProperty("IsBoy",false);

    m_boy = new Person("王小明",this);
    m_boy->setProperty("name","王小明");
    m_boy->setProperty("age",m_boy->age());
    m_boy->setProperty("score",m_boy->score());
    m_girl = new Person("赵小娟",this);
    m_girl->setProperty("name","赵小娟");
    m_girl->setProperty("age",m_girl->age());
    m_girl->setProperty("score",m_girl->score());


    ui->plainTextEdit->setPlaceholderText("输出信息在这里显示");

    ui->BoyspinBox->setValue(m_boy->age());
    ui->GirlspinBox->setValue(m_girl->age());

    connect(ui->BoyIncBtn,&QPushButton::clicked,this,[=](){

        m_boy->setAge(m_boy->age()+1);
    });

    connect(ui->GirlIncBtn,&QPushButton::clicked,this,[=](){

        m_girl->setAge(m_girl->age()+1);
    });

    connect(m_boy,&Person::ageChange,this,[=](int val){
        ui->BoyspinBox->setValue(val);
        QString str = QString("name=%1,age=%2,score=%3\n").arg(m_boy->property("name").toString() \
        ).arg(m_boy->property("age").toUInt()).arg(m_boy->property("score").toUInt());

        ui->plainTextEdit->appendPlainText(str);
    });

    connect(m_girl,&Person::ageChange,this,[=](int val){
        ui->GirlspinBox->setValue(val);

        QString str = QString("name=%1,age=%2,score=%3\n").arg(m_girl->property("name").toString() \
        ).arg(m_girl->property("age").toUInt()).arg(m_girl->property("score").toUInt());

        ui->plainTextEdit->appendPlainText(str);
    });


    // static_cast<void(QSpinBox::*)(const QString &)>(&QSpinBox::valueChanged)
    auto p = static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged) ;
    connect(ui->BoyspinBox,p,this,&Widget::on_spinBox);

    connect(ui->GirlspinBox,p,this,&Widget::on_spinBox);







    connect(ui->MetaInfoBtn,&QPushButton::clicked,this,[=](){

        Person p("",this);
        QString name_0 = p.metaObject()->classInfo(0).name();
        QString value_0 = p.metaObject()->classInfo(0).value();
        QString name_1 = p.metaObject()->classInfo(1).name();
        QString value_1 = p.metaObject()->classInfo(1).value();
        QString name_2 = p.metaObject()->classInfo(2).name();
        QString value_2 = p.metaObject()->classInfo(2).value();

        QString str = QString("------->类的信息<-------\n") +
                      name_0+"-->"+value_0+"\n"+ \
                      name_1+"-->"+value_1+"\n"+ \
                      name_2+"-->"+value_2+"\n";

        ui->plainTextEdit->appendPlainText(str);



//        QString BoyInfo = "姓名="+m_boy->property("name").toString() + ",年龄="+QString::number(m_boy->property("age").toUInt()) + ",score="+QString::number(m_boy->property("score").toUInt());
//        QString GirlInfo = "姓名="+m_girl->property("name").toString() + ",年龄="+QString::number(m_girl->property("age").toUInt()) + ",score="+QString::number(m_girl->property("score").toUInt());
//        QString strr = QString("------->属性信息<-------\n") ;
//        strr += BoyInfo+"\n"+GirlInfo;
//        ui->plainTextEdit->appendPlainText(strr);

        const QMetaObject *meta = m_girl->metaObject();
        for(int i = meta->propertyOffset();i<meta->propertyCount();++i)
        {
            QMetaProperty prop =  meta->property(i);
            const char * propName = prop.name();
            QString propValue = m_girl->property(propName).toString();
            qDebug()<<propName<<"\t"<<propValue;
        }


    });



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_spinBox()
{

    QSpinBox * p = static_cast<QSpinBox*>(sender()); //获取到信号的发送者
    qDebug()<<p;

    if(p->property("IsBoy").toBool())
        m_boy->setAge(ui->BoyspinBox->value());
    else
        m_girl->setAge(ui->GirlspinBox->value());
}

