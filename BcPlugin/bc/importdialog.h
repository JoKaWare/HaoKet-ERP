#ifndef IMPORTDIALOG_H
#define IMPORTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include "log4qt/logger.h"

namespace Ui {
class ImportDialog;
}

class ImportDialog : public QDialog
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    explicit ImportDialog(QWidget *parent = 0);
    ~ImportDialog();
    QSqlQuery *sqlQuery(){ return mSqlQuery;}
    int getCountNum(){ return mCountNum;}
private slots:
    void on_openBtn_clicked();

    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::ImportDialog *ui;
    void init();
    int mCountNum;
    QSqlQueryModel *mModel;
    QSqlQuery *mSqlQuery;
    QSqlDatabase mExcelDb;

};

#endif // IMPORTDIALOG_H
