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

#include <hitman.h>
#include <entities.h>

#include "hitman.h"
#include "entities.h"


namespace Ui {
class Widget;
}


class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QGraphicsScene *Maps;

    Entities *Slayer;

    int x, y, Width, Height;



};

#endif // WIDGET_H
