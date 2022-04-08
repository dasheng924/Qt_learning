#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QObject>
#include <QLineEdit>
#include <QWidget>
#include <QKeyEvent>
#include <QEvent>


class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event) override;
    bool event(QEvent *event) override;

};

#endif // MYLINEEDIT_H
