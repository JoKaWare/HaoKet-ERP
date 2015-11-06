
#include <QApplication>
#include <QMessageBox>
#include "version.h"
#include "haokeapp.h"
#include "haokegui.h"
#include "common/glogin.h"

int main(int argc, char *argv[])
{
    HaoKeApp::setApplicationName("HaoKeL-" HAOKE_VERSION_STR);
    HaoKeApp::setOrganizationName("Full Hotel");
    HaoKeApp::setOrganizationDomain("http://www.haokel.com/");

    HaoKeApp::addLibraryPath(HaoKeApp::applicationDirPath());
    HaoKeApp::addLibraryPath(HaoKeApp::applicationDirPath() + "/plugins");

    /*
        Create the application object
    */
    //qApp->setStyle("Plastique");
    //WindowsXP Plastique Windows Cleanlooks WindowsVista Macintosh
    HaoKeApp *app = new HaoKeApp(argc, argv);

    /*
     *加载qm翻译文件
    */
    QDir dir(QApplication::applicationDirPath() + "/lang");
    QFileInfoList files = dir.entryInfoList(QStringList("*.qm"), QDir::Filter::Files);
    int size = files.size();
    for(int i = 0; i < size; ++i) {
            QTranslator *trs = new QTranslator();
            QString fileName = files.at(i).absoluteFilePath();
            trs->load(fileName);
            qApp->installTranslator(trs);
    }
    files.clear();

    int wstatus = app->login();
    if(wstatus==QDialog::Accepted){
        /*
        QLineEdit edit;
        QString str = edit.metaObject()->className();
        edit.setObjectName("cusName");
        QMessageBox::information(0,"",edit.objectName());
        */
        QApplication::setOverrideCursor(Qt::WaitCursor);
        app->gui()->init();
        QApplication::restoreOverrideCursor();
        app->gui()->showMaximized();



    }else if(wstatus==QDialog::Rejected){
        return 0;
    }

    return app->exec();
}
