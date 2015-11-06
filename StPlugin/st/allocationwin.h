#ifndef ALLOCATIONWIN_H
#define ALLOCATIONWIN_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "common/common.h"
#include "haokeapp.h"
#include "bean/DepBean.h"
#include "bean/WareHouseBean.h"
#include "bean/SupplieBean.h"
#include "bean/EmployeeBean.h"
#include "bean/ProductBean.h"
#include "bean/RdBean.h"
#include "bean/RdsBean.h"
#include "bean/StockBean.h"
#include "bean/TransVouchBean.h"
#include "bean/TransVouchsBean.h"
#include "dao/depdao.h"
#include "dao/waredao.h"
#include "dao/suppliedao.h"
#include "dao/employeedao.h"
#include "dao/productdao.h"
#include "dao/rddao.h"
#include "dao/stockdao.h"
#include "dao/transdao.h"
#include "business/businessno.h"
#include "widget/qkeditdelegate.h"
#include "log4qt/logger.h"
#include <QMessageBox>
#include "widget/qkeditdelegate.h"
#include "common/widgetbeanutil.h"
#include "widget/hierarchicalheaderview.h"
#include "widget/foottablemodel.h"
namespace Ui {
class AllocationWin;
}

class AllocationWin : public QMainWindow
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    explicit AllocationWin(QWidget *parent = 0);
    AllocationWin(QString no,QWidget *parent = 0);
    AllocationWin(int editStatus,QWidget *parent = 0);
    ~AllocationWin();
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
    Ui::AllocationWin *ui;
    QToolBar *baseToolBar;
    int mEditStatus;
    bool mIsEdit;
    QString mId;
    QString mNo;
    QString mVouchSource;
    QString mVouchType;
    QString mWinId;
    QString mWinTitle;
    QString mDateLabel;
    QString mWareLabel;
    int mRdFlag;
    int mRecord;
    int mCountRecord;
    double mTotalQuantity ;
    double mTotalSum;
    QList<int > mDelChildList;
    QList<TransVouchsBean *> mChildRdsList;
    QList<TransVouchsBean *> mAddChildRdsList;
    QList<struct childItemProperties > mChildItem;
    HierarchicalHeaderView *mFootView;
    FootTableModel *mFootModel;
    void init();
    void refreshData();
    void read(QString no);
    void readAuthority();
    void inputClear();
    void setInputEnable(bool );
    void addActionsTo(actionProperties [], unsigned int);
};

#endif // ALLOCATIONWIN_H
