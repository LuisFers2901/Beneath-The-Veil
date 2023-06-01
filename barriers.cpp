#include "barriers.h"


Barriers::Barriers(int X, int Y, int WidthBarrier, int HeightBarrier, int Color)
{
    PixMap = new QPixmap(":/Images/Sprite-WithoutBackground.png");
    this-> X = X;
    this-> Y = Y;
    this-> WidthBarrier = WidthBarrier;
    this-> HeightBarrier = HeightBarrier;
    this-> Color = Color;
    ColorHex.setNamedColor("#FFB7AE");


}

QRectF Barriers::boundingRect() const
{
    return QRectF(X, Y, WidthBarrier, HeightBarrier);
}

void Barriers::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch (Color) {
    case 0:
        painter->setBrush(Qt::transparent);
        painter->setPen(Qt::NoPen);
        break;
    case 1:
        painter->setBrush(Qt::blue);
        break;
    case 2:
        painter->setBrush(Qt::gray);
        break;
    case 3:
        painter->setBrush(Qt::red);
        break;
    case 4:
        painter->setBrush(Qt::magenta);
        break;
    case 5:
        painter->setBrush(Qt::darkMagenta);
        break;
    case 6:
        painter->setBrush(Qt::darkGray);
        break;
    case 7:
        painter->setBrush(Qt::darkGreen);
        break;
    case 8:
        painter->setBrush(Qt::yellow);
        break;
    }

    painter->drawRect(boundingRect());

}
