#include "bcmenuaction.h"
#include "bc/rdinimeiwin.h"
#include "bc/rdimeiquery.h"
#include "bc/rdqueryform.h"
#include "bc/inimeiqueryform.h"
#include "bc/rdoutimeiwin.h"
#include "bc/outimeiqueryform.h"
#include "bc/rdoutimeiquery.h"
#include "bc/transimeiwin.h"
#include "bc/transimeiquery.h"
#include "bc/stockimeiquery.h"
#include "bc/imeiquery.h"

#include "bcplugin.h"
BcMenuAction::BcMenuAction(HaoKeGUI *parent):
    mParent(parent)
{
    baseMenu = new QMenu(tr("´®Âë¹ÜÀí(&C)"),mParent);
    baseMenu->setObjectName("menu.st");
    mainBIMenu = new QMenu(tr("BI Sub"),mParent);
    mainBOMenu = new QMenu(tr("BO Sub"),mParent);
    mainBTMenu = new QMenu(tr("BT Sub"),mParent);
    mainBPMenu = new QMenu(tr("BP Sub"),mParent);
    QString s="sysAccount";
    if(HaoKeApp::getInstance()->getAccountName() == s ){}
    else{
        mParent->menuBar()->addMenu(baseMenu);
        actionProperties acts[]= {
            { "menu",tr("&Receipt IMEI"),(char*)mainBIMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "bc.RdInImei",tr("&Receipt IMEI"),SLOT(sRdInImei()), mainBIMenu, "&Receipt IMEI", QPixmap(":/image/page_add.png"), NULL,  true, tr("Receipt IMEI"),HaoKeApp::bcSubId() + BcPlugin::rdInImeiWinId() },
            { "bc.RdInListQuery",tr("&Receipt List"),SLOT(sRdInListQuery()), mainBIMenu, "&Receipt List", NULL, NULL,  true, tr("Receipt List"),HaoKeApp::bcSubId() + BcPlugin::rdInListQueryWinId() },
            { "bc.RdInImeiQuery",tr("&Receipt IMEI Query"),SLOT(sRdInImeiQuery()), mainBIMenu, "&Receipt IMEI Query", QPixmap(":/image/page_add.png"), NULL,  true, tr("Receipt IMEI Query"),HaoKeApp::bcSubId() + BcPlugin::rdInImeiQueryWinId() },
            { "bc.RdReInImeiQuery",tr("&Returned Receipt IMEI Query"),SLOT(sRdReInImeiQuery()), mainBIMenu, "&Returned Receipt IMEI Query", NULL, NULL,  true, tr("Returned Receipt IMEI Query"),HaoKeApp::bcSubId() + BcPlugin::rdReInImeiQueryWinId() },
            { "menu",tr("&Out Receipt IMEI"),(char*)mainBOMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "bc.RdOutImei",tr("&Out Receipt IMEI"),SLOT(sRdOutImei()), mainBOMenu, "&Out Receipt IMEI", QPixmap(":/image/page_add.png"), NULL,  true, tr("Out Receipt IMEI"),HaoKeApp::bcSubId() + BcPlugin::rdOutImeiWinId() },
            { "bc.RdOutListQuery",tr("&Out Receipt List"),SLOT(sRdOutListQuery()), mainBOMenu, "&Out Receipt List", NULL, NULL,  true, tr("Out Receipt List"),HaoKeApp::bcSubId() + BcPlugin::rdOutListQueryWinId() },
            { "bc.RdOutImeiQuery",tr("&Out Receipt IMEI Query"),SLOT(sRdOutImeiQuery()), mainBOMenu, "&Out Receipt IMEI Query", NULL, NULL,  true, tr("Out Receipt IMEI Query"),HaoKeApp::bcSubId() + BcPlugin::rdOutImeiQueryWinId() },
            { "bc.RdReOutImeiQuery",tr("&Returned Out Receipt IMEI Query"),SLOT(sRdReOutImeiQuery()), mainBOMenu, "&Returned Out Receipt IMEI Query", NULL, NULL,  true, tr("Returned Out Receipt IMEI Query"),HaoKeApp::bcSubId() + BcPlugin::rdReOutImeiQueryWinId() },
            { "menu",tr("&Trans IMEI"),(char*)mainBTMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "bc.TransImei",tr("&Trans IMEI"),SLOT(sTransImei()), mainBTMenu, "&Trans IMEI",NULL, NULL,  true, tr("Trans IMEI"),HaoKeApp::bcSubId() + BcPlugin::transImeiWinId() },
            { "bc.TransImeiQuery",tr("&Trans IMEI Query"),SLOT(sTransImeiQuery()), mainBTMenu, "&Trans IMEI Query",NULL, NULL,  true, tr("Trans IMEI Query"),HaoKeApp::bcSubId() + BcPlugin::transImeiQueryWinId() },
            { "menu",tr("&IMEI Query"),(char*)mainBPMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "bc.StockImeiQuery",tr("&Stock IMEI Query"),SLOT(sStockImeiQuery()), mainBPMenu, "&Stock IMEI Query",NULL, NULL,  true, tr("Stock IMEI Query"),HaoKeApp::bcSubId() + BcPlugin::stockImeiQueryWinId() },
            { "bc.ImeiQuery",tr("&IMEI Query"),SLOT(sImeiQuery()), mainBPMenu, "&IMEI Query",NULL, NULL,  true, tr("IMEI Query"),HaoKeApp::bcSubId() + BcPlugin::imeiQueryWinId() }
        };
        addActionsToMenu(acts, sizeof(acts) / sizeof(acts[0]));
    }
}

