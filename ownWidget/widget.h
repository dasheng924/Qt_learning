#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QObject>


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
    void mouseMoveEvent(QMouseEvent *event) override;
    bool event(QEvent *event) override;//对TAB键做拦截
    bool eventFilter(QObject *watch,QEvent * event) override;
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
