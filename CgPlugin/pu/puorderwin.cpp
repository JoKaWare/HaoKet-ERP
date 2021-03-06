#include "puorderwin.h"
#include "ui_puorderwin.h"
#include "haokeapp.h"
#include "bean/DepBean.h"
#include "bean/SupplieBean.h"
#include "bean/EmployeeBean.h"
#include "bean/WareHouseBean.h"
#include "bean/ProductBean.h"
#include "bean/CustomerBean.h"
#include "bean/CustomerTypeBean.h"
#include "bean/SystemSetBean.h"
#include "bean/DefineBean.h"
#include "../SaPlugin/bean/SaOrderVouchsBean.h"
#include "dao/systemsetdao.h"
#include "dao/commondao.h"
#include "dao/depdao.h"
#include "dao/suppliedao.h"
#include "dao/supplietypedao.h"
#include "dao/customerdao.h"
#include "dao/customertypedao.h"
#include "dao/employeedao.h"
#include "dao/waredao.h"
#include "dao/productdao.h"
#include "dao/orderdao.h"
#include "utils/puitemutil.h"
#include "common/cachebabeancommon.h"
#include "common/printutils.h"
#include "qtrpt.h"
#include "bean/ReportFormatBean.h"
#include "dao/reportdao.h"
#include "widget/designoptdialog.h"
#include "widget/choosevouchdialog.h"
#include "widget/optinvdialog.h"
#include "bean/PuArrivalVouchsBean.h"
#include "dao/arrivaldao.h"
#include "cgplugin.h"

PuOrderWin::PuOrderWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PuOrderWin)
{
    ui->setupUi(this);
    init();
    //qApp->setStyle("Plastique");
    setupContextMenu();
    mCountRecord = OrderDAO::getPuOrderCount() - 1;
    if(mCountRecord < 0) mCountRecord = 0;
    mRecord = mCountRecord;
    QList<PuOrderVouchBean *> vouchBeanList = OrderDAO::queryPuOrderByPage(mCountRecord,1);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->no());
    }
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(false);
    ui->toolBar->actions().at(0)->setEnabled(true);
    ui->toolBar->actions().at(1)->setEnabled(true);
    ui->toolBar->actions().at(7)->setEnabled(true);
    if(ui->noEdit->text().length() >0){
        ui->toolBar->actions().at(2)->setEnabled(true);
    }
    readAuthority();

}

PuOrderWin::PuOrderWin(QString no,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PuOrderWin)
{
    ui->setupUi(this);
    init();
    //qApp->setStyle("Plastique");
    setupContextMenu();
    mCountRecord = OrderDAO::getPuOrderCount() - 1;
    if(mCountRecord < 0) mCountRecord = 0;
    ui->toolBar->actions().at(0)->setEnabled(true);
    ui->toolBar->actions().at(1)->setEnabled(true);
    ui->toolBar->actions().at(7)->setEnabled(true);

    PuOrderVouchBean *bean = OrderDAO::getPuOrderByNo(no);
    if(bean != NULL && bean->no().length() > 0){
        mRecord = OrderDAO::getPuOrderRowNumber(bean->id()) - 1;
        if(mRecord == 0){
            baseToolBar->actions().at(0)->setEnabled(false);
            baseToolBar->actions().at(2)->setEnabled(false);
        }else if(mRecord >= mCountRecord ){
            baseToolBar->actions().at(1)->setEnabled(false);
            baseToolBar->actions().at(3)->setEnabled(false);
        }
        delete bean;
        read(no);
        if(ui->noEdit->text().length() >0){
            ui->toolBar->actions().at(2)->setEnabled(true);
        }
    }else{
        QMessageBox::critical(this,"错误","此单不存在！");
    }
    readAuthority();

}

PuOrderWin::~PuOrderWin()
{
    delete ui;
}

void PuOrderWin::readAuthority(){
    LimitsCommon::authority(ui->toolBar,mWinId.toInt());
}

