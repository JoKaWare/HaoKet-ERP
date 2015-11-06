#ifndef RECOVERACCOUNTDIALOG_H
#define RECOVERACCOUNTDIALOG_H

#include <QDialog>
#include "log4qt/logger.h"
namespace Ui {
class RecoverAccountDialog;
}

class RecoverAccountDialog : public QDialog
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    explicit RecoverAccountDialog(QWidget *parent = 0);
    ~RecoverAccountDialog();
    
private slots:
    void on_cancelBtn_clicked();

    void on_okBtn_clicked();

private:
    Ui::RecoverAccountDialog *ui;
    int mAccntMonth;
    QString mWayName; //计价方式名称
    int mWayId;       //计价方式ID
    void reAccntFIFO();
    void reAccntMACost();
};

#endif // RECOVERACCOUNTDIALOG_H
