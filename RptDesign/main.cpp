/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(QApplication::tr("QtRptDesigner"));
    a.setOrganizationName("Aleksey Osipov");
    a.setOrganizationDomain("https://sourceforge.net/projects/qtrpt/");//projects web page
    a.setApplicationVersion("1.3.0");

    QTextCodec *codec = QTextCodec::codecForName("UTF8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);

    //on linux you need super user rights to write in system directory, so the settings.ini in apps dir is not practicable
    //the best thing for settings file is to write settings to the default paths. on linux
    // /home/<user>/.config/<organization name>/<app name>.conf
    // on windows it's write configuration to registry
    // HKEY_CURRENT_USER/Software/<organization name>/<app name>/<settings group>
    //and configuration is hidden from common user
    QTranslator qTranslator;
    QString locale = QLocale::system().name(); //reading system locale
    QString loSettings;
    QSettings settings(QCoreApplication::applicationDirPath()+"/setting.ini",QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.beginGroup("language");
    loSettings = settings.value("language").toString();
    settings.endGroup();

    if (loSettings != "")//if language is set then ignore system locale
        locale = loSettings;
    //! NOTE: windows and linux system locale are different for serbian language, sr_RS is latin not cyril, this differenc is corrected in code

    if ( qTranslator.load(":/language/i18n/QtRprtDesigner_"+locale+".qm") ) { a.installTranslator(&qTranslator); }


    MainWindow w;
    w.show();

    return a.exec();
}
