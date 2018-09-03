#ifndef AOVERLAYABLETEXTEDIT_H
#define AOVERLAYABLETEXTEDIT_H

#include <QTextEdit>
#include <QObject>
#include <QWidget>

#include "IExpression.h"

class OverlayableTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit OverlayableTextEdit(QWidget *parent = nullptr);
    ~OverlayableTextEdit();

private:
    std::vector<IExpression*> expressions;
    QString userEnteredText;
    int oldSize = -1;
    bool isDirty;

    QString build();
    void keyPressEvent(QKeyEvent *event);

public:

private slots:
    void updateUserEnteredText();
public slots:
    void render();
};

#endif // AOVERLAYABLETEXTEDIT_H
