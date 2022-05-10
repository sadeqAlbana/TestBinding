#ifndef NEWTESTOBJECT_H
#define NEWTESTOBJECT_H

#include <QObject>
#include <QProperty>
class NewTestObject : public QObject
{
    Q_OBJECT
public:
    explicit NewTestObject(const QString &test,QObject *parent = nullptr);

    const QString &getTest() const;
    void setTest(const QString &newTest);
       QBindable<QString> bindableTest() { return &m_test; }

signals:
    void testChanged();

private:
    Q_PROPERTY(QString test READ getTest WRITE setTest NOTIFY testChanged BINDABLE bindableTest)
    Q_OBJECT_BINDABLE_PROPERTY(NewTestObject,
                                  QString,
                                  m_test,
                                  &NewTestObject::testChanged)
};



#endif // NEWTESTOBJECT_H
