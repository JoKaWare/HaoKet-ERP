#ifndef TRANSIMEIWIN_H
#define TRANSIMEIWIN_H

#include <QMainWindow>
#include "common/common.h"
#include "bean/TransImeiBean.h"
#include "widget/qkeditdelegate.h"
#include "common/widgetbeanutil.h"
#include "widget/hierarchicalheaderview.h"
#include "widget/foottablemodel.h"
#include "log4qt/logger.h"
namespace Ui {
class TransImeiWin;
}

class TransImeiWin : public QMainWindow
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    explicit TransImeiWin(QWidget *parent = 0);
    TransImeiWin(QString no, QWidget *parent = 0);
    ~TransImeiWin();
    
private slots:
    void sEdit();
    void sDelete();
    void sAudit();
    void sAbAudit();
    void sPrint();
    void sExport();
    void sFirst();
    void sNext();
    void sPrevious();
    void sEnd();
    void sCancel();
    void sDelRow();
    void footResized(int logicalIndex, int oldSize, int newSize );
    void setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage);
    void on_tableWidget_clicked(const QModelIndex &index);

    void on_saveButton_clicked();

    void on_importButton_clicked();

    void on_clearButton_clicked();

    void on_delButton_clicked();

    void on_tableWidget2_itemChanged(QTableWidgetItem *item);

    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);
    void toolBarActTriggered(QAction *act);

private:
    Ui::TransImeiWin *ui;
    QToolBar *baseToolBar;
    int mEditStatus;
    QString mWinId;
    QString mWinTitle;
    bool mIsEdit;
    bool mIsEditMode;
    bool mIsImport;
    QString mId;
    QString mNo;
    QString mVouchType;
    QString mVouchSource;
    QString mIdx;   //序列ID
    QString mInvCode; //商品编码
    int mQuantity;
    int mRow;
    int mRdFlag;
    int mRdRed;
    int mRecord;
    int mCountRecord;
    int mImeiCount;
    bool mIsChoose;
    bool mIsHathOrder; //采购业务是否必有订单
    bool mIsMakeRd;    //审核是否生成入库单
    QList<int > mDelChildList;

    QList<TransImeiBean *> mChildVouchsList;
    QList<TransImeiBean *> mAddChildVouchsList;
    QList<struct childItemProperties > mChildItem;
    QList<struct childItemProperties > mImeiItem;
    HierarchicalHeaderView *mFootView;
    FootTableModel *mFootModel;
    double mTotalQuantity ;
    double mTotalSum;
    QAction *mActDelRow;
    void readAuthority();
    void setupContextMenu();
    void closeEvent(QCloseEvent *event);
    void init();
    void createActions();
    void refreshData();
    void initTableHead2();
    void read(QString no);
    void inputClear();
    void setInputEnable(bool b);
    bool exportExcel(QString fileName, QTableWidget *tableWidget);
    void addActionsTo(actionProperties [], unsigned int);
};

#endif // TRANSIMEIWIN_H
