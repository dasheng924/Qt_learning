#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "person.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Person;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

private:
    Person * m_boy;
    Person * m_girl;

public slots:
    void on_spinBox();

};
#endif // WIDGET_H
