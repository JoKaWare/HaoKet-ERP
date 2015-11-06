#ifndef STRUCTUREDIALOG_H
#define STRUCTUREDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include "bean/DepBean.h"
#include "bean/ProductBean.h"
#include "bean/DishesBean.h"
#include "bean/EmployeeBean.h"
#include "bean/StructureBean.h"
#include "bean/StructuresBean.h"
#include "dao/structuredao.h"
#include "dao/depdao.h"
#include "dao/productdao.h"
#include "dao/dishesdao.h"
#include "dao/employeedao.h"
#include "widget/qkeditdelegate.h"

namespace Ui {
class StructureDialog;
}

class StructureDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit StructureDialog(QWidget *parent = 0);
    StructureDialog(QString no,QWidget *parent = 0);
    ~StructureDialog();
    
private slots:
    void on_newButton_clicked();

    void on_saveButton_clicked();

    void on_printButton_clicked();

    void on_cancelButton_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);
    void on_delRowButton_clicked();

    void on_productSearchEditbox_editChanged(const QString &arg1);

private:
    Ui::StructureDialog *ui;
    int mEditStatus;
    bool mIsEdit;
    QString mId;
    QString mWinId;
    QString mWinTitle;
    QList<int > mDelChildList;
    QList<StructuresBean *> mChildList;
    QList<StructuresBean *> mAddChildList;
    void init();
    void refreshData();
    void sNew();
    void read(QString no);
    void inputClear();
    void setInputEnable(bool );
};

#endif // STRUCTUREDIALOG_H
