#include "widget.h"
#include "ui_widget.h"


#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPushButton>
#include <QTextEdit>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_manager = new QNetworkAccessManager(this);
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        QString str = ui->lineEdit->text();
        startRequest(QUrl(str));
    });



}

Widget::~Widget()
{
    delete ui;
}

void Widget::startRequest(const QUrl &requestUrl)
{
    const QUrl url = requestUrl;
    QNetworkRequest request;
    request.setUrl(url);
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute,true);
    request.setRawHeader("Usr-Agent","macOS/11.5.1 (20G80) CalendarAgent/954");
    request.setRawHeader("Accept","*/*");
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");

    QNetworkReply *reply = m_manager->get(request);

    connect(reply,&QNetworkReply::finished,this,[=]()mutable{
        if(reply->error() == QNetworkReply::NoError)
        {
            //状态码
            int status = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            ui->textEdit->setPlainText(QString::number(status));
            //reason
            QString reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
            ui->textEdit->append(reason);
            reply->deleteLater();
            reply = nullptr;
        }
        else{

            reply->deleteLater();
            reply = nullptr;

        }
    });

}

