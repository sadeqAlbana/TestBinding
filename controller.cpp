#include "controller.h"
#include <QDebug>
#include <QDateTime>
Controller::Controller(QObject *parent)
    : QObject{parent},
      m_oldTestObject(new OldTestObject("old initial",this)),
      m_newTestObject(new NewTestObject("new initial",this)),
    m_bindableOldTestObject(new OldTestObject("old initial",this)),
    m_bindableNewTestObject(new NewTestObject("new initial",this))
{

}

void Controller::createNewObject()
{
    setNewTestObject(new NewTestObject(QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch())));
}

void Controller::createOldObject()
{
    setOldTestObject(new OldTestObject(QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch())));

}

void Controller::createbindableNewObject()
{
    setBindableNewTestObject(new NewTestObject(QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch())));

}

void Controller::createbindableOldObject()
{
    setBindableOldTestObject(new OldTestObject(QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch())));

}

OldTestObject *Controller::oldTestObject() const
{
    return m_oldTestObject;
}

void Controller::setOldTestObject(OldTestObject *newOldTestObject)
{
    if (m_oldTestObject == newOldTestObject)
        return;
    m_oldTestObject = newOldTestObject;
    emit oldTestObjectChanged();
}

NewTestObject *Controller::newTestObject() const
{
    return m_newTestObject;
}

void Controller::setNewTestObject(NewTestObject *newNewTestObject)
{
    if (m_newTestObject == newNewTestObject)
        return;
    m_newTestObject = newNewTestObject;
    emit newTestObjectChanged();
}

OldTestObject *Controller::bindableOldTestObject() const
{
    return m_bindableOldTestObject;
}

void Controller::setBindableOldTestObject(OldTestObject *newBindableOldTestObject)
{
    m_bindableOldTestObject = newBindableOldTestObject;
}

NewTestObject *Controller::bindableNewTestObject() const
{
    return m_bindableNewTestObject;
}

void Controller::setBindableNewTestObject(NewTestObject *newBindableNewTestObject)
{

    m_bindableNewTestObject = newBindableNewTestObject;
}
