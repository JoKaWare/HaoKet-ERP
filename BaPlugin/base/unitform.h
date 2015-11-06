#ifndef UNITFORM_H
#define UNITFORM_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class UnitForm;
}

class UnitForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit UnitForm(QWidget *parent = 0);
    ~UnitForm();
    
private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_saveButton_clicked();

    void on_delButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::UnitForm *ui;
    int m_status;
    QString m_id;
    QString mWinId;
    QString mWinTitle;
    void init();
    void limitsInit();
    void refreshData();
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
};

#endif // UNITFORM_H
