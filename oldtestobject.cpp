#include "oldtestobject.h"
#include <QDebug>
OldTestObject::OldTestObject(const QString &test,QObject *parent)
    : QObject{parent},m_test(test)
{

}


const QString &OldTestObject::getTest() const
{
    return m_test;
}

void OldTestObject::setTest(const QString &newTest)
{
//    qDebug()<<"(OLD)new test: " << newTest;
//    qDebug()<<"(OLD)test: " << m_test;

    if (m_test == newTest)
        return;
    //qDebug()<<"passed verification";

    m_test = newTest;
    emit testChanged();
}

