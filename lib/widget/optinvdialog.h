#ifndef OPTINVDIALOG_H
#define OPTINVDIALOG_H

#include <QDialog>
#include <QTableView>
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include "qksearcheditbox.h"
#include "common/common.h"
#include "common/dbmanager.h"
#include "lib_global.h"
namespace Ui {
class OptInvDialog;
}

class LIBSHARED_EXPORT OptInvDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit OptInvDialog(QWidget *parent = 0);
    OptInvDialog(QList<childItemProperties> dItem,QString dSql,QWidget *parent = 0);
    OptInvDialog(QList<childItemProperties> dItem,QString dSql,QString invCode, QWidget *parent = 0);
    OptInvDialog(QList<childItemProperties> dItem,QString dSql,QString whCode, QString invCode, QWidget *parent = 0);
    ~OptInvDialog();
    void initTableHead();
    void initData(QList<childItemProperties> dItem,QString dSql);
    QTableView *getTableView();
private slots:
    void on_cancelBtn_clicked();
    void on_okBtn_clicked();
    void on_queryBtn_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::OptInvDialog *ui;
    void sQuery();
    void init();

    QSqlQueryModel *sqlQueryModel(QString sql,QVector<QVariant> qvar);
    QList<struct childItemProperties > mDetailChildItem;
    QStandardItemModel *mDetailModel;
    QString mHandleFiled;
    QString mFormId;
    QString mStrDetailSql;
    QString mTypeId;
};

#endif // OPTINVDIALOG_H
