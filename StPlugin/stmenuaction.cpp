#include "stmenuaction.h"
#include "st/allocationwin.h"
#include "st/stcheckwin.h"
#include "st/stinwin.h"
#include "st/stoutwin.h"
#include "st/stinqueryform.h"
#include "st/stoutqueryform.h"
#include "st/allocationqueryform.h"
#include "st/stcheckqueryform.h"
#include "st/ststockquery.h"
#include "st/stinvaccountqueryform.h"
#include "st/stjournalaccountqueryform.h"
#include "stplugin.h"

StMenuAction::StMenuAction(HaoKeGUI *praent):
    mParent(praent)
{
    baseMenu = new QMenu(tr("Stock Management(&I)"),mParent);
    baseMenu->setObjectName("menu.st");
    mainORMenu = new QMenu(tr("OR Sub"),mParent);
    mainODMenu = new QMenu(tr("OD Sub"),mParent);
    mainAIMenu = new QMenu(tr("AI Sub"),mParent);
    mainCIMenu = new QMenu(tr("CI Sub"),mParent);
    mainSReportMenu = new QMenu(tr("REPORT Sub"),mParent);
    QString s="sysAccount";
    if(HaoKeApp::getInstance()->getAccountName() == s ){}
    else{
        mParent->menuBar()->addMenu(baseMenu);
        actionProperties acts[]= {
            { "menu",tr("&Other Receipt"),(char*)mainORMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "st.OtherReceipt",tr("&Other Receipt"),SLOT(sOtherIn()), mainORMenu, "Other Receipt", QPixmap(":/image/home-in.png"), NULL,  true, tr("Other Receipt"),HaoKeApp::stSubId() + StPlugin::otherInWinId()  },
            { "menu",tr("&Other Delivery"),(char*)mainODMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "st.OtherDelivery",tr("&Other Delivery"),SLOT(sOtherOut()), mainODMenu, "Other Delivery", QPixmap(":/image/home-out.png"), NULL,  true, tr("Other Delivery"),HaoKeApp::stSubId() + StPlugin::otherOutWinId() },
            { "menu",tr("&Allocation Invoice"),(char*)mainAIMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "st.Allocation",tr("&Allocation Invoice"),SLOT(sStTrans()), mainAIMenu, "Allocation Invoice", QPixmap(":/image/allocation.png"), NULL,  true, tr("Allocation Invoice"),HaoKeApp::stSubId() + StPlugin::allocationWinId() },
            { "menu",tr("&Check Invoice"),(char*)mainCIMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "st.Check",tr("&Check Invoice"),SLOT(sStCheck()), mainCIMenu, "Check Invoice", QPixmap(":/image/check.png"), NULL,  true, tr("Check Invoice"),HaoKeApp::stSubId() + StPlugin::checkWinId() },
            { "separator",tr("&separator"),NULL, baseMenu, "separator", NULL, NULL,  true, tr("separator"),"0" },
            { "st.AllocationQuery",tr("&Allocation Invoice Query"),SLOT(sStTransQuery()), mainAIMenu, "Allocation Invoice Query", NULL, NULL,  true, tr("Allocation Invoice Query"),HaoKeApp::stSubId() + StPlugin::alloQueryWinId() },
            { "st.CheckQuery",tr("&Check Invoice Query"),SLOT(sStCheckQuery()), mainCIMenu, "Check Invoice Query",NULL, NULL,  true, tr("Check Invoice Query"),HaoKeApp::stSubId() + StPlugin::checkQueryWinId() },
            { "st.ReceiptQuery",tr("&Other Receipt Query"),SLOT(sOtherInQuery()), mainORMenu, "Other Receipt Query", NULL, NULL,  true, tr("Other Receipt Query"),HaoKeApp::stSubId() + StPlugin::otherInQueryWinId() },
            { "st.DeliveryQuery",tr("&Delivery Query"),SLOT(sOtherOutQuery()), mainODMenu, "Delivery Query", NULL, NULL,  true, tr("Delivery Query"),HaoKeApp::stSubId() + StPlugin::otherOutQueryWinId() },
            { "menu",tr("&Stock Report"),(char*)mainSReportMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "st.StInvAccountQuery",tr("&Product Account Query"),SLOT(sStInvAccountQuery()), mainSReportMenu, "Product Account Query", NULL, NULL,  true, tr("Product Account Query"),HaoKeApp::stSubId() + StPlugin::invAccountQueryWinId() },
            { "st.StJournalAccountQuery",tr("&Journal Account Query"),SLOT(sStJournalAccountQuery()), mainSReportMenu, "Journal Account Query", NULL, NULL,  true, tr("Journal Account Query"),HaoKeApp::stSubId() + StPlugin::journalAccountQueryWinId() },
            { "st.StockQuery",tr("&Stock Query"),SLOT(sStQuery()), baseMenu, "Stock Query", QPixmap(":/image/home_search.png"), NULL,  true, tr("Stock Query"),HaoKeApp::stSubId() + StPlugin::stockQueryWinId() }


         };
        addActionsToMenu(acts, sizeof(acts) / sizeof(acts[0]));
    }
}

