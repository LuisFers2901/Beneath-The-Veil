#include "listbarriers.h"

ListBarriers::ListBarriers()
{

}

ListBarriers::~ListBarriers()
{
    qDeleteAll(Door);
    qDeleteAll(MapsImage);
    qDeleteAll(Maps);
}

void ListBarriers::ObjectsMap()
{

    //Laterales
    Paredes.push_back(new Barriers(0, 0, 43, 1080, 1));
    Paredes.push_back(new Barriers(1877, 0, 43, 1080, 1));
    //Polares
    Paredes.push_back(new Barriers(0, 0, 1920, 43, 1));
    Paredes.push_back(new Barriers(0, 1041, 1920, 43, 1));

    //Carcel
    Door.push_back(new Barriers(1850, 500, 28, 265, 2));
    //Corredor
    Door.push_back(new Barriers(0, 572, 59, 209, 2));
    Door.push_back(new Barriers(730, 90, 230, 350, 2));
    Door.push_back(new Barriers(1865, 672, 50, 260, 2));
    //Habitacion Hermana
    Door.push_back(new Barriers(730, 1006, 230, 53, 2));
    //Cocina
    Door.push_back(new Barriers(0, 846, 80, 206, 2));
    Door.push_back(new Barriers(1242, 90, 319, 345, 2));
    Door.push_back(new Barriers(1550, 1020, 311, 38, 2));
    //Laboratorio
    Door.push_back(new Barriers(1620, 990, 192, 92, 2));
    //Vestibulo
    Door.push_back(new Barriers(30, 0, 189, 347, 2));

    //----------------------------Objetos----------------------------

    //Corredor
    Objetos.push_back(new Barriers(1733, 461, 138, 90, 3));

    //Habitacion Hermana
    Objetos.push_back(new Barriers(1647, 255, 99, 136, 4));

    //Cocina
    Objetos.push_back(new Barriers(337, 930, 170, 109, 5));

    //Laboratorio
    Objetos.push_back(new Barriers(37, 165, 141, 167, 6));

    //Vestibulo
    Objetos.push_back(new Barriers(1667, 901, 200, 150, 7));

    //----------------------------Llaves----------------------------


    //Corredor  250 860
//    Llaves.push_back(new Barriers(250, 860, 50, 50, 8));

//    //Habitacion Hermana 1710 175
//    Llaves.push_back(new Barriers(1710, 175, 50, 50, 8));

//    //Cocina    170 225
//    Llaves.push_back(new Barriers(170, 225, 50, 50, 8));

//    //Laboratorio   1700 910
//    Llaves.push_back(new Barriers(1700, 910, 50, 50, 8));

//    //Vestibulo 1750 915
//    Llaves.push_back(new Barriers(1750, 915, 50, 50, 8));



    MapsImage.push_back(new QImage(":/Images/Menu Temp.png"));
    MapsImage.push_back(new QImage(":/Images/IMGS/room.png"));
    MapsImage.push_back(new QImage(":/Images/IMGS/corredor.png"));
    MapsImage.push_back(new QImage(":/Images/IMGS/sisteroom.png"));
    MapsImage.push_back(new QImage(":/Images/IMGS/cosina.png"));
    MapsImage.push_back(new QImage(":/Images/IMGS/lav.png"));
    MapsImage.push_back(new QImage(":/Images/IMGS/hall.png"));


    for (QList<QImage*>::iterator i = MapsImage.begin(); i != MapsImage.end(); i++) {
        QImage* Image = *i;
//        QImage* ScaledImage = new QImage(Image->scaled(Image->width()/1.25, Image->height()/1.25));   //En caso de que la imagen este grande (Laptops en especcial)
//        QBrush* Brush = new QBrush(*ScaledImage);                                                     //Descomentar esta funcion y comentar la siguiente linea
        QBrush* Brush = new QBrush(*Image);
        Maps.push_back(Brush);
    }



   // Sounds.push_back(new QSoundEffect(":/Sounds/sound drop.wav"));

}

