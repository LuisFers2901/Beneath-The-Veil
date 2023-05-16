#include "widget.h"
#include "ui_widget.h"
#include "delimiters.h"


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

    Maps = new QGraphicsScene();
    ui->graphicsView->setScene(Maps);
    Maps->setSceneRect(x, y, ui->graphicsView->width()-2, ui->graphicsView->height()-2);
    showFullScreen();

    Slayer = new Delimiters(100, 100, 10, 10);
    Maps->addItem(Slayer);

}

Widget::~Widget()
{
    delete ui;
}
