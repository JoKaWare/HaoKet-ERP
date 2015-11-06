#include "sasettlequeryform.h"
#include "bean/CustomerBean.h"
#include "bean/CustomerTypeBean.h"
#include "dao/customerdao.h"
#include "dao/customertypedao.h"
#include "sasettlewin.h"
#include "haokeapp.h"
#include "saplugin.h"

SaSettleQueryForm::SaSettleQueryForm(QWidget *parent) :
    QueryForm(parent)
{
    QString lSql1 = "select e.*,d.emp_name from (select f.*,c.dep_name from "
            " (select a.*,b.cus_name from sa_settle_vouch a "
            " left join ba_customer b on a.cus_code=b.cus_code "
            " WHERE a.bus_type='01' AND a.settle_date>=? AND a.settle_date<=? AND b.cus_type like ? AND a.cus_code like ? ) f "
            " left join ba_department c on f.dep_code=c.dep_id) e left join ba_employee d on e.person_code=d.emp_code ORDER BY e.settle_date,e.no ASC";
    QString lSql2 = "select e.*,d.emp_name from (select f.*,c.dep_name from "
            " (select a.*,b.cus_name from sa_settle_vouch a "
            " left join ba_customer b on a.cus_code=b.cus_code "
            " WHERE a.no like ? AND a.bus_type='01' ) f"
            " left join ba_department c on f.dep_code=c.dep_id) e left join ba_employee d on e.person_code=d.emp_code ";

    childItemProperties listItem[] = {
            { "no","结算单号","结算单号", 0,100, true, true },
            { "settle_date","结算日期","结算日期", 1,80, true, true },
            { "settle_type","结算类型","结算类型", 2,80, true, false },
            { "rd_no","出库单号","出库单号", 3,100, true, false },
            { "cus_code","编码","客户", 4,80, true, false },
            { "cus_name","名称","客户", 5, 120,true, true },
            { "dep_name","部门","部门", 6,80, true, false },
            { "emp_name","业务员","业务员", 7,60, true, false },
            { "handler","审核","审核", 8,60, true, false },
            { "audit_time","审核时间","审核时间", 9,120, true, false },
            { "creater","制单","制单", 10,60, true, false },
            { "memo","备注","备注", 11,180, true, false }

    };
    QString dSql1 =
            " SELECT a.id, a.no, a.settle_date,  a.settle_type, a.cus_code, b.cus_name,a.dep_code,c.rd_no,c.product_code,"
                       " d.product_name, c.product_style, c.unit, a.person_code, a.handler, a.audit_time, a.creater, a.created,"
                       " a.updater, a.updated, a.status, a.memo, c.quantity,c.price,c.s_price,c.amount "
                       " from sa_settle_vouch a,sa_settle_vouchs c,ba_product d,ba_customer b "
                       " WHERE a.bus_type='01' AND a.settle_date>=? AND a.settle_date<=? AND b.cus_type like ? AND a.cus_code like ? "
                       " AND d.type_id like ? AND c.product_code like ?"
                       " AND a.no=c.settle_no AND c.product_code=d.product_code AND a.cus_code= b.cus_code "
                       " ORDER BY id ASC";
    QString dSql2 = "select f.*,b.cus_name from ( "
            "SELECT a.id, a.no, a.settle_date, a.settle_type, a.cus_code,a.dep_code,c.rd_no,c.product_code,"
            " d.product_name, c.product_style, c.unit, a.person_code, a.handler, a.audit_time, a.creater, a.created,"
            " a.updater, a.updated, a.status, a.memo, c.quantity,c.price,c.s_price,c.amount "
            " from sa_settle_vouch a,sa_settle_vouchs c,ba_product d"
            "  WHERE a.bus_type='01' AND a.no like ?  AND a.no=c.settle_no AND c.product_code=d.product_code) f "
            " left join ba_customer b on f.cus_code= b.cus_code ORDER BY id ASC";
    childItemProperties childItem[] = {
            { "no","结算单号","结算单号", 0,100, true, true },
            { "settle_date","结算日期","结算日期", 1,80, true, true },
            { "settle_type","结算类型","结算类型", 2,80, true, false },
            { "cus_code","编码","客户", 3,60, true, false },
            { "cus_name","名称","客户", 4, 120,true, true },
            { "rd_no","出库单号","出库单号", 5,100, true, true },
            { "product_code","编码","商品", 6,80, true, true },
            { "product_name","名称","商品", 7,100, true, true },
            { "product_style","规格","商品",8,80, true, false },
            { "unit","单位","单位", 9,60, true, false },
            { "quantity","结算数量","结算数量", 10, 60,true, true },
            { "price","原单价","原单价", 11,80, true, true },
            { "s_price","结算单价","结算单价", 12,80, true, true },
            { "amount","结算金额","结算金额", 13,80, true, false }

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
    QString formId = HaoKeApp::saSubId() + SaPlugin::settleQueryWinId();
    QString winTitle = "销售结算单查询";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::saSubId().toInt(),formId.toInt(),0,"");

    setFormId(formId);
    setTabListText("结算单列表");
    setTabDetailText("结算明细");
    //设置明细合计列号
    QList<int > totalItem;
    totalItem << 10 << 13;
    setTotalItem(totalItem);
    initData(lItem,dItem,lSql1,lSql2,dSql1,dSql2);
    initTableHead();
    //设定是否根据审核状态查询
    setHandleFiled("is_handle");
    connect(this,SIGNAL(tableClicked(QString)),this,SLOT(sTableClicked(QString)));
    //setHandleVisible(false);
}

void SaSettleQueryForm::sTableClicked(QString no){
    if(no.length()>1){
        if(!HaoKeApp::getInstance()->gui()->subWinIsOpen(tr("Sales Settle"))){
            SaSettleWin *pWin = new SaSettleWin(no,this);
            pWin->setWindowTitle(tr("Sales Settle"));
            HaoKeApp::getInstance()->gui()->addSubWin(pWin);
            pWin->showMaximized();
        }
    }
}
