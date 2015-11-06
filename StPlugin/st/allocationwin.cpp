#include "allocationwin.h"
#include "ui_allocationwin.h"
#include "haokeapp.h"
#include "stplugin.h"
#include "common/itemutil.h"
#include "common/cachebabeancommon.h"
#include "common/printutils.h"
#include "qtrpt.h"
#include "bean/ReportFormatBean.h"
#include "dao/reportdao.h"
#include "widget/designoptdialog.h"
#include "widget/optinvdialog.h"

AllocationWin::AllocationWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AllocationWin)
{
    ui->setupUi(this);
    init();
    mCountRecord = TransDAO::getTransCount() - 1;
    mRecord = mCountRecord;
    if(mCountRecord < 0) mCountRecord = 0;
    QList<TransVouchBean *> beanList = TransDAO::queryTransByPage(mCountRecord,1);
    if(beanList.size()>0){
        read(beanList.at(0)->tvNo());
    }
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(false);
    ui->toolBar->actions().at(0)->setEnabled(true);
    ui->toolBar->actions().at(1)->setEnabled(true);
    if(ui->noEdit->text().length() >0){
        ui->toolBar->actions().at(2)->setEnabled(true);
    }
    readAuthority();
}

AllocationWin::AllocationWin(QString no, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AllocationWin)
{
    ui->setupUi(this);
    init();
    mCountRecord = TransDAO::getTransCount() - 1;
    if(mCountRecord < 0) mCountRecord = 0;
    ui->toolBar->actions().at(0)->setEnabled(true);
    ui->toolBar->actions().at(1)->setEnabled(true);

    TransVouchBean *bean = TransDAO::getTransBeanByNo(no);
    if(bean != NULL && bean->tvNo().length() > 0){
        mRecord = TransDAO::getTransRowNumber(bean->id()) - 1;
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
    }
    readAuthority();
}


AllocationWin::AllocationWin(int editStatus, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AllocationWin)
{
    ui->setupUi(this);
    init();
    mCountRecord = TransDAO::getTransCount() - 1;
    mRecord = mCountRecord;

    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(false);
    ui->toolBar->actions().at(0)->setEnabled(true);
    ui->toolBar->actions().at(1)->setEnabled(true);
    if(ui->noEdit->text().length() >0){
        ui->toolBar->actions().at(2)->setEnabled(true);
    }
    if(editStatus == addFlag){
        sNew();
    }
     readAuthority();
}
AllocationWin::~AllocationWin()
{
    delete ui;
}


