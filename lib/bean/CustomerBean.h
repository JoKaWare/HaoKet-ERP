#ifndef CUSTOMERBEAN_H
#define CUSTOMERBEAN_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"
class LIBSHARED_EXPORT CustomerBean: public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString cusCode READ cusCode WRITE setCusCode)
    Q_PROPERTY(QString cusName READ cusName WRITE setCusName)
    Q_PROPERTY(QString cusAlias READ cusAlias WRITE setCusAlias)
    Q_PROPERTY(QString cusType READ cusType WRITE setCusType)
    Q_PROPERTY(QString areaCity READ areaCity WRITE setAreaCity)
    Q_PROPERTY(QString pinyinCode READ pinyinCode WRITE setPinyinCode)
    Q_PROPERTY(QString trade READ trade WRITE setTrade)
    Q_PROPERTY(QString address READ address WRITE setAddress)
    Q_PROPERTY(QString post READ post WRITE setPost)
    Q_PROPERTY(QString cusRegCode READ cusRegCode WRITE setCusRegCode)
    Q_PROPERTY(QString cusBank READ cusBank WRITE setCusBank)
    Q_PROPERTY(QString cusAccount READ cusAccount WRITE setCusAccount)
    Q_PROPERTY(QDate devDate READ devDate WRITE setDevDate)
    Q_PROPERTY(QString corporate READ corporate WRITE setCorporate)
    Q_PROPERTY(QString email READ email WRITE setEmail)
    Q_PROPERTY(QString contacts READ contacts WRITE setContacts)
    Q_PROPERTY(QString tel READ tel WRITE setTel)
    Q_PROPERTY(QString fax READ fax WRITE setFax)
    Q_PROPERTY(QString phone READ phone WRITE setPhone)
    Q_PROPERTY(QString cusAddress READ cusAddress WRITE setCusAddress)
    Q_PROPERTY(QString cusPerson READ cusPerson WRITE setCusPerson)
    Q_PROPERTY(QString depCode READ depCode WRITE setDepCode)
    Q_PROPERTY(bool isCredit READ isCredit WRITE setIsCredit)
    Q_PROPERTY(QString cusCreGrade READ cusCreGrade WRITE setCusCreGrade)
    Q_PROPERTY(double cusCreLine READ cusCreLine WRITE setCusCreLine)
    Q_PROPERTY(int cusCreDate READ cusCreDate WRITE setCusCreDate)
    Q_PROPERTY(bool isShop READ isShop WRITE setIsShop)
    Q_PROPERTY(QDate licenceSdate READ licenceSdate WRITE setLicenceSdate)
    Q_PROPERTY(QDate licenceEdate READ licenceEdate WRITE setLicenceEdate)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
    Q_PROPERTY(QString cusDefine1 READ cusDefine1 WRITE setCusDefine1)
    Q_PROPERTY(QString cusDefine2 READ cusDefine2 WRITE setCusDefine2)
    Q_PROPERTY(QString cusDefine3 READ cusDefine3 WRITE setCusDefine3)
    Q_PROPERTY(int status READ status WRITE setStatus)

