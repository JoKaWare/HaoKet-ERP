#ifndef DINNERBEAN_H
#define DINNERBEAN_H
#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT DinnerBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString dinnerId READ dinnerId WRITE setDinnerId)
    Q_PROPERTY(QString dinnerName READ dinnerName WRITE setDinnerName)
    Q_PROPERTY(QString dinnerType READ dinnerType WRITE setDinnerType)
    Q_PROPERTY(int areaId READ areaId WRITE setAreaId)
    Q_PROPERTY(int number READ number WRITE setNumber)
    Q_PROPERTY(bool isService READ isService WRITE setIsService)
    Q_PROPERTY(double lostConsumption READ lostConsumption WRITE setLostConsumption)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)

public:
    Q_INVOKABLE DinnerBean(QObject* parent = 0){};
    virtual ~DinnerBean() {}
    int id() const {return m_id;}
    void setId(int id){ m_id=id;}
    QString dinnerId() const { return m_dinner_id;}
    void setDinnerId(QString id){ m_dinner_id=id;}
    QString dinnerName() const { return m_dinner_name;}
    void setDinnerName(QString name){ m_dinner_name=name;}
    QString dinnerType() const { return m_dinner_type;}
    void setDinnerType(QString type){ m_dinner_type=type;}
    int areaId() const { return m_area_id;}
    void setAreaId(int area_id) { m_area_id=area_id;}
    int number() const { return m_number;}
    void setNumber(int n) { m_number=n;}
    bool isService() const { return m_is_service;}
    void setIsService(bool b){ m_is_service=b;}
    double lostConsumption() const { return m_lost_consumption; }
    void setLostConsumption(double lost) { m_lost_consumption = lost ;}
    QString memo() const { return m_memo;}
    void setMemo(QString memo) { m_memo = memo;}
private:
    int m_id;
    QString m_dinner_id;
    QString m_dinner_name;
    QString m_dinner_type;
    int m_area_id;
    int m_number;
    bool m_is_service;
    double m_lost_consumption;
    QString m_memo;
};
#endif // DINNERBEAN_H
