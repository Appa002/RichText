#ifndef NULLFACTORY_H
#define NULLFACTORY_H

#include <QObject>
#include <QWidget>
#include "app/IExpressionFactory.h"

class NullFactory : public IExpressionFactory
{
public:
    NullFactory() : IExpressionFactory() {}
    ~NullFactory() override {}

private:
public:
    void setup(QWidget*) override {}
    void createWidgets() override {}
};
#endif // NULLFACTORY_H
