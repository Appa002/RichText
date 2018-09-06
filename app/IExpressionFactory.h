#ifndef IEXPRESSIONFACTORY_H
#define IEXPRESSIONFACTORY_H

#include <QObject>

class IExpressionFactory : public QObject
{
    Q_OBJECT
public:
    explicit IExpressionFactory(QObject *parent = nullptr);

private:
public:
    virtual void createWidgets() = 0;

signals:

public slots:
};

#endif // IEXPRESSIONFACTORY_H
