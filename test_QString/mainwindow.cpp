#include "mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

#if 0

// 构造一个空字符串对象
//QString::QString();
QString str1;
// 将 char* 字符串 转换为 QString 类型
//QString::QString(const char *str);
QString str2("apple");
// 将 QByteArray 转换为 QString 类型
//QString::QString(const QByteArray &ba);
QString str3(QByteArray("apple"));

qDebug()<<str1;
qDebug()<<str2;
qDebug()<<str3;


#endif


#if 0
    // 尾部追加数据

    QString x1("apple");
    x1.append(QString("  ok!"));
    x1.push_back("!!");

    // 头部添加数据
    x1.prepend("111");
    x1.push_front("222");


    // 插入数据, 将 str 插入到字符串第 position 个字符的位置(从0开始)

//    QString &QString::insert(int position, const QString &str);
//    QString &QString::insert(int position, const char *str);
//    QString &QString::insert(int position, const QByteArray &str);
    x1.insert(0,"TTT");
    // 删除数据
    // 从大字符串中删除len个字符, 从第pos个字符的位置开始删除
    //QString &QString::remove(int position, int n);
    x1.remove(0,2);
    qDebug()<<x1;

    // 从字符串的尾部删除 n 个字符
//    void QString::chop(int n);
    // 从字节串的 position 位置将字符串截断 (前边部分留下, 后边部分被删除)
//    void QString::truncate(int position);
    // 将对象中的数据清空, 使其为null
//    void QString::clear();

    // 字符串替换
    // 将字节数组中的 子字符串 before 替换为 after
    // 参数 cs 为是否区分大小写, 默认区分大小写

    //QString &QString::replace(const QString &before, const QString &after, Qt::CaseSensitivity cs = Qt::CaseSensitive);
    x1.insert(0,'t');
    x1.replace("T","bbb",Qt::CaseInsensitive); // 默认区分大小写,Qt::CaseInsensitive 不区分大小写
    qDebug()<<x1;


#endif


#if 0
    // 参数 cs 为是否区分大小写, 默认区分大小写
    // 其他重载的同名函数可参考Qt帮助文档, 此处略

    // 判断字符串中是否包含子字符串 str, 包含返回true, 否则返回false
//    bool QString::contains(const QString &str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;

    // 判断字符串是否以字符串 ba 开始, 是返回true, 不是返回false
//    bool QString::startsWith(const QString &s, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;

    // 判断字符串是否以字符串 ba 结尾, 是返回true, 不是返回false
//    bool QString::endsWith(const QString &s, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;



    //----------------------遍历---------------------
    // 使用迭代器
//    iterator QString::begin();
//    iterator QString::end();

    // 使用数组的方式进行遍历
    // i的取值范围 0 <= position < size()
//    const QChar QString::at(int position) const
//        const QChar QString::operator[](int position) const;

//-----------------------查看字节-----------------------
    // 返回字节数组对象中字符的个数 (字符个数和字节个数是不同的概念)
//    int QString::length() const;
//    int QString::size() const;
//    int QString::count() const;

    // 返回字节串对象中 子字符串 str 出现的次数
    // 参数 cs 为是否区分大小写, 默认区分大小写
    //int QString::count(const QStringRef &str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const;



#endif


#if 1

    //转换
    //QString ---->QByteArray
    QString str("apple");

    QByteArray ret;
    ret = str.toUtf8();
    qDebug()<<ret;
    ret = str.toLocal8Bit();
    qDebug()<<ret;
    //ret = str.toLatin1();不支持中文

    QString xx = QString("I Love %1,%2,%3").arg("apple").arg("orange").arg("pair");
    qDebug()<<xx;




#endif





}

MainWindow::~MainWindow()
{
}

