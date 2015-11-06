#ifndef SETTLETYPEBEAN_H
#define SETTLETYPEBEAN_H
#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT SettleTypeBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString settleName READ settleName WRITE setSettleName)
    Q_PROPERTY(QString settleNature READ settleNature WRITE setSettleNature)
    Q_PROPERTY(QString settleCaption READ settleCaption WRITE setSettleCaption)
public:
    int id(){return m_id;}
    void setId(int id){ m_id = id;}
    QString settleName(){ return m_settle_name;}
    void setSettleName(QString name){ m_settle_name = name;}
    QString settleNature(){ return m_settle_nature;}
    void setSettleNature(QString nature){ m_settle_nature = nature;}
    QString settleCaption() { return m_settle_caption;}
    void setSettleCaption(QString caption) { m_settle_caption = caption;}
private:
    int m_id;
    QString m_settle_name;
    QString m_settle_nature;
    QString m_settle_caption;

};
#endif // SETTLETYPEBEAN_H