void AllocationWin::init(){
    mWinId = HaoKeApp::stSubId() + StPlugin::allocationWinId();
    mWinTitle = "调拨单";
    actionProperties actsBase[]= {
        { "puOrder.new",tr("&New"),SLOT(sNew()), NULL, "New", QPixmap(":/image/Add.png"), NULL,  true, tr("New") },
        { "puOrder.edit",tr("&Edit"),SLOT(sEdit()), NULL, "Edit", QPixmap(":/image/edit.png"), NULL,  true, tr("Edit") },
        { "puOrder.delete",tr("&Delete"),SLOT(sDelete()), NULL, "Delete", QPixmap(":/image/cross_48.png"), NULL,  true, tr("Delete") },
        { "puOrder.save",tr("&Save"),SLOT(sSave()), NULL, "Save", QPixmap(":/image/save.png"), NULL,  true, tr("Save") },
        { "puOrder.audit",tr("&Audit"),SLOT(sAudit()), NULL, "Audit", QPixmap(":/image/stamp_48.png"), NULL,  true, tr("Audit") },
        { "puOrder.abandonAudit",tr("&Abandon Audit"),SLOT(sAbAudit()), NULL, "Abandon Audit", QPixmap(":/image/c_stamp_48.png"), NULL,  true, tr("Abandon Audit") },
        { "puOrder.delRow",tr("&DelRow"),SLOT(sDelRow()), NULL, "DelRow", QPixmap(":/image/minus.png"), NULL,  true, tr("DelRow") },
        { "puOrder.print",tr("&Print"),SLOT(sPrint()), NULL, "Print", QPixmap(":/image/printer.png"), NULL,  true, tr("Print") },
        { "puOrder.first",tr("&First"),SLOT(sFirst()), NULL, "First", QPixmap(":/image/first48.png"), NULL,  true, tr("First") },
        { "puOrder.next",tr("&Next"),SLOT(sNext()), NULL, "Next", QPixmap(":/image/n-next48.png"), NULL,  true, tr("Next") },
        { "puOrder.previous",tr("&Previous"),SLOT(sPrevious()), NULL, "Previous", QPixmap(":/image/n-previous48.png"), NULL,  true, tr("Previous") },
        { "puOrder.end",tr("&End"),SLOT(sEnd()), NULL, "End", QPixmap(":/image/end48.png"), NULL,  true, tr("End") },
        { "puOrder.cancel",tr("&Cancel"),SLOT(sCancel()), NULL, "Cancel", QPixmap(":/image/cancel.png"), NULL,  true, tr("Cancel") }

    };
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::stSubId().toInt(),mWinId.toInt(),0,"");

    addActionsTo(actsBase,sizeof(actsBase) / sizeof(actsBase[0]));

    mIsEdit =false;
    //06 材料出库单 查看vouch_type表
    mVouchType = "09";
    mVouchSource = "";
    ui->dateEdit->setDate(QDate::currentDate());

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
    ui->whInSearchEditbox->setListModel(true);
    ui->whInSearchEditbox->setItems(whList);
    ui->whOutSearchEditbox->setListModel(true);
    ui->whOutSearchEditbox->setItems(whList);
    setInputEnable(false);
    childItemProperties childItem[] = {
            { "productCode","商品编码","商品编码", 0,180, true, true },
            { "productName","商品名称","商品名称", 1,180, true, true },
            { "productStyle","商品规格","商品规格", 2,80, true, false },
            { "unit","商品单位","商品单位", 3,80, true, false },
            { "quantity","数量","数量", 4, 60,true, true },
            { "unitPrice","单价","单价", 5,80, true, true },
            { "money","金额","金额", 6,80, true, false },
            { "id","ID","ID", 7,60, false, false }


    };
    int size = sizeof(childItem) / sizeof(childItem[0]);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(size);
    for(int i =0 ; i < size ; i ++){
        mChildItem << childItem[i];
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


void AllocationWin::sInvClick(){
    QString sql = " SELECT b.wh_name,a.*,a.sum-a.c_sum+a.r_sum as k_sum FROM st_stock_query a, ba_ware_house b , ba_product c"
            " WHERE a.wh_code=b.wh_code AND a.product_code=c.product_code "
            " AND a.wh_code LIKE ? AND a.product_code LIKE ? AND c.type_id LIKE ? ";
    childItemProperties childItem[] = {
            { "product_code","编码商品","商品", 0,60, true, true },
            { "product_name","名称商品","商品", 1,100, true, true },
            { "wh_name","名称仓库","仓库", 2,80, true, true },
            { "sum","现存量","现存量", 3, 60,true, true },
            { "r_sum","待入库","待入库", 4, 60,true, true },
            { "c_sum","待出库","待出库", 5, 60,true, true },
            { "k_sum","可发量","可发量", 6,60, true, true }
    };

    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }
    QString whCode = ui->whOutSearchEditbox->text() + " - " + ui->whOutSearchEditbox->subText();
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

void AllocationWin::readAuthority(){
    LimitsCommon::authority(ui->toolBar,mWinId.toInt());
}

void AllocationWin::addActionsTo(actionProperties acts[], unsigned int numElems){
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
        act->setIcon(icon);

        connect(act, SIGNAL(triggered()), this, acts[i].slot);

        if(i<8){
            act->setEnabled(false);
            ui->toolBar->addAction(act);
            QString proceccId = mWinId + QString::number(i);
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::stSubId().toInt(),mWinId.toInt(),proceccId.toInt(),acts[i].toolTip,acts[i].actionName);

        }
        else
            baseToolBar->addAction(act);
    }

    connect(ui->toolBar, SIGNAL(actionTriggered(QAction*)), this, SLOT(toolBarActTriggered(QAction*)));
}

void AllocationWin::toolBarActTriggered(QAction *act){
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::stSubId().toInt(),mWinId.toInt(),act->objectName());

}

