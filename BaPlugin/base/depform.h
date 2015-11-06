#ifndef DEPFORM_H
#define DEPFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>
#include "common/common.h"
#include "bean/DepBean.h"
#include "dao/depdao.h"

namespace Ui {
class DepForm;
}

class DepForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit DepForm(QWidget *parent = 0);
    ~DepForm();
    
private slots:
    void on_cancelButton_clicked();
    void on_newButton_clicked();
    void on_saveButton_clicked();
    void on_editButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_delButton_clicked();

private:
    int editStatus;
    Ui::DepForm *ui;
    QString mWinId;
    QString mWinTitle;
    void init();
    void reTreeData();
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
    void limitsInit();
};

#endif // DEPFORM_H
