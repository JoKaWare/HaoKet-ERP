#ifndef WAREHOUSEFORM_H
#define WAREHOUSEFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include "bean/WareHouseBean.h"
#include "dao/waredao.h"

namespace Ui {
class WareHouseForm;
}

class WareHouseForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit WareHouseForm(QWidget *parent = 0);
    ~WareHouseForm();
    
private slots:
    void on_cancelButton_clicked();

    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_saveButton_clicked();

    void on_delButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::WareHouseForm *ui;
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

#endif // WAREHOUSEFORM_H
