#ifndef COMMANDPALLET_H
#define COMMANDPALLET_H

#include "ExpressionDisplayWidget.h"
#include "ExpressionInputWidget.h"
#include "app/IExpressionFactory.h"
#include "expressionFactory/GenericFactory.h"


#include <QObject>
#include <QKeyEvent>
#include <QWidget>
#include <QFrame>
#include <QLayout>

#include <unordered_map>

class CommandPallet : public QFrame
{
    Q_OBJECT
public:
    explicit CommandPallet(QWidget *parent = nullptr);
    ~CommandPallet();

private:
    ExpressionInputWidget* textEnter = nullptr;
    QWidget* centralWidget;
    QVBoxLayout* sugestionList = nullptr;
    std::vector<QString> listOfExpressions;
    std::vector<ExpressionDisplayWidget*> displayedExpression;
    size_t markedIndex = 0;
    bool dirty = false;
    std::unordered_map<std::string, IExpressionFactory*> name2Factory;

    bool partialyContains(QString a, QString b);
public:
    void setup(ExpressionInputWidget* textEnter, QVBoxLayout* sugestionList, QWidget* centralWidget);
signals:

private slots:
    void textChanged();
    void handleSubmit();

public slots:
};

#endif // COMMANDPALLET_H
