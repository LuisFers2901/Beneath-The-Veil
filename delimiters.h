#ifndef DELIMITERS_H
#define DELIMITERS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Delimiters
{
public:

    int WidthDelimiters, HeightDelimiters, X, Y;

    Delimiters(int X, int Y, int WidthDelimiters, int HeightDelimiters);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // DELIMITERS_H
