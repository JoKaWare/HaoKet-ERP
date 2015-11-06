#-------------------------------------------------
#
# Project created by QtCreator 2014-04-17T19:19:46
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HaoKeLERP
TEMPLATE = app
INCLUDEPATH += lib/ E:/qtproj/log4qt/src
build_all:!build_pass {
    CONFIG -= build_all
    CONFIG += release
}
win32 {
    CONFIG(release): LIBS += release/commlib.lib
    #CONFIG(debug): LIBS += debug/commlib.lib
}
#MOC_DIR = build
#OBJECTS_DIR = build
#RCC_DIR = build

MOC_DIR = buildD
OBJECTS_DIR = buildD
RCC_DIR = buildD

SOURCES += main.cpp

HEADERS  +=

OTHER_FILES +=
RC_FILE = logo.rc

