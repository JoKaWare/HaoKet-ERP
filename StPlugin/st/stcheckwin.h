#ifndef STCHECKWIN_H
#define STCHECKWIN_H

#include <QMainWindow>
#include "common/common.h"
#include "bean/CheckVouchBean.h"
#include "bean/CheckVouchsBean.h"
#include "widget/qkeditdelegate.h"
#include "common/widgetbeanutil.h"
#include "widget/hierarchicalheaderview.h"
#include "widget/foottablemodel.h"
namespace Ui {
class StCheckWin;
}

class StCheckWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit StCheckWin(QWidget *parent = 0);
    StCheckWin(QString no,QWidget *parent = 0);
    ~StCheckWin();
    
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
    Ui::StCheckWin *ui;
    QToolBar *baseToolBar;
    int mEditStatus;
    QString mWinId;
    QString mWinTitle;
    bool mIsEdit;
    QString mId;
    QString mNo;
    int mRecord;
    int mCountRecord;
    //是否提取单据
    bool mIsChoose;
    QList<int > mDelChildList;
    QList<CheckVouchsBean *> mChildVouchsList;
    QList<CheckVouchsBean *> mAddChildVouchsList;
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

#endif // STCHECKWIN_H
