#ifndef DISHESDIALOG_H
#define DISHESDIALOG_H

#include <QDialog>
#include "common/pinyinutils.h"
#include "bean/UnitBean.h"
#include "dao/commondao.h"
#include "common/qkstringutils.h"

namespace Ui {
class DishesDialog;
}

class DishesDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DishesDialog(int status,QString id,QWidget *parent = 0);
    ~DishesDialog();
    
private slots:
    void on_cancelButton_clicked();

    void on_saveButton_clicked();

    void on_addButton_clicked();

    void on_nameEdit_textChanged(const QString &arg1);

private:
    Ui::DishesDialog *ui;
    int editStatus;
    QString m_id;
    QString mTypeId;
    QString mWinId;
    QString mWinTitle;
    void init();
    QString getCodeMaxId();
    QString getCodeByTypeId(QString type);
    void setInputEnable(bool b);
    void getDishes(QString id);
    void clearInput();
    void limitsInit();
    PinYinUtils *pinying;
};

#endif // DISHESDIALOG_H
