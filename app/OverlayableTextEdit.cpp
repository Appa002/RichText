#include "OverlayableTextEdit.h"
#include "expressions/HeaderExpresion.h"

#include <QDebug>
#include <QKeyEvent>

OverlayableTextEdit::OverlayableTextEdit(QWidget *parent) : QTextEdit (parent)
{
    isDirty = true;
    connect(this, &QTextEdit::textChanged, this, &OverlayableTextEdit::updateUserEnteredText);

    HeaderExpresion* expr = new HeaderExpresion();
    HeaderExprStruct exprStruct;
    exprStruct.content = "OI!";
    exprStruct.size = 1;
    expr->contentStruct(&exprStruct);
    expr->pos(0);

    this->userEnteredText = "Lorem ipsum dolore sid amit. This is text. Did you know that the british spitfire had a huge"
            "engine problem, which made it impossible to do -g manouver, because it would starve the engine.";

    this->expressions.push_back(expr);
}

OverlayableTextEdit::~OverlayableTextEdit()
{
    for(auto& it : this->expressions){
        delete it;
    }
}

QString OverlayableTextEdit::build()
{
    qInfo() << "Bulding text representation...";
    QString out = this->userEnteredText;

    for(auto& expr : this->expressions){
        qInfo() << "Inserting expression: " << expr->info();
        out.insert(expr->pos(), expr->html());
    }

    int from = 0;
    while(((void)(from = out.indexOf('\n', from)), from ) != -1){
        out.replace(from, 1, "<br/>");
    }

    qInfo() << "...Build";
    return out;
}

void OverlayableTextEdit::render()
{
    qInfo() << "Rendering text. Is dirty?: " << this->isDirty;
    QString newHtml = build();
    this->clear();
    this->setHtml(newHtml);
    this->isDirty = false;
}

void OverlayableTextEdit::keyPressEvent(QKeyEvent* event)
{
    QTextEdit::keyPressEvent(event);

/*    if(event->text().size() == 1 && event->key() != 16777219){
        int pos = this->textCursor().position();
        for(auto& expr : expressions){
            if(expr->pos() < pos)
                pos -= expr->size();
        }
        this->userEnteredText.insert(pos - 1, event->text());
    }*/

    if(event->key() != 16777219 || this->isDirty)
       return;

    int pos = this->textCursor().position();
    for(signed long long i = this->expressions.size() - 1; i >= 0; i--){
        size_t idx = static_cast<size_t>(i);
        IExpression* expr = this->expressions.at(idx);

        int lowerBound = expr->pos() + 1;
        int upperBound = expr->pos() + expr->size();

        if(lowerBound <= pos && pos <= upperBound){
            this->expressions.erase(this->expressions.begin() + i);
        }
    }
}

void OverlayableTextEdit::updateUserEnteredText()
{
    if(this->isDirty)
        return;

    int size = this->toPlainText().size();
    for(auto& expr : this->expressions){
        size -= expr->size();
    }

    int pos = this->textCursor().position();
    for(auto& expr : this->expressions){
        if(pos - 1 <= expr->pos()){
            if(this->oldSize < size)
                expr->pos(expr->pos() + 1);
            else
                expr->pos(expr->pos() - 1);
        }
    }

    this->userEnteredText = this->toPlainText();
    for(auto& expr : this->expressions){
        this->userEnteredText.replace(expr->pos(), expr->size(), "");
    }

    this->oldSize = size;
}
