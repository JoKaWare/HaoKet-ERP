#ifndef KMFORM_H
#define KMFORM_H

#include <QWidget>
#include <QModelIndex>
#include <QStandardItemModel>
#include <QStandardItem>

#include <common/common.h>

namespace Ui {
class KmForm;
}

class KmForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit KmForm(QWidget *parent = 0);
    ~KmForm();
    
private slots:
    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_saveButton_clicked();

    void on_delButton_clicked();

    void on_cancelButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::KmForm *ui;
    int mEditStatus;
    QString mId;
    QString mWinId;
    QString mWinTitle;
    void init();
    void limitsInit();
    void refreshData();
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
};

#endif // KMFORM_H
