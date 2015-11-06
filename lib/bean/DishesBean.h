#ifndef productBEAN_H
#define productBEAN_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"

class LIBSHARED_EXPORT DishesBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString productName READ productName WRITE setProductName)
    Q_PROPERTY(QString productCode READ productCode WRITE setProductCode)
    Q_PROPERTY(QString pinyinCode READ pinyinCode WRITE setPinyinCode)
    Q_PROPERTY(QString assistedCode READ assistedCode WRITE setAssistedCode)
    Q_PROPERTY(QString enName READ enName WRITE setEnName)
    Q_PROPERTY(QString style READ style WRITE setStyle)
    Q_PROPERTY(QString unit READ unit WRITE setUnit)
    Q_PROPERTY(QString typeId READ typeId WRITE setTypeId)
    Q_PROPERTY(QString purchaseUnit READ purchaseUnit WRITE setPurchaseUnit)
    Q_PROPERTY(QString stockUnit READ stockUnit WRITE setStockUnit)
    Q_PROPERTY(int puStUnit READ puStUnit WRITE setPuStUnit)
    Q_PROPERTY(bool isRaw READ isRaw WRITE setIsRaw)
    Q_PROPERTY(double price1 READ price1 WRITE setPrice1)
    Q_PROPERTY(double price2 READ price2 WRITE setPrice2)
    Q_PROPERTY(double price3 READ price3 WRITE setPrice3)
    Q_PROPERTY(double mPrice1 READ mPrice1 WRITE setMPrice1)
    Q_PROPERTY(double mPrice2 READ mPrice2 WRITE setMPrice2)
    Q_PROPERTY(double mPrice3 READ mPrice3 WRITE setMPrice3)
    Q_PROPERTY(int status READ status WRITE setStatus)
    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(double lowDiscount READ lowDiscount WRITE setLowDiscount)
    Q_PROPERTY(bool isTempDishes READ isTempDishes WRITE setIsTempDishes)
    Q_PROPERTY(bool isWeighingConf READ isWeighingConf WRITE setIsWeighingConf)
    Q_PROPERTY(bool isDisc READ isDisc WRITE setIsDisc)
    Q_PROPERTY(bool isCurrentPrices READ isCurrentPrices WRITE setIsCurrentPrices)
    Q_PROPERTY(bool isSet READ isSet WRITE setIsSet)
    Q_PROPERTY(bool isDownPad READ isDownPad WRITE setIsDownPad)
    Q_PROPERTY(bool isPieceDishes READ isPieceDishes WRITE setIsPieceDishes)
    Q_PROPERTY(bool isMarketing READ isMarketing WRITE setIsMarketing)
    Q_PROPERTY(bool isPurchase READ isPurchase WRITE setIsPurchase)
    Q_PROPERTY(double puPrice READ puPrice WRITE setPuPrice)
    Q_PROPERTY(QString eatType READ eatType WRITE setEatType)
    Q_PROPERTY(QString picture1 READ picture1 WRITE setPicture1)
    Q_PROPERTY(QString picture2 READ picture2 WRITE setPicture2)
    Q_PROPERTY(QString picture3 READ picture3 WRITE setPicture3)
