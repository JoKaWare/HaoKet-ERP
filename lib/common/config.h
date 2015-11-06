#ifndef CONFIG_H
#define CONFIG_H
#include <QtCore/QDir>
#include "aes.h"
#include "sha384.h"
#include "log4qt/logger.h"
#include "lib_global.h"

class LIBSHARED_EXPORT Config:public QObject
{

    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    Config();
    void loadSettings();
    void saveSettings();
    void saveSettings(QString _dbName,QString _dbIp,QString _dbPort,QString _dbUser,QString _dbPass);
    void saveServer(QString _serverAddr);
    void saveLoginUser(QString _user,QString _pass);
    void parserSetting(QString s);
    static Config *configuration();
    QString encrypt(QString src);
    QString decrypt(QString dest);
    QString getServerAddress(){ return serverAddress;}
    quint16 getServerPort() { return serverPort;}
    QString getConfigFN()	{ return configFN; }
    QString getDbDriver()   { return dbDriver; }
    QString getDbIp()       { return dbIp; }
    QString getDbName()     { return dbName; }
    QString getDbPort()     { return dbPort; }
    QString getDbUser()     { return dbUser; }
    QString getDbPass()     { return dbPass; }

    QString getUsername()   { return _cUsername; }
    QString getPassword()   { return _cPassword; }
    QString getDatabaseURL(){ return _evalDatabaseURL; }

private:
    QString serverAddress;

    QString configFN;
    QString dbDriver;
    QString dbIp;
    QString dbName;
    QString dbPort;
    QString dbUser;
    QString dbPass;
    QString _cUsername;
    QString _cPassword;
    QString _evalDatabaseURL;

    quint16 serverPort;
    Aarni::AES aes;
    Aarni::SHA384 sha;
    QString aesKey;
    QByteArray buf;


};

#endif // CONFIG_H
