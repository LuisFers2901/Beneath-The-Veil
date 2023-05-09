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
    showFullScreen();

    Maps = new QGraphicsScene();
    ui->graphicsView->setScene(Maps);
    Maps->setSceneRect(x, y, ui->graphicsView->width()-2, ui->graphicsView->height()-2);

    Slayer = new Entities(100,100,120,130,3,65);

}

Widget::~Widget()
{
    delete ui;
}







