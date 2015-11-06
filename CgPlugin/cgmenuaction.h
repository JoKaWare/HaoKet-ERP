#ifndef CGMENUACTION_H
#define CGMENUACTION_H
#include <QMenu>
#include <QMenuBar>
#include "common/kaction.h"
#include "common/common.h"

#include "haokegui.h"
#include "haokeapp.h"
#include "pu/puorderwin.h"


class CgMenuAction : public QObject
{
    Q_OBJECT
public:
    CgMenuAction(HaoKeGUI *parent);
    private slots:
    void sPuOrder();
    void sPuReceipt();
    void sPuArrival();
    void sRePurchase();
    void sPuHReceipt();
    void sPuSettle();
    void sPuAccount();
    void sPuOrderList();
    void sPuOrderExecList();
    void sPuReceiptList();
    void sPuArrivalQuery();
    void sRePurchaseList();
    void sPuSettleList();
    void sPuDeliverySummary();
    void sPuProductSummary();
    void sPuSettleDetaileQuery();
    void sPuSettleRemainQuery();
    void sPuBegin();
    void sPuSet();
private:
    HaoKeGUI *mParent;
    QToolBar *baseToolBar;
    QMenu *baseMenu;
    QMenu *mainPOMenu;
    QMenu *mainPSMenu;
    QMenu *mainPRMenu;
    QMenu *mainPPMenu;
    QMenu *mainPMMenu;
    QMenu *mainPReportMenu;
    void addActionsToMenu(actionProperties [], unsigned int);
};

#endif // CGMENUACTION_H
