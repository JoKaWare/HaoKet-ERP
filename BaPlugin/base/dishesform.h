#ifndef DISHESFORM_H
#define DISHESFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include "bean/TypeBean.h"
#include "bean/DishesBean.h"
#include "dao/typedao.h"
#include "dao/dishesdao.h"
namespace Ui {
class DishesForm;
}

class DishesForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit DishesForm(QWidget *parent = 0);
    ~DishesForm();
    
private slots:
    void on_cancelButton_clicked();
    void on_newButton_clicked();
    void on_editButton_clicked();
    void on_delButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_treeView_clicked(const QModelIndex &index);

    void on_queryButton_clicked();

private:
    Ui::DishesForm *ui;
    int statusEdit;
    QString m_id;
    QString m_typeId;
    QString mWinId;
    QString mWinTitle;
    void init();
    void refreshData();
    void clearInput();
    void setButtonEnabled(bool b);
    void limitsInit();
};

#endif // DISHESFORM_H
