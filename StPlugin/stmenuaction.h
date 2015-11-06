#ifndef STMENUACTION_H
#define STMENUACTION_H
#include <QMenu>
#include <QMenuBar>
#include "common/kaction.h"
#include "common/common.h"

#include "haokegui.h"
#include "haokeapp.h"

class StMenuAction: public QObject
{
    Q_OBJECT
public:
    StMenuAction(HaoKeGUI *parent);
private slots:
    void sStQuery();
    void sStOut();
    void sOtherIn();
    void sOtherOut();
    void sStTrans();
    void sStCheck();
    void sStTransQuery();
    void sStCheckQuery();
    void sOtherInQuery();
    void sOtherOutQuery();
    void sStInvAccountQuery();
    void sStJournalAccountQuery();
private:
    HaoKeGUI *mParent;
    QToolBar *baseToolBar;
    QMenu *baseMenu;
    QMenu *mainORMenu;
    QMenu *mainODMenu;
    QMenu *mainAIMenu;
    QMenu *mainCIMenu;
    QMenu *mainSReportMenu;
    void addActionsToMenu(actionProperties [], unsigned int);
};

#endif // STMENUACTION_H