void PuOrderWin::init(){


    //窗体ID号
    mWinId = HaoKeApp::puSubId() + CgPlugin::orderWinId();
    mWinTitle = "采购订单";
    mIsChoose = false;
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::puSubId().toInt(),mWinId.toInt(),0,"");

    //功能菜单
    actionProperties actsBase[]= {
        { "puOrder.new",tr("&New"),SLOT(sNew()), NULL, "New", QPixmap(":/image/Add.png"), NULL,  true, tr("New") },
        { "puOrder.edit",tr("&Edit"),SLOT(sEdit()), NULL, "Edit", QPixmap(":/image/edit.png"), NULL,  true, tr("Edit") },
        { "puOrder.delete",tr("&Delete"),SLOT(sDelete()), NULL, "Delete", QPixmap(":/image/cross_48.png"), NULL,  true, tr("Delete") },
        { "puOrder.save",tr("&Save"),SLOT(sSave()), NULL, "Save", QPixmap(":/image/save.png"), NULL,  true, tr("Save") },
        { "puOrder.audit",tr("&Audit"),SLOT(sAudit()), NULL, "Audit", QPixmap(":/image/stamp_48.png"), NULL,  true, tr("Audit") },
        { "puOrder.abandonAudit",tr("&Abandon Audit"),SLOT(sAbAudit()), NULL, "Abandon Audit", QPixmap(":/image/c_stamp_48.png"), NULL,  true, tr("Abandon Audit") },
        { "puOrder.delRow",tr("&DelRow"),SLOT(sDelRow()), NULL, "DelRow", QPixmap(":/image/minus.png"), NULL,  true, tr("DelRow") },
        { "puOrder.print",tr("&Print"),SLOT(sPrint()), NULL, "Print", QPixmap(":/image/printer.png"), NULL,  true, tr("Print") },
        { "puOrder.choose",tr("&Choose"),SLOT(sChoose()), NULL, "Choose", QPixmap(":/image/page_accept.png"), NULL,  true, tr("Choose") },
        { "puOrder.first",tr("&First"),SLOT(sFirst()), NULL, "First", QPixmap(":/image/first48.png"), NULL,  true, tr("First") },
        { "puOrder.next",tr("&Next"),SLOT(sNext()), NULL, "Next", QPixmap(":/image/n-next48.png"), NULL,  true, tr("Next") },
        { "puOrder.previous",tr("&Previous"),SLOT(sPrevious()), NULL, "Previous", QPixmap(":/image/n-previous48.png"), NULL,  true, tr("Previous") },
        { "puOrder.end",tr("&End"),SLOT(sEnd()), NULL, "End", QPixmap(":/image/end48.png"), NULL,  true, tr("End") },
        { "puOrder.cancel",tr("&Cancel"),SLOT(sCancel()), NULL, "Cancel", QPixmap(":/image/cancel.png"), NULL,  true, tr("Cancel") }

    };
    addActionsTo(actsBase,sizeof(actsBase) / sizeof(actsBase[0]));

    mIsEdit =false;

    ui->dateEdit->setDate(HaoKeApp::getInstance()->getOperateDate());
    ui->demanddDateEdit->setDate(HaoKeApp::getInstance()->getOperateDate());
    ui->projectDateEdit->setDate(HaoKeApp::getInstance()->getOperateDate());

    //初始化表体格式
    setInputEnable(false);


    childItemProperties childItem[] = {
            { "productCode","商品编码","商品编码", 0,180, true, true },
            { "productName","商品名称","商品名称", 1,180, true, true },
            { "productStyle","商品规格","商品规格", 2,80, true, false },
            { "unit","采购单位","采购单位", 3,80, true, false },
            { "quantity","数量","数量", 4, 60,true, true },
            { "price","采购单价","采购单价", 5,80, true, true },
            { "money","采购金额","采购金额", 6,80, true, false },
            { "id","ID","ID", 7,60, false, false },
            { "originNo","销售订单号","销售订单号", 8, 120,true, false },
            { "define1","自定义1","自定义1", 9,100, false, true },
            { "define2","自定义2","自定义2", 10,100, false, true },
            { "define3","自定义3","自定义3", 11,100, false, true },
            { "define4","自定义4","自定义4", 12,100, false, true },
            { "define5","自定义5","自定义5", 13,100, false, true },
            { "define6","自定义6","自定义6", 14,100, false, true },
            { "memo","备注","备注", 15,160, false, true }
    };

    //mChildItem << childItem[0] << childItem[1] << childItem[2] << childItem[3] << childItem[4] << childItem[5] << childItem[6] << childItem[7];
    int size = sizeof(childItem) / sizeof(childItem[0]);
    //qDebug() << size;
    for(int i =0 ; i < size ; i ++){
        mChildItem << childItem[i];
    }

    //是否使用自定义字段
    SystemSetBean *useDefineBean = SystemSetDAO::getBean("101");
    if(useDefineBean && useDefineBean->id().length() > 0){
        if(useDefineBean->yesNo()){
            QList<DefineBean *> defineList = CommonDAO::queryDefine();
            for(int i =9 ; i < size ; i ++){
                for(int j =0 ; j < defineList.size() ; j ++){
                    if(mChildItem.at(i).name.trimmed() ==   defineList.at(j)->code()){
                        mChildItem[i].cnName = defineList.at(j)->name();
                        mChildItem[i].title = defineList.at(j)->name();
                        mChildItem[i].visible = defineList.at(j)->isView();

                    }
                }
            }
        }
    }

    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(size);
    //初始化表尾
    mFootView = new HierarchicalHeaderView(Qt::Horizontal);
    mFootView->setClickable(true);
    //mFootView->setMovable(false);
    mFootView->setResizeMode(QHeaderView::Fixed);
    mFootView->setHighlightSections(true);
    mFootModel = new FootTableModel(1,mChildItem.size(),this);
    mFootModel->setItem(0,new QStandardItem(""));
    mFootModel->setItem(1,new QStandardItem("合计:"));
    mFootView->setModel(mFootModel);

    mFootView->resizeSection(0,ui->tableWidget->verticalHeader()->width());
    mFootView->setFixedHeight(22);

    ui->verticalLayout_2->addWidget(mFootView);
    mFootModel->setItem(size - 1,new QStandardItem(""));
    QObject::connect(ui->tableWidget->horizontalHeader(),SIGNAL(sectionResized(int,int,int)),this,SLOT(footResized(int,int,int)));
    refreshData();
    /*
    ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    */
    mFootView->setDefaultAlignment (Qt::AlignLeft | Qt::AlignVCenter);
    mFootView->setTextElideMode (Qt::ElideLeft); //...效果


    //初始化表头数据
    QStringList  busTypeList;
    busTypeList << "普通采购";
    busTypeList << "计划采购" << "合同采购" <<"受托入库采购";
    ui->busTypeComboBox->addItems(busTypeList);
    QList<SupplieBean *> venBeanList = SupplieDAO::querySupplie();
    QStringList venList ;
    for(int i =0 ; i < venBeanList.size(); i++){
        venList << venBeanList.at(i)->supplieCode() + " - " +venBeanList.at(i)->supplieName();
    }
    ui->venSearchEditbox->setListModel(true);
    ui->venSearchEditbox->setItems(venList);

    QList<DepBean *> depBeanList = DepDAO::queryDepByEnd();
    QStringList depList ;
    for(int i =0 ; i < depBeanList.size(); i++){
        depList << depBeanList.at(i)->depId() + " - " +depBeanList.at(i)->depName();
    }
    ui->depSearchEditbox->setListModel(true);
    ui->depSearchEditbox->setItems(depList);

    QList<EmployeeBean *> employeeBeanList = EmployeeDAO::queryEmp();
    QStringList empList ;
    for(int i =0 ; i < employeeBeanList.size(); i++){
        empList << employeeBeanList.at(i)->empCode() + " - " +employeeBeanList.at(i)->empName();
    }
    ui->userSearchEditbox->setListModel(true);
    ui->userSearchEditbox->setItems(empList);

    QList<WareHouseBean *> whBeanList = WareDAO::queryWarehouse();
    QStringList whList ;
    for(int i =0 ; i < whBeanList.size(); i++){
        whList << whBeanList.at(i)->whCode() + " - " +whBeanList.at(i)->whName();
    }
    ui->whSearchEditbox->setListModel(true);
    ui->whSearchEditbox->setItems(whList);

    QList<ProductBean *> proBeanList = ProductDAO::queryProduct();
    QStandardItemModel *model = new QStandardItemModel(proBeanList.size(),1);
    for(int i=0;i < proBeanList.size();i++){
        QStandardItem *itemName = new QStandardItem(proBeanList.at(i)->productCode() + " - " +proBeanList.at(i)->productName());
        model->setItem(i,0,itemName);
    }
    QkEditDelegate *delegate = new QkEditDelegate(model,this);
    connect(delegate,SIGNAL(btnClicked()),this,SLOT(sInvClick()));
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(22);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setItemDelegateForColumn(0,delegate);

}
void PuOrderWin::sInvClick(){

    QString sql = " SELECT a.* FROM ba_product a"
            " WHERE a.product_code LIKE ? AND a.type_id LIKE ? ";
    childItemProperties childItem[] = {
            { "product_code","编码商品","商品", 0,60, true, true },
            { "product_name","名称商品","商品", 1,100, true, true },
            { "style","规格","规格", 2,80, true, true },
            { "purchase_unit","单位","单位", 3, 60,true, true },
            { "pu_price","价格","价格", 4, 60,true, true }
    };

    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }

    QString whCode = ui->whSearchEditbox->text() + " - " + ui->whSearchEditbox->subText();
    QString invCode = "";
    OptInvDialog *invDlg = new OptInvDialog(dItem,sql,invCode,this);

    if(invDlg->exec() == QDialog::Accepted){
        QItemSelectionModel *selectionModel = invDlg->getTableView()->selectionModel();
        QModelIndexList selected= selectionModel->selectedIndexes();
        if(selected.size() < 1){
            QMessageBox::information(this,"提示","末选择商品!");

        }else{
            invCode = invDlg->getTableView()->model()->data(invDlg->getTableView()->model()->index(selected.at(0).row(),0)).toString();
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,ui->tableWidget->currentRow(),mChildItem,"productCode",invCode);
        }
    }
    delete invDlg;

}
void PuOrderWin::footResized(int logicalIndex, int oldSize, int newSize){
    mFootView->resizeSection(logicalIndex + 1,newSize);
}
void PuOrderWin::refreshData(){

    QStringList headerLabels;
    for (int i = 0; i < mChildItem.size(); i++){
        headerLabels.append(mChildItem[i].cnName);
        ui->tableWidget->setColumnWidth(mChildItem[i].id,mChildItem[i].width);
        mFootView->resizeSection(mChildItem[i].id + 1,mChildItem[i].width);
        if(!mChildItem[i].visible)ui->tableWidget->hideColumn(mChildItem[i].id);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
}

void PuOrderWin::read(QString no){
    PuOrderVouchBean *bean = OrderDAO::getPuOrderByNo(no);
    mNo = no;
    if(bean != NULL && bean->no().length() > 0){
        ui->noEdit->setText(bean->no());
        ui->dateEdit->setDate(bean->busDate());
        ui->demanddDateEdit->setDate(bean->demandDate());
        ui->projectDateEdit->setDate(bean->projectDate());
        SupplieBean *venBean = SupplieDAO::getSupplieByCode(bean->supplierId());
        ui->venSearchEditbox->setText(bean->supplierId() + " - " + venBean->supplieName());
        WareHouseBean *whBean = WareDAO::getWarehouseById(bean->whCode());
        ui->whSearchEditbox->setText(bean->whCode() + " - " + whBean->whName());
        DepBean *depBean = DepDAO::getDepById(bean->depCode());
        ui->depSearchEditbox->setText(bean->depCode() + " - " + depBean->depName());
        ui->userSearchEditbox->setText(bean->personCode() + " - " + CacheBaBeanCommon::personToName(bean->personCode()));
        ui->memoEdit->setText(bean->memo());
        ui->makerEdit->setText(CacheBaBeanCommon::userToName(bean->createdBy(),1));
        ui->auditEdit->setText(bean->handler());
        for(int i = 0; i < ui->busTypeComboBox->count(); i++){
            if(bean->busType() == ui->busTypeComboBox->itemText(i)){
                ui->busTypeComboBox->setCurrentIndex(i);
            }
        }
        ui->toolBar->actions().at(0)->setEnabled(true);
        ui->toolBar->actions().at(1)->setEnabled(true);
        ui->toolBar->actions().at(3)->setEnabled(false);
        ui->toolBar->actions().at(6)->setEnabled(false);

        if(bean->handler().length() > 1){
            ui->toolBar->actions().at(4)->setEnabled(false);
            ui->toolBar->actions().at(5)->setEnabled(true);
        }else{
            ui->toolBar->actions().at(4)->setEnabled(true);
            ui->toolBar->actions().at(5)->setEnabled(false);
        }
        QList<PuOrderVouchsBean *> pBeanList = OrderDAO::queryPuOrderVouchsByNo(no);
        mChildVouchsList = OrderDAO::queryPuOrderVouchsByNo(no);
        ui->tableWidget->setRowCount(pBeanList.size() + 1);
        mTotalQuantity = 0;
        mTotalSum = 0;
        for(int i =0; i < pBeanList.size(); i++){
            WidgetBeanUtil::setBeanToTableWidget(ui->tableWidget,i,mChildItem,pBeanList.at(i));
            mTotalQuantity = mTotalQuantity + pBeanList.at(i)->quantity();
            mTotalSum = mTotalSum + pBeanList.at(i)->money();
        }
        QString strmTotalQuantity = QString("%1").arg(mTotalQuantity, 0, 'f', 2);
        QString strmTotalSum = QString("%1").arg(mTotalSum, 0, 'f', 2);
        mFootModel->setItem(5,new QStandardItem(strmTotalQuantity));
        mFootModel->setItem(7,new QStandardItem(strmTotalSum));
        mFootView->reset();
        readAuthority();
    }
}

void PuOrderWin::inputClear(){
    WidgetBeanUtil::clearLayoutWidgetData(ui->headGridLayout);


}

void PuOrderWin::setInputEnable(bool b){
     WidgetBeanUtil::setLayoutWidgetEnable(ui->headGridLayout,b);
     if(b){
         ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);
     }else{
         ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
     }
}

