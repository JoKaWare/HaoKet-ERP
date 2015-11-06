#ifndef SUPPLIETYPEFORM_H
#define SUPPLIETYPEFORM_H

#include <QWidget>
#include <QModelIndex>
#include <QStandardItemModel>
#include <QStandardItem>

#include <common/common.h>
#include "bean/SupplieTypeBean.h"
#include "dao/supplietypedao.h"

namespace Ui {
class SupplieTypeForm;
}

class SupplieTypeForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit SupplieTypeForm(QWidget *parent = 0);
    ~SupplieTypeForm();
    
private slots:
    void on_newButton_clicked();

    void on_cancelButton_clicked();

    void on_editButton_clicked();

    void on_saveButton_clicked();

    void on_delButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::SupplieTypeForm *ui;
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

#endif // SUPPLIETYPEFORM_H
