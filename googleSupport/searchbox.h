 #ifndef SEARCHBOX_H
#define SEARCHBOX_H

#include <QLineEdit>

class GSuggestCompletion;

class SearchBox: public QLineEdit
{
    Q_OBJECT

public:
    SearchBox(QWidget *parent = 0);

protected slots:
    void doSearch();

private:
    GSuggestCompletion *completer;
};

#endif // SEARCHBOX_H
