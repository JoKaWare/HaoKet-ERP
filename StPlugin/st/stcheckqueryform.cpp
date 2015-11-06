#include "stcheckqueryform.h"
#include "bean/WareHouseBean.h"
#include "bean/CheckVouchBean.h"
#include "dao/waredao.h"
#include "stcheckwin.h"
#include "haokeapp.h"
#include "stplugin.h"
StCheckQueryForm::StCheckQueryForm(QWidget *parent) :
    QueryForm(parent)
{
    QString lSql1 = "select f.*,b.wh_name as wh_name from "
                " (select a.*,c.dep_name,d.emp_name "
                " from st_check_vouch a "
                " LEFT JOIN ba_department c ON a.dep_code=c.dep_id "
                " LEFT JOIN ba_employee d ON a.person_code=d.emp_code "
                " WHERE a.bus_date>=? AND a.bus_date<? AND a.wh_code LIKE ? ) f "
                " INNER JOIN ba_ware_house b ON f.wh_code=b.wh_code "
                " ORDER BY f.bus_date,f.no ASC";
    QString lSql2 = "select f.*,b.wh_name as wh_name from "
            " (select a.*,c.dep_name,d.emp_name "
            " from st_check_vouch a "
            " LEFT JOIN ba_department c ON a.dep_code=c.dep_id "
            " LEFT JOIN ba_employee d ON a.person_code=d.emp_code "
            " WHERE a.no LIKE ? ) f "
            " INNER JOIN ba_ware_house b ON f.wh_code=b.wh_code "
            " ORDER BY f.bus_date,f.no ASC ";

    childItemProperties listItem[] = {
            { "no","单号","单号", 0,100, true, true },
            { "bus_date","盘库日期","盘库日期", 1,80, true, true },
            { "sa_type","单据类型","单据类型", 2,80, true, false },
            { "wh_name","仓库","仓库", 3,80, true, false },
            { "dep_name","部门","部门", 4,80, true, false },
            { "emp_name","业务员","业务员", 5,60, true, false },
            { "handler","审核","审核", 6,60, true, false },
            { "audit_time","审核时间","审核时间", 7,100, true, false },
            { "creater","制单","制单", 8,60, true, false },
            { "memo","备注","备注", 9,180, true, false },

    };
    QString dSql1 =
            "select f.*,b.wh_name as wh_name,p.product_name from "
                " (select a.*,c.dep_name,d.emp_name,e.product_code,e.product_style,e.unit,  e.quantity,e.price,e.money "
                " from st_check_vouch a "
                " LEFT JOIN ba_department c ON a.dep_code=c.dep_id "
                " LEFT JOIN ba_employee d ON a.person_code=d.emp_code "
                " INNER JOIN st_check_vouchs e  ON a.no=e.check_no "
                " WHERE a.bus_date>=? AND a.bus_date<? AND a.wh_code LIKE ? ) f "
                " INNER JOIN ba_ware_house b ON f.wh_code=b.wh_code "
                " INNER JOIN ba_product p ON f.product_code=p.product_code "
                " WHERE p.type_id LIKE ? AND f.product_code LIKE ? "
                " ORDER BY f.bus_date,f.no ASC ";

    QString dSql2 = "select f.*,b.wh_name as wh_name,p.product_name from "
            " (select a.*,c.dep_name,d.emp_name,e.product_code,e.product_style,e.unit,  e.quantity,e.price,e.money "
            " from st_check_vouch a "
            " LEFT JOIN ba_department c ON a.dep_code=c.dep_id "
            " LEFT JOIN ba_employee d ON a.person_code=d.emp_code "
            " INNER JOIN st_check_vouchs e  ON a.no=e.check_no "
            " WHERE a.no LIKE ?  ) f "
            " INNER JOIN ba_ware_house b ON f.wh_code=b.wh_code "
            " INNER JOIN ba_product p ON f.product_code=p.product_code "
            " ORDER BY f.bus_date,f.no ASC ";
    childItemProperties childItem[] = {
            { "no","单号","单号", 0,100, true, true },
            { "bus_date","出库日期","出库日期", 1,80, true, true },
            { "sa_type","单据类型","单据类型", 2,80, true, false },
            { "wh_name","仓库","仓库",3,80, true, true },
            { "product_code","编码","商品",4,80, true, true },
            { "product_name","名称","商品",5,100, true, true },
            { "product_style","规格","商品",6,80, true, false },
            { "unit","单位","单位", 7,60, true, false },
            { "quantity","数量","数量", 8, 60,true, true },
            { "unit_price","单价","单价", 9,80, true, true },
            { "money","金额","金额", 10,80, true, false }

    };
    QList<struct childItemProperties > lItem;
    int size = sizeof(listItem) / sizeof(listItem[0]);
    for(int i = 0 ; i < size ; i++){
        lItem << listItem[i];
    }
    QList<struct childItemProperties > dItem;
    size = sizeof(childItem) / sizeof(childItem[0]);
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

    QList<CustomerTypeBean *> typeBeanList = CustomerTypeDAO::queryType();
    QStringList typeList ;
    for(int i =0 ; i < typeBeanList.size(); i++){
        typeList << typeBeanList.at(i)->typeId() + " - " +typeBeanList.at(i)->typeName();
    }
    dwTypeQks->setListModel(true);
    dwTypeQks->setItems(typeList);
    */
    dwNameQks->setVisible(false);
    dwNameLabel->setVisible(false);
    QList<WareHouseBean *> beanList = WareDAO::queryWarehouse();
    QStringList typeList ;
    for(int i =0 ; i < beanList.size(); i++){
        typeList << beanList.at(i)->whCode() + " - " +beanList.at(i)->whName();
    }
    dwTypeQks->setListModel(true);
    dwTypeQks->setItems(typeList);
    dwTypeLabel->setText("仓    库");
    QString formId = HaoKeApp::stSubId() + StPlugin::checkQueryWinId();
    QString winTitle = "盘点查询";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::stSubId().toInt(),formId.toInt(),0,"");

    setFormId(formId);
    setTabListText("盘点单列表");
    setTabDetailText("盘点明细");
    //设置明细合计列号
    QList<int > totalItem;
    totalItem << 8 << 10;
    setTotalItem(totalItem);
    initData(lItem,dItem,lSql1,lSql2,dSql1,dSql2);
    initTableHead();
    //设定是否根据审核状态查询
    setHandleFiled("is_handle");
    connect(this,SIGNAL(tableClicked(QString)),this,SLOT(sTableClicked(QString)));
}

void StCheckQueryForm::sTableClicked(QString no){
    if(no.length()>1){
        if(!HaoKeApp::getInstance()->gui()->subWinIsOpen(tr("Check Invoice"))){
            StCheckWin *pWin = new StCheckWin(no,this);
            pWin->setWindowTitle(tr("Check Invoice"));
            HaoKeApp::getInstance()->gui()->addSubWin(pWin);
            pWin->showMaximized();
        }
    }
}
