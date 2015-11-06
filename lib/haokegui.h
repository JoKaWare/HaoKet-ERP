#ifndef HAOKEGUI_H
#define HAOKEGUI_H
#include "lib_global.h"
#include <QtGui>
#include <QMainWindow>
#include <QMdiArea>
#include <QDockWidget>
#include <QMessageBox>
#include <QMenu>
#include <QAction>

#include "common/config.h"
#include "log4qt/logger.h"
#include "common/common.h"
#include "common/dbmanager.h"

class LIBSHARED_EXPORT HaoKeGUI : public QMainWindow
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    HaoKeGUI();
    void addSubWin(QWidget *w);
    void removeSubWin(QWidget *w);
    void closeEvent(QCloseEvent *event);
    void showNav();
    bool subWinIsOpen(QString title);
    void init();
private slots:
    void closeAllExit();
    void about();

private:

    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();

    QMdiArea *mdiArea;
    QMenu *helpMenu;

    QDockWidget* winDock;
    //QToolBar *systemToolBar;


    QAction *showAct;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *closeAct;
};

#endif // HAOKEGUI_H
