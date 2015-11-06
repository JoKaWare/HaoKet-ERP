/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#ifndef LANGUAGEDLG_H
#define LANGUAGEDLG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class LanguageDlg;
}

class LanguageDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit LanguageDlg(QWidget *parent = 0);
    ~LanguageDlg();
    
private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

private:
    Ui::LanguageDlg *ui;
    int loadedIndex;
};

#endif // LANGUAGEDLG_H
