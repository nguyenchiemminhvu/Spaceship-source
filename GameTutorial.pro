#-------------------------------------------------
#
# Project created by QtCreator 2015-05-29T13:39:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bullet.cpp \
    enemy.cpp \
    player.cpp \
    score.cpp \
    graphicsscene.cpp \
    health.cpp \
    emp.cpp

HEADERS  += mainwindow.h \
    bullet.h \
    enemy.h \
    player.h \
    score.h \
    graphicsscene.h \
    health.h \
    emp.h

FORMS    += mainwindow.ui

RESOURCES += \
    MyResource.qrc
