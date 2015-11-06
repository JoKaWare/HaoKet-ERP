#ifndef ARBILLWIN_H
#define ARBILLWIN_H

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
class ArBillWin;
}

class ArBillWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ArBillWin(QWidget *parent = 0);
    ArBillWin(QString no, QWidget *parent = 0);
    ~ArBillWin();
    
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
    Ui::ArBillWin *ui;
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

#endif // ARBILLWIN_H
