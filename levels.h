#ifndef LEVELS_H
#define LEVELS_H

#include "listbarriers.h"
#include <QGraphicsScene>

#include <QImage>
#include <QBrush>
#include <QList>

class Levels
{
public:

    QGraphicsScene* Scene;

    ListBarriers OptionLevels;

    int NumberLevel;
    Levels();

    Levels(QGraphicsScene* MainMenu);
    void GameLevels(int LevelSelect);
};

#endif // LEVELS_H
