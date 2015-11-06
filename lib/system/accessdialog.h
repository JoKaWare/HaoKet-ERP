#ifndef ACCESSDIALOG_H
#define ACCESSDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QStringListModel>
#include "system/bean/ProcessBean.h"
#include "system/bean/WindowBean.h"
#include "system/bean/RoleBean.h"
#include "system/bean/RoleAccessBean.h"
#include "system/bean/SubSysBean.h"
#include "system/dao/processdao.h"
#include "system/dao/roledao.h"
#include "system/dao/roleaccessdao.h"
namespace Ui {
class  LIBSHARED_EXPORT AccessDialog;
}

class AccessDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AccessDialog(QWidget *parent = 0);
    explicit AccessDialog(QString id,QWidget *parent = 0);
    ~AccessDialog();
    
private slots:
    void on_exitButton_clicked();

    void on_saveButton_clicked();

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_listView2_clicked(const QModelIndex &index);

private:
    Ui::AccessDialog *ui;
    QString m_id;
    QList<SubSysBean *> mListSubSys;
    QList<int> mOpenLimitsList;
    QList<int> mCloseLimitsList;
    void init();
    void refresh();
    QString getSubSysName(int id);

};

#endif // ACCESSDIALOG_H
