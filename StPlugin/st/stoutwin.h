#ifndef STOUTWIN_H
#define STOUTWIN_H

#include <QMainWindow>
#include "common/common.h"
#include "bean/RdBean.h"
#include "bean/RdsBean.h"
#include "widget/qkeditdelegate.h"
#include "common/widgetbeanutil.h"
#include "widget/hierarchicalheaderview.h"
#include "widget/foottablemodel.h"
namespace Ui {
class StOutWin;
}

class StOutWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit StOutWin(QWidget *parent = 0);
    StOutWin(QString no,QWidget *parent = 0);
    StOutWin(int rdFlag,QWidget *parent = 0);
    StOutWin(int rdFlag,QString no,QWidget *parent = 0);
    ~StOutWin();
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
    void footResized(int logicalIndex, int oldSize, int newSize );
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);
    void on_tableWidget_itemChanged(QTableWidgetItem *item);
    void sInvClick();
    void toolBarActTriggered(QAction *act);
private:
    Ui::StOutWin *ui;
    QToolBar *baseToolBar;
    int mEditStatus;
    QString mWinId;
    QString mWinTitle;
    bool mIsEdit;
    QString mId;
    QString mNo;
    QString mVouchType;
    QString mVouchSource;
    int mRdFlag;
    int mRecord;
    int mCountRecord;
    bool mIsChoose;
    bool mIsHathOrder; //销售业务是否必有订单
    bool mIsMakeRd;    //审核是否生成出库单
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

#endif // STOUTWIN_H
