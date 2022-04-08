#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //鼠标左键可以拖动窗口，鼠标左键双击可以放大缩小窗口
    //按着鼠标右键让鼠标变形状
    //滚轮可以放大缩小显式的内容

    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    this->setCursor(cursor);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //先改变鼠标的形状
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        //获取鼠标位置到窗口左上角的差值
        offset = event->globalPos() - pos();
    }
    else if(event->button() == Qt::RightButton)
    {
        QCursor cursor(QPixmap("/Users/sunguosheng/NewQt/sample_10/images/(199).png"));
        QApplication::setOverrideCursor(cursor);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();//恢复鼠标的形状
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton) //鼠标移动的时候会检测所以按下的键
    {
        QPoint tmp;
        tmp = event->globalPos() - offset;
        //event->globalPos() 获取鼠标的全局位置,相当于event->pos()
        move(tmp);
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) //左键双击
    {
        if(this->windowState() != Qt::WindowFullScreen) //如果不是全屏
        {
            this->setWindowState(Qt::WindowFullScreen);
        }
        else
        {
            this->setWindowState(Qt::WindowNoState); //恢复以前的大小
        }
    }


}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0) //远离使用者
    {
        ui->textEdit->zoomIn();
    }
    else
    {
        ui->textEdit->zoomOut();
    }

}

