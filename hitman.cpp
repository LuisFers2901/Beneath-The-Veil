#include "hitman.h"

HitMan::HitMan(QObject *parent) : QObject(parent)
{
    Timer = new QTimer();
    Timer->start(500);

    Rows = 0;
    Columns = 0;

    Width = 120;
    Height = 130;

    PixMap = new QPixmap(":/Images/SpriteExample2.png");

    connect(Timer,&QTimer::timeout,this,&HitMan::RefreshSprite);

}

QRectF HitMan::boundingRect() const
{
    return QRectF((-Width)/2, (-Height)/2, Width, Height);

}

void HitMan::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap((-Width)/2, (-Height)/2, *PixMap, Columns, 0, Width, Height);
}

void HitMan::RefreshSprite()
{
    Columns += 120;

    if (Columns >= 360){
        Columns = 0;
    }
    this->update((-Width)/2, (-Height)/2, Width, Height);
}

