#-------------------------------------------------
#
# Project created by QtCreator 2011-07-31T16:05:05
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_qcsvwritertest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += tst_qcsvwritertest.cpp \
    ../qcsvwriter.cpp \
    ../qcsvcell.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../qcsvwriter.h \
    ../qcsvcell.h


