#-------------------------------------------------
#
# Project created by QtCreator 2014-05-09T22:37:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    welcomescreen.cpp \
    wizard_loadimages.cpp \
    wizard_selectimage.cpp \
    selectregionwidget.cpp \
    tissueviewer.cpp \
    layerslide.cpp \
    wizardcontroller.cpp \
    wizarddataconfig.cpp \
    wizard_processfiles.cpp \
    loadworkerthread.cpp \
    mriscene.cpp \
    processworkerthread.cpp \
    dataset.cpp

HEADERS  += mainwindow.h \
    welcomescreen.h \
    wizard_loadimages.h \
    wizard_selectimage.h \
    selectregionwidget.h \
    tissueviewer.h \
    layerslide.h \
    wizardcontroller.h \
    wizarddataconfig.h \
    wizard_processfiles.h \
    loadworkerthread.h \
    mriscene.h \
    processworkerthread.h \
    dataset.h

FORMS    += mainwindow.ui \
    welcomescreen.ui \
    wizard_loadimages.ui \
    wizard_selectimage.ui \
    selectregionwidget.ui \
    tissueviewer.ui \
    layerslide.ui \
    wizard_processfiles.ui

RESOURCES += \
    resource.qrc