void PuOrderWin::addActionsTo(actionProperties acts[], unsigned int numElems){
    baseToolBar = addToolBar(tr("Base"));
    baseToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    baseToolBar->setIconSize(QSize(24, 24));
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolBar->setIconSize(QSize(24, 24));
    for (unsigned int i = 0; i < numElems; i++){
        QAction *act = new QAction(acts[i].actionName, this);
        QIcon icon;
        icon.addPixmap(acts[i].pixmap,  QIcon::Normal, QIcon::Off);

        act->setText(acts[i].actionTitle);
        act->setObjectName(acts[i].actionName);
        act->setIcon(icon);

        connect(act, SIGNAL(triggered()), this, acts[i].slot);

        if(i<9){
            QString proceccId = mWinId + QString::number(i);
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::puSubId().toInt(),mWinId.toInt(),proceccId.toInt(),acts[i].toolTip,acts[i].actionName);

            act->setEnabled(false);
            ui->toolBar->addAction(act);
            addAction(act);
        }
        else
            baseToolBar->addAction(act);
    }

    connect(ui->toolBar, SIGNAL(actionTriggered(QAction*)), this, SLOT(toolBarActTriggered(QAction*)));


}

void PuOrderWin::toolBarActTriggered(QAction *act){
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::puSubId().toInt(),mWinId.toInt(),act->objectName());

}

void PuOrderWin::sFirst(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            ui->toolBar->actions().at(8)->setEnabled(false);
            setInputEnable(false);
        }else{
            return ;
        }
    }
    mRecord = 0;
    ui->tableWidget->clear();
    refreshData();
    QList<PuOrderVouchBean *> vouchBeanList = OrderDAO::queryPuOrderByPage(0,1);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->no());

    }
    baseToolBar->actions().at(0)->setEnabled(false);
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(2)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(true);
}
\
void PuOrderWin::sNext(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            ui->toolBar->actions().at(8)->setEnabled(false);
            setInputEnable(false);
        }else{
            return ;
        }
    }
    if(mRecord < mCountRecord)
        mRecord = mRecord + 1;
    if(mRecord == mCountRecord){
        baseToolBar->actions().at(3)->setEnabled(false);
        baseToolBar->actions().at(1)->setEnabled(false);
    }
    ui->tableWidget->clear();
    refreshData();
    QList<PuOrderVouchBean *> vouchBeanList = OrderDAO::queryPuOrderByPage(mRecord,1);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->no());
    }
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(0)->setEnabled(true);
}

void PuOrderWin::sPrevious(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            ui->toolBar->actions().at(8)->setEnabled(false);
            setInputEnable(false);
        }else{
            return ;
        }
    }
    if(mRecord > 0)
        mRecord = mRecord - 1;
    if(mRecord == 0){
        baseToolBar->actions().at(0)->setEnabled(false);
        baseToolBar->actions().at(2)->setEnabled(false);
    }
    ui->tableWidget->clear();
    refreshData();
    QList<PuOrderVouchBean *> vouchBeanList = OrderDAO::queryPuOrderByPage(mRecord,1);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->no());
    }
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(true);
}

void PuOrderWin::sEnd(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            ui->toolBar->actions().at(8)->setEnabled(false);
            setInputEnable(false);
        }else{
            return ;
        }
    }
    ui->tableWidget->clear();
    refreshData();
    mCountRecord = OrderDAO::getPuOrderCount() - 1;
    mRecord = mCountRecord;
    QList<PuOrderVouchBean *> vouchBeanList = OrderDAO::queryPuOrderByPage(mCountRecord,1);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->no());
    }
    baseToolBar->actions().at(0)->setEnabled(true);
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(false);
}

