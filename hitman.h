#ifndef HITMAN_H
#define HITMAN_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>



class HitMan : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit HitMan(QObject *parent = nullptr);

    QTimer *Timer;
    QPixmap *PixMap;

    float Rows, Columns, Width, Height;

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


signals:

public slots:

    void RefreshSprite();

};

#endif // HITMAN_H
