#ifndef WFAPLUGIN_H
#define WFAPLUGIN_H
#include <QObject>
#include "wfaplugin_global.h"
#include "HaoKeMenuInterface.h"
#include "haokegui.h"
#include "system/limitscommon.h"

class WFaPlugin : public QObject, public HaoKeMenuInterface
{
    Q_OBJECT
    Q_INTERFACES(HaoKeMenuInterface)
public:

    QString name() const ;
    QString group() const ;
    QString toolTip() const ;
    QString whatsThis() const ;
    static QString apWinId() { return HAOKE_FA_AP_STR;}
    static QString arWinId() { return HAOKE_FA_AR_STR;}
    static QString apBillWinId() { return HAOKE_FA_AP_BILL_STR;}
    static QString arBillWinId() { return HAOKE_FA_AR_BILL_STR;}
    static QString faBillACCNTWinId() { return HAOKE_FA_BILL_ACCNT_STR;}
    static QString faBillCancelACCNTWinId() { return HAOKE_FA_BILL_CANCEL_ACCNT_STR;}
    static QString faSubsidiaryWinId() { return HAOKE_FA_SUBSIDIARY_STR;}
    static QString faSummaryWinId() { return HAOKE_FA_SUMMARY_STR;}
    static QString faTransceiversSummaryWinId() { return HAOKE_FA_TRANSCEIVERS_SUMMARY_STR;}
    static QString apBillQueryWinId() { return HAOKE_FA_AP_BILL_QUERY_STR;}
    static QString arBillQueryWinId() { return HAOKE_FA_AR_BILL_QUERY_STR;}
    static QString costAccountSetWinId() { return HAOKE_FA_COSTACCOUNT_SET_STR;}
    static QString kmWinId() { return HAOKE_FA_KM_STR;}
    bool createMenus(QWidget *parent) ;
    bool createNavigation(QWidget *parent);
    static void authority(QGridLayout *layout, int winId,QString winTitle);
};

#endif // WFAPLUGIN_H
