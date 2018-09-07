#-------------------------------------------------
#
# Project created by QtCreator 2018-08-29T19:13:45
#
#-------------------------------------------------

QT       += core gui widgets script

TARGET = RichNotes
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES += \
        main.cpp \
        app/mainwindow.cpp \
        app/OverlayableTextEdit.cpp \
    expressions/HeaderExpresion.cpp \
    app/ExpressionDisplayWidget.cpp \
    app/ExpressionInputWidget.cpp \
    app/CommandPallet.cpp \
    expressionFactory/GenericFactory.cpp

HEADERS += \
        app/mainwindow.h \
        app/OverlayableTextEdit.h \
    app/IExpression.h \
    expressions/HeaderExpresion.h \
    expressions/ExpressionStructs.h \
    app/ExpressionDisplayWidget.h \
    app/IExpressionFactory.h \
    app/ExpressionInputWidget.h \
    app/CommandPallet.h \
    expressionFactory/GenericFactory.h \
    expressionFactory/NullFactory.h

FORMS += \
        mainwindow.ui

RESOURCES = resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
