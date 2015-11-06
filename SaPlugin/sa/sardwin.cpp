#include "sardwin.h"
#include "ui_sardwin.h"
#include "haokeapp.h"
#include "bean/DepBean.h"
#include "bean/CustomerBean.h"
#include "bean/CustomerTypeBean.h"
#include "bean/EmployeeBean.h"
#include "bean/WareHouseBean.h"
#include "bean/ProductBean.h"
#include "bean/SystemSetBean.h"
#include "bean/SupplieTypeBean.h"
#include "bean/SaPriceBean.h"
#include "bean/StockBean.h"
#include "bean/DefineBean.h"
#include "dao/commondao.h"
#include "dao/depdao.h"
#include "dao/CustomerDAO.h"
#include "dao/customertypedao.h"
#include "dao/supplietypedao.h"
#include "dao/employeedao.h"
#include "dao/waredao.h"
#include "dao/productdao.h"
#include "dao/saorderdao.h"
#include "dao/rddao.h"
#include "dao/sapricedao.h"
#include "dao/systemsetdao.h"
#include "common/itemutil.h"
#include "common/cachebabeancommon.h"
#include "common/printutils.h"
#include "qtrpt.h"
#include "bean/ReportFormatBean.h"
#include "dao/reportdao.h"
#include "widget/designoptdialog.h"
#include "widget/choosevouchdialog.h"
#include "widget/optinvdialog.h"
#include "bean/SaDispatchVouchsBean.h"
#include "bean/StockBean.h"
#include "dao/sadispatchdao.h"
#include "dao/stockdao.h"
#include "dao/sarddao.h"
#include "saplugin.h"

