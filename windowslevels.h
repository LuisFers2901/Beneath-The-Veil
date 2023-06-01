#ifndef WINDOWSLEVELS_H
#define WINDOWSLEVELS_H

#include "widget.h"
#include "ui_widget.h"


class WindowsLevels
{
public:

    WindowsLevels(QGraphicsScene *Window);
    ~WindowsLevels();

    void NewScene(QGraphicsScene *Window, int DesktopX, int DesktopY, int UIWidth, int UIHeight);
};

#endif // WINDOWSLEVELS_H
