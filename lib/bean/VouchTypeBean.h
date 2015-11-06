#ifndef VOUCHTYPEBEAN_H
#define VOUCHTYPEBEAN_H

#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT VouchTypeBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(QString vouchType READ vouchType WRITE setVouchType)
    Q_PROPERTY(QString vouchName READ vouchName WRITE setVouchName)
    Q_PROPERTY(QString vouchDesc READ vouchDesc WRITE setVouchDesc)
public:
    QString vouchType(){ return m_vouch_type;}
    void setVouchType(QString code){ m_vouch_type = code;}
    QString vouchName(){ return m_vouch_name;}
    void setVouchName(QString name){ m_vouch_name = name;}
    QString vouchDesc(){ return m_vouch_desc;}
    void setVouchDesc(QString desc){ m_vouch_desc = desc;}
private:
    QString m_vouch_type;
    QString m_vouch_name;
    QString m_vouch_desc;
};
#endif // VOUCHTYPEBEAN_H
