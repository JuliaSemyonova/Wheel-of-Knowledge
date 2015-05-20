#-------------------------------------------------
#
# Project created by QtCreator 2015-03-21T02:49:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WheelOfKnowledge
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

OTHER_FILES +=

TRANSLATIONS = wheel_ru.ts

RESOURCES += \
    resource.qrc
