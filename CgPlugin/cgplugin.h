#ifndef CGPLUGIN_H
#define CGPLUGIN_H

#include <QObject>
#include "cgplugin_global.h"
#include "../Lib/HaoKeMenuInterface.h"
#include "haokegui.h"
#include "system/limitscommon.h"

class CgPlugin : public QObject, public HaoKeMenuInterface
{
    Q_OBJECT
    Q_INTERFACES(HaoKeMenuInterface)
public:

    QString name() const ;
    QString group() const ;
    QString toolTip() const ;
    QString whatsThis() const ;
    static QString orderWinId() { return HAOKE_PU_ORDER_STR;}
    static QString arrivalWinId() { return HAOKE_PU_ARRIVAL_STR;}
    static QString returnedWinId() { return HAOKE_PU_RETURNED_STR;}
    static QString rdWinId() { return HAOKE_PU_RD_STR;}
    static QString beginRdWinId() { return HAOKE_PU_BEGIN_RD_STR;}
    static QString settleWinId() { return HAOKE_PU_SETTLE_STR;}
    static QString orderQueryWinId() { return HAOKE_PU_ORDERQUERY_STR;}
    static QString orderExecQueryWinId() { return HAOKE_PU_ORDEREXECQUERY_STR;}
    static QString arrivalQueryWinId() { return HAOKE_PU_ARRIVALQUERY_STR;}
    static QString returnedQueryWinId() { return HAOKE_PU_RETURNEDQUERY_STR;}
    static QString rdQueryWinId() { return HAOKE_PU_RDQUERY_STR;}
    static QString settleQueryWinId() { return HAOKE_PU_SETTLEQUERY_STR;}
    static QString systemSetWinId() { return HAOKE_PU_SYSTEMSET_STR;}
    static QString supplieSummaryWinId() { return HAOKE_PU_SUPPLIE_SUMMARY_STR;}
    static QString settleDetaileQueryWinId() { return HAOKE_PU_SETTLE_DETAILE_STR; }
    static QString settleRemainQueryWinId() { return HAOKE_PU_SETTLE_REMAIN_STR; }
    static QString purchaseSummaryWinId() { return HAOKE_PU_PURCHASE_SUMMARY_STR;}
    bool createMenus(QWidget *parent) ;
    bool createNavigation(QWidget *parent);
};

#endif // CGPLUGIN_H