void StMenuAction::addActionsToMenu(actionProperties acts[], unsigned int numElems){
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
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,"",HaoKeApp::stSubId().toInt(),
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

void StMenuAction::sOtherIn(){
    if(!mParent->subWinIsOpen(tr("Other Receipt"))){
        StInWin *pWin = new StInWin(mParent);
        pWin->setWindowTitle(tr("Other Receipt"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void StMenuAction::sOtherOut(){
    if(!mParent->subWinIsOpen(tr("Other Delivery"))){
        StOutWin *pWin = new StOutWin(mParent);
        pWin->setWindowTitle(tr("Other Delivery"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void StMenuAction::sStOut(){

}

void StMenuAction::sStTrans(){

    if(!mParent->subWinIsOpen(tr("Allocation Invoice"))){
        AllocationWin *pWin = new AllocationWin(mParent);
        pWin->setWindowTitle(tr("Allocation Invoice"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void StMenuAction::sStCheck(){

    if(!mParent->subWinIsOpen(tr("Check Invoice"))){
        StCheckWin *pWin = new StCheckWin(mParent);
        pWin->setWindowTitle(tr("Check Invoice"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void StMenuAction::sStTransQuery(){
    if(!mParent->subWinIsOpen(tr("Allocation Invoice Query"))){
        AllocationQueryForm *pWin = new AllocationQueryForm(mParent);
        pWin->setWindowTitle(tr("Allocation Invoice Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void StMenuAction::sStCheckQuery(){
    if(!mParent->subWinIsOpen(tr("Check Invoice Query"))){
        StCheckQueryForm *pWin = new StCheckQueryForm(mParent);
        pWin->setWindowTitle(tr("Check Invoice Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void StMenuAction::sOtherInQuery(){
    if(!mParent->subWinIsOpen(tr("Other Receipt Query"))){
        StInQueryForm *pWin = new StInQueryForm(mParent);
        pWin->setWindowTitle(tr("Other Receipt Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void StMenuAction::sOtherOutQuery(){
    if(!mParent->subWinIsOpen(tr("Delivery Query"))){
        StOutQueryForm *pWin = new StOutQueryForm(mParent);
        pWin->setWindowTitle(tr("Delivery Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void StMenuAction::sStQuery(){
    if(!mParent->subWinIsOpen(tr("Stock Query"))){
        StStockQuery *pWin = new StStockQuery(mParent);
        pWin->setWindowTitle(tr("Stock Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void StMenuAction::sStInvAccountQuery(){
    if(!mParent->subWinIsOpen(tr("Product Account Query"))){
        StInvAccountQueryForm *pWin = new StInvAccountQueryForm(mParent);
        pWin->setWindowTitle(tr("Product Account Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void StMenuAction::sStJournalAccountQuery(){
    if(!mParent->subWinIsOpen(tr("Journal Account Query"))){
        StJournalAccountQueryForm *pWin = new StJournalAccountQueryForm(mParent);
        pWin->setWindowTitle(tr("Journal Account Query"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
