#ifndef SUPPLIERS_H
#define SUPPLIERS_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"

class LIBSHARED_EXPORT SupplieBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int supplieId READ supplieId WRITE setSupplieId)
    Q_PROPERTY(QString supplieCode READ supplieCode WRITE setSupplieCode)
    Q_PROPERTY(QString supplieName READ supplieName WRITE setSupplieName)
    Q_PROPERTY(QString supplieExplian READ supplieExplian WRITE setSupplieExplian)
    Q_PROPERTY(QString supplieType READ supplieType WRITE setSupplieType)
    Q_PROPERTY(QString addr READ addr WRITE setAddr)
    Q_PROPERTY(QString linkman READ linkman WRITE setLinkman)
    Q_PROPERTY(QString linkFunc READ linkFunc WRITE setLinkFunc)
    Q_PROPERTY(QString linkPhone READ linkPhone WRITE setLinkPhone)
    Q_PROPERTY(QString tax READ tax WRITE setTax)
    Q_PROPERTY(QString bank READ bank WRITE setBank)
    Q_PROPERTY(QString bankCard READ bankCard WRITE setBankCard)
    Q_PROPERTY(QString bankName READ bankName WRITE setBankName)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)
    Q_PROPERTY(int updatedBy READ updatedBy WRITE setUpdatedBy)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(QDateTime updated READ updated WRITE setUpdated)
    Q_PROPERTY(int status READ status WRITE setStatus)
public:
    Q_INVOKABLE SupplieBean(QObject* parent = 0){};
    virtual ~SupplieBean() {}
    int supplieId() const {return m_supplie_id;}
    void setSupplieId(int id){ m_supplie_id=id;}
    QString supplieCode() const { return m_supplie_code;}
    void setSupplieCode(QString code){ m_supplie_code=code;}
    QString supplieName() const { return m_supplie_name;}
    void setSupplieName(QString name){ m_supplie_name=name;}
    QString supplieExplian() const { return m_supplie_explian;}
    void setSupplieExplian(QString explian){ m_supplie_explian=explian;}
    QString supplieType() const { return m_supplie_type;}
    void setSupplieType(QString type){ m_supplie_type=type;}
    QString addr() const { return m_addr;}
    void setAddr(QString addr){ m_addr=addr;}
    QString linkman() const { return m_linkman;}
    void setLinkman(QString linkman){ m_linkman=linkman;}
    QString linkFunc() const { return m_link_func;}
    void setLinkFunc(QString func){ m_link_func=func;}
    QString linkPhone() const { return m_link_phone;}
    void setLinkPhone(QString phone){ m_link_phone=phone;}
    QString tax() const { return m_tax;}
    void setTax(QString tax){ m_tax=tax;}
    QString bank() const { return m_bank;}
    void setBank(QString bank){ m_bank=bank;}
    QString bankCard() const { return m_bank_card;}
    void setBankCard(QString card){ m_bank_card=card;}
    QString bankName() const { return m_bank_name;}
    void setBankName(QString name){ m_bank_name=name;}
    QString memo() const { return m_memo;}
    void setMemo(QString memo){ m_memo=memo;}
    int createdBy() const { return m_created_by;}
    void setCreatedBy(int by) { m_created_by=by;}
    int updatedBy() const { return m_updated_by;}
    void setUpdatedBy(int by) { m_updated_by=by;}
    QDateTime created() const { return m_created;}
    void setCreated(QDateTime d){ m_created=d;}
    QDateTime updated() const { return m_updated;}
    void setUpdated(QDateTime d){ m_updated=d;}
    int status(){ return m_status;}
    void setStatus(int status){ m_status = status;}
private:
    int m_supplie_id;
    QString m_supplie_code;
    QString m_supplie_name;
    QString m_supplie_explian;
    QString m_supplie_type;
    QString m_linkman;
    QString m_addr;
    QString m_link_func;
    QString m_link_phone;
    QString m_tax;
    QString m_bank;
    QString m_bank_card;
    QString m_bank_name;
    QString m_memo;
    int m_created_by;
    int m_updated_by;
    QDateTime m_created;
    QDateTime m_updated;
    int m_status;

};
#endif // SUPPLIERS_H
