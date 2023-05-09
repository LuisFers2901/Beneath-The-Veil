#ifndef ENTITIES_H
#define ENTITIES_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Entities: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

    QTimer *TimerSprite;
    QPixmap *PixMap;
    int X, Y,NumSprites, PosX, PosY, Speed, Columns, WidthSprite, HeightSprite, Timer;
    Entities(int PosX, int PosY, int WidthSprite, int HeightSprite, int Speed, int Timer); //Inicializa las varaibles necesarias para crear la entidad
    Entities(QObject *parent = nullptr);        //Conexion que anima el sprite en pantalla
    QRectF boundingRect() const;                //Genera la hitbox de la entidad
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget, const QString& ImagePath, int X, int Y, int NumSprites); //Toma la imagen e indiica la posicion y tamano del sprite
    void repaint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget, int X, int Y, int NumSprites); //Repinta la imagen para cambiar de posicion en el sprite
signals:

public slots:

    void RefreshSprite();       //Se encarga de actualizar el srpite constantemente

};


#endif // ENTITIES_H
