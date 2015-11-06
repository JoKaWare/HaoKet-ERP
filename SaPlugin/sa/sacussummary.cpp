#include "sacussummary.h"
#include "bean/CustomerBean.h"
#include "bean/CustomerTypeBean.h"
#include "dao/customerdao.h"
#include "dao/customertypedao.h"
#include "sardwin.h"
#include "haokeapp.h"
#include "saplugin.h"
SaCusSummary::SaCusSummary(QWidget *parent) :
    SingleQueryForm(parent)
{
    QString dSql1 =
            " SELECT g.*, h.product_name, h.style, s.cus_name "
            " FROM ( "
               " SELECT a.cus_code, b.product_code,sum(b.quantity) as sumQ,sum(money) as sumMoeny "
                   " FROM rd_record a "
                   " INNER JOIN rd_records b "
                   " ON a.rd_no=b.rd_no "
                   " WHERE a.bus_date>=? AND a.bus_date<=? "
                   " AND a.rd_flag=2 AND (a.vouch_type='02' OR a.vouch_type='15' "
                   " OR a.vouch_type='11' OR a.vouch_type='12' ) "
                   " GROUP BY a.cus_code, b.product_code "
            ") g "
            " INNER JOIN ba_product h "
            " ON g.product_code = h.product_code "
            " INNER JOIN ba_customer s "
            " ON g.cus_code=s.cus_code"
            " WHERE s.cus_type LIKE ? AND s.cus_code LIKE ? "
            " AND h.type_id LIKE ? AND g.product_code LIKE ? "
            " ORDER BY g.cus_code,g.product_code ";
    QString dSql2 = "";
    childItemProperties childItem[] = {
            { "cus_code","编码","客户", 0,80, true, true },
            { "cus_name","名称","客户", 1,180, true, true },
            { "product_code","编码","商品", 2,80, true, true },
            { "product_name","名称","商品", 3,100, true, true },
            { "style","规格","商品",4,80, true, false },
            { "sumQ","数量","数量", 5,60, true, true },
            { "sumMoeny","金额","金额", 6,80, true, false }


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

    Label->setVisible(false);
    rBnt1->setVisible(false);
    rBnt2->setVisible(false);
    rBnt3->setVisible(false);
    QString formId = HaoKeApp::saSubId() + SaPlugin::cusSummaryWinId();
    QString winTitle = "销售发货汇总表";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::saSubId().toInt(),formId.toInt(),0,"");

    setFormId(formId);
    setTabDetailText("销售发货汇总表");
    //设置明细合计列号
    QList<int > totalItem;
    totalItem << 5 << 6 ;
    setTotalItem(totalItem);
    initData(dItem,dSql1,dSql2);
    initTableHead();

}
