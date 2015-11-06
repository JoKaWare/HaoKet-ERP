#ifndef ACCOUNTDIALOG_H
#define ACCOUNTDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include "lib_global.h"

namespace Ui {
class AccountDialog;
}

class LIBSHARED_EXPORT AccountDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AccountDialog(QWidget *parent = 0);
    ~AccountDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_backupButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::AccountDialog *ui;
    QStandardItemModel *mModel;
    QString mId;
    void init();
    void initTableHead(QAbstractItemModel *model);

};

#endif // ACCOUNTDIALOG_H
