#include "GenericFactoryWidget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QFrame>
#include <QResizeEvent>
#include <QApplication>
#include <QWindow>

GenericFactoryWidget::GenericFactoryWidget(QWidget *parent) : QFrame(parent)
{
    QPalette pallet;
    pallet.setBrush(QPalette::Window, QBrush(QColor(0x39, 0x39, 0x39)));
    pallet.setBrush(QPalette::WindowText, QBrush(QColor(0xff, 0xff, 0xff)));

    this->setAutoFillBackground(true);
    this->setObjectName("expressionFactoryFrame");
    this->setPalette(pallet);
    this->setLayout(new QVBoxLayout());

    QLabel* label = new QLabel;
    label->setPalette(pallet);
    label->setText("Generic");
    this->layout()->addWidget(label);


    QSize size = QApplication::topLevelWindows()[0]->size();

    double frameRelativeWidth = 0.8;
    double frameWidth = size.width() * frameRelativeWidth;
    double frameYPos = (size.width() - frameWidth) / 2;

    this->resize(static_cast<int>(frameWidth), this->layout()->sizeHint().height());
    this->move(static_cast<int>(frameYPos), 0);
}
