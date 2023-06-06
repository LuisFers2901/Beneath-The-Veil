#ifndef LEVELS_H
#define LEVELS_H

#include "listbarriers.h"
#include "entities.h"
#include <QGraphicsScene>

#include <QImage>
#include <QBrush>
#include <QList>
#include <QProgressbar>
#include <QLabel>

#include <QPushButton>

class Levels
{
public:

    QGraphicsScene* Scene;
    Entities* Personaje;
    QPushButton* PlayButton;

    ListBarriers OptionLevels;

    int NumberLevel, Life = 100;
    QProgressBar *BarradeVida;
    QLabel *RelationshipName;
    QLabel *Letter;

    Levels();

    Levels(QGraphicsScene* MainMenu, Entities* Personaje);
    void GameLevels(int LevelSelect);
    void RemoveElementsScene();
    void LifeBar();

};

#endif // LEVELS_H
