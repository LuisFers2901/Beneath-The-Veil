
#include "levels.h"



Levels::Levels()
{



}

Levels::Levels(QGraphicsScene *MainMenu)
{
    this->NumberLevel = 0;
    this->Scene = MainMenu;


}

void Levels::GameLevels(int LevelSelect)
{
    OptionLevels.ObjectsMap();

    switch (LevelSelect) {
    case 0:     //Menu Principal
        Scene->setBackgroundBrush(*OptionLevels.Maps[0]);
        break;
    case 1:     //Carcel
        Scene->setBackgroundBrush(*OptionLevels.Maps[1]);
        break;
    case 2:     //Corredor
        Scene->setBackgroundBrush(*OptionLevels.Maps[2]);
        break;
    case 3:     //Habitacion Hermana
        Scene->setBackgroundBrush(*OptionLevels.Maps[3]);
        break;
    case 4:     //Cocina
        Scene->setBackgroundBrush(*OptionLevels.Maps[4]);
        break;
    case 5:     //Laboratorio
        Scene->setBackgroundBrush(*OptionLevels.Maps[5]);
        break;
    case 6:     //Vestibulo
        Scene->setBackgroundBrush(*OptionLevels.Maps[6]);
        break;
    }
}
