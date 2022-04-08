#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    void btn_in();
    void btn_out();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    void btn_in();
    void btn_out();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
hellohelloappleappleapple