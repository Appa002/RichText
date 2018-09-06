#ifndef EXPRESSIONDISPLAYWIDGET_H
#define EXPRESSIONDISPLAYWIDGET_H

#include "IExpressionFactory.h"

#include <QWidget>
#include <QLabel>
#include <QObject>
#include <QKeyEvent>

class ExpressionDisplayWidget : public QLabel
{
    Q_OBJECT
public:
    explicit ExpressionDisplayWidget(QWidget *parent = nullptr);
    ~ExpressionDisplayWidget();

private:
    QString name_;
    IExpressionFactory* factory_;
    bool marked_ = false;

    void mousePressEvent(QMouseEvent* event);

public:
    QLabel* toLabel();
    QString name();
    QString name(QString val);
    IExpressionFactory* factory();
    IExpressionFactory* factory(IExpressionFactory* val);
    bool underlined();
    bool underlined(bool val);

signals:

private slots:

public slots:
    void creationEvent();

};


#endif // EXPRESSIONDISPLAYWIDGET_H
