#ifndef TYPEFORM_H
#define TYPEFORM_H

#include <QWidget>
#include <QModelIndex>
#include <QStandardItemModel>
#include <QStandardItem>

#include <common/common.h>
#include <bean/TypeBean.h>
#include <dao/typedao.h>

namespace Ui {
class TypeForm;
}

class TypeForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit TypeForm(QWidget *parent = 0);
    ~TypeForm();
    
private slots:
    void on_cancelButton_clicked();

    void on_newButton_clicked();

    void on_saveButton_clicked();

    void on_editButton_clicked();

    void on_treeView_activated(const QModelIndex &index);

    void on_treeView_clicked(const QModelIndex &index);

    void on_delButton_clicked();

private:
    Ui::TypeForm *ui;
    int statusEdit;
    QString m_id;
    QString mWinId;
    QString mWinTitle;
    void init();
    void limitsInit();
    void refreshData();
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
};

#endif // TYPEFORM_H
