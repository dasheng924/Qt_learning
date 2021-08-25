#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


struct MY_TEST{
    int age;
    QString name;
};

Q_DECLARE_METATYPE(MY_TEST)


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
