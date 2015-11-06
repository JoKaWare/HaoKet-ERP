#ifndef PUBEGINRDWIN_H
#define PUBEGINRDWIN_H

#include <QMainWindow>
#include "common/common.h"
#include "bean/PuOrderVouchBean.h"
#include "bean/PuOrderVouchsBean.h"
#include "bean/RdBean.h"
#include "bean/RdsBean.h"
#include "widget/qkeditdelegate.h"
#include "common/widgetbeanutil.h"
#include "widget/hierarchicalheaderview.h"
#include "widget/foottablemodel.h"
namespace Ui {
class PuBeginRdWin;
}

class PuBeginRdWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit PuBeginRdWin(QWidget *parent = 0);
    ~PuBeginRdWin();
    
private slots:
    void sNew();
    void sEdit();
    void sDelete();
    void sSave();
    void sAudit();
    void sAbAudit();
    void sDelRow();
    void sPrint();
    void sFirst();
    void sNext();
    void sPrevious();
    void sEnd();
    void sCancel();
    void on_tableWidget_itemChanged(QTableWidgetItem *item);
    void footResized(int logicalIndex, int oldSize, int newSize );
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);
private:
    Ui::PuBeginRdWin *ui;
    QToolBar *baseToolBar;
    int mEditStatus;
    QString mWinId;
    QString mWinTitle;
    bool mIsEdit;
    QString mId;
    QString mNo;
    QString mVouchType;
    QString mVouchSource;
    //是否红字单据
    int mRdRed;
    int mRdFlag;
    int mRecord;
    int mCountRecord;
    bool mIsChoose;
    bool mIsHathOrder; //采购业务是否必有订单
    bool mIsMakeRd;    //审核是否生成入库单
    QList<int > mDelChildList;
    QList<RdsBean *> mChildVouchsList;
    QList<RdsBean *> mAddChildVouchsList;
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

#endif // PUBEGINRDWIN_H
