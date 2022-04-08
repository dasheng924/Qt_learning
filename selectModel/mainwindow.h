#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QTableView;
class QItemSelection;
class QModelIndex;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void getCurrentItemData(); //获取当前项目
    void toggleSelection(); //切换选择
    //更新选择
    void updateSelection(const QItemSelection &selection,const QItemSelection &deselected);
    //改变选择
    void changeCurrent(const QModelIndex &current,const QModelIndex &previous);


private:
    Ui::MainWindow *ui;
    QTableView *tableView;
    QTableView *tableView2;
};
#endif // MAINWINDOW_H
