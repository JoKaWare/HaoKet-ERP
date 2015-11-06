#include "wfamenuaction.h"
#include "fa/apbillwin.h"
#include "fa/arbillwin.h"
#include "fa/kmform.h"
#include "fa/faaccntform.h"
#include "fa/fawaydialog.h"
#include "fa/fasubsidiaryqueryform.h"
#include "fa/fatransceiverssummaryqueryform.h"
#include "wfaplugin.h"

WFaMenuAction::WFaMenuAction(HaoKeGUI *parent):
    mParent(parent)
{
    baseMenu = new QMenu(tr("Financial Management(&F)"),mParent);
    baseMenu->setObjectName("menu.st");
    mainAPMenu = new QMenu(tr("AP Sub"),mParent);
    mainARMenu = new QMenu(tr("AR Sub"),mParent);
    mainAIMenu = new QMenu(tr("AI Sub"),mParent);
    mainCAMenu = new QMenu(tr("CA Sub"),mParent);
    mainSReportMenu = new QMenu(tr("REPORT Sub"),mParent);
    QString s="sysAccount";
    if(HaoKeApp::getInstance()->getAccountName() == s ){}
    else{
        mParent->menuBar()->addMenu(baseMenu);
        actionProperties acts[]= {
            { "menu",tr("&Payment of the purchase"),(char*)mainAPMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "fa.PaymentBill",tr("&Payment Bill"),SLOT(sPaymentBill()), mainAPMenu, "Payment Bill", NULL, NULL,  true, tr("Payment Bill"),HaoKeApp::faSubId() + WFaPlugin::apBillWinId()  },
            { "menu",tr("&Sales of receivables"),(char*)mainARMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "fa.ReceivablesBill",tr("&Receivables Bill"),SLOT(sReceivablesBill()), mainARMenu, "Receivables Bill", NULL, NULL,  true, tr("Receivables Bill"),HaoKeApp::faSubId() + WFaPlugin::arBillWinId() },
            { "menu",tr("&Cost Accounting"),(char*)mainCAMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "fa.BillACCNT",tr("&Bill ACCNT"),SLOT(sBillAccnt()), mainCAMenu, "Bill ACCNT", NULL, NULL,  true, tr("Bill ACCNT"),HaoKeApp::faSubId() + WFaPlugin::faBillACCNTWinId() },
            { "fa.Subsidiary",tr("&Fa Subsidary"),SLOT(sFaSubsidiaryQuery()), mainCAMenu, "Fa Subsidary", NULL, NULL,  true, tr("Fa Subsidary"),HaoKeApp::faSubId() + WFaPlugin::faSubsidiaryWinId()},
            //{ "fa.Summary",tr("&Fa Summary"),SLOT(sFaSummaryQuery()), mainCAMenu, "Fa Summary", NULL, NULL,  true, tr("Fa Summary"),HaoKeApp::faSubId() + WFaPlugin::faSummaryWinId() },
            { "fa.TransceiversSummary",tr("&Fa Transceivers Summary"),SLOT(sFaTransceiversSummaryQuery()), mainCAMenu, "Fa Transceivers Summary", NULL, NULL,  true, tr("Fa Transceivers Summary"),HaoKeApp::faSubId() + WFaPlugin::faTransceiversSummaryWinId() },
            { "menu",tr("&Financial System Set"),(char*)mainAIMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "fa.Km",tr("&Account Book"),SLOT(sAccountBook()), mainAIMenu, "Account Book", NULL, NULL,  true, tr("Account Book"),HaoKeApp::faSubId() + WFaPlugin::kmWinId() },
            { "fa.CostAccountingSet",tr("&Cost Accounting Set"),SLOT(sAccountSet()), mainAIMenu, "Cost Accounting Set", NULL, NULL,  true, tr("Cost Accounting Set"),HaoKeApp::faSubId() + WFaPlugin::costAccountSetWinId() },

        };
        addActionsToMenu(acts, sizeof(acts) / sizeof(acts[0]));
    }
}

void WFaMenuAction::addActionsToMenu(actionProperties acts[], unsigned int numElems){
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
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,"",HaoKeApp::faSubId().toInt(),
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

void WFaMenuAction::sPaymentBill(){
    if(!mParent->subWinIsOpen(tr("Payment Bill"))){
        ApBillWin *pWin = new ApBillWin(mParent);
        pWin->setWindowTitle(tr("Payment Bill"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void WFaMenuAction::sReceivablesBill(){
    if(!mParent->subWinIsOpen(tr("Receivables Bill"))){
        ArBillWin *pWin = new ArBillWin(mParent);
        pWin->setWindowTitle(tr("Receivables Bill"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void WFaMenuAction::sBillAccnt(){
    if(!mParent->subWinIsOpen(tr("Bill ACCNT"))){
        FaAccntForm *pWin = new FaAccntForm(mParent);
        pWin->setWindowTitle(tr("Bill ACCNT"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void WFaMenuAction::sFaSubsidiaryQuery(){
    if(!mParent->subWinIsOpen(tr("Fa Subsidiary"))){
        FaSubsidiaryQueryForm *pWin = new FaSubsidiaryQueryForm(mParent);
        pWin->setWindowTitle(tr("Fa Subsidiary"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void WFaMenuAction::sFaSummaryQuery(){

}

void WFaMenuAction::sFaTransceiversSummaryQuery(){
    if(!mParent->subWinIsOpen(tr("Fa Transceivers Summary"))){
        FaTransceiversSummaryQueryForm *pWin = new FaTransceiversSummaryQueryForm(mParent);
        pWin->setWindowTitle(tr("Fa Transceivers Summary"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void WFaMenuAction::sAccountBook(){
    if(!mParent->subWinIsOpen(tr("Account Book"))){
        KmForm *pWin = new KmForm(mParent);
        pWin->setWindowTitle(tr("Account Book"));
        mParent->addSubWin(pWin);
        pWin->showMaximized();
    }
}

void WFaMenuAction::sAccountSet(){
    FaWayDialog *fDlg = new FaWayDialog(mParent);
    fDlg->setWindowTitle("成本核算计价方式");
    if(fDlg->exec()==QDialog::Accepted){

    }
}


