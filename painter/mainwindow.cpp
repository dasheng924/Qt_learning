#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QRect>
#include <QPen>
#include <QList>
#include <QPoint>
#include <QGradient>
#include <QTime>
#include <QDateTime>
#include <QTimer>
#include <QFont>
#include <QFontInfo>
#include <QTextOption>
#include <QFontMetrics>
#include <QFontDatabase>
#include <QDebug>
#include <QPainterPath>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer,&QTimer::timeout,this,[=](){
        // update();
    });

//    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    m_angle = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    {
#if  0
    //初始化painter
    QPainter painter(this); //在MainWindow上面绘制
    painter.drawLine(QPoint(0,0),QPoint(200,200));//窗口的左上角开始绘制

#else
//    QPainter painter;
//    painter.begin(this);

//    painter.drawLine(100,20,400,300);

//    painter.end();

#endif
//    //创建画笔
//    QPen pen(QBrush(Qt::red,Qt::Dense1Pattern),5,Qt::DashLine,Qt::RoundCap,Qt::RoundJoin);
//    //使用画笔
//    QPainter painter(this);
//    painter.setPen(pen);
//    //画圆弧
//    QRectF rect(70.0,40.0,800.0,600.0);
//    painter.drawArc(rect,30*16,120*16);

//    //重新设置画笔
//    pen.setWidth(5);
//    pen.setStyle(Qt::SolidLine);
//    //设置给画家
//    painter.setPen(pen);
//    //绘制一个矩形
//    painter.drawRect(100,200,100,80);
//    //---------------------------------
//    QBrush brush;
//    brush.setColor(QColor(0,0,255));
//    brush.setStyle(Qt::Dense4Pattern);
//    painter.setBrush(brush);
//    painter.drawEllipse(200,20,50,50);

//    //设置画刷的纹理
//    brush.setTexture(QPixmap(":/(128).png"));
//    //重新使用画刷
//    painter.setBrush(brush);
//    //绘制四边形
//    static const QPointF points[4] =
//    {
//        QPointF(270.0,80.0),
//        QPointF(290.0,10.0),
//        QPointF(350.0,30.0),
//        QPointF(390.0,70.0)
//     };

//    painter.drawPolygon(points,4,Qt::WindingFill);


//    painter.fillRect(QRect(255,255,200,100),QBrush(Qt::green));


//    //线性渐变
//    QLinearGradient lineGradient(QPointF(40,190),QPointF(70,190));
//    //插入颜色
//    lineGradient.setColorAt(0,Qt::yellow);
//    lineGradient.setColorAt(0.3,Qt::darkYellow);
//    lineGradient.setColorAt(0.5,Qt::green);
//    lineGradient.setColorAt(1,Qt::red);
//    //渐变区域以外的区域扩散方式
//    //梯度在梯度区域外重复。
//    lineGradient.setSpread(QGradient::RepeatSpread);

//    QPainter painter(this);
//    painter.setBrush(lineGradient);
//    painter.drawEllipse(100,100,80,80);


//    //辐射渐变
//    QRadialGradient radialGradient(QPointF(300,190),60,QPointF(275,200));
//    radialGradient.setColorAt(0,QColor(255,255,100,150));
//    radialGradient.setColorAt(0.5,QColor(255,123,25,100));
//    radialGradient.setColorAt(1,QColor(0,0,0,50));
//    painter.setBrush(radialGradient);
//    painter.drawEllipse(QPointF(300,190),60,60);


//    //锥型渐变
//    QConicalGradient conicalGradient(QPointF(400,300), 60);
//    conicalGradient.setColorAt(0.2, Qt::cyan);
//    conicalGradient.setColorAt(0.9, Qt::black);
//    painter.setBrush(conicalGradient);
//    painter.drawEllipse(QPointF(400, 300), 50, 50);


//    //线性渐变画直线
//    painter.setBrush(lineGradient);

//    painter.drawLine(200,300,399,400);

//    //画文字
//    QFont font;
//    font.setPointSize(30);
//    painter.setFont(font);
//    painter.drawText(320,350,"hello Qt");


//    QPainter painter(this);
//    QPen pen(Qt::red,2);
//    painter.setPen(pen);

//    painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
//    painter.drawLine(10,40,300,30);


