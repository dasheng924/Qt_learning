#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QComboBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //直接构造
    //构造QTabWidget对象，设置为10行，5列
    //QTableWidget *tableWidget = new QTableWidget(10,5); //10行5列


    //先有对象，再去设置对应的属性
    //下面的方法也是可以的
//    QTableWidget *tableWidget2 = new QTableWidget;
//    tableWidget2->setRowCount(10);
//    tableWidget2->setColumnCount(5);


    //设置标题
    this->setWindowTitle("表格测试!");
    //设置大小
   //ui->tableWidget->resize(350,200);

    //==========================列的设置==========================
    ui->tableWidget->setColumnCount(5);//设置5列

    //设置表头内容
    QStringList header;
    header<<"姓名"<<"性别"<<"年龄"<<"学号"<<"平均成绩";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    //设置表头不可点击,默认点击是进行排序
    ui->tableWidget->horizontalHeader()->setSectionsClickable(false);
    //设置表头是可以移动位置的
    ui->tableWidget->horizontalHeader()->setSectionsMovable(true);
    //设置表头的字体
    QFont font = ui->tableWidget->horizontalHeader()->font();
    font.setBold(true); //也就是先获取原有字体，然后加粗，然后再设置
    ui->tableWidget->horizontalHeader()->setFont(font);
    //设置列的宽度
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(300);

    //ui->tableWidget->horizontalHeader()->resizeSection(0, 150); //设置表头第一列的宽度为150
    //ui->tableWidget->horizontalHeader()->setFixedHeight(40);    //设置表头的高度
    //设置列宽策略，使列自适应宽度，所有列平均分来填充空白部分
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //设置列表头的样式
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

    //==========================行的设置==========================
    //设置10行
    ui->tableWidget->setRowCount(10);
    //设置行的高度
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    //设置垂直头不可见，不显示行号
    ui->tableWidget->verticalHeader()->setVisible(true);//是否隐藏表头

    //设置行宽策略，使列自适应宽度，所有列平均分来填充空白部分
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //设置行表头的样式
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");



    //==========================整体的设置==========================
    //ui->tableWidget->setFrameShape(QFrame::NoFrame); //设置无边框
    //ui->tableWidget->setShowGrid(false); //设置不显示格子线

    //ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);   //设置不可选择
    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);//设置多个选中
    /*
QAbstractItemView::NoSelection 不能选择

QAbstractItemView::SingleSelection 选中单个目标

AbstractItemView::MultiSelection 选中多个目标

QAbstractItemView::ExtendedSelection QAbstractItemView::ContiguousSelection 的区别不明显，主要功能是正常情况下是单选，但按下Ctrl或Shift键后，可以多选

     */
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems); //整行选中的方式
    /*
Constant  Value  Description
QAbstractItemView::SelectItems  0  Selecting single items.选中单个单元格
QAbstractItemView::SelectRows  1  Selecting only rows.选中一行
QAbstractItemView::SelectColumns  2  Selecting only columns.选中一列
     */
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    /*
QAbstractItemView::NoEditTriggers  0  不能对表格内容进行修改
QAbstractItemView::CurrentChanged  1  任何时候都能对单元格修改
QAbstractItemView::DoubleClicked  2  双击单元格
QAbstractItemView::SelectedClicked  4  单击已选中的内容
QAbstractItemView::EditKeyPressed  8  Editing starts when the platform edit key has been pressed over an item.
QAbstractItemView::AnyKeyPressed  16  按下任意键就能修改
QAbstractItemView::AllEditTriggers  31 以上条件全包括
    */


    //单元格里面可以加入控件
