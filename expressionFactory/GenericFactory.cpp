#include "GenericFactory.h"

#include <QLabel>
#include <QDebug>
#include <QFrame>
#include <QLayout>
#include <QMainWindow>
#include <QApplication>
#include <QWindow>
#include <QResizeEvent>


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

    QPalette pallet;
    pallet.setBrush(QPalette::Window, QBrush(QColor(0x39, 0x39, 0x39)));
    pallet.setBrush(QPalette::WindowText, QBrush(QColor(0xff, 0xff, 0xff)));

    QFrame* frame = new QFrame();
    frame->setAutoFillBackground(true);
    frame->setObjectName("expressionFactoryFrame");
    frame->setPalette(pallet);
    frame->setLayout(new QVBoxLayout());

    QWidget* mainWindow = QApplication::topLevelWidgets()[0];
    QCoreApplication::postEvent(mainWindow, new QResizeEvent(QSize(mainWindow->size().width(), mainWindow->size().height()),
                                                             QSize(mainWindow->size().width(), mainWindow->size().height() + 1)));

    QLabel* label = new QLabel;
    label->setPalette(pallet);
    label->setText("Generic");
    frame->layout()->addWidget(label);

    if(this->attachedTo->layout())
        this->attachedTo->layout()->addWidget(frame);
    else
        frame->setParent(this->attachedTo);

    frame->show();
}
