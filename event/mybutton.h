#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QEvent>
#include <QMouseEvent>
#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>

class MyButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);

protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

signals:
    void clicked();

private:
    QPixmap p;

};

#endif // MYBUTTON_H
