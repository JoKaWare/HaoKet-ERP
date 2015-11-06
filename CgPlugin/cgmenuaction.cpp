#include "cgmenuaction.h"
#include "widget/queryform.h"
#include "pu/puorderqueryform.h"
#include "pu/puarrivalwin.h"
#include "pu/pureturnedwin.h"
#include "pu/purdwin.h"
#include "pu/pubeginrdwin.h"
#include "pu/puarrivalqueryform.h"
#include "pu/pureturnedqueryform.h"
#include "pu/purdqueryform.h"
#include "pu/pusettlewin.h"
#include "pu/pusetdialog.h"
#include "pu/puorderexecqueryform.h"
#include "pu/pusettlequeryform.h"
#include "pu/purchasesummary.h"
#include "pu/pusuppliesummary.h"
#include "pu/pusettledetailequeryform.h"
#include "pu/pusettleremainqueryform.h"
#include "widget/ProxyModelWithHeaderModels.h"
#include "widget/hierarchicalheaderview.h"
#include "cgplugin.h"

CgMenuAction::CgMenuAction(HaoKeGUI *praent):
    mParent(praent)
{
    baseMenu = new QMenu(tr("Purchase Management(&U)"),mParent);
    baseMenu->setObjectName("menu.pu");
    mainPOMenu = new QMenu(tr("PO Sub"),mParent);
    mainPSMenu = new QMenu(tr("PS Sub"),mParent);
    mainPRMenu = new QMenu(tr("PR Sub"),mParent);
    mainPPMenu = new QMenu(tr("PP Sub"),mParent);
    mainPMMenu = new QMenu(tr("PM Sub"),mParent);
    mainPReportMenu = new QMenu(tr("PReport Sub"),mParent);
    QString s="sysAccount";
    if(HaoKeApp::getInstance()->getAccountName() == s ){}
    else{
        mParent->menuBar()->addMenu(baseMenu);
        actionProperties acts[]= {
            { "menu",tr("&Purchase Order"),(char*)mainPOMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "pu.puOrder",tr("&Purchase Order"),SLOT(sPuOrder()), mainPOMenu, "Purchase Order", QPixmap(":/image/page_add.png"), NULL,  true, tr("Purchase Order"),HaoKeApp::puSubId() + CgPlugin::orderWinId() },
            { "menu",tr("&Purchase Arrival"),(char*)mainPRMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "pu.puArrival",tr("&Purchase Arrival"),SLOT(sPuArrival()), mainPRMenu, "Purchase Arrival", NULL, NULL,  true, tr("Purchase Arrival"),HaoKeApp::puSubId() + CgPlugin::arrivalWinId() },
            { "pu.puReturned",tr("&Purchase Returned"),SLOT(sRePurchase()), mainPRMenu, "Purchase Returned", QPixmap(":/image/home-re.png"), NULL,  true, tr("Purchase Returned"),HaoKeApp::puSubId() + CgPlugin::returnedWinId() },
            { "menu",tr("&Purchase Receipt"),(char*)mainPSMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "pu.puReceipt",tr("&Purchase Receipt"),SLOT(sPuReceipt()), mainPSMenu, "Purchase Receipt", QPixmap(":/image/home-in.png"), NULL,  true, tr("Purchase Receipt"),HaoKeApp::puSubId() + CgPlugin::rdWinId() },
            { "pu.puReceipt",tr("&Purchase HReceipt"),SLOT(sPuHReceipt()), mainPSMenu, "Purchase HReceipt", NULL, NULL,  true, tr("Purchase HReceipt"),HaoKeApp::puSubId() + CgPlugin::rdWinId() },
            { "menu",tr("&Purchase Settle"),(char*)mainPPMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "pu.puSettle",tr("&Purchase Settle"),SLOT(sPuSettle()), mainPPMenu, "Purchase Settle", QPixmap(":/image/page_accept.png"), NULL,  true, tr("Purchase Settle"),HaoKeApp::puSubId() + CgPlugin::settleWinId() },
            { "separator",tr("&separator"),NULL, baseMenu, "separator", NULL, NULL,  true, tr("separator"),"0" },
            { "pu.puOrderQuery",tr("&Purchase Order Query"),SLOT(sPuOrderList()), mainPOMenu, "Purchase Order Query", NULL, NULL,  true, tr("Purchase Order Query"),HaoKeApp::puSubId() + CgPlugin::orderQueryWinId() },
            { "pu.puOrderExecList",tr("&Purchase Order Execution List"),SLOT(sPuOrderExecList()), mainPOMenu, "Purchase Order Execution List", NULL, NULL,  true, tr("Purchase Order Execution List"),HaoKeApp::puSubId() + CgPlugin::orderExecQueryWinId() },
            { "pu.puReceiptQuery",tr("&Purchase Receipt Query"),SLOT(sPuReceiptList()), mainPSMenu, "Purchase Receipt Query", NULL, NULL,  true, tr("Purchase Receipt Query"),HaoKeApp::puSubId() + CgPlugin::rdQueryWinId() },
            { "pu.puArrivalQuery",tr("&Purchase Arrival Query"),SLOT(sPuArrivalQuery()), mainPRMenu, "Purchase Arrival Query", NULL, NULL,  true, tr("Purchase Arrival Query"),HaoKeApp::puSubId() + CgPlugin::arrivalQueryWinId() },
            { "pu.puReturnedQuery",tr("&Purchase Returned Query"),SLOT(sRePurchaseList()), mainPRMenu, "Purchase Returned Query", NULL, NULL,  true, tr("Purchase Returned Query"),HaoKeApp::puSubId() + CgPlugin::returnedQueryWinId() },
            { "pu.puSettlQuery",tr("Purchase Settle Query"),SLOT(sPuSettleList()), mainPPMenu, "Purchase Settle Query", NULL, NULL,  true, tr("Purchase Settle Query"),HaoKeApp::puSubId() + CgPlugin::settleQueryWinId() },
            { "menu",tr("&Purchase Report"),(char*)mainPReportMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "pu.supSummaryQuery",tr("&Supplier delivery summary"),SLOT(sPuDeliverySummary()), mainPReportMenu, "Supplier delivery summary", NULL, NULL,  true, tr("Supplier delivery summary"),HaoKeApp::puSubId() + CgPlugin::supplieSummaryWinId() },
            { "pu.puSummaryQuery",tr("&Purchase Summary"),SLOT(sPuProductSummary()), mainPReportMenu, "Purchase Summary", NULL, NULL,  true, tr("Purchase Summary"),HaoKeApp::puSubId() + CgPlugin::purchaseSummaryWinId() },
            { "pu.puSettleDetaileQuery",tr("&Purchase Settle Detaile Query"),SLOT(sPuSettleDetaileQuery()), mainPReportMenu, "Purchase Settle Detaile Query", NULL, NULL,  true, tr("Purchase Settle Detaile Query"),HaoKeApp::puSubId() + CgPlugin::settleDetaileQueryWinId()},
            { "pu.puSettleRemainQuery",tr("&Purchase Settle Remain Query"),SLOT(sPuSettleRemainQuery()), mainPReportMenu, "Purchase Settle Remain Query", NULL, NULL,  true, tr("Purchase Settle Remain Query"),HaoKeApp::puSubId() + CgPlugin::settleRemainQueryWinId()},
            { "separator",tr("&separator"),NULL, baseMenu, "separator", NULL, NULL,  true, tr("separator"),"0" },
            { "menu",tr("&Purchase Set"),(char*)mainPMMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "pu.puBegin",tr("&Purchase Begin"),SLOT(sPuBegin()), mainPMMenu, "Purchase Begin", NULL, NULL,  true, tr("Purchase Begin"),HaoKeApp::puSubId() + CgPlugin::beginRdWinId() },
            { "pu.puSystemSet",tr("&Purchase System Set"),SLOT(sPuSet()), mainPMMenu, "Purchase System Set", NULL, NULL,  true, tr("Purchase System Set"),HaoKeApp::puSubId() + CgPlugin::systemSetWinId() }

        };
        addActionsToMenu(acts, sizeof(acts) / sizeof(acts[0]));
    }
}