SaRdWin::SaRdWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaRdWin)
{
    ui->setupUi(this);
    mRdFlag = RdFlag::RdOutFlag;
    mVouchType = HaoKeApp::getVouchRdSaOut();
    init();
    //qApp->setStyle("Plastique");
    setupContextMenu();
    mCountRecord = RdDAO::getRdCount(mVouchType) - 1;
    if(mCountRecord < 0) mCountRecord = 0;
    mRecord = mCountRecord;
    QList<RdBean *> rdBeanList = RdDAO::queryRdByPage(mVouchType,mCountRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
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

SaRdWin::SaRdWin(QString no,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaRdWin)
{
    ui->setupUi(this);
    RdBean *bean = RdDAO::getRdByNo(no);

    if(bean != NULL && bean->rdNo().length() > 0){
        mRdFlag = bean->rdFlag();
        if(bean->vouchType() == HaoKeApp::getVouchRdSaRe())
            mRdRed = RdFlag::RdInFlag;
        mVouchType = bean->vouchType();

        init();
        //qApp->setStyle("Plastique");
        setupContextMenu();
        mCountRecord = RdDAO::getRdCount(mVouchType) - 1;
        if(mCountRecord < 0) mCountRecord = 0;
        ui->toolBar->actions().at(0)->setEnabled(true);
        ui->toolBar->actions().at(1)->setEnabled(true);
        ui->toolBar->actions().at(7)->setEnabled(true);

        mRecord = RdDAO::getRdRowNumber(mVouchType,bean->id()) - 1;
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
        init();
        QMessageBox::critical(this,"错误","此单不存在！");
    }
    readAuthority();

}

SaRdWin::SaRdWin(int rdf, QString vouchType,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaRdWin)
{
    ui->setupUi(this);
    mVouchType = vouchType;
    mRdRed = rdf;
    init();

    //qApp->setStyle("Plastique");
    setupContextMenu();
    mCountRecord = RdDAO::getRdCount(mVouchType) - 1;
    if(mCountRecord < 0) mCountRecord = 0;
    mRecord = mCountRecord;
    QList<RdBean *> rdBeanList = RdDAO::queryRdByPage(mVouchType,mCountRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
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
SaRdWin::~SaRdWin()
{
    delete ui;
}

void SaRdWin::readAuthority(){
    LimitsCommon::authority(ui->toolBar,mWinId.toInt());
}

void SaRdWin::init(){
    QApplication::setOverrideCursor(Qt::WaitCursor);
    //窗体ID号
    mWinId = HaoKeApp::saSubId()+ SaPlugin::rdWinId();
    mWinTitle = "销售出库单";
    mRdFlag = RdFlag::RdOutFlag;
    //02 销售出库单 查看vouch_type表
    mVouchSource = "";
    ui->rdLabel->setText("");
    if(mRdRed == RdFlag::RdInFlag){
        //15销售退货单
        //mVouchType = HaoKeApp::getVouchRdSaRe();
        mWinId = HaoKeApp::saSubId()+ SaPlugin::hRdWinId();
        mWinTitle = "销售红字出库";
        ui->arrivalLabel->setText("退货单号");
        ui->rdLabel->setText("<html><head/><body><p><span style=\" color:#ff0000;\">红字出库</span></p></body></html>");
        ui->label_16->setText("<html><head/><body><p><span style=\" color:#ff0000;\">销售出库单</span></p></body></html>");
    }
    //初始化表头数据
    QStringList  busTypeList;
    if(mRdRed == RdFlag::RdInFlag){
        busTypeList << "销售退货" ;
    }else{
        busTypeList << "普通销售";
        busTypeList << "特价销售" << "计划销售" ;
    }
    if(mVouchType == HaoKeApp::getVouchRdCtOut()){
        mWinId = HaoKeApp::saSubId()+ SaPlugin::conRdWinId();
        mWinTitle = "委托代销出库";
        ui->label_16->setText("委托代销出库单");
        busTypeList.clear();
        busTypeList << "委托代销";

    }else if(mVouchType == HaoKeApp::getVouchRdCtRe()){
        mWinId = HaoKeApp::saSubId()+ SaPlugin::hConRdWinId();
        mWinTitle = "委托代销出库红字出库";
        ui->label_16->setText("<html><head/><body><p><span style=\" color:#ff0000;\">委托代销出库单</span></p></body></html>");
        busTypeList.clear();
        busTypeList << "委托代销退货";
    }
    ui->busTypeComboBox->addItems(busTypeList);
    QList<CustomerBean *> cusBeanList = CustomerDAO::queryCus();
    QStringList venList ;
    for(int i =0 ; i < cusBeanList.size(); i++){
        venList << cusBeanList.at(i)->cusCode() + " - " +cusBeanList.at(i)->cusName();
    }
    ui->cusSearchEditbox->setListModel(true);
    ui->cusSearchEditbox->setItems(venList);
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::puSubId().toInt(),mWinId.toInt(),0,"");

    //功能菜单
    actionProperties actsBase[]= {
        { "saRd.new",tr("&New"),SLOT(sNew()), NULL, "New", QPixmap(":/image/Add.png"), NULL,  true, tr("New") },
        { "saRd.edit",tr("&Edit"),SLOT(sEdit()), NULL, "Edit", QPixmap(":/image/edit.png"), NULL,  true, tr("Edit") },
        { "saRd.delete",tr("&Delete"),SLOT(sDelete()), NULL, "Delete", QPixmap(":/image/cross_48.png"), NULL,  true, tr("Delete") },
        { "saRd.save",tr("&Save"),SLOT(sSave()), NULL, "Save", QPixmap(":/image/save.png"), NULL,  true, tr("Save") },
        { "saRd.audit",tr("&Audit"),SLOT(sAudit()), NULL, "Audit", QPixmap(":/image/stamp_48.png"), NULL,  true, tr("Audit") },
        { "saRd.abandonAudit",tr("&Abandon Audit"),SLOT(sAbAudit()), NULL, "Abandon Audit", QPixmap(":/image/c_stamp_48.png"), NULL,  true, tr("Abandon Audit") },
        { "saRd.delRow",tr("&DelRow"),SLOT(sDelRow()), NULL, "DelRow", QPixmap(":/image/minus.png"), NULL,  true, tr("DelRow") },
        { "saRd.print",tr("&Print"),SLOT(sPrint()), NULL, "Print", QPixmap(":/image/printer.png"), NULL,  true, tr("Print") },
        { "saRd.choose",tr("&Choose"),SLOT(sChoose()), NULL, "Choose", QPixmap(":/image/page_accept.png"), NULL,  true, tr("Choose") },
        { "saRd.first",tr("&First"),SLOT(sFirst()), NULL, "First", QPixmap(":/image/first48.png"), NULL,  true, tr("First") },
        { "saRd.next",tr("&Next"),SLOT(sNext()), NULL, "Next", QPixmap(":/image/n-next48.png"), NULL,  true, tr("Next") },
        { "saRd.previous",tr("&Previous"),SLOT(sPrevious()), NULL, "Previous", QPixmap(":/image/n-previous48.png"), NULL,  true, tr("Previous") },
        { "saRd.end",tr("&End"),SLOT(sEnd()), NULL, "End", QPixmap(":/image/end48.png"), NULL,  true, tr("End") },
        { "saRd.cancel",tr("&Cancel"),SLOT(sCancel()), NULL, "Cancel", QPixmap(":/image/cancel.png"), NULL,  true, tr("Cancel") }

    };
    addActionsTo(actsBase,sizeof(actsBase) / sizeof(actsBase[0]));

    mIsEdit =false;

    ui->dateEdit->setDate(HaoKeApp::getInstance()->getOperateDate());
    mIsChoose = false;

    mIsHathOrder = false; //销售业务必有订单
    mIsMakeRd = false; //审核是否生成出库单
    mOverTop = false;
    SystemSetBean *hathOrderBean = SystemSetDAO::getBean("601");
    if(hathOrderBean && hathOrderBean->id().length() > 0){
        mIsHathOrder = hathOrderBean->yesNo();
    }

    SystemSetBean *makeRdBean = SystemSetDAO::getBean("602");
    if(makeRdBean && makeRdBean->id().length() > 0){
        mIsMakeRd = makeRdBean->yesNo();
    }

    SystemSetBean *overBean = SystemSetDAO::getBean("603");
    if(overBean && overBean->id().length() > 0){
        mOverTop = overBean->yesNo();
    }
    //初始化表体格式
    setInputEnable(false);

    childItemProperties childItem[] = {
            { "productCode","商品编码","商品编码", 0,180, true, true },
            { "productName","商品名称","商品名称", 1,180, true, true },
            { "productStyle","商品规格","商品规格", 2,80, true, false },
            { "unit","单位","单位", 3,80, true, false },
            { "quantity","数量","数量", 4, 60,true, true },
            { "unitPrice","销售单价","销售单价", 5,80, true, true },
            { "money","销售金额","销售金额", 6,80, true, false },
            { "id","ID","ID", 7,60, false, false },
            { "busNo","发货单单号","发货单单号", 8,100, false, false },
            { "orderNo","销售订单号","销售订单号", 9,100, false, false },
        { "define1","自定义1","自定义1", 10,100, false, true },
        { "define2","自定义2","自定义2", 11,100, false, true },
        { "define3","自定义3","自定义3", 12,100, false, true },
        { "define4","自定义4","自定义4", 13,100, false, true },
        { "define5","自定义5","自定义5", 14,100, false, true },
        { "define6","自定义6","自定义6", 15,100, false, true },
        { "memo","备注","备注", 16,160, false, true }
    };
    //mChildItem << childItem[0] << childItem[1] << childItem[2] << childItem[3] << childItem[4] << childItem[5] << childItem[6] << childItem[7] << childItem[8] << childItem[9];
    int size = sizeof(childItem) / sizeof(childItem[0]);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(size);
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
    mFootModel->setItem(size - 1,new QStandardItem(""));
    mFootModel->setItem(size - 2,new QStandardItem(""));
    ui->verticalLayout_2->addWidget(mFootView);
    mFootModel->setItem(7,new QStandardItem(""));
    QObject::connect(ui->tableWidget->horizontalHeader(),SIGNAL(sectionResized(int,int,int)),this,SLOT(footResized(int,int,int)));
    refreshData();
    /*
    ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    */
    mFootView->setDefaultAlignment (Qt::AlignLeft | Qt::AlignVCenter);
    mFootView->setTextElideMode (Qt::ElideLeft); //...效果




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
    QApplication::restoreOverrideCursor();
}

void SaRdWin::sInvClick(){

    QString sql = " SELECT b.wh_name,a.*,a.sum-a.c_sum+a.r_sum as k_sum,c.style FROM st_stock_query a, ba_ware_house b , ba_product c"
            " WHERE a.wh_code=b.wh_code AND a.product_code=c.product_code "
            " AND a.wh_code LIKE ? AND a.product_code LIKE ? AND c.type_id LIKE ? ";
    childItemProperties childItem[] = {
            { "product_code","编码商品","商品", 0,60, true, true },
            { "product_name","商品名称","商品", 1,100, true, true },
            { "style","商品规格","商品", 2,100, true, true },
            { "wh_name","名称仓库","仓库", 3,80, true, true },
            { "sum","现存量","现存量", 4, 60,true, true },
            { "r_sum","待入库","待入库", 5, 60,true, true },
            { "c_sum","待出库","待出库", 6, 60,true, true },
            { "k_sum","可发量","可发量", 7,60, true, true }
    };

    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }
    QString whCode = ui->whSearchEditbox->text() + " - " + ui->whSearchEditbox->subText();
    QString invCode = "";
    OptInvDialog *invDlg = new OptInvDialog(dItem,sql,whCode,invCode,this);
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
void SaRdWin::footResized(int logicalIndex, int oldSize, int newSize){
    mFootView->resizeSection(logicalIndex + 1,newSize);
    mFootView->resizeSection(0,ui->tableWidget->verticalHeader()->width());
}
void SaRdWin::refreshData(){

    QStringList headerLabels;
    for (int i = 0; i < mChildItem.size(); i++){
        headerLabels.append(mChildItem[i].cnName);
        ui->tableWidget->setColumnWidth(mChildItem[i].id,mChildItem[i].width);
        mFootView->resizeSection(mChildItem[i].id + 1,mChildItem[i].width);
        if(!mChildItem[i].visible)ui->tableWidget->hideColumn(mChildItem[i].id);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
}

void SaRdWin::read(QString no){
    RdBean *bean = RdDAO::getRdByNo(no);
    mNo = no;
    if(bean != NULL && bean->rdNo().length() > 0){
        ui->noEdit->setText(bean->rdNo());
        ui->dateEdit->setDate(bean->busDate());
        CustomerBean *cusBean = CustomerDAO::getCusByCode(bean->cusCode());
        ui->cusSearchEditbox->setText(bean->cusCode() + " - " + cusBean->cusName());
        WareHouseBean *whBean = WareDAO::getWarehouseById(bean->whCode());
        ui->whSearchEditbox->setText(bean->whCode() + " - " + whBean->whName());;
        DepBean *depBean = DepDAO::getDepById(bean->depCode());
        ui->depSearchEditbox->setText(bean->depCode() + " - " + depBean->depName());
        ui->userSearchEditbox->setText(bean->personCode() + " - " + CacheBaBeanCommon::personToName(bean->personCode()));
        ui->memoEdit->setText(bean->memo());
        ui->makerEdit->setText(CacheBaBeanCommon::userToName(bean->createdBy(),1));
        ui->auditEdit->setText(bean->handler());
        ui->dispatchNoEdit->setText(bean->busNo());
        for(int i = 0; i < ui->busTypeComboBox->count(); i++){
            if(bean->busType() == ui->busTypeComboBox->itemText(i)){
                ui->busTypeComboBox->setCurrentIndex(i);
            }
        }
        ui->toolBar->actions().at(0)->setEnabled(true);
        ui->toolBar->actions().at(1)->setEnabled(true);
        ui->toolBar->actions().at(3)->setEnabled(false);
        ui->toolBar->actions().at(6)->setEnabled(false);
        ui->toolBar->actions().at(8)->setEnabled(false);

        if(bean->handler().length() > 1){
            ui->toolBar->actions().at(4)->setEnabled(false);
            ui->toolBar->actions().at(5)->setEnabled(true);
        }else{
            ui->toolBar->actions().at(4)->setEnabled(true);
            ui->toolBar->actions().at(5)->setEnabled(false);
        }
        QList<RdsBean *> pBeanList = RdDAO::queryRdsBy(no);
        mChildVouchsList = RdDAO::queryRdsBy(no);
        ui->tableWidget->setRowCount(pBeanList.size() + 1);
        mTotalQuantity = 0;
        mTotalSum = 0;
        for(int i =0; i < pBeanList.size(); i++){
            WidgetBeanUtil::setBeanToTableWidget(ui->tableWidget,i,mChildItem,pBeanList.at(i));
            mTotalQuantity = mTotalQuantity + pBeanList.at(i)->quantity();
            mTotalSum = mTotalSum + pBeanList.at(i)->money();
        }

        mFootModel->setItem(5,new QStandardItem(QString::number(mTotalQuantity,'f',2)));
        mFootModel->setItem(7,new QStandardItem(QString::number(mTotalSum,'f',2)));
        mFootView->resizeSection(0,ui->tableWidget->verticalHeader()->width());
        mFootView->reset();
        readAuthority();
    }
}

void SaRdWin::inputClear(){
    WidgetBeanUtil::clearLayoutWidgetData(ui->headGridLayout);


}

void SaRdWin::setInputEnable(bool b){
     WidgetBeanUtil::setLayoutWidgetEnable(ui->headGridLayout,b);
     if(b){
         ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);
     }else{
         ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
     }
}

void SaRdWin::addActionsTo(actionProperties acts[], unsigned int numElems){
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
            act->setEnabled(false);
            ui->toolBar->addAction(act);
            addAction(act);
            QString proceccId = mWinId + QString::number(i);
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::saSubId().toInt(),mWinId.toInt(),proceccId.toInt(),acts[i].toolTip,acts[i].actionName);

        }
        else
            baseToolBar->addAction(act);
    }

    connect(ui->toolBar, SIGNAL(actionTriggered(QAction*)), this, SLOT(toolBarActTriggered(QAction*)));
}