void BcMenuAction::addActionsToMenu(actionProperties acts[], unsigned int numElems){
    QAction * m = 0;
    for (unsigned int i = 0; i < numElems; i++)
    {
        if (! acts[i].visible){
            continue;
        }else if (acts[i].actionName == QString("menu")){
            m = acts[i].menu->addMenu((QMenu*)(acts[i].slot));
            if(m)
                m->setText(acts[i].actionTitle);
        }else if (acts[i].actionName == QString("separator")) {
            acts[i].menu->addSeparator();
        }else if(acts[i].toolBar !=NULL){
            new KAction( mParent,
                        acts[i].actionName,
                        acts[i].actionTitle,
                        this,
                        acts[i].slot,
                        acts[i].menu,
                        acts[i].visible,
                        acts[i].pixmap,
                        acts[i].toolBar) ;
        }else{
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,"",HaoKeApp::bcSubId().toInt(),
                                   acts[i].menuId.toInt(),0,acts[i].toolTip,acts[i].actionName);

            new KAction( mParent,
                        acts[i].actionName,
                        acts[i].actionTitle,
                        this,
                        acts[i].slot,
                        acts[i].menu,
                        acts[i].visible,
                        acts[i].pixmap) ;
        }
   }

}

void BcMenuAction::sRdInImei(){
    if(!mParent->subWinIsOpen(tr("Receipt IMEI"))){
        RdInImeiWin *pWin = new RdInImeiWin(mParent);
        pWin->setWindowTitle(tr("Receipt IMEI"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void BcMenuAction::sRdInImeiQuery(){
    if(!mParent->subWinIsOpen(tr("Receipt IMEI Query"))){
        RdImeiQuery *pWin = new RdImeiQuery(mParent);
        pWin->setWindowTitle(tr("Receipt IMEI Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void BcMenuAction::sRdReInImeiQuery(){
    if(!mParent->subWinIsOpen(tr("Returned Receipt IMEI Query"))){
        RdImeiQuery *pWin = new RdImeiQuery(HaoKeApp::getVouchRdSaRe(), mParent);
        pWin->setWindowTitle(tr("Returned Receipt IMEI Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void BcMenuAction::sRdInListQuery(){
    if(!mParent->subWinIsOpen(tr("Receipt List Query"))){
        InImeiQueryForm *pWin = new InImeiQueryForm(mParent);
        pWin->setWindowTitle(tr("Receipt List Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void BcMenuAction::sRdOutImei(){
    if(!mParent->subWinIsOpen(tr("Out Receipt IMEI"))){
        RdOutImeiWin *pWin = new RdOutImeiWin(mParent);
        pWin->setWindowTitle(tr("Out Receipt IMEI"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void BcMenuAction::sRdOutImeiQuery(){
    if(!mParent->subWinIsOpen(tr("Out Receipt IMEI Query"))){
        RdOutImeiQuery *pWin = new RdOutImeiQuery(mParent);
        pWin->setWindowTitle(tr("Out Receipt IMEI Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void BcMenuAction::sRdReOutImeiQuery(){
    if(!mParent->subWinIsOpen(tr("Returned Out Receipt IMEI Query"))){
        RdOutImeiQuery *pWin = new RdOutImeiQuery(HaoKeApp::getVouchRdPuRe(), mParent);
        pWin->setWindowTitle(tr("Returned Out Receipt IMEI Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void BcMenuAction::sRdOutListQuery(){
    if(!mParent->subWinIsOpen(tr("Out Receipt List"))){
        OutImeiQueryForm *pWin = new OutImeiQueryForm(mParent);
        pWin->setWindowTitle(tr("Out Receipt List"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void BcMenuAction::sTransImei(){
    if(!mParent->subWinIsOpen(tr("Trans IMEI"))){
        TransImeiWin *pWin = new TransImeiWin(mParent);
        pWin->setWindowTitle(tr("Trans IMEI"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void BcMenuAction::sTransImeiQuery(){
    if(!mParent->subWinIsOpen(tr("Trans IMEI Query"))){
        TransImeiQuery *pWin = new TransImeiQuery(mParent);
        pWin->setWindowTitle(tr("Trans IMEI Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void BcMenuAction::sStockImeiQuery(){
    if(!mParent->subWinIsOpen(tr("Stock IMEI Query"))){
        StockImeiQuery *pWin = new StockImeiQuery(mParent);
        pWin->setWindowTitle(tr("Stock IMEI Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void BcMenuAction::sImeiQuery(){
    if(!mParent->subWinIsOpen(tr("IMEI Query"))){
        ImeiQuery *pWin = new ImeiQuery(mParent);
        pWin->setWindowTitle(tr("IMEI Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

