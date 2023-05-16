#include "delimiters.h"

Delimiters::Delimiters(int X, int Y, int WidthDelimiters, int HeightDelimiters)
{
    this-> X = X;
    this-> Y = Y;
    this-> WidthDelimiters = WidthDelimiters;
    this-> HeightDelimiters = HeightDelimiters;
}

QRectF Delimiters::boundingRect() const
{
    return QRectF(X, Y, WidthDelimiters, HeightDelimiters);
}

void Delimiters::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::transparent);
    //painter->setPen(Qt::NoPen);

    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}
