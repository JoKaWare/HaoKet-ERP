#ifndef WAREHOUSEBEAN_H
#define WAREHOUSEBEAN_H


#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT WareHouseBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(QString whCode READ whCode WRITE setWhCode)
    Q_PROPERTY(QString whName READ whName WRITE setWhName)
    Q_PROPERTY(QString depCode READ depCode WRITE setDepCode)
    Q_PROPERTY(QString whAddr READ whAddr WRITE setWhAddr)
    Q_PROPERTY(QString whTel READ whTel WRITE setWhTel)
    Q_PROPERTY(int whPerson READ whPerson WRITE setWhPerson)
    Q_PROPERTY(bool isCargo READ isCargo WRITE setIsCargo)
    Q_PROPERTY(bool isShop READ isShop WRITE setIsShop)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)

public:
    QString whCode(){ return m_wh_code;}
    void setWhCode(QString code) { m_wh_code = code;}
    QString whName(){ return m_wh_name;}
    void setWhName(QString name) { m_wh_name = name;}
    QString depCode() { return m_dep_code;}
    void setDepCode(QString code){ m_dep_code = code;}
    QString whAddr(){ return m_wh_addr;}
    void setWhAddr(QString addr) { m_wh_addr = addr;}
    QString whTel() { return m_wh_tel;}
    void setWhTel(QString tel){ m_wh_tel = tel;}
    int whPerson() { return m_wh_person;}
    void setWhPerson(int person){ m_wh_person = person;}
    bool isCargo() { return m_is_cargo;}
    void setIsCargo(bool b){ m_is_cargo = b;}
    bool isShop() { return m_is_shop;}
    void setIsShop(bool b) { m_is_shop = b;}
    QString memo() { return m_memo;}
    void setMemo(QString memo){ m_memo = memo;}
private:
    QString m_wh_code;
    QString m_wh_name;
    QString m_dep_code;
    QString m_wh_addr;
    QString m_wh_tel;
    int m_wh_person;
    bool m_is_cargo;
    bool m_is_shop;
    QString m_memo;
};
#endif // WAREHOUSEBEAN_H
