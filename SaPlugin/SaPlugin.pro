#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T15:55:33
#
#-------------------------------------------------

QT       += core network sql script xml

TARGET = SaPlugin
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
DEFINES += SAPLUGIN_LIBRARY

SOURCES += saplugin.cpp \
    samenuaction.cpp \
    dao/saorderdao.cpp \
    dao/sadispatchdao.cpp \
    dao/queryrunner.cpp \
    sa/saorderwin.cpp \
    sa/sadeliverywin.cpp \
    sa/sardwin.cpp \
    dao/sarddao.cpp \
    sa/sareturnedwin.cpp \
    sa/saorderexecqueryform.cpp \
    sa/saorderqueryform.cpp \
    sa/sadeliveryqueryform.cpp \
    sa/sareturnedqueryform.cpp \
    sa/sardqueryform.cpp \
    dao/sapricedao.cpp \
    sa/sapricewin.cpp \
    sa/sasetdialog.cpp \
    sa/sacondeliverwin.cpp \
    sa/saconreturnedwin.cpp \
    sa/sacondeliveryqueryform.cpp \
    sa/saconreturnedqueryform.cpp \
    dao/sasettledao.cpp \
    sa/sasettlewin.cpp \
    sa/saconsettlewin.cpp \
    sa/sasettlequeryform.cpp \
    sa/saconsettlequeryform.cpp \
    sa/sasettledetailequeryform.cpp \
    sa/sasettleremainqueryform.cpp \
    sa/sacussummary.cpp \
    sa/salessummary.cpp

HEADERS += saplugin.h\
        saplugin_global.h \
    samenuaction.h \
    bean/SaOrderVouchsBean.h \
    bean/SaDispatchVouchBean.h \
    dao/saorderdao.h \
    dao/sadispatchdao.h \
    dao/queryrunner.h \
    bean/SaOrderVouchBean.h \
    bean/SaSettleVouchBean.h \
    sa/saorderwin.h \
    sa/sadeliverywin.h \
    bean/SaDispatchVouchsBean.h \
    sa/sardwin.h \
    dao/sarddao.h \
    sa/sareturnedwin.h \
    sa/saorderexecqueryform.h \
    sa/saorderqueryform.h \
    sa/sadeliveryqueryform.h \
    sa/sareturnedqueryform.h \
    sa/sardqueryform.h \
    bean/SaPriceBean.h \
    dao/sapricedao.h \
    sa/sapricewin.h \
    sa/sasetdialog.h \
    sa/sacondeliverwin.h \
    sa/saconreturnedwin.h \
    sa/sacondeliveryqueryform.h \
    sa/saconreturnedqueryform.h \
    bean/SaSettleVouchsBean.h \
    dao/sasettledao.h \
    sa/sasettlewin.h \
    sa/saconsettlewin.h \
    sa/sasettlequeryform.h \
    sa/saconsettlequeryform.h \
    sa/sasettledetailequeryform.h \
    sa/sasettleremainqueryform.h \
    sa/sacussummary.h \
    sa/salessummary.h



unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

TRANSLATIONS += saplugin.ts

FORMS += \
    sa/saorderwin.ui \
    sa/sadeliverywin.ui \
    sa/sardwin.ui \
    sa/sareturnedwin.ui \
    sa/sapricewin.ui \
    sa/sasetdialog.ui \
    sa/sacondeliverwin.ui \
    sa/saconreturnedwin.ui \
    sa/sasettlewin.ui \
    sa/saconsettlewin.ui
