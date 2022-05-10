#include "newtestobject.h"
#include <QDebug>
NewTestObject::NewTestObject(const QString &test, QObject *parent)
    : QObject{parent},m_test(test)
{

}
const QString &NewTestObject::getTest() const
{
    return m_test;
}

void NewTestObject::setTest(const QString &newTest)
{
//    qDebug()<<"(New)new test: " << newTest;
//    qDebug()<<"(New)test: " << m_test;
    m_test = newTest;
}
