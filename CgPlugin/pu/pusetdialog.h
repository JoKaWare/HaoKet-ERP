#ifndef PUSETDIALOG_H
#define PUSETDIALOG_H

#include <QDialog>

namespace Ui {
class PuSetDialog;
}

class PuSetDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PuSetDialog(QWidget *parent = 0);
    ~PuSetDialog();
    
private slots:
    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    Ui::PuSetDialog *ui;
    void init();
    QString mWinId;
    QString mWinTitle;
};

#endif // PUSETDIALOG_H
