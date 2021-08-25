#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "dialog.h"


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
    void on_showDialogBtn_clicked();

private:
    Ui::Widget *ui;
    Dialog *dialog;
};
#endif // WIDGET_H
