#ifndef SAORDERWIN_H
#define SAORDERWIN_H

#include <QMainWindow>
#include "common/common.h"
#include "bean/SaOrderVouchBean.h"
#include "bean/SaOrderVouchsBean.h"
#include "bean/SaDispatchVouchBean.h"
#include "bean/SaDispatchVouchsBean.h"
#include "widget/qkeditdelegate.h"
#include "common/widgetbeanutil.h"
#include "widget/hierarchicalheaderview.h"
#include "widget/foottablemodel.h"
namespace Ui {
class SaOrderWin;
}

class SaOrderWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SaOrderWin(QWidget *parent = 0);
    SaOrderWin(QString no,QWidget *parent = 0);
    ~SaOrderWin();
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
    void sInvClick();
    void toolBarActTriggered(QAction *act);
private:
    Ui::SaOrderWin *ui;
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
    QList<SaOrderVouchsBean *> mChildVouchsList;
    QList<SaOrderVouchsBean *> mAddChildVouchsList;
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

#endif // SAORDERWIN_H
