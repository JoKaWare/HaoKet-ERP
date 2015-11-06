#include "sasettleremainqueryform.h"
#include "bean/CustomerBean.h"
#include "bean/CustomerTypeBean.h"
#include "dao/customerdao.h"
#include "dao/customertypedao.h"
#include "sardwin.h"
#include "haokeapp.h"
#include "saplugin.h"
SaSettleRemainQueryForm::SaSettleRemainQueryForm(QWidget *parent) :
    SingleQueryForm(parent)
{
    QString dSql1 = " SELECT t.* FROM sa_settle_remain(?, ?, ?, ?, ?, ?) "
            " t(cus_code varchar, cus_name varchar, product_code varchar, product_name varchar, "
            " sumQuantity numeric, sumMoney numeric, "
            " settleSumQuantity numeric, settleSumMoney numeric, settleSumAmount numeric,"
            " startSumQuantity numeric, startSumMoney numeric, "
            " startSettleSumQuantity numeric, startSettleSumMoney numeric, "
            " endSumQuantity numeric, endSumMoney numeric )";
    QString dSql2 = "";
    childItemProperties childItem[] = {
            { "cus_code","客户编码","客户编码", 0,80, false, false },
            { "cus_name","客户名称","客户名称", 1, 120,true, true },
            { "product_code","编码","商品", 2,80, true, true },
            { "product_name","名称","商品", 3,100, true, true },
            { "startSumQuantity","数量","上期结余", 4, 80,true, true },
            { "startSumMoney","金额","上期结余", 5, 80,true, true },
            { "sumQuantity","数量","本期出库", 6, 80,true, true },
            { "sumMoney","金额","本期出库", 7, 80,true, true },
            { "settleSumQuantity","数量","本期结算", 8, 80,true, true },
            { "settleSumMoney","金额","本期结算", 9,80, true, true },
            { "settleSumAmount","实际金额","本期结算", 10,80, true, true },
            { "endSumQuantity","数量","本期结余", 11,80, true, false },
            { "endSumMoney","金额","本期结余", 12,80, true, false }

    };
    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }
    QDate oneDate = QDate(QDate::currentDate().year(),QDate::currentDate().month(),1);
    sDateEdit1->setDate(oneDate);
    QList<CustomerBean *> venBeanList = CustomerDAO::queryCus();
    QStringList venList ;
    for(int i =0 ; i < venBeanList.size(); i++){
        venList << venBeanList.at(i)->cusCode() + " - " +venBeanList.at(i)->cusName();
    }
    dwNameQks->setListModel(true);
    dwNameQks->setItems(venList);

    QList<CustomerTypeBean *> typeBeanList = CustomerTypeDAO::queryType();
    QStringList typeList ;
    for(int i =0 ; i < typeBeanList.size(); i++){
        typeList << typeBeanList.at(i)->typeId() + " - " +typeBeanList.at(i)->typeName();
    }
    dwTypeQks->setListModel(true);
    dwTypeQks->setItems(typeList);

    noEdit->setVisible(false);
    idLabel->setVisible(false);

    Label->setText("是否结算:");
    rBnt2->setText("未结算");
    rBnt3->setText("已结算");
    Label->setVisible(false);
    rBnt1->setVisible(false);
    rBnt2->setVisible(false);
    rBnt3->setVisible(false);
    QString formId = HaoKeApp::saSubId() + SaPlugin::settleRemainQueryWinId();
    QString winTitle = "销售结算余额表";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::saSubId().toInt(),formId.toInt(),0,"");

    setFormId(formId);
    setTabDetailText("销售结算余额表");
    //设置明细合计列号
    QList<int > totalItem;
    totalItem << 6 << 7 << 8 << 9 << 10 << 11 << 12;
    setTotalItem(totalItem);
    initData(dItem,dSql1,dSql2);
    initTableHead();
    setHandleFiled("a.is_bill");

    //setHandleVisible(false);
}

SaSettleRemainQueryForm::SaSettleRemainQueryForm(QString bus_type,QWidget *parent) :
    SingleQueryForm(parent)
{
    QString dSql1 = " SELECT t.* FROM sa_con_settle_remain(?, ?, ?, ?, ?, ?) "
            " t(cus_code varchar, cus_name varchar, product_code varchar, product_name varchar, "
            " sumQuantity numeric, sumMoney numeric, "
            " settleSumQuantity numeric, settleSumMoney numeric, settleSumAmount numeric,"
            " startSumQuantity numeric, startSumMoney numeric, "
            " startSettleSumQuantity numeric, startSettleSumMoney numeric, "
            " endSumQuantity numeric, endSumMoney numeric )";
    QString dSql2 = "";
    childItemProperties childItem[] = {
            { "cus_code","客户编码","客户编码", 0,80, false, false },
            { "cus_name","客户名称","客户名称", 1, 120,true, true },
            { "product_code","编码","商品", 2,80, true, true },
            { "product_name","名称","商品", 3,100, true, true },
            { "startSumQuantity","数量","上期结余", 4, 80,true, true },
            { "startSumMoney","金额","上期结余", 5, 80,true, true },
            { "sumQuantity","数量","本期出库", 6, 80,true, true },
            { "sumMoney","金额","本期出库", 7, 80,true, true },
            { "settleSumQuantity","数量","本期结算", 8, 80,true, true },
            { "settleSumMoney","金额","本期结算", 9,80, true, true },
            { "settleSumAmount","实际金额","本期结算", 10,80, true, true },
            { "endSumQuantity","数量","本期结余", 11,80, true, false },
            { "endSumMoney","金额","本期结余", 12,80, true, false }

    };
    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }
    QDate oneDate = QDate(QDate::currentDate().year(),QDate::currentDate().month(),1);
    sDateEdit1->setDate(oneDate);
    QList<CustomerBean *> venBeanList = CustomerDAO::queryCus();
    QStringList venList ;
    for(int i =0 ; i < venBeanList.size(); i++){
        venList << venBeanList.at(i)->cusCode() + " - " +venBeanList.at(i)->cusName();
    }
    dwNameQks->setListModel(true);
    dwNameQks->setItems(venList);

    QList<CustomerTypeBean *> typeBeanList = CustomerTypeDAO::queryType();
    QStringList typeList ;
    for(int i =0 ; i < typeBeanList.size(); i++){
        typeList << typeBeanList.at(i)->typeId() + " - " +typeBeanList.at(i)->typeName();
    }
    dwTypeQks->setListModel(true);
    dwTypeQks->setItems(typeList);

    noEdit->setVisible(false);
    idLabel->setVisible(false);

    Label->setText("是否结算:");
    rBnt2->setText("未结算");
    rBnt3->setText("已结算");
    Label->setVisible(false);
    rBnt1->setVisible(false);
    rBnt2->setVisible(false);
    rBnt3->setVisible(false);
    QString formId = HaoKeApp::saSubId() + SaPlugin::settleRemainQueryWinId();
    QString winTitle = "委托代销结算余额表";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::saSubId().toInt(),formId.toInt(),0,"");

    setFormId(formId);
    setTabDetailText("委托代销结算余额表");
    //设置明细合计列号
    QList<int > totalItem;
    totalItem << 6 << 7 << 8 << 9 << 10 << 11 << 12;
    setTotalItem(totalItem);
    initData(dItem,dSql1,dSql2);
    initTableHead();
    setHandleFiled("a.is_bill");

    //setHandleVisible(false);
}


