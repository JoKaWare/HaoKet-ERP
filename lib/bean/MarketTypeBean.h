#ifndef MARKETTYPEBEAN_H
#define MARKETTYPEBEAN_H
#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT MarketTypeBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int marketTypeId READ marketTypeId WRITE setMarketTypeId)
    Q_PROPERTY(QString marketTypeName READ marketTypeName WRITE setMarketTypeName)
    Q_PROPERTY(QString marketTypeStart READ marketTypeStart WRITE setMarketTypeStart)
    Q_PROPERTY(QString marketTypeAlia READ marketTypeAlia WRITE setMarketTypeAlia)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
public:
    Q_INVOKABLE MarketTypeBean(QObject* parent = 0){};
    virtual ~MarketTypeBean() {}
    int marketTypeId() const { return m_market_type_id;}
    void setMarketTypeId(int id){ m_market_type_id=id;}
    QString marketTypeName() const { return m_market_type_name;}
    void setMarketTypeName(QString name) { m_market_type_name = name;}
    QString marketTypeStart() const { return m_market_type_start;}
    void  setMarketTypeStart(QString start){ m_market_type_start=start;}
    QString marketTypeAlia() const { return m_market_type_alia;}
    void setMarketTypeAlia(QString alia) { m_market_type_alia = alia;}
    QString memo() const { return m_memo;}
    void setMemo(QString memo) { m_memo = memo;}
private:
    int m_market_type_id;
    QString m_market_type_name;
    QString m_market_type_start;
    QString m_market_type_alia;
    QString m_memo;

};
#endif // MARKETTYPEBEAN_H
