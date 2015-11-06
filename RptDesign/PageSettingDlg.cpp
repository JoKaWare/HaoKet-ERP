/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#include "PageSettingDlg.h"
#include "ui_PageSettingDlg.h"

PageSettingDlg::PageSettingDlg(QWidget *parent) : QDialog(parent), ui(new Ui::PageSettingDlg) {
    ui->setupUi(this);
    QObject::connect(ui->rLandscape, SIGNAL(clicked()), this, SLOT(changeOrientation()));
    QObject::connect(ui->rPortrait, SIGNAL(clicked()), this, SLOT(changeOrientation()));
}

void PageSettingDlg::showThis(PageSetting pageSetting) {
    ui->edtLeft->setText(QString::number(pageSetting.marginsLeft/40));
    ui->edtRight->setText(QString::number(pageSetting.marginsRight/40));
    ui->edtTop->setText(QString::number(pageSetting.marginsTop/40));
    ui->edtBottom->setText(QString::number(pageSetting.marginsBottom/40));
    ui->edtWidth->setText(QString::number(pageSetting.pageWidth/40));
    ui->edtHeight->setText(QString::number(pageSetting.pageHeight/40));
    if (pageSetting.pageOrientation == 0) ui->rPortrait->setChecked(true);
    if (pageSetting.pageOrientation == 1) ui->rLandscape->setChecked(true);
    if (ui->rLandscape->isChecked())
        ui->lblOrientation->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/landscape.png")));
    if (ui->rPortrait->isChecked())
        ui->lblOrientation->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/portrait.png")));
    if (exec() == QDialog::Accepted) {
        saveSettings();
    }
}

void PageSettingDlg::changeOrientation() {
    QString str = ui->edtHeight->text();
    ui->edtHeight->setText(ui->edtWidth->text());
    ui->edtWidth->setText(str);
    if (ui->rLandscape->isChecked())
        ui->lblOrientation->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/landscape.png")));
    if (ui->rPortrait->isChecked())
        ui->lblOrientation->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/portrait.png")));
}

void PageSettingDlg::saveSettings() {
    pageSetting.marginsLeft   = ui->edtLeft->text().toFloat()*40;
    pageSetting.marginsRight  = ui->edtRight->text().toFloat()*40;
    pageSetting.marginsTop    = ui->edtTop->text().toFloat()*40;
    pageSetting.marginsBottom = ui->edtBottom->text().toFloat()*40;
    pageSetting.pageWidth     = ui->edtWidth->text().toFloat()*40;
    pageSetting.pageHeight    = ui->edtHeight->text().toFloat()*40;
    if (ui->rLandscape->isChecked())
        pageSetting.pageOrientation = 1;
    if (ui->rPortrait->isChecked())
        pageSetting.pageOrientation = 0;
}

PageSettingDlg::~PageSettingDlg() {
    delete ui;
}
