#ifndef COMMANDPALLET_H
#define COMMANDPALLET_H

#include "ExpressionDisplayWidget.h"
#include "ExpressionInputWidget.h"

#include <QObject>
#include <QKeyEvent>
#include <QWidget>
#include <QFrame>
#include <QLayout>

class CommandPallet : public QFrame
{
    Q_OBJECT
public:
    explicit CommandPallet(QWidget *parent = nullptr);

private:
    ExpressionInputWidget* textEnter = nullptr;
    QVBoxLayout* sugestionList = nullptr;
    std::vector<QString> listOfExpressions;
    std::vector<ExpressionDisplayWidget*> displayedExpression;
    size_t markedIndex = 0;

    bool dirty = false;
    bool partialyContains(QString a, QString b);
public:
    void setup(ExpressionInputWidget* textEnter, QVBoxLayout* sugestionList);
signals:

private slots:
    void textChanged();
public slots:
};

#endif // COMMANDPALLET_H
