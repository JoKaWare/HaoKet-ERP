#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>
#include "lib_global.h"

namespace Ui {
class AddUserDialog;
}

class LIBSHARED_EXPORT AddUserDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddUserDialog(QWidget *parent = 0);
    ~AddUserDialog();
    
private slots:
    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::AddUserDialog *ui;
};

#endif // ADDUSERDIALOG_H
