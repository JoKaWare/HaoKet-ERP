#include "samenuaction.h"
#include "sa/saorderwin.h"
#include "sa/sadeliverywin.h"
#include "sa/sardwin.h"
#include "sa/sareturnedwin.h"
#include "sa/sacondeliverwin.h"
#include "sa/saconreturnedwin.h"
#include "sa/saconsettlewin.h"
#include "sa/sasettlewin.h"
#include "sa/saorderexecqueryform.h"
#include "sa/saorderqueryform.h"
#include "sa/sadeliveryqueryform.h"
#include "sa/sareturnedqueryform.h"
#include "sa/sacondeliveryqueryform.h"
#include "sa/saconreturnedqueryform.h"
#include "sa/saconsettlequeryform.h"
#include "sa/sasettlequeryform.h"
#include "sa/sasettledetailequeryform.h"
#include "sa/sasettleremainqueryform.h"
#include "sa/sacussummary.h"
#include "sa/salessummary.h"
#include "sa/sardqueryform.h"
#include "sa/sapricewin.h"
#include "sa/sasetdialog.h"
#include "saplugin.h"

SaMenuAction::SaMenuAction(HaoKeGUI *parent) :
    mParent(parent)
{
    baseMenu = new QMenu(tr("Sales Management(&A)"),mParent);
    baseMenu->setObjectName("menu.sa");
    mainSOMenu = new QMenu(tr("SO Sub"),mParent);
    mainSDMenu = new QMenu(tr("SD Sub"),mParent);
    mainSCMenu = new QMenu(tr("SC Sub"),mParent);
    mainSAMenu = new QMenu(tr("SA Sub"),mParent);
    mainSSMenu = new QMenu(tr("SS Sub"),mParent);
    mainSReportMenu = new QMenu(tr("SReport Sub"),mParent);
    QString s="sysAccount";
    if(HaoKeApp::getInstance()->getAccountName() == s ){}
    else{
        mParent->menuBar()->addMenu(baseMenu);
        actionProperties acts[]= {
            { "menu",tr("&Sales Order"),(char*)mainSOMenu,baseMenu,"true",NULL, NULL,true, NULL},
            { "sa.saOrder",tr("&Sales Order"),SLOT(sSaOrder()), mainSOMenu, "Sales Order", QPixmap(":/image/page_add.png"), NULL,  true, tr("Sales Order"),HaoKeApp::saSubId() + SaPlugin::orderWinId() },
            { "menu",tr("&Sales Delivery"),(char*)mainSDMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "sa.saDelivery",tr("&Sales Delivery"),SLOT(sSaDelivery()), mainSDMenu, "Sales Delivery", NULL, NULL,  true, tr("Sales Delivery"),HaoKeApp::saSubId() + SaPlugin::deliverylWinId() },
            { "sa.saReturned",tr("&Sales Returned"),SLOT(sReSales()), mainSDMenu, "Sales Returned", QPixmap(":/image/home-re.png"), NULL,  true, tr("Sales Returned"),HaoKeApp::saSubId() + SaPlugin::returnedWinId() },
            { "menu",tr("&Sales Consignment"),(char*)mainSCMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "sa.saConsignmentDelivery",tr("&Consignment Delivery"),SLOT(sSaConDelivery()), mainSCMenu, "Consignment Delivery", NULL, NULL,  true, tr("Consignment Delivery"),HaoKeApp::saSubId() + SaPlugin::conDeliverylWinId() },
            { "sa.saConsignmentReturned",tr("&Consignment Returned"),SLOT(sReConSales()), mainSCMenu, "Consignment Returned", NULL, NULL,  true, tr("Consignment Returned"),HaoKeApp::saSubId() + SaPlugin::conReturnedWinId() },
            { "sa.saConsignmentSettle",tr("&Consignment Settle"),SLOT(sSaConSettle()), mainSCMenu, "Consignment Settle", NULL, NULL,  true, tr("Consignment Settle"),HaoKeApp::saSubId() + SaPlugin::conSettleWinId() },
            { "sa.saConsignmentDeliveryQuery",tr("&Consignment Delivery Query"),SLOT(sSaConDeliveryQuery()), mainSCMenu, "Consignment Delivery Query", NULL, NULL,  true, tr("Consignment Delivery Query"),HaoKeApp::saSubId() + SaPlugin::conDeliverylQueryWinId() },
            { "sa.saConsignmentReturnedQuery",tr("&Consignment Returned Query"),SLOT(sReConSalesQuery()), mainSCMenu, "Consignment Returned Query", NULL, NULL,  true, tr("Consignment Returned Query"),HaoKeApp::saSubId() + SaPlugin::conReturnedQueryWinId() },
            { "sa.saConsignmentSettleQuery",tr("&Consignment Settle Query"),SLOT(sSaConSettleQuery()), mainSCMenu, "Consignment Settle Query", NULL, NULL,  true, tr("Consignment Settle Query"),HaoKeApp::saSubId() + SaPlugin::conSettleQueryWinId() },
            { "menu",tr("&Sales Receipt"),(char*)mainSAMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "sa.saReceipt",tr("&Sales Receipt"),SLOT(sSaReceipt()), mainSAMenu, "Sales Receipt", QPixmap(":/image/home-in.png"), NULL,  true, tr("Sales Receipt"),HaoKeApp::saSubId() + SaPlugin::rdWinId() },
            { "sa.saHReceipt",tr("&Sales HReceipt"),SLOT(sSaHReceipt()), mainSAMenu, "Sales HReceipt", NULL, NULL,  true, tr("Sales HReceipt"),HaoKeApp::saSubId() + SaPlugin::hRdWinId() },
            { "sa.saConReceipt",tr("&Consignment Receipt"),SLOT(sSaConReceipt()), mainSAMenu, "Consignment Receipt", QPixmap(":/image/home-in.png"), NULL,  true, tr("Consignment Receipt"),HaoKeApp::saSubId() + SaPlugin::conRdWinId() },
            { "sa.saHConReceipt",tr("&Consignment HReceipt"),SLOT(sSaHConReceipt()), mainSAMenu, "Consignment HReceipt", NULL, NULL,  true, tr("Consignment HReceipt"),HaoKeApp::saSubId() + SaPlugin::hConRdWinId()},

            { "menu",tr("&Sales Settle"),(char*)mainSSMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "sa.saSettle",tr("&Sales Settle"),SLOT(sSaSettle()), mainSSMenu, "Sales Settle", QPixmap(":/image/page_accept.png"), NULL,  true, tr("Sales Settle"),HaoKeApp::saSubId() + SaPlugin::settleWinId() },
            { "separator",tr("&separator"),NULL, baseMenu, "separator", NULL, NULL,  true, tr("separator") },
            { "sa.saOrderQuery",tr("&Sales Order Query"),SLOT(sSaOrderQuery()), mainSOMenu, "Sales Order Query", NULL, NULL,  true, tr("Sales Order Query"),HaoKeApp::saSubId() + SaPlugin::orderQueryWinId() },
            { "sa.saOrderExecList",tr("&Sales Order Execution List"),SLOT(sSaOrderExecQuery()), mainSOMenu, "Sales Order Execution List", NULL, NULL,  true, tr("Sales Order Execution List"),HaoKeApp::saSubId() + SaPlugin::orderExecQueryWinId() },
            { "sa.saReceiptQuery",tr("&Sales Receipt Query"),SLOT(sSaReceiptQuery()), mainSAMenu, "Sales Receipt Query", NULL, NULL,  true, tr("Sales Receipt Query"),HaoKeApp::saSubId() + SaPlugin::rdQueryWinId() },
            { "sa.saDeliveryQuery",tr("&Sales Delivery Query"),SLOT(sSaDeliveryQuery()), mainSDMenu, "Sales Delivery Query", NULL, NULL,  true, tr("Sales Delivery Query"),HaoKeApp::saSubId() + SaPlugin::deliverylQueryWinId() },
            { "sa.saReturnedQuery",tr("&Sales Returned Query"),SLOT(sReSalesQuery()), mainSDMenu, "Sales Returned Query", NULL, NULL,  true, tr("Sales Returned Query"),HaoKeApp::saSubId() + SaPlugin::returnedQueryWinId() },
            { "sa.saSettlQuery",tr("Sales Settle Query"),SLOT(sSaSettleQuery()), mainSSMenu, "Sales Settle Query", NULL, NULL,  true, tr("Sales Settle Query"),HaoKeApp::saSubId() + SaPlugin::settleQueryWinId() },
            { "menu",tr("&Sales Report"),(char*)mainSReportMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "sa.saSettleDetaileQuery",tr("&Sales Settle Detaile Query"),SLOT(sSaSettleDetaileQuery()), mainSReportMenu, "Sales Settle Detaile Query", NULL, NULL,  true, tr("Sales Settle Detaile Query"),HaoKeApp::saSubId() + SaPlugin::settleDetaileQueryWinId()},
            { "sa.saSettleRemainQuery",tr("Sales Settle Remain Query"),SLOT(sSaSettleRemainQuery()), mainSReportMenu, "Sales Settle Remain Query", NULL, NULL,  true, tr("Sales Settle Remain Query"),HaoKeApp::saSubId() + SaPlugin::settleRemainQueryWinId()},
            { "sa.saConsignmentSettleDetaileQuery",tr("&Consignment Settle Detaile Query"),SLOT(sSaConSettleDetaileQuery()), mainSReportMenu, "Consignment Settle Detaile Query", NULL, NULL,  true, tr("Consignment Settle Detaile Query"),HaoKeApp::saSubId() + SaPlugin::settleDetaileQueryWinId()},
            { "sa.saConsignmentSettleRemainQuery",tr("&Consignment Settle Remain Query"),SLOT(sSaConSettleRemainQuery()), mainSReportMenu, "Consignment Settle Remain Query", NULL, NULL,  true, tr("Consignment Settle Remain Query"),HaoKeApp::saSubId() + SaPlugin::settleRemainQueryWinId()},
            { "sa.suSummaryQuery",tr("&Customer delivery summary"),SLOT(sSaDeliverySummary()), mainSReportMenu, "Customer delivery summary", NULL, NULL,  true, tr("Customer delivery summary"),HaoKeApp::saSubId() + SaPlugin::cusSummaryWinId() },
            { "sa.saSummaryQuery",tr("&Sales Summary"),SLOT(sSaProductSummary()), mainSReportMenu, "Sales Summary", NULL, NULL,  true, tr("Sales Summary"),HaoKeApp::saSubId() + SaPlugin::productSummaryWinId() },
            { "separator",tr("&separator"),NULL, baseMenu, "separator", NULL, NULL,  true, tr("separator"),"0" },
            { "sa.suPrice",tr("&Sales Price Report"),SLOT(sSaPrice()), baseMenu, "Sales Price Report", NULL, NULL,  true, tr("Sales Price Report"),HaoKeApp::saSubId() + SaPlugin::priceWinId() },
            { "sa.saSystemSet",tr("&Sales System Set"),SLOT(sSaSet()), baseMenu, "Sales System Set", NULL, NULL,  true, tr("Sales System Set"),HaoKeApp::saSubId() + SaPlugin::systemSetWinId() }

        };
        addActionsToMenu(acts, sizeof(acts) / sizeof(acts[0]));
        //QApplication::setOverrideCursor(Qt::WaitCursor);

        //QApplication::restoreOverrideCursor();
    }
}

