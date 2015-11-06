#ifndef STRUCTUREFORM_H
#define STRUCTUREFORM_H

#include <QWidget>
#include <QStandardItem>
#include "bean/TypeBean.h"
#include "bean/StructureBean.h"
#include "dao/typedao.h"
#include "dao/structuredao.h"
#include "system/limitscommon.h"
namespace Ui {
class StructureForm;
}

class StructureForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit StructureForm(QWidget *parent = 0);
    ~StructureForm();
    
private slots:
    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_delButton_clicked();

    void on_cancelButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_queryButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::StructureForm *ui;
    int statusEdit;
    QString m_id;
    QString m_typeId;
    QString mWinId;
    QString mWinTitle;
    void init();
    void refreshData();
    void clearInput();
    void setButtonEnabled(bool b);
    void limitsInit();
};

#endif // STRUCTUREFORM_H