public:
    Q_INVOKABLE DishesBean(QObject* parent = 0){};
    virtual ~DishesBean() {}
    int id() const  { return m_id;}
    void setId(int id) { m_id=id;}
    QString productName() const { return m_product_name;}
    void setProductName(QString name) { m_product_name=name;}

    QString productCode() const { return m_product_code;}
    void setProductCode(QString code) { m_product_code=code;}

    QString pinyinCode() const { return m_pinyin_code;}
    void setPinyinCode(QString code) { m_pinyin_code=code;}

    QString assistedCode() const { return m_assisted_code;}
    void setAssistedCode(QString code) { m_assisted_code=code;}

    QString enName() const { return m_en_name;}
    void setEnName(QString name) { m_en_name=name;}

    QString style() const { return m_style;}
    void setStyle(QString style) { m_style=style;}

    QString unit() const { return m_unit;}
    void setUnit(QString unit) { m_unit=unit;}

    QString typeId() const { return m_type_id;}
    void setTypeId(QString id) { m_type_id=id;}
    QString purchaseUnit() { return m_purchase_unit;}
    void setPurchaseUnit(QString unit){ m_purchase_unit = unit;}
    QString stockUnit() { return m_stock_unit;}
    void setStockUnit(QString unit){ m_stock_unit = unit;}
    int puStUnit() { return m_pu_st_unit;}
    void setPuStUnit(int value){ m_pu_st_unit = value;}
    bool isRaw() { return m_is_raw;}
    void setIsRaw(bool b){ m_is_raw = b;}
    double price1() const { return m_price1;}
    void setPrice1(double price) { m_price1=price;}
    double price2() const { return m_price2;}
    void setPrice2(double price) { m_price2=price;}
    double price3() const { return m_price3;}
    void setPrice3(double price) { m_price3=price;}
    double mPrice1() const { return m_m_price1;}
    void setMPrice1(double price) { m_m_price1=price;}
    double mPrice2() const { return m_m_price2;}
    void setMPrice2(double price) { m_m_price2=price;}
    double mPrice3() const { return m_m_price3;}
    void setMPrice3(double price) { m_m_price3=price;}
    int createdBy(){return m_created_by; }
    void setCreatedBy(int user){ m_created_by = user;}

    QDateTime created(){ return m_created; }
    void setCreated(QDateTime time){m_created = time;}

    int status() const { return m_status;}
    void setStatus(int status) { m_status=status;}

    bool isTempDishes() const { return m_is_temp_dishes;}
    void setIsTempDishes(bool b) { m_is_temp_dishes=b;}
    bool isWeighingConf() const { return m_is_weighing_conf;}
    void setIsWeighingConf(bool b) { m_is_weighing_conf=b;}
    double lowDiscount(){ return m_low_discount;}
    void setLowDiscount(double discount){ m_low_discount = discount;}
    bool isDisc() const { return m_is_disc;}
    void setIsDisc(bool b) { m_is_disc=b;}
    bool isCurrentPrices() const { return m_is_current_prices;}
    void setIsCurrentPrices(bool b) { m_is_current_prices=b;}
    bool isSet() const { return m_is_set;}
    void setIsSet(bool b) { m_is_set=b;}
    bool isDownPad() const { return m_is_down_pad;}
    void setIsDownPad(bool b) { m_is_down_pad=b;}
    bool isPieceDishes() const { return m_is_piece_dishes;}
    void setIsPieceDishes(bool b) { m_is_piece_dishes=b;}
    bool isMarketing() const { return m_is_marketing;}
    void setIsMarketing(bool b) { m_is_marketing=b;}
    bool isPurchase() { return m_is_purchase;}
    void setIsPurchase(bool b) { m_is_purchase = b;}
    double puPrice() { return m_pu_price;}
    void setPuPrice(double value){ m_pu_price = value;}
    QString eatType() const { return m_eat_type;}
    void setEatType(QString type) { m_eat_type=type;}
    QString picture1() const { return m_picture1;}
    void setPicture1(QString p) { m_picture1=p;}
    QString picture2() const { return m_picture2;}
    void setPicture2(QString p) { m_picture2=p;}
    QString picture3() const { return m_picture3;}
    void setPicture3(QString p) { m_picture3=p;}
private:
    int m_id;
    QString m_product_code;
    QString m_product_name;
    QString m_pinyin_code;
    QString m_assisted_code;
    QString m_en_name;
    QString m_style;
    QString m_unit;
    QString m_type_id;
    QString m_purchase_unit;
    QString m_stock_unit;
    int m_pu_st_unit;
    bool m_is_raw;
    double m_price1;
    double m_price2;
    double m_price3;
    double m_m_price1;
    double m_m_price2;
    double m_m_price3;
    int m_status;
    int m_created_by;
    QDateTime m_created;
    double m_low_discount;
    bool m_is_temp_dishes;
    bool m_is_weighing_conf;
    bool m_is_disc;
    bool m_is_current_prices;
    bool m_is_set;
    bool m_is_down_pad;
    bool m_is_piece_dishes;
    bool m_is_marketing;
    bool m_is_purchase;
    double m_pu_price;
    QString m_eat_type;
    QString m_picture1;
    QString m_picture2;
    QString m_picture3;


};
#endif // productBEAN_H
