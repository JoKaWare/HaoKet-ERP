#ifndef PUSETTLEWIN_H
#define PUSETTLEWIN_H

#include <QMainWindow>
#include <QMessageBox>
#include "common/common.h"
#include "bean/RdBean.h"
#include "bean/RdsBean.h"
#include "bean/PuSettleVouchBean.h"
#include "bean/PuSettleVouchsBean.h"
#include "widget/qkeditdelegate.h"
#include "common/widgetbeanutil.h"
#include "widget/hierarchicalheaderview.h"
#include "widget/foottablemodel.h"
namespace Ui {
class PuSettleWin;
}

class PuSettleWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit PuSettleWin(QWidget *parent = 0);
    PuSettleWin(QString no,QWidget *parent = 0);
    ~PuSettleWin();
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
    Ui::PuSettleWin *ui;
    QToolBar *baseToolBar;
    int mEditStatus;
    QString mWinId;
    QString mWinTitle;
    bool mIsEdit;
    QString mId;
    QString mNo;
    int mRecord;
    int mCountRecord;

    bool mIsChoose;
    QList<int > mDelChildList;
    QList<PuSettleVouchsBean *> mChildVouchsList;
    QList<PuSettleVouchsBean *> mAddChildVouchsList;
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

#endif // PUSETTLEWIN_H
