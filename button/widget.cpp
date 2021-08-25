#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QColorDialog>
#include <QToolButton>
#include <QRadioButton>
#include <QCheckBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    testToolBtn();

    testRadioBtn();
    //默认选中
    ui->manRadio->setChecked(true);

    count = 0;
    testCheckBox();


}



Widget::~Widget()
{
    delete ui;
}

void Widget::testPushBtn()
{
    //普通的按钮
    ui->pushButton->setText("普通按钮");
    ui->pushButton->setIcon(QIcon(":/img/(127).png"));
    ui->pushButton->setIconSize(QSize(30,30));
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        qDebug()<<"我被点击了";
    });

    //check 属性的按钮
    ui->pushButton_2->setCheckable(true); //打开check属性
    connect(ui->pushButton_2,&QPushButton::toggled,[=](bool ok){
        if(ok){
            qDebug()<<"我被持续选中了!";
        }
        else{
            qDebug()<<"我被取消了！";
        }
    });

    //按钮关联菜单
    ui->menubtn->setText("你最喜欢的颜色");
    QMenu * menu = new QMenu;

    menu->addAction("红色");
    menu->addAction("绿色");
    menu->addAction("黑色");

    //直接这样添加，不可以关联到动作
    QAction * action = new QAction("五颜六色");
    menu->addAction(action);

    connect(action,&QAction::triggered,[=](){

        QColor currColor=QColorDialog::getColor();
        QString colorStr=currColor.name(QColor::HexRgb);
        QMessageBox::information(this,"info",colorStr);
        qDebug()<<"red="<<currColor.red()<<"\tgreen="<<currColor.green()<<"\tblue="<<currColor.blue()<<"\talpha="<<currColor.alpha();
    });

    ui->menubtn->setMenu(menu); //这个可以设置延迟显示，这样就会有切换的动画

    connect(ui->menubtn,&QPushButton::clicked,[=](){
        ui->menubtn->showMenu();
    });

}

void Widget::testToolBtn()
{
    //toolButton和PushButton的区别：主要就是在关联菜单的时候，toolButton可以设置弹出的菜单的属性，以及在显示图标的时候可以设置更多的样式
    QMenu * menu = new QMenu;
    menu->addAction("open");
    menu->addAction("save");
    menu->addAction("setting");


    ui->toolButton->setMenu(menu);
    //设置弹出的状态
/*
弹出菜单的弹出模式是一个枚举类型: QToolButton::ToolButtonPopupMode, 取值如下:
    - QToolButton::DelayedPopup:
        - 延时弹出, 按压工具按钮一段时间后才能弹出, 比如:浏览器的返回按钮
        - 长按按钮菜单弹出, 但是按钮的 clicked 信号不会被发射
        - 短按就会触发clicked 信号，不会弹出菜单
    - QToolButton::MenuButtonPopup:
        - 在这种模式下，工具按钮会显示一个特殊的箭头，表示有菜单。
        - 当按下按钮的箭头部分时，将显示菜单。按下按钮部分发射 clicked 信号
    - QToolButton::InstantPopup:
        - 当按下工具按钮时，菜单立即显示出来。
        - 在这种模式下，按钮本身的动作不会被触发(不会发射clicked信号）
*/

    ui->toolButton->setPopupMode(QToolButton::InstantPopup);
    //设置按钮的箭头
    //这个箭头会替换掉文字和图标
    //ui->toolButton->setArrowType(Qt::UpArrow);
    //设置按钮的样式
    //ui->toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //setDefaultAction 这个用于对话框的按钮


    connect(ui->toolButton,&QToolButton::clicked,[=](){

        qDebug()<<"clicked";
    });




}

void Widget::testRadioBtn()
{
    //用容器来设置分组
    //同一组中，只有一个可以选中
    //默认是没有选中的

    //setChecked 可以设置默认选中

    connect(ui->manRadio,&QRadioButton::clicked,[=](){
        qDebug()<<"男";

    });

    connect(ui->womanRadio,&QRadioButton::clicked,[=](){
        qDebug()<<"女";
    });
}



void Widget::testCheckBox()
{
    ui->checkBox_all->setTristate(true);


    connect(ui->checkBox1,&QCheckBox::stateChanged,[=](int s){
        statusShow(s);

    } );
    connect(ui->checkBox2,&QCheckBox::stateChanged,[=](int s){
        statusShow(s);
    } );
    connect(ui->checkBox3,&QCheckBox::stateChanged,[=](int s){
       statusShow(s);

    } );
    connect(ui->checkBox4,&QCheckBox::stateChanged,[=](int s){
       statusShow(s);
    } );

    connect(ui->checkBox_all,&QCheckBox::stateChanged,[=](int state){
        if(state == Qt::Checked){
            ui->checkBox1->setChecked(true);
            ui->checkBox2->setChecked(true);
            ui->checkBox3->setChecked(true);
            ui->checkBox4->setChecked(true);
        }
        else if(state == Qt::Unchecked){
            ui->checkBox1->setChecked(false);
            ui->checkBox2->setChecked(false);
            ui->checkBox3->setChecked(false);
            ui->checkBox4->setChecked(false);
        }
    });


}


void Widget::statusShow(int s)
{/*
    QCheckBox * ch = (QCheckBox*)sender();
    QString str = ch->text();
*/

    if(s == Qt::Checked)
    {
        count++;
    }
    else if(s == Qt::Unchecked)
    {
        count--;
    }

    if(count ==4)
    {
        ui->checkBox_all->setCheckState(Qt::Checked);
    }
    else if(count == 0)
    {
        ui->checkBox_all->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_all->setCheckState(Qt::PartiallyChecked);
    }


}

