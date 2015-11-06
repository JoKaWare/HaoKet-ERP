#ifndef POSITIONFORM_H
#define POSITIONFORM_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class PositionForm;
}

class PositionForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit PositionForm(QWidget *parent = 0);
    ~PositionForm();
    
private slots:
    void on_newButton_clicked();

    void on_editButton_clicked();

    void on_saveButton_clicked();

    void on_delButton_clicked();

    void on_cancelButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::PositionForm *ui;
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

#endif // POSITIONFORM_H