void SaRdWin::toolBarActTriggered(QAction *act){
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::saSubId().toInt(),mWinId.toInt(),act->objectName());

}

void SaRdWin::sFirst(){
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
    QList<RdBean *> rdBeanList = RdDAO::queryRdByPage(mVouchType,0,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
        mNo = rdBeanList.at(0)->rdNo();
    }
    baseToolBar->actions().at(0)->setEnabled(false);
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(2)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(true);
}
\
void SaRdWin::sNext(){
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
    QList<RdBean *> rdBeanList = RdDAO::queryRdByPage(mVouchType,mRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
    }
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(0)->setEnabled(true);
}

void SaRdWin::sPrevious(){
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
    QList<RdBean *> rdBeanList = RdDAO::queryRdByPage(mVouchType,mRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
    }
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(true);
}

void SaRdWin::sEnd(){
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
    mCountRecord = RdDAO::getRdCount(mVouchType) - 1;
    mRecord = mCountRecord;
    QList<RdBean *> rdBeanList = RdDAO::queryRdByPage(mVouchType,mCountRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
    }
    baseToolBar->actions().at(0)->setEnabled(true);
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(false);
}

void SaRdWin::sNew(){
    inputClear();
    mIsEdit = true;
    mEditStatus = addFlag;
    setInputEnable(true);
    ui->dateEdit->setDate(HaoKeApp::getInstance()->getOperateDate());
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
    mNo = ItemUtil::getToDayMaxRdNo(QDate::currentDate());
    ui->noEdit->setText(mNo);
    refreshData();

    mTotalQuantity = 0;
    mTotalSum = 0;

    mFootModel->setItem(5,new QStandardItem(QString::number(mTotalQuantity)));
    mFootModel->setItem(7,new QStandardItem(QString::number(mTotalSum)));
    mFootView->reset();
    readAuthority();
}

