#-------------------------------------------------
#
# Project created by QtCreator 2021-08-04T22:26:15
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyWindowUi
TEMPLATE = app


SOURCES += main.cpp\
        mymainwindow.cpp \
    smallwidget.cpp \
    mylabelevent.cpp \
    mybuttonevent.cpp

HEADERS  += mymainwindow.h \
    includes.h \
    smallwidget.h \
    mylabelevent.h \
    mybuttonevent.h \
    ../build-MyWindowUi-Desktop_Qt_5_5_0_MinGW_32bit-Debug/ui_mymainwindow.h

FORMS    += mymainwindow.ui

CONFIG   += C++11  resources_big  #添加Lambda表达��  增加资源空间

RESOURCES += \
    image.qrc
