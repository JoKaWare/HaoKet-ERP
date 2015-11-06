#ifndef POSITIONBEAN_H
#define POSITIONBEAN_H


#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT PositionBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(QString positionCode READ positionCode WRITE setPositionCode)
    Q_PROPERTY(QString positionName READ positionName WRITE setPositionName)
    Q_PROPERTY(QString whCode READ whCode WRITE setWhCode)
    Q_PROPERTY(QString positionUnit READ positionUnit WRITE setPositionUnit)
    Q_PROPERTY(int topSum READ topSum WRITE setTopSum)
    Q_PROPERTY(QString positionArea READ positionArea WRITE setPositionArea)
    Q_PROPERTY(QString positionDesc READ positionDesc WRITE setPositionDesc)
    Q_PROPERTY(int positionLevel READ positionLevel WRITE setPositionLevel)
    Q_PROPERTY(int status READ status WRITE setStatus)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
public:
    QString positionCode() { return m_position_code;}
    void setPositionCode(QString code) { m_position_code = code;}
    QString positionName() { return m_position_name;}
    void setPositionName(QString name) { m_position_name = name;}
    QString whCode() { return m_wh_code;}
    void setWhCode(QString code) { m_wh_code = code ;}
    QString positionUnit(){ return m_position_unit;}
    void setPositionUnit(QString unit){ m_position_unit = unit;}
    int topSum() { return m_top_sum;}
    void setTopSum(int sum){ m_top_sum = sum;}
    QString positionArea(){ return m_position_area;}
    void setPositionArea(QString area){ m_position_area = area;}
    QString positionDesc(){ return m_position_desc;}
    void setPositionDesc(QString desc){ m_position_desc = desc;}
    int positionLevel() { return m_position_level;}
    void setPositionLevel(int level){ m_position_level = level;}
    int status() { return m_status;}
    void setStatus(int status){ m_status = status;}
    QString memo() { return m_memo;}
    void setMemo(QString memo){ m_memo = memo;}

private:
    QString m_position_code;
    QString m_position_name;
    QString m_wh_code;
    QString m_position_unit;
    int m_top_sum;
    QString m_position_desc;
    QString m_position_area;
    int m_position_level;
    int m_status;
    QString m_memo;
};
#endif // POSITIONBEAN_H
