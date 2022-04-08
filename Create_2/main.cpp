#include "ui_dialog.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    QDialog w;


    /*
    QLabel label(&w);
    label.setText(QObject::tr("hello"));
     */


    /*
    namespace Ui {
    class Dialog: public Ui_Dialog {};
}
     */
    Ui::Dialog ui; //Ui::Dialog 这个Ui命名空间下的Dialog ,这个就是Ui_Dialog
    ui.setupUi(&w); //生成界面,选择的模板就是Dialog,以Dialog的对象作为参数
    //上面的ui的操作相当于上面注释起来的
    //也就是用拖控件的形式替代了上面手写控件的形式
    /*
     *  可以看一下Qt默认生成的ui_dialog.h文件中 setupUi的参数
     *   void setupUi(QDialog *Dialog)
     *
     */


    w.show();


    return a.exec();
}
