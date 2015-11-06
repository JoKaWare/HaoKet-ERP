#ifndef CHANGPWDIALOG_H
#define CHANGPWDIALOG_H

#include <QDialog>
#include <QAbstractButton>
namespace Ui {
class ChangPwDialog;
}

class ChangPwDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ChangPwDialog(QWidget *parent = 0);
    ~ChangPwDialog();
    
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::ChangPwDialog *ui;
    void clear();
};

#endif // CHANGPWDIALOG_H
