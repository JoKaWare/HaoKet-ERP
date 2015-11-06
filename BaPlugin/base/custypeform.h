#ifndef CUSTYPEFORM_H
#define CUSTYPEFORM_H

#include <QWidget>
#include <QModelIndex>
#include <QStandardItemModel>
#include <QStandardItem>

#include <common/common.h>
#include "bean/CustomerTypeBean.h"
#include "dao/customertypedao.h"
namespace Ui {
class CusTypeForm;
}

class CusTypeForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit CusTypeForm(QWidget *parent = 0);
    ~CusTypeForm();
    
private slots:
    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_saveButton_clicked();

    void on_delButton_clicked();

    void on_cancelButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::CusTypeForm *ui;
    int mEditStatus;
    QString mId;
    QString mWinId;
    QString mWinTitle;
    void init();
    void limitsInit();
    void refreshData();
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
};

#endif // CUSTYPEFORM_H
