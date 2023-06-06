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

    Personaje = new Entities(450, 700, 80, 96, 10, 1, 120, 1, nullptr);
    Hermano = new Entities(1490, 440, 80, 96, 10, 2, 65, 20, nullptr);
    Hermana = new Entities(350, 350, 80, 96, 10, 3, 65, 5, nullptr);
    Mama = new Entities(1350, 520, 80, 96, 10, 4, 65, 5, nullptr);
    Papa = new Entities(370, 810, 80, 96, 10, 5, 65, 5, nullptr);
    Cheems = new Entities(1640, 440, 80, 96, 10, 6, 65, 5, nullptr);
    Brazo = new Entities(550, 710, 20, 10, 10, 2, 65, 5, nullptr);
    SpecialPower = new Entities(550, 710, 25, 20, 10, 2, 65, 5, nullptr);


    BarradeVida = new QProgressBar(nullptr);
    BarradeVida->setRange(0,100);
    BarradeVida->setValue(100);
    BarradeVida->setGeometry(1300, 75, 400,25);
    BarradeVida->setTextVisible(false);
    BarradeVida->setStyleSheet("QProgressBar {"
                               "background-color: transparent;"
                               "color: white;"
                               "border: none;"
                               "}"
                               "QProgressBar::chunk {"
                               "background-color: red;"
                               "}"
                               "QProgressBar::chunk:disabled {"
                               "background-color: transparent;"
                               "}");

    BarradeVidaPersonaje = new QProgressBar(nullptr);
    BarradeVidaPersonaje->setRange(0,100);
    BarradeVidaPersonaje->setValue(100);
    BarradeVidaPersonaje->setGeometry(200, 75, 300,25);
    BarradeVidaPersonaje->setStyleSheet("QProgressBar {"
                               "background-color: transparent;"
                               "color: white;"
                               "border: none;"
                               "}"
                               "QProgressBar::chunk {"
                               "background-color: blue;"
                               "}"
                               "QProgressBar::chunk:disabled {"
                               "background-color: transparent;"
                               "}");

    RelationshipName = new QLabel("Rehtorb", nullptr);
    RelationshipName->setGeometry(1300, 25, 400, 25);
    RelationshipName->setStyleSheet("color: black;"
                                "font-weight: bold;"
                                "background-color: transparent;"
                                "font-size: 25px;");
    RelationshipName->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    Letter = new QLabel("“Recuerdo jugar con el tren de mi hermano, especialmente\ncuando sacaba de paseo a la muñeca de mi hermana”", nullptr);
    Letter->setGeometry(260, 90, 1400, 900);
    Letter->setStyleSheet("color: black;"
                        "font-weight: bold;"
                        "background-color: transparent;"
                        "font-size: 50px;");
    Letter->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);



    BarradeVidaPersonaje->setTextVisible(true);
    BarriersMaps.ObjectsMap();

    ListObjectsScene = MainMenu->items();

    Levelspa = Levels(MainMenu, Personaje);



    MainMenu->addItem(Personaje);
    MainMenu->addItem(Hermano);
    MainMenu->addItem(Hermana);
    MainMenu->addItem(Mama);
    MainMenu->addItem(Papa);
    MainMenu->addItem(Cheems);
    MainMenu->addWidget(BarradeVidaPersonaje);
    MainMenu->addWidget(RelationshipName);
    MainMenu->addWidget(BarradeVida);

    for (auto doors : BarriersMaps.Door){
        MainMenu->addItem(doors);
    }
    for (auto objetos : BarriersMaps.Objetos){
        MainMenu->addItem(objetos);
    }
    for (auto paredes : BarriersMaps.Paredes){
        MainMenu->addItem(paredes);
    }

    Levelspa.GameLevels(1);


    connect(Personaje->TimerMove, &QTimer::timeout, this, &Widget::EvalueCollision);



}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *evento)
{
    //qDebug() << "X: " << Personaje->PosX << "   Y: " << Personaje->PosY << "\n";

    if (EnabledKeys == true && (evento->key() == Qt::Key_W || evento->key() == Qt::Key_Up)){
        Personaje->MoveUp();
//        Personaje->MoveEntity(1);
        Option = 1;
    }
    else if (EnabledKeys == true && (evento->key() == Qt::Key_S || evento->key() == Qt::Key_Down)){
        Personaje->MoveDown();
//        Personaje->MoveEntity(2);
        Option = 2;
    }
    else if (EnabledKeys == true && (evento->key() == Qt::Key_A || evento->key() == Qt::Key_Left)){
        Personaje->MoveLeft();
//        Personaje->MoveEntity(3);
        Option = 3;
    }
    else if (EnabledKeys == true && (evento->key() == Qt::Key_D || evento->key() == Qt::Key_Right)){
        Personaje->MoveRight();
//        Personaje->MoveEntity(4);
        Option = 4;
    }  

    if (evento->key() == Qt::Key_J){
        Interaction = true;
    }
    else{
        Interaction = false;
    }


    if (EnabledKeys == true && evento->key() == Qt::Key_K){
        Attack = true;
    }
    else{
        Attack = false;
    }
}

