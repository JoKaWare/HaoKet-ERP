#ifndef PUARRIVALWIN_H
#define PUARRIVALWIN_H

#include <QMainWindow>
#include "common/common.h"
#include "bean/PuOrderVouchBean.h"
#include "bean/PuOrderVouchsBean.h"
#include "bean/PuArrivalVouchBean.h"
#include "bean/PuArrivalVouchsBean.h"
#include "widget/qkeditdelegate.h"
#include "common/widgetbeanutil.h"
#include "widget/hierarchicalheaderview.h"
#include "widget/foottablemodel.h"
namespace Ui {
class PuArrivalWin;
}

class PuArrivalWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit PuArrivalWin(QWidget *parent = 0);
    PuArrivalWin(QString no,QWidget *parent = 0);
    ~PuArrivalWin();
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
    void footResized(int logicalIndex, int oldSize, int newSize );
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);
    void on_tableWidget_itemChanged(QTableWidgetItem *item);
    void sInvClick();
    void toolBarActTriggered(QAction *act);
private:
    Ui::PuArrivalWin *ui;
    QToolBar *baseToolBar;
    int mEditStatus;
    QString mWinId;
    QString mWinTitle;
    bool mIsEdit;
    QString mId;
    QString mNo;
    int mRecord;
    int mCountRecord;
    bool mIsHathOrder; //采购业务是否必有订单
    bool mIsMakeRd;    //审核是否生成入库单
    //是否提取单据
    bool mIsChoose;
    QList<int > mDelChildList;
    QList<PuArrivalVouchsBean *> mChildVouchsList;
    QList<PuArrivalVouchsBean *> mAddChildVouchsList;
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

#endif // PUARRIVALWIN_H