void AllocationWin::refreshData(){
    QStringList headerLabels;
    for (int i = 0; i < mChildItem.size(); i++){
        headerLabels.append(mChildItem[i].cnName);
        ui->tableWidget->setColumnWidth(mChildItem[i].id,mChildItem[i].width);
        mFootView->resizeSection(mChildItem[i].id + 1,mChildItem[i].width);
        if(!mChildItem[i].visible)ui->tableWidget->hideColumn(mChildItem[i].id);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
}

void AllocationWin::footResized(int logicalIndex, int oldSize, int newSize){
    mFootView->resizeSection(logicalIndex + 1,newSize);
}

void AllocationWin::setInputEnable(bool b){
    WidgetBeanUtil::setLayoutWidgetEnable(ui->gridLayout,b);
    if(b){
        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);
    }else{
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}

void AllocationWin::inputClear(){
    WidgetBeanUtil::clearLayoutWidgetData(ui->gridLayout);

}

void AllocationWin::read(QString no){
    TransVouchBean *bean = TransDAO::getTransBeanByNo(no);
    if(bean != NULL && bean->tvNo().length() > 0){
        ui->noEdit->setText(bean->tvNo());
        ui->dateEdit->setDate(bean->tvDate());

        WareHouseBean *whBean = WareDAO::getWarehouseById(bean->owhCode());
        ui->whOutSearchEditbox->setText(bean->owhCode() + " - " + whBean->whName());;

        WareHouseBean *whInBean = WareDAO::getWarehouseById(bean->iwhCode());
        ui->whInSearchEditbox->setText(bean->iwhCode() + " - " + whInBean->whName());;
        DepBean *depBean = DepDAO::getDepById(bean->depCode());
        ui->depSearchEditbox->setText(bean->depCode() + " - " + depBean->depName());
        ui->userSearchEditbox->setText(bean->personCode() + " - " + CacheBaBeanCommon::personToName(bean->personCode()));

        ui->memoEdit->setText(bean->memo());
        ui->makerEdit->setText(BusinessNo::userToName(bean->createdBy(),1));
        ui->auditEdit->setText(bean->handler());

        if(bean->isHandle()){
            ui->toolBar->actions().at(4)->setEnabled(false);
            ui->toolBar->actions().at(5)->setEnabled(true);
        }else{
            ui->toolBar->actions().at(4)->setEnabled(true);
            ui->toolBar->actions().at(5)->setEnabled(false);
        }
        ui->toolBar->actions().at(7)->setEnabled(true);
        QList<TransVouchsBean *> pBeanList = TransDAO::queryTransVouchsByNo(no);
        mChildRdsList =  TransDAO::queryTransVouchsByNo(no);
        ui->tableWidget->setRowCount(pBeanList.size() + 1);
        mTotalQuantity = 0;
        mTotalSum = 0;
        for(int i =0; i < pBeanList.size(); i++){
            WidgetBeanUtil::setBeanToTableWidget(ui->tableWidget,i,mChildItem,pBeanList.at(i));
            mTotalQuantity = mTotalQuantity + pBeanList.at(i)->quantity();
            mTotalSum = mTotalSum + pBeanList.at(i)->money();
        }
        readAuthority();
        mFootModel->setItem(5,new QStandardItem(QString::number(mTotalQuantity,'f',2)));
        mFootModel->setItem(7,new QStandardItem(QString::number(mTotalSum,'f',2)));
        mFootView->reset();


    }
}

void AllocationWin::sNew(){
    inputClear();
    mIsEdit = true;
    mEditStatus = addFlag;
    setInputEnable(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);
    ui->dateEdit->setDate(QDate::currentDate());

    ui->toolBar->actions().at(0)->setEnabled(false);
    ui->toolBar->actions().at(1)->setEnabled(false);
    ui->toolBar->actions().at(2)->setEnabled(false);
    ui->toolBar->actions().at(3)->setEnabled(true);
    ui->toolBar->actions().at(4)->setEnabled(false);
    ui->toolBar->actions().at(5)->setEnabled(false);
    ui->toolBar->actions().at(6)->setEnabled(true);
    int nCount = TransDAO::getTransCount(QDate::currentDate());
    QString no = ItemUtil::getToDayMaxNo(mWinId,"st_trans_vouch",QDate::currentDate(),nCount);
    ui->noEdit->setText(no);
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);
    refreshData();
    readAuthority();
}

void AllocationWin::sEdit(){
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
    //ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);

    ui->toolBar->actions().at(0)->setEnabled(false);
    ui->toolBar->actions().at(1)->setEnabled(false);
    ui->toolBar->actions().at(2)->setEnabled(true);
    ui->toolBar->actions().at(3)->setEnabled(true);
    ui->toolBar->actions().at(6)->setEnabled(true);
    readAuthority();
}

