#include "GenericFactory.h"
#include "GenericFactoryWidget.h"
#include <QLayout>

GenericFactory::GenericFactory() : IExpressionFactory ()
{

}

GenericFactory::~GenericFactory()
{

}

void GenericFactory::setup(QWidget *attachedTo)
{
    this->attachedTo = attachedTo;
}

void GenericFactory::createWidgets()
{
    GenericFactoryWidget* widget = new GenericFactoryWidget();

    if(this->attachedTo->layout())
        this->attachedTo->layout()->addWidget(widget);
    else
        widget->setParent(this->attachedTo);

    widget->show();
}
