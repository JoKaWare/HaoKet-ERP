#-------------------------------------------------
#
# Project created by QtCreator 2014-09-01T11:07:07
#
#-------------------------------------------------

QT       += core sql network xml script
TARGET = WFaPlugin
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
DEFINES += WFAPLUGIN_LIBRARY
SOURCES += wfaplugin.cpp \
    wfamenuaction.cpp \
    dao/apclosebilldao.cpp \
    dao/queryrunner.cpp \
    fa/apbillwin.cpp \
    fa/arbillwin.cpp \
    dao/kmcodedao.cpp \
    fa/kmform.cpp \
    fa/faaccntform.cpp \
    dao/faaccntdao.cpp \
    fa/fawaydialog.cpp \
    fa/fasubsidiaryqueryform.cpp \
    fa/fatransceiverssummaryqueryform.cpp \
    fa/recoveraccountdialog.cpp

HEADERS += wfaplugin.h\
        wfaplugin_global.h \
    wfamenuaction.h \
    bean/ApCloseBillBean.h \
    bean/ApCloseBillsBean.h \
    dao/apclosebilldao.h \
    dao/queryrunner.h \
    fa/apbillwin.h \
    bean/ApTypeBean.h \
    fa/arbillwin.h \
    bean/KmCodeBean.h \
    dao/kmcodedao.h \
    fa/kmform.h \
    bean/FaSubsidiaryBean.h \
    bean/FaSummaryBean.h \
    fa/faaccntform.h \
    dao/faaccntdao.h \
    bean/FaWayBean.h \
    fa/fawaydialog.h \
    fa/fasubsidiaryqueryform.h \
    fa/fatransceiverssummaryqueryform.h \
    fa/recoveraccountdialog.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

TRANSLATIONS += faplugin.ts

FORMS += \
    fa/apbillwin.ui \
    fa/arbillwin.ui \
    fa/kmform.ui \
    fa/faaccntform.ui \
    fa/fawaydialog.ui \
    fa/recoveraccountdialog.ui
