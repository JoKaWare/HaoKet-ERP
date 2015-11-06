#ifndef STPLUGIN_H
#define STPLUGIN_H

#include <QObject>
#include "stplugin_global.h"
#include "../Lib/HaoKeMenuInterface.h"
#include "haokegui.h"
#include "system/limitscommon.h"

class StPlugin : public QObject, public HaoKeMenuInterface
{
    Q_OBJECT
    Q_INTERFACES(HaoKeMenuInterface)
public:

    QString name() const ;
    QString group() const ;
    QString toolTip() const ;
    QString whatsThis() const ;
    static QString allocationWinId() { return HAOKE_ST_ALLOCATION_STR;}
    static QString checkWinId() { return HAOKE_ST_CHECK_STR;}
    static QString otherInWinId() { return HAOKE_ST_OTHERIN_STR;}
    static QString otherOutWinId() { return HAOKE_ST_OTHEROUT_STR;}
    static QString alloQueryWinId() { return HAOKE_ST_ALLOCATION_QUERY_STR;}
    static QString checkQueryWinId() {return HAOKE_ST_CHECK_QUERY_STR;}
    static QString otherInQueryWinId() {return HAOKE_ST_OTHERIN_QUERY_STR;}
    static QString otherOutQueryWinId() {return HAOKE_ST_OTHEROUT_QUERY_STR;}
    static QString systemWinId() {return HAOKE_ST_SYSTEM_STR;}
    static QString stockQueryWinId() {return HAOKE_ST_STOCK_QUERY_STR;}
    static QString invAccountQueryWinId() {return HAOKE_ST_INV_ACCOUNT_QUERY_STR;}
    static QString journalAccountQueryWinId() {return HAOKE_ST_JOURNAL_ACCOUNT_QUERY_STR;}
    bool createMenus(QWidget *parent) ;
    bool createNavigation(QWidget *parent);
};

#endif // STPLUGIN_H