void AllocationWin::sDelete(){
    if(ui->auditEdit->text().length() > 0){
        QMessageBox::warning(this,"提示","已审核，不能删除！");
        return ;
    }
    if(QMessageBox::warning(this,"提示","是否删除？",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        RdBean *bean = new RdBean;
        bean->setRdNo(ui->noEdit->text());
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = RdDAO::delRdByNo(bean);
        int cResult = RdDAO::delRdsByNo(ui->noEdit->text());
        if(mResult < 1){
            if(QMessageBox::warning(this,"提示","生成的出入库调拨单已删除，是否删除此调拨单" + ui->noEdit->text() + "?",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
                DBManager::getDBManager()->getGoinDBConnection().commit();
                mIsEdit =false;
                setInputEnable(false);
                ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
                if(mRecord ==0){
                    sNext();
                }else sPrevious();
                mCountRecord = RdDAO::getRdCount(mVouchType) - 1;
            }
        }else if(mResult > 0 && cResult>0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            mIsEdit =false;
            setInputEnable(false);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            if(mRecord ==0){
                sNext();
            }else sPrevious();
            mCountRecord = RdDAO::getRdCount(mVouchType) - 1;
        }else{
            QMessageBox::critical(this,"错误","删除出错");
            DBManager::getDBManager()->getGoinDBConnection().rollback();
        }

    }
    readAuthority();
}

void AllocationWin::sSave(){
    if(ui->noEdit->text().length()< 1){
        QMessageBox::warning(this,"提示","出错，此单号为空，不能保存");
        return ;
    }
    mNo = ui->noEdit->text().trimmed();
    QString whCode = ui->whInSearchEditbox->text().trimmed();
    if(whCode.length() < 1){
        ui->whInSearchEditbox->setFocus();
        QMessageBox::warning(this,"提示","转入仓库为空，不能保存");
        return ;
    }

    WareHouseBean *whBean = WareDAO::getWarehouseById(whCode);
    if(whBean == NULL ){
        ui->whInSearchEditbox->setFocus();
        QMessageBox::warning(this,"提示","转入仓库" + whCode + "不存在，不能保存");
        return ;
    }else if(whBean->whCode().length() < 1){
        ui->whInSearchEditbox->setFocus();
        QMessageBox::warning(this,"提示","转入仓库" + whCode + "不存在，不能保存");
        return ;
    }

    QString owhCode = ui->whOutSearchEditbox->text().trimmed();
    if(owhCode.length() < 1){
        ui->whOutSearchEditbox->setFocus();
        QMessageBox::warning(this,"提示","转出仓库为空，不能保存");
        return ;
    }
    if(owhCode == whCode){
        QMessageBox::warning(this,"提示","转出转入仓库相同，不能保存");
        return ;
    }
    WareHouseBean *whOutBean = WareDAO::getWarehouseById(owhCode);
    if(whOutBean == NULL ){
        ui->whOutSearchEditbox->setFocus();
        QMessageBox::warning(this,"提示","转出仓库" + owhCode + "不存在，不能保存");

        return ;
    }else if(whOutBean->whCode().length() < 1){
        ui->whOutSearchEditbox->setFocus();
        QMessageBox::warning(this,"提示","转出仓库" + owhCode + "不存在，不能保存");
        return ;
    }
    QAbstractItemModel *model = ui->tableWidget->model();
    int rowNum = model->rowCount() -1;
    if(rowNum == 0){
        QMessageBox::warning(this,"提示","无数据，不能保存");
        return;
    }
    for(int i = 0;i < rowNum; i++){
        QString pCode = model->data(model->index(i,0)).toString();
        ProductBean *pBean = ProductDAO::getProductByCode(pCode);
        if(pBean != NULL && pBean->productCode().length() > 0){
            for(int j = 0; j < ui->tableWidget->rowCount(); j ++){
                if(i != j && ui->tableWidget->model()->data(ui->tableWidget->model()->index(j,0)).toString().trimmed() == pCode){
                    QMessageBox::information(this,"提示","此原料" + pCode + " 重复！");
                    ui->tableWidget->model()->setData(ui->tableWidget->model()->index(j,0),"");
                    return;
                }
            }
        }else{
            QMessageBox::warning(this,"提示","此原料编码，不存在，不能保存");
            return ;
        }
    }
    QList<StockBean *> stockList = StockDAO::queryStockByWh(ui->whOutSearchEditbox->text());
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
                                     + " 库存不足,可调拨量为:"+ QString::number(topSum) + " 不能保存");
            return ;
        }
    }
    if(mEditStatus == addFlag){
        if(TransDAO::getTransCountByNo(ui->noEdit->text()) > 0){
            QMessageBox::warning(this,"提示","出错，此单号重复，不能保存，重新生成新单号");
            int nCount = TransDAO::getTransCount(QDate::currentDate());
            QString no = ItemUtil::getToDayMaxNo(mWinId,"st_trans_vouch",QDate::currentDate(),nCount);
            ui->noEdit->setText(no);
            return ;
        }

        QDateTime time = QDateTime::currentDateTime();
        TransVouchBean *bean = new TransVouchBean();
        bean->setTvNo(ui->noEdit->text());

        bean->setTvDate(ui->dateEdit->date());

        bean->setDepCode(ui->depSearchEditbox->text());
        bean->setPersonCode(ui->userSearchEditbox->text());
        bean->setOwhCode(ui->whOutSearchEditbox->text());
        bean->setIwhCode(ui->whInSearchEditbox->text());
        bean->setCreated(time);
        bean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        bean->setUpdated(time);
        bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        bean->setHandler("");
        bean->setIsHandle(false);
        bean->setCreater(HaoKeApp::getInstance()->getUserDesc());
        bean->setStatus(0);
        bean->setMemo(ui->memoEdit->text());
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = 0;
        mResult = TransDAO::createTrans(bean);
        int cResult = 0;
        double total = 0;
        double sum = 0;
        for(int i = 0;i < rowNum; i++){
            TransVouchsBean *vouchsBean = new TransVouchsBean();
            vouchsBean->setTvNo(ui->noEdit->text());
            QString pCode = model->data(model->index(i,0)).toString();
            double quantity = model->data(model->index(i,4)).toDouble();
            double price = model->data(model->index(i,5)).toDouble();

            double money = price * quantity;
            vouchsBean->setProductCode(pCode);
            vouchsBean->setProductStyle(model->data(model->index(i,2)).toString());
            vouchsBean->setUnit(model->data(model->index(i,3)).toString());
            vouchsBean->setUnitPrice(price);
            vouchsBean->setQuantity(quantity);
            vouchsBean->setMoney(money);

            sum = sum + quantity;
            total = total + money;
            int c = TransDAO::createTransVouchs(vouchsBean);
            if(c < 1){
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"提示","此" + pCode + " 数据提交出错,不能保存");
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
            ui->makerEdit->setText(BusinessNo::userToName(HaoKeApp::getInstance()->getUserId(),1));
            setInputEnable(false);
            mCountRecord = TransDAO::getTransCount() - 1;
            mRecord = mCountRecord;
            mDelChildList.clear();
            mAddChildRdsList.clear();
            mChildRdsList.clear();
            ui->tableWidget->clear();
            refreshData();
            read(ui->noEdit->text());
            readAuthority();
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::information(this,"Prompt","数据提交出错");
            return ;
        }


    }else if(mEditStatus == editFlag){
        //修改数据保存
        TransVouchBean *bean = TransDAO::getTransBeanByNo(ui->noEdit->text());
        bean->setTvNo(ui->noEdit->text());
        QDateTime time = QDateTime::currentDateTime();
        bean->setTvDate(ui->dateEdit->date());
        bean->setOwhCode(ui->whOutSearchEditbox->text());
        bean->setIwhCode(ui->whInSearchEditbox->text());
        bean->setDepCode(ui->depSearchEditbox->text());
        bean->setPersonCode(ui->userSearchEditbox->text());

        bean->setMemo(ui->memoEdit->text());
        bean->setIsHandle(false);
        bean->setCreater(HaoKeApp::getInstance()->getUserDesc());
        bean->setUpdated(time);
        bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = 0;
        mResult = TransDAO::updateTrans(bean);
        int cResult = 0;
        //删除
        for(int i = 0; i < mDelChildList.size(); i++){
            TransVouchsBean *delBean = new TransVouchsBean;
            delBean->setId(mDelChildList.at(i));
            int c = TransDAO::delTransVouchs(delBean);
            cResult = cResult + c;
        }
        //更新
        for(int i = 0; i < mChildRdsList.size(); i++){
            int c = TransDAO::updateTransVouchs(mChildRdsList.at(i));
            cResult = cResult + c;
        }
        //添加
        for(int i = 0; i < mAddChildRdsList.size(); i++){
            int c = TransDAO::createTransVouchs(mAddChildRdsList.at(i));
            cResult = cResult + c;
        }

        if(mResult > 0 && cResult>0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            ui->makerEdit->setText(BusinessNo::userToName(HaoKeApp::getInstance()->getUserId(),1));
            mDelChildList.clear();
            mAddChildRdsList.clear();
            mChildRdsList.clear();
            ui->tableWidget->clear();
            refreshData();
            read(ui->noEdit->text());
            setInputEnable(false);
            readAuthority();
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::information(this,"Prompt","数据提交出错");
            return ;
        }
    }
}

