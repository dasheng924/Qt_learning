### 1.设置窗口的属性

```c++
    //去边框
    setWindowFlags( windowFlags()| Qt::FramelessWindowHint);
    //窗口透明
    setAttribute(Qt::WA_TranslucentBackground);
    //最大化
    showMaximized();

```

### 2.生成随机数

```C++
    #include <QRandomGenerator>
     num = QRandomGenerator::global()->bounded(10,20);//10~19
     num = QRandomGenerator::global()->bounded(10);//0~9

```

### 3.获取屏幕的长度属性

```c++

    #include <QDesktopWidget> //获取屏幕对象，QApplication::desktop()
    #include <QApplication>

    QDesktopWidget * desk = QApplication::desktop(); //获得屏幕的对象
    desk->screenGeometry().right() //right() 屏幕最右边的边

```

### 4.鼠标右键菜单

```c++
if(event->button() == Qt::RightButton)
    {
        QMenu menu;
        QAction * action = menu.addAction("关闭");


        connect(action,&QAction::triggered,this,[=](){
            this->parentWidget()->close();
        }) ;

        menu.exec(QCursor::pos()); //关键的步骤
    }
```



### 5.获取程序执行时间

```c++
#include <QElapsedTimer>
 timer->start();
 int milSec = timer->elapsed(); //获取到 上一次start的时间
```



### 6.认识自定义类型

```c++
qRegisterMetaType<QVector<int>>("QVector<int>"); //让认识自定义类型
```



### 7.Action设置图标和标题。同时设置快捷键

```c++
openAction = new QAction(QIcon(":/images/file-open"),tr("&Open..."), this);
openAction->setShortcuts(QKeySequence::Open); //设置快捷键
openAction->setStatusTip(tr("Open an existing file")); //设置提示
```



### 8.QLineEdit 和 QLabel

```c++
 //QLabel显示链接
    QLabel * label = new QLabel(this);
    label->setText("hello world");
    label->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
    label->setOpenExternalLinks(true);


    //QLabel 显示GIF
    QLabel * label2 = new QLabel(this);
    QMovie * movie = new QMovie("/Users/sunguosheng/Downloads/test.gif");
    movie->start();
    label2->setMovie(movie);
    label2->move(300,300);
    label2->resize(200,200);
    movie->setScaledSize(label2->size());

    //QLabel显示图片
    QPixmap p("/Users/sunguosheng/Pictures/QQ20201028-0.jpg");
    QLabel *label3 = new QLabel(this);
    label3->move(500,100);
    label3->setPixmap(p.scaled(500,500));
    label3->resize(500,500);


    //QLineEdit
    QLineEdit * lineEdit = new QLineEdit(this);
    //lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    lineEdit->resize(500,30);
    lineEdit->move(200,20);
    //lineEdit->setTextMargins(10,0,0,0);//设置距离边框的像素值

    //设置输入提示
    QStringList list;
    list<<"hello world"<<"hood"<<"hog"<<"hpple"<<"very good";
    QCompleter * completer = new QCompleter(list,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);//不区分大小写
    completer->setFilterMode(Qt::MatchContains); //设置字符串其中某一部分匹配

    lineEdit->setCompleter(completer);

```



### 9.信号重载的使用

```c++
connect(spinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
    [=](int i){ /* ... */ });


connect(spinBox, static_cast<void(QSpinBox::*)(const QString &)>(&QSpinBox::valueChanged),
        [=](const QString &text){ /* ... */ });
```



### 10.事件处理函数的使用

```c++
void Widget::mouseMoveEvent(QMouseEvent *event)
{

    QString str;
    str.sprintf("<center><h1>Release: (%d, %d)</h1></center>",event->x(),event->y());
    this->setMouseTracking(true);//按下鼠标一次，其余的时候都可以追踪
    this->setWindowTitle(str);
}

bool Widget::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);//转化为键盘事件
        if(keyEvent->key() == Qt::Key_Tab)
        {
            qDebug()<<"你按下了Tab键"                    ;
        }
        return true;
    }
    return QWidget::event(event);
}

bool FilterObject::eventFilter(QObject *object, QEvent *event)
{
    if (object == target && event->type() == QEvent::KeyPress) 
{
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Tab) {
            qDebug() << "You press tab.";
            return true;
        } else {
            return false;
        }
    }
    return false;
}
```

### 11.事件处理的不同方法