void Widget::EvalueCollision()
{
    for (auto paredes : BarriersMaps.Paredes) {
        if(paredes->collidesWithItem(Personaje)){
            Personaje->StopEntity(Option);
        }
        if(paredes->collidesWithItem(Hermano)){
            Hermano->StopEntity(Hermano->Option);
        }
    }

    if(Option == 3){
        Brazo->X = Personaje->PosX - 35;
    }
    else if (Option == 4){
        Brazo->X = Personaje->PosX + 35;
    }
    Brazo->Y = Personaje->PosY;
    Brazo->setPos(Brazo->X, Brazo->Y);


    switch (Level) {
    case 1:     //Carcel
        if (Personaje->collidesWithItem(BarriersMaps.Door[0])){
            //Eliminar el background anterior

            Levelspa.GameLevels(2);
            if (Level2 == false){

                MainMenu->addItem(BarriersMaps.Objetos[0]);
            }
            Hermano->setVisible(true);

            Personaje->PosX = 100;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 2;
        }
        break;

    case 2:     //Corredor

        if (Personaje->collidesWithItem(BarriersMaps.Door[1]) && Level2 == true){
            //Eliminar el background anterior

            Levelspa.GameLevels(1);
            Personaje->PosX = 1825;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 1;
        }
        else if (Personaje->collidesWithItem(BarriersMaps.Door[1]) && Level2 == false){
            Personaje->StopEntity(Option);
        }

        if (Personaje->collidesWithItem(BarriersMaps.Door[2]) && Level2 == true){
            //Eliminar el background anterior

            Levelspa.GameLevels(3);
            Hermana->setVisible(true);
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

            Levelspa.GameLevels(4);
            Mama->setVisible(true);
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
            MainMenu->addWidget(Letter);
            MainMenu->removeItem(BarriersMaps.Objetos[0]);
            EnabledKeys = false;
            Interaction = false;

        }

        if (EnabledKeys == false && Level2 == true){
            if (Interaction == true){
                EnabledKeys = true;
                Letter->setVisible(false);
                Letter->setText("“Recuerdo el día que mis hermanos salieron, como me aburrí, \nmama jugó conmigo a la cocina y me preparo un plato especial”");
                //Cambiar letter po una imagen del escrito y anadir audio de nino llorando desesperadamente
            }
        }

        break;

    case 3:     //Habitacion Hermana

        if (Personaje->collidesWithItem(BarriersMaps.Door[4]) && Level3 == true){
            //Eliminar el background anterior

            Levelspa.GameLevels(2);
            Hermano->setVisible(true);
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
            Letter->setVisible(true);
            EnabledKeys = false;
            Interaction = false;
        }

        if (EnabledKeys == false && Level3 == true){
            if (Interaction == true){
                EnabledKeys = true;
                Letter->setVisible(false);
                Letter->setText(" “Siempre me gustó la comida de mamá y más cuando \nlos servía en los frascos del laboratorio de papá”");
                //Cambiar letter po una imagen del escrito y anadir audio de nino llorando desesperadamente
            }
        }
        break;

    case 4:     //Cocina

        if (Personaje->collidesWithItem(BarriersMaps.Door[5]) && Level4 == true){
            //Eliminar el background anterior

            Levelspa.GameLevels(2);
            Hermano->setVisible(true);
            Personaje->PosX = 1800;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 2;
        }
        else if (Personaje->collidesWithItem(BarriersMaps.Door[5]) && Level4 == false){
            Personaje->StopEntity(Option);
        }

        if (Personaje->collidesWithItem(BarriersMaps.Door[6]) && Level4 == true){
            //Eliminar el background anterior

            Levelspa.GameLevels(5);
            Papa->setVisible(true);
            if(Level5 == false){
                MainMenu->addItem(BarriersMaps.Objetos[3]);
            }
            Personaje->PosY = 200;
            Personaje->setPos(Personaje->PosX, Personaje->PosY);
            Level = 5;
        }

        else if (Personaje->collidesWithItem(BarriersMaps.Door[6]) && Level4 == false){
            Personaje->StopEntity(Option);
        }

        if (Personaje->collidesWithItem(BarriersMaps.Door[7]) && Level5 == true){
            //Eliminar el background anterior

            Levelspa.GameLevels(6);
            Cheems->setVisible(true);
            if (Level6 == false){
                MainMenu->addItem(BarriersMaps.Objetos[4]);
            }
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
            Letter->setVisible(true);
            EnabledKeys = false;
            Interaction = false;
        }

        if (EnabledKeys == false && Level4 == true){
            if (Interaction == true){
                EnabledKeys = true;
                Letter->setVisible(false);
                Letter->setText("“Nunca olvidare el día en que Chemms destruyo el laboratorio\nde papá mientras jugaba con su hueso, ¡Que travieso!”");
                //Cambiar letter po una imagen del escrito y anadir audio de nino llorando desesperadamente
            }
        }
        break;

    case 5:

        if (Personaje->collidesWithItem(BarriersMaps.Door[8]) && Level5 == true){
            //Eliminar el background anterior

            Levelspa.GameLevels(4);
            Mama->setVisible(true);
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
            Letter->setVisible(true);
            EnabledKeys = false;
            Interaction = false;
        }
        if (EnabledKeys == false && Level5 == true){
            if (Interaction == true){
                EnabledKeys = true;
                Letter->setVisible(false); //Cambiar letter po una imagen del escrito y anadir audio de nino llorando desesperadamente
            }
        }

        break;

    case 6:

        if (Personaje->collidesWithItem(BarriersMaps.Door[9])  && Level6 == true){
            //Eliminar el background anterior
            Levelspa.GameLevels(4);
            Mama->setVisible(true);
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

//    if (Level == 2 && Level2 == false){

//        if (Life == 100){
//            BarradeVida->setValue(Life);
//            BarradeVida->setVisible(true);
//            BarradeVidaPersonaje->setValue(Life);
//            BarradeVidaPersonaje->setVisible(true);
//            RelationshipName->setVisible(true);
//        }
//        else if (Life == 0){
//            BarradeVida->setVisible(false);
//            RelationshipName->setVisible(false);
//            Level2 = true;
//            Life = 100;
//        }

//        if (Personaje->collidesWithItem(Hermano)){
//            Personaje->StopEntity(Option);
//        }
//        if (Life > 0 && Brazo->collidesWithItem(Hermano) && Attack == true){
//            Life -= 10;
//            BarradeVida->setValue(Life);
//            qDebug() << Life << "\n";
//            Attack = false;
//        }
//    }
//    else if (Level == 2 && Level2 == true){
//        if (Personaje->collidesWithItem(Hermano)){
//            Personaje->StopEntity(Option);
//        }
//        StatusLife1 = false;
//    }


//    if (Level == 3 && Level3 == false){

//        if (Life == 100){
//            BarradeVida->setValue(Life);
//            BarradeVida->setVisible(true);
//            BarradeVidaPersonaje->setValue(Life);
//            BarradeVidaPersonaje->setVisible(true);
//            RelationshipName->setText("Retsis");
//            RelationshipName->setVisible(true);
//        }
//        else if (Life == 0){
//            BarradeVida->setVisible(false);
//            RelationshipName->setVisible(false);
//            Level3 = true;
//            Life = 100;
//        }

//        if (Personaje->collidesWithItem(Hermana)){
//            Personaje->StopEntity(Option);
//        }
//        if (Life > 0 && Brazo->collidesWithItem(Hermana) && Attack == true){
//            Life -= 10;
//            BarradeVida->setValue(Life);
//            qDebug() << Life << "\n";
//            Attack = false;
//        }
//    }

//    if (Level == 4 && Level4 == false){

//        if (Life == 100){
//            BarradeVida->setValue(Life);
//            BarradeVida->setVisible(true);
//            BarradeVidaPersonaje->setValue(Life);
//            BarradeVidaPersonaje->setVisible(true);
//            RelationshipName->setText("Rehtom");
//            RelationshipName->setVisible(true);
//        }
//        else if (Life == 0){
//            BarradeVida->setVisible(false);
//            RelationshipName->setVisible(false);
//            Level4 = true;
//            Life = 100;
//        }

//        if (Personaje->collidesWithItem(Mama)){
//            Personaje->StopEntity(Option);
//        }
//        if (Life > 0 && Brazo->collidesWithItem(Mama) && Attack == true){
//            Life -= 10;
//            BarradeVida->setValue(Life);
//            qDebug() << Life << "\n";
//            Attack = false;
//        }
//    }

//    if (Level == 5 && Level5 == false){

//        if (Life == 100){
//            BarradeVida->setValue(Life);
//            BarradeVida->setVisible(true);
//            BarradeVidaPersonaje->setValue(Life);
//            BarradeVidaPersonaje->setVisible(true);
//            RelationshipName->setText("Rehtaf");
//            RelationshipName->setVisible(true);
//        }
//        else if (Life == 0){
//            BarradeVida->setVisible(false);
//            RelationshipName->setVisible(false);
//            Level5 = true;
//            Life = 100;
//        }

//        if (Personaje->collidesWithItem(Papa)){
//            Personaje->StopEntity(Option);
//        }
//        if (Life > 0 && Brazo->collidesWithItem(Papa) && Attack == true){
//            Life -= 10;
//            BarradeVida->setValue(Life);
//            qDebug() << Life << "\n";
//            Attack = false;
//        }
//    }

//    if (Level == 6 && Level6 == false){

//        if (Life == 100){
//            BarradeVida->setValue(Life);
//            BarradeVida->setVisible(true);
//            BarradeVidaPersonaje->setValue(Life);
//            BarradeVidaPersonaje->setVisible(true);
//            RelationshipName->setText("Smeehc");
//            RelationshipName->setVisible(true);
//        }
//        else if (Life == 0){
//            BarradeVida->setVisible(false);
//            RelationshipName->setVisible(false);
//            Level6 = true;
//            Life = 100;
//        }

//        if (Personaje->collidesWithItem(Cheems)){
//            Personaje->StopEntity(Option);
//        }
//        if (Life > 0 && Brazo->collidesWithItem(Cheems) && Attack == true){
//            Life -= 10;
//            BarradeVida->setValue(Life);
//            qDebug() << Life << "\n";
//            Attack = false;
//        }
//    }

//    if (EnabledKeys == false && Interaction == true){
//        EnabledKeys = true;
//        if (Letter->isVisible()){
//            Letter->setVisible(false);
//        }
//    }

//    if (Life < 50){
//        MainMenu->addItem(SpecialPower);
//    }
//    else{
//        MainMenu->removeItem(SpecialPower);
//    }

//    if (Level == 2 && Life < 50){
//        SpecialPower->Rosa(Hermano->PosX, Hermano->PosY);
//    }
//    else if (Level == 3 && Life < 50){
//        SpecialPower->Lemniscata(Hermana->PosX, Hermana->PosY);
//    }
//    else if (Level == 4 && Life < 50){
//        SpecialPower->Lemniscata(Mama->PosX, Mama->PosY);
//    }
//    else if (Level == 5 && Life < 50){
//        SpecialPower->RosaAlCuadrado(Papa->PosX, Papa->PosY);
//    }
//    else if (Level == 6 && Life < 50){
//        SpecialPower->RosaAlCuadrado(Cheems->PosX, Cheems->PosY);
//    }

////    int Random = 1 + rand() % 15;
////    if (Level == 2 && Life > 0 && StatusLife1 == true){
////        if (Random == 15){

////            Familiar.Persecucion(Hermano, Personaje);
////        }
////    }


//    if(SpecialPower->collidesWithItem(Personaje) && Life < 50){

//        Personaje->StopEntity(Option);

//        LifePersonaje -= 1;
//        BarradeVidaPersonaje->setValue(LifePersonaje);
//    }



}
