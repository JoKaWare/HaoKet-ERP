#ifndef TASTEFORM_H
#define TASTEFORM_H

#include <QWidget>
#include <QStandardItemModel>
namespace Ui {
class TasteForm;
}

class TasteForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit TasteForm(QWidget *parent = 0);
    ~TasteForm();
    
private slots:
    void on_cancelButton_clicked();

    void on_newButton_clicked();

    void on_saveButton_clicked();

    void on_editButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_delButton_clicked();

private:
    Ui::TasteForm *ui;
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

#endif // TASTEFORM_H
