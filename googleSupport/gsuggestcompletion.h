
#ifndef GOOGLESUGGEST_H
#define GOOGLESUGGEST_H

#include <QtWidgets>
#include <QtNetwork>
#include <QObject>

class QLineEdit;
class QNetworkReply;
class QTimer;
class QTreeWidget;

class GSuggestCompletion : public QObject
{
    Q_OBJECT

public:
    GSuggestCompletion(QLineEdit *parent = 0);
    ~GSuggestCompletion();
    bool eventFilter(QObject *obj, QEvent *ev) override;
    void showCompletion(const QStringList &choices);

public slots:

    void doneCompletion();
    void preventSuggest();
    void autoSuggest();
    void handleNetworkData(QNetworkReply *networkReply);

private:
    QLineEdit *editor;
    QTreeWidget *popup;
    QTimer *timer;
    QNetworkAccessManager networkManager;
};
#endif // GOOGLESUGGEST_H
