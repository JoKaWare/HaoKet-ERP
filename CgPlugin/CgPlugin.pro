#-------------------------------------------------
#
# Project created by QtCreator 2014-06-07T10:07:47
#
#-------------------------------------------------

QT       += core sql network xml script

TARGET = CgPlugin
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

DEFINES += CGPLUGIN_LIBRARY

SOURCES += cgplugin.cpp \
    cgmenuaction.cpp \
    pu/puorderwin.cpp \
    utils/puitemutil.cpp \
    dao/orderdao.cpp \
    dao/queryrunner.cpp \
    pu/puorderqueryform.cpp \
    pu/puarrivalwin.cpp \
    pu/puarrivalqueryform.cpp \
    dao/arrivaldao.cpp \
    pu/pureturnedwin.cpp \
    pu/pureturnedqueryform.cpp \
    pu/purdwin.cpp \
    pu/purdqueryform.cpp \
    pu/pusetdialog.cpp \
    pu/pusettlewin.cpp \
    dao/pusettledao.cpp \
    pu/puorderexecqueryform.cpp \
    dao/purddao.cpp \
    pu/pubeginrdwin.cpp \
    pu/pusettlequeryform.cpp \
    pu/pusuppliesummary.cpp \
    pu/purchasesummary.cpp \
    pu/pusettledetailequeryform.cpp \
    pu/pusettleremainqueryform.cpp

HEADERS += cgplugin.h\
        cgplugin_global.h \
    cgmenuaction.h \
    pu/puorderwin.h \
    bean/PuSettleVouchsBean.h \
    bean/PuSettleVouchBean.h \
    bean/PuOrderVouchsBean.h \
    bean/PuOrderVouchBean.h \
    utils/puitemutil.h \
    dao/orderdao.h \
    dao/queryrunner.h \
    pu/puorderqueryform.h \
    pu/puarrivalwin.h \
    pu/puarrivalqueryform.h \
    bean/PuArrivalVouchBean.h \
    bean/PuArrivalVouchsBean.h \
    dao/arrivaldao.h \
    pu/pureturnedwin.h \
    pu/pureturnedqueryform.h \
    pu/purdwin.h \
    bean/RdsBean.h \
    pu/purdqueryform.h \
    pu/pusetdialog.h \
    pu/pusettlewin.h \
    dao/pusettledao.h \
    pu/puorderexecqueryform.h \
    dao/purddao.h \
    pu/pubeginrdwin.h \
    pu/pusettlequeryform.h \
    pu/pusuppliesummary.h \
    pu/purchasesummary.h \
    pu/pusettledetailequeryform.h \
    pu/pusettleremainqueryform.h \
    ../SaPlugin/bean/SaOrderVouchsBean.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    pu/puorderwin.ui \
    pu/puarrivalwin.ui \
    pu/pureturnedwin.ui \
    pu/purdwin.ui \
    pu/pusetdialog.ui \
    pu/pusettlewin.ui \
    pu/pubeginrdwin.ui

TRANSLATIONS += cgplugin.ts
