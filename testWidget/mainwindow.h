#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQueue>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toolBox_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    QQueue<QWidget*> tabWidget;
    QQueue<QString> tabText;
    QQueue<QIcon> tabIcon;


};
#endif // MAINWINDOW_H
