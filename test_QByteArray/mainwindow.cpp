#include "mainwindow.h"

#include <QDebug>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

#if 0
    //初始化QByteArray
    QByteArray str1 = QByteArray(); //空对象
    QByteArray str2 = QByteArray("hello Qt",-1);//参数二：-1 自动计算字符串的长度，可以指定长度，-1时可省略参数二
    QByteArray str3 = QByteArray("hello Qt",5);
    QByteArray str4 = QByteArray(10,'f');//10个字符'f'

    qDebug()<<str1;
    qDebug()<<str2;
    qDebug()<<str3;
    qDebug()<<str4;


    //增
    //尾插
    str3.append("world");
    qDebug()<<str3;
    str3.push_back("!!!");
    qDebug()<<str3;

    //头插
    str3.prepend("listen to me,");
    str3.push_front("-->");
    qDebug()<<str3;

    //删
    str3.remove(26,3); //pos 开始删除num个
    str3.chop(3); //尾删
    str3.truncate(10);//pos 位置截断，留下前面，去掉后面
    str3.clear();//清空字符数组

    qDebug()<<str3;

    //改
    //替换
    //QByteArray &QByteArray::replace(const QByteArray &before, const QByteArray &after);
    //可以查看对应文档

    //查
    //str1.contains  可以查处包含的字符或者字符数组
    //str1.startsWith 以什么开头
    //str1.endsWith 以什么结尾

    //遍历
    //1.迭代器 begin end
    //2.数组方式遍历 [i] or at(i)


    //查看字节数
    QByteArray x("123456");
    qDebug()<<x.length();
    qDebug()<<x.size();
    qDebug()<<x.count();

    x.prepend("11");
    x.append("26");

    //统计字符/字符串出现的次数
    qDebug()<<x;
    qDebug()<<"字符1出现的次数："<<x.count('1');
    qDebug()<<"字符数组11出现的次数:"<<x.count("11");

#endif

    //转换
    //------------------------------------------------
    //QByteArray ---->char *
//    QByteArray y("123456");

//    char *date = y.data();
//    qDebug()<<date;

    //------------------------------------------------
//    // int, short, long, float, double -> QByteArray

    int n = 62 ; //10进制的63
    qDebug()<<"8进制"<<QByteArray::number(n,8);//"76"
    qDebug()<<"16进制"<<QByteArray::number(n,16);//"3e"

    //和这个静态函数功能相同的是setNum()
    QByteArray xx;
    qDebug()<<"验证和静态函数功能相同的成员函数setNum"<<xx.setNum(n,16);



    //------------------------------------------------
    //QByteArray -> int, short, long, float, double
    QByteArray old("3e");
    int num = old.toInt(nullptr,16) ; //这个写16进制，才会转换为原来的数字
    qDebug()<<num;


    //fromHex()返回十六进制编码数组 hexEncoded 的解码副本。不检查输入的有效性；输入中的无效字符将被跳过，使解码过程能够继续处理后续字符。
    //toHex()返回字节数组的十六进制编码副本。十六进制编码使用数字 0-9 和字母 a-f。
//    QByteArray macAddress = QByteArray::fromHex("123456abcdef") ;
//    qDebug()<<macAddress;//"\x12""4V\xAB\xCD\xEF"
//    qDebug()<<macAddress.toHex(':');//"12:34:56:ab:cd:ef"



    //大小写的转换
    QByteArray xxx("apple");
    qDebug()<<xxx.toUpper();






}

MainWindow::~MainWindow()
{
}

