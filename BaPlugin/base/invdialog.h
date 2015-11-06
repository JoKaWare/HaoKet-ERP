#ifndef INVDIALOG_H
#define INVDIALOG_H

#include <QDialog>
#include "common/pinyinutils.h"
#include "bean/ProductBean.h"
#include "bean/ProductTypeBean.h"
#include "bean/UnitBean.h"
#include "bean/WareHouseBean.h"
#include "bean/StockBean.h"
#include "dao/productdao.h"
#include "dao/producttypedao.h"
#include "dao/waredao.h"
#include "dao/stockdao.h"
#include "dao/commondao.h"
namespace Ui {
class InvDialog;
}

class InvDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InvDialog(QWidget *parent = 0);
    InvDialog(int status,QString id,QWidget *parent = 0);
    ~InvDialog();
    
private slots:
    void on_addButton_clicked();

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_nameEdit_textChanged(const QString &arg1);

    void on_uCodeButton_clicked();

private:
    Ui::InvDialog *ui;
    int mEditStatus;
    QString mId;
    QString mTypeId;
    QString mWinId;
    QString mWinTitle;
    void init();
    QString getCodeMaxId();
    QString getCodeByTypeId(QString type);
    void setInputEnable(bool b);
    void getProduct(QString id);
    void clearInput();
    void limitsInit();
    PinYinUtils *pinying;
};

#endif // INVDIALOG_H
