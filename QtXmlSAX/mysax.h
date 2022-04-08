#ifndef MYSAX_H
#define MYSAX_H


#include <QXmlDefaultHandler>

class QListWidget;
class MySAX : public QXmlDefaultHandler
{

public:
    MySAX();
    ~MySAX();
    bool readFile(const QString &filename);
protected:
    bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts) override;
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName) override;
    bool characters(const QString &ch) override;
    bool fatalError(const QXmlParseException &exception) override;
private:
    QListWidget *list;
    QString currentText;
};

#endif // MYSAX_H
