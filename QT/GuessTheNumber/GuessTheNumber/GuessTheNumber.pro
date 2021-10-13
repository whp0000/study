#-------------------------------------------------
#
# Project created by QtCreator 2021-08-18T21:43:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GuessTheNumber
TEMPLATE = app


SOURCES += main.cpp\
        gamewidget.cpp

HEADERS  += gamewidget.h \
    includes.h

FORMS    += gamewidget.ui

CONFIG   += C++11  resources_big  #添加Lambda表达��  增加资源空间

RESOURCES += \
    myresources.qrc