void PuOrderWin::sNew(){
    inputClear();
    mIsEdit = true;
    mEditStatus = addFlag;
    setInputEnable(true);
    ui->dateEdit->setDate(HaoKeApp::getInstance()->getOperateDate());
    ui->demanddDateEdit->setDate(HaoKeApp::getInstance()->getOperateDate());
    ui->projectDateEdit->setDate(HaoKeApp::getInstance()->getOperateDate());
    ui->toolBar->actions().at(0)->setEnabled(false);
    ui->toolBar->actions().at(1)->setEnabled(false);
    ui->toolBar->actions().at(2)->setEnabled(false);
    ui->toolBar->actions().at(3)->setEnabled(true);
    ui->toolBar->actions().at(4)->setEnabled(false);
    ui->toolBar->actions().at(5)->setEnabled(false);
    ui->toolBar->actions().at(6)->setEnabled(true);
    ui->toolBar->actions().at(8)->setEnabled(true);
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);
    int nCount = OrderDAO::getPuOrderCount(QDate::currentDate()) ;
    mNo = PuItemUtil::getToDayMaxNo(mWinId,"pu_order_vouch",QDate::currentDate(),nCount);
    ui->noEdit->setText(mNo);
    ui->noEdit->setText(mNo);
    refreshData();

    mTotalQuantity = 0;
    mTotalSum = 0;

    mFootModel->setItem(5,new QStandardItem(QString::number(mTotalQuantity)));
    mFootModel->setItem(7,new QStandardItem(QString::number(mTotalSum)));
    mFootView->reset();
    readAuthority();
}

void PuOrderWin::sEdit(){
    if(ui->noEdit->text().length() < 1){
        QMessageBox::warning(this,"提示","无单不能修改！");
        return ;
    }
    if(ui->auditEdit->text().length() > 0){
        QMessageBox::warning(this,"提示","已审核，不能修改！");
        return ;
    }
    mIsEdit = true;
    setInputEnable(true);
    mEditStatus = editFlag;
    ui->noEdit->setEnabled(false);

    ui->toolBar->actions().at(0)->setEnabled(false);
    ui->toolBar->actions().at(1)->setEnabled(false);
    ui->toolBar->actions().at(2)->setEnabled(true);
    ui->toolBar->actions().at(3)->setEnabled(true);
    ui->toolBar->actions().at(4)->setEnabled(false);
    ui->toolBar->actions().at(5)->setEnabled(false);
    ui->toolBar->actions().at(6)->setEnabled(true);
    ui->toolBar->actions().at(8)->setEnabled(true);
    readAuthority();
}

void PuOrderWin::sSave(){
    if(ui->noEdit->text().length()< 1){
        QMessageBox::warning(this,"提示","出错，此单号为空，不能保存");
        return ;
    }

    QAbstractItemModel *model = ui->tableWidget->model();
    int rowNum = model->rowCount() -1;
    if(rowNum == 0){
        QMessageBox::warning(this,"提示","无数据，不能保存");
        return;
    }

    if(ui->venSearchEditbox->text().trimmed().length() < 1){
        QMessageBox::warning(this,"提示","请输入供应商");
        return ;
    }
    if(ui->whSearchEditbox->text().trimmed().length() < 1){
        QMessageBox::warning(this,"提示","请输入仓库");
        return ;
    }
    for(int i = 0;i < rowNum; i++){
        QString pCode = model->data(model->index(i,0)).toString();
        ProductBean *pBean = ProductDAO::getProductByCode(pCode);
        if(pBean != NULL && pBean->productCode().length() > 0){
            for(int j = 0; j < ui->tableWidget->rowCount(); j ++){
                if(i != j && ui->tableWidget->model()->data(ui->tableWidget->model()->index(j,0)).toString().trimmed() == pCode){
                    QMessageBox::information(this,"提示","此商品：" + pCode + " 重复！");
                    ui->tableWidget->model()->setData(ui->tableWidget->model()->index(j,0),"");
                    return;
                }
            }
        }else{
            QMessageBox::warning(this,"提示","此原商品编码，不存在，不能保存");
            return ;
        }
    }
    if(mEditStatus == addFlag){
        if(OrderDAO::getPuOrderCountByNo(ui->noEdit->text()) > 0){
            QMessageBox::warning(this,"提示","出错，此单号重复，不能保存，重新生成新单号");
            int nCount = OrderDAO::getPuOrderCount(QDate::currentDate()) ;
            mNo = PuItemUtil::getToDayMaxNo(mWinId,"pu_order_vouch",QDate::currentDate(),nCount);
            ui->noEdit->setText(mNo);
            return ;
        }
        mNo = ui->noEdit->text();
        PuOrderVouchBean *puVouchBean = new PuOrderVouchBean();
        puVouchBean->setNo(ui->noEdit->text());
        QDateTime time = QDateTime::currentDateTime();
        puVouchBean->setBusDate(ui->dateEdit->date());
        puVouchBean->setBusType(ui->busTypeComboBox->currentText());
        puVouchBean->setDemandDate(ui->demanddDateEdit->date());
        puVouchBean->setProjectDate(ui->projectDateEdit->date());
        puVouchBean->setSupplierId(ui->venSearchEditbox->text());
        puVouchBean->setDepCode(ui->depSearchEditbox->text());
        puVouchBean->setPersonCode(ui->userSearchEditbox->text());
        puVouchBean->setWhCode(ui->whSearchEditbox->text());
        puVouchBean->setMemo(ui->memoEdit->text());
        puVouchBean->setHandler("");
        puVouchBean->setCreated(time);
        puVouchBean->setIsHandle(false);
        puVouchBean->setIsComplete(false);
        puVouchBean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        puVouchBean->setCreater(HaoKeApp::getInstance()->getUserDesc());
        puVouchBean->setUpdated(time);
        puVouchBean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        puVouchBean->setUpdater(HaoKeApp::getInstance()->getUserDesc());
        puVouchBean->setStatus(0);
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = 0;
        mResult = OrderDAO::createPuOrder(puVouchBean);
        int cResult = 0;
        double d_val = 0;
        for(int i = 0;i < rowNum; i++){
            PuOrderVouchsBean *puVouchsBean = new PuOrderVouchsBean();
            puVouchsBean->setOrderNo(mNo);
            WidgetBeanUtil::setItemModelToBean(model,i,mChildItem,puVouchsBean);

            puVouchsBean->setTaxPrice(puVouchsBean->price());
            puVouchsBean->setIsComplete(false);
            puVouchsBean->setInQuantity(d_val);
            puVouchsBean->setReQuantity(d_val);

            //puVouchsBean->setDefine1("1");
            //puVouchsBean->setDefine2("8");
            //puVouchsBean->setDefine3("3");

            puVouchsBean->setToq(0);

            int c = OrderDAO::createPuOrderVouchs(puVouchsBean);
            if(c < 1){
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"提示","此" + puVouchsBean->productCode() + " 数据提交出错,不能保存");
                return ;
            }
            cResult = cResult + c;
        }
        if(mResult > 0 && cResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            ui->toolBar->actions().at(8)->setEnabled(false);
            ui->makerEdit->setText(CacheBaBeanCommon::userToName(HaoKeApp::getInstance()->getUserId(),1));
            setInputEnable(false);
            mCountRecord = OrderDAO::getPuOrderCount() - 1;
            mRecord = mCountRecord;

            mDelChildList.clear();
            mAddChildVouchsList.clear();
            mChildVouchsList.clear();

            ui->tableWidget->clear();
            refreshData();
            read(ui->noEdit->text());

            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::information(this,"Prompt","数据提交出错");
            return ;
        }
        readAuthority();



    }else if(mEditStatus == editFlag){
        //修改数据保存
        PuOrderVouchBean *puVouchBean = OrderDAO::getPuOrderByNo(mNo);
        if(puVouchBean && puVouchBean->isHandle()){
            QMessageBox::warning(this,"提示","此单已审核，不能修改");
            return ;
        }
        puVouchBean->setNo(ui->noEdit->text());
        QDateTime time = QDateTime::currentDateTime();
        puVouchBean->setBusDate(ui->dateEdit->date());
        puVouchBean->setBusType(ui->busTypeComboBox->currentText());
        puVouchBean->setDemandDate(ui->demanddDateEdit->date());
        puVouchBean->setProjectDate(ui->projectDateEdit->date());
        puVouchBean->setSupplierId(ui->venSearchEditbox->text());
        puVouchBean->setDepCode(ui->depSearchEditbox->text());
        puVouchBean->setPersonCode(ui->userSearchEditbox->text());
        puVouchBean->setWhCode(ui->whSearchEditbox->text());
        puVouchBean->setMemo(ui->memoEdit->text());
        puVouchBean->setUpdated(time);
        puVouchBean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        puVouchBean->setUpdater(HaoKeApp::getInstance()->getUserDesc());
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = 0;
        mResult = OrderDAO::updatePuOrder(puVouchBean);
        int cResult = 0;
        //删除
        for(int i = 0; i < mDelChildList.size(); i++){
            PuOrderVouchsBean *delBean = new PuOrderVouchsBean;
            delBean->setId(mDelChildList.at(i));
            int c = OrderDAO::delPuOrderVouchs(delBean);
            cResult = cResult + c;
        }
        //更新
        for(int i = 0; i < mChildVouchsList.size(); i++){
            int c = OrderDAO::updatePuOrderVouchs(mChildVouchsList.at(i));
            cResult = cResult + c;
        }
        //添加
        for(int i = 0; i < mAddChildVouchsList.size(); i++){
            int c = OrderDAO::createPuOrderVouchs(mAddChildVouchsList.at(i));
            cResult = cResult + c;
        }

        if(mResult > 0 && cResult>0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            ui->makerEdit->setText(CacheBaBeanCommon::userToName(HaoKeApp::getInstance()->getUserId(),1));
            setInputEnable(false);
            mDelChildList.clear();
            mAddChildVouchsList.clear();
            mChildVouchsList.clear();

            ui->tableWidget->clear();
            refreshData();
            read(ui->noEdit->text());

            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::information(this,"Prompt","数据提交出错");
            return ;
        }
        readAuthority();
    }

}

