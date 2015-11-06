#ifndef PUORDERWIN_H
#define PUORDERWIN_H

#include <QMainWindow>
#include "common/common.h"
#include "bean/PuOrderVouchBean.h"
#include "bean/PuOrderVouchsBean.h"
#include "widget/qkeditdelegate.h"
#include "common/widgetbeanutil.h"
#include "widget/hierarchicalheaderview.h"
#include "widget/foottablemodel.h"
namespace Ui {
class PuOrderWin;
}

class PuOrderWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit PuOrderWin(QWidget *parent = 0);
    PuOrderWin(QString no,QWidget *parent = 0);
    ~PuOrderWin();
private slots:
    void sNew();
    void sEdit();
    void sDelete();
    void sSave();
    void sAudit();
    void sAbAudit();
    void sDelRow();
    void sPrint();
    void sChoose();
    void sFirst();
    void sNext();
    void sPrevious();
    void sEnd();
    void sCancel();
    void on_tableWidget_itemChanged(QTableWidgetItem *item);
    void footResized(int logicalIndex, int oldSize, int newSize );
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);
    void sInvClick();
    void toolBarActTriggered(QAction *act);
private:
    Ui::PuOrderWin *ui;
    QToolBar *baseToolBar;
    int mEditStatus;
    QString mWinId;
    QString mWinTitle;
    bool mIsEdit;
    QString mId;
    QString mNo;
    int mRdFlag;
    int mRecord;
    int mCountRecord;
    //是否提取单据
    bool mIsChoose;
    QList<int > mDelChildList;
    QList<PuOrderVouchsBean *> mChildVouchsList;
    QList<PuOrderVouchsBean *> mAddChildVouchsList;
    QList<struct childItemProperties > mChildItem;
    HierarchicalHeaderView *mFootView;
    FootTableModel *mFootModel;
    double mTotalQuantity ;
    double mTotalSum;
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

#endif // PUORDERWIN_H
