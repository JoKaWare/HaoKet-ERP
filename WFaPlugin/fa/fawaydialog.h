#ifndef FAWAYDIALOG_H
#define FAWAYDIALOG_H

#include <QDialog>

namespace Ui {
class FaWayDialog;
}

class FaWayDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit FaWayDialog(QWidget *parent = 0);
    ~FaWayDialog();
    
private slots:
    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::FaWayDialog *ui;
    void init();
};

#endif // FAWAYDIALOG_H