void PuOrderWin::sDelete(){
    if(ui->auditEdit->text().length() > 0){
        QMessageBox::warning(this,"提示","已审核，不能删除！");
        return ;
    }
    mNo = ui->noEdit->text().trimmed();
    QList<PuArrivalVouchsBean *> vouchsList = ArrivalDAO::queryPuArrivalVouchsByOrderNo(ui->noEdit->text().trimmed());
    if(vouchsList.size() > 0){
        QMessageBox::information(this,"提示","此单在到货单：" + vouchsList.at(0)->arrivalNo() + " 中已执行，不能删除！");
        return ;
    }
    if(QMessageBox::warning(this,"提示","是否删除？",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        PuOrderVouchBean *bean = OrderDAO::getPuOrderByNo(mNo);
        bean->setNo(mNo);
        if(bean->isHandle()){
            QMessageBox::warning(this,"提示",bean->handler() + " 已审核，不能删除！");
            return ;
        }
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = OrderDAO::delPuOrderByNo(bean);
        int cResult = OrderDAO::delPuOrderVouchsByNo(ui->noEdit->text());
        if(mResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            mIsEdit =false;
            setInputEnable(false);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            if(mRecord ==0){
                sNext();
            }else sPrevious();
            mCountRecord = OrderDAO::getPuOrderCount() - 1;
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::critical(this,"错误","删除出错");

        }

    }
    readAuthority();
}

void PuOrderWin::sDelRow(){
    if(!mIsEdit){
        QMessageBox::information(this,"提示","不能修改！");
        return;
    }
    QAbstractItemModel *modelTotal = ui->tableWidget->model();
    QItemSelectionModel *seleced = ui->tableWidget->selectionModel();
    int row = seleced->currentIndex().row();

    if(row >= 0){

        QString name = modelTotal->data(modelTotal->index(row,1)).toString();
        QString code = modelTotal->data(modelTotal->index(row,0)).toString();
        if(name.length() < 1){
            QMessageBox::information(this,"提示","不能删除此行！");
            return;
        }
        if(QMessageBox::warning(this, tr("Prompt"),"是否要删除此 *" + name + "*",
                                QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            if(mEditStatus == addFlag){
                modelTotal->removeRow(row);
            }else{
                for(int i =0 ; i < mChildVouchsList.size(); i++){
                    if(code == mChildVouchsList.at(i)->productCode()){
                        mDelChildList.append(mChildVouchsList.at(i)->id());
                        mChildVouchsList.removeAt(i);

                    }
                }
                for(int i =0 ; i < mAddChildVouchsList.size(); i++){
                    if(code == mAddChildVouchsList.at(i)->productCode()){
                        mAddChildVouchsList.removeAt(i);
                    }
                }
                modelTotal->removeRow(row);
            }
            if(mIsEdit){
                mTotalQuantity = 0;
                mTotalSum = 0;
                QAbstractItemModel *model = ui->tableWidget->model();
                for(int i = 0 ; i < ui->tableWidget->rowCount(); i++){
                    double quantity = model->data(model->index(i,WidgetBeanUtil::getChildItemId(mChildItem,"quantity"))).toDouble();
                    double money = model->data(model->index(i,WidgetBeanUtil::getChildItemId(mChildItem,"money"))).toDouble();

                    mTotalQuantity = mTotalQuantity + quantity;
                    mTotalSum = mTotalSum + money;

                }

                mFootModel->setItem(5,new QStandardItem(QString::number(mTotalQuantity)));
                mFootModel->setItem(7,new QStandardItem(QString::number(mTotalSum)));
                mFootView->reset();

            }


        }
    }else{
        QMessageBox::information(this,"Prompt","请选择要删除的行!");
    }
}

void PuOrderWin::sAudit(){
    PuOrderVouchBean *bean = OrderDAO::getPuOrderByNo(ui->noEdit->text().trimmed());
    if(bean !=NULL && bean->no().length() > 0){
        if(bean->isHandle()){
            ui->toolBar->actions().at(4)->setEnabled(false);
            ui->toolBar->actions().at(5)->setEnabled(true);
            QMessageBox::information(this,"提示","已审核，不能再审核！");
            return ;
        }
        //是否可更新销售订单已采购数量
        bool isUpSaOrder = false;
        //判断销售订单的可采购数量
        for(int i=0;i<mChildVouchsList.size();i++){
            if(mChildVouchsList.at(i)->originNo().length()>2){
                isUpSaOrder = true;
                SaOrderVouchsBean *oBean = OrderDAO::getSaOrderVouchsBy(mChildVouchsList.at(i)->originNo(),mChildVouchsList.at(i)->productCode());
                double real = 0;
                if(oBean && oBean->orderNo().length() > 2){
                    real = oBean->quantity() - oBean->puQuantity();
                    if(real - mChildVouchsList.at(i)->quantity() < 0){
                        QMessageBox::critical(this,"错误","销售订单:" + mChildVouchsList.at(i)->originNo() + " 商品：" + mChildVouchsList.at(i)->productName() + " 可采购数量为：" + QString::number(real) );
                        return ;
                    }
                }else{
                    QMessageBox::critical(this,"错误","销售订单:" + mChildVouchsList.at(i)->originNo() + " 商品：" +
                                          mChildVouchsList.at(i)->productName() + " 不存在");
                    return ;
                }
            }

        }
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int saResult = 0;
        if(isUpSaOrder){
            for(int i=0;i<mChildVouchsList.size();i++){
                if(mChildVouchsList.at(i)->originNo().length()>2){
                    SaOrderVouchsBean *oBean = OrderDAO::getSaOrderVouchsBy(mChildVouchsList.at(i)->originNo(),mChildVouchsList.at(i)->productCode());
                    double real = 0;
                    if(oBean && oBean->orderNo().length() > 2){
                        real = oBean->quantity() - oBean->puQuantity();
                        oBean->setPuQuantity(oBean->puQuantity() + mChildVouchsList.at(i)->quantity() );
                        OrderDAO::updateSaOrderVouchs(oBean);
                        saResult = saResult + 1;

                    }else{
                        DBManager::getDBManager()->getGoinDBConnection().rollback();
                        QMessageBox::critical(this,"错误","无此销售订单不能审核,订单号:" + mChildVouchsList.at(i)->originNo()  );
                        return ;
                    }
                }

            }
        }
        bean->setHandler(CacheBaBeanCommon::userToName(HaoKeApp::getInstance()->getUserId(),1));
        bean->setAuditTime(QDateTime::currentDateTime());
        bean->setIsHandle(true);
        bean->setUpdated(QDateTime::currentDateTime());
        bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        bean->setUpdater(HaoKeApp::getInstance()->getUserDesc());
        int result = OrderDAO::updatePuOrder(bean);
        if(isUpSaOrder){
            if(result > 0 && saResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
                ui->auditEdit->setText(bean->handler());
                ui->toolBar->actions().at(4)->setEnabled(false);
                ui->toolBar->actions().at(5)->setEnabled(true);
                readAuthority();
                QMessageBox::information(this,"提示","审核成功！");
            }else{
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"提示","更新销售订单出错审核出错！");
            }
        }else{
            if(result > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
                ui->auditEdit->setText(bean->handler());
                ui->toolBar->actions().at(4)->setEnabled(false);
                ui->toolBar->actions().at(5)->setEnabled(true);
                readAuthority();
                QMessageBox::information(this,"提示","审核成功！");
            }else{
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"提示","审核出错！");
            }
        }

    }else{
        QMessageBox::critical(this,"错误","无此单据，不能审核");
    }

}

