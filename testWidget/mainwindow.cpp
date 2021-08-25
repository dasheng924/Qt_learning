#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QWidget * widget = new QWidget;
    QVBoxLayout * vlayout = new QVBoxLayout;

    for(int i = 0;i<10;++i)
    {
        QLabel * label = new QLabel;
        QString str = QString(":/img/(%1).png").arg(127+i);
        label->setPixmap(QPixmap(str));
        label->setAlignment(Qt::AlignCenter); //对里面的图标设置居中
        vlayout->addWidget(label);
    }

    widget->setLayout(vlayout);

    ui->scrollArea->setWidget(widget);//会自动居中对齐

    //只有重新设置了里面的大小，才需要重新设置剧中
    //ui->scrollArea->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//设置居中

    ui->toolBox->setCurrentIndex(1); //默认显示
//----------------------------
    if(tabWidget.empty())
        ui->ok->setEnabled(false);


    ui->tabWidget->setTabPosition(QTabWidget::North);
    connect(ui->tabWidget,&QTabWidget::tabCloseRequested,[=](int index){

        //获取当前的tab 对象
        QWidget *wg = ui->tabWidget->widget(index);
        QString str = ui->tabWidget->tabText(index);
        QIcon icon = ui->tabWidget->tabIcon(index);


        tabWidget.enqueue(wg);
        tabText.enqueue(str);
        tabIcon.enqueue(icon);

        ui->tabWidget->removeTab(index);
        ui->ok->setEnabled(true);

    });

    connect(ui->tabWidget,&QTabWidget::tabBarClicked,[=](int index){
        qDebug()<<"我被点击了一下,我的标题是"<<ui->tabWidget->tabText(index);

    });

    connect(ui->tabWidget,&QTabWidget::currentChanged,[=](int index){

        qDebug()<<"切换完的tab的标题是:"<<ui->tabWidget->tabText(index);
    });

    connect(ui->ok,&QPushButton::clicked,[=](){

        if(tabWidget.empty()){
            ui->ok->setEnabled(false);
        }
        else if(ui->tabWidget->count() == 4){
            ui->ok->setEnabled(false);
        }
        else{
            ui->tabWidget->addTab(tabWidget.dequeue(),tabIcon.dequeue(),tabText.dequeue());

        }
    });

    //------------------------------stackedWidget

    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->changeBtn,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(rand()%2);

    });




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolBox_currentChanged(int index)
{
    qDebug()<<ui->toolBox->itemText(index);
}