//    QPainter painter(this);
//    QPen pen(Qt::darkRed,3);
//    painter.setPen(pen);
//    painter.setRenderHints(QPainter::SmoothPixmapTransform|QPainter::Antialiasing);
//    //painter.drawLine(200,200,300,200);
//    painter.drawEllipse(QPointF(200,200),120,120);
//    painter.setBrush(Qt::darkRed);
//    painter.drawEllipse(QPointF(200,200),5,5);
//    painter.drawLine(200,80,200,90); //12
//    painter.drawLine(320,200,310,200); //3
//    painter.drawLine(200,320,200,310); //6
//    painter.drawLine(80,200,90,200); //9


//    painter.translate(200,200);



//    m_angle += 6;
//    if(m_angle == 360)
//        m_angle = 0;
//    painter.rotate(m_angle);//正数顺时针,负数逆时针
//    painter.drawLine(0,0,100,0);
//    painter.drawLine(100,0,90,5);
//    painter.drawLine(100,0,90,-5);


//    QPainter painter(this);
//    painter.setPen(Qt::blue);
//    painter.drawRect(0,0,50,50);




//    int side = qMin(width() ,height());
//    painter.setViewport((width()-side)/2,(height()-side)/2,side,side);
//    painter.setWindow(-50,-50,100,100);
//    painter.setPen(Qt::red);
//    painter.drawRect(0,0,20,20);



//    painter.drawText(rect(),QStringLiteral("你好,我的客人"));//绘制的起点是(0,0)
//    painter.drawText(100,100,QStringLiteral("你好,世界"));
//    painter.drawText(200,200,QStringLiteral("good idea"));

//    painter.drawText(rect(),Qt::AlignCenter,QStringLiteral("happy"));
//    painter.drawText(100,100,100,100,Qt::AlignVCenter,QStringLiteral("ABCDEFGHI"));


//    QTextOption option(Qt::AlignLeft|Qt::AlignVCenter);//对齐方式
//    option.setWrapMode(QTextOption::WordWrap);//开启换行
//    option.setTextDirection(Qt::LeftToRight);//左到右

//    painter.rotate(10);
//    painter.drawText(QRectF(20,20,150,150),QStringLiteral("你好,陌生人!"),option);
    //painter.drawText(rect(), QStringLiteral("老是不知道今天是星期几,应该挑一个日子,去吃火锅."), option);


//    QPainter painter(this);
//    //设置画笔颜色
//    painter.setPen(QPen(Qt::red,3));

//    resize(100,100);


//    QFontDatabase fdb;
//    QStringList fontList = fdb.families(QFontDatabase::SimplifiedChinese);
//    qDebug()<<fontList;

//    QFont font;
//    font.setFamily(".PingFang SC");//设置字体
//    font.setBold(true);//加粗
//    font.setItalic(true);//斜体
//    font.setWeight(12);//字重
//    font.setPointSize(16);//字体大小
//    font.setCapitalization(QFont::SmallCaps);//首字母大写
//    font.setLetterSpacing(QFont::AbsoluteSpacing,20);//按照像素值增大间距

//    painter.setFont(font);


//    QFontInfo info = painter.fontInfo();//获取字体信息
//    qDebug()<<info.family();
//    qDebug()<<info.weight();

//    QTextOption option;
//    option.setAlignment(Qt::AlignVCenter|Qt::AlignLeft);
//    option.setWrapMode(QTextOption::WrapAnywhere);


//    QString str = QStringLiteral("ABCDEFGHIJKLMNOPQRST");
////    QFontMetrics fm = painter.fontMetrics();
////    QString out = fm.elidedText(str,Qt::ElideRight,500,Qt::TextShowMnemonic);
//    painter.drawText(rect(),str,option);



    }



    QLinearGradient myGradient(QPointF(0,0),QPointF(800,800));
    myGradient.setColorAt(0,Qt::green);
    myGradient.setColorAt(0.2,Qt::darkYellow);
    myGradient.setColorAt(1,Qt::darkGreen);

    QPen myPen(Qt::darkRed,5);

    QPainterPath myPath;
    myPath.cubicTo(QPointF(100,100),QPointF(400,600),QPointF(300,240));
    myPath.closeSubpath();



    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
    painter.setBrush(myGradient);
    painter.setPen(myPen);
    painter.drawPath(myPath);

//    QPainterPath path;
//    path.addRect(20, 20, 60, 60);

//    path.moveTo(0, 0);
//    path.cubicTo(99, 0,  50, 50,  99, 99);
//    path.cubicTo(0, 99,  50, 50,  0, 0);

//    QPainter painter(this);
//    painter.fillRect(0, 0, 100, 100, Qt::white);
//    painter.setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
//                        Qt::FlatCap, Qt::MiterJoin));
//    painter.setBrush(QColor(122, 163, 39));
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawPath(path);



















}