void PuOrderWin::sAbAudit(){
    PuOrderVouchBean *bean = OrderDAO::getPuOrderByNo(ui->noEdit->text().trimmed());
    if(bean !=NULL && bean->no().length() > 0){
        if(!bean->isHandle()){
            ui->toolBar->actions().at(4)->setEnabled(true);
            ui->toolBar->actions().at(5)->setEnabled(false);
            QMessageBox::information(this,"提示","未审核，不能弃审！");
            return ;
        }
        QList<PuArrivalVouchsBean *> vouchsList = ArrivalDAO::queryPuArrivalVouchsByOrderNo(ui->noEdit->text().trimmed());
        if(vouchsList.size() > 0){
            QMessageBox::information(this,"提示","此单在到货单：" + vouchsList.at(0)->arrivalNo() + " 中已执行，不能弃审！");
            return ;
        }
        bool isUpSaOrder = false;
        //判断销售订单的可采购数量
        for(int i=0;i<mChildVouchsList.size();i++){
            if(mChildVouchsList.at(i)->originNo().length()>2){
                isUpSaOrder = true;
                SaOrderVouchsBean *oBean = OrderDAO::getSaOrderVouchsBy(mChildVouchsList.at(i)->originNo(),mChildVouchsList.at(i)->productCode());
                double real = 0;
                if(oBean && oBean->orderNo().length() > 2){
                    real = oBean->puQuantity();
                    if(real - mChildVouchsList.at(i)->quantity() < 0){
                        QMessageBox::critical(this,"错误","销售订单:" + mChildVouchsList.at(i)->originNo() + " 商品：" + mChildVouchsList.at(i)->productName() + " 已采购数量为：" + QString::number(real) );
                        return ;
                    }
                }else{
                    QMessageBox::critical(this,"错误","销售订单:" + mChildVouchsList.at(i)->originNo() + " 商品：" +
                                          mChildVouchsList.at(i)->productName() + " 不存在");
                    return ;
                }
            }

        }
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int saResult = 0;
        if(isUpSaOrder){
            for(int i=0;i<mChildVouchsList.size();i++){
                if(mChildVouchsList.at(i)->originNo().length()>2){
                    SaOrderVouchsBean *oBean = OrderDAO::getSaOrderVouchsBy(mChildVouchsList.at(i)->originNo(),mChildVouchsList.at(i)->productCode());
                    double real = 0;
                    if(oBean && oBean->orderNo().length() > 2){
                        real = oBean->quantity() - oBean->puQuantity();
                        oBean->setPuQuantity(oBean->puQuantity() - mChildVouchsList.at(i)->quantity() );
                        OrderDAO::updateSaOrderVouchs(oBean);
                        saResult = saResult + 1;

                    }else{
                        DBManager::getDBManager()->getGoinDBConnection().rollback();
                        QMessageBox::critical(this,"错误","无此销售订单不能审核,订单号:" + mChildVouchsList.at(i)->originNo()  );
                        return ;
                    }
                }

            }
        }
        bean->setHandler("");
        bean->setIsHandle(false);
        bean->setUpdated(QDateTime::currentDateTime());
        bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        bean->setUpdater(HaoKeApp::getInstance()->getUserDesc());
        int result = OrderDAO::updatePuOrder(bean);
        if(isUpSaOrder){
            if(result > 0 && saResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
                ui->auditEdit->setText(bean->handler());
                ui->toolBar->actions().at(4)->setEnabled(true);
                ui->toolBar->actions().at(5)->setEnabled(false);
                readAuthority();
                QMessageBox::information(this,"提示","弃审成功*");
            }else{
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"提示","销售订单弃审出错*");
            }
        }else{
            if(result > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
                ui->auditEdit->setText(bean->handler());
                ui->toolBar->actions().at(4)->setEnabled(true);
                ui->toolBar->actions().at(5)->setEnabled(false);
                readAuthority();
                QMessageBox::information(this,"提示","弃审成功！");
            }else{
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"提示","弃审出错！");
            }
        }

    }

}


