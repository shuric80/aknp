#-------------------------------------------------
#
# Project created by QtCreator 2014-01-24T15:59:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = aknp_balakovo
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    ake_01.cpp \
    ake_02.cpp \
    aknp_imit/periodimit.cpp \
    aknp_imit/react_imit.cpp \
    aknp_imit/ulineedit.cpp \
    aknp_imit/verify.cpp \
    aknp_imit/aknp_imit.cpp \
    aknp_imit/freqgenerator.cpp \
    mainwidget.cpp \
    cansocketdriver.cpp \
    canthread.cpp \
    slotmainwidget.cpp \
    topclass.cpp \
    slotoutwidget.cpp

HEADERS  += widget.h \
    ake_01.h \
    ake_02.h \
    aknp_imit/ulineedit.h \
    aknp_imit/freqgenerator.h \
    aknp_imit/verify.h \
    aknp_imit/react_imit.h \
    aknp_imit/periodimit.h \
    aknp_imit/aknp_imit.h \
    mainwidget.h \
    cansocketdriver.h \
    canthread.h \
    slotmainwidget.h \
    topclass.h \
    slotoutwidget.h

