#ifndef CUSFORM_H
#define CUSFORM_H

#include <QWidget>
#include <QStandardItem>
#include <QSqlQueryModel>
#include "bean/CustomerBean.h"
#include "bean/CustomerTypeBean.h"
#include "dao/customerdao.h"
#include "dao/customertypedao.h"
#include "system/limitscommon.h"

namespace Ui {
class CusForm;
}

class CusForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit CusForm(QWidget *parent = 0);
    ~CusForm();

private slots:
    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_delButton_clicked();

    void on_cancelButton_clicked();

    void on_queryButton_clicked();

    void on_treeView_doubleClicked(const QModelIndex &index);

    void on_treeView_clicked(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);
    void sortByColumn(int);

private:
    Ui::CusForm *ui;
    int mEditStatus;
    QString mId;
    QString mCusCode;
    QString mTypeCode;
    QStandardItemModel *mListModel;
    QList<struct childItemProperties > mListChildItem;
    QString mSql1;
    QString mSql2;
    QString mWinId;
    QString mWinTitle;
    void init();
    void limitsInit();
    void refreshData();
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
    void sQuery(QString sql,QVector<QVariant> v);
    QSqlQuery sqlQuery(QString sql,QVector<QVariant> qvar);
};

#endif // CUSFORM_H
