#ifndef BCPLUGIN_H
#define BCPLUGIN_H

#include <QObject>
#include "bcplugin_global.h"
#include "../Lib/HaoKeMenuInterface.h"
#include "haokegui.h"
#include "bean/RdInImeiBean.h"
#include "system/limitscommon.h"

class BcPlugin : public QObject, public HaoKeMenuInterface
{
    Q_OBJECT
    Q_INTERFACES(HaoKeMenuInterface)
public:

    QString name() const ;
    QString group() const ;
    QString toolTip() const ;
    QString whatsThis() const ;

    static QString rdInImeiWinId() { return HAOKE_BC_RDINIMEI_STR;}
    static QString rdOutImeiWinId() { return HAOKE_BC_RDOUTIMEI_STR;}
    static QString transImeiWinId() { return HAOKE_BC_TRANSIMEI_STR;}
    static QString rdInImeiQueryWinId() { return HAOKE_BC_RDINIMEIQUERY_STR;}
    static QString rdInListQueryWinId() { return HAOKE_BC_RDINLISTQUERY_STR;}
    static QString rdReInImeiQueryWinId() { return HAOKE_BC_RDREINIMEIQUERY_STR;}
    static QString rdOutImeiQueryWinId() { return HAOKE_BC_RDOUTIMEIQUERY_STR;}
    static QString rdOutListQueryWinId() { return HAOKE_BC_RDOUTLISTQUERY_STR;}
    static QString rdReOutImeiQueryWinId() { return HAOKE_BC_RDREOUTIMEIQUERY_STR;}
    static QString transImeiQueryWinId() {return HAOKE_BC_TRANSIMEIQUERY_STR;}
    static QString stockImeiQueryWinId() {return HAOKE_BC_STOCKIMEIQUERY_STR;}
    static QString imeiQueryWinId() {return HAOKE_BC_IMEIQUERY_STR;}
    bool createMenus(QWidget *parent) ;
    bool createNavigation(QWidget *parent);
};

#endif // BCPLUGIN_H
