#ifndef MYERRMSGDIALOG_H
#define MYERRMSGDIALOG_H

#include <QErrorMessage>

class MyErrMsgDialog : public QErrorMessage
{
    Q_OBJECT
public:
    explicit MyErrMsgDialog(QErrorMessage *parent = nullptr);



};

#endif // MYERRMSGDIALOG_H
