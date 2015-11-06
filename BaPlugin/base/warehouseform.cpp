#include "warehouseform.h"
#include "ui_warehouseform.h"
#include "haokeapp.h"
#include "system/limitscommon.h"
#include "bean/DepBean.h"
#include "bean/EmployeeBean.h"
#include "dao/depdao.h"
#include "dao/employeedao.h"
#include "dao/rddao.h"
#include "baplugin.h"
#include <QMessageBox>
WareHouseForm::WareHouseForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WareHouseForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    init();
}

WareHouseForm::~WareHouseForm()
{
    delete ui;
}

void WareHouseForm::init(){
    mWinId = HaoKeApp::baSubId() + BaPlugin::baWareWinId();
    mWinTitle = "仓库资料";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");

    setInputEnabled(false);
    setButtonEnabled(false);
    mId="";
    refreshData();

    QList<EmployeeBean *> personBean = EmployeeDAO::queryEmp();
    QList<DepBean *> depBeanList = DepDAO::queryDepByEnd();
    QStringList personList;
    QStringList depList;
    ui->personQksearchEditbox->setListModel(true);
    ui->depQksearchEditbox->setListModel(true);
    for(int i = 0;i<depBeanList.size();i++){
        depList<< depBeanList.at(i)->depId() + " - " + depBeanList.at(i)->depName();

    }
    for(int i = 0;i<personBean.size();i++){
        personList<<QString::number(personBean.at(i)->empId()) + " - " + personBean.at(i)->empName();
    }
    ui->depQksearchEditbox->setItems(depList);
    ui->personQksearchEditbox->setItems(personList);
}

void WareHouseForm::refreshData(){
    QList<WareHouseBean *> listBean=WareDAO::queryWarehouse();
    QStandardItemModel *model;
    model = new QStandardItemModel(listBean.size(),2);
    model->setHeaderData(0, Qt::Horizontal, tr("Warehouse Code"));
    model->setHeaderData(1, Qt::Horizontal, tr("Warehouse Name"));


    for(int i=0;i<listBean.size();i++){
        QStandardItem *itemId = new QStandardItem(listBean.at(i)->whCode());
        QStandardItem *itemName = new QStandardItem(listBean.at(i)->whName());

        model->setItem(i,0,itemId);
        model->setItem(i,1,itemName);


    }
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,80);
    ui->tableView->setColumnWidth(1,120);
}

void WareHouseForm::setInputEnabled(bool b){
    ui->nameEdit->setEnabled(b);
    ui->codeEdit->setEnabled(b);
    ui->addrEdit->setEnabled(b);
    ui->phoneEdit->setEnabled(b);
    ui->personQksearchEditbox->setEnabled(b);
    ui->depQksearchEditbox->setEnabled(b);
    ui->cargoCheckBox->setEnabled(b);
    ui->shopCheckBox->setEnabled(b);
    ui->memoEdit->setEnabled(b);

}

void WareHouseForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}
void WareHouseForm::setButtonEnabled(bool b){

    if(b){
        ui->editButton->setEnabled(b);
        ui->delButton->setEnabled(b);
        if(mEditStatus == addFlag || mEditStatus == editFlag)
            ui->saveButton->setEnabled(b);
        else
            ui->saveButton->setEnabled(false);
    }else{
        ui->editButton->setEnabled(false);
        ui->saveButton->setEnabled(false);
        ui->delButton->setEnabled(false);
    }
    limitsInit();
}


void WareHouseForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void WareHouseForm::on_newButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"newButton");

    mEditStatus = addFlag;
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->codeEdit->clear();
    ui->nameEdit->clear();
    ui->addrEdit->clear();
    ui->phoneEdit->clear();
    ui->depQksearchEditbox->clear();
    ui->personQksearchEditbox->clear();
    ui->memoEdit->clear();
}

void WareHouseForm::on_editButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"editButton");

    mEditStatus = editFlag;
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->codeEdit->setEnabled(false);

}

