#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QMenu>
#include <QTextStream>
#include <QThread>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QListWidget 类提供了一个基于项目的列表小部件。

    test_ListWidget_listMod();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test_ListWidget_listMod()
{
    //测试第一项：添加item元素

    //先设置listWidget的显示模式
    //设置从上到下的列表形式 QListView::ListMode
    //设置从左到右依次的图标样式 QListView::IconMode
    ui->listWidget->setViewMode(QListView::ListMode);
    ui->listWidget->setSpacing(3); //设置图标之间的间距
    //设置QLisView大小改变时，图标的调整模式，默认是固定的，可以改成自动调整
    ui->listWidget->setResizeMode(QListView::Adjust);   //自动适应布局

    //设置列表可以拖动，如果想固定不能拖动，使用QListView::Static
    ui->listWidget->setMovement(QListView::Free);//free 可以拖动




    //添加我们需要的项
    //第一种，构造item对象的时候，直接指定已存在的QListWidget对象
    QListWidgetItem *item1 = new QListWidgetItem("鲁班",ui->listWidget);
    QListWidgetItem *item2 = new QListWidgetItem("后裔",ui->listWidget);
    QListWidgetItem *item3 = new QListWidgetItem("妲己",ui->listWidget);
    QListWidgetItem *item4 = new QListWidgetItem("女娲",ui->listWidget);

    //第二种：先创建好item对象，通过QListWidget的成员函数insertItem添加
    QListWidgetItem *item5  = new QListWidgetItem;
    item5->setText("宫本武藏");
    ui->listWidget->insertItem(ui->listWidget->count(),item5);

    //第三种：直接使用addItem 快速插入列表项
    QListWidgetItem *item6 = new QListWidgetItem("王昭君");
    ui->listWidget->addItem(item6); //addItem 参数可以是QListWidgetItem对象或者是Qlabel对象

    ui->listWidget->addItem(QString("诸葛亮"));


    connect(ui->listWidget,&QListWidget::itemClicked,this,[=](QListWidgetItem *item){
        //获取当前的所有行数
        qint32 count = ui->listWidget->count();
        qDebug()<<"获取当前的所有行数"<<count;

        //获取当前行
        qDebug()<<ui->listWidget->currentRow();

        //获取当前选中的item
        qDebug()<<"获取当前选中的item"<<item->text();

    });

    connect(ui->listWidget,&QListWidget::doubleClicked,this,[=](){
        QString str = ui->listWidget->currentItem()->text();
        QMessageBox::information(this,"info",str);

    });

    //删除item
    //添加一个右键的菜单来删除item
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    //处理右键触发的信号
    connect(ui->listWidget,&QListWidget::customContextMenuRequested,this,[=](const QPoint &point){

        QListWidgetItem *item = ui->listWidget->itemAt(point);

        if(item == NULL)
        {
            qDebug()<<"点击了空白处";
        }
        else{

            int row = ui->listWidget->currentRow();
            ui->listWidget->takeItem(row);
            delete  item;

        }

    });

}

void MainWindow::test_listWidget_iconMod()
{
    //设置QListWidget的显示模式
    ui->listWidget->setViewMode(QListWidget::IconMode);
    //设置图标的大小
    ui->listWidget->setIconSize(QSize(60,60));
    //设置item的大小
    ui->listWidget->setGridSize(QSize(80,80));

    //设置是否拖动
    ui->listWidget->setMovement(QListWidget::Free);
    //设置自适应窗口大小
    ui->listWidget->setResizeMode(QListWidget::Adjust);
    //设置图标之间的间距
    ui->listWidget->setSpacing(10);
    //设置右键菜单的属性
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);


    //加载item

    //读取文件，保存在QStringList

    QString filter = "图片(*.png);;程序文件(*.h *.cpp);;文本文件(*.txt);;所有文件(*.*)";

    QStringList fileList = QFileDialog::getOpenFileNames(this,"选择文件","/Users/sunguosheng/Code/reQt/ListWidget/file_png",filter);

    //qDebug()<<fileList;

    //把这些图片加载到QListWidget

    for(int i = 0;i<fileList.size();++i)
    {
        QFileInfo info (fileList.at(i));
        ui->listWidget->addItem(new QListWidgetItem(QIcon(fileList.at(i)),info.fileName()));
    }




    //右键菜单的完善

    QMenu *menu = new QMenu(this);

    QAction *action_delete = new QAction("删除",this);
    QAction *action_show = new QAction("属性",this);

    menu->addAction(action_show);
    menu->addAction(action_delete);

    connect(ui->listWidget,&QListWidget::customContextMenuRequested,this,[=](const QPoint &point){
        QListWidgetItem *item = ui->listWidget->itemAt(point);
        if(item != NULL)
        {

            menu->exec(QCursor::pos());
        }
    });


    connect(action_delete,&QAction::triggered,this,[=](){
        QListWidgetItem *item  = ui->listWidget->currentItem();
        ui->listWidget->takeItem(ui->listWidget->currentRow());
        delete item;
    });

    connect(action_show,&QAction::triggered,this,[=](){

        QListWidgetItem *item  = ui->listWidget->currentItem();
        QString filePath = "/Users/sunguosheng/Code/reQt/ListWidget/file_png/"+item->text();

        QFileInfo info (filePath);

        QString str = info.fileName();
        str.append(",大小：");
        str.append(QString::number(info.size()));

        qDebug()<<str;

    });




    //双击打开文件
    connect(ui->listWidget,&QListWidget::itemDoubleClicked,this,[=](QListWidgetItem *item){

        ui->plainTextEdit->clear();

        QString filePath = "/Users/sunguosheng/Code/reQt/ListWidget/file_png/"+item->text();

        QFile file(filePath);
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"open file fail!";
            return;
        }

        QTextStream in;
        in.setDevice(&file);

        ui->plainTextEdit->setPlainText(in.readAll());

        file.close();


    });

}


