#ifndef SERVERSETTINGSDIALOG_H
#define SERVERSETTINGSDIALOG_H
#include "abstractsettingsdialog.h"
#include <QMap>
#include <QObject>
#include <QPalette>
#include "config.h"
class QCheckBox;
class QComboBox;
class QCommandLinkButton;
class QGroupBox;
class QLabel;
class QLineEdit;
class QSpinBox;
class QSpacerItem;

class ServerSettingsDialog : public AbstractSettingsDialog
{
    Q_OBJECT

public:
    enum Page {
      CommonPage,
      NetPage,
      ServicePage

    };
    ServerSettingsDialog(QWidget *parent = 0);

public slots:
    void accept();

};

class ServerCommonSettings : public AbstractSettingsPage
{
    Q_OBJECT

public:
    ServerCommonSettings(QWidget *parent = 0);

public slots:
    void reset(int page);
    void save();

private:
    void createListenList();
    Config *m_cf;
    QCheckBox *m_channelLog;
    QComboBox *m_listen;
    QSpinBox *m_logLevel;
    QSpinBox *m_maxUsers;
    QSpinBox *m_maxUsersPerIp;
    QSpinBox *m_port;
};

class ServerNetSettings : public AbstractSettingsPage
{
    Q_OBJECT

public:
    ServerNetSettings(QWidget *parent = 0);

public slots:

    void save();

private:
    Config *m_cf;
    QComboBox *m_dbIp;
    QSpinBox *m_dbPort;
    QLineEdit *m_dbServer;
    QLineEdit *m_dbUser;
    QLineEdit *m_dbPw;

};
#endif // SERVERSETTINGSDIALOG_H
