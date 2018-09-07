#ifndef GENERICFACTORY_H
#define GENERICFACTORY_H

#include <QObject>
#include <QWidget>
#include "app/IExpressionFactory.h"

class GenericFactory : public IExpressionFactory
{
public:
    GenericFactory();
    ~GenericFactory() override;

private:
    QWidget* attachedTo;
public:
    void setup(QWidget* attachTo) override;
    void createWidgets() override;
};

#endif // GENERICFACTORY_H
