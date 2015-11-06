#ifndef ROLEDIALOG_H
#define ROLEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include "system/bean/RoleBean.h"
#include "system/dao/processdao.h"
#include "system/dao/roledao.h"
namespace Ui {
class LIBSHARED_EXPORT RoleDialog;
}

class RoleDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit RoleDialog(QWidget *parent = 0);
    ~RoleDialog();
    
private slots:
    void on_cancelButton_clicked();

    void on_newButton_clicked();

    void on_saveButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_editButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_authorityButton_clicked();

private:
    Ui::RoleDialog *ui;
    int m_status;
    QString m_id;
    void init();
    void refreshData();
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
};

#endif // ROLEDIALOG_H
