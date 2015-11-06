#ifndef BAPLUGIN_H
#define BAPLUGIN_H

#include <QObject>
#include "baplugin_global.h"
#include "../Lib/HaoKeMenuInterface.h"
#include "haokegui.h"
#include "log4qt/logger.h"
class BaPlugin : public QObject, public HaoKeMenuInterface
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
    Q_INTERFACES(HaoKeMenuInterface)
public:

    QString name() const ;
    QString group() const ;
    QString toolTip() const ;
    QString whatsThis() const ;
    static QString baAreaWinId() { return HAOKE_BA_AREA_STR;}
    static QString baCusWinId() { return HAOKE_BA_CUS_STR;}
    static QString baCusTypeWinId() { return HAOKE_BA_CUSTYPE_STR;}
    static QString baCusSWinId() { return HAOKE_BA_CUSFORM_STR;}
    static QString baDepWinId() { return HAOKE_BA_DEP_STR;}
    static QString baEmpWinId() { return HAOKE_BA_EMP_STR;}
    static QString baProWinId() { return HAOKE_BA_PRO_STR;}
    static QString baProSWinId() { return HAOKE_BA_PROFORM_STR;}
    static QString baProTypeWinId() { return HAOKE_BA_PROTYPE_STR;}
    static QString baSupWinId() { return HAOKE_BA_SUP_STR;}
    static QString baSupTypeWinId() { return HAOKE_BA_SUPTYPE_STR;}
    static QString baTypeWinId() { return HAOKE_BA_TYPE_STR;}
    static QString baWareWinId() { return HAOKE_BA_WAREHOUSE_STR;}
    static QString baTasteWinId() { return HAOKE_BA_TASTE_STR;}
    static QString baPositionWinId() { return HAOKE_BA_POSITION_STR;}
    static QString baUnitWinId() { return HAOKE_BA_UNIT_STR;}

    bool createMenus(QWidget *parent) ;
    bool createNavigation(QWidget *parent);
    static void authority(QGridLayout *layout,int winId,QString winTitle);
};

#endif // BAPLUGIN_H
