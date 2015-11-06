#include "pusettlequeryform.h"
#include "bean/SupplieBean.h"
#include "bean/SupplieTypeBean.h"
#include "dao/suppliedao.h"
#include "dao/supplietypedao.h"
#include "pusettlewin.h"
#include "haokeapp.h"
#include "cgplugin.h"
PuSettleQueryForm::PuSettleQueryForm(QWidget *parent) :
    QueryForm(parent)
{
    QString lSql1 = "select e.*,d.emp_name from (select f.*,c.dep_name from "
            " (select a.*,b.supplie_name from pu_settle_vouch a "
            " left join ba_suppliers b on a.supplier_id=b.supplie_code "
            " WHERE a.settle_date>=? AND a.settle_date<=? AND b.supplie_type like ? AND a.supplier_id like ? ) f "
            " left join ba_department c on f.dep_code=c.dep_id) e left join ba_employee d on e.person_code=d.emp_code ORDER BY e.settle_date,e.no ASC";
    QString lSql2 = "select e.*,d.emp_name from (select f.*,c.dep_name from "
            " (select a.*,b.supplie_name from pu_settle_vouch a "
            " left join ba_suppliers b on a.supplier_id=b.supplie_code "
            " WHERE a.no like ? ) f"
            " left join ba_department c on f.dep_code=c.dep_id) e left join ba_employee d on e.person_code=d.emp_code ";

    childItemProperties listItem[] = {
            { "no","���㵥��","���㵥��", 0,100, true, true },
            { "settle_date","��������","��������", 1,80, true, true },
            { "settle_type","��������","��������", 2,80, true, false },
            { "rd_no","��ⵥ��","��ⵥ��", 3,100, true, false },
            { "supplier_id","����","��Ӧ��", 4,80, true, false },
            { "supplie_name","����","��Ӧ��", 5, 120,true, true },
            { "dep_name","����","����", 6,80, true, false },
            { "emp_name","ҵ��Ա","ҵ��Ա", 7,60, true, false },
            { "handler","���","���", 8,60, true, false },
            { "audit_time","���ʱ��","���ʱ��", 9,120, true, false },
            { "creater","�Ƶ�","�Ƶ�", 10,60, true, false },
            { "memo","��ע","��ע", 11,180, true, false }

    };
    QString dSql1 =
            " SELECT a.id, a.no, a.settle_date,  a.settle_type, a.supplier_id, b.supplie_name,a.dep_code,c.rd_no,c.product_code,"
                       " d.product_name, c.product_style, c.unit, a.person_code, a.handler, a.audit_time, a.creater, a.created,"
                       " a.updater, a.updated, a.status, a.memo, c.quantity,c.price,c.s_price,c.amount "
                       " from pu_settle_vouch a,pu_settle_vouchs c,ba_product d,ba_suppliers b "
                       " WHERE a.settle_date>=? AND a.settle_date<=? AND b.supplie_type like ? AND a.supplier_id like ? "
                       " AND d.type_id like ? AND c.product_code like ?"
                       " AND a.no=c.settle_no AND c.product_code=d.product_code AND a.supplier_id= b.supplie_code "
                       " ORDER BY id ASC";
    QString dSql2 = "select f.*,b.supplie_name from ( "
            "SELECT a.id, a.no, a.settle_date, a.settle_type, a.supplier_id,a.dep_code,c.rd_no,c.product_code,"
            " d.product_name, c.product_style, c.unit, a.person_code, a.handler, a.audit_time, a.creater, a.created,"
            " a.updater, a.updated, a.status, a.memo, c.quantity,c.price,c.s_price,c.amount "
            " from pu_settle_vouch a,pu_settle_vouchs c,ba_product d"
            "  WHERE a.no like ?  AND a.no=c.settle_no AND c.product_code=d.product_code) f "
            " left join ba_suppliers b on f.supplier_id= b.supplie_code ORDER BY id ASC";
    childItemProperties childItem[] = {
            { "no","���㵥��","���㵥��", 0,100, true, true },
            { "settle_date","��������","��������", 1,80, true, true },
            { "settle_type","��������","��������", 2,80, true, false },
            { "supplier_id","����","��Ӧ��", 3,60, true, false },
            { "supplie_name","����","��Ӧ��", 4, 120,true, true },
            { "rd_no","��ⵥ��","��ⵥ��", 5,100, true, true },
            { "product_code","����","��Ʒ", 6,80, true, true },
            { "product_name","����","��Ʒ", 7,100, true, true },
            { "product_style","���","��Ʒ",8,80, true, false },
            { "unit","�ɹ���λ","�ɹ���λ", 9,60, true, false },
            { "quantity","��������","��������", 10, 60,true, true },
            { "price","ԭ����","ԭ����", 11,80, true, true },
            { "s_price","���㵥��","���㵥��", 12,80, true, true },
            { "amount","������","������", 13,80, true, false }

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
    QString formId = HaoKeApp::puSubId() + CgPlugin::settleQueryWinId();
    QString winTitle = "�ɹ����㵥��ѯ";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::puSubId().toInt(),formId.toInt(),0,"");

    setFormId(formId);
    setTabListText("���㵥�б�");
    setTabDetailText("������ϸ");
    //������ϸ�ϼ��к�
    QList<int > totalItem;
    totalItem << 10 << 13;
    setTotalItem(totalItem);
    initData(lItem,dItem,lSql1,lSql2,dSql1,dSql2);
    initTableHead();
    //�趨�Ƿ�������״̬��ѯ
    setHandleFiled("is_handle");
    connect(this,SIGNAL(tableClicked(QString)),this,SLOT(sTableClicked(QString)));
    //setHandleVisible(false);
}

void PuSettleQueryForm::sTableClicked(QString no){
    if(no.length()>1){
        if(!HaoKeApp::getInstance()->gui()->subWinIsOpen(tr("Purchase Settle"))){
            PuSettleWin *pWin = new PuSettleWin(no,this);
            pWin->setWindowTitle(tr("Purchase Settle"));
            HaoKeApp::getInstance()->gui()->addSubWin(pWin);
            pWin->showMaximized();
        }
    }
}