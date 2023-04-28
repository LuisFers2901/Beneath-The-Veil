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

#include "hitman.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget

{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;

    HitMan *Slayer;

    float x, y, Width, Height;


};

#endif // WIDGET_H
