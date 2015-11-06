#include "stplugin.h"
#include "stmenuaction.h"

QString StPlugin::name() const{
    return tr("Stock Management(&I)");
}

QString StPlugin::toolTip() const{
    return tr("Stock Management");
}

QString StPlugin::group() const{
    return tr("Stock Management");
}

QString StPlugin::whatsThis() const{
    return tr("Stock Management");
}

bool StPlugin::createMenus(QWidget *parent){
    HaoKeGUI *gui = qobject_cast<HaoKeGUI *>(parent) ;
    StMenuAction *sMA = new StMenuAction(gui);
    return true;
}

bool StPlugin::createNavigation(QWidget *parent){

    return true;
}

Q_EXPORT_PLUGIN2(stplugin, StPlugin)
