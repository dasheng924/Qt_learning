#include "widget.h"
#include "ui_widget.h"


#include <QPaintEvent>
#include <QImage>
#include <QPixmap>
#include <QBitmap>
#include <QPicture>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>
#include <QWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QToolTip>





Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //setMouseTracking(true);//开启鼠标跟踪
    //把主界面的背景设置为透明
    setWindowFlags(Qt::FramelessWindowHint);//设置无边框
    setWindowFlags( windowFlags()|Qt::Dialog);
    setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
    setWindowState(Qt::WindowMaximized);//设置窗口最大尺寸








}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    {
    /*

    QPainter painter;

    //绘制image
    QImage image(QSize(100,100),QImage::Format_ARGB32);
    image.fill(Qt::darkGray);
    painter.begin(&image);
    painter.setPen(QPen(Qt::green,3));
    painter.setBrush(Qt::yellow);
    painter.drawRect(10,10,60,60);
    painter.drawText(10,10,60,60,Qt::AlignCenter,QStringLiteral("QImage"));
    painter.setBrush(QColor(0,0,0,100));
    painter.drawRect(50,50,40,40);
    painter.end();


    //绘制pixmap
    QPixmap pix(100,100);//设置pixmap的长度和宽度
    pix.fill(Qt::red);
    painter.begin(&pix);
    painter.setPen(QPen(Qt::green,3));
    painter.setBrush(Qt::yellow);
    painter.drawRect(10,10,60,60);
    painter.drawText(10,10,60,60,Qt::AlignCenter,QStringLiteral("QPixmap"));
    painter.setBrush(QColor(0,0,0,100));
    painter.drawRect(50,50,40,40);
    painter.end();

    //绘制Bitmap
    QBitmap bitmap(100,100);
    bitmap.fill(Qt::red);
    painter.begin(&bitmap);
    painter.setPen(QPen(Qt::green,3));
    painter.setBrush(Qt::yellow);
    painter.drawRect(10,10,60,60);
    painter.drawText(10,10,60,60,Qt::AlignCenter,QStringLiteral("QBitmap"));
    painter.setBrush(QColor(0,0,0,100));
    painter.drawRect(50,50,40,40);
    painter.end();

    //绘制picture
    QPicture picture;
    painter.begin(&picture);
    painter.setPen(QPen(Qt::green,3));
    painter.setBrush(Qt::yellow);
    painter.drawRect(10,10,60,60);
    painter.drawText(10,10,60,60,Qt::AlignCenter,QStringLiteral("QPicture"));
    painter.setBrush(QColor(0,0,0,100));
    painter.drawRect(50,50,40,40);
    painter.end();



    //在widget部件上绘制image
    painter.begin(this);
    painter.drawImage(50,20,image);
    painter.drawPixmap(200,20,pix);
    painter.drawPixmap(50,170,bitmap);
    painter.drawPicture(200,170,picture);
    painter.end();

    */
    }

//    QPainter painter(this);

//    QImage image;
//    //加载一张图片
//    image.load(":/WechatIMG4179.jpeg");
//    //输出图片的一些信息
//    qDebug()<<"图像大小:"<<image.size();
//    qDebug()<<"图像的格式:"<<image.format();
//    qDebug()<<"图像的色彩深度:"<<image.depth();

//    //在界面绘制图片
//    painter.drawImage(QPointF(0,0),image);

//    //获取镜像图片
//    QImage mirror = image.mirrored();//默认垂直镜像
//    //图片进行扭曲
//    QTransform transform;//连续进行多次变换,可以对transform对象操作
//    transform.shear(0.2,0);
//    QImage image2 = mirror.transformed(transform);
//   // painter.drawImage(QPointF(10,160),image2);
//    //将镜像保存到文件
//    image2.save("/Users/sunguosheng/Pictures/mirror.jpeg");

//-----------------------------------------------------------------

//    QPainter painter(this);

//    QPixmap pix;
//    //加载图像
//    pix.load(":/WechatIMG4179.jpeg");
//    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);

//    painter.setBrush(QColor(255,255,255,0));
//    painter.drawRect(0,0,pix.width(),pix.height());


//    QPixmap pix2 = pix.copy(pix.rect());//复制原有图形
//    painter.translate(QPointF(pix.width(),0));
//    painter.drawPixmap(0,0,pix2.width(),pix.height(),pix2);

//    painter.setBrush(QColor(0,0,255,100));
//    painter.drawRect(0,0,pix2.width(),pix2.height());

//-----------------------------------------------------------------


//    QWindow window;
//    QPixmap grab  = window.screen()->grabWindow(QApplication::desktop()->winId(),0,0,-1,-1);

//    grab.save("/Users/sunguosheng/Pictures/desktop.png","png");



    QPainter painter(this);
    QPen pen(Qt::red,2);
    painter.setPen(pen);

    painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
    int step = 10;
    painter.drawLine(currPos.x(),currPos.y()-step,currPos.x(),currPos.y()+step);
    painter.drawLine(currPos.x()-step,currPos.y(),currPos.x()+step,currPos.y());

    painter.setPen(Qt::white);
    painter.drawRect(startPos.x(),startPos.y(),currPos.x()-startPos.x(),currPos.y()-startPos.y());





}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    currPos = QPointF(event->pos());
    QString gloPos = QString("%1,%2").arg(currPos.x()).arg(currPos.y());
    QToolTip::showText(event->pos()-QPoint(20,20),gloPos,this);
    repaint();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    startPos = event->pos();
    update();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    endPos = event->pos();
}



