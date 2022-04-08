#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->btn_in,&QPushButton::clicked,this,&Dialog::btn_in);
    connect(ui->btn_out,&QPushButton::clicked,this,&Dialog::btn_out);


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::btn_in()
{
    accept();
}

void Dialog::btn_out()
{
    reject();
}
