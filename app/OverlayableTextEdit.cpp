#include "OverlayableTextEdit.h"
#include "expressions/HeaderExpresion.h"

#include <QDebug>
#include <QKeyEvent>

OverlayableTextEdit::OverlayableTextEdit(QWidget *parent) : QTextEdit (parent)
{
    HeaderExpresion* expr = new HeaderExpresion();
    HeaderExprStruct exprStruct;
    exprStruct.content = "OI!";
    exprStruct.size = 1;
    expr->contentStruct(&exprStruct);
    expr->pos(10);

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
    QString out = this->toPlainText();
    int from = -1;

    for(auto& expr : this->expressions){
        qInfo() << "Inserting expression: " << expr->info();
        out.insert(expr->pos(), expr->html());
    }

    from = 0;
    while(((void)(from = out.indexOf('\n', from)), from ) != -1){
        out.replace(from, 1, "<br/>");
    }

    qInfo() << "...Build";
    return out;
}

void OverlayableTextEdit::render()
{
    QString newHtml = build();
    this->clear();
    this->setHtml(newHtml);
    qDebug() << this->toHtml();
}

void OverlayableTextEdit::keyPressEvent(QKeyEvent* event)
{
    QTextEdit::keyPressEvent(event);

   if(event->key() != 16777219)
       return;

    int pos = this->textCursor().position();
    for(signed long long i = this->expressions.size() - 1; i >= 0; i--){
        size_t idx = static_cast<size_t>(i);
        IExpression* expr = this->expressions.at(idx);

        int lowerBound = expr->pos();
        int upperBound = expr->pos() + expr->size();


        if(lowerBound <= pos && pos <= upperBound){
            this->expressions.erase(this->expressions.begin() + i);
            qDebug("did the thing");
        }
    }
}









