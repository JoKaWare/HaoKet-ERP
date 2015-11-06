#include "imeiquery.h"
#include "bean/SupplieBean.h"
#include "bean/SupplieTypeBean.h"
#include "bean/CustomerBean.h"
#include "dao/suppliedao.h"
#include "dao/supplietypedao.h"
#include "dao/customerdao.h"
#include "bc/rdinimeiwin.h"
#include "haokeapp.h"
#include "bcplugin.h"
ImeiQuery::ImeiQuery(QWidget *parent) :
    SingleQueryForm(parent)
{
    QString dSql1 = " SELECT t.* FROM bc_imei_query(?, ?, ?, ? ) "
            " t(no varchar, imei varchar, vouchs_id numeric,wh_code varchar, vouch_type varchar,"
            " product_code varchar, bus_date date, created timestamp, creater varchar, memo varchar,"
            " bus_name varchar, wh_name varchar, product_name varchar, vouch_name varchar)";
    QString dSql2 = " SELECT t.* FROM bc_imei_query_by(? ) "
            " t(no varchar, imei varchar, vouchs_id numeric,wh_code varchar, vouch_type varchar,"
            " product_code varchar, bus_date date, created timestamp, creater varchar, memo varchar,"
            " bus_name varchar, wh_name varchar, product_name varchar, vouch_name varchar)";

    childItemProperties childItem[] = {
            { "no","单号","单号", 0,100, true, false },
            { "imei","IMEI","IMEI", 1,120, true, true },
            { "vouch_name","单据类型","单据类型", 2, 80,true, true },
            { "bus_name","单位名称/调入仓库","单位名称/调入仓库", 3, 160,true, true },
            { "product_code","商品编码","商品编码", 4,80, true, true },
            { "product_name","商品名称","商品名称", 5,80, true, true },
            { "wh_name","仓库","仓库", 6,100, true, true },
            { "bus_date","日期","日期", 7,100, true, true },
            { "memo","备注","备注",8,180, true, false }
    };

    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }

    QList<SupplieBean *> venBeanList = SupplieDAO::querySupplie();
    QStringList venList ;
    for(int i =0 ; i < venBeanList.size(); i++){
        venList << venBeanList.at(i)->supplieCode() + " - " +venBeanList.at(i)->supplieName();
    }
    dwTypeQks->setListModel(true);
    dwTypeQks->setItems(venList);
    dwTypeLabel->setText("供 应 商:");
    dwNameQks->setVisible(false);
    dwNameLabel->setVisible(false);
    dwTypeQks->setVisible(false);
    dwTypeLabel->setVisible(false);
    Label->setVisible(false);
    //idLabel->setVisible(false);
    //noEdit->setVisible(false);
    idLabel->setText("串    码:");
    Label->setVisible(false);
    rBnt1->setVisible(false);
    rBnt2->setVisible(false);
    rBnt3->setVisible(false);
    //verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);
    //gridLayout->addItem(verticalSpacer_2, 5, 1, 1, 1);
    QString formId = HaoKeApp::bcSubId() + BcPlugin::rdInImeiQueryWinId();
    setFormId(formId);
    setTabDetailText("入库串码");

    initData(dItem,dSql1,dSql2);
    initTableHead();
    connect(this,SIGNAL(tableClicked(QString)),this,SLOT(sTableClicked(QString)));
}

void ImeiQuery::sTableClicked(QString no){
    if(no.length()>1){

    }
}
