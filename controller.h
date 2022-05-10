#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "oldtestobject.h"
#include "newtestobject.h"
class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

    Q_INVOKABLE void createNewObject();
    Q_INVOKABLE void createOldObject();
    Q_INVOKABLE void createbindableNewObject();
    Q_INVOKABLE void createbindableOldObject();

    OldTestObject *oldTestObject() const;
    void setOldTestObject(OldTestObject *newOldTestObject);

    NewTestObject *newTestObject() const;
    void setNewTestObject(NewTestObject *newNewTestObject);

    OldTestObject *bindableOldTestObject() const;
    void setBindableOldTestObject(OldTestObject *newBindableOldTestObject);

    NewTestObject *bindableNewTestObject() const;
    void setBindableNewTestObject(NewTestObject *newBindableNewTestObject);


    QBindable<OldTestObject *> bindablebindableOldTestObject() { return &m_bindableOldTestObject; }
    QBindable<NewTestObject *> bindablebindableNewTestObject() { return &m_bindableNewTestObject; }

signals:

    void oldTestObjectChanged();

    void newTestObjectChanged();

    void bindableOldTestObjectChanged();

    void bindableNewTestObjectChanged();

private:
    OldTestObject *m_oldTestObject;
    NewTestObject *m_newTestObject;

    Q_PROPERTY(OldTestObject *oldTestObject READ oldTestObject WRITE setOldTestObject NOTIFY oldTestObjectChanged)
    Q_PROPERTY(NewTestObject *newTestObject READ newTestObject WRITE setNewTestObject NOTIFY newTestObjectChanged)

    Q_PROPERTY(OldTestObject *bindableOldTestObject READ bindableOldTestObject WRITE setBindableOldTestObject NOTIFY bindableOldTestObjectChanged BINDABLE bindablebindableOldTestObject)
    Q_PROPERTY(NewTestObject *bindableNewTestObject READ bindableNewTestObject WRITE setBindableNewTestObject NOTIFY bindableNewTestObjectChanged BINDABLE bindablebindableNewTestObject)

    Q_OBJECT_BINDABLE_PROPERTY(Controller,
                                  OldTestObject *,
                                  m_bindableOldTestObject,
                                  &Controller::bindableOldTestObjectChanged)

    Q_OBJECT_BINDABLE_PROPERTY(Controller,
                                  NewTestObject *,
                                  m_bindableNewTestObject,
                                  &Controller::bindableNewTestObjectChanged)
};

#endif // CONTROLLER_H
