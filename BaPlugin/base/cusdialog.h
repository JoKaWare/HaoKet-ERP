#ifndef CUSDIALOG_H
#define CUSDIALOG_H

#include <QDialog>
#include "common/pinyinutils.h"
#include "bean/CustomerBean.h"
#include "bean/CustomerTypeBean.h"
#include "bean/UnitBean.h"
#include "dao/customerdao.h"
#include "dao/customertypedao.h"
#include "dao/commondao.h"
namespace Ui {
class CusDialog;
}

class CusDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CusDialog(QWidget *parent = 0);
    CusDialog(int status,QString id,QWidget *parent = 0);

    ~CusDialog();
    
private slots:
    void on_cancelButton_clicked();

    void on_addButton_clicked();

    void on_saveButton_clicked();

    void on_uCodeButton_clicked();

    void on_cusNameEdit_textChanged(const QString &arg1);

private:
    Ui::CusDialog *ui;
    int mEditStatus;
    QString mId;
    QString mTypeId;
    QString mWinId;
    QString mWinTitle;
    void init();
    QString getCodeMaxId();
    QString getCodeByTypeId(QString type);
    void setInputEnable(bool b);
    void getCusotmer(QString id);
    void clearInput();
    void limitsInit();
    PinYinUtils *pinying;
};

#endif // CUSDIALOG_H
