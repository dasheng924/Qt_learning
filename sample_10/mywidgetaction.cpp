#include "mywidgetaction.h"
#include <QLabel>
#include <QLineEdit>
#include <QSplitter>


MyWidgetAction::MyWidgetAction(QObject *parent):QWidgetAction(parent)
{
    lineEdit = new QLineEdit;
    connect(lineEdit,&QLineEdit::returnPressed,this,[=](){
        emit getText(lineEdit->text());
        lineEdit->clear();
    });

}


//重写createWidget()
QWidget *MyWidgetAction::createWidget(QWidget *parent)
{
    if(parent->inherits("QMenu") || parent->inherits("QToolBar"))
    {
        QSplitter *splitter = new QSplitter(parent);
        QLabel *label = new QLabel;
        label->setText("插入文本");
        splitter->addWidget(label);
        splitter->addWidget(lineEdit);

        return splitter;
    }
    return 0;
}
