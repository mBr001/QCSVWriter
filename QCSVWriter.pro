#-------------------------------------------------
#
# Project created by QtCreator 2011-10-13T15:57:45
#
#-------------------------------------------------

QT       -= gui

TARGET = QCSVWriter
TEMPLATE = lib

VERSION = 0.0.1

DEFINES += QCSVWRITER_LIBRARY

SOURCES += qcsvwriter.cpp

HEADERS += qcsvwriter.h\
        QCSVWriter.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE0A9C3B1
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = QCSVWriter.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
