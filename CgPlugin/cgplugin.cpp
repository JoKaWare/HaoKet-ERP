#include "cgplugin.h"
#include "cgmenuaction.h"
QString CgPlugin::name() const{
    return tr("Purchasing Management(&P)");
}

QString CgPlugin::toolTip() const{
    return tr("Purchasing Management");
}

QString CgPlugin::group() const{
    return tr("Purchasing Management");
}

QString CgPlugin::whatsThis() const{
    return tr("Purchasing Management");
}

bool CgPlugin::createMenus(QWidget *parent){
    HaoKeGUI *gui = qobject_cast<HaoKeGUI *>(parent) ;
    CgMenuAction *cMA = new CgMenuAction(gui);
    return true;
}

bool CgPlugin::createNavigation(QWidget *parent){

    return true;
}

Q_EXPORT_PLUGIN2(cgplugin, CgPlugin)
