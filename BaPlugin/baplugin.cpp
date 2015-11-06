#include "baplugin.h"
#include "bamenuaction.h"
#include "system/limitscommon.h"

QString BaPlugin::name() const{
    return tr("Base Info(&B)");
}

QString BaPlugin::toolTip() const{
    return tr("Base Info");
}

QString BaPlugin::group() const{
    return tr("Base Info");
}

QString BaPlugin::whatsThis() const{
    return tr("Base Info");
}

bool BaPlugin::createMenus(QWidget *parent){
    HaoKeGUI *gui = qobject_cast<HaoKeGUI *>(parent) ;
    BaMenuAction *bMA = new BaMenuAction(gui);
    return true;
}

bool BaPlugin::createNavigation(QWidget *parent){

    return true;
}

/**
 * @brief BaPlugin::authority 权限按纽控制
 * @param layout
 * @param winId
 */
void BaPlugin::authority(QGridLayout *layout, int winId,QString winTitle){
    int v = 1;
    //Log4Qt::PropertyConfigurator::configure(QApplication::applicationDirPath() + "/log4j.properties");
    //Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
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
                    if(!LimitsCommon::getUserRoleLimits(HaoKeApp::getInstance()->getUserId(),widget->objectName(),winId)){
                        widget->setEnabled(false);
                        //logger->debug(widget->objectName() + " WINID:" + QString::number(winId));
                    }
                }
             }
         }
    }
}

Q_EXPORT_PLUGIN2(baplugin, BaPlugin)