```c++
1.基本的事件处理函数，鼠标按压，键盘按压
  
2.所有对象的事件分发：event函数，这里面可以对一类的事件进行处理，在QObject 和QWidget 中实现，要重写虚函数
  
3.在特定对象上安装事件过滤器，这个过滤的效果只在这个对象上是有用的
  
4.在QCoreApplication::instance()上面安装事件过滤器。该过滤器将过滤所有对象的所有事件，因此和notify()函数一样强大，但是它更灵活，因为可以安装多个过滤器。全局的事件过滤器可以看到 disabled 组件上面发出的鼠标事件。全局过滤器有一个问题：只能用在主线程。
  
5.重写QCoreApplication::notify()函数。这是最强大的，和全局事件过滤器一样提供完全控制，并且不受线程的限制。但是全局范围内只能有一个被使用（因为QCoreApplication是单例的）。

  
  1.开始事件循环之后，事件就会放入事件队列，调用QCoreApplication::notify() 进行事件的派发，派发也就是派发到指定的窗口。
  2.在派发到这个窗口的过程当中，就可以用事件过滤器进行过滤，QObject::eventFilter()进行事件的过滤，这个事件过滤器需要先安装事件过滤器，这个安装可以安装到一般的控件上面，也可以用QCoreApplication::instance()进行全局的安装，这个全局的安装效果等同于QCoreApplication::notify() ，但会让程序的效率减慢。
  3.当事件发送到指定的窗口之后，就会用QWidget::event()进行事件的分发，分发是根据事件的类型进行分发，比如键盘按压事件，鼠标事件等
  4.当在分发器中根据事件类型分发完成之后，就开始调用对应的事件处理函数来进行事件的处理。
  
  事件派发 -> 事件过滤->事件分发->事件处理
  
  
accept() -->该函数的作用是让窗口接受传递过来的事件，事件不会向上层窗口（父窗口）传递。
ignore() -->该函数的作用是让窗口忽略传递过来的事件，事件被传递给父窗口（向上传递）。
  
  设置传递过来的事件是被接受还是被忽略
setAccepted(true) == accept()
setAccepted(false) == ignore()

  
  bool QWidget::event(QEvent *ev)
{
    switch(ev->type())
    {
    // 鼠标移动
    case QEvent::MouseMove:		
        mouseMoveEvent((QMouseEvent*)event);
        break;
    // 鼠标按下
    case QEvent::MouseButtonPress:	
        mousePressEvent((QMouseEvent*)event);
        break;
    // 鼠标释放
    case QEvent::MouseButtonRelease:	
        mouseReleaseEvent((QMouseEvent*)event);
        break;
    // 鼠标双击
    case QEvent::MouseButtonDblClick:	
        mouseDoubleClickEvent((QMouseEvent*)event);
        break;
    // 键盘按键被按下事件
    case QEvent::KeyPress:
        break;
        ...
        ...
        ...
    default:
        break;
    }
}


如果传入的事件已被识别并且处理，则需要返回 true，否则返回 false。如果返回值是 true，那么 Qt 会认为这个事件已经处理完毕，不会再将这个事件发送给其它对象，而是会继续处理事件队列中的下一事件。

在event()函数中，调用事件对象的 accept() 和 ignore() 函数是没有作用的，不会影响到事件的传播。
Qt 默认值是accept()接受事件；QWidget的默认处理动作是 ignore()

//-------------------这样窗口就收不到鼠标的单击和双击的事件了---------
  bool MainWindow::event(QEvent *ev)
{
    if(ev->type() == QEvent::MouseButtonPress ||
            ev->type() == QEvent::MouseButtonDblClick)
    {
        // 过滤调用鼠标按下的事件
        return true;
    }
    return QWidget::event(ev); //保证其他事件按照默认的分发流程进行分发，并最终被窗口处理掉。
}


//-------------------------事件过滤器举例-------------------------
给 QTextEdit 安装事件过滤器，基于 QTextEdit 的父窗口对这个控件的事件进行过滤
   bool eventFilter(QObject *watched, QEvent *event); //不是虚函数，不需要重写这个类

//---------
//基于 QTextEdit 的父窗口对这个控件的事件进行过滤
//在要进行事件过滤的类中（filterObj 参数对应的类）重写从QObject类继承的虚函数eventFilter()。

ui->textEdit->installEventFilter(this); //构造函数里面的操作

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    // 判断对象和事件
    if(watched == ui->textEdit && event->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEv = (QKeyEvent*)event;
        if(keyEv->key() == Qt::Key_Enter ||         // 小键盘确认
                keyEv->key() == Qt::Key_Return)     // 大键盘回车
        {
            qDebug() << "我是回车, 被按下了...";
            return true;
        }
    }
    return false;
}

--》通过这样的处理，事件在被应用程序对象发送出去之后，进入到对应的窗口之前就被其父窗口过滤掉了。
  
  注意事项：

事件过滤器和被安装过滤器的组件必须在同一线程，否则，过滤器将不起作用。另外，如果在安装过滤器之后，这两个组件到了不同的线程，那么，只有等到二者重新回到同一线程的时候过滤器才会有效。

```



### 12.抗锯齿

```c++
pp.drawEllipse(QPoint(50,50),30,30);
    pp.setRenderHint(QPainter::HighQualityAntialiasing); //抗锯齿
    pp.translate(30,80);//移动画家
    pp.drawEllipse(QPoint(50,50),30,30); 

```



### 13.mysql 服务操作

```sql
sudo /usr/local/mysql/support-files/mysql.server stop  // 停止
sudo /usr/local/mysql/support-files/mysql.server start // 启动
sudo /usr/local/mysql/support-files/mysql.server restart // 重启
```

