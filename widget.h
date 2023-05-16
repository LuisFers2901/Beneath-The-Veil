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
#include "entities.h"
#include "delimiters.h"

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
    QGraphicsScene *Maps;

    Delimiters *Slayer;

    int x, y, Width, Height;



};

#endif // WIDGET_H
