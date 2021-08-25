#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QWidget>
#include <QPaintEvent>

class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintedWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // PAINTEDWIDGET_H
