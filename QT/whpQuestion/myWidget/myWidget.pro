#-------------------------------------------------
#
# Project created by QtCreator 2021-09-24T13:53:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myWidget
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    threadhandle.cpp

HEADERS  += mywidget.h \
    threadhandle.h \
    includes.h

FORMS    += mywidget.ui
