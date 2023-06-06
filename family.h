#ifndef FAMILY_H
#define FAMILY_H

#include "listbarriers.h"
#include "entities.h"
#include <QList>
#include <QObject>
#include <QTimer>


class Family
{
public:

    int DistanceX, DistanceY;


    Family();
    void Persecucion(Entities *Familiar, Entities *Personaje);
    void MoveNortheast(Entities *Entity);
    void MoveNorthwest(Entities *Entity);
    void MoveSouthwest(Entities *Entity);
    void MoveSoutheast(Entities *Entity);


};

#endif // FAMILY_H
