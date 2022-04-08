 #include <QApplication>

#include "searchbox.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    SearchBox *searchEdit = new SearchBox;
    searchEdit->show();
    return app.exec();
}
