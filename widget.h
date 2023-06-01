#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QApplication>
#include <QScreen>
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QIcon>
#include <QList>
#include <QLabel>
#include <QFont>
#include <QString>
#include <random>
#include <QSoundEffect>
#include <QMediaPlayer>

#include "hitman.h"
#include "entities.h"
#include "barriers.h"
#include "listbarriers.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_BEGIN_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QGraphicsScene *MainMenu;


    QBrush br1, br2;

    int Level = 1;
    int Option;


    void keyPressEvent(QKeyEvent *evento);
    void EvalueCollision();

    Entities *Personaje;
    Entities *Hermano;
    Entities *Hermana;
    Entities *Mama;
    Entities *Papa;
    Entities *Chemms;

    bool Level1 = true;
    bool Level2 = false;
    bool Level3 = false;
    bool Level4 = false;
    bool Level5 = false;
    bool Level6 = false;
    bool Level7 = false;

    bool    KeyLevel1 = true;
    bool    KeyLevel2 = false;
    bool    KeyLevel3 = false;
    bool    KeyLevel4 = false;
    bool    KeyLevel5 = false;
    bool    KeyLevel6 = false;
    bool    KeyLevel7 = false;

    bool Interaction = false;

    ListBarriers BarriersMaps;

    QList<QGraphicsItem*> ListObjectsScene;



    int DesktopX, DesktopY, DesktopWidth, DesktopHeight;
    int UIWidth, UIHeight;



};

#endif // WIDGET_H
