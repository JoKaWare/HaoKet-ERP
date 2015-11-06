#include "wfaplugin.h"
#include "wfamenuaction.h"

QString WFaPlugin::name() const{
    return tr("Financial Management(&I)");
}

QString WFaPlugin::toolTip() const{
    return tr("Financial Management");
}

QString WFaPlugin::group() const{
    return tr("Financial Management");
}

QString WFaPlugin::whatsThis() const{
    return tr("Financial Management");
}

bool WFaPlugin::createMenus(QWidget *parent){
    HaoKeGUI *gui = qobject_cast<HaoKeGUI *>(parent) ;
    WFaMenuAction *sMA = new WFaMenuAction(gui);
    return true;
}

bool WFaPlugin::createNavigation(QWidget *parent){

    return true;
}
/**
 * @brief WFaPlugin::authority 权限按纽控制
 * @param layout
 * @param winId
 * @param winTitle
 */
void WFaPlugin::authority(QGridLayout *layout, int winId,QString winTitle){
    int v = 1;
    for(int i = 0 ; i < layout->rowCount(); i ++){
        for(int j =0 ; j < layout->columnCount(); j ++ ){
            QLayoutItem *layoutItem = layout->itemAtPosition(i,j);

            if(layoutItem && !layoutItem->isEmpty()){
                QWidget *widget = layoutItem->widget();

                QString className = widget->metaObject()->className();

                if(className == "QPushButton" || className == "QToolButton"){
                    if(widget->objectName().contains("cancel") || widget->objectName().contains("close")){
                        return ;
                    }
                    QString procId =QString::number(winId) + QString::number(v);
                    HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::baSubId().toInt(),winId,procId.toInt(),widget->toolTip(),widget->objectName());
                    v = v + 1;
                    if(!LimitsCommon::getUserRoleLimits(HaoKeApp::getInstance()->getUserId(),widget->objectName(),winId))
                        widget->setEnabled(false);
                }
             }
         }
    }
}
Q_EXPORT_PLUGIN2(wfaplugin, WFaPlugin)
