#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QObject>

class SmallWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SmallWidget(QWidget *parent = nullptr);

signals:

private:
    QSlider * slider;
    QSpinBox * spinBox;

};

#endif // SMALLWIDGET_H
