#ifndef SAPRICEWIN_H
#define SAPRICEWIN_H

#include <QMainWindow>
#include "bean/SaPriceBean.h"
#include "common/common.h"
#include "widget/qkeditdelegate.h"
#include "common/widgetbeanutil.h"
namespace Ui {
class SaPriceWin;
}

class SaPriceWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SaPriceWin(QWidget *parent = 0);
    ~SaPriceWin();
private slots:
    void sNew();
    void sEdit();
    void sSave();
    void sDelRow();
    void sPrint();
    void sCancel();
    void sInvClick();
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);

    void on_tableWidget_itemChanged(QTableWidgetItem *item);
    void toolBarActTriggered(QAction *act);

private:
    Ui::SaPriceWin *ui;
    QToolBar *baseToolBar;
    int mEditStatus;
    QString mWinId;
    QString mWinTitle;
    bool mIsEdit;
    QString mId;
    QString mNo;

    QList<int > mDelChildList;
    QList<SaPriceBean *> mChildVouchsList;
    QList<SaPriceBean *> mAddChildVouchsList;
    QList<struct childItemProperties > mChildItem;

    void setupContextMenu();
    void closeEvent(QCloseEvent *event);
    void init();
    void refreshData();
    void read(QString no);
    void inputClear();
    void setInputEnable(bool b);
    void addActionsTo(actionProperties [], unsigned int);
    void readAuthority();
};

#endif // SAPRICEWIN_H
