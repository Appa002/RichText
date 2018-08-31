#include "OverlayableTextEdit.h"

#include <QDebug>

OverlayableTextEdit::OverlayableTextEdit(QWidget *parent) : QTextEdit (parent)
{
}

OverlayableTextEdit::~OverlayableTextEdit()
{
}

QString OverlayableTextEdit::build()
{
    qInfo() << "Bulding text representation...";
    QString out = this->toPlainText();
    int from = -1;
    while( ((void)(from = out.indexOf('$', from + 1)), from) != -1){
        int exprLen = out.indexOf('$', from + 1) - from;
        QString expr = out.mid(from + 1, exprLen - 1);

        qInfo() << "Found expression: " << expr;

        out.replace(from, exprLen + 1, "<h1>" + expr + "</h1>");
        from = out.indexOf('$', from + 1);
    }

    qInfo() << "...Build";
    return out;
}


void OverlayableTextEdit::render()
{
    QString newHtml = build();
    this->clear();
    this->setHtml(newHtml);


    /*int pos = this->textCursor().position();
    QString str = this->toPlainText();


    QString left = str.mid(0, pos);
    QString right = str.mid(pos, str.size() - 1);
    this->clear();
    this->setHtml(left + "<br/>" + right);

    QTextCursor cursor(this->textCursor());
    cursor.movePosition(QTextCursor::MoveOperation::Start, QTextCursor::MoveMode::MoveAnchor, 1);
    cursor.movePosition(QTextCursor::MoveOperation::NextCharacter, QTextCursor::MoveMode::MoveAnchor, pos);
    this->setTextCursor(cursor);*/
}
