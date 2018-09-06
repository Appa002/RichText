#include "ExpressionInputWidget.h"
#include <QKeyEvent>
#include <QDebug>

ExpressionInputWidget::ExpressionInputWidget(QWidget* parent) : QPlainTextEdit(parent)
{
    if(parent){
        this->setPalette(parent->palette());
    }
}

ExpressionInputWidget::~ExpressionInputWidget()
{

}

void ExpressionInputWidget::keyPressEvent(QKeyEvent *event)
{
    QPlainTextEdit::keyPressEvent(event);
    if(event->key() == Qt::Key::Key_Return){
        emit submited();
        this->clear();
    }

}
