#ifndef MYWIDGETACTION_H
#define MYWIDGETACTION_H



#include <QWidgetAction>

class QLineEdit;

class MyWidgetAction : public QWidgetAction
{
    Q_OBJECT
public:
    explicit MyWidgetAction(QObject *parent = 0);

protected:
    QWidget * createWidget(QWidget *parent) override;

signals:
    void getText(QString);

private:
    QLineEdit *lineEdit;
};

#endif // MYWIDGETACTION_H
