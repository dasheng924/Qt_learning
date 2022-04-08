#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QBitmap>
#include <QPicture>
#include <QWindow>
#include <QScreen>
#include <QDesktopWidget>
#include <QDateTime>
#include <QDebug>
#include <QLabel>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //label = new QLabel(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
//    QWindow window;
//    QPixmap desktopPix = window.screen()->grabWindow(QApplication::desktop()->winId(),0,0,-1,-1);

//    label->resize(300,400);
//    QPixmap out = desktopPix.scaled(label->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
//    label->setPixmap(out);
//    label->move(100,100);

#if 0
    QPicture picture;
    QPainter painter;

    painter.begin(&picture) ;//在Painter绘图设备上进行绘制
    painter.drawRect(10,10,300,300);
    painter.drawEllipse(QRect(10,10,300,300));
    painter.end();

    picture.save("/Users/sunguosheng/NewQt/painterPixmap/drawing.pic");
#else
//    QPicture picture;
//    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//    bool ret = picture.load("/Users/sunguosheng/NewQt/painterPixmap/drawing.pic");
//    if(ret)
//        qDebug()<<QString("%1,pic文件加载成功!").arg(currentTime);
//    else
//        qDebug()<<QString("%1,pic文件加载失败!").arg(currentTime);

//    QPainter painter(this);
//    painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);//抗锯齿和平滑的处理
//    painter.setPen(QPen(Qt::darkRed,5));
//    painter.setBrush(Qt::yellow);
//    painter.drawPicture(QPointF(0,0),picture);

#endif

    QPainter painter;
    QImage image(400,300,QImage::Format_ARGB32_Premultiplied);
    painter.begin(&image);

    painter.setBrush(Qt::green);
    painter.drawRect(100,50,200,200); //源图像
    painter.setBrush(QColor(0,0,255,150));
    painter.drawRect(50,0,100,100); //左上角图像,默认SourceOver
    painter.drawText(QRect(50,0,100,100),QPainter::Antialiasing|Qt::AlignCenter,QStringLiteral("SourceOver"));

    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.drawRect(250,0,100,100);
    painter.drawText(QRect(250,0,100,100),QPainter::Antialiasing|Qt::AlignCenter,QStringLiteral("SourceIn"));

    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter.drawRect(50,200,100,100);
    painter.drawText(QRect(50,200,100,100),QPainter::Antialiasing|Qt::AlignCenter,QStringLiteral("DestinationOver"));

    painter.setCompositionMode(QPainter::CompositionMode_Xor);
    painter.drawRect(250,200,100,100);
    painter.drawText(QRect(250,200,100,100),QPainter::Antialiasing|Qt::AlignCenter,QStringLiteral("Xor"));

    painter.end();


    painter.begin(this);
    painter.drawImage(0,0,image);

}
