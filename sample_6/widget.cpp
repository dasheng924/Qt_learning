#include "widget.h"
#include "ui_widget.h"

#include <QValidator>
#include <QDebug>
#include <QCompleter>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("LineEdit的设置");

    ui->comboBox->addItem(QString("Normal"));
    ui->comboBox->addItem(QString("NoEcho"));
    ui->comboBox->addItem(QString("Password"));
    ui->comboBox->addItem(QString("PasswordEchoOnEdit"));


    //ui->lineEdit_1->setReadOnly(true);
    ui->lineEdit_2->setText(">AA-90-bb-! aa\\# H");


    //方法1:
    //auto p = static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged) ;
    //方法2:
    void (QComboBox::*pp)(int) = &QComboBox::currentIndexChanged;

    connect(ui->comboBox,pp,this,[=](int index){
        Q_UNUSED(index)
        QString echoMode = ui->comboBox->currentText();
        //ui->lineEdit_1->setText(echoMode);
        QLineEdit::EchoMode mode ;
        if(echoMode == "Normal")
            mode = QLineEdit::Normal;
        else if(echoMode == "NoEcho")
            mode = QLineEdit::NoEcho;
        else if(echoMode == "Passwprd")
            mode = QLineEdit::Password;
        else
            mode = QLineEdit::PasswordEchoOnEdit;

        ui->lineEdit_1->setEchoMode(mode) ;
    });


     //输入掩码
    connect(ui->lineEdit_2,&QLineEdit::returnPressed,this,[=](){

        QString mask = ui->lineEdit_2->displayText();
        ui->lineEdit_1->setInputMask(mask);
    });
    
    
    


    //输入验证
    //验证器 validator
    QValidator *validator = new QIntValidator(100,999,this);
    ui->lineEdit_3->setValidator(validator);

    qDebug()<<validator->locale().name();


    //自动补全
    QStringList list;
    list<<"hello"<<"help"<<"good head"<<"hexo" ;
    QCompleter *completer = new QCompleter(list,this);

    completer->setCaseSensitivity(Qt::CaseInsensitive);

    ui->lineEdit_4->setCompleter(completer);
    









}

Widget::~Widget()
{
    delete ui;
}