void SaRdWin::sEdit(){
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
    ui->toolBar->actions().at(8)->setEnabled(false);
    readAuthority();
}

void SaRdWin::sSave(){
    if(ui->noEdit->text().length()< 1){
        QMessageBox::warning(this,"提示","出错，此单号为空，不能保存");
        return ;
    }
    mNo = ui->noEdit->text();
    QAbstractItemModel *model = ui->tableWidget->model();
    int rowNum = model->rowCount() -1;
    if(rowNum == 0){
        QMessageBox::warning(this,"提示","无数据，不能保存");
        return;
    }

    if(ui->cusSearchEditbox->text().trimmed().length() < 1){
        QMessageBox::warning(this,"提示","请输入客户");
        return ;
    }
    if(ui->whSearchEditbox->text().trimmed().length() < 1){
        QMessageBox::warning(this,"提示","请输入仓库");
        return ;
    }
    for(int i = 0;i < rowNum; i++){
        QString pCode = model->data(model->index(i,0)).toString();
        ProductBean *pBean = ProductDAO::getProductByCode(pCode);
        if(mRdFlag == RdFlag::RdInFlag){
            double quantity = model->data(model->index(i,4)).toDouble();
            if(quantity > 0){
                QMessageBox::information(this,"提示","红字出库,此商品：" + pCode + " ,数量要为负！");
                return ;
            }

        }
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

    if(!mOverTop && mRdRed != RdFlag::RdInFlag){
        QList<StockBean *> stockList = SaRdDAO::queryStockBy(ui->whSearchEditbox->text());
        for(int i = 0;i < rowNum; i++){
            RdsBean *rdsBean = new RdsBean();
            rdsBean->setRdNo(mNo);
            WidgetBeanUtil::setItemModelToBean(model,i,mChildItem,rdsBean);
            bool isTop = true;
            double topSum= 0 ;
            for(int j = 0 ; j < stockList.size() ; j ++){

                if(stockList.at(j)->productCode() == rdsBean->productCode() ){
                    topSum = stockList.at(j)->canSum();
                    if(topSum-rdsBean->quantity()>=0){
                        isTop = false;
                        break ;
                    }
                }
            }
            if(isTop){
                QMessageBox::information(this,"提示","此" + rdsBean->productName()
                                         + " 库存不足,可发货量为:"+ QString::number(topSum) + " 不能保存");
                return ;
            }


        }
    }
    if(mEditStatus == addFlag){
        if(RdDAO::getRdCountByNo(ui->noEdit->text()) > 0){
            QMessageBox::warning(this,"提示","出错，此单号重复，不能保存，重新生成新单号");
            mNo = ItemUtil::getToDayMaxRdNo(QDate::currentDate());
            ui->noEdit->setText(mNo);
            return ;
        }
        mNo = ui->noEdit->text();
        RdBean *bean = new RdBean();
        bean->setRdNo(ui->noEdit->text());
        bean->setRdFlag(mRdFlag);
        bean->setBusNo(ui->dispatchNoEdit->text().trimmed());
        bean->setBusDate(ui->dateEdit->date());
        bean->setBusType(ui->busTypeComboBox->currentText());
        bean->setCusCode(ui->cusSearchEditbox->text());
        bean->setWhCode(ui->whSearchEditbox->text());
        bean->setDepCode(ui->depSearchEditbox->text());
        bean->setBusNo(ui->dispatchNoEdit->text());
        //bean->setOrderNo(ui->oNoEdit->text());
        bean->setVouchType(mVouchType);
        bean->setPersonCode(ui->userSearchEditbox->text());
        QDateTime time = QDateTime::currentDateTime();
        bean->setCreated(time);
        bean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        bean->setCreater(HaoKeApp::getInstance()->getUserDesc());
        bean->setHandler("");
        bean->setIsHandle(false);
        bean->setIsBill(false);
        bean->setImeiAudit(false);
        bean->setStatus(0);
        bean->setMemo(ui->memoEdit->text());
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = 0;
        mResult = RdDAO::createRd(bean);
        int cResult = 0;
        double d_val = 0;
        for(int i = 0;i < rowNum; i++){
            RdsBean *rdsBean = new RdsBean();
            rdsBean->setRdNo(ui->noEdit->text());
            WidgetBeanUtil::setItemModelToBean(model,i,mChildItem,rdsBean);
            rdsBean->setAMoney(d_val);
            int c = RdDAO::createRds(rdsBean);
            if(c < 1){
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"提示","此" + rdsBean->productCode() + " 数据提交出错,不能保存");
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
            ui->makerEdit->setText(CacheBaBeanCommon::userToName(HaoKeApp::getInstance()->getUserId(),1));
            setInputEnable(false);

            mCountRecord = RdDAO::getRdCount(mVouchType) - 1;
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
        RdBean *bean = RdDAO::getRdByNo(ui->noEdit->text());
        if(bean && bean->isHandle()){
            QMessageBox::warning(this,"提示","此单已审核，不能修改");
            return ;
        }
        bean->setRdNo(ui->noEdit->text());

        bean->setBusDate(ui->dateEdit->date());
        bean->setBusType(ui->busTypeComboBox->currentText());

        bean->setCusCode(ui->cusSearchEditbox->text());
        bean->setDepCode(ui->depSearchEditbox->text());
        bean->setPersonCode(ui->userSearchEditbox->text());
        bean->setWhCode(ui->whSearchEditbox->text());
        bean->setMemo(ui->memoEdit->text());

        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = 0;
        mResult = RdDAO::updateRd(bean);
        int cResult = 0;
        //删除
        for(int i = 0; i < mDelChildList.size(); i++){
            RdsBean *delBean = new RdsBean;
            delBean->setId(mDelChildList.at(i));
            int c = RdDAO::delRds(delBean);
            cResult = cResult + c;
        }
        //更新
        for(int i = 0; i < mChildVouchsList.size(); i++){
            int c = RdDAO::updateRds(mChildVouchsList.at(i));
            cResult = cResult + c;
        }
        //添加
        for(int i = 0; i < mAddChildVouchsList.size(); i++){
            int c = RdDAO::createRds(mAddChildVouchsList.at(i));
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

void SaRdWin::sDelete(){
    if(ui->auditEdit->text().length() > 0){
        QMessageBox::warning(this,"提示","已审核，不能删除！");
        return ;
    }

    if(QMessageBox::warning(this,"提示","是否删除？",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){

        RdBean *bean = RdDAO::getRdByNo(ui->noEdit->text());
        bean->setRdNo(ui->noEdit->text());
        if(bean->isHandle()){
            QMessageBox::warning(this,"提示",bean->handler() + " 已审核，不能删除！");
            return ;
        }
        if(bean->imeiAudit()){
            QMessageBox::information(this,"提示","串码已审核，不能删除！");
            return ;
        }

        int imeiCount = SaRdDAO::getRdImeiCount(ui->noEdit->text());
        if(imeiCount > 0){
            QMessageBox::information(this,"提示","存在串码记录,不能删除！,请在串码系统中删除记录！");
            return ;
        }
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = RdDAO::delRdByNo(bean);
        int cResult = RdDAO::delRdsByNo(ui->noEdit->text());
        if(mResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            mIsEdit =false;
            setInputEnable(false);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            if(mRecord ==0){
                sNext();
            }else sPrevious();
            mCountRecord = RdDAO::getRdCount(mVouchType) - 1;
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::critical(this,"错误","删除出错");

        }

    }
    readAuthority();
}

void SaRdWin::sDelRow(){
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

void SaRdWin::sAudit(){
    RdBean *bean = RdDAO::getRdByNo(ui->noEdit->text());

    if(bean && bean->rdNo().length() > 0){
        if(bean->isHandle()==NULL && bean->isHandle()){
            ui->toolBar->actions().at(4)->setEnabled(false);
            ui->toolBar->actions().at(5)->setEnabled(true);
            QMessageBox::information(this,"提示","已审核，不能再审核！");
            return ;
        }
        QList<RdsBean *> mChildRdsList = RdDAO::queryRdsBy(ui->noEdit->text());

        if(!mOverTop && mRdRed != RdFlag::RdInFlag){
            QList<StockBean *> stockList = SaRdDAO::queryStockBy(ui->whSearchEditbox->text());
            for(int i = 0; i < mChildRdsList.size(); i++){

                bool isTop = true;
                double topSum= 0 ;
                for(int j = 0 ; j < stockList.size() ; j ++){

                    if(stockList.at(j)->productCode() == mChildRdsList.at(i)->productCode() ){
                        topSum = stockList.at(j)->sum();
                        if(topSum-mChildRdsList.at(i)->quantity()>=0){
                            isTop = false;
                            break ;
                        }
                    }
                }
                if(isTop){
                    QMessageBox::information(this,"提示","此" + mChildRdsList.at(i)->productName()
                                             + " 库存不足,可发货量为:"+ QString::number(topSum) + " 不能保存");
                    return ;
                }


            }
        }
        bean->setHandler(CacheBaBeanCommon::userToName(HaoKeApp::getInstance()->getUserId(),1));
        bean->setAuditTime(QDateTime::currentDateTime());
        bean->setIsHandle(true);
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int cResult = 0;
        for(int i = 0; i < mChildRdsList.size(); i++){
            ProductBean *pBean = ProductDAO::getProductByCode(mChildRdsList.at(i)->productCode());
            if(pBean != NULL &&  pBean->productCode().length() > 0 ){
                StockBean *sBean = StockDAO::getStockBy(bean->whCode(),pBean->productCode());
                double sum = 0;
                if( pBean->stDoUnit() <= 0)
                    sum = mChildRdsList.at(i)->quantity();
                else sum = mChildRdsList.at(i)->quantity() * pBean->stDoUnit();
                if(sBean != NULL && sBean->productCode().length() > 0){
                    //出库减少库存
                    sBean->setSum(sBean->sum() - sum);
                    int c = StockDAO::updateStock(sBean);
                    if(c < 1){
                        DBManager::getDBManager()->getGoinDBConnection().rollback();
                        QMessageBox::information(this,"提示","审核出错！更新库存");
                        return ;
                    }
                    cResult = cResult + c;
                }else{
                    StockBean *stBean = new StockBean;
                    stBean->setWhCode(bean->whCode());
                    stBean->setPositionCode(bean->positionCode());
                    stBean->setProductCode(mChildRdsList.at(i)->productCode());
                    stBean->setStyle(pBean->style());
                    stBean->setUnit(pBean->stockUnit());
                    stBean->setSum(sum);
                    stBean->setCanSum(0);
                    stBean->setReadySum(0);
                    stBean->setStatus(0);
                    int c = StockDAO::createStock(stBean);
                    if(c < 1){
                        DBManager::getDBManager()->getGoinDBConnection().rollback();
                        QMessageBox::information(this,"提示","审核出错！增加库存");
                        return ;
                    }
                    cResult = cResult + c;

                }
            }else{
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"提示","审核出错！" + mChildRdsList.at(i)->productCode() + " 原料不存在");
                return ;
            }
        }
        int result = RdDAO::updateRd(bean);
        if(result > 0 && cResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            ui->auditEdit->setText(bean->handler());
            ui->toolBar->actions().at(4)->setEnabled(false);
            ui->toolBar->actions().at(5)->setEnabled(true);
            readAuthority();
            QMessageBox::information(this,"提示","审核成功！");
        }else{
            QMessageBox::information(this,"提示","审核出错！");
        }

    }else{
        QMessageBox::critical(this,"错误","无此单据，不能审核");
    }
}

void SaRdWin::sAbAudit(){
    RdBean *bean = RdDAO::getRdByNo(ui->noEdit->text());
    if(bean !=NULL && bean->rdNo().length() > 0){
        if(bean->accounter().length()>2 ){
            QMessageBox::information(this,"提示","单据已记帐，不能弃审！");
            return ;
        }
        if(!bean->isHandle()){
            ui->toolBar->actions().at(4)->setEnabled(true);
            ui->toolBar->actions().at(5)->setEnabled(false);
            QMessageBox::information(this,"提示","未审核，不能弃审！");
            return ;
        }
        if(bean->imeiAudit()){
            QMessageBox::information(this,"提示","串码已审核，不能弃审！");
            return ;
        }
        int imeiCount = SaRdDAO::getRdImeiCount(ui->noEdit->text());
        if(imeiCount > 0){
            QMessageBox::information(this,"提示","存在串码记录,不能弃审！,请在串码系统中删除记录！");
            return ;
        }
        bean->setHandler("");
        bean->setIsHandle(false);
        int cResult = 0;
        QList<RdsBean *> mChildRdsList = RdDAO::queryRdsBy(ui->noEdit->text());
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        for(int i = 0; i < mChildRdsList.size(); i++){
            ProductBean *pBean = ProductDAO::getProductByCode(mChildRdsList.at(i)->productCode());
            if(pBean != NULL && pBean->productCode().length() > 0 ){
                StockBean *sBean = StockDAO::getStockBy(bean->whCode(),pBean->productCode());
                double sum = 0;
                if( pBean->stDoUnit() <= 0)
                    sum = mChildRdsList.at(i)->quantity();
                else sum = mChildRdsList.at(i)->quantity() * pBean->stDoUnit();
                if(sBean != NULL && sBean->productCode().length() > 0){
                    //增加库存
                    sBean->setSum(sBean->sum() + sum);
                    int c = StockDAO::updateStock(sBean);
                    if(c < 1){
                        DBManager::getDBManager()->getGoinDBConnection().rollback();
                        QMessageBox::information(this,"提示","弃审出错！更新库存");
                        return ;
                    }
                    cResult = cResult + c;
                }else{

                    DBManager::getDBManager()->getGoinDBConnection().rollback();
                    QMessageBox::information(this,"提示","弃审出错！库存中不存在些原料 " + pBean->productCode());
                    return ;


                }
            }else{
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"提示","弃审出错！" + mChildRdsList.at(i)->productCode() + " 原料不存在");
                return ;
            }
        }
        int result = RdDAO::updateRd(bean);
        if(result > 0 && cResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            ui->auditEdit->setText(bean->handler());
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(4)->setEnabled(true);
            ui->toolBar->actions().at(5)->setEnabled(false);
            readAuthority();
            QMessageBox::information(this,"提示","弃审成功！");
        }else{
            QMessageBox::information(this,"提示","弃审出错！");
        }

    }
}

void SaRdWin::sChoose(){
    if(ui->cusSearchEditbox->text().trimmed().length() < 1){
        QMessageBox::warning(this,"提示","请输入客户");
        return ;
    }
    ChooseVouchDialog *cVouchDlg = new ChooseVouchDialog(this);
    cVouchDlg->setWindowTitle("提取销售发货单");

    childItemProperties childItem[] = {
            { "no","发货单号","发货单号", 0,100, true, true },
            { "bus_date","发货日期","发货日期", 1,80, true, true },
            { "pu_type","销售类型","销售类型", 2,80, true, false },
            { "supplier_id","客户编码","客户编码", 3,80, true, false },
            { "supplie_name","客户名称","客户名称", 4, 120,true, true },


    };

    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }

    QList<CustomerBean *> cusBeanList = CustomerDAO::queryCus();
    QStringList venList ;
    for(int i =0 ; i < cusBeanList.size(); i++){
        venList << cusBeanList.at(i)->cusCode() + " - " +cusBeanList.at(i)->cusName();
    }
    cVouchDlg->dwNameQks->setListModel(true);
    cVouchDlg->dwNameQks->setItems(venList);
    CustomerBean *cusBean = CustomerDAO::getCusByCode(ui->cusSearchEditbox->text());
    cVouchDlg->dwNameQks->setText(cusBean->cusCode() + " - " + cusBean->cusName());

    QList<CustomerTypeBean *> typeBeanList = CustomerTypeDAO::queryType();
    QStringList typeList ;
    for(int i =0 ; i < typeBeanList.size(); i++){
        typeList << typeBeanList.at(i)->typeId() + " - " +typeBeanList.at(i)->typeName();
    }
    cVouchDlg->dwTypeQks->setListModel(true);
    cVouchDlg->dwTypeQks->setItems(typeList);
    cVouchDlg->proNameQks->setVisible(false);
    cVouchDlg->proTypeQks->setVisible(false);
    cVouchDlg->proNameLabel->setVisible(false);
    cVouchDlg->proTypeLabel->setVisible(false);
    QString sql = " SELECT a.*,b.cus_name FROM sa_dispatch_vouch a ,ba_customer b WHERE "
            " no not in(SELECT bus_no FROM rd_record WHERE vouch_type='02') AND a.is_handle=true AND a.bus_type='01' "
            " AND a.cus_code=b.cus_code "
            " AND a.bus_date>=? AND a.bus_date<=? AND b.cus_type like ? AND a.cus_code like ? "
            " ORDER BY id ASC";
    if(mRdFlag == RdFlag::RdOutFlag){
        sql = " SELECT a.*,b.cus_name FROM sa_dispatch_vouch a ,ba_customer b WHERE "
                    " no not in(SELECT bus_no FROM rd_record WHERE vouch_type='15') AND a.is_handle=true AND a.bus_type='02' "
                    " AND a.cus_code=b.cus_code "
                    " AND a.bus_date>=? AND a.bus_date<=? AND b.cus_type like ? AND a.cus_code like ? "
                    " ORDER BY id ASC";
    }
    if(mVouchType== HaoKeApp::getVouchRdCtOut()){
        sql = " SELECT a.*,b.cus_name FROM sa_dispatch_vouch a ,ba_customer b WHERE "
                    " no not in(SELECT bus_no FROM rd_record WHERE vouch_type='11') AND a.is_handle=true AND a.bus_type='03' "
                    " AND a.cus_code=b.cus_code "
                    " AND a.bus_date>=? AND a.bus_date<=? AND b.cus_type like ? AND a.cus_code like ? "
                    " ORDER BY id ASC";
    }else if(mVouchType == HaoKeApp::getVouchRdCtRe()){
        sql = " SELECT a.*,b.cus_name FROM sa_dispatch_vouch a ,ba_customer b WHERE "
                    " no not in(SELECT bus_no FROM rd_record WHERE vouch_type='12') AND a.is_handle=true AND a.bus_type='04' "
                    " AND a.cus_code=b.cus_code "
                    " AND a.bus_date>=? AND a.bus_date<=? AND b.cus_type like ? AND a.cus_code like ? "
                    " ORDER BY id ASC";
    }
    cVouchDlg->initData(dItem,sql);
    cVouchDlg->initTableHead();

    if(cVouchDlg->exec() == QDialog::Accepted){
        QItemSelectionModel *selectionModel = cVouchDlg->tableView->selectionModel();
        QModelIndexList selected= selectionModel->selectedIndexes();
        if(selected.size()<1){
            QMessageBox::information(this,"提示","未提取数据");

        }else{
            ui->tableWidget->clear();
            ui->tableWidget->setRowCount(1);
            refreshData();
            QAbstractItemModel *modelChoose = cVouchDlg->tableView->model();
            QString dispatchNo = modelChoose->data(modelChoose->index(selected.at(0).row(),0)).toString();
            QString venCode = modelChoose->data(modelChoose->index(selected.at(0).row(),3)).toString();
            QString venName = modelChoose->data(modelChoose->index(selected.at(0).row(),4)).toString();
            QList<SaDispatchVouchsBean *> beanLists = SaDispatchDAO::querySaDispatchVouchsByNo(dispatchNo);
            mIsChoose = true;
            ui->cusSearchEditbox->setText(venCode + " - " + venName);
            ui->dispatchNoEdit->setText(dispatchNo);
            if(mRdFlag == RdFlag::RdOutFlag)
                ui->memoEdit->setText("提取退货单生成,单号:" + dispatchNo);
            else ui->memoEdit->setText("提取发货单生成,单号:" + dispatchNo);
            SystemSetBean *useDefineBean = SystemSetDAO::getBean("101");
            for(int i = 0 ; i < beanLists.size(); i ++ ){
                WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"productCode",beanLists.at(i)->productCode());
                WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"price",beanLists.at(i)->price());
                if(mRdFlag == RdFlag::RdOutFlag){
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"quantity",-beanLists.at(i)->quantity());
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"money",-beanLists.at(i)->money());

                }else{
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"quantity",beanLists.at(i)->quantity());
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"money",beanLists.at(i)->money());
                }
                WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"orderNo",beanLists.at(i)->orderNo());
                WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"busNo",beanLists.at(i)->dispatchNo());

                if(useDefineBean && useDefineBean->id().length() > 0){
                    if(useDefineBean->yesNo()){
                        WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"define1",beanLists.at(i)->define1());
                        WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"define2",beanLists.at(i)->define2());
                        WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"define3",beanLists.at(i)->define3());
                        WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"define4",beanLists.at(i)->define4());
                        WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"define5",beanLists.at(i)->define5());
                        WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"define6",beanLists.at(i)->define6());
                        WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"memo",beanLists.at(i)->memo());
                    }
                }

            }
            mIsChoose = false;
        }

    }

}
void SaRdWin::sPrint(){

    QString fileName = "ReportPuOrder.xml";
    QString title = "销售出库单";
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

void SaRdWin::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage){
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

void SaRdWin::sCancel(){

    this->close();
}

void SaRdWin::closeEvent(QCloseEvent *event){

    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::No){
            event->ignore();
            return ;
        }
    }

    event->accept();
    HaoKeApp::getInstance()->gui()->removeSubWin(this);


}

