#ifndef BCMENUACTION_H
#define BCMENUACTION_H
#include <QMenu>
#include <QMenuBar>
#include "common/kaction.h"
#include "common/common.h"

#include "haokegui.h"
#include "haokeapp.h"
class BcMenuAction: public QObject
{
    Q_OBJECT
public:
    BcMenuAction(HaoKeGUI *parent);
private slots:
    void sRdInImei();
    void sRdInImeiQuery();
    void sRdInListQuery();
    void sRdReInImeiQuery();
    void sRdOutImei();
    void sRdOutImeiQuery();
    void sRdReOutImeiQuery();
    void sRdOutListQuery();
    void sTransImei();
    void sTransImeiQuery();
    void sStockImeiQuery();
    void sImeiQuery();
private:
    HaoKeGUI *mParent;
    QToolBar *baseToolBar;
    QMenu *baseMenu;
    QMenu *mainBIMenu;
    QMenu *mainBOMenu;
    QMenu *mainBTMenu;
    QMenu *mainBPMenu;
    QMenu *mainPReportMenu;
    void addActionsToMenu(actionProperties [], unsigned int);

};

#endif // BCMENUACTION_H
