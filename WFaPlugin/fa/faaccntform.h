#ifndef FAACCNTFORM_H
#define FAACCNTFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlError>
#include "log4qt/logger.h"
namespace Ui {
class FaAccntForm;
}

class FaAccntForm : public QWidget
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    explicit FaAccntForm(QWidget *parent = 0);
    ~FaAccntForm();
    
private slots:
    void on_queryBtn_clicked();

    void on_cancelBtn_clicked();

    void on_AccntBtn_clicked();

    void on_AccntCancelBtn_clicked();

private:
    Ui::FaAccntForm *ui;
    QString mWinId;
    QString mWinTitle;
    QString mHNote;
    int mAccntMonth;
    QString mWayName; //计价方式名称
    int mWayId;       //计价方式ID
    QString mStrSql;
    QList<struct childItemProperties > mListChildItem;

    QStandardItemModel *mListModel;
    void init();
    void intiHeadData();
    void sQuery();
    QSqlQuery sqlQuery(QString sql, QVector<QVariant> qvar);
    void MACostACCOUNT();
    void FIFOCostACCOUNT();

};

#endif // FAACCNTFORM_H
