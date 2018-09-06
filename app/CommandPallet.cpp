#include "CommandPallet.h"

#include <QLayout>
#include <QDebug>

CommandPallet::CommandPallet(QWidget *parent) : QFrame(parent)
{
    this->listOfExpressions = {"Header", "Graph", "Image", "Horizontal Ruler"};
}

bool CommandPallet::partialyContains(QString a, QString b)
{
    while(a.size() != 0){
        if(a.toLower() == b.toLower())
            return true;

        a.remove(a.size() - 1, 1);
    }
    return false;
}

void CommandPallet::setup(ExpressionInputWidget *textEnter, QVBoxLayout *sugestionList)
{
    this->textEnter = textEnter;
    this->sugestionList = sugestionList;

    connect(this->textEnter, &QPlainTextEdit::textChanged, this, &CommandPallet::textChanged);
    connect(this->textEnter, &ExpressionInputWidget::submited, this, &CommandPallet::handleSubmit);
}

void CommandPallet::textChanged()
{

    if(this->textEnter->toPlainText().size() != 0
            && this->textEnter->toPlainText().at(this->textEnter->toPlainText().size() - 1) == '\n')
        return;

    if(this->textEnter->toPlainText().size() != 0
            && this->textEnter->toPlainText().at(this->textEnter->toPlainText().size() - 1) == '\t'){
        if(this->displayedExpression.size() == 0)
            return;

        for(auto& it : this->displayedExpression) {
            it->underlined(false);
        }

        this->markedIndex++;

        if(this->displayedExpression.size() - 1 < this->markedIndex)
            this->markedIndex = 0;

        this->displayedExpression.at(this->markedIndex)->underlined(true);

        QString str = this->textEnter->toPlainText();
        str = str.remove(str.size() - 1, 1);
        this->dirty = true;
        this->textEnter->setPlainText(str);

        QTextCursor cursor = this->textEnter->textCursor();
        cursor.setPosition(this->textEnter->toPlainText().size());
        this->textEnter->setTextCursor(cursor);

        return;
    }

    if(dirty){
        dirty = false;
        return;
    }

    QLayoutItem* item;
    while(((void)(item = this->sugestionList->layout()->takeAt(0)), item) != nullptr){
        delete item->widget();
        delete item;
    }

    std::vector<QString> matchingExpressions;
    for(auto& it : listOfExpressions){
        if(partialyContains(it, textEnter->toPlainText()))
            matchingExpressions.push_back(it);
    }

    this->displayedExpression.clear();
    int size = 0;
    for(auto& it : matchingExpressions){
        ExpressionDisplayWidget* label = new ExpressionDisplayWidget;
        label->name(it);

        this->displayedExpression.push_back(label);
        this->sugestionList->layout()->addWidget(label);
        label->resize(label->width(), 18);
        size+=19;
    }
    this->markedIndex = 0;
    if(this->displayedExpression.size() > 0)
        this->displayedExpression.at(0)->underlined(true);
    this->resize(width(), 82 + size);

}

void CommandPallet::handleSubmit()
{
    if(this->displayedExpression.size() > 0){
        this->displayedExpression.at(this->markedIndex)->creationEvent();
    }
}




