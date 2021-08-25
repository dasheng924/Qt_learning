/* 1.先绘制出蝴蝶的图片 Qpainter p(this) ;p.drawPixmp(rect(),m_p)
 * 2.定时器里面就是 按照事件变化的加载图片，然后用随机数参与运算，让蝴蝶窗口移动起来
 * 3.鼠标移动事件：根据比列的移动图片，用鼠标控制移动
 *
 */



#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QWidget>
#include <QPaintEvent>
#include <QPixmap>
#include <QTimerEvent>
#include <QEvent>

class ButterFly : public QWidget
{
    Q_OBJECT
public:
    explicit ButterFly(QWidget *parent = nullptr);
    void fly();
    void fly(int,int);

signals:

protected:
    void paintEvent(QPaintEvent *event) override;

    void timerEvent(QTimerEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void enterEvent(QEvent *event) override;

private:
    QPixmap m_p;
    int index = 1;//用来控制图片的编号

    QPoint m_pos;

};

#endif // BUTTERFLY_H
