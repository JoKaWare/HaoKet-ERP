#include "saorderwin.h"
#include "ui_saorderwin.h"

#include "ui_SaOrderWin.h"
#include "haokeapp.h"
#include "bean/DepBean.h"
#include "bean/CustomerBean.h"
#include "bean/EmployeeBean.h"
#include "bean/WareHouseBean.h"
#include "bean/ProductBean.h"
#include "bean/SaPriceBean.h"
#include "bean/DefineBean.h"
#include "bean/SystemSetBean.h"
#include "dao/systemsetdao.h"
#include "dao/depdao.h"
#include "dao/customerdao.h"
#include "dao/employeedao.h"
#include "dao/waredao.h"
#include "dao/productdao.h"
#include "dao/saorderdao.h"
#include "dao/sapricedao.h"
#include "dao/commondao.h"
#include "common/itemutil.h"
#include "common/cachebabeancommon.h"
#include "common/printutils.h"
#include "qtrpt.h"
#include "bean/ReportFormatBean.h"
#include "dao/reportdao.h"
#include "widget/designoptdialog.h"
#include "widget/optinvdialog.h"
#include "bean/SaDispatchVouchsBean.h"
#include "dao/sadispatchdao.h"
#include "saplugin.h"

SaOrderWin::SaOrderWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaOrderWin)
{
    ui->setupUi(this);
    init();
    //qApp->setStyle("Plastique");
    setupContextMenu();
    mCountRecord = SaOrderDAO::getSaOrderCount() - 1;
    if(mCountRecord < 0) mCountRecord = 0;
    mRecord = mCountRecord;
    QList<SaOrderVouchBean *> vouchBeanList = SaOrderDAO::querySaOrderByPage(mCountRecord,1);
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

SaOrderWin::SaOrderWin(QString no,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaOrderWin)
{
    ui->setupUi(this);
    init();
    //qApp->setStyle("Plastique");
    setupContextMenu();
    mCountRecord = SaOrderDAO::getSaOrderCount() - 1;
    if(mCountRecord < 0) mCountRecord = 0;
    ui->toolBar->actions().at(0)->setEnabled(true);
    ui->toolBar->actions().at(1)->setEnabled(true);
    ui->toolBar->actions().at(7)->setEnabled(true);

    SaOrderVouchBean *bean = SaOrderDAO::getSaOrderByNo(no);
    if(bean != NULL && bean->no().length() > 0){
        mRecord = SaOrderDAO::getSaOrderRowNumber(bean->id()) - 1;
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

SaOrderWin::~SaOrderWin()
{
    delete ui;
}

void SaOrderWin::readAuthority(){
    LimitsCommon::authority(ui->toolBar,mWinId.toInt());
}

void SaOrderWin::init(){
    QApplication::setOverrideCursor(Qt::WaitCursor);
    //窗体ID号
    mWinId = HaoKeApp::saSubId() + SaPlugin::orderWinId();
    mWinTitle = "销售订单";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::saSubId().toInt(),mWinId.toInt(),0,"");

    //功能菜单
    actionProperties actsBase[]= {
        { "SaOrder.new",tr("&New"),SLOT(sNew()), NULL, "New", QPixmap(":/image/Add.png"), NULL,  true, tr("New") },
        { "SaOrder.edit",tr("&Edit"),SLOT(sEdit()), NULL, "Edit", QPixmap(":/image/edit.png"), NULL,  true, tr("Edit") },
        { "SaOrder.delete",tr("&Delete"),SLOT(sDelete()), NULL, "Delete", QPixmap(":/image/cross_48.png"), NULL,  true, tr("Delete") },
        { "SaOrder.save",tr("&Save"),SLOT(sSave()), NULL, "Save", QPixmap(":/image/save.png"), NULL,  true, tr("Save") },
        { "SaOrder.audit",tr("&Audit"),SLOT(sAudit()), NULL, "Audit", QPixmap(":/image/stamp_48.png"), NULL,  true, tr("Audit") },
        { "SaOrder.abandonAudit",tr("&Abandon Audit"),SLOT(sAbAudit()), NULL, "Abandon Audit", QPixmap(":/image/c_stamp_48.png"), NULL,  true, tr("Abandon Audit") },
        { "SaOrder.delRow",tr("&DelRow"),SLOT(sDelRow()), NULL, "DelRow", QPixmap(":/image/minus.png"), NULL,  true, tr("DelRow") },
        { "SaOrder.print",tr("&Print"),SLOT(sPrint()), NULL, "Print", QPixmap(":/image/printer.png"), NULL,  true, tr("Print") },
        { "SaOrder.first",tr("&First"),SLOT(sFirst()), NULL, "First", QPixmap(":/image/first48.png"), NULL,  true, tr("First") },
        { "SaOrder.next",tr("&Next"),SLOT(sNext()), NULL, "Next", QPixmap(":/image/n-next48.png"), NULL,  true, tr("Next") },
        { "SaOrder.previous",tr("&Previous"),SLOT(sPrevious()), NULL, "Previous", QPixmap(":/image/n-previous48.png"), NULL,  true, tr("Previous") },
        { "SaOrder.end",tr("&End"),SLOT(sEnd()), NULL, "End", QPixmap(":/image/end48.png"), NULL,  true, tr("End") },
        { "SaOrder.cancel",tr("&Cancel"),SLOT(sCancel()), NULL, "Cancel", QPixmap(":/image/cancel.png"), NULL,  true, tr("Cancel") }

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
            { "unit","商品单位","商品单位", 3,80, true, false },
            { "quantity","数量","数量", 4, 60,true, true },
            { "price","单价","单价", 5,80, true, true },
            { "money","金额","金额", 6,80, true, false },
            { "id","ID","ID", 7,60, false, false },
        { "define1","自定义1","自定义1", 8,100, false, true },
        { "define2","自定义2","自定义2", 9,100, false, true },
        { "define3","自定义3","自定义3", 10,100, false, true },
        { "define4","自定义4","自定义4", 11,100, false, true },
        { "define5","自定义5","自定义5", 12,100, false, true },
        { "define6","自定义6","自定义6", 13,100, false, true },
        { "memo","备注","备注", 14,160, false, true }
    };
    //mChildItem << childItem[0] << childItem[1] << childItem[2] << childItem[3] << childItem[4] << childItem[5] << childItem[6] << childItem[7];

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
            for(int i =8 ; i < size ; i ++){
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
    busTypeList << "普通销售";
    busTypeList << "计划销售" << "合同销售" <<"委托代销";
    ui->busTypeComboBox->addItems(busTypeList);
    QList<CustomerBean *> cusBeanList = CustomerDAO::queryCus();
    QStringList venList ;
    for(int i =0 ; i < cusBeanList.size(); i++){
        venList << cusBeanList.at(i)->cusCode() + " - " +cusBeanList.at(i)->cusName();
    }
    ui->cusSearchEditbox->setListModel(true);
    ui->cusSearchEditbox->setItems(venList);

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
void SaOrderWin::sInvClick(){

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
    QString whCode = "";
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
void SaOrderWin::footResized(int logicalIndex, int oldSize, int newSize){
    mFootView->resizeSection(logicalIndex + 1,newSize);
}
void SaOrderWin::refreshData(){

    QStringList headerLabels;
    for (int i = 0; i < mChildItem.size(); i++){
        headerLabels.append(mChildItem[i].cnName);
        ui->tableWidget->setColumnWidth(mChildItem[i].id,mChildItem[i].width);
        mFootView->resizeSection(mChildItem[i].id + 1,mChildItem[i].width);
        if(!mChildItem[i].visible)ui->tableWidget->hideColumn(mChildItem[i].id);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
}

void SaOrderWin::read(QString no){
    SaOrderVouchBean *bean = SaOrderDAO::getSaOrderByNo(no);
    mNo = no;
    if(bean != NULL && bean->no().length() > 0){
        ui->noEdit->setText(bean->no());
        ui->dateEdit->setDate(bean->busDate());
        ui->demanddDateEdit->setDate(bean->demandDate());
        ui->projectDateEdit->setDate(bean->projectDate());
        CustomerBean *cusBean = CustomerDAO::getCusByCode(bean->cusCode());
        ui->cusSearchEditbox->setText(bean->cusCode() + " - " + cusBean->cusName());
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
        QList<SaOrderVouchsBean *> pBeanList = SaOrderDAO::querySaOrderVouchsByNo(no);
        mChildVouchsList = SaOrderDAO::querySaOrderVouchsByNo(no);
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
        mFootView->reset();
        readAuthority();
    }
}

void SaOrderWin::inputClear(){
    WidgetBeanUtil::clearLayoutWidgetData(ui->headGridLayout);


}

void SaOrderWin::setInputEnable(bool b){
     WidgetBeanUtil::setLayoutWidgetEnable(ui->headGridLayout,b);
     if(b){
         ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);
     }else{
         ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
     }
}

void SaOrderWin::addActionsTo(actionProperties acts[], unsigned int numElems){
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

        if(i<8){
            QString proceccId = mWinId + QString::number(i);
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::saSubId().toInt(),mWinId.toInt(),proceccId.toInt(),acts[i].toolTip,acts[i].actionName);

            act->setEnabled(false);
            ui->toolBar->addAction(act);
            addAction(act);
        }
        else
            baseToolBar->addAction(act);
    }

    connect(ui->toolBar, SIGNAL(actionTriggered(QAction*)), this, SLOT(toolBarActTriggered(QAction*)));
}

void SaOrderWin::toolBarActTriggered(QAction *act){
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::saSubId().toInt(),mWinId.toInt(),act->objectName());

}

void SaOrderWin::sFirst(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            setInputEnable(false);
        }else{
            return ;
        }
    }
    mRecord = 0;
    ui->tableWidget->clear();
    refreshData();
    QList<SaOrderVouchBean *> vouchBeanList = SaOrderDAO::querySaOrderByPage(0,1);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->no());

    }
    baseToolBar->actions().at(0)->setEnabled(false);
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(2)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(true);
}
\
void SaOrderWin::sNext(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
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
    QList<SaOrderVouchBean *> vouchBeanList = SaOrderDAO::querySaOrderByPage(mRecord,1);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->no());
    }
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(0)->setEnabled(true);
}

