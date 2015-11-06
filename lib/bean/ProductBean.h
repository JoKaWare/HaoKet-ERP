#ifndef PRODUCTBEAN_H
#define PRODUCTBEAN_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"

class LIBSHARED_EXPORT ProductBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString productCode READ productCode WRITE setProductCode)
    Q_PROPERTY(QString productName READ productName WRITE setProductName)
    Q_PROPERTY(QString productNo READ productNo WRITE setProductNo)
    Q_PROPERTY(QString style READ style WRITE setStyle)
    Q_PROPERTY(QString pinyinCode READ pinyinCode WRITE setPinyinCode)
    Q_PROPERTY(QString typeId READ typeId WRITE setTypeId)
    Q_PROPERTY(int supplierId READ supplierId WRITE setSupplierId)
    Q_PROPERTY(QString whCode READ whCode WRITE setWhCode)
    Q_PROPERTY(QString positionCode READ positionCode WRITE setPositionCode)
    Q_PROPERTY(bool isRaw READ isRaw WRITE setIsRaw)
    Q_PROPERTY(bool isSale READ isSale WRITE setIsSale)
    Q_PROPERTY(bool isPurchase READ isPurchase WRITE setIsPurchase)
    Q_PROPERTY(bool isComsume READ isComsume WRITE setIsComsume)
    Q_PROPERTY(bool isImei READ isImei WRITE setIsImei)
    Q_PROPERTY(QString purchaseUnit READ purchaseUnit WRITE setPurchaseUnit)
    Q_PROPERTY(QString stockUnit READ stockUnit WRITE setStockUnit)
    Q_PROPERTY(int puStUnit READ puStUnit WRITE setPuStUnit)
    Q_PROPERTY(int stDoUnit READ stDoUnit WRITE setStDoUnit)
    Q_PROPERTY(QString doseUnit READ doseUnit WRITE setDoseUnit)
    Q_PROPERTY(QString saleUnit READ saleUnit WRITE setSaleUnit)
    Q_PROPERTY(bool isPosPurchase READ isPosPurchase WRITE setIsPosPurchase)
    Q_PROPERTY(bool isPosDown READ isPosDown WRITE setIsPosDown)
    Q_PROPERTY(bool isSaleConsumption READ isSaleConsumption WRITE setIsSaleConsumption)
    Q_PROPERTY(bool isWeighingConf READ isWeighingConf WRITE setIsWeighingConf)
    Q_PROPERTY(int lowSum READ lowSum WRITE setLowSum)
    Q_PROPERTY(int topSum READ topSum WRITE setTopSum)
    Q_PROPERTY(double puPrice READ puPrice WRITE setPuPrice)

    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(int status READ status WRITE setStatus)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
public:

    int id() {return m_id;}
    void setId(int id) { m_id = id;}

    QString productCode() { return m_product_code;}
    void setProductCode(QString code) { m_product_code = code;}
    QString productName() { return m_product_name;}
    void setProductName(QString name) { m_product_name = name;}
    QString productNo() { return m_product_no;}
    void setProductNo(QString no) { m_product_no = no;}
    QString style() { return m_style;}
    void setStyle(QString std) { m_style = std;}
    QString pinyinCode() { return m_pinyin_code;}
    void setPinyinCode(QString code) { m_pinyin_code = code;}
    QString typeId() { return m_type_id;}
    void setTypeId(QString id){ m_type_id = id;}
    int supplierId() const {return m_supplier_id;}
    void setSupplierId(int id){ m_supplier_id=id;}
    QString whCode() { return m_wh_code;}
    void setWhCode(QString code) { m_wh_code = code ;}
    QString positionCode() { return m_position_code;}
    void setPositionCode(QString code) { m_position_code = code;}
    bool isRaw() { return m_is_raw;}
    void setIsRaw(bool b){ m_is_raw = b;}
    bool isImei() { return m_is_imei;}
    void setIsImei(bool b){ m_is_imei = b;}
    bool isSale() { return m_is_sale;}
    void setIsSale(bool b){ m_is_sale = b;}
    bool isPurchase() { return m_is_purchase;}
    void setIsPurchase(bool b) { m_is_purchase = b;}
    bool isComsume() { return m_is_comsume;}
    void setIsComsume(bool b) { m_is_comsume = b;}
    QString purchaseUnit() { return m_purchase_unit;}
    void setPurchaseUnit(QString unit){ m_purchase_unit = unit;}
    QString stockUnit() { return m_stock_unit;}
    void setStockUnit(QString unit){ m_stock_unit = unit;}
    int puStUnit() { return m_pu_st_unit;}
    void setPuStUnit(int value){ m_pu_st_unit = value;}
    int stDoUnit() { return m_st_do_unit;}
    void setStDoUnit(int value){ m_st_do_unit = value;}
    QString doseUnit() { return m_dose_unit;}
    void setDoseUnit(QString unit){ m_dose_unit = unit;}
    QString saleUnit() { return m_sale_unit;}
    void setSaleUnit(QString unit){ m_sale_unit = unit;}
    bool isPosPurchase() { return m_is_pos_purchase;}
    void setIsPosPurchase(bool b){ m_is_pos_purchase = b;}
    bool isPosDown() { return m_is_pos_down;}
    void setIsPosDown(bool b){ m_is_pos_down = b;}
    bool isSaleConsumption() { return m_is_sale_consumption;}
    void setIsSaleConsumption(bool b){ m_is_sale_consumption = b;}
    bool isWeighingConf() { return m_is_weighing_conf;}
    void setIsWeighingConf(bool b){ m_is_weighing_conf = b;}
    int lowSum(){ return m_low_sum;}
    void setLowSum(int value){ m_low_sum = value;}
    int topSum(){ return m_top_sum;}
    void setTopSum(int value){ m_top_sum = value;}
    double puPrice() { return m_pu_price;}
    void setPuPrice(double value){ m_pu_price = value;}

    int createdBy(){return m_created_by; }
    void setCreatedBy(int user){ m_created_by = user;}

    QDateTime created(){ return m_created; }
    void setCreated(QDateTime time){m_created = time;}
    int status() { return m_status;}
    void setStatus(int status){ m_status = status;}
    QString memo() { return m_memo;}
    void setMemo(QString memo){ m_memo = memo;}
private:
    int m_id;
    QString m_product_code;
    QString m_product_name;
    QString m_product_no;
    QString m_style;
    QString m_pinyin_code;
    QString m_type_id;
    int m_supplier_id;
    QString m_wh_code;
    QString m_position_code;
    bool m_is_raw;
    bool m_is_sale;
    bool m_is_purchase;
    bool m_is_comsume;
    bool m_is_imei;
    QString m_purchase_unit;
    QString m_stock_unit;
    int m_pu_st_unit;
    int m_st_do_unit;
    QString m_dose_unit;
    QString m_sale_unit;
    bool m_is_pos_purchase;
    bool m_is_pos_down;
    bool m_is_sale_consumption;
    bool m_is_weighing_conf;
    int m_low_sum;
    int m_top_sum;
    double m_pu_price;
    int m_created_by;
    QDateTime m_created;
    int m_status;
    QString m_memo;

};
#endif // PRODUCTBEAN_H