void SaRdWin::setupContextMenu(){
    /*
    handleAct = new QAction(QIcon(":/images/connector.png"),tr("关联联赛"),this);

    connect(handleAct, SIGNAL(triggered()), this, SLOT(handleMatch()));
    */
    setContextMenuPolicy(Qt::ActionsContextMenu);
}
void SaRdWin::on_tableWidget_itemChanged(QTableWidgetItem *item)
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
        //销售业务必有订单不可直接录入商品数据
        if(mIsHathOrder && !mIsChoose){
            QMessageBox::warning(this,"提示","此销售业务必有订单，不可直接录入商品！");
            ui->tableWidget->model()->setData(ui->tableWidget->model()->index(item->row(),0),"");
            return ;
        }
        //根据ID查询原料信息
        //ProductBean *bean = ProductDAO::getProductByCode(code);
        SaPriceBean *bean = SaPriceDAO::getSaPriceBy(code);
        if(code.length() > 0 && bean != NULL && bean->productCode() == code ){
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"productName",bean->productName());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"productStyle",bean->style());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"unit",bean->unit());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"unitPrice",bean->price());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"quantity",1);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"money",1*bean->price());

            if((ui->tableWidget->rowCount()-1) == item->row()){
                QAbstractItemModel *model = ui->tableWidget->model();
                int id = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toInt();
                if(mEditStatus == editFlag && id < 1){

                    //单据修改 增加数据
                    RdsBean *sBean = new RdsBean();
                    sBean->setRdNo(ui->noEdit->text());
                    WidgetBeanUtil::setItemModelToBean(model,item->row(),mChildItem,sBean);
                    mAddChildVouchsList.append(sBean);
                }
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            }
        }else{
            QMessageBox::information(this,"提示","不存在此商品，或此商品无销售报价");

            return ;
        }

    }else if(item->column() == 4 || item->column()==5){

        QTableWidgetItem *moneyItemR = new QTableWidgetItem();

        double price = ui->tableWidget->model()->data(ui->tableWidget->model()->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"unitPrice"))).toDouble();
        double quantity = ui->tableWidget->model()->data(ui->tableWidget->model()->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"quantity"))).toDouble();

        double money = price * quantity;
        moneyItemR->setData(Qt::EditRole,QString::number(money,'f',2));

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

            mFootModel->setItem(5,new QStandardItem(QString::number(mTotalQuantity,'f',2)));
            mFootModel->setItem(7,new QStandardItem(QString::number(mTotalSum,'f',2)));
            mFootView->reset();

        }

    }

    //单据修改
    if(mEditStatus == editFlag){
        QAbstractItemModel *model = ui->tableWidget->model();
        int id = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toInt();
        QString pCode = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"productCode"))).toString();
        double price = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"unitPrice"))).toDouble();
        double quantity = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"quantity"))).toDouble();
        if(item->column() == 4 || item->column()==5){
            if(id < 1 ){
                for(int i =0; i < mAddChildVouchsList.size(); i++){
                    if(mAddChildVouchsList.at(i)->productCode() == pCode){
                        double money = price * quantity;
                        mAddChildVouchsList.at(i)->setQuantity(quantity);
                        mAddChildVouchsList.at(i)->setUnitPrice(price);
                        mAddChildVouchsList.at(i)->setMoney(money);

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

                mChildVouchsList.at(i)->setMoney(money);

            }
        }

    }
}

