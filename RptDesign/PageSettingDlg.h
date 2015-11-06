/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#ifndef PAGESETTINGDLG_H
#define PAGESETTINGDLG_H

#include <QDialog>

namespace Ui {
    class PageSettingDlg;
}

struct PageSetting {
    float marginsLeft;
    float marginsRight;
    float marginsTop;
    float marginsBottom;
    float pageWidth;
    float pageHeight;
    int pageOrientation;
};

class PageSettingDlg : public QDialog
{
    Q_OBJECT

public:
    explicit PageSettingDlg(QWidget *parent = 0);
    ~PageSettingDlg();
    void showThis(PageSetting pageSetting);
    PageSetting pageSetting;

private:
    Ui::PageSettingDlg *ui;
    void saveSettings();

private slots:
    void changeOrientation();

};

#endif // PAGESETTINGDLG_H
