#include "bcplugin.h"

#include "bcmenuaction.h"

QString BcPlugin::name() const{
    return tr("Sales Management(&S)");
}

QString BcPlugin::toolTip() const{
    return tr("Sales Management");
}

QString BcPlugin::group() const{
    return tr("Sales Management");
}

QString BcPlugin::whatsThis() const{
    return tr("Sales Management");
}

bool BcPlugin::createMenus(QWidget *parent){
    HaoKeGUI *gui = qobject_cast<HaoKeGUI *>(parent) ;
    BcMenuAction *bMA = new BcMenuAction(gui);
    return true;
}

bool BcPlugin::createNavigation(QWidget *parent){

    return true;
}

Q_EXPORT_PLUGIN2(bcplugin, BcPlugin)
