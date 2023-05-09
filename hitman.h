#ifndef HITMAN_H
#define HITMAN_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include <entities.h>


class HitMan : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:

    void keyPressEvent(QKeyEvent *evento, Entities *Entity);
    void MoveUp(Entities *Entity);
    void MoveDown(Entities *Entity);
    void MoveLeft(Entities *Entity);
    void MoveRight(Entities *Entity);


signals:

public slots:

};

#endif // HITMAN_H