public:
    int id() {return m_id;}
    void setId(int id) { m_id = id;}

    QString cusCode() { return m_cus_code;}
    void setCusCode(QString code) { m_cus_code = code;}
    QString cusName() { return m_cus_name;}
    void setCusName(QString name) { m_cus_name = name;}
    QString cusAlias() { return m_cus_alias;}
    void setCusAlias(QString value) { m_cus_alias = value;}
    QString cusType() { return m_cus_type;}
    void setCusType(QString value) { m_cus_type = value;}
    QString areaCity() { return m_area_city;}
    void setAreaCity(QString value) { m_area_city = value;}
    QString pinyinCode() { return m_pinyin_code;}
    void setPinyinCode(QString code) { m_pinyin_code = code;}
    QString trade() { return m_trade;}
    void setTrade(QString value) { m_trade = value;}
    QString address() { return m_address;}
    void setAddress(QString value) { m_address = value;}
    QString post() { return m_post;}
    void setPost(QString value) { m_post = value;}
    QString cusRegCode() { return m_cus_reg_code;}
    void setCusRegCode(QString value) { m_cus_reg_code = value;}
    QString cusBank() { return m_cus_bank;}
    void setCusBank(QString value) { m_cus_bank = value;}
    QString cusAccount() { return m_cus_account;}
    void setCusAccount(QString value) { m_cus_account = value;}
    QDate devDate() { return m_dev_date;}
    void setDevDate(QDate value) { m_dev_date = value;}
    QString corporate() { return m_corporate;}
    void setCorporate(QString value) { m_corporate = value;}
    QString email() { return m_email;}
    void setEmail(QString value) { m_email = value;}
    QString contacts() { return m_contacts;}
    void setContacts(QString value) { m_contacts = value;}
    QString tel() { return m_tel;}
    void setTel(QString value) { m_tel = value;}
    QString fax() { return m_fax;}
    void setFax(QString value) { m_fax = value;}
    QString phone() { return m_phone;}
    void setPhone(QString value) { m_phone = value;}
    QString cusAddress() { return m_cus_address;}
    void setCusAddress(QString value) { m_cus_address = value;}
    QString cusPerson() { return m_cus_person;}
    void setCusPerson(QString value) { m_cus_person = value;}
    QString depCode() { return m_dep_code;}
    void setDepCode(QString value) { m_dep_code = value;}
    bool isCredit(){ return m_is_credit;}
    void setIsCredit(bool value){ m_is_credit = value;}
    QString cusCreGrade() { return m_cus_cre_grade;}
    void setCusCreGrade(QString value) { m_cus_cre_grade = value;}
    double cusCreLine() { return m_cus_cre_line;}
    void setCusCreLine(double value) { m_cus_cre_line = value;}
    int cusCreDate() { return m_cus_cre_date;}
    void setCusCreDate(int value) { m_cus_cre_date = value;}
    bool isShop() { return m_is_shop;}
    void setIsShop(bool value) { m_is_shop = value;}
    QDate licenceSdate() { return m_licence_sdate;}
    void setLicenceSdate(QDate value) { m_licence_sdate = value;}
    QDate licenceEdate() { return m_licence_edate;}
    void setLicenceEdate(QDate value) { m_licence_edate = value;}
    QString memo() { return m_memo;}
    void setMemo(QString value) { m_memo = value;}
    QString cusDefine1() { return m_cus_define1;}
    void setCusDefine1(QString value) { m_cus_define1 = value;}
    QString cusDefine2() { return m_cus_define2;}
    void setCusDefine2(QString value) { m_cus_define2 = value;}
    QString cusDefine3() { return m_cus_define3;}
    void setCusDefine3(QString value) { m_cus_define3 = value;}
    int status(){ return m_status;}
    void setStatus(int status){ m_status = status;}
private:
    int m_id;
    QString m_cus_code;
    QString m_cus_name;
    QString m_cus_alias;
    QString m_cus_type;
    QString m_area_city;
    QString m_pinyin_code;
    QString m_trade;
    QString m_address;
    QString m_post;
    QString m_cus_reg_code;
    QString m_cus_bank;
    QString m_cus_account;
    QDate m_dev_date;
    QString m_corporate;
    QString m_email;
    QString m_contacts;
    QString m_tel;
    QString m_fax;
    QString m_phone;
    QString m_cus_address;
    QString m_cus_person;
    QString m_dep_code;
    bool m_is_credit;
    QString m_cus_cre_grade;
    double m_cus_cre_line;
    int m_cus_cre_date;
    bool m_is_shop;
    QDate m_licence_sdate;
    QDate m_licence_edate;
    QString m_memo;
    QString m_cus_define1;
    QString m_cus_define2;
    QString m_cus_define3;
    int m_status;

};
#endif // CUSTOMERBEAN_H
