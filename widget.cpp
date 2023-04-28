#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QScreen* primaryScreen = QApplication::primaryScreen();
    QRect Desktop = primaryScreen->geometry();
    x = Desktop.x();
    y = Desktop.y();
    Width = Desktop.width();
    Height = Desktop.height();

    scene = new QGraphicsScene(x, y, Width, Height);

    ui->graphicsView->setScene(scene);

    Slayer = new HitMan();

    scene->addItem(Slayer);

    Slayer->setPos(960, 540);

}

Widget::~Widget()
{
    delete ui;
}




