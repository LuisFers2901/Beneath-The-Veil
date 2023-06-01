#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)

{
    ui->setupUi(this);
    QScreen* primaryScreen = QApplication::primaryScreen();
    QRect Desktop = primaryScreen->geometry();
    showFullScreen();
    DesktopX = Desktop.x();
    DesktopY = Desktop.y();
    ui->graphicsView->setGeometry(0,0,width(),height());
    DesktopWidth = Desktop.width();
    DesktopHeight = Desktop.height();

    DesktopWidth = 1280;
    DesktopHeight = 720;
    UIWidth = ui->graphicsView->width()-2;
    UIHeight = ui->graphicsView->height()-2;

    MainMenu = new QGraphicsScene();

    MainMenu->setSceneRect(0, 0, UIWidth, UIHeight);

    ui->graphicsView->setScene(MainMenu);

    Personaje = new Entities(450, 700, 50, 50, 10, 5, 65, 5, nullptr);
    Hermano = new Entities(1490, 440, 100, 150, 10, 2, 65, 5, nullptr);
    Hermana = new Entities(350, 350, 100, 150, 10, 3, 65, 5, nullptr);
    Mama = new Entities(1350, 520, 100, 150, 10, 4, 65, 5, nullptr);
    Papa = new Entities(370, 810, 100, 150, 10, 5, 65, 5, nullptr);
    Chemms = new Entities(1640, 440, 100, 150, 10, 6, 65, 5, nullptr);

    BarriersMaps.ObjectsMap();
    MainMenu->setBackgroundBrush(*BarriersMaps.Maps[1]);
    MainMenu->addItem(Personaje);
    MainMenu->addItem(BarriersMaps.Door[0]);

    for (int i = 0; i < 4; i++){
        MainMenu->addItem(BarriersMaps.Paredes[i]);
    }

    ListObjectsScene = MainMenu->items();

    connect(Personaje->TimerMove, &QTimer::timeout, this, &Widget::EvalueCollision);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *evento)
{
    //qDebug() << "X: " << Personaje->PosX << "   Y: " << Personaje->PosY << "\n";

    if (evento->key() == Qt::Key_W || evento->key() == Qt::Key_Up){
//        Personaje->MoveUp();
        Personaje->MoveEntity(1);
        Option = 1;
    }
    else if (evento->key() == Qt::Key_S || evento->key() == Qt::Key_Down){
//        Personaje->MoveDown();
        Personaje->MoveEntity(2);
        Option = 2;
    }
    else if (evento->key() == Qt::Key_A || evento->key() == Qt::Key_Left){
//        Personaje->MoveLeft();
        Personaje->MoveEntity(3);
        Option = 3;
    }
    else if (evento->key() == Qt::Key_D || evento->key() == Qt::Key_Right){
//        Personaje->MoveRight();
        Personaje->MoveEntity(4);
        Option = 4;
    }  

    if (evento->key() == Qt::Key_J){
        Interaction = true;
    }
    else{
        Interaction = false;
    }
}

