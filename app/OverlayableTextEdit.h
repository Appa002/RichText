#ifndef AOVERLAYABLETEXTEDIT_H
#define AOVERLAYABLETEXTEDIT_H

#include <QTextEdit>
#include <QObject>

class OverlayableTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit OverlayableTextEdit(QWidget *parent = nullptr);
    ~OverlayableTextEdit();

private:
    QString codeRepresentation;

    QString build();

public:

public slots:
    void render();
};

#endif // AOVERLAYABLETEXTEDIT_H
