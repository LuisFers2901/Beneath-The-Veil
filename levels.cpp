
#include "levels.h"



Levels::Levels()
{



}

Levels::Levels(QGraphicsScene *MainMenu, Entities *Personaje)
{
    this->NumberLevel = 0;
    this->Scene = MainMenu;
    this->Personaje = Personaje;

}

void Levels::GameLevels(int LevelSelect)
{
    RemoveElementsScene();
    OptionLevels.ObjectsMap();

//    for (int i = 0; i < 4; i++){
//        Scene->addItem(OptionLevels.Paredes[i]);
//    }


    switch (LevelSelect) {
    case 0:     //Menu Principal
        Scene->setBackgroundBrush(*OptionLevels.Maps[0]);
        PlayButton = new QPushButton("Inciar", nullptr);
        PlayButton->setGeometry(800, 800, 150, 50);

        break;
    case 1:     //Carcel
        Scene->setBackgroundBrush(*OptionLevels.Maps[1]);
        Scene->addItem(OptionLevels.Door[0]);
        break;
    case 2:     //Corredor
        Scene->setBackgroundBrush(*OptionLevels.Maps[2]);
        Scene->addItem(OptionLevels.Door[1]);
        Scene->addItem(OptionLevels.Door[2]);
        Scene->addItem(OptionLevels.Door[3]);
        break;
    case 3:     //Habitacion Hermana
        Scene->setBackgroundBrush(*OptionLevels.Maps[3]);
        Scene->addItem(OptionLevels.Door[4]);
        break;
    case 4:     //Cocina
        Scene->setBackgroundBrush(*OptionLevels.Maps[4]);
        Scene->addItem(OptionLevels.Door[5]);
        Scene->addItem(OptionLevels.Door[6]);
        Scene->addItem(OptionLevels.Door[7]);
        break;
    case 5:     //Laboratorio
        Scene->setBackgroundBrush(*OptionLevels.Maps[5]);
        Scene->addItem(OptionLevels.Door[8]);
        break;
    case 6:     //Vestibulo
        Scene->setBackgroundBrush(*OptionLevels.Maps[6]);
        Scene->addItem(OptionLevels.Door[9]);
        break;
    }
}

void Levels::RemoveElementsScene()
{
    QList<QGraphicsItem*> ItemsList = Scene->items();

    for (QGraphicsItem* Item : ItemsList){
        if(Item != Personaje){
            Item->setVisible(false);
        }
    }

}

void Levels::LifeBar()
{

}