void PuOrderWin::sChoose(){
    if(ui->venSearchEditbox->text().trimmed().length() < 1){
        QMessageBox::warning(this,"提示","请输入供应商");
        return ;
    }
    ChooseVouchDialog *cVouchDlg = new ChooseVouchDialog(this);
    cVouchDlg->setWindowTitle("提取销售订单");

    childItemProperties childItem[] = {
            { "no","销售订单号","销售订单号", 0,100, true, true },
            { "bus_date","销售订单日期","销售订单日期", 1,80, true, true },
            { "bus_type","销售订单类型","销售订单类型", 2,80, true, false },
            { "cus_code","客户编码","客户编码", 3,80, true, false },
            { "cus_name","客户名称","客户名称", 4, 120,true, true },
            { "product_code","商品编码","商品编码", 5,80, true, true },
            { "product_name","商品名称","商品名称", 6,100, true, true },
            { "product_style","商品规格","商品规格",7,80, true, false },
            { "unit","单位","单位", 8,60, true, false },
            { "pu_quantity","累计采购数量","累计采购数量", 9, 80,true, true },
            { "not_quantity","未采购数量","未采购数量", 10, 80,true, true },
            { "price","销售单价","销售单价", 11,80, true, true },
            { "money","销售金额","销售金额", 12,80, false, false },
        { "define1","自定义1","自定义1", 13,100, false, true },
        { "define2","自定义2","自定义2", 14,100, false, true },
        { "define3","自定义3","自定义3", 15,100, false, true },
        { "define4","自定义4","自定义4", 16,100, false, true },
        { "define5","自定义5","自定义5", 17,100, false, true },
        { "define6","自定义6","自定义6", 18,100, false, true },
        { "memo","备注","备注", 19,160, false, true }

    };

    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }

    //是否使用自定义字段
    SystemSetBean *useDefineBean = SystemSetDAO::getBean("101");
    if(useDefineBean && useDefineBean->id().length() > 0){
        if(useDefineBean->yesNo()){
            QList<DefineBean *> defineList = CommonDAO::queryDefine();
            for(int i =10 ; i < size ; i ++){
                for(int j =0 ; j < defineList.size() ; j ++){
                    if(dItem.at(i).name.trimmed() ==   defineList.at(j)->code()){
                        dItem[i].cnName = defineList.at(j)->name();
                        dItem[i].title = defineList.at(j)->name();
                        dItem[i].visible = defineList.at(j)->isView();

                    }
                }
            }
        }
    }

    QList<CustomerBean *> cusBeanList = CustomerDAO::queryCus();
    QStringList venList ;
    for(int i =0 ; i < cusBeanList.size(); i++){
        venList << cusBeanList.at(i)->cusCode() + " - " +cusBeanList.at(i)->cusName();
    }
    cVouchDlg->dwNameQks->setListModel(true);
    cVouchDlg->dwNameQks->setItems(venList);

    QList<CustomerTypeBean *> typeBeanList = CustomerTypeDAO::queryType();
    QStringList typeList ;
    for(int i =0 ; i < typeBeanList.size(); i++){
        typeList << typeBeanList.at(i)->typeId() + " - " +typeBeanList.at(i)->typeName();
    }
    cVouchDlg->dwTypeQks->setListModel(true);
    cVouchDlg->dwTypeQks->setItems(typeList);
    //cVouchDlg->dwTypeQks->setReadOnly(true);
    QString sql = " SELECT a.id, a.no, a.bus_date, a.bus_type, a.cus_code, b.cus_name, a.wh_code,a.dep_code,a.demand_date,c.product_code,"
            " d.product_name, c.product_style, c.unit,  a.project_date, a.person_code, a.handler, a.audit_time, a.creater, a.created,"
            " a.closer, a.updater, a.updated, a.status, c.quantity,c.pu_quantity,c.not_quantity , c.price, c.money, "
            " c.memo, c.define1, c.define2, c.define3, c.define4, c.define5, c.define6 "
            " from sa_order_vouch a, "
            "( SELECT g.*,g.quantity- COALESCE(h.sum_qunatity,0) as not_quantity "
                " from  sa_order_vouchs g "
                " LEFT JOIN ( "
                    " SELECT e.origin_no,e.product_code,sum(quantity) as sum_qunatity "
                    " from pu_order_vouchs e inner join pu_order_vouch f ON e.order_no=f.no "
                    " GROUP BY e.origin_no,e.product_code) h "
                " ON g.order_no=h.origin_no AND g.product_code = h.product_code "
                " where g.quantity-COALESCE(h.sum_qunatity,0) > 0 "
                " ) c,ba_product d,ba_customer b "
            " WHERE a.bus_date>=? AND a.bus_date<=? AND b.cus_type like ? AND a.cus_code like ? "
            " AND d.type_id like ? AND c.product_code like ?"
            " AND a.no=c.order_no AND c.product_code=d.product_code AND a.cus_code= b.cus_code "
            " ORDER BY id ASC";
    cVouchDlg->initData(dItem,sql);
    cVouchDlg->initTableHead();

    if(cVouchDlg->exec() == QDialog::Accepted){
        QItemSelectionModel *selectionModel = cVouchDlg->tableView->selectionModel();
        QModelIndexList selected= selectionModel->selectedIndexes();
        if(selected.size()<1){
            QMessageBox::information(this,"提示","未提取数据");

        }else{
            QAbstractItemModel *modelChoose = cVouchDlg->tableView->model();
            int cusRow = 0;
            QList<int > selectedRowsList;
            foreach (QModelIndex index, selected){
                int b = true;
                for(int i = 0; i < selectedRowsList.size(); i++){
                    if(selectedRowsList.at(i)== index.row())b = false;
                }
                if(selectedRowsList.size() < 1 || b){
                    selectedRowsList.append(index.row());
                }


            }
            mIsChoose = true;
            foreach (int row, selectedRowsList){
                cusRow = ui->tableWidget->rowCount() -1 ;
                QString orderNo = modelChoose->data(modelChoose->index(row,0)).toString();
                QString productCode = modelChoose->data(modelChoose->index(row,5)).toString();
                double quantity = modelChoose->data(modelChoose->index(row,10)).toDouble();
                double price = modelChoose->data(modelChoose->index(row,11)).toDouble();
                double money = quantity * price;
                WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,cusRow,mChildItem,"productCode",productCode);
                productCode = ui->tableWidget->model()->data(ui->tableWidget->model()->index(cusRow,WidgetBeanUtil::getChildItemId(mChildItem,"productCode"))).toString();
                if(productCode.trimmed().length() > 1){
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,cusRow,mChildItem,"price",price);
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,cusRow,mChildItem,"quantity",quantity);
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,cusRow,mChildItem,"money",money);
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,cusRow,mChildItem,"originNo",orderNo);
                }

            }
            mIsChoose = false;
        }

    }
}

void PuOrderWin::sPrint(){

    QString fileName = "ReportPuOrder.xml";
    QString title = "采购订单";
    QString formatData = "";
    QList<ReportFormatBean *> rptList = ReportDAO::queryRptBy(mWinId);

    if(rptList.size() > 0){
        formatData = rptList.at(rptList.size() - 1)->reportFormat();
    }else {
        formatData = PrintUtils::makeWinPrintFormatData(ui->headGridLayout,mChildItem,title,fileName);
        ReportFormatBean *rptBean = new ReportFormatBean();
        rptBean->setReportTitle(title);
        rptBean->setReportFormat(formatData);
        rptBean->setWinId(mWinId.toInt());
        rptBean->setCreated(QDateTime::currentDateTime());
        rptBean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        rptBean->setCreater(HaoKeApp::getInstance()->getUserDesc());
        int result = ReportDAO::createRpt(rptBean);

    }
    QtRPT *report = new QtRPT(this);
    report->setBackgroundImage(QPixmap("./qt_background_portrait.png"));
    connect(report,SIGNAL(setValue(int&,QString&,QVariant&,int)),this,SLOT(setValue(int&,QString&,QVariant&,int)));
    report->recordCount << ui->tableWidget->rowCount() - 1;
    if (report->loadReportFormat(formatData) == false) {
        qDebug()<<"Report's format is null";
    }
    report->setWindowTitle(title);
    report->setModel(ui->tableWidget->model());
    report->setChildItem(mChildItem);

    if(HaoKeApp::getInstance()->getUserLevel()>8){
        DesignOptDialog *designOptDlg = new DesignOptDialog(this);
        QString formatData2 = PrintUtils::makeWinPrintFormatData(ui->headGridLayout,mChildItem,title,fileName);
        designOptDlg->setPrintData(0,mWinId,title,formatData,formatData2);
        int r = designOptDlg->exec();
        if(r == QDialog::Accepted){
            ReportFormatBean *fBean = ReportDAO::getRptById(QString::number(designOptDlg->getPrintId()));
            if(fBean){
                formatData = fBean->reportFormat();
                if (report->loadReportFormat(formatData) == false) {
                    qDebug()<<"Report's file not found";
                }
            }
            report->printExec();
        }else{

        }
    }else{
        report->printExec();
    }

}

