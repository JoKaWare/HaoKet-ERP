#ifndef SYSTEMMENUACTION_H
#define SYSTEMMENUACTION_H
#include <QObject>
#include <QToolBar>
#include <QMenu>
#include "haokegui.h"

class SystemMenuAction: public QObject
{
  Q_OBJECT
public:
    SystemMenuAction(HaoKeGUI *parent);
private slots:
    void sExit();
    void sUserAdd();
    void sUser();
    void sOption();
    void sShowNav();
    void sLimits();
    void sRoles();
    void sChange();
    void sAccountCreate();
    void sAccountManagement();
    void sAccountList();
private:

    HaoKeGUI *parent;
    QToolBar *systemToolBar;
    QToolBar *userToolBar;
    QMenu *systemMenu;
    QMenu *accountMenu;
    QMenu *mainMenu;
    void addActionsToMenu(actionProperties [], unsigned int);
};

#endif // SYSTEMMENUACTION_H
