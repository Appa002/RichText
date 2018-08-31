#ifndef AOVERLAYABLETEXTEDIT_H
#define AOVERLAYABLETEXTEDIT_H

#include <QTextEdit>
#include <QObject>
#include <QWidget>

class OverlayableTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit OverlayableTextEdit(QWidget *parent = nullptr);
    ~OverlayableTextEdit();

private:
    QString code;

    QString build();

public:

public slots:
    void render();
    void updateInternalRepresentation();
};

#endif // AOVERLAYABLETEXTEDIT_H
