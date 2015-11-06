#ifndef SAPLUGIN_H
#define SAPLUGIN_H


#include <QObject>
#include "saplugin_global.h"
#include "../Lib/HaoKeMenuInterface.h"
#include "haokegui.h"
#include "system/limitscommon.h"

class SaPlugin : public QObject, public HaoKeMenuInterface
{
    Q_OBJECT
    Q_INTERFACES(HaoKeMenuInterface)
public:

    QString name() const ;
    QString group() const ;
    QString toolTip() const ;
    QString whatsThis() const ;

    static QString orderWinId() { return HAOKE_SA_ORDER_STR;}
    static QString deliverylWinId() { return HAOKE_SA_DELIVERY_STR;}
    static QString returnedWinId() { return HAOKE_SA_RETURNED_STR;}
    static QString rdWinId() { return HAOKE_SA_RD_STR;}
    static QString hRdWinId() { return HAOKE_SA_HRD_STR;}
    static QString conRdWinId() { return HAOKE_SA_CONRD_STR;}
    static QString hConRdWinId() { return HAOKE_SA_HCONRD_STR;}
    static QString settleWinId() { return HAOKE_SA_SETTLE_STR;}
    static QString conDeliverylWinId() { return HAOKE_SA_CONDELIVERY_STR;}
    static QString conReturnedWinId() { return HAOKE_SA_CONRETURNED_STR;}
    static QString conSettleWinId() { return HAOKE_SA_CONSETTLE_STR;}
    static QString orderQueryWinId() { return HAOKE_SA_ORDERQUERY_STR;}
    static QString orderExecQueryWinId() { return HAOKE_SA_ORDEREXECQUERY_STR;}
    static QString deliverylQueryWinId() { return HAOKE_SA_DELIVERYQUERY_STR;}
    static QString returnedQueryWinId() { return HAOKE_SA_RETURNEDQUERY_STR;}
    static QString rdQueryWinId() { return HAOKE_SA_RDQUERY_STR;}
    static QString settleQueryWinId() { return HAOKE_SA_SETTLEQUERY_STR;}
    static QString conDeliverylQueryWinId() { return HAOKE_SA_CON_DELIVERYQUERY_STR;}
    static QString conReturnedQueryWinId() { return HAOKE_SA_CON_RETURNEDQUERY_STR;}
    static QString conSettleQueryWinId() { return HAOKE_SA_CON_SETTLEQUERY_STR;}
    static QString systemSetWinId() { return HAOKE_SA_SYSTEMSET_STR;}
    static QString cusSummaryWinId() { return HAOKE_SA_CUSTOMER_SUMMARY_STR;}
    static QString productSummaryWinId() { return HAOKE_SA_PURCHASE_SUMMARY_STR;}
    static QString settleDetaileQueryWinId() { return HAOKE_SA_SETTLE_DETAILE_STR; }
    static QString settleRemainQueryWinId() { return HAOKE_SA_SETTLE_REMAIN_STR; }
    static QString priceWinId() { return HAOKE_SA_PRICE_STR;}

    bool createMenus(QWidget *parent) ;
    bool createNavigation(QWidget *parent);
};

#endif // SAPLUGIN_H
