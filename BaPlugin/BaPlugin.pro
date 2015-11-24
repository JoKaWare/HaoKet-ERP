#-------------------------------------------------
#
# Project created by QtCreator 2014-06-28T17:06:51
#
#-------------------------------------------------

QT       += core sql network xml

TARGET = BaPlugin
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

SOURCES += baplugin.cpp \
    bamenuaction.cpp \
    base/warehouseform.cpp \
    base/typeform.cpp \
    base/tasteform.cpp \
    base/supplieform.cpp \
    base/structureform.cpp \
    base/structuredialog.cpp \
    base/producttypeform.cpp \
    base/productform.cpp \
    base/productdialog.cpp \
    base/positionform.cpp \
    base/marketypeform.cpp \
    base/employeeform.cpp \
    base/emplistdialog.cpp \
    base/dishesform.cpp \
    base/dishesdialog.cpp \
    base/dinnerform.cpp \
    base/depform.cpp \
    base/areaform.cpp \
    dao/structuredao.cpp \
    dao/queryrunner.cpp \
    base/supplietypeform.cpp \
    base/custypeform.cpp \
    base/cusform.cpp \
    base/cusdialog.cpp \
    dao/unitdao.cpp \
    base/unitform.cpp \
    base/invdialog.cpp \
    dao/basedao.cpp

HEADERS += baplugin.h\
        baplugin_global.h \
    bamenuaction.h \
    base/warehouseform.h \
    base/typeform.h \
    base/tasteform.h \
    base/supplieform.h \
    base/structureform.h \
    base/structuredialog.h \
    base/producttypeform.h \
    base/productform.h \
    base/productdialog.h \
    base/positionform.h \
    base/marketypeform.h \
    base/employeeform.h \
    base/emplistdialog.h \
    base/dishesform.h \
    base/dishesdialog.h \
    base/dinnerform.h \
    base/depform.h \
    base/areaform.h \
    dao/structuredao.h \
    bean/StructuresBean.h \
    bean/StructureBean.h \
    dao/queryrunner.h \
    base/supplietypeform.h \
    base/custypeform.h \
    base/cusform.h \
    base/cusdialog.h \
    dao/unitdao.h \
    base/unitform.h \
    base/invdialog.h \
    dao/basedao.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    base/warehouseform.ui \
    base/typeform.ui \
    base/tasteform.ui \
    base/supplieform.ui \
    base/structureform.ui \
    base/structuredialog.ui \
    base/producttypeform.ui \
    base/productform.ui \
    base/productdialog.ui \
    base/positionform.ui \
    base/marketypeform.ui \
    base/employeeform.ui \
    base/emplistdialog.ui \
    base/dishesform.ui \
    base/dishesdialog.ui \
    base/dinnerform.ui \
    base/depform.ui \
    base/areaform.ui \
    base/supplietypeform.ui \
    base/custypeform.ui \
    base/cusform.ui \
    base/cusdialog.ui \
    base/unitform.ui \
    base/invdialog.ui

RESOURCES += \
    goinerp.qrc \
    goinerp.qrc

TRANSLATIONS += baplugin.ts
