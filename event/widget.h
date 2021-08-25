#ifndef WIDGET_H
#define WIDGET_H

#include <QCloseEvent>
#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>

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

    void keyPressEvent(QKeyEvent *event) override;

    void closeEvent(QCloseEvent *event) override ;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
