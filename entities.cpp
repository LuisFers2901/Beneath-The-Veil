#include "entities.h"

Entities::Entities(int PosX, int PosY, int WidthSprite, int HeightSprite, int Speed, int Sprite, int TimerS, int TimerM, QObject *parent)
{

    this->PosX = PosX;
    this->PosY = PosY;
    this->WidthSprite = WidthSprite;
    this->HeightSprite = HeightSprite;
    this->Speed = Speed;
    this->Sprite = Sprite;
    this->SpriteOp = 4;
    this->TimerS = TimerS;
    this->TimerM = TimerM;
    this->Columns = 0;
    this->PosXPixMap = 0;
    this->PosYPixMap = 0;
    StartPosXPixMap = 0;
    this->Option = 4;
    NumberSprite = 6;
    TimerSprite = new QTimer();
    TimerSprite->start(TimerS);
    TimerMove = new QTimer();
    TimerMove->start(TimerM);
    PixMap = new QPixmap(":/Images/Esto esta melo/Spritess.png");
    setPos(PosX, PosY);
    connect(TimerSprite,&QTimer::timeout,this,&Entities::RefreshSprite);


}

QRectF Entities::boundingRect() const
{
    return QRectF((-WidthSprite)/2, (-HeightSprite)/2, WidthSprite, HeightSprite);
}

void Entities::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //80 x 96
    //    painter->setBrush(Qt::transparent);
    //    painter->setPen(Qt::NoPen);
    switch (Sprite) {
    case 1:
        PosYPixMap = 0;
        break;
    case 2:
        PosYPixMap = (96 * 1);
        break;
    case 3:
        PosYPixMap = (96 * 2);
        break;
    case 4:
        PosYPixMap = (96 * 3);
        break;
    case 5:
        PosYPixMap = (96 * 4);
        break;
    case 6:
        PosYPixMap = (96 * 5);
        break;
    }




    painter->drawPixmap((-WidthSprite)/2, (-HeightSprite)/2, *PixMap, PosXPixMap, PosYPixMap, WidthSprite, HeightSprite);

}



void Entities::MoveEntity(int Option)
{

    disconnect(TimerMove, &QTimer::timeout, this, &Entities::MoveUp);
    disconnect(TimerMove, &QTimer::timeout, this, &Entities::MoveDown);
    disconnect(TimerMove, &QTimer::timeout, this, &Entities::MoveLeft);
    disconnect(TimerMove, &QTimer::timeout, this, &Entities::MoveRight);

    switch (Option) {
    case 1:
        connect(TimerMove,&QTimer::timeout,this,&Entities::MoveUp);
        break;
    case 2:
        connect(TimerMove,&QTimer::timeout,this,&Entities::MoveDown);
        break;
    case 3:
        connect(TimerMove,&QTimer::timeout,this,&Entities::MoveLeft);
        break;
    case 4:
        connect(TimerMove,&QTimer::timeout,this,&Entities::MoveRight);
        break;
    }

}

void Entities::StopEntity(int Option)
{
    switch (Option) {
    case 1:
        disconnect(TimerMove,&QTimer::timeout,this,&Entities::MoveUp);
        PosY = PosY + Speed;
        setPos(PosX, PosY);
        break;
    case 2:
        disconnect(TimerMove,&QTimer::timeout,this,&Entities::MoveDown);
        PosY = PosY - Speed;
        setPos(PosX, PosY);
        break;
    case 3:
        disconnect(TimerMove,&QTimer::timeout,this,&Entities::MoveLeft);
        PosX = PosX + Speed;
        setPos(PosX, PosY);
        break;
    case 4:
        disconnect(TimerMove,&QTimer::timeout,this,&Entities::MoveRight);
        PosX = PosX - Speed;
        setPos(PosX, PosY);
        break;
    }
}

void Entities::MoveUp()
{
    PosY = PosY - Speed;
    SpriteOp = 1;
    setPos(PosX, PosY);
}

void Entities::MoveDown()
{
    PosY = PosY + Speed;
    SpriteOp = 2;
    setPos(PosX, PosY);
}

void Entities::MoveLeft()
{
    PosX = PosX - Speed;
    SpriteOp = 3;
    setPos(PosX, PosY);
}

void Entities::MoveRight()
{
    PosX = PosX + Speed;
    SpriteOp = 4;
    setPos(PosX, PosY);
}

void Entities::RandomMove(Entities *Entity, int Option)
{
    RandomNum = 1 + rand() % 4;
    while (RandomNum == Option){
        RandomNum = 1 + rand() % 4;
    }
    Entity->Option = RandomNum;
    Entity->MoveEntity(RandomNum);
}

void Entities::Circulo(int PosXEntity, int PosYEntity)
{
    r = sin(theta);

    if (theta == 360){
        theta == 0;
    }
    else{
        theta = theta + 0.001;
    }

    double x = PosXEntity + r*cos(theta);
    double y = PosYEntity + r*sin(theta);

    PosX = x;
    PosY = y;

    setPos(PosX,PosY);

}


void Entities::Rosa(int PosXEntity, int PosYEntity)
{
    r = 200*(sin(5*theta));

    if (theta == 360){
        theta == 0;
    }
    else{
        theta = theta + 0.005;
    }

    double x = PosXEntity + r*cos(theta);
    double y = PosYEntity + r*sin(theta);

    PosX = x;
    PosY = y;

    setPos(PosX,PosY);

}

void Entities::RosaAlCuadrado(int PosXEntity, int PosYEntity)
{
    r = (100 - (200*(sin(5*theta))));

    if (theta == 360){
        theta == 0;
    }
    else{
        theta = theta + 0.005;
    }

    double x = PosXEntity + r*cos(theta);
    double y = PosYEntity + r*sin(theta);

    PosX = x;
    PosY = y;

    setPos(PosX,PosY);

}

void Entities::Lemniscata(int PosXEntity, int PosYEntity)
{
    r = (160 * cos(2 * theta));

    if (theta == 360){
        theta == 0;
    }
    else{
        theta = theta + 0.005;
    }

    double x = PosXEntity + r*cos(theta);
    double y = PosYEntity + r*sin(theta);

    PosX = x;
    PosY = y;

    setPos(PosX,PosY);

}

void Entities::Dead(int Option)
{
    Sprite = 8;
    StopEntity(Option);
    disconnect(TimerSprite,&QTimer::timeout,this,&Entities::RefreshSprite);
    TimerSprite->start(200);
    connect(TimerSprite,&QTimer::timeout,this,&Entities::RefreshSprite);
}

void Entities::Persecution(int PosXPacMan, int PosYPacMan, int PosXGhost, int PosYGhost, Entities *Entity)
{

}

void Entities::RefreshSprite()
{
    PosXPixMap += 80;
    if (PosXPixMap >= (NumberSprite * 80) + StartPosXPixMap){
        PosXPixMap = StartPosXPixMap;
    }
    this->update((-WidthSprite)/2, (-HeightSprite)/2, WidthSprite, HeightSprite);

}
