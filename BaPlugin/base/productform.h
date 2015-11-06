#ifndef PRODUCTFORM_H
#define PRODUCTFORM_H

#include <QWidget>
#include <QStandardItem>
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"
#include "dao/Producttypedao.h"
#include "dao/productdao.h"
#include "system/limitscommon.h"

namespace Ui {
class ProductForm;
}

class ProductForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit ProductForm(QWidget *parent = 0);
    ~ProductForm();
    
private slots:
    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_delButton_clicked();

    void on_cancelButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_queryButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::ProductForm *ui;
    int mEditStatus;
    QString mWinId;
    QString mWinTitle;
    QString mId;
    QString mTypeCode;
    void init();
    void limitsInit();
    void refreshData();
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
};

#endif // PRODUCTFORM_H
