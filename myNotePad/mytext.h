#ifndef MYTEXT_H
#define MYTEXT_H

#include <QPlainTextEdit>

class Mytext : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit Mytext(QWidget *parent = nullptr);


protected:
    void dropEvent(QDropEvent *e) override;

signals:

};

#endif // MYTEXT_H
