#-------------------------------------------------
#
# Project created by QtCreator 2021-08-13T21:05:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyWindowUiDraw
TEMPLATE = app


SOURCES += main.cpp\
        mymainwindow.cpp

HEADERS  += mymainwindow.h \
    includes.h

FORMS    += mymainwindow.ui

RESOURCES += \
    myresoure.qrc
CONFIG += resources_big
