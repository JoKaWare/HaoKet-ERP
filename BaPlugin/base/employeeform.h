#ifndef EMPLOYEEFORM_H
#define EMPLOYEEFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>
#include <QList>
#include "bean/EmployeeBean.h"
#include "bean/DepBean.h"
#include "dao/employeedao.h"
#include "dao/depdao.h"
#include "common/common.h"
namespace Ui {
class EmployeeForm;
}

class EmployeeForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit EmployeeForm(QWidget *parent = 0);
    ~EmployeeForm();
    
private slots:
    void on_cancelButton_clicked();

    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_saveButton_clicked();

    void on_delButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::EmployeeForm *ui;
    int statusEdit;
    QString m_id;
    QString mWinId;
    QString mWinTitle;
    void init();
    void limitsInit();
    void refreshData();
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
    void clearInput();
};

#endif // EMPLOYEEFORM_H
