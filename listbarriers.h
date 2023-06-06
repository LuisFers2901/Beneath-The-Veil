#ifndef LISTBARRIERS_H
#define LISTBARRIERS_H

#include <QImage>
#include <QBrush>
#include <QDebug>
#include <QSoundEffect>
#include <QLabel>

#include "barriers.h"

#include <QList>

class ListBarriers
{
public:
    ListBarriers();
    ~ListBarriers();


    void ObjectsMap();

    QList<Barriers*> Objetos;
    QList<Barriers*> Paredes;
    QList<Barriers*> Door;
    QList<QImage*> MapsImage;
    QList<QBrush*> Maps;
    QList<QSoundEffect*> Sounds;
};

#endif // LISTBARRIERS_H
