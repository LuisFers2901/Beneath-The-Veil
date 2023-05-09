#include "hitman.h"
#include "entities.h"

void HitMan::keyPressEvent(QKeyEvent *evento, Entities *Entity)
{
    if (evento->key() == Qt::Key_W || evento->key() == Qt::Key_Up){
        MoveUp(Entity);
    }
    else if (evento->key() == Qt::Key_S || evento->key() == Qt::Key_Down){
        MoveDown(Entity);
    }
    else if (evento->key() == Qt::Key_A || evento->key() == Qt::Key_Left){
        MoveLeft(Entity);
    }
    else if (evento->key() == Qt::Key_D || evento->key() == Qt::Key_Right){
        MoveRight(Entity);
    }
}

void HitMan::MoveUp(Entities *Entity)
{
    Entity->PosY = Entity->PosY - Entity->Speed;
    Entity->setPos(Entity->PosX, Entity->PosY);
}

void HitMan::MoveDown(Entities *Entity)
{
    Entity->PosY = Entity->PosY + Entity->Speed;
    Entity->setPos(Entity->PosX, Entity->PosY);
}

void HitMan::MoveLeft(Entities *Entity)
{
    Entity->PosX = Entity->PosX - Entity->Speed;
    Entity->setPos(Entity->PosX, Entity->PosY);
}

void HitMan::MoveRight(Entities *Entity)
{
    Entity->PosX = Entity->PosX + Entity->Speed;
    Entity->setPos(Entity->PosX, Entity->PosY);
}