void SaOrderWin::sPrevious(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
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
    QList<SaOrderVouchBean *> vouchBeanList = SaOrderDAO::querySaOrderByPage(mRecord,1);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->no());
    }
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(true);
}

void SaOrderWin::sEnd(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            setInputEnable(false);
        }else{
            return ;
        }
    }
    ui->tableWidget->clear();
    refreshData();
    mCountRecord = SaOrderDAO::getSaOrderCount() - 1;
    mRecord = mCountRecord;
    QList<SaOrderVouchBean *> vouchBeanList = SaOrderDAO::querySaOrderByPage(mCountRecord,1);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->no());
    }
    baseToolBar->actions().at(0)->setEnabled(true);
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(false);
}

void SaOrderWin::sNew(){
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
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);
    int nCount = SaOrderDAO::getSaOrderCount(QDate::currentDate()) ;
    mNo = ItemUtil::getToDayMaxNo(mWinId,"sa_order_vouch",QDate::currentDate(),nCount);
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

void SaOrderWin::sEdit(){
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
    readAuthority();
}

void SaOrderWin::sSave(){
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

    if(ui->cusSearchEditbox->text().trimmed().length() < 1){
        QMessageBox::warning(this,"提示","请输入客户");
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
        if(SaOrderDAO::getSaOrderCountByNo(ui->noEdit->text()) > 0){
            QMessageBox::warning(this,"提示","出错，此单号重复，不能保存，重新生成新单号");
            int nCount = SaOrderDAO::getSaOrderCount(QDate::currentDate()) ;
            mNo = ItemUtil::getToDayMaxNo(mWinId,"sa_order_vouch",QDate::currentDate(),nCount);
            ui->noEdit->setText(mNo);
            return ;
        }
        mNo = ui->noEdit->text();
        SaOrderVouchBean *saVouchBean = new SaOrderVouchBean();
        saVouchBean->setNo(ui->noEdit->text());
        QDateTime time = QDateTime::currentDateTime();
        saVouchBean->setBusDate(ui->dateEdit->date());
        saVouchBean->setBusType(ui->busTypeComboBox->currentText());
        saVouchBean->setDemandDate(ui->demanddDateEdit->date());
        saVouchBean->setProjectDate(ui->projectDateEdit->date());
        saVouchBean->setCusCode(ui->cusSearchEditbox->text());
        saVouchBean->setDepCode(ui->depSearchEditbox->text());
        saVouchBean->setPersonCode(ui->userSearchEditbox->text());
        saVouchBean->setMemo(ui->memoEdit->text());
        saVouchBean->setHandler("");
        saVouchBean->setCreated(time);
        saVouchBean->setIsHandle(false);
        saVouchBean->setIsComplete(false);
        saVouchBean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        saVouchBean->setCreater(HaoKeApp::getInstance()->getUserDesc());
        saVouchBean->setUpdated(time);
        saVouchBean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        saVouchBean->setUpdater(HaoKeApp::getInstance()->getUserDesc());
        saVouchBean->setStatus(0);
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = 0;
        mResult = SaOrderDAO::createSaOrder(saVouchBean);
        int cResult = 0;
        double d_val = 0;
        for(int i = 0;i < rowNum; i++){
            SaOrderVouchsBean *puVouchsBean = new SaOrderVouchsBean();
            puVouchsBean->setOrderNo(mNo);
            WidgetBeanUtil::setItemModelToBean(model,i,mChildItem,puVouchsBean);

            puVouchsBean->setTaxPrice(puVouchsBean->price());
            puVouchsBean->setIsComplete(false);
            puVouchsBean->setOutQuantity(d_val);
            puVouchsBean->setReQuantity(d_val);
            puVouchsBean->setToq(0);

            int c = SaOrderDAO::createSaOrderVouchs(puVouchsBean);
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
            ui->makerEdit->setText(CacheBaBeanCommon::userToName(HaoKeApp::getInstance()->getUserId(),1));
            setInputEnable(false);
            mCountRecord = SaOrderDAO::getSaOrderCount() - 1;
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
        SaOrderVouchBean *saVouchBean = SaOrderDAO::getSaOrderByNo(mNo);
        if(saVouchBean && saVouchBean->isHandle()){
            QMessageBox::warning(this,"提示","此单已审核，不能修改");
            return ;
        }
        saVouchBean->setNo(ui->noEdit->text());
        QDateTime time = QDateTime::currentDateTime();
        saVouchBean->setBusDate(ui->dateEdit->date());
        saVouchBean->setBusType(ui->busTypeComboBox->currentText());
        saVouchBean->setDemandDate(ui->demanddDateEdit->date());
        saVouchBean->setProjectDate(ui->projectDateEdit->date());
        saVouchBean->setCusCode(ui->cusSearchEditbox->text());
        saVouchBean->setDepCode(ui->depSearchEditbox->text());
        saVouchBean->setPersonCode(ui->userSearchEditbox->text());
        saVouchBean->setMemo(ui->memoEdit->text());
        saVouchBean->setUpdated(time);
        saVouchBean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        saVouchBean->setUpdater(HaoKeApp::getInstance()->getUserDesc());
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = 0;
        mResult = SaOrderDAO::updateSaOrder(saVouchBean);
        int cResult = 0;
        //删除
        for(int i = 0; i < mDelChildList.size(); i++){
            SaOrderVouchsBean *delBean = new SaOrderVouchsBean;
            delBean->setId(mDelChildList.at(i));
            int c = SaOrderDAO::delSaOrderVouchs(delBean);
            cResult = cResult + c;
        }
        //更新
        for(int i = 0; i < mChildVouchsList.size(); i++){
            int c = SaOrderDAO::updateSaOrderVouchs(mChildVouchsList.at(i));
            cResult = cResult + c;
        }
        //添加
        for(int i = 0; i < mAddChildVouchsList.size(); i++){
            int c = SaOrderDAO::createSaOrderVouchs(mAddChildVouchsList.at(i));
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

void SaOrderWin::sDelete(){
    if(ui->auditEdit->text().length() > 0){
        QMessageBox::warning(this,"提示","已审核，不能删除！");
        return ;
    }
    mNo = ui->noEdit->text().trimmed();

    QList<SaDispatchVouchsBean *> vouchsList = SaDispatchDAO::querySaDispatchVouchsByOrderNo(ui->noEdit->text().trimmed());
    if(vouchsList.size() > 0){
        QMessageBox::information(this,"提示","此单在发货单：" + vouchsList.at(0)->dispatchNo() + " 中已执行，不能删除！");
        return ;
    }
    if(QMessageBox::warning(this,"提示","是否删除？",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        SaOrderVouchBean *bean = SaOrderDAO::getSaOrderByNo(mNo);
        bean->setNo(mNo);
        if(bean->isHandle()){
            QMessageBox::warning(this,"提示",bean->handler() + " 已审核，不能删除！");
            return ;
        }
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = SaOrderDAO::delSaOrderByNo(bean);
        int cResult = SaOrderDAO::delSaOrderVouchsByNo(ui->noEdit->text());
        if(mResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            mIsEdit =false;
            setInputEnable(false);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            if(mRecord ==0){
                sNext();
            }else sPrevious();
            mCountRecord = SaOrderDAO::getSaOrderCount() - 1;
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::critical(this,"错误","删除出错");

        }

    }

    readAuthority();
}

void SaOrderWin::sDelRow(){
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

void SaOrderWin::sAudit(){
    SaOrderVouchBean *bean = SaOrderDAO::getSaOrderByNo(ui->noEdit->text().trimmed());
    if(bean !=NULL && bean->no().length() > 0){
        if(bean->isHandle()){
            ui->toolBar->actions().at(4)->setEnabled(false);
            ui->toolBar->actions().at(5)->setEnabled(true);
            QMessageBox::information(this,"提示","已审核，不能再审核！");
            return ;
        }
        bean->setHandler(CacheBaBeanCommon::userToName(HaoKeApp::getInstance()->getUserId(),1));
        bean->setAuditTime(QDateTime::currentDateTime());
        bean->setIsHandle(true);
        bean->setUpdated(QDateTime::currentDateTime());
        bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        bean->setUpdater(HaoKeApp::getInstance()->getUserDesc());
        int result = SaOrderDAO::updateSaOrder(bean);
        if(result > 0){
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

void SaOrderWin::sAbAudit(){
    SaOrderVouchBean *bean = SaOrderDAO::getSaOrderByNo(ui->noEdit->text().trimmed());
    if(bean !=NULL && bean->no().length() > 0){
        if(!bean->isHandle()){
            ui->toolBar->actions().at(4)->setEnabled(true);
            ui->toolBar->actions().at(5)->setEnabled(false);
            QMessageBox::information(this,"提示","未审核，不能弃审！");
            return ;
        }

        QList<SaDispatchVouchsBean *> vouchsList = SaDispatchDAO::querySaDispatchVouchsByOrderNo(ui->noEdit->text().trimmed());
        if(vouchsList.size() > 0){
            QMessageBox::information(this,"提示","此单在发货单：" + vouchsList.at(0)->dispatchNo() + " 中已执行，不能弃审！");
            return ;
        }

        bean->setHandler("");
        bean->setIsHandle(false);
        bean->setUpdated(QDateTime::currentDateTime());
        bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        bean->setUpdater(HaoKeApp::getInstance()->getUserDesc());
        int result = SaOrderDAO::updateSaOrder(bean);
        if(result > 0){
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

void SaOrderWin::sPrint(){

    QString fileName = "ReportSaOrder.xml";
    QString title = "销售订单";
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

void SaOrderWin::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage){
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

void SaOrderWin::sCancel(){

    this->close();
}

void SaOrderWin::closeEvent(QCloseEvent *event){

    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::No){
            event->ignore();
            return ;
        }
    }

    event->accept();
    HaoKeApp::getInstance()->gui()->removeSubWin(this);


}

void SaOrderWin::setupContextMenu(){
    /*
    handleAct = new QAction(QIcon(":/images/connector.png"),tr("关联联赛"),this);

    connect(handleAct, SIGNAL(triggered()), this, SLOT(handleMatch()));
    */
    setContextMenuPolicy(Qt::ActionsContextMenu);
}
void SaOrderWin::on_tableWidget_itemChanged(QTableWidgetItem *item)
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
        //ProductBean *bean = ProductDAO::getProductByCode(code);
        SaPriceBean *bean = SaPriceDAO::getSaPriceBy(code);
        if(code.length() > 0 && bean != NULL && bean->productCode() == code ){
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"productName",bean->productName());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"productStyle",bean->style());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"unit",bean->unit());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"price",bean->price());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"quantity",1);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"money",1*bean->price());

            if((ui->tableWidget->rowCount()-1) == item->row()){
                QAbstractItemModel *model = ui->tableWidget->model();
                int id = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toInt();
                if(mEditStatus == editFlag && id < 1){

                    //单据修改 增加数据
                    SaOrderVouchsBean *puVouchsBean = new SaOrderVouchsBean();
                    puVouchsBean->setOrderNo(ui->noEdit->text());
                    WidgetBeanUtil::setItemModelToBean(model,item->row(),mChildItem,puVouchsBean);
                    puVouchsBean->setIsComplete(false);
                    mAddChildVouchsList.append(puVouchsBean);
                }
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            }
        }else{
            QMessageBox::information(this,"提示","不存在此商品,或此商品无销售报价");

            return ;
        }

    }else if(item->column() == 4 || item->column()==5){

        QTableWidgetItem *moneyItemR = new QTableWidgetItem();

        double price = ui->tableWidget->model()->data(ui->tableWidget->model()->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"price"))).toDouble();
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
        double price = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"price"))).toDouble();
        double quantity = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"quantity"))).toDouble();
        if(item->column() == 4 || item->column()==5){
            if(id < 1 ){
                for(int i =0; i < mAddChildVouchsList.size(); i++){
                    if(mAddChildVouchsList.at(i)->productCode() == pCode){
                        double money = price * quantity;
                        mAddChildVouchsList.at(i)->setQuantity(quantity);
                        mAddChildVouchsList.at(i)->setPrice(price);
                        mAddChildVouchsList.at(i)->setMoney(money);
                        mAddChildVouchsList.at(i)->setReQuantity(0);
                        mAddChildVouchsList.at(i)->setOutQuantity(0);
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

