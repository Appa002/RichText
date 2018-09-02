#include "HeaderExpresion.h"
#include "app/IExpression.h"

HeaderExpresion::HeaderExpresion()
{
    this->contentStruct_ = new HeaderExprStruct;
}

HeaderExpresion::~HeaderExpresion()
{
    delete this->contentStruct_;
}

QString HeaderExpresion::info()
{
    return "HeaderExpression, "
           "size: " + QString::number(this->contentStruct_->size) + " , "
            + "pos: " + QString::number(this->pos_) + " , "
            + "content: '" + this->contentStruct_->content + "'";
}

int HeaderExpresion::size()
{
    return this->contentStruct_->content.size();
}

int HeaderExpresion::pos()
{
    return this->pos_;
}

int HeaderExpresion::pos(int val)
{
    this->pos_ = val;
    return val;
}

QString HeaderExpresion::html()
{

    return QString("<h%0> %1 </h%2>")
            .arg(QString::number(contentStruct_->size))
            .arg(contentStruct_->content)
            .arg(QString::number(contentStruct_->size));
}

void *HeaderExpresion::contentStruct()
{
    return this->contentStruct_;
}

void *HeaderExpresion::contentStruct(void *val)
{
    HeaderExprStruct* casted = static_cast<HeaderExprStruct*>(val);
    this->contentStruct_->content = casted->content;
    this->contentStruct_->size = casted->size;

    return this->contentStruct_;
}
