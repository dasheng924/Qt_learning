#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_showBtn_clicked();

    void on_execBtn_clicked();

private:
    Ui::Widget *ui;
    QMessageBox *pm1;
};
#endif // WIDGET_H
