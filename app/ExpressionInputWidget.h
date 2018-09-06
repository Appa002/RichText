#ifndef EXPRESSIONINPUTWIDGET_H
#define EXPRESSIONINPUTWIDGET_H

#include <QPlainTextEdit>
#include <QObject>
#include <QWidget>

#include <QEvent>
#include <QKeyEvent>

class ExpressionInputWidget : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit ExpressionInputWidget(QWidget* parent = nullptr);
    ~ExpressionInputWidget();

private:
    void keyPressEvent(QKeyEvent* event);

signals:
    void submited();


};

#endif // EXPRESSIONINPUTWIDGET_H