void WareHouseForm::on_saveButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"saveButton");

    if(ui->nameEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),"请输入仓库名称",QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;

    }
    if(ui->codeEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),"请输入仓库编码",QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;
    }
    if(mEditStatus == addFlag){
        WareHouseBean *wBean = new WareHouseBean();
        wBean->setWhCode(ui->codeEdit->text().trimmed());
        wBean->setWhName(ui->nameEdit->text().trimmed());
        wBean->setWhAddr(ui->addrEdit->text().trimmed());
        wBean->setWhTel(ui->phoneEdit->text().trimmed());
        wBean->setWhPerson(ui->personQksearchEditbox->text().toInt());
        wBean->setDepCode(ui->depQksearchEditbox->text());
        wBean->setMemo(ui->memoEdit->text().trimmed());
        wBean->setIsCargo(ui->cargoCheckBox->isChecked());
        wBean->setIsShop(ui->shopCheckBox->isChecked());
        int result = WareDAO::createWarehouse(wBean);
        if(result > 0){
            QMessageBox::information(this,"提示","添加仓库成功");
            refreshData();
            setButtonEnabled(false);
            setInputEnabled(false);
        }else{
            QMessageBox::critical(this,"错误","添加仓库出错");
        }

    }else if(mEditStatus == editFlag){

        WareHouseBean *wBean = WareDAO::getWarehouseById(mId);
        wBean->setWhName(ui->nameEdit->text().trimmed());
        wBean->setWhAddr(ui->addrEdit->text().trimmed());
        wBean->setWhTel(ui->phoneEdit->text().trimmed());
        wBean->setWhPerson(ui->personQksearchEditbox->text().toInt());
        wBean->setDepCode(ui->depQksearchEditbox->text());
        wBean->setMemo(ui->memoEdit->text().trimmed());
        wBean->setIsCargo(ui->cargoCheckBox->isChecked());
        wBean->setIsShop(ui->shopCheckBox->isChecked());
        int result = WareDAO::updateWarehouse(wBean);
        if(result > 0){
            QMessageBox::information(this,"提示","修改仓库成功");
            refreshData();
            setButtonEnabled(false);
            setInputEnabled(false);
        }else{
            QMessageBox::critical(this,"错误","修改仓库出错");
        }
    }
}

void WareHouseForm::on_delButton_clicked()
{
    mId = ui->codeEdit->text().trimmed();
    if(mId.length() < 1){
        QMessageBox::information(this,"提示","未选择行,不能删除");
        return ;
    }
    if(RdDAO::getRdsCountByWh(mId) > 0){
        QMessageBox::information(this,"提示","此仓库已产生业务数据,不能删除",QMessageBox::Ok);
        ui->delButton->setEnabled(false);
        return ;
    }

    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        //写入操作日志
        HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"delButton");

        WareHouseBean *wBean = WareDAO::getWarehouseById(mId);
        int result = WareDAO::delWarehouse(wBean);
        if(result > 0){
            ui->codeEdit->clear();
            ui->nameEdit->clear();
            ui->addrEdit->clear();
            ui->phoneEdit->clear();

            ui->memoEdit->clear();
            ui->depQksearchEditbox->setText("");
            ui->personQksearchEditbox->setText("");
            refreshData();
            setInputEnabled(false);
            ui->delButton->setEnabled(false);
            ui->editButton->setEnabled(false);
            mId = "";
        }
    }
}

void WareHouseForm::on_tableView_clicked(const QModelIndex &index)
{
    setInputEnabled(false);
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
    QString str = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    mId = str;
    WareHouseBean *bean = WareDAO::getWarehouseById(mId);
    if(bean == NULL) return;
    DepBean *dBean = DepDAO::getDepById(bean->depCode());
    EmployeeBean *eBean = EmployeeDAO::getEmpById(QString::number(bean->whPerson()));
    ui->nameEdit->setText(bean->whName());
    ui->codeEdit->setText(bean->whCode());
    ui->addrEdit->setText(bean->whAddr());
    ui->phoneEdit->setText(bean->whTel());
    ui->depQksearchEditbox->setText(dBean->depId() + " - " + dBean->depName() );

    ui->personQksearchEditbox->setText(QString::number(eBean->empId()) + " - " + eBean->empName());
    ui->cargoCheckBox->setChecked(bean->isCargo());
    ui->shopCheckBox->setChecked(bean->isShop());
    ui->memoEdit->setText(bean->memo());
    limitsInit();

}
