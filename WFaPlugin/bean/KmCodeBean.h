#ifndef KMCODEBEAN_H
#define KMCODEBEAN_H
#include <QObject>

class KmCodeBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(QString kmCode READ kmCode WRITE setKmCode)
    Q_PROPERTY(QString kmName READ kmName WRITE setKmName)
    Q_PROPERTY(int grade READ grade WRITE setGrade)
    Q_PROPERTY(QString code READ code WRITE setCode)
    Q_PROPERTY(int property READ property WRITE setProperty)
    Q_PROPERTY(QString kmExplain READ kmExplain WRITE setKmExplain)
    Q_PROPERTY(bool isEnd READ isEnd WRITE setIsEnd)
    Q_PROPERTY(bool isCus READ isCus WRITE setIsCus)
    Q_PROPERTY(bool isSup READ isSup WRITE setIsSup)
    Q_PROPERTY(bool isCash READ isCash WRITE setIsCash)
    Q_PROPERTY(bool isBank READ isBank WRITE setIsBank)

public:
    QString kmCode() { return m_km_code;}
    void setKmCode(QString code){ m_km_code = code;}
    QString kmName() { return m_km_name;}
    void setKmName(QString name){ m_km_name = name;}
    int grade() { return m_grade;}
    void setGrade(int value){ m_grade = value;}
    QString code() { return m_code;}
    void setCode(QString code){ m_code = code;}
    int property() { return m_property;}
    void setProperty(int value){ m_property = value;}
    QString kmExplain() { return m_km_explain;}
    void setKmExplain(QString value){ m_km_explain = value;}
    bool isEnd() { return m_is_end;}
    void setIsEnd(bool b){ m_is_end = b ;}
    bool isCus() { return m_is_cus;}
    void setIsCus(bool b){ m_is_cus = b ;}
    bool isSup() { return m_is_sup;}
    void setIsSup(bool b){ m_is_sup = b ;}
    bool isCash() { return m_is_cash;}
    void setIsCash(bool b){ m_is_cash = b ;}
    bool isBank() { return m_is_bank;}
    void setIsBank(bool b){ m_is_bank = b ;}
private:
    QString m_km_code;
    QString m_km_name;
    int m_grade;
    QString m_code;
    bool m_is_end;
    int m_property;
    QString m_km_explain;
    bool m_is_cus;
    bool m_is_sup;
    bool m_is_cash;
    bool m_is_bank;
};
#endif // KMCODEBEAN_H
