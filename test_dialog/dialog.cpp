#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_acceptedBtn_clicked()
{
    this->accept();
}


void Dialog::on_rejectedBtn_clicked()
{
    this->reject();
}

void Dialog::on_finishedBtn_clicked()
{
    this->done(100);
}
