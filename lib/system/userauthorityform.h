#ifndef USERAUTHORITYFORM_H
#define USERAUTHORITYFORM_H

#include <QWidget>
#include "system/bean/RoleBean.h"
#include "system/bean/RoleAccessBean.h"
#include "system/bean/UserRolesBean.h"
#include "system/dao/roleaccessdao.h"
#include "system/dao/userrolesdao.h"
#include "system/dao/roledao.h"
#include "bean/userbean.h"
#include "dao/userdao.h"
#include <QModelIndex>
namespace Ui {
class UserAuthorityForm;
}

class LIBSHARED_EXPORT UserAuthorityForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit UserAuthorityForm(QWidget *parent = 0);
    ~UserAuthorityForm();
    
private slots:
    void on_tableView_clicked(const QModelIndex &index);
    void on_roleTableView_clicked(const QModelIndex &index);

    void on_addButton_clicked();

    void on_roleTableView_doubleClicked(const QModelIndex &index);

    void on_cancelButton_clicked();

    void on_delButton_clicked();

    void on_tableView1_clicked(const QModelIndex &index);

private:
    Ui::UserAuthorityForm *ui;
    int mUserId;
    int mRoleId;
    int mDelRoleId;
    void refreshData();
    void init();
};

#endif // USERAUTHORITYFORM_H
