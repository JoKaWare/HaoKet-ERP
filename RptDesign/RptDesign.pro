#-------------------------------------------------
#
# Project created by QtCreator 2012-03-29T16:09:02
#
#-------------------------------------------------

QT       += core gui xml sql network

TARGET = RptDesign
TEMPLATE = lib
DEFINES += RPTLIB_LIBRARY

INCLUDEPATH += ../lib/ E:/qtproj/log4qt/src

win32 {
    #CONFIG(release): LIBS += ../lib/release/parent.lib
    #CONFIG(release): LIBS += ../release/commlib.lib E:/qtproj/log4qt/src/release/log4qt.lib E:/qtproj/kWidget-plug/kWidget/release/kWidget.lib E:/qtproj/wwWidgets/widgets/release/wwwidgets4.lib
    #CONFIG(release):  DESTDIR       = ../release
    CONFIG(debug): LIBS += ../debug/commlib.lib E:/qtproj/log4qt/src/debug/log4qt.lib
    CONFIG(debug): DESTDIR = ../debug
}
SOURCES +=\
        mainwindow.cpp \
    PageSettingDlg.cpp \
    ReportBand.cpp \
    tcontainerfield.cpp \
    CommonFiles/qlabelex.cpp \
    CommonFiles/tcontainer.cpp \
    EditFldDlg.cpp \
    aboutDlg.cpp \
    languagedlg.cpp \
    FldPropertyDlg.cpp \
    RepScrollArea.cpp \
    editordelegate.cpp

HEADERS  += mainwindow.h \
    PageSettingDlg.h \
    ReportBand.h \
    tcontainerfield.h \
    CommonFiles/qlabelex.h \
    CommonFiles/tcontainer.h \
    EditFldDlg.h \
    aboutDlg.h \
    languagedlg.h \
    FldPropertyDlg.h \
    RepScrollArea.h \
    LibGlobal.h \
    editordelegate.h

FORMS    += mainwindow.ui \
    PageSettingDlg.ui \
    ReportBand.ui \
    EditFldDlg.ui \
    languagedlg.ui \
    FldPropertyDlg.ui \
    RepScrollArea.ui

RESOURCES += \
    images.qrc

#TRANSLATIONS += i18n/QtRprtDesigner_ru_RU.ts


 #win32:INCLUDEPATH += "../CommonFiles/"
 #unix:INCLUDEPATH += "/home/user/extra headers"
