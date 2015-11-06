#include "sardqueryform.h"
#include "bean/CustomerBean.h"
#include "bean/CustomerTypeBean.h"
#include "dao/customerdao.h"
#include "dao/customertypedao.h"
#include "sardwin.h"
#include "haokeapp.h"
#include "saplugin.h"
SaRdQueryForm::SaRdQueryForm(QWidget *parent) :
    QueryForm(parent)
{QString lSql1 = "select e.*,d.emp_name from (select f.*,c.dep_name from "
            " (select a.*,b.cus_name from rd_record a "
            " left join ba_customer b on a.cus_code=b.cus_code "
            " WHERE a.bus_date>=? AND a.bus_date<=? AND b.cus_type like ? AND a.cus_code like ?"
            " AND ( a.vouch_type='02' OR a.vouch_type='15' OR a.vouch_type='11' OR a.vouch_type='12')) f "
            " left join ba_department c on f.dep_code=c.dep_id) e left join ba_employee d on e.person_code=d.emp_code ORDER BY e.bus_date,e.rd_no ASC";
    QString lSql2 = "select e.*,d.emp_name from (select f.*,c.dep_name from "
            " (select a.*,b.cus_name from rd_record a "
            " left join ba_customer b on a.cus_code=b.cus_code "
            " WHERE a.rd_no like ? AND ( a.vouch_type='02' OR a.vouch_type='15' OR a.vouch_type='11' OR a.vouch_type='12' )) f"
            " left join ba_department c on f.dep_code=c.dep_id) e left join ba_employee d on e.person_code=d.emp_code ";

    childItemProperties listItem[] = {
            { "rd_no","单号","单号", 0,100, true, true },
            { "bus_date","出库日期","出库日期", 1,80, true, true },
            { "bus_type","销售类型","销售类型", 2,80, true, false },
            { "cus_code","编码","客户", 3,80, true, false },
            { "cus_name","名称","客户", 4, 120,true, true },
            { "bus_no","发货单号","发货单号", 5,80, true, false },
            { "dep_name","部门","部门", 6,80, true, false },
            { "emp_name","业务员","业务员", 7,60, true, false },
            { "handler","审核","审核", 8,60, true, false },
            { "audit_time","审核时间","审核时间", 9,100, true, false },
            { "creater","制单","制单", 10,60, true, false },
            { "memo","备注","备注", 11,180, true, false },

    };
    QString dSql1 = "SELECT f.*,j.dep_name,h.emp_name FROM ("
            " SELECT a.id, a.rd_no, a.bus_date, a.bus_type, a.cus_code, b.cus_name, a.wh_code, g.wh_name, a.dep_code,c.product_code,"
                       " d.product_name, c.product_style, c.unit, a.person_code, a.handler, a.audit_time, a.creater, a.created,"
                       " a.status, a.memo, c.quantity,c.unit_price,c.money "
                       " from rd_record a,rd_records c,ba_product d,ba_customer b, ba_ware_house g  "
                       " WHERE a.bus_date>=? AND a.bus_date<=? AND b.cus_type like ? AND a.cus_code like ? "
                       " AND d.type_id like ? AND c.product_code like ?"
                       " AND a.wh_code=g.wh_code AND a.rd_no=c.rd_no "
                       " AND c.product_code=d.product_code AND a.cus_code= b.cus_code "
                       " AND ( a.vouch_type='02' OR a.vouch_type='15' OR a.vouch_type='11' OR a.vouch_type='12' )) f"
                       " LEFT JOIN ba_department j ON f.dep_code=j.dep_id "
                       " LEFT JOIN ba_employee h ON f.person_code=h.emp_code "
                       " ORDER BY id ASC";
    QString dSql2 = "SELECT f.*,b.cus_name,j.dep_name,h.emp_name FROM ( "
            "SELECT a.id, a.rd_no, a.bus_date, a.bus_type, a.cus_code,a.wh_code, g.wh_name, a.dep_code,c.product_code,"
            " d.product_name, c.product_style, c.unit,  a.person_code, a.handler, a.audit_time, a.creater, a.created,"
            " a.status, a.memo, c.quantity,c.unit_price,c.money "
            " from rd_record a,rd_records c,ba_product d, ba_ware_house g "
            "  WHERE a.rd_no like ? AND a.wh_code=g.wh_code AND a.rd_no=c.rd_no "
            " AND c.product_code=d.product_code "
            " AND ( a.vouch_type='02' OR a.vouch_type='15' OR a.vouch_type='11' OR a.vouch_type='12')) f "
            " left join ba_customer b on f.cus_code= b.cus_code "
            " LEFT JOIN ba_department j ON f.dep_code=j.dep_id "
            " LEFT JOIN ba_employee h ON f.person_code=h.emp_code "
            " ORDER BY id ASC";
    childItemProperties childItem[] = {
            { "rd_no","单号","单号", 0,100, true, true },
            { "bus_date","出库日期","出库日期", 1,80, true, true },
            { "bus_type","销售类型","销售类型", 2,80, true, false },
            { "cus_code","编码","客户", 3,60, true, false },
            { "cus_name","名称","客户", 4, 120,true, true },
            { "wh_name","仓库","仓库",5,80, true, true },
            { "dep_name","部门","部门",6,80, true, true },
            { "emp_name","业务员","业务员",7,80, true, true },
            { "product_code","编码","商品",8,80, true, true },
            { "product_name","名称","商品",9,100, true, true },
            { "product_style","规格","商品",10,80, true, false },
            { "unit","单位","单位", 11,60, true, false },
            { "quantity","数量","数量", 12, 60,true, true },
            { "unit_price","销售单价","销售单价", 13,80, true, true },
            { "money","销售金额","销售金额", 14,80, true, false }

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
    QString formId = HaoKeApp::saSubId() + SaPlugin::rdQueryWinId();
    QString winTitle = "销售出库查询";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::saSubId().toInt(),formId.toInt(),0,"");

    setFormId(formId);
    setTabListText("销售出库列表");
    setTabDetailText("销售出库明细");
    //设置明细合计列号
    QList<int > totalItem;
    totalItem << 12 << 14;
    setTotalItem(totalItem);
    initData(lItem,dItem,lSql1,lSql2,dSql1,dSql2);
    initTableHead();
    //设定是否根据审核状态查询
    setHandleFiled("is_handle");
    connect(this,SIGNAL(tableClicked(QString)),this,SLOT(sTableClicked(QString)));
    //setHandleVisible(false);
}

void SaRdQueryForm::sTableClicked(QString no){
    if(no.length()>1){
        if(!HaoKeApp::getInstance()->gui()->subWinIsOpen(tr("Sales Receipt"))){
            SaRdWin *pWin = new SaRdWin(no,this);
            pWin->setWindowTitle(tr("Sales Receipt"));
            HaoKeApp::getInstance()->gui()->addSubWin(pWin);
            pWin->showMaximized();
        }
    }
}