//    QComboBox *comboBox = new QComboBox();
//    comboBox->addItem("Y");
//    comboBox->addItem("N");
//    ui->tableWidget->setCellWidget(0,0,comboBox);


     //==========================单元格的设置==========================

    //单元格设置字体颜色和背景
    QTableWidgetItem *item = new QTableWidgetItem("Apple");
    item->setBackgroundColor(QColor(0,60,10));
    item->setTextColor(QColor(100,120,100));
    item->setFont(QFont("Helvetica"));
    ui->tableWidget->setItem(0,0,item);

    //设置单元格对齐方式
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    /*
Constant Value Description
Qt.AlignLeft 0x0001 Aligns with the left edge.
Qt.AlignRight 0x0002 Aligns with the right edge.
Qt.AlignHCenter 0x0004 Centers horizontally in the available space.
Qt.AlignJustify 0x0008 Justifies the text in the available space.

Constant Value Description
Qt.AlignTop 0x0020 Aligns with the top.
Qt.AlignBottom 0x0040 Aligns with the bottom.
Qt.AlignVCenter 0x0080 Centers vertically in the available space.

    */





    //所有的单元格设置字体
    ui->tableWidget->setFont(QFont("Helvetica"));

    //单元格的合并
    //ui->tableWidget->setSpan(0,0,3,1);

    //设置单元格的大小
    //ui->tableWidget->setColumnWidth(1,50); //第二列设置为50的高度
   // ui->tableWidget->setRowHeight(0,50);//第1行设置为50的高度

    ui->tableWidget->resizeColumnsToContents();//列的大小与内容相匹配
    ui->tableWidget->resizeRowsToContents();




    //获取单元格的内容,信号  itemClicked (QTableWidgetItem *)
    connect(ui->tableWidget,&QTableWidget::itemClicked,this,[=](QTableWidgetItem *item){
        qDebug()<<item->text();

    });


    //动态的对数据进行插入
    for(int i = 0;i<10;++i)
    {
        int rowNum = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowNum);

        //新建item
        QTableWidgetItem *item1 = new QTableWidgetItem;
        QTableWidgetItem *item2 = new QTableWidgetItem;
        QTableWidgetItem *item3 = new QTableWidgetItem;
        QTableWidgetItem *item4 = new QTableWidgetItem;
        QTableWidgetItem *item5 = new QTableWidgetItem;

        //设置字体显示风格：居中
        item1->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item2->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item3->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item4->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item5->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);


        //header<<"姓名"<<"性别"<<"年龄"<<"学号"<<"平均成绩";
        item1->setText(QString("name%1").arg(i));
        item2->setText(QString("sex%1").arg(i));
        item3->setText(QString("age%1").arg(i));
        item4->setText(QString("id%1").arg(i));
        item5->setText(QString("score%1").arg(i));



        //设置item
        ui->tableWidget->setItem(rowNum, 0, item1);
        ui->tableWidget->setItem(rowNum, 1, item2);
        ui->tableWidget->setItem(rowNum, 2, item3);
        ui->tableWidget->setItem(rowNum, 3, item4);
        ui->tableWidget->setItem(rowNum, 4, item5);


    }

    //循环清空行
    for(int i = 0; i < 10; ++i)
    {
        //参数为0，不是i，自动delete里面的item
        ui->tableWidget->removeRow(0);
    }






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test_tabWidget1()
{
    //表头相关设置
    //设置列数, 3列：排名、文件名、下载量
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(500); //设列的宽度

    //设置表头不可点击（默认点击后进行排序）
    ui->tableWidget->horizontalHeader()-> setSectionsClickable(false);


    //设置表头内容
    QStringList header;
    header.append("排名");
    header.append("文件名");
    header.append("下载量");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    //设置字体
    QFont font = ui->tableWidget->horizontalHeader()->font(); //获取表头原来的字体
    font.setBold(true);//字体设置粗体
    ui->tableWidget->horizontalHeader()->setFont(font);

    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40); //设置处垂直方向高度
    //ui->tableWidget->setFrameShape(QFrame::NoFrame); //设置无边框
    //ui->tableWidget->setShowGrid(false); //设置不显示格子线
    ui->tableWidget->verticalHeader()->setVisible(false); //设置垂直头不可见，不自动显示行号
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);   //设置不可选择
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    //ui->tableWidget->horizontalHeader()->resizeSection(0, 150); //设置表头第一列的宽度为150
    //ui->tableWidget->horizontalHeader()->setFixedHeight(40);    //设置表头的高度

    //通过样式表，设置表头背景色
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");


    //设置列宽策略，使列自适应宽度，所有列平均分来填充空白部分
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    //动态插入行， 10行
    for(int i = 0; i < 10; ++i)
    {
        int rowCount = ui->tableWidget->rowCount(); //获取表单行数
        ui->tableWidget->insertRow(rowCount); //插入新行

        //新建item
        QTableWidgetItem *item1 = new QTableWidgetItem;
        QTableWidgetItem *item2 = new QTableWidgetItem;
        QTableWidgetItem *item3 = new QTableWidgetItem;

        //设置字体显示风格：居中
        item1->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item2->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item3->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);

        //排行
        //字体大写
        QFont font;
        font.setPointSize(15); //设置字体大小
        item1->setFont( font ); //设置字体
        item1->setText(QString::number(i+1));

        //文件名
        item2->setText( QString("file%1%2%3.mp4").arg(i).arg(i).arg(i));

        //下载量
        item3->setText(QString::number(1024-i));


        //设置item
        ui->tableWidget->setItem(rowCount, 0, item1);
        ui->tableWidget->setItem(rowCount, 1, item2);
        ui->tableWidget->setItem(rowCount, 2, item3);
    }

    //循环清空行
    for(int i = 0; i < 10; ++i)
    {
        //参数为0，不是i，自动delete里面的item
        //ui->tableWidget->removeRow(0);
    }

}

