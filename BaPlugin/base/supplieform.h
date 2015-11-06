#ifndef SUPPLIEFORM_H
#define SUPPLIEFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
namespace Ui {
class SupplieForm;
}

class SupplieForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit SupplieForm(QWidget *parent = 0);
    ~SupplieForm();
    
private slots:
    void on_cancelButton_clicked();

    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_saveButton_clicked();

    void on_delButton_clicked();

    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::SupplieForm *ui;
    int statusEdit;
    QString m_id;
    QString mWinId;
    QString mWinTitle;
    void init();
    void limitsInit();
    void refreshData();
    void setInputEnabled(bool b);
    void setInputClear();
    void setButtonEnabled(bool b);
};

#endif // SUPPLIEFORM_H
