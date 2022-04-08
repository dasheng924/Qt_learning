#include "widget.h"
#include "ui_widget.h"

#include <QHBoxLayout>
#include <QFontComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QWidget * widget = new QWidget;

    QHBoxLayout *hBoxLayout = new QHBoxLayout;

    QFontComboBox * fontComboBox = new QFontComboBox;

    QTextEdit *textEdit = new QTextEdit;

    QPushButton *btn = new QPushButton("隐藏TextEdit");


    hBoxLayout->addWidget(fontComboBox);
    hBoxLayout->setSpacing(50);
    hBoxLayout->addWidget(textEdit);
    hBoxLayout->setSpacing(50);
    hBoxLayout->addWidget(btn);
    hBoxLayout->setContentsMargins(0,0,0,0);

    widget->setLayout(hBoxLayout);
    widget->show();

    widget->setWindowTitle("布局测试");


    connect(fontComboBox,&QFontComboBox::currentTextChanged,textEdit,&QTextEdit::setText);
    connect(btn,&QPushButton::clicked,textEdit,[=](){
        if(btn->text() == "隐藏TextEdit")
        {
            textEdit->hide();
            btn->setText("显示TextEdit");
        }
        else if(btn->text() == "显示TextEdit"){
            textEdit->show();
            btn->setText("隐藏TextEdit");
        }



    });

    this->close();







}

Widget::~Widget()
{
    delete ui;
}

