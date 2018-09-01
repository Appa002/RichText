#ifndef HEADEREXPRESION_H
#define HEADEREXPRESION_H

#include "app/IExpression.h"
#include "expressions/ExpressionStructs.h"

class HeaderExpresion : public IExpression
{
public:
    HeaderExpresion();
    virtual ~HeaderExpresion() override;

private:
    HeaderExprStruct* contentStruct_;
    int pos_;

public:
    virtual QString info() override;

    virtual int size() override;

    virtual int pos() override;
    virtual int pos(int val) override;

    virtual QString html() override;

    virtual void* contentStruct() override;
    virtual void* contentStruct(void* val) override;
};

#endif // HEADEREXPRESION_H
