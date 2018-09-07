#ifndef GENEREICFACTORYWIDGET_H
#define GENEREICFACTORYWIDGET_H

#include <QWidget>
#include <QFrame>

class GenericFactoryWidget : public QFrame
{
    Q_OBJECT
public:
    explicit GenericFactoryWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // GENEREICFACTORYWIDGET_H
