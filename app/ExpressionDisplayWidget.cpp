#include "ExpressionDisplayWidget.h"
#include <QAction>
#include <QDebug>

ExpressionDisplayWidget::ExpressionDisplayWidget(QWidget *parent) : QLabel(parent)
{
    if(parent){
        this->setPalette(parent->palette());
    }
    this->setTextFormat(Qt::RichText);
}

ExpressionDisplayWidget::~ExpressionDisplayWidget()
{
}

void ExpressionDisplayWidget::mousePressEvent(QMouseEvent *event)
{
    QLabel::mousePressEvent(event);
    creationEvent();
}

void ExpressionDisplayWidget::creationEvent()
{
    qDebug() << "OI! : " << this->name_;
    factory_->createWidgets();
}

QLabel *ExpressionDisplayWidget::toLabel()
{
    return this;
}

QString ExpressionDisplayWidget::name()
{
    return this->name_;
}

QString ExpressionDisplayWidget::name(QString val)
{
    this->name_ = val;
    this->setText(this->name_);
    return this->name_;
}

IExpressionFactory *ExpressionDisplayWidget::factory()
{
    return this->factory_;
}

IExpressionFactory *ExpressionDisplayWidget::factory(IExpressionFactory *val)
{
    this->factory_ = val;
    return this->factory_;
}

bool ExpressionDisplayWidget::underlined()
{
    return this->marked_;
}

bool ExpressionDisplayWidget::underlined(bool val)
{
    if(val == true){
        this->setText("<u>" + this->name_ + "</u>");
    }else
        this->setText(this->name_);

    this->marked_ = val;
    return this->marked_;
}



