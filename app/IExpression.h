#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include <QString>

class IExpression
{
public:
    IExpression() {}
    virtual ~IExpression() {}

public:
    virtual QString info() = 0;

    virtual int size() = 0;

    virtual int pos() = 0;
    virtual int pos(int val) = 0;

    virtual QString html() = 0;

    virtual void* contentStruct() = 0;
    virtual void* contentStruct(void* val) = 0;
};

#endif // IEXPRESSION_H
