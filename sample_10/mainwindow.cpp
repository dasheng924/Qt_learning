#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QSpinBox>
#include <QTextEdit>
#include <QToolButton>
#include <QMdiSubWindow>
#include <QLabel>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include <QLineEdit>
#include "mywidgetaction.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //用来测试QMainWindow
    QMenu *menu = ui->menubar->addMenu("编辑(&E)");
    QAction *action_open = menu->addAction(QIcon(":/images/(210).png"),"打开文件(&O)");
    action_open->setShortcut(QKeySequence("Ctrl+O"));//添加快捷键
    menu->addSeparator(); //菜单中各项的分割线



     // 创建一个动作组，同一个时刻，只能选中一个action
    QActionGroup *group = new QActionGroup(this);
    QAction *actionL = group->addAction("左对齐(&L)");
    actionL->setCheckable(true);
    QAction *actionR = group->addAction("右对齐(&R)");
    actionR->setCheckable(true);
    QAction *actionC = group->addAction("中心对齐(&C)");
    actionC->setCheckable(true);

    actionL->setChecked(true);
    menu->addSeparator();
    menu->addAction(actionL);
    menu->addAction(actionC);
    menu->addAction(actionR);


    //在toolbar上面添加控件
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setText("颜色");

    QMenu *colorMenu = new QMenu(this);
    colorMenu->addAction("红色");
    colorMenu->addAction("绿色");

    toolBtn->setMenu(colorMenu);
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);

    ui->toolBar->addWidget(toolBtn);

    QSpinBox *spinBox = new QSpinBox(this);
    ui->toolBar->addWidget(spinBox);


    //中心区域添加了一个MDI
    menu->addSeparator();
    QAction *action_new = menu->addAction("新建(&N)");
    action_new->setShortcut(QKeySequence("Ctrl+N"));

//    connect(action_new,&QAction::triggered,this,[=](){
//        QTextEdit  *edit = new QTextEdit(this);
//        QMdiSubWindow *subWindow = ui->mdiArea->addSubWindow(edit);
//        subWindow->setWindowTitle("多文档编辑器子窗口");
//        subWindow->show();
//    });

    QAction *action_hideDock = ui->toolBar->addAction(QIcon(":/images/(209).png"),"隐藏Dock栏");
    connect(action_hideDock,&QAction::triggered,this,[=](){

        QString text = action_hideDock->text();

        if(text == "隐藏Dock栏")
        {
            ui->dockWidget->hide();
            action_hideDock->setText("显示Dock栏");
        }
        else
        {
            ui->dockWidget->show();
            action_hideDock->setText("隐藏Dock栏");
        }

    });


    //状态栏的三种显示模式：
    //临时信息：一般的提示信息,showMessage(),状态栏的最左边
    //正常信息：显示页数和行数，addWidget()添加一个QLabel用于显示正常的信息，位于最左边，可能会被临时信息所掩盖
    //永久信息:显示版本号和日期，addPermanentWidget()添加类似于QLabel一样显示信息的部件，位于最右边，不会被临时信息所掩盖


    //临时信息，一般有时间
    ui->statusbar->showMessage("欢迎使用文档编辑器",2000);
    //永久的信息,需要用QLabel来显示
    QLabel *label = new QLabel(this);



    QTimer *timer = new QTimer(this);
    timer->start(1000);

    connect(timer,&QTimer::timeout,this,[=](){
        QString str;
        QDateTime dateTime = QDateTime::currentDateTime();
        str = dateTime.toString("yyyy-M-d h:m:s");
        label->setText(str);

        ui->statusbar->addPermanentWidget(label);
    });



    //在菜单栏上加控件
    MyWidgetAction *myWidgetAction = new MyWidgetAction;

    QMenu *editmenu = ui->menubar->addMenu("TEST");
    editmenu->addAction(myWidgetAction);

    connect(myWidgetAction,&MyWidgetAction::getText,this,[=](QString str){
        ui->textEdit->setText(str);
    });






















    ui->toolBar->addAction(action_open);















}

MainWindow::~MainWindow()
{
    delete ui;
}

