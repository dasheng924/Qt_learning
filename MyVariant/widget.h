#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>


struct Person{
    QString name;
    int age;
};




Q_DECLARE_METATYPE(Person) //自定义类型，需要加这个宏

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
    void testVariant();//验证QVariant的使用
    void testDateTime();//验证时间日期
    void testTimer();//定时器类


    void mousePressEvent(QMouseEvent *event) override;






};
#endif // WIDGET_H