void CgMenuAction::addActionsToMenu(actionProperties acts[], unsigned int numElems){
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
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,"",HaoKeApp::puSubId().toInt(),
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

void CgMenuAction::sPuOrder(){

    if(!mParent->subWinIsOpen(tr("Purchase Order"))){
        PuOrderWin *pWin = new PuOrderWin(mParent);
        pWin->setWindowTitle(tr("Purchase Order"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }


}

void CgMenuAction::sPuArrival(){
    if(!mParent->subWinIsOpen(tr("Purchase Arrival"))){
        PuArrivalWin *pWin = new PuArrivalWin(mParent);
        pWin->setWindowTitle(tr("Purchase Arrival"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void CgMenuAction::sPuArrivalQuery(){
    if(!mParent->subWinIsOpen(tr("Purchase Arrival Query"))){

        PuArrivalQueryForm *pWin = new PuArrivalQueryForm(mParent);
        pWin->setWindowTitle(tr("Purchase Arrival Query"));
        pWin->setDwLableText("供应商分类:","供应商名称:");

        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void CgMenuAction::sPuHReceipt(){
    if(!mParent->subWinIsOpen(tr("Purchase HReceipt"))){
        PuRdWin *pWin = new PuRdWin(RdFlag::RdOutFlag,mParent);
        pWin->setWindowTitle(tr("Purchase HReceipt"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void CgMenuAction::sPuReceipt(){

    if(!mParent->subWinIsOpen(tr("Purchase Receipt"))){
        PuRdWin *pWin = new PuRdWin(mParent);
        pWin->setWindowTitle(tr("Purchase Receipt"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
    /*
    if(!mParent->subWinIsOpen(tr("Purchase Receipt"))){
        PuWindow *pWin = new PuWindow(mParent);
        pWin->setWindowTitle(tr("Purchase Receipt"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
    */
}

void CgMenuAction::sPuSet(){
    PuSetDialog *sDlg = new PuSetDialog(mParent);
    sDlg->show();
}

void CgMenuAction::sPuBegin(){
    if(!mParent->subWinIsOpen(tr("Purchase Begin"))){
        PuBeginRdWin *pWin = new PuBeginRdWin(mParent);
        pWin->setWindowTitle(tr("Purchase Begin"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void CgMenuAction::sPuSettle(){

    if(!mParent->subWinIsOpen(tr("Purchase Settle"))){
        PuSettleWin *pWin = new PuSettleWin(mParent);
        pWin->setWindowTitle(tr("Purchase Settle"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }

}

void CgMenuAction::sRePurchase(){

    if(!mParent->subWinIsOpen(tr("Purchase Returned"))){
        PuReturnedWin *pWin = new PuReturnedWin(mParent);
        pWin->setWindowTitle(tr("Purchase Returned"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }

}

void CgMenuAction::sPuAccount(){
    /*
    if(!mParent->subWinIsOpen(tr("Supplier Accounts"))){
        PuAccountQueryForm *pWin = new PuAccountQueryForm(mParent);
        pWin->setWindowTitle(tr("Supplier Accounts"));
        mParent->addSubWin(pWin);

        pWin->showMaximized();
    }
    */
}

void CgMenuAction::sPuOrderList(){
    /*
    if(!mParent->subWinIsOpen(tr("Purchase Order List"))){
        PuOrderListForm *pWin = new PuOrderListForm(mParent);
        pWin->setWindowTitle(tr("Purchase Order List"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
    */
    if(!mParent->subWinIsOpen(tr("Purchase Order Query"))){

        PuOrderQueryForm *pWin = new PuOrderQueryForm(mParent);
        pWin->setWindowTitle(tr("Purchase Order Query"));
        pWin->setDwLableText("供应商分类:","供应商名称:");

        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }

}

void CgMenuAction::sPuOrderExecList(){
    if(!mParent->subWinIsOpen(tr("Purchase Order Execution List"))){

        PuOrderExecQueryForm *pWin = new PuOrderExecQueryForm(mParent);
        pWin->setWindowTitle(tr("Purchase Order Execution List"));
        pWin->setDwLableText("供应商分类:","供应商名称:");

        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void CgMenuAction::sPuSettleList(){

    if(!mParent->subWinIsOpen(tr("Purchase Settle Query"))){
        PuSettleQueryForm *pWin = new PuSettleQueryForm(mParent);
        pWin->setWindowTitle(tr("Purchase Settle Query"));
        pWin->setDwLableText("供应商分类:","供应商名称:");

        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }

}

void CgMenuAction::sPuReceiptList(){
    if(!mParent->subWinIsOpen(tr("Purchase Receipt Query"))){

        PuRdQueryForm *pWin = new PuRdQueryForm(mParent);
        pWin->setWindowTitle(tr("Purchase Receipt Query"));
        pWin->setDwLableText("供应商分类:","供应商名称:");

        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
    /*
    if(!mParent->subWinIsOpen(tr("Purchase Receipt List"))){
        RdListForm *pWin = new RdListForm(mParent);
        pWin->setWindowTitle(tr("Purchase Receipt List"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
    */
}

void CgMenuAction::sRePurchaseList(){

    if(!mParent->subWinIsOpen(tr("Purchase Returned Query"))){
        PuReturnedQueryForm *pWin = new PuReturnedQueryForm(mParent);
        pWin->setWindowTitle(tr("Purchase Returned Query"));
        pWin->setDwLableText("供应商分类:","供应商名称:");

        mParent->addSubWin(pWin);

        pWin->showMaximized();
    }

}

void CgMenuAction::sPuDeliverySummary(){

    if(!mParent->subWinIsOpen(tr("Supplier delivery summary"))){
        PuSupplieSummary *pWin = new PuSupplieSummary(mParent);
        pWin->setWindowTitle(tr("Supplier delivery summary"));
        mParent->addSubWin(pWin);
        pWin->setDwLableText("供应商:","供应商名称:");
        pWin->showMaximized();
    }

}



void CgMenuAction::sPuProductSummary(){

    if(!mParent->subWinIsOpen(tr("Purchase Summary"))){
        PurchaseSummary *pWin = new PurchaseSummary(mParent);
        pWin->setWindowTitle(tr("Purchase Summary"));
        mParent->addSubWin(pWin);
        pWin->setDwLableText("供应商:","供应商名称:");
        pWin->showMaximized();
    }

}

void CgMenuAction::sPuSettleDetaileQuery(){
    if(!mParent->subWinIsOpen(tr("Purchase Settle Detaile Query"))){
        PuSettleDetaileQueryForm *pWin = new PuSettleDetaileQueryForm(mParent);
        pWin->setWindowTitle(tr("Purchase Settle Detaile Query"));
        mParent->addSubWin(pWin);
        pWin->setDwLableText("供应商分类:","供应商名称:");
        pWin->showMaximized();
    }
}

void CgMenuAction::sPuSettleRemainQuery(){
    if(!mParent->subWinIsOpen(tr("Purchase Settle Remain Query"))){
        PuSettleRemainQueryForm *pWin = new PuSettleRemainQueryForm(mParent);
        pWin->setWindowTitle(tr("Purchase Settle Remain Query"));
        mParent->addSubWin(pWin);
        pWin->setDwLableText("供应商分类:","供应商名称:");
        pWin->showMaximized();
    }
}



