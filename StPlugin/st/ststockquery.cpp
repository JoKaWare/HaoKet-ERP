#include "ststockquery.h"
#include "bean/SupplieBean.h"
#include "bean/SupplieTypeBean.h"
#include "dao/suppliedao.h"
#include "dao/supplietypedao.h"
#include "bean/WareHouseBean.h"
#include "dao/waredao.h"
#include "stinwin.h"
#include "haokeapp.h"
#include "stplugin.h"

StStockQuery::StStockQuery(QWidget *parent) :
    SingleQueryForm(parent)
{
    QString dSql1 = " SELECT b.wh_name,a.*,a.sum-a.c_sum+a.r_sum as k_sum,c.style FROM"
            " st_stock_query a, ba_ware_house b , ba_product c"
            " WHERE a.wh_code=b.wh_code AND a.product_code=c.product_code "
            " AND a.wh_code LIKE ? AND c.type_id LIKE ? AND a.product_code LIKE ?";
    QString dSql2 = "";
    childItemProperties childItem[] = {
            { "wh_code","编码","仓库", 0,80, true, true },
            { "wh_name","名称","仓库", 1,80, true, true },
            { "product_code","编码","商品", 2,80, true, true },
            { "product_name","名称","商品", 3,100, true, true },
            { "style","规格","商品",4,80, true, false },
            { "unit","单位","商品", 5,80, true, false },
            { "sum","现存量","现存量", 6, 80,true, true },
            { "r_sum","待入库","待入库", 7, 80,true, true },
            { "c_sum","待出库","待出库", 8, 80,true, true },
            { "k_sum","可发量","可发量", 9,80, true, true }
    };

    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }
    /*
    QList<CustomerBean *> venBeanList = CustomerDAO::queryCus();
    QStringList venList ;
    for(int i =0 ; i < venBeanList.size(); i++){
        venList << venBeanList.at(i)->cusCode() + " - " +venBeanList.at(i)->cusName();
    }
    dwNameQks->setListModel(true);
    dwNameQks->setItems(venList);
    */
    dwNameQks->setVisible(false);
    dwNameLabel->setVisible(false);
    eDateEdit->setVisible(false);
    sDateEdit1->setVisible(false);
    endLabel->setVisible(false);
    startLabel->setVisible(false);
    noEdit->setVisible(false);
    Label->setVisible(false);
    idLabel->setVisible(false);
    QList<WareHouseBean *> beanList = WareDAO::queryWarehouse();
    QStringList typeList ;
    for(int i =0 ; i < beanList.size(); i++){
        typeList << beanList.at(i)->whCode() + " - " +beanList.at(i)->whName();
    }
    dwTypeQks->setListModel(true);
    dwTypeQks->setItems(typeList);
    dwTypeLabel->setText("仓    库");

    Label->setVisible(false);
    rBnt1->setVisible(false);
    rBnt2->setVisible(false);
    rBnt3->setVisible(false);
    QString formId = HaoKeApp::stSubId() + StPlugin::stockQueryWinId();
    QString winTitle = "库存查询";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::saSubId().toInt(),formId.toInt(),0,"");

    setFormId(formId);
    setTabDetailText("库存查询");
    //设置明细合计列号
    QList<int > totalItem;
    totalItem << 6 << 7 << 8 << 9;
    setTotalItem(totalItem);
    initData(dItem,dSql1,dSql2);
    initTableHead();


    connect(this,SIGNAL(tableClicked(QString)),this,SLOT(sTableClicked(QString)));
}
