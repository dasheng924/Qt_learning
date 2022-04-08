#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class QNetworkAccessManager;
class QFile;
class QNetworkReply;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void startRequest(const QUrl url);

public slots:
    void httpReadyRead();
    void updateDataReadProgress(qint64,qint64);
    void httpFinished();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QFile *file;
    QUrl url;
    QNetworkReply *reply;

};
#endif // MAINWINDOW_H
