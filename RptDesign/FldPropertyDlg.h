/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#ifndef FLDPROPERTYDLG_H
#define FLDPROPERTYDLG_H

#include <QDialog>

namespace Ui {
class FldPropertyDlg;
}

class FldPropertyDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit FldPropertyDlg(QWidget *parent = 0);
    ~FldPropertyDlg();
    QString showThis(int index);
    
private:
    Ui::FldPropertyDlg *ui;
};

#endif // FLDPROPERTYDLG_H
