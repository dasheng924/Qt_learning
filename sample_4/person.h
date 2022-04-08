#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author","sungs")
    Q_CLASSINFO("company","OWN")
    Q_CLASSINFO("version","1.0.0")

    Q_PROPERTY(unsigned age READ age WRITE setAge NOTIFY ageChange)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(unsigned  score MEMBER m_score)


public:
    explicit Person(const QString name,QObject *parent = nullptr);
    unsigned age();
    unsigned score();
    void setAge(unsigned value);
    virtual ~Person();

signals:
    void ageChange(unsigned value);
private:
    unsigned m_age  =10;
    QString  m_name;
    unsigned m_score = 79;

};

#endif // PERSON_H
