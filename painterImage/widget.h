#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


class QPointF;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    Ui::Widget *ui;
    QPointF currPos;
    QPoint startPos;
    QPoint endPos;

};
#endif // WIDGET_H
