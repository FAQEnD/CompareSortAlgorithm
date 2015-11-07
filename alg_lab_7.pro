#-------------------------------------------------
#
# Project created by QtCreator 2015-10-27T13:05:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alg_lab_7
TEMPLATE = app
CONFIG += c++11
QMAKE_LFLAGS_WINDOWS += -Wl,--stack,32000000


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    sorts/isort.h \
    sorts/mergesort.h \
    sorts/selectionsort.h \
    sorts/shellsort.h \
    timemanager.h \
    sorts/quicksort.h \
    sorts/countingsort.h \
    sorts/bubblesort.h

FORMS    += mainwindow.ui
