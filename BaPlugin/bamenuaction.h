#ifndef BAMENUACTION_H
#define BAMENUACTION_H

#include <QObject>
#include <QMenu>
#include <QMenuBar>
#include "common/kaction.h"
#include "common/common.h"

#include "haokegui.h"
#include "haokeapp.h"
class BaMenuAction : public QObject
{
    Q_OBJECT
public:
    explicit BaMenuAction(HaoKeGUI *parent);
    
private slots:
    void sDep();
    void sSuppliers();
    void sEmployee();
    void sMarketType();
    void sType();
    void sArea();
    void sDinner();
    void sDishes();
    void sTaste();
    void sExit();
    void sWare();
    void sPosition();
    void sProductType();
    void sProduct();
    void sSupplieType();
    void sCustomer();
    void sCustomerType();
    void sUnit();
private:
    HaoKeGUI *mParent;
    QToolBar *baseToolBar;
    QMenu *baseMenu;
    QMenu *mainOrgMenu;
    QMenu *mainCusMenu;
    QMenu *mainProMenu;
    QMenu *mainBusMenu;

    void addActionsToMenu(actionProperties [], unsigned int);
};

#endif // BAMENUACTION_H
