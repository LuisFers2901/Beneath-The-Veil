#include "entities.h"

Entities::Entities()
{

}

Entities::Entities(int PosX, int PosY, int WidthSprite, int HeightSprite, int Speed, int Timer, const QString& ImagePath)
{

    this->PosX = PosX;
    this->PosY = PosY;
    this->WidthSprite = WidthSprite;
    this->HeightSprite = HeightSprite;
    this->Speed = Speed;
    this->Timer = Timer;
    this->ImagePath = ImagePath;

}

Entities::Entities(QObject *parent)
{
    TimerSprite = new QTimer();
    TimerSprite->start(Timer);

    connect(TimerSprite,&QTimer::timeout,this,&Entities::RefreshSprite);
    setPos(PosX, PosY);
}

QRectF Entities::boundingRect() const
{
    return QRectF((-WidthSprite)/2, (-HeightSprite)/2, WidthSprite, HeightSprite);
}

void Entities::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget, const QString& ImagePath, int X, int Y, int NumSprites)
{
    PixMap = new QPixmap(ImagePath);
    painter->drawPixmap((-WidthSprite)/2, (-HeightSprite)/2, *PixMap, X, Y, WidthSprite, HeightSprite);
    this->NumSprites = NumSprites;
    this->X = X;
    this->Columns = X;
    this->Y = Y;
}

void Entities::RefreshSprite()
{

    Columns += WidthSprite;

    if (Columns >= (NumSprites * WidthSprite)){
        Columns = X;
    }
    this->update((-WidthSprite)/2, (-HeightSprite)/2, WidthSprite, HeightSprite);

}