void SaMenuAction::addActionsToMenu(actionProperties acts[], unsigned int numElems){
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
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,"",HaoKeApp::saSubId().toInt(),
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

void SaMenuAction::sSaOrder(){
    if(!mParent->subWinIsOpen(tr("Sales Order"))){
        SaOrderWin *pWin = new SaOrderWin(mParent);
        pWin->setWindowTitle(tr("Sales Order"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaDelivery(){
    if(!mParent->subWinIsOpen(tr("Sales Delivery"))){
        SaDeliveryWin *pWin = new SaDeliveryWin(mParent);
        pWin->setWindowTitle(tr("Sales Delivery"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sReSales(){
    if(!mParent->subWinIsOpen(tr("Sales Returned"))){
        SaReturnedWin *pWin = new SaReturnedWin(mParent);
        pWin->setWindowTitle(tr("Sales Returned"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaReceipt(){
    if(!mParent->subWinIsOpen(tr("Sales Receipt"))){
        SaRdWin *pWin = new SaRdWin(mParent);
        pWin->setWindowTitle(tr("Sales Receipt"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaHReceipt(){
    if(!mParent->subWinIsOpen(tr("Sales HReceipt"))){
        SaRdWin *pWin = new SaRdWin(RdFlag::RdInFlag,HaoKeApp::getVouchRdSaRe(),mParent);
        pWin->setWindowTitle(tr("Sales HReceipt"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void SaMenuAction::sSaConReceipt(){
    if(!mParent->subWinIsOpen(tr("Consignment Receipt"))){
        SaRdWin *pWin = new SaRdWin(RdFlag::RdOutFlag,HaoKeApp::getVouchRdCtOut(),mParent);
        pWin->setWindowTitle(tr("Consignment Receipt"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaHConReceipt(){
    if(!mParent->subWinIsOpen(tr("Consignment HReceipt"))){
        SaRdWin *pWin = new SaRdWin(RdFlag::RdInFlag,HaoKeApp::getVouchRdCtRe(),mParent);
        pWin->setWindowTitle(tr("Consignment HReceipt"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaSettle(){
    if(!mParent->subWinIsOpen(tr("Sales Settle"))){
        SaSettleWin *pWin = new SaSettleWin(mParent);
        pWin->setWindowTitle(tr("Sales Settle"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaOrderQuery(){
    if(!mParent->subWinIsOpen(tr("Sales Order Query"))){

        SaOrderQueryForm *pWin = new SaOrderQueryForm(mParent);
        pWin->setWindowTitle(tr("Sales Order Query"));
        pWin->setDwLableText("客户分类:","客户名称:");

        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaOrderExecQuery(){
    if(!mParent->subWinIsOpen(tr("Sales Order Execution List"))){

        SaOrderExecQueryForm *pWin = new SaOrderExecQueryForm(mParent);
        pWin->setWindowTitle(tr("Sales Order Execution List"));
        pWin->setDwLableText("客户分类:","客户名称:");

        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaReceiptQuery(){
    if(!mParent->subWinIsOpen(tr("Sales Receipt Query"))){

        SaRdQueryForm *pWin = new SaRdQueryForm(mParent);
        pWin->setWindowTitle(tr("Sales Receipt Query"));
        pWin->setDwLableText("客户分类:","客户名称:");

        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaDeliveryQuery(){
    if(!mParent->subWinIsOpen(tr("Sales Delivery Query"))){

        SaDeliveryQueryForm *pWin = new SaDeliveryQueryForm(mParent);
        pWin->setWindowTitle(tr("Sales Delivery Query"));
        pWin->setDwLableText("客户分类:","客户名称:");

        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sReSalesQuery(){
    if(!mParent->subWinIsOpen(tr("Sales Returned Query"))){

        SaReturnedQueryForm *pWin = new SaReturnedQueryForm(mParent);
        pWin->setWindowTitle(tr("Sales Returned Query"));
        pWin->setDwLableText("客户分类:","客户名称:");

        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaSettleQuery(){
    if(!mParent->subWinIsOpen(tr("Sales Settle Query"))){
        SaSettleQueryForm *pWin = new SaSettleQueryForm(mParent);
        pWin->setWindowTitle(tr("Sales Settle Query"));
        pWin->setDwLableText("客户分类:","客户名称:");
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaSettleDetaileQuery(){
    if(!mParent->subWinIsOpen(tr("Sales Settle Detaile Query"))){
        SaSettleDetaileQueryForm *pWin = new SaSettleDetaileQueryForm(mParent);
        pWin->setWindowTitle(tr("Sales Settle Detaile Query"));
        pWin->setDwLableText("客户分类:","客户名称:");
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaSettleRemainQuery(){
    if(!mParent->subWinIsOpen(tr("Sales Settle Remain Query"))){
        SaSettleRemainQueryForm *pWin = new SaSettleRemainQueryForm(mParent);
        pWin->setWindowTitle(tr("Sales Settle Remain Query"));
        pWin->setDwLableText("客户分类:","客户名称:");
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void SaMenuAction::sSaConSettleDetaileQuery(){
    if(!mParent->subWinIsOpen(tr("Consignment Settle Detaile Query"))){
        SaSettleDetaileQueryForm *pWin = new SaSettleDetaileQueryForm("04",mParent);
        pWin->setWindowTitle(tr("Consignment Settle Detaile Query"));
        pWin->setDwLableText("客户分类:","客户名称:");
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaConSettleRemainQuery(){
    if(!mParent->subWinIsOpen(tr("Consignment Settle Remain Query"))){
        SaSettleRemainQueryForm *pWin = new SaSettleRemainQueryForm("04",mParent);
        pWin->setWindowTitle(tr("Consignment Settle Remain Query"));
        pWin->setDwLableText("客户分类:","客户名称:");
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void SaMenuAction::sSaDeliverySummary(){
    if(!mParent->subWinIsOpen(tr("Customer delivery summary"))){
        SaCusSummary *pWin = new SaCusSummary(mParent);
        pWin->setWindowTitle(tr("Customer delivery summary"));
        pWin->setDwLableText("客户分类:","客户名称:");
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void SaMenuAction::sSaProductSummary(){
    if(!mParent->subWinIsOpen(tr("Sales Summary"))){
        SalesSummary *pWin = new SalesSummary(mParent);
        pWin->setWindowTitle(tr("Sales Summary"));
        pWin->setDwLableText("客户分类:","客户名称:");
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void SaMenuAction::sSaPrice(){
    if(!mParent->subWinIsOpen(tr("Sales Price Report"))){

        SaPriceWin *pWin = new SaPriceWin(mParent);
        pWin->setWindowTitle(tr("Sales Price Report"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaSet(){
    if(!mParent->subWinIsOpen(tr("Sales System Set"))){

        SaSetDialog *pDlg = new SaSetDialog(mParent);
        pDlg->setWindowTitle(tr("Sales System Set"));

        pDlg->exec();
    }
}

void SaMenuAction::sSaConDelivery(){
    if(!mParent->subWinIsOpen(tr("Consignment Delivery"))){
        SaConDeliverWin *pWin = new SaConDeliverWin(mParent);
        pWin->setWindowTitle(tr("Consignment Delivery"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void SaMenuAction::sReConSales(){
    if(!mParent->subWinIsOpen(tr("Consignment Returned"))){
        SaConReturnedWin *pWin = new SaConReturnedWin(mParent);
        pWin->setWindowTitle(tr("Consignment Returned"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void SaMenuAction::sSaConSettle(){
    if(!mParent->subWinIsOpen(tr("Consignment Settle"))){
        SaConSettleWin *pWin = new SaConSettleWin(mParent);
        pWin->setWindowTitle(tr("Consignment Settle"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void SaMenuAction::sSaConDeliveryQuery(){
    if(!mParent->subWinIsOpen(tr("Consignment Delivery Query"))){
        SaConDeliveryQueryForm *pWin = new SaConDeliveryQueryForm(mParent);
        pWin->setWindowTitle(tr("Consignment Delivery Query"));
        pWin->setDwLableText("客户分类:","客户名称:");
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sSaConSettleQuery(){
    if(!mParent->subWinIsOpen(tr("Consignment Settle Query"))){
        SaConSettleQueryForm *pWin = new SaConSettleQueryForm(mParent);
        pWin->setWindowTitle(tr("Consignment Settle Query"));
        pWin->setDwLableText("客户分类:","客户名称:");
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
void SaMenuAction::sReConSalesQuery(){
    if(!mParent->subWinIsOpen(tr("Consignment Returned Query"))){
        SaConReturnedQueryForm *pWin = new SaConReturnedQueryForm(mParent);
        pWin->setWindowTitle(tr("Consignment Returned Query"));
        pWin->setDwLableText("客户分类:","客户名称:");
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}
