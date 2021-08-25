#include "mainwindow.h"

#include <QVariant>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
#if 0
    //标准类型转换为QVariant



    //1.使用构造函数
    int num = 10;
    QVariant v1(num);
    //2.使用成员函数
    QVariant v2;
    v2.setValue(num);
    //使用静态函数
    QVariant v3;
    v3 = QVariant::fromValue(num);

    // 该函数的返回值是一个枚举类型, 可通过这个枚举判断出实际是什么类型的数据
    //Type QVariant::type() const;

    //转换为实际的类型，用to类型方法

    if(v3.type() == QVariant::Int)
    {
        qDebug()<<"Int 类型";
        qDebug()<<v3.toInt();
    }
    else
    {
        qDebug()<<"未知";
    }


#endif

    //使用QVariant 封装自定义类型
   // 1.类声明的位置加入宏 Q_DECLARE_METATYPE(Type)，为的是实现自定义数据类型的构造函数和拷贝构造函数
   //2.
    // 如果当前QVariant对象可用转换为对应的模板类型 T, 返回true, 否则返回false
    //bool QVariant::canConvert() const;
    // 将当前QVariant对象转换为实际的 T 类型
   // T QVariant::value() const;

    MY_TEST t;
    t.age = 10;
    t.name = "alex";
    //值的封装
    QVariant v = QVariant::fromValue(t);

    //值的读取
    if(v.canConvert<MY_TEST>())
    {
        MY_TEST tt = v.value<MY_TEST>();
        qDebug()<<tt.name<<"\t"<<tt.age;
    }







}

MainWindow::~MainWindow()
{

}

