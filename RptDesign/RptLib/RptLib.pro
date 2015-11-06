#-------------------------------------------------
#
# Project created by QtCreator 2014-07-10T17:24:03
#
#-------------------------------------------------

QT       -= gui

TARGET = RptLib
TEMPLATE = lib

DEFINES += RPTLIB_LIBRARY

SOURCES += rptlib.cpp

HEADERS += rptlib.h\
        rptlib_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
