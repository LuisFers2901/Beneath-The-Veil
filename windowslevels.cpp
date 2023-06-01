#include "windowslevels.h"


WindowsLevels::WindowsLevels(QGraphicsScene *Window)
{

}

WindowsLevels::~WindowsLevels()
{

}

void WindowsLevels::NewScene(QGraphicsScene *Window, int DesktopX, int DesktopY, int UIWidth, int UIHeight)
{
    Window = new QGraphicsScene();
    Window->setSceneRect(DesktopX, DesktopY, UIWidth, UIHeight);
}
