#include "stinqueryform.h"
#include "bean/SupplieBean.h"
#include "bean/SupplieTypeBean.h"
#include "dao/suppliedao.h"
#include "dao/supplietypedao.h"
#include "bean/WareHouseBean.h"
#include "dao/waredao.h"
#include "stinwin.h"
#include "haokeapp.h"
#include "stplugin.h"

StInQueryForm::StInQueryForm(QWidget *parent) :
    QueryForm(parent)
{
    QString lSql1 = "select e.*,d.emp_name from (select f.*,c.dep_name from "
            " (select a.* from rd_record a "
            " WHERE a.bus_date>=? AND a.bus_date<=? AND a.wh_code LIKE ? AND a.vouch_type='05' ) f "
            " left join ba_department c on f.dep_code=c.dep_id) e left join ba_employee d on e.person_code=d.emp_code ORDER BY e.bus_date,e.rd_no ASC";
    QString lSql2 = "select e.*,d.emp_name from (select f.*,c.dep_name from "
            " (select a.* from rd_record a "
            " WHERE a.rd_no like ? AND a.vouch_type='05' ) f"
            " left join ba_department c on f.dep_code=c.dep_id) e left join ba_employee d on e.person_code=d.emp_code ";

    childItemProperties listItem[] = {
            { "rd_no","单号","单号", 0,100, true, true },
            { "bus_date","入库日期","入库日期", 1,80, true, true },
            { "bus_type","单据类型","单据类型", 2,80, true, false },
            { "bus_no","到货单号","到货单号", 3,80, true, false },
            { "dep_name","部门","部门", 4,80, true, false },
            { "emp_name","业务员","业务员", 5,60, true, false },
            { "handler","审核","审核", 6,60, true, false },
            { "audit_time","审核时间","审核时间", 7,100, true, false },
            { "creater","制单","制单", 8,60, true, false },
            { "memo","备注","备注", 9,180, true, false }

    };
    QString dSql1 =
            " SELECT a.id, a.rd_no, a.bus_date, a.bus_type, a.supplier_id, a.wh_code, g.wh_name, a.dep_code,c.product_code,"
                       " d.product_name, c.product_style, c.unit, a.person_code, a.handler, a.audit_time, a.creater, a.created,"
                       " a.status, a.memo, c.quantity,c.unit_price,c.money "
                       " from rd_record a,rd_records c,ba_product d, ba_ware_house g  "
                       " WHERE a.bus_date>=? AND a.bus_date<=? AND a.wh_code LIKE ? "
                       " AND d.type_id like ? AND c.product_code like ? "
                       " AND a.wh_code=g.wh_code AND a.rd_no=c.rd_no AND c.product_code=d.product_code AND a.vouch_type='05' "
                       " ORDER BY id ASC";
    QString dSql2 = "select f.* from ( "
            "SELECT a.id, a.rd_no, a.bus_date, a.bus_type, a.supplier_id,a.wh_code, g.wh_name, a.dep_code,c.product_code,"
            " d.product_name, c.product_style, c.unit,  a.person_code, a.handler, a.audit_time, a.creater, a.created,"
            " a.status, a.memo, c.quantity,c.unit_price,c.money "
            " from rd_record a,rd_records c,ba_product d, ba_ware_house g "
            "  WHERE a.rd_no like ? AND a.wh_code=g.wh_code AND a.rd_no=c.rd_no AND c.product_code=d.product_code AND a.vouch_type='05') f "
            "  ORDER BY id ASC";
    childItemProperties childItem[] = {
            { "rd_no","单号","单号", 0,100, true, true },
            { "bus_date","入库日期","入库日期", 1,80, true, true },
            { "bus_type","单据类型","单据类型", 2,80, true, false },
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
    QList<SupplieBean *> venBeanList = SupplieDAO::querySupplie();
    QStringList venList ;
    for(int i =0 ; i < venBeanList.size(); i++){
        venList << venBeanList.at(i)->supplieCode() + " - " +venBeanList.at(i)->supplieName();
    }
    dwNameQks->setListModel(true);
    dwNameQks->setItems(venList);
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


    QString formId = HaoKeApp::stSubId() + StPlugin::otherInQueryWinId();
    QString winTitle = "其他入库查询";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::stSubId().toInt(),formId.toInt(),0,"");

    setFormId(formId);
    setTabListText("其他入库列表");
    setTabDetailText("其他入库明细");
    //设置明细合计列号
    QList<int > totalItem;
    totalItem << 8 << 10;
    setTotalItem(totalItem);
    initData(lItem,dItem,lSql1,lSql2,dSql1,dSql2);
    initTableHead();
    //设定是否根据审核状态查询
    setHandleFiled("is_handle");
    connect(this,SIGNAL(tableClicked(QString)),this,SLOT(sTableClicked(QString)));
    //setHandleVisible(false);
}

void StInQueryForm::sTableClicked(QString no){
    if(no.length()>1){
        if(!HaoKeApp::getInstance()->gui()->subWinIsOpen(tr("Other Receipt"))){
            StInWin *pWin = new StInWin(no,this);
            pWin->setWindowTitle(tr("Other Receipt"));
            HaoKeApp::getInstance()->gui()->addSubWin(pWin);
            pWin->showMaximized();
        }
    }
}

