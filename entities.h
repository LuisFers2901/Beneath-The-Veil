#ifndef ENTITIES_H
#define ENTITIES_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <cmath>
#include <random>

#define tiempo 0.1

class Entities: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

    QTimer *TimerSprite, *TimerMove;
    float Speed;
    QPixmap *PixMap;
    int X, Y, PosX, PosY, Columns, WidthSprite, HeightSprite, RandomNum;
    int Sprite, TimerS, TimerM,PosXPixMap, PosYPixMap, Option, SpriteOp, StartPosXPixMap, NumberSprite;
    Entities(int PosX, int PosY, int WidthSprite, int HeightSprite, float Speed, int Sprite, int TimerS, int TimerM, QObject *parent); //Inicializa las varaibles necesarias para crear la entidad
    QRectF boundingRect() const;                //Genera la hitbox de la entidad
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//, const QString& ImagePath, int X, int Y, int NumSprites); //Toma la imagen e indiica la posicion y tamano del sprite

    double theta=0;
    double r=0;

    void MoveEntity(int Option);
    void StopEntity(int Option);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void RandomMove(Entities *Entity, int Option);
    void Circulo(int PosXEntity, int PosYEntity);
    void Rosa(int PosXEntity, int PosYEntity);
    void RosaAlCuadrado(int PosXEntity, int PosYEntity);
    void Lemniscata(int PosXEntity, int PosYEntity);
    void Dead(int Option);
    void Persecution(int PosXPacMan, int PosYPacMan, int PosXGhost, int PosYGhost, Entities *Entity);

public slots:

    void RefreshSprite();       //Se encarga de actualizar el srpite constantemente

};


#endif // ENTITIES_H
