#include "HeaderExpresion.h"
#include "app/IExpression.h"

#include <QDebug>

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
    QString size;
    switch (contentStruct_->size) {
     case(1):
        size="xx-large";
        break;

    case(2):
        size="x-large";
        break;

    case(3):
        size="large";
        break;

    case(4):
        size="medium";
        break;

    case(5):
        size="small";
        break;

    default:
        qWarning() << "HeaderExpression with size out of range: range: 1-5, size: " << contentStruct_->size;
        size="xx-large";
        break;
    }

    return QString("<span style='font-size:%0; font-weight:600;'>%1</span>")
            .arg(size)
            .arg(contentStruct_->content);
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
