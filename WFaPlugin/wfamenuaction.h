#ifndef WFAMENUACTION_H
#define WFAMENUACTION_H
#include <QMenu>
#include <QMenuBar>
#include "common/kaction.h"
#include "common/common.h"

#include "haokegui.h"
#include "haokeapp.h"

class WFaMenuAction: public QObject
{
    Q_OBJECT
public:
    WFaMenuAction(HaoKeGUI *parent);
private slots:
    void sPaymentBill();
    void sReceivablesBill();
    void sBillAccnt();
    void sFaSubsidiaryQuery();
    void sFaSummaryQuery();
    void sFaTransceiversSummaryQuery();
    void sAccountBook();
    void sAccountSet();
private:
    HaoKeGUI *mParent;
    QToolBar *baseToolBar;
    QMenu *baseMenu;
    QMenu *mainAPMenu;
    QMenu *mainARMenu;
    QMenu *mainAIMenu;
    QMenu *mainCAMenu;
    QMenu *mainSReportMenu;
    void addActionsToMenu(actionProperties [], unsigned int);
};

#endif // WFAMENUACTION_H
