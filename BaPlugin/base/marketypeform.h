#ifndef MARKETYPEFORM_H
#define MARKETYPEFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
namespace Ui {
class MarkeTypeForm;
}

class MarkeTypeForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit MarkeTypeForm(QWidget *parent = 0);
    ~MarkeTypeForm();
    
private slots:
    void on_cancelButton_clicked();

    void on_newButton_clicked();

    void on_saveButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_editButton_clicked();

    void on_delButton_clicked();

private:
    Ui::MarkeTypeForm *ui;
    int statusEdit;
    QString m_id;
    QString mWinId;
    QString mWinTitle;
    void init();
    void refreshData();
    void limitsInit();
    void setInputEnabled(bool b);
    void setButtonEnabled(bool b);
};

#endif // MARKETYPEFORM_H
