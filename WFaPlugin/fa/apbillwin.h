#ifndef APBILLWIN_H
#define APBILLWIN_H

#include <QMainWindow>
#include "common/common.h"
#include "bean/ApCloseBillBean.h"
#include "bean/ApCloseBillsBean.h"
#include "bean/ApTypeBean.h"
#include "widget/qkeditdelegate.h"
#include "common/widgetbeanutil.h"
#include "widget/hierarchicalheaderview.h"
#include "widget/foottablemodel.h"
namespace Ui {
class ApBillWin;
}

class ApBillWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ApBillWin(QWidget *parent = 0);
    ApBillWin(QString no, QWidget *parent = 0);
    ~ApBillWin();
    
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

    void on_busQsk_editChanged(const QString &arg1);

private:
    Ui::ApBillWin *ui;
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
    QList<int > mDelChildList;
    QList<ApCloseBillsBean *> mChildVouchsList;
    QList<ApCloseBillsBean *> mAddChildVouchsList;
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

#endif // APBILLWIN_H
