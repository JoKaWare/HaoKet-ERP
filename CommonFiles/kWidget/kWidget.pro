#-------------------------------------------------
#
# Project created by QtCreator 2012-12-21T10:34:04
#
#-------------------------------------------------

QT     += core gui

TARGET = kWidget
TEMPLATE = lib
DEFINES += KWIDGET_LIBRARY

SOURCES += \
    qksearcheditbox.cpp \
    qkgridview.cpp \
    qkgridlistview.cpp \
    qkbuttonview.cpp \
    qktableview.cpp

HEADERS +=\
        kWidget_global.h \
    qksearcheditbox_p.h \
    qksearcheditbox.h \
    qkgridview.h \
    qkgridlistview.h \
    qkbuttonview.h \
    qktableview.h


symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE4DF8010
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = kWidget.dll
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

OTHER_FILES += \
    Makefile.Debug

RESOURCES += \
    kwidget.qrc
