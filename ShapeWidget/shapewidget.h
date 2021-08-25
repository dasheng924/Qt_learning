#ifndef SHAPEWIDGET_H
#define SHAPEWIDGET_H

#include <QWidget>
#include <QTimerEvent>
#include <QObject>

class ShapeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShapeWidget(QWidget *parent = nullptr);
    void goMove();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;



signals:

private:
    QPoint m_pos;

};

#endif // SHAPEWIDGET_H
