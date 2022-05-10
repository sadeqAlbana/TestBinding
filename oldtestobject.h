#ifndef OLDTESTOBJECT_H
#define OLDTESTOBJECT_H

#include <QObject>

class OldTestObject : public QObject
{
    Q_OBJECT
public:
    explicit OldTestObject(const QString &test, QObject *parent = nullptr);

    const QString &getTest() const;
    void setTest(const QString &newTest);

signals:
    void testChanged();

private:
    Q_PROPERTY(QString test READ getTest WRITE setTest NOTIFY testChanged)
    QString m_test;


};

#endif // OLDTESTOBJECT_H
