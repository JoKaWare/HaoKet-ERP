#ifndef DINNERFORM_H
#define DINNERFORM_H

#include <QWidget>
#include "common/common.h"
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class DinnerForm;
}

class DinnerForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit DinnerForm(QWidget *parent = 0);
    ~DinnerForm();
    
private slots:
    void on_cancelButton_clicked();

    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_saveButton_clicked();

    void on_delButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::DinnerForm *ui;
    int statusEdit;
    QString m_id;
    QString mWinId;
    QString mWinTitle;
    void init();
    void refreshData();
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
    void clearInput();
    void limitsInit();
};

#endif // DINNERFORM_H
