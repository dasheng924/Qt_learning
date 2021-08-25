#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QLabel>
#include <QMovie>
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    //void keyPressEvent(QKeyEvent *event) override;
    //void mouseMoveEvent(QMouseEvent *event) override;
signals:


private:
    QMovie *mm;
};

#endif // MYLABEL_H
