#include "gsuggestcompletion.h"

#include <QDebug>

#define GSUGGEST_URL "http://google.com/complete/search?output=toolbar&q=%1"

GSuggestCompletion::GSuggestCompletion(QLineEdit *parent): QObject(parent), editor(parent)
{
    popup = new QTreeWidget; //作为一个顶层窗口显示
    popup->setWindowFlags(Qt::Popup);//弹出式的顶层窗口,是模态的
    popup->setFocusPolicy(Qt::NoFocus); //小部件不接受焦点
    popup->setFocusProxy(parent);//焦点代理,也就是popup接受焦点的时候,让焦点转移到QLineEdit
    popup->setMouseTracking(true);//启用了鼠标跟踪,即使没有按下键,也会产生鼠标移动事件

    popup->setColumnCount(1); //1列,treeWidget使用前需要设置列的数量,子节点的层数
    popup->setUniformRowHeights(true);//视图中的项目高度保持一致,参照是第一项的高度
    popup->setRootIsDecorated(false);//是否显示树控件的展开和折叠的控件
    popup->setEditTriggers(QTreeWidget::NoEditTriggers);//项目不可编辑
    popup->setSelectionBehavior(QTreeWidget::SelectRows);//选择时默认选择一行
    popup->setFrameStyle(QFrame::Box | QFrame::Plain);//设置窗体的style,内容周围绘制一个框,没有3D效果
    popup->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//从不显示滚动条
    popup->header()->hide();//隐藏标题

    popup->installEventFilter(this);

    //有一个条目被单击,那么内容就会放到LineEdit里面,然后发送一个returnPressed信号
    connect(popup, SIGNAL(itemClicked(QTreeWidgetItem*,int)),
            SLOT(doneCompletion()));

    timer = new QTimer(this);
    timer->setSingleShot(true); //定时器为一个单次定时器
    timer->setInterval(500);//定时器的间隔时间为0.5秒
    connect(timer, SIGNAL(timeout()), SLOT(autoSuggest()));
    //这个作用就是当你在lineEdit上面写入内容的时候,过0.5秒就会去请求google数据
    connect(editor, SIGNAL(textEdited(QString)), timer, SLOT(start()));

    //数据请求完成之后,回去处理数据
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(handleNetworkData(QNetworkReply*)));

}

GSuggestCompletion::~GSuggestCompletion()
{
    delete popup;
}

bool GSuggestCompletion::eventFilter(QObject *obj, QEvent *ev)
{
    if (obj != popup)
        return false;

    if (ev->type() == QEvent::MouseButtonPress) {
        popup->hide();
        editor->setFocus();
        return true;
    }

    if (ev->type() == QEvent::KeyPress) {

        bool consumed = false;
        int key = static_cast<QKeyEvent*>(ev)->key();
        switch (key) {
        case Qt::Key_Enter:
        case Qt::Key_Return:
            doneCompletion();
            consumed = true;
            break;

        case Qt::Key_Escape:
            editor->setFocus();
            popup->hide();
            consumed = true;
            break;

        case Qt::Key_Up:
        case Qt::Key_Down:
        case Qt::Key_Home:
        case Qt::Key_End:
        case Qt::Key_PageUp:
        case Qt::Key_PageDown:
            break;

        default:
            editor->setFocus();
            editor->event(ev);
            popup->hide();
            break;
        }

        return consumed;
    }

    return false;
}

void GSuggestCompletion::showCompletion(const QStringList &choices)
{

    if (choices.isEmpty())
        return;

    const QPalette &pal = editor->palette();
    QColor color = pal.color(QPalette::Disabled, QPalette::WindowText); //不活跃的前景色

    popup->setUpdatesEnabled(false);//禁用更新,无法接受绘图事件和背景色的设置
    popup->clear();
    for (int i = 0; i < choices.count(); ++i) {
        QTreeWidgetItem * item;
        item = new QTreeWidgetItem(popup);
        item->setText(0, choices[i]);
        item->setTextColor(0, color);//color也就是为了保持颜色一致性
    }
    popup->setCurrentItem(popup->topLevelItem(0));
    popup->resizeColumnToContents(0);
    popup->setUpdatesEnabled(true);
    //也就是起始的位置是lineEdit的左下角
    popup->move(editor->mapToGlobal(QPoint(0, editor->height())));
    popup->setFocus();
    popup->show();
}

void GSuggestCompletion::doneCompletion()
{
    timer->stop();
    popup->hide();
    editor->setFocus();
    QTreeWidgetItem *item = popup->currentItem();
    if (item) {
        editor->setText(item->text(0));

        //调用QLineEdit的returnPressed信号
        QMetaObject::invokeMethod(editor, "returnPressed");
    }
}

//0.5秒把lineEdit中的内容去请求google
void GSuggestCompletion::autoSuggest()
{
    QString str = editor->text();
    QString url = QString(GSUGGEST_URL).arg(str);
    networkManager.get(QNetworkRequest(QString(url)));
}

void GSuggestCompletion::preventSuggest()
{
    timer->stop();
}

void GSuggestCompletion::handleNetworkData(QNetworkReply *networkReply)
{
    QUrl url = networkReply->url();
    if (!networkReply->error()) {
        QStringList choices;

        QByteArray response(networkReply->readAll());
        //-------------------把获得的数据放到一个文件中-----------
        QFile file("/Users/sunguosheng/Downloads/googleSuggestion.xml");
        if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        {
            file.close();
            qDebug()<<"保存google的查询数据失败!";
        }

        file.write(response);
        file.close();

        QXmlStreamReader xml(response); //构建出一个XML
        while (!xml.atEnd()) {
            xml.readNext();
            if (xml.tokenType() == QXmlStreamReader::StartElement)
                if (xml.name() == "suggestion") {
                    QStringRef str = xml.attributes().value("data");
                    choices << str.toString();
                }
        }

        showCompletion(choices);
    }

    networkReply->deleteLater();
}

