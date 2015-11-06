#ifndef SASETDIALOG_H
#define SASETDIALOG_H

#include <QDialog>

namespace Ui {
class SaSetDialog;
}

class SaSetDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SaSetDialog(QWidget *parent = 0);
    ~SaSetDialog();
    
private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::SaSetDialog *ui;
    void init();
    QString mWinId;
    QString mWinTitle;
};

#endif // SASETDIALOG_H
