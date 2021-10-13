#-------------------------------------------------
#
# Project created by QtCreator 2021-08-03T21:24:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyWindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    includes.h

FORMS    += \
    Page1Window.ui

CONFIG   += C++11    #添加Lambda表达�

RESOURCES += \
    myresource.qrc