void Widget::EvalueCollision()
{
    for (auto paredes : BarriersMaps.Paredes) {
        if(paredes->collidesWithItem(Personaje)){
            Personaje->StopEntity(Option);
        }
    }


    switch (Level) {
    case 1:     //Carcel
        if (Personaje->collidesWithItem(BarriersMaps.Door[0])){
            //Eliminar el background anterior

            MainMenu->setBackgroundBrush(*BarriersMaps.Maps[2]);
            MainMenu->removeItem(BarriersMaps.Door[0]);
            MainMenu->addItem(BarriersMaps.Door[1]);
            MainMenu->addItem(BarriersMaps.Door[2]);
            MainMenu->addItem(BarriersMaps.Door[3]);
            if (Level2 == false){
                MainMenu->addItem(BarriersMaps.Objetos[0]);
            }
            MainMenu->addItem(Hermano);
            Personaje->PosX = 100;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 2;
        }
        break;

    case 2:     //Corredor

        if (Personaje->collidesWithItem(BarriersMaps.Door[1]) && Level2 == true){
            //Eliminar el background anterior

            MainMenu->setBackgroundBrush(*BarriersMaps.Maps[1]);
            MainMenu->removeItem(BarriersMaps.Door[1]);
            MainMenu->removeItem(BarriersMaps.Door[2]);
            MainMenu->removeItem(BarriersMaps.Door[3]);
            MainMenu->removeItem(Hermano);
            MainMenu->removeItem(BarriersMaps.Objetos[0]);
            MainMenu->addItem(BarriersMaps.Door[0]);
            Personaje->PosX = 1825;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 1;
        }
        else if (Personaje->collidesWithItem(BarriersMaps.Door[1]) && Level2 == false){
            Personaje->StopEntity(Option);
        }

        if (Personaje->collidesWithItem(BarriersMaps.Door[2]) && Level2 == true){
            //Eliminar el background anterior

            MainMenu->setBackgroundBrush(*BarriersMaps.Maps[3]);
            MainMenu->removeItem(BarriersMaps.Door[1]);
            MainMenu->removeItem(BarriersMaps.Door[2]);
            MainMenu->removeItem(BarriersMaps.Door[3]);
            MainMenu->removeItem(Hermano);
            MainMenu->removeItem(BarriersMaps.Objetos[0]);
            MainMenu->addItem(BarriersMaps.Door[4]);
            MainMenu->addItem(Hermana);
            if (Level3 == false){
                MainMenu->addItem(BarriersMaps.Objetos[1]);
            }
            Personaje->PosY = 975;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 3;
        }

        else if (Personaje->collidesWithItem(BarriersMaps.Door[2]) && Level2 == false){
            Personaje->StopEntity(Option);
        }

        if (Personaje->collidesWithItem(BarriersMaps.Door[3]) && Level3 == true){
            //Eliminar el background anterior

            MainMenu->setBackgroundBrush(*BarriersMaps.Maps[4]);
            MainMenu->removeItem(BarriersMaps.Door[1]);
            MainMenu->removeItem(BarriersMaps.Door[2]);
            MainMenu->removeItem(BarriersMaps.Door[3]);
            MainMenu->removeItem(Hermano);
            MainMenu->removeItem(BarriersMaps.Objetos[0]);
            MainMenu->addItem(BarriersMaps.Door[5]);
            MainMenu->addItem(BarriersMaps.Door[6]);
            MainMenu->addItem(BarriersMaps.Door[7]);
            MainMenu->addItem(Mama);
            if (Level4 == false){
                MainMenu->addItem(BarriersMaps.Objetos[2]);
            }
            Personaje->PosX = 100;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 4;
        }

        else if (Personaje->collidesWithItem(BarriersMaps.Door[3]) && Level3 == false){
            Personaje->StopEntity(Option);
        }

        if (Personaje->collidesWithItem(BarriersMaps.Objetos[0]) && Interaction == true && Level2 == false){
            Level2 = true;
            MainMenu->removeItem(BarriersMaps.Objetos[0]);

        }

        break;

    case 3:     //Habitacion Hermana

        if (Personaje->collidesWithItem(BarriersMaps.Door[4]) && Level3 == true){
            //Eliminar el background anterior

            MainMenu->setBackgroundBrush(*BarriersMaps.Maps[2]);
            MainMenu->removeItem(BarriersMaps.Door[4]);
            MainMenu->removeItem(Hermana);
            MainMenu->removeItem(BarriersMaps.Objetos[1]);
            MainMenu->addItem(BarriersMaps.Door[1]);
            MainMenu->addItem(BarriersMaps.Door[2]);
            MainMenu->addItem(BarriersMaps.Door[3]);
            MainMenu->addItem(Hermano);
            Personaje->PosY = 125;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 2;
        }
        else if (Personaje->collidesWithItem(BarriersMaps.Door[4]) && Level3 == false){
            Personaje->StopEntity(Option);
        }
        if (Personaje->collidesWithItem(BarriersMaps.Objetos[1]) && Interaction == true && Level3 == false){
            Level3 = true;
            MainMenu->removeItem(BarriersMaps.Objetos[1]);
//            QSoundEffect* SoundEffect = BarriersMaps.Sounds[0];
//            SoundEffect->play();
        }
        break;

    case 4:     //Cocina

        if (Personaje->collidesWithItem(BarriersMaps.Door[5]) && Level4 == true){
            //Eliminar el background anterior

            MainMenu->setBackgroundBrush(*BarriersMaps.Maps[2]);
            MainMenu->addItem(BarriersMaps.Door[1]);
            MainMenu->addItem(BarriersMaps.Door[2]);
            MainMenu->addItem(BarriersMaps.Door[3]);
            MainMenu->addItem(Hermano);
            MainMenu->removeItem(BarriersMaps.Door[5]);
            MainMenu->removeItem(BarriersMaps.Door[6]);
            MainMenu->removeItem(BarriersMaps.Door[7]);
            MainMenu->removeItem(Mama);
            MainMenu->removeItem(BarriersMaps.Objetos[2]);
            Personaje->PosX = 1800;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 2;
        }
        else if (Personaje->collidesWithItem(BarriersMaps.Door[5]) && Level4 == false){
            Personaje->StopEntity(Option);
        }

        if (Personaje->collidesWithItem(BarriersMaps.Door[6]) && Level4 == true){
            //Eliminar el background anterior

            MainMenu->setBackgroundBrush(*BarriersMaps.Maps[5]);
            MainMenu->addItem(BarriersMaps.Door[8]);
            MainMenu->addItem(Papa);
            if(Level5 == false){
                MainMenu->addItem(BarriersMaps.Objetos[3]);
            }
            MainMenu->removeItem(BarriersMaps.Door[5]);
            MainMenu->removeItem(BarriersMaps.Door[6]);
            MainMenu->removeItem(BarriersMaps.Door[7]);
            MainMenu->removeItem(Mama);
            MainMenu->removeItem(BarriersMaps.Objetos[2]);
            Personaje->PosY = 200;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 5;
        }

        else if (Personaje->collidesWithItem(BarriersMaps.Door[6]) && Level4 == false){
            Personaje->StopEntity(Option);
        }

        if (Personaje->collidesWithItem(BarriersMaps.Door[7]) && Level5 == true){
            //Eliminar el background anterior

            MainMenu->setBackgroundBrush(*BarriersMaps.Maps[6]);
            MainMenu->addItem(BarriersMaps.Door[9]);
            MainMenu->addItem(Chemms);
            if (Level6 == false){
                MainMenu->addItem(BarriersMaps.Objetos[4]);
            }
            MainMenu->removeItem(BarriersMaps.Door[5]);
            MainMenu->removeItem(BarriersMaps.Door[6]);
            MainMenu->removeItem(BarriersMaps.Door[7]);
            MainMenu->removeItem(Mama);
            MainMenu->removeItem(BarriersMaps.Objetos[2]);
            Personaje->PosX = 100;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 6;
        }
        else if (Personaje->collidesWithItem(BarriersMaps.Door[7]) && Level6 == false){
            Personaje->StopEntity(Option);
        }

        if (Personaje->collidesWithItem(BarriersMaps.Objetos[2]) && Interaction == true && Level4 == false){
            Level4 = true;
            MainMenu->removeItem(BarriersMaps.Objetos[2]);

        }
        break;

    case 5:

        if (Personaje->collidesWithItem(BarriersMaps.Door[8]) && Level5 == true){
            //Eliminar el background anterior

            MainMenu->setBackgroundBrush(*BarriersMaps.Maps[4]);
            MainMenu->addItem(BarriersMaps.Door[5]);
            MainMenu->addItem(BarriersMaps.Door[6]);
            MainMenu->addItem(BarriersMaps.Door[7]);
            MainMenu->addItem(Mama);
            MainMenu->removeItem(BarriersMaps.Door[8]);
            MainMenu->removeItem(Papa);
            MainMenu->removeItem(BarriersMaps.Objetos[3]);
            Personaje->PosY = 975;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 4;
        }
        else if (Personaje->collidesWithItem(BarriersMaps.Door[8]) && Level5 == false){
            Personaje->StopEntity(Option);
        }
        if (Personaje->collidesWithItem(BarriersMaps.Objetos[3]) && Interaction == true && Level5 == false){
            Level5 = true;
            MainMenu->removeItem(BarriersMaps.Objetos[3]);
        }


        break;

    case 6:

        if (Personaje->collidesWithItem(BarriersMaps.Door[9])  && Level6 == true){
            //Eliminar el background anterior

            MainMenu->setBackgroundBrush(*BarriersMaps.Maps[4]);
            MainMenu->addItem(BarriersMaps.Door[5]);
            MainMenu->addItem(BarriersMaps.Door[6]);
            MainMenu->addItem(BarriersMaps.Door[7]);
            MainMenu->addItem(Mama);
            MainMenu->removeItem(BarriersMaps.Door[9]);
            MainMenu->removeItem(Chemms);
            Personaje->PosX = 1800;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 4;
        }
        else if (Personaje->collidesWithItem(BarriersMaps.Door[9]) && Level6 == false){
            Personaje->StopEntity(Option);
        }
        if (Personaje->collidesWithItem(BarriersMaps.Objetos[4]) && Interaction == true && Level6 == false){
            Level6 = true;
            MainMenu->removeItem(BarriersMaps.Objetos[4]);
        }

        break;


    }


}
