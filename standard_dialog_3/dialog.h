#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QErrorMessage>
#include <QWizardPage>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class QErrorMessage;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QErrorMessage *errMsg;
private:
    Ui::Dialog *ui;

    QWizardPage* createPage1();
    QWizardPage* createPage2();
    QWizardPage* createPage3();

};
#endif // DIALOG_H
