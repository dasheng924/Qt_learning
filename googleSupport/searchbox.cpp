#include <QDesktopServices>
#include <QUrl>

#include "searchbox.h"
#include "gsuggestcompletion.h"

#define GSEARCH_URL "http://www.google.com/search?q=%1"

SearchBox::SearchBox(QWidget *parent): QLineEdit(parent)
{
    completer = new GSuggestCompletion(this);

    connect(this, SIGNAL(returnPressed()),this, SLOT(doSearch()));

    setWindowTitle("Search with Google");

    adjustSize();//大小适应内容
    resize(400, height());
    setFocus();
}

void SearchBox::doSearch()
{
    completer->preventSuggest();
    QString url = QString(GSEARCH_URL).arg(text());
    QDesktopServices::openUrl(QUrl(url));
}

