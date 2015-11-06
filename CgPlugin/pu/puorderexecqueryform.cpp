#include "puorderexecqueryform.h"
#include "bean/SupplieBean.h"
#include "bean/SupplieTypeBean.h"
#include "dao/suppliedao.h"
#include "dao/supplietypedao.h"
#include "puorderwin.h"
#include "haokeapp.h"
#include "cgplugin.h"

PuOrderExecQueryForm::PuOrderExecQueryForm(QWidget *parent) :
    SingleQueryForm(parent)
{

    QString dSql1 =
            " SELECT a.no, a.bus_date, a.bus_type, b.supplie_name,c.product_code,d.product_name,c.product_style, c.unit,"
            " c.quantity, c.in_quantity, (c.quantity-c.in_quantity) as real_quantity, c.re_quantity,c.is_complete,c.price,c.money,a.demand_date,a.project_date"
            " FROM pu_order_vouch a,pu_order_vouchs c,ba_product d,ba_suppliers b "
                       " WHERE a.bus_date>=? AND a.bus_date<=? AND b.supplie_type like ? AND a.supplier_id like ? "
                       " AND d.type_id like ? AND c.product_code like ?"
                       " AND a.no=c.order_no AND c.product_code=d.product_code AND a.supplier_id= b.supplie_code "
                       " ORDER BY no ASC";
    QString dSql2 = "select f.*,b.supplie_name from ( "
            "SELECT a.no, a.bus_date, a.bus_type, a.supplier_id,a.wh_code,a.dep_code,a.demand_date,c.product_code,"
            " d.product_name, c.product_style, c.unit,  a.project_date, a.person_code, a.handler, a.audit_time, a.creater, a.created,"
            " a.closer, a.updater, a.updated, a.status, a.memo, c.quantity, c.in_quantity, (c.quantity-c.in_quantity) as real_quantity, c.re_quantity, c.is_complete, c.price,c.money "
            " from pu_order_vouch a,pu_order_vouchs c,ba_product d"
            "  WHERE a.no like ? AND a.no=c.order_no AND c.product_code=d.product_code) f "
            " left join ba_suppliers b on f.supplier_id= b.supplie_code ORDER BY no ASC";
    childItemProperties childItem[] = {
            { "no","单号","单号", 0,100, true, true },
            { "bus_date","订单日期","订单日期", 1,80, true, true },
            { "bus_type","订单类型","订单类型", 2,80, true, false },
            { "supplie_name","供应商","供应商", 3, 160,true, true },
            { "product_code","编码","商品", 4,80, true, true },
            { "product_name","名称","商品", 5,100, true, true },
            { "product_style","规格","商品",6,80, true, false },
            { "unit","采购单位","采购单位", 7,60, true, false },
            { "quantity","订单数量","订单数量", 8, 80,true, true },
            { "in_quantity","已到货数量","已到货数量", 9, 80,true, true },
            { "real_quantity","未到货数量","未到货数量", 10, 80,true, true },
            { "is_complete","是否执行","是否执行", 11,60, true, true },
            { "price","采购单价","采购单价", 12,60, true, true },
            { "money","采购金额","采购金额", 13,80, true, false },
            { "demand_date","需求日期","需求日期", 14,80, true, false },
            { "project_date","计划到货日期","计划到货日期", 15,80, true, false }


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
    dwNameQks->setListModel(true);
    dwNameQks->setItems(venList);

    QList<SupplieTypeBean *> typeBeanList = SupplieTypeDAO::queryType();
    QStringList typeList ;
    for(int i =0 ; i < typeBeanList.size(); i++){
        typeList << typeBeanList.at(i)->typeId() + " - " +typeBeanList.at(i)->typeName();
    }
    dwTypeQks->setListModel(true);
    dwTypeQks->setItems(typeList);
    Label->setText("是否执行:");
    rBnt2->setText("末执行");
    rBnt3->setText("已执行");
    QString formId = HaoKeApp::puSubId() + CgPlugin::orderExecQueryWinId();
    QString winTitle = "采购订单执行统计表";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::puSubId().toInt(),formId.toInt(),0,"");

    setFormId(formId);
    setTabDetailText("采购订单执行统计表");
    //设置明细合计列号
    QList<int > totalItem;
    totalItem << 8 << 9 << 10 << 13;
    setTotalItem(totalItem);
    initData(dItem,dSql1,dSql2);
    initTableHead();
    //设定是否根据审核状态查询
    setHandleFiled("c.is_complete");

    connect(this,SIGNAL(tableClicked(QString)),this,SLOT(sTableClicked(QString)));
}

void PuOrderExecQueryForm::sTableClicked(QString no){
    if(no.length()>1){
        if(!HaoKeApp::getInstance()->gui()->subWinIsOpen(tr("Purchase Order"))){
            PuOrderWin *pWin = new PuOrderWin(no,this);
            pWin->setWindowTitle(tr("Purchase Order"));
            HaoKeApp::getInstance()->gui()->addSubWin(pWin);
            pWin->showMaximized();
        }
    }
}
