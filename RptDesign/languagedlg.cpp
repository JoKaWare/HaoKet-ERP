/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#include "languagedlg.h"
#include "ui_languagedlg.h"

LanguageDlg::LanguageDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LanguageDlg)
{
    ui->setupUi(this);
    this->setWindowTitle("Language QtRptDesigner");
    this->setFixedSize(485,148);

    QSettings settings(QCoreApplication::applicationDirPath()+"/setting.ini",QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.beginGroup("language");
    QString language = settings.value("language").toString();
    settings.endGroup();
//    //loading active languge from qsettings ini file
//    //default value is not set because i'm reading the system language at start up

    if (language == "") //default system language
        ui->cmbLanguage->setCurrentIndex(0);

    else if (language == "en_US")//english united states
        ui->cmbLanguage->setCurrentIndex(1);

    else if (language == "ru_RU")//russian
        ui->cmbLanguage->setCurrentIndex(2);

    else if (language == "sr_RS")//serbian cyrilic
        ui->cmbLanguage->setCurrentIndex(3);

    else if (language == "sr_RS@latin")
        ui->cmbLanguage->setCurrentIndex(4);

    loadedIndex = ui->cmbLanguage->currentIndex();
}

LanguageDlg::~LanguageDlg() {
    delete ui;
}

void LanguageDlg::on_btnOk_clicked() {
    QSettings settings(QCoreApplication::applicationDirPath()+"/setting.ini",QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    if (ui->cmbLanguage->currentIndex() != loadedIndex) {
        settings.beginGroup("language");
        switch(ui->cmbLanguage->currentIndex())
        {
        case 0://system default
            settings.setValue("language", "");
            break;
        case 1://american english
            settings.setValue("language", "en_US");
            break;
        case 2://russian
            settings.setValue("language", "ru_RU");
            break;
        case 3://serbian
            settings.setValue("language", "sr_RS");
            break;
        case 4://serbian latin
            settings.setValue("language", "sr_RS@latin");
            break;
        }
        settings.endGroup();
        QMessageBox::information(this,tr("Message QtRptDesigner"),tr("The language for this application has been changed. The change will take effect the next time the application is started"),QMessageBox::Ok);
    }
    this->close();
}

void LanguageDlg::on_btnCancel_clicked() {
    this->close();
}
