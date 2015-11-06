#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T15:40:27
#
#-------------------------------------------------

QT       += network sql script xml

TARGET = StPlugin
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH += ../lib/ ../CommonFiles/log4qt ../CommonFiles/kWidget ../CommonFiles/wwWidgets/widgets ../CommonFiles/wwWidgets/widgets/qwwnumpad ../CommonFiles/wwWidgets/widgets/qwwconfigwidget
win32 {
    #CONFIG(release): LIBS += ../lib/release/parent.lib
    CONFIG(release): LIBS += ../release/commlib.lib ../CommonFiles/lib/log4qt.lib ../CommonFiles/lib/kWidget.lib ../CommonFiles/lib/wwwidgets4.lib
    CONFIG(release):  DESTDIR       = ../release/plugins
    #CONFIG(debug): LIBS += ../debug/commlib.lib ../CommonFiles/lib/log4qt.lib ../CommonFiles/lib/kWidgetd.lib ../CommonFiles/lib/wwwidgets4d.lib
    #CONFIG(debug): DESTDIR = ../debug/plugins
}
DEFINES += STPLUGIN_LIBRARY

SOURCES += stplugin.cpp \
    stmenuaction.cpp \
    st/allocationwin.cpp \
    dao/transdao.cpp \
    dao/queryrunner.cpp \
    dao/stcheckdao.cpp \
    st/stcheckwin.cpp \
    st/stinwin.cpp \
    st/stoutwin.cpp \
    st/stinqueryform.cpp \
    st/stoutqueryform.cpp \
    st/allocationqueryform.cpp \
    st/stcheckqueryform.cpp \
    st/ststockquery.cpp \
    st/stinvaccountqueryform.cpp \
    st/stjournalaccountqueryform.cpp \
    st/strdwin.cpp

HEADERS += stplugin.h\
        stplugin_global.h \
    stmenuaction.h \
    st/allocationwin.h \
    bean/TransVouchsBean.h \
    bean/TransVouchBean.h \
    dao/transdao.h \
    dao/queryrunner.h \
    bean/CheckVouchBean.h \
    bean/CheckVouchsBean.h \
    dao/stcheckdao.h \
    st/stcheckwin.h \
    st/stinwin.h \
    st/stoutwin.h \
    st/stinqueryform.h \
    st/stoutqueryform.h \
    st/allocationqueryform.h \
    st/stcheckqueryform.h \
    st/ststockquery.h \
    st/stinvaccountqueryform.h \
    st/stjournalaccountqueryform.h \
    st/strdwin.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

TRANSLATIONS += stplugin.ts

FORMS += \
    st/allocationwin.ui \
    st/stcheckwin.ui \
    st/stinwin.ui \
    st/stoutwin.ui \
    st/strdwin.ui