void PuOrderWin::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage){
    Q_UNUSED(reportPage);
    QGridLayout *layout = ui->headGridLayout;
    for(int i = 0 ; i < layout->rowCount(); i ++){
        for(int j =0 ; j < layout->columnCount(); j ++ ){
            QLayoutItem *layoutItem = layout->itemAtPosition(i,j);

            if(layoutItem && !layoutItem->isEmpty()){
                QWidget *widget = layoutItem->widget();

                QString className = widget->metaObject()->className();
                if(className == "QLineEdit"){
                    QLineEdit *c = (QLineEdit *)layoutItem->widget();
                    if (paramName == c->objectName()){
                        paramValue = c->text();
                        return ;
                    }
                }else if(className == "QkSearchEditBox"){
                    QkSearchEditBox *c = (QkSearchEditBox *)layoutItem->widget();
                    if (paramName == c->objectName()){
                        //paramValue = c->text() + "  " + c->subText();
                        paramValue = c->subText();
                        return ;
                    }
                }else if(className == "QDateEdit"){
                    QDateEdit *c = (QDateEdit *)layoutItem->widget();
                    if (paramName == c->objectName()){
                        paramValue = c->text();
                        return ;
                    }
                }else if(className == "QComboBox"){
                    QComboBox *c = (QComboBox *)layoutItem->widget();
                    if (paramName == c->objectName()){
                        paramValue = c->currentText();
                        return ;
                    }
                }
            }

        }
    }

}

void PuOrderWin::sCancel(){

    this->close();
}

void PuOrderWin::closeEvent(QCloseEvent *event){

    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::No){
            event->ignore();
            return ;
        }
    }

    event->accept();
    HaoKeApp::getInstance()->gui()->removeSubWin(this);


}

void PuOrderWin::setupContextMenu(){
    /*
    handleAct = new QAction(QIcon(":/images/connector.png"),tr("关联联赛"),this);

    connect(handleAct, SIGNAL(triggered()), this, SLOT(handleMatch()));
    */
    setContextMenuPolicy(Qt::ActionsContextMenu);
}
void PuOrderWin::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    if(item->column() == 0 && mIsEdit){
        QString code = item->data(Qt::EditRole).toString().trimmed();
        if(code.length() < 1){
            return ;
        }
        //重复判断
        for(int i = 0; i < ui->tableWidget->rowCount(); i ++){
            if(i != item->row() && ui->tableWidget->model()->data(ui->tableWidget->model()->index(i,0)).toString().trimmed() == code){
                QMessageBox::information(this,"提示","此商品,编码：" + code + " 已输入！");
                ui->tableWidget->model()->setData(ui->tableWidget->model()->index(item->row(),0),"");
                return;
            }
        }
        //根据ID查询原料信息
        ProductBean *bean = ProductDAO::getProductByCode(code);
        if(code.length() > 0 && bean != NULL && bean->productCode() == code ){
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"productName",bean->productName());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"productStyle",bean->style());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"unit",bean->purchaseUnit());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"price",bean->puPrice());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"quantity",1);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"money",1*bean->puPrice());

            if((ui->tableWidget->rowCount()-1) == item->row()){
                QAbstractItemModel *model = ui->tableWidget->model();
                int id = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toInt();
                if(mEditStatus == editFlag && id < 1){

                    //单据修改 增加数据
                    PuOrderVouchsBean *puVouchsBean = new PuOrderVouchsBean();
                    puVouchsBean->setOrderNo(ui->noEdit->text());
                    WidgetBeanUtil::setItemModelToBean(model,item->row(),mChildItem,puVouchsBean);
                    puVouchsBean->setIsComplete(false);
                    mAddChildVouchsList.append(puVouchsBean);
                }
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            }
        }else{
            QMessageBox::information(this,"提示","不存在此商品");

            return ;
        }

    }else if(item->column() == 4 || item->column()==5){

        QTableWidgetItem *moneyItemR = new QTableWidgetItem();

        double price = ui->tableWidget->model()->data(ui->tableWidget->model()->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"price"))).toDouble();
        double quantity = ui->tableWidget->model()->data(ui->tableWidget->model()->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"quantity"))).toDouble();
        double money = price * quantity;
        QString strMoney = QString("%1").arg(money, 0, 'f', 2);
        moneyItemR->setData(Qt::EditRole,strMoney);
        ui->tableWidget->setItem(item->row(),6,moneyItemR);
        if(mIsEdit){
            mTotalQuantity = 0;
            mTotalSum = 0;
            QAbstractItemModel *model = ui->tableWidget->model();
            for(int i = 0 ; i < ui->tableWidget->rowCount(); i++){
                double quantity = model->data(model->index(i,WidgetBeanUtil::getChildItemId(mChildItem,"quantity"))).toDouble();
                double money = model->data(model->index(i,WidgetBeanUtil::getChildItemId(mChildItem,"money"))).toDouble();

                mTotalQuantity = mTotalQuantity + quantity;
                mTotalSum = mTotalSum + money;

            }
            QString strmTotalQuantity = QString("%1").arg(mTotalQuantity, 0, 'f', 2);
            QString strmTotalSum = QString("%1").arg(mTotalSum, 0, 'f', 2);
            mFootModel->setItem(5,new QStandardItem(strmTotalQuantity));
            mFootModel->setItem(7,new QStandardItem(strmTotalSum));
            mFootView->reset();

        }

    }

    //单据修改
    if(mEditStatus == editFlag){
        QAbstractItemModel *model = ui->tableWidget->model();
        int id = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toInt();
        QString pCode = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"productCode"))).toString();
        double price = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"price"))).toDouble();
        double quantity = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"quantity"))).toDouble();
        QString originNo = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"originNo"))).toString();

        if(item->column() == 4 || item->column()==5){
            if(id < 1 ){
                for(int i =0; i < mAddChildVouchsList.size(); i++){
                    if(mAddChildVouchsList.at(i)->productCode() == pCode){
                        double money = price * quantity;
                        mAddChildVouchsList.at(i)->setOriginNo(originNo);
                        mAddChildVouchsList.at(i)->setQuantity(quantity);
                        mAddChildVouchsList.at(i)->setReQuantity(0);
                        mAddChildVouchsList.at(i)->setInQuantity(0);
                        mAddChildVouchsList.at(i)->setPrice(price);
                        mAddChildVouchsList.at(i)->setMoney(money);
                        mAddChildVouchsList.at(i)->setTaxPrice(price);
                        mAddChildVouchsList.at(i)->setToq(0);
                        mAddChildVouchsList.at(i)->setIsComplete(false);

                    }

                }
            }
        }
        QString name = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"productName"))).toString();
        //单据修改 更新数据
        for(int i =0; i < mChildVouchsList.size(); i++){
            if(mChildVouchsList.at(i)->id() == id){
                double money = price * quantity;
                WidgetBeanUtil::setItemModelToBean(model,item->row(),mChildItem,mChildVouchsList.at(i));
                mChildVouchsList.at(i)->setIsComplete(false);
                mChildVouchsList.at(i)->setMoney(money);

            }
        }

    }
}
