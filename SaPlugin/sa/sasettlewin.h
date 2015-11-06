#ifndef SASETTLEWIN_H
#define SASETTLEWIN_H

#include <QMainWindow>
#include <QMessageBox>
#include "common/common.h"
#include "bean/RdBean.h"
#include "bean/RdsBean.h"
#include "bean/SaSettleVouchBean.h"
#include "bean/SaSettleVouchsBean.h"
#include "widget/qkeditdelegate.h"
#include "common/widgetbeanutil.h"
#include "widget/hierarchicalheaderview.h"
#include "widget/foottablemodel.h"
namespace Ui {
class SaSettleWin;
}

class SaSettleWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SaSettleWin(QWidget *parent = 0);
    SaSettleWin(QString no,QWidget *parent = 0);
    ~SaSettleWin();
    
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
    void toolBarActTriggered(QAction *act);
private:
    Ui::SaSettleWin *ui;
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
    QList<SaSettleVouchsBean *> mChildVouchsList;
    QList<SaSettleVouchsBean *> mAddChildVouchsList;
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

#endif // SASETTLEWIN_H
