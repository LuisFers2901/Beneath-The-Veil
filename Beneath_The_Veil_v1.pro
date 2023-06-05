QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barriers.cpp \
    entities.cpp \
    family.cpp \
    levels.cpp \
    listbarriers.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    barriers.h \
    entities.h \
    family.h \
    levels.h \
    listbarriers.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Sounds.qrc \
    pictures.qrc

DISTFILES += \
    Images/Barreras invisible.png \
    Images/Corredor Temporal.png \
    Images/Menu Temp.png \
    Images/Pantalla Inicio Temporal.png \
    Images/SpriteExample.png \
    Images/SpriteExample2.png
