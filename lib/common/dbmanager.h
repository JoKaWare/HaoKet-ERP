#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include "config.h"
#include "log4qt/logger.h"
#include "common.h"
#include "lib_global.h"

class LIBSHARED_EXPORT DBManager:public QObject
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    DBManager(Config *c);
    static DBManager * getDBManager();
    static QSqlDatabase openGoinDB(QString name);
    QSqlDatabase getDBConnection();
    QSqlDatabase getGoinDBConnection();

    void closeConnection();
    bool isClose();
    bool isOpen();
private:
    Config *config;
    QSqlDatabase db;
    QSqlDatabase goindb;
    QSqlError dbErr;
    void initDB();
    void openGoinDB();


};

#endif // DBMANAGER_H
