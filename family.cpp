#include "family.h"

Family::Family()
{

}

void Family::Persecucion(Entities *Familiar, Entities *Personaje)
{
    DistanceX = Familiar->PosX - Personaje->PosX;
    DistanceY = Familiar->PosY - Personaje->PosY;

    if (DistanceX == 0 && DistanceY > 0){
        Familiar->MoveUp();
    }
    else if (DistanceX == 0 && DistanceY < 0){
        Familiar->MoveDown();
    }
    else if (DistanceX > 0 && DistanceY == 0){
        Familiar->MoveLeft();
    }
    else if (DistanceX < 0 && DistanceY == 0){
        Familiar->MoveRight();
    }
    else if (DistanceX > 0 && DistanceY > 0){
        MoveNorthwest(Familiar);
    }
    else if (DistanceX < 0 && DistanceY > 0){
        MoveNortheast(Familiar);
    }
    else if (DistanceX > 0 && DistanceY < 0){
        MoveSouthwest(Familiar);
    }
    else if (DistanceX < 0 && DistanceY < 0){
        MoveSoutheast(Familiar);
    }


}

void Family::MoveNortheast(Entities *Familiar)
{
    Familiar->MoveRight();
    Familiar->MoveUp();

}

void Family::MoveNorthwest(Entities *Familiar)
{
    Familiar->MoveLeft();
    Familiar->MoveUp();

}

void Family::MoveSouthwest(Entities *Familiar)
{
    Familiar->MoveLeft();
    Familiar->MoveDown();

}

void Family::MoveSoutheast(Entities *Familiar)
{
    Familiar->MoveRight();
    Familiar->MoveDown();
}




