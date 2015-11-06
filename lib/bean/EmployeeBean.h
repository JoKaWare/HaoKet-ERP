#ifndef EMPLOYEEBEAN_H
#define EMPLOYEEBEAN_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"

class LIBSHARED_EXPORT EmployeeBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int empId READ empId WRITE setEmpId)
    Q_PROPERTY(QString empName READ empName WRITE setEmpName)
    Q_PROPERTY(QString empCode READ empCode WRITE setEmpCode)
    Q_PROPERTY(QString empAttr READ empAttr WRITE setEmpAttr)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
    Q_PROPERTY(QDateTime entryDate READ entryDate WRITE setEntryDate)
    Q_PROPERTY(QString depId READ depId WRITE setDepId)
    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(QString sex READ sex WRITE setSex)
    Q_PROPERTY(QString height READ height WRITE setHeight)
    Q_PROPERTY(QString weight READ weight WRITE setWeight)
    Q_PROPERTY(QString nation READ nation WRITE setNation)
    Q_PROPERTY(QString hometown READ hometown WRITE setHometown)
    Q_PROPERTY(QDateTime birth READ birth WRITE setBirth)
    Q_PROPERTY(QDateTime graduationDate READ graduationDate WRITE setGraduationDate)
    Q_PROPERTY(QString educational READ educational WRITE setEducational)
    Q_PROPERTY(QString graduationShcool READ graduationShcool WRITE setGraduationShcool)
    Q_PROPERTY(QString cardNumber READ cardNumber WRITE setCardNumber)
    Q_PROPERTY(QString phone READ phone WRITE setPhone)
    Q_PROPERTY(QString zip READ zip WRITE setZip)
    Q_PROPERTY(QString addr READ addr WRITE setAddr)
    Q_PROPERTY(QString tel READ tel WRITE setTel)
    Q_PROPERTY(QString residenceAddr READ residenceAddr WRITE setResidenceAddr)
    Q_PROPERTY(QString guarantor READ guarantor WRITE setGuarantor)
    Q_PROPERTY(QString guarantorTel READ guarantorTel WRITE setGuarantorTel)
    Q_PROPERTY(QString guarantorAddr READ guarantorAddr WRITE setGuarantorAddr)
    Q_PROPERTY(QString guarantorNumber READ guarantorNumber WRITE setGuarantorNumber)
    Q_PROPERTY(QString guarantorRelation READ guarantorRelation WRITE setGuarantorRelation)
    Q_PROPERTY(int status READ status WRITE setStatus)

public:
    Q_INVOKABLE EmployeeBean(QObject* parent = 0){};
    virtual ~EmployeeBean() {}
    int empId() const { return m_emp_id;}
    void setEmpId(int id){ m_emp_id=id;}
    QString empName() const { return m_emp_name;}
    void setEmpName(QString name) { m_emp_name=name;}
    QString empCode() const { return m_emp_code;}
    void setEmpCode(QString code) { m_emp_code=code;}
    QString empAttr() const { return m_emp_attr;}
    void setEmpAttr(QString attr) { m_emp_attr=attr;}
    QString memo() const { return m_memo;}
    void setMemo(QString memo) { m_memo=memo;}
    QDateTime entryDate() const { return m_entry_date;}
    void setEntryDate(QDateTime date){ m_entry_date=date;}
    QString depId() const { return m_dep_id;}
    void setDepId(QString id) { m_dep_id=id;}
    int createdBy() const { return m_created_by;}
    void setCreatedBy(int by){ m_created_by=by;}
    QDateTime created() const { return m_created;}
    void setCreated(QDateTime c) { m_created=c;}

    QString sex() const { return m_sex;}
    void setSex(QString sex) { m_sex=sex;}
    QString height() const { return m_height;}
    void setHeight(QString height) { m_height=height;}
    QString weight() const { return m_weight;}
    void setWeight(QString weight) { m_weight=weight;}
    QString nation() const { return m_nation;}
    void setNation(QString nation) { m_nation=nation;}
    QString hometown() const { return m_hometown;}
    void setHometown(QString hometown) { m_hometown=hometown;}
    QDateTime birth() const { return m_birth;}
    void setBirth(QDateTime c) { m_birth=c;}
    QDateTime graduationDate() const { return m_graduation_date;}
    void setGraduationDate(QDateTime c) { m_graduation_date=c;}
    QString educational() const { return m_educational;}
    void setEducational(QString educational) { m_educational=educational;}
    QString graduationShcool() const { return m_graduation_shcool;}
    void setGraduationShcool(QString s) { m_graduation_shcool=s;}
    QString cardNumber() const { return m_card_number;}
    void setCardNumber(QString s) { m_card_number=s;}
    QString phone() const { return m_phone;}
    void setPhone(QString s) { m_phone=s;}
    QString zip() const { return m_zip;}
    void setZip(QString s) { m_zip=s;}
    QString tel() const { return m_tel;}
    void setTel(QString s) { m_tel=s;}
    QString addr() const { return m_addr;}
    void setAddr(QString s) { m_addr=s;}
    QString residenceAddr() const { return m_residence_addr;}
    void setResidenceAddr(QString s) { m_residence_addr=s;}
    QString guarantor() const { return m_guarantor;}
    void setGuarantor(QString s) { m_guarantor=s;}
    QString guarantorTel() const { return m_guarantor_tel;}
    void setGuarantorTel(QString s) { m_guarantor_tel=s;}
    QString guarantorAddr() const { return m_guarantor_addr;}
    void setGuarantorAddr(QString s) { m_guarantor_addr=s;}
    QString guarantorNumber() const { return m_guarantor_number;}
    void setGuarantorNumber(QString s) { m_guarantor_number=s;}
    QString guarantorRelation() const { return m_guarantor_relation;}
    void setGuarantorRelation(QString s) { m_guarantor_relation=s;}
    int status(){ return m_status;}
    void setStatus(int status){ m_status = status;}
private:
    int m_emp_id;
    QString m_emp_code;
    QString m_emp_name;
    QString m_emp_attr;
    QString m_dep_id;
    QDateTime m_entry_date;
    QString m_memo;
    int m_created_by;
    QDateTime m_created;
    QString m_sex;
    QString m_height;
    QString m_weight;
    QString m_nation;
    QString m_hometown;
    QDateTime m_birth;
    QDateTime m_graduation_date;
    QString m_educational;
    QString m_graduation_shcool;
    QString m_phone;
    QString m_card_number;
    QString m_addr;
    QString m_zip;
    QString m_residence_addr;
    QString m_tel;
    QString m_guarantor;
    QString m_guarantor_tel;
    QString m_guarantor_addr;
    QString m_guarantor_number;
    QString m_guarantor_relation;
    int m_status;


};
#endif // EMPLOYEEBEAN_H
