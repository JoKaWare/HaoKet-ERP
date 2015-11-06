#ifndef EMPLISTDIALOG_H
#define EMPLISTDIALOG_H

#include <QDialog>
#include <QModelIndex>
namespace Ui {
class EmpListDialog;
}

class EmpListDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit EmpListDialog(QWidget *parent = 0);
    ~EmpListDialog();
    
private slots:
    void on_cancleButton_clicked();

    void on_okButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_qksearcheditbox_editChanged(const QString &arg1);

private:
    Ui::EmpListDialog *ui;
    QString mWinId;
    QString mWinTitle;
    void init();
    void limitsInit();
    QString m_id;
};

#endif // EMPLISTDIALOG_H
