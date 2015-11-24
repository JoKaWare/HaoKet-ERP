#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T17:37:28
#
#-------------------------------------------------
QT       += core sql network xml script gui
TARGET = BcPlugin
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH += ../lib/ ../CommonFiles/log4qt ../CommonFiles/kWidget ../CommonFiles/wwWidgets/widgets ../CommonFiles/wwWidgets/widgets/qwwnumpad ../CommonFiles/wwWidgets/widgets/qwwconfigwidget
win32 {
    #CONFIG(release): LIBS += ../lib/release/parent.lib
    CONFIG(release): LIBS += ../release/commlib.lib ../CommonFiles/lib/log4qt.lib ../CommonFiles/lib/kWidget.lib ../CommonFiles/lib/wwwidgets4.lib
    CONFIG(release):  DESTDIR       = ../release/plugins
    #CONFIG(debug): LIBS += ../debug/commlib.lib ../CommonFiles/lib/log4qtd.lib ../CommonFiles/lib/kWidgetd.lib ../CommonFiles/lib/wwwidgets4d.lib
    #CONFIG(debug): DESTDIR = ../debug/plugins
}
DEFINES += BCPLUGIN_LIBRARY

SOURCES += bcplugin.cpp \
    bcmenuaction.cpp \
    dao/imeidao.cpp \
    bc/rdinimeiwin.cpp \
    bc/rdimeiquery.cpp \
    bc/rdqueryform.cpp \
    dao/queryrunner.cpp \
    dao/inimeidao.cpp \
    dao/outimeidao.cpp \
    dao/stimeidao.cpp \
    bc/importdialog.cpp \
    bc/inimeiqueryform.cpp \
    bc/rdoutimeiwin.cpp \
    bc/outimeiqueryform.cpp \
    bc/rdoutimeiquery.cpp \
    bc/transimeiwin.cpp \
    dao/transimeidao.cpp \
    bc/transimeiquery.cpp \
    bc/stockimeiquery.cpp \
    bc/imeiquery.cpp

HEADERS += bcplugin.h\
        bcplugin_global.h \
    bcmenuaction.h \
    bean/RdInImeiBean.h \
    dao/imeidao.h \
    bc/rdinimeiwin.h \
    bc/rdimeiquery.h \
    bc/rdqueryform.h \
    dao/queryrunner.h \
    dao/inimeidao.h \
    dao/outimeidao.h \
    dao/stimeidao.h \
    bc/importdialog.h \
    bc/inimeiqueryform.h \
    bc/rdoutimeiwin.h \
    bc/outimeiqueryform.h \
    bc/rdoutimeiquery.h \
    bc/transimeiwin.h \
    dao/transimeidao.h \
    bean/TransImeiBean.h \
    bean/TransVouchsBean.h \
    bean/TransVouchBean.h \
    bc/transimeiquery.h \
    bc/stockimeiquery.h \
    bc/imeiquery.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    bc/rdinimeiwin.ui \
    bc/rdqueryform.ui \
    bc/importdialog.ui \
    bc/rdoutimeiwin.ui \
    bc/transimeiwin.ui


TRANSLATIONS += bcplugin.ts
