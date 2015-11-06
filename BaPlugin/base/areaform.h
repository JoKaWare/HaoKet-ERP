#ifndef AREAFORM_H
#define AREAFORM_H

#include <QWidget>
#include <QModelIndex>

#include "areaform.h"
#include "common/common.h"

namespace Ui {
class AreaForm;
}

class AreaForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit AreaForm(QWidget *parent = 0);
    ~AreaForm();
    
private slots:
    void on_cancelButton_clicked();

    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_saveButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_delButton_clicked();

private:
    Ui::AreaForm *ui;
    int statusEdit;
    QString mWinId;
    QString mWinTitle;
    QString m_id;
    void init();
    void refreshData();
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
    void limitsInit();
};

#endif // AREAFORM_H
