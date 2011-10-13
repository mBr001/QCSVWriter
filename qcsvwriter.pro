#-------------------------------------------------
#
# Project created by QtCreator 2011-10-13T15:57:45
#
#-------------------------------------------------

QT       -= gui

TARGET = QCSVWriter
TEMPLATE = lib
# comment/uncomment to build dinamic/static library
CONFIG += staticlib

VERSION = 0.0.1

DEFINES += QCSVWRITER_LIBRARY

SOURCES += qcsvwriter.cpp

HEADERS += qcsvwriter.h\
        QCSVWriter.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