void AllocationWin::sDelRow(){

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
               for(int i =0 ; i < mChildRdsList.size(); i++){
                   if(code == mChildRdsList.at(i)->productCode()){
                       mDelChildList.append(mChildRdsList.at(i)->id());
                       mChildRdsList.removeAt(i);

                   }
               }
               for(int i =0 ; i < mAddChildRdsList.size(); i++){
                   if(code == mAddChildRdsList.at(i)->productCode()){
                       mAddChildRdsList.removeAt(i);
                   }
               }
               modelTotal->removeRow(row);
            }

       }
    }else{
       QMessageBox::information(this,"Prompt","请选择要删除的行!");
    }
}

void AllocationWin::sAudit(){
    TransVouchBean *bean = TransDAO::getTransBeanByNo(ui->noEdit->text().trimmed());
    if(bean !=NULL && bean->tvNo().length() > 0){
        if(bean->isHandle()){
            ui->toolBar->actions().at(4)->setEnabled(false);
            ui->toolBar->actions().at(5)->setEnabled(true);
            QMessageBox::information(this,"提示","已审核，不能再审核！");
            return ;
        }
        QList<TransVouchsBean *> tvBeanList = TransDAO::queryTransVouchsByNo(ui->noEdit->text().trimmed());
        if(tvBeanList.size() < 1){
            QMessageBox::information(this,"提示","无数据，不能再审核！");
            return ;
        }
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = 0;
        QDateTime time = QDateTime::currentDateTime();
        QString rdNo = ItemUtil::getToDayMaxRdNo(QDate::currentDate());
        QString rdOutNo = ItemUtil::getToDayMaxRdNo(QDate::currentDate());
        bean->setHandler(BusinessNo::userToName(HaoKeApp::getInstance()->getUserId(),1));
        bean->setIrdNo(rdNo + "");
        bean->setIsHandle(true);
        bean->setOrdNo(rdOutNo + "");
        bean->setAuditTime(time);
        bean->setUpdated(time);
        bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        mResult = TransDAO::updateTrans(bean);

        RdBean *rInBean = new RdBean;
        rInBean->setRdNo(rdNo);
        rInBean->setRdFlag(RdFlag::RdInFlag);
        rInBean->setBusNo(bean->tvNo());
        rInBean->setWhCode(bean->iwhCode());
        rInBean->setDepCode(bean->depCode());
        rInBean->setPersonCode(bean->personCode());
        rInBean->setBusDate(QDate::currentDate());
        rInBean->setVouchSource(HaoKeApp::getVouchAllocation());
        rInBean->setVouchType(HaoKeApp::getVouchRdOtherIn());
        rInBean->setBusType("调拨入库");
        rInBean->setCusCode("");
        rInBean->setSupplierId("");
        rInBean->setHandler("");
        rInBean->setIsHandle(false);
        rInBean->setPtCode("");
        rInBean->setBillNo("");
        rInBean->setIsBill(false);
        rInBean->setImeiAudit(false);
        rInBean->setStatus(0);
        rInBean->setCreated(time);
        rInBean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        rInBean->setCreater(HaoKeApp::getInstance()->getUserDesc());
        rInBean->setMemo("调拨审核生成,调拨单号:" + bean->tvNo());
        int iResult = RdDAO::createRd(rInBean);
        RdBean *rOutBean = new RdBean;
        rOutBean->setRdNo(rdOutNo);
        rOutBean->setRdFlag(RdFlag::RdOutFlag);
        rOutBean->setBusNo(bean->tvNo());
        rOutBean->setWhCode(bean->owhCode());
        rOutBean->setDepCode(bean->depCode());
        rOutBean->setPersonCode(bean->personCode());
        rOutBean->setBusDate(QDate::currentDate());
        rOutBean->setVouchSource(HaoKeApp::getVouchAllocation());
        rOutBean->setVouchType(HaoKeApp::getVouchRdOtherOut());
        rOutBean->setBusType("调拨出库");
        rOutBean->setCusCode("");
        rOutBean->setSupplierId("");
        rOutBean->setHandler("");
        rOutBean->setIsHandle(false);
        rOutBean->setPtCode("");
        rOutBean->setBillNo("");
        rOutBean->setIsBill(false);
        rOutBean->setImeiAudit(false);
        rOutBean->setStatus(0);
        rOutBean->setCreated(time);
        rOutBean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        rOutBean->setCreater(HaoKeApp::getInstance()->getUserDesc());
        rOutBean->setMemo("调拨审核生成,调拨单号:" + bean->tvNo());
        int oResult = RdDAO::createRd(rOutBean);
        int iRdsResult = 0;
        int oRdsResult = 0;
        for(int i = 0; i < tvBeanList.size(); i ++ ){
            RdsBean *rdsInBean = new RdsBean;
            rdsInBean->setRdNo(rInBean->rdNo());
            rdsInBean->setProductCode(tvBeanList.at(i)->productCode());
            rdsInBean->setProductStyle(tvBeanList.at(i)->productStyle());
            rdsInBean->setUnit(tvBeanList.at(i)->unit());
            rdsInBean->setUnitPrice(tvBeanList.at(i)->unitPrice());
            rdsInBean->setQuantity(tvBeanList.at(i)->quantity());
            rdsInBean->setMoney(tvBeanList.at(i)->money());
            rdsInBean->setAMoney(0);
            iRdsResult = iRdsResult + RdDAO::createRds(rdsInBean);
            RdsBean *rdsOutBean = new RdsBean;
            rdsOutBean->setRdNo(rOutBean->rdNo());
            rdsOutBean->setProductCode(tvBeanList.at(i)->productCode());
            rdsOutBean->setProductStyle(tvBeanList.at(i)->productStyle());
            rdsOutBean->setUnit(tvBeanList.at(i)->unit());
            rdsOutBean->setUnitPrice(tvBeanList.at(i)->unitPrice());
            rdsOutBean->setQuantity(tvBeanList.at(i)->quantity());
            rdsOutBean->setMoney(tvBeanList.at(i)->money());
            rdsOutBean->setAMoney(0);
            oRdsResult = oRdsResult + RdDAO::createRds(rdsOutBean);

        }
        if(mResult > 0 && iResult>0 && oResult>0 && iRdsResult>0 && oRdsResult>0 && iRdsResult == oRdsResult
                ){
            logger()->debug("Commit Sucess. i=" + QString::number(iResult)  +" o="+ QString::number(oResult) );
            DBManager::getDBManager()->getGoinDBConnection().commit();
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
}

void AllocationWin::sAbAudit(){
    TransVouchBean *bean = TransDAO::getTransBeanByNo(ui->noEdit->text().trimmed());
    if(bean !=NULL && bean->tvNo().length() > 0){
        if(!bean->isHandle()){
            ui->toolBar->actions().at(4)->setEnabled(true);
            ui->toolBar->actions().at(5)->setEnabled(false);
            QMessageBox::information(this,"提示","未审核，不能再弃审！");
            return ;
        }
        RdBean *rInBean = RdDAO::getRdByNo(bean->irdNo());
        if(rInBean->handler().length() > 0){
            QMessageBox::information(this,"提示","调拨入库单 " + bean->irdNo()+ " 已审核，请把调拨入库单弃审后，再弃审此单！");
            return ;
        }
        RdBean *rOutBean = RdDAO::getRdByNo(bean->ordNo());
        if(rOutBean->handler().length() > 0){
            QMessageBox::information(this,"提示","调拨出库单 " + bean->ordNo()+ " 已审核，请把调拨出库单弃审后，再弃审此单！");
            return ;
        }
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = 0;
        bean->setHandler("");
        bean->setIsHandle(false);
        bean->setUpdated(QDateTime::currentDateTime());
        bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        mResult = TransDAO::updateTrans(bean);
        int iResult = RdDAO::delRdByNo(rInBean);
        int oResult = RdDAO::delRdByNo(rOutBean);
        int iRdsResult = RdDAO::delRdsByNo(bean->irdNo());
        int oRdsResult = RdDAO::delRdsByNo(bean->ordNo());
        if(iResult < 1 || oResult < 1){
            if(QMessageBox::warning(this,"提示","生成的出入库调拨单已删除，是否弃审此调拨单" + ui->noEdit->text() + "?",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
                DBManager::getDBManager()->getGoinDBConnection().commit();
                ui->auditEdit->setText(bean->handler());
                ui->toolBar->actions().at(4)->setEnabled(true);
                ui->toolBar->actions().at(5)->setEnabled(false);
                readAuthority();
                QMessageBox::information(this,"提示","弃审成功！");
            }
        }else if(mResult > 0 && iResult>0 && oResult>0 && iRdsResult>0 && oRdsResult>0 && iRdsResult == oRdsResult
                && DBManager::getDBManager()->getGoinDBConnection().commit()){
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

void AllocationWin::sPrint(){
    QString fileName = "ReportPuArrival.xml";
    QString formatData = "";
    QList<ReportFormatBean *> rptList = ReportDAO::queryRptBy(mWinId);
    QString title = mWinTitle;
    if(rptList.size() > 0){
        formatData = rptList.at(rptList.size() - 1)->reportFormat();
    }else {
        formatData = PrintUtils::makeWinPrintFormatData(ui->gridLayout,mChildItem,mWinTitle,fileName);
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
        QString formatData2 = PrintUtils::makeWinPrintFormatData(ui->gridLayout,mChildItem,title,fileName);
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

void AllocationWin::sFirst(){
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
    QList<TransVouchBean *> rdBeanList = TransDAO::queryTransByPage(0,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->tvNo());
    }
    baseToolBar->actions().at(0)->setEnabled(false);
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(2)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(true);
}

void AllocationWin::sNext(){
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
    QList<TransVouchBean *> rdBeanList = TransDAO::queryTransByPage(mRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->tvNo());
    }
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(0)->setEnabled(true);
}

void AllocationWin::sPrevious(){
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
    QList<TransVouchBean *> rdBeanList = TransDAO::queryTransByPage(mRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->tvNo());
    }

    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(true);
}

void AllocationWin::sEnd(){
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
    mCountRecord = TransDAO::getTransCount() - 1;
    mRecord = mCountRecord;
    QList<TransVouchBean *> rdBeanList = TransDAO::queryTransByPage(mCountRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->tvNo());
    }
    baseToolBar->actions().at(0)->setEnabled(true);
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(false);
}

void AllocationWin::sCancel(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::No){
            return ;
        }
    }
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void AllocationWin::on_tableWidget_itemChanged(QTableWidgetItem *item)
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
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"unitPrice",0);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"quantity",1);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"money",0);

            if((ui->tableWidget->rowCount()-1) == item->row()){
                QAbstractItemModel *model = ui->tableWidget->model();
                int id = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toInt();
                if(mEditStatus == editFlag && id < 1){
                    //单据修改 增加数据
                    TransVouchsBean *sBean = new TransVouchsBean();
                    sBean->setTvNo(ui->noEdit->text());
                    WidgetBeanUtil::setItemModelToBean(model,item->row(),mChildItem,sBean);
                    mAddChildRdsList.append(sBean);
                }
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            }
        }else{
            QMessageBox::information(this,"提示","不存在此商品");

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

        if(item->column() == 4 || item->column()==5 || item->column()==8){
            if(id < 1 ){
                for(int i =0; i < mAddChildRdsList.size(); i++){
                    if(mAddChildRdsList.at(i)->productCode() == pCode){
                        double money = price * quantity;
                        mAddChildRdsList.at(i)->setQuantity(quantity);
                        mAddChildRdsList.at(i)->setUnitPrice(price);
                        mAddChildRdsList.at(i)->setMoney(money);

                    }

                }
            }
        }
        QString name = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"productName"))).toString();
        //单据修改 更新数据
        for(int i =0; i < mChildRdsList.size(); i++){
            if(mChildRdsList.at(i)->id() == id){
                double money = price * quantity;
                WidgetBeanUtil::setItemModelToBean(model,item->row(),mChildItem,mChildRdsList.at(i));
                mChildRdsList.at(i)->setMoney(money);

            }
        }

    }
}

void AllocationWin::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage){
    Q_UNUSED(reportPage);
    QGridLayout *layout = ui->gridLayout;
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




