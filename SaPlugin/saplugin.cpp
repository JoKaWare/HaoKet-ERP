#include "saplugin.h"
#include "samenuaction.h"

QString SaPlugin::name() const{
    return tr("Sales Management(&S)");
}

QString SaPlugin::toolTip() const{
    return tr("Sales Management");
}

QString SaPlugin::group() const{
    return tr("Sales Management");
}

QString SaPlugin::whatsThis() const{
    return tr("Sales Management");
}

bool SaPlugin::createMenus(QWidget *parent){
    HaoKeGUI *gui = qobject_cast<HaoKeGUI *>(parent) ;
    SaMenuAction *sMA = new SaMenuAction(gui);
    return true;
}

bool SaPlugin::createNavigation(QWidget *parent){

    return true;
}

Q_EXPORT_PLUGIN2(saplugin, SaPlugin)
