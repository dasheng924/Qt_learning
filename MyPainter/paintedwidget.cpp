#include "paintedwidget.h"

#include <QPainter>
#include <QPixmap>
#include <QBitmap>
#include <QImage>
#include <QPicture>


PaintedWidget::PaintedWidget(QWidget *parent) : QWidget(parent)
{
    resize(800,600);
    setWindowTitle("测试绘图设备");
}

void PaintedWidget::paintEvent(QPaintEvent *event)
{
    //QPainter pp(this);

    /*
    pp.drawLine(QLineF(QPoint(1,3),QPoint(100,300)));


    pp.setPen(Qt::red);
    pp.drawRect(100,200,30,50);

    pp.setPen(QPen(Qt::green,10)); //这个是画边框的
    pp.drawPie(100,200,130,180,190,190);

    pp.setBrush(Qt::blue);
    pp.drawEllipse(50,150,400,200); //这个是填充的

    */

#if 0
    QPixmap p1("/Users/sunguosheng/Pictures/白驹素材站-家电卫浴 (5)/(155).png");
    QBitmap p2("/Users/sunguosheng/Pictures/白驹素材站-家电卫浴 (5)/(155).png");

    //透明色在QBitmap中转换成了黑色；其他颜色则是使用点的疏密程度来体现的。
    pp.drawPixmap(20,30,p1) ;
    pp.drawPixmap(100,200,p2);
#endif


#if 0
    QImage image(200,200,QImage::Format_RGB32);//32位数值表示一个颜色的RGB值，也就是说每种颜色使用8位
    //我们可以把QImage想象成一个RGB颜色的二维数组，记录了每一像素的颜色。

    QRgb value;
    //将图片背景设置成白色背景

    image.fill(Qt::white);

    //改变指定区域的像素点的值
    for(int i=50; i<100; ++i)
    {
        for(int j=50; j<100; ++j)
        {
            value = qRgb(255, 255, 0); // 红色
            image.setPixel(i, j, value);
        }
    }

    //将图片绘制到窗口中
    pp.drawImage(QPoint(0,0), image);

    //QPixmap--->QImage: pixmap.toImage()

    //QImage--->QPixmap:QPixmapfromImage
#endif

#if 0
    pp.drawEllipse(QPoint(50,50),30,30);
    pp.setRenderHint(QPainter::HighQualityAntialiasing); //抗锯齿
    pp.translate(30,80);//移动画家
    pp.drawEllipse(QPoint(50,50),30,30);
#endif

    QPicture pic;
    QPainter ppp(this);
    //将图像绘制到QPicture中,并保存到文件
//    pp.begin(&pic);
//    pp.drawEllipse(20, 20, 100, 50);
//    pp.fillRect(20, 100, 100, 100, Qt::red);
//    pp.end();
//    pic.save("/Users/sunguosheng/Downloads/drawing.pic");


    //将保存的绘图动作重新绘制到设备上
    pic.load("/Users/sunguosheng/Downloads/drawing.pic");
    ppp.begin(this);
    ppp.drawPicture(200, 200, pic);
    ppp.end();


}
