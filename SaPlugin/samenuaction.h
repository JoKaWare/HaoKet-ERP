#ifndef SAMENUACTION_H
#define SAMENUACTION_H

#include <QMenu>
#include <QMenuBar>
#include "common/kaction.h"
#include "common/common.h"

#include "haokegui.h"
#include "haokeapp.h"

class SaMenuAction : public QObject
{
    Q_OBJECT
public:
    explicit SaMenuAction(HaoKeGUI *parent);
private slots:
    void sSaOrder();
    void sSaDelivery();
    void sReSales();
    void sSaReceipt();
    void sSaHReceipt();
    void sSaConReceipt();
    void sSaHConReceipt();
    void sSaSettle();
    void sSaOrderQuery();
    void sSaOrderExecQuery();
    void sSaReceiptQuery();
    void sSaDeliveryQuery();
    void sReSalesQuery();
    void sSaSettleQuery();
    void sSaSettleDetaileQuery();
    void sSaSettleRemainQuery();
    void sSaConSettleDetaileQuery();
    void sSaConSettleRemainQuery();
    void sSaDeliverySummary();
    void sSaProductSummary();
    void sSaPrice();
    void sSaSet();

    void sSaConDelivery();
    void sSaConSettle();
    void sReConSales();
    void sSaConDeliveryQuery();
    void sSaConSettleQuery();
    void sReConSalesQuery();

private:
    HaoKeGUI *mParent;
    QToolBar *baseToolBar;
    QMenu *baseMenu;
    QMenu *mainSOMenu;
    QMenu *mainSDMenu;
    QMenu *mainSCMenu;
    QMenu *mainSAMenu;
    QMenu *mainSSMenu;
    QMenu *mainSReportMenu;

    void addActionsToMenu(actionProperties [], unsigned int);
};

#endif // SAMENUACTION_H
