#include "person.h"

Person::Person(const QString name, QObject *parent) : QObject(parent)
{
    m_name = name;

}

unsigned Person::age()
{
    return m_age;
}

unsigned Person::score()
{
    return m_score;
}

void Person::setAge(unsigned value)
{
    m_age = value;
    emit(ageChange(m_age));
}

Person::~Person()
{

}


