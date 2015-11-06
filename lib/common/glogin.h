#ifndef GLOGIN_H
#define GLOGIN_H

#include "lib_global.h"
#include <QDialog>
#include <QPointer>
#include "log4qt/logger.h"
#include "serversettingsdialog.h"
namespace Ui {
class GLogin;
}

class LIBSHARED_EXPORT GLogin : public QDialog
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    explicit GLogin(QWidget *parent = 0);
    ~GLogin();
    void refresh();
    
private slots:

    void on_cancelPushButton_clicked();
    void on_okPushButton_clicked();
    void on_settingsPushButton_clicked();
    void on_serverNameLineEdit_lostFocus();

    void on_serverNameLineEdit_textChanged(const QString &arg1);

private:
    Ui::GLogin *ui;
    QPointer<ServerSettingsDialog> m_settingsDialog;
    QString serverName;
    bool serverNameChangeStatus;
};

#endif // GLOGIN_H
