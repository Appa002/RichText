#ifndef IEXPRESSIONFACTORY_H
#define IEXPRESSIONFACTORY_H

#include <QWidget>
#include <QObject>

class IExpressionFactory
{
public:
    virtual ~IExpressionFactory() {};
    virtual void setup(QWidget*) = 0;
    virtual void createWidgets() = 0;

};

#endif // IEXPRESSIONFACTORY_H
