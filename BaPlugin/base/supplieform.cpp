#include <QMessageBox>
#include "supplieform.h"
#include "ui_supplieform.h"
#include "haokeapp.h"
#include "bean/SupplieBean.h"
#include "dao/suppliedao.h"
#include "dao/rddao.h"
#include "dao/supplietypedao.h"
#include "bean/SupplieTypeBean.h"
#include "system/limitscommon.h"
#include "baplugin.h"
SupplieForm::SupplieForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SupplieForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    init();
}

SupplieForm::~SupplieForm()
{
    delete ui;
}

void SupplieForm::init(){
    mWinId = HaoKeApp::baSubId() + BaPlugin::baSupWinId();
    mWinTitle = "供应商资料";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");

    setInputEnabled(false);
    setButtonEnabled(false);
    ui->typeQsk->clear();
    /*
    ui->typeComboBox->addItem(tr("蔬菜供应商"));
    ui->typeComboBox->addItem(tr("肉类供应商"));
    ui->typeComboBox->addItem(tr("面食供应商"));
    ui->typeComboBox->addItem(tr("海鲜供应商"));
    ui->typeComboBox->addItem(tr("水果供应商"));
    ui->typeComboBox->addItem(tr("酒水供应商"));
    ui->typeComboBox->addItem(tr("其他"));
    */
    QList<SupplieTypeBean *> listBean=SupplieTypeDAO::queryType();
    QList<QString> typeList;
    for(int i = 0; i < listBean.size(); i ++ ){
        typeList << listBean.at(i)->typeId() + " - " + listBean.at(i)->typeName();
    }

    ui->typeQsk->setListModel(true);
    ui->typeQsk->setItems(typeList);
    refreshData();
}

void SupplieForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}

void SupplieForm::setInputEnabled(bool b){
    ui->nameEdit->setEnabled(b);
    ui->typeQsk->setEnabled(b);
    ui->explianEdit->setEnabled(b);
    ui->codeEdit->setEnabled(b);
    ui->statusCheckBox->setEnabled(b);
    ui->addrEdit->setEnabled(b);
    ui->manEdit->setEnabled(b);
    ui->phoneEdit->setEnabled(b);
    ui->funcEdit->setEnabled(b);
    ui->taxEdit->setEnabled(b);
    ui->bankCardEdit->setEnabled(b);
    ui->bankEdit->setEnabled(b);
    ui->bankNameEdit->setEnabled(b);
    ui->memoEdit->setEnabled(b);

}
void SupplieForm::setInputClear(){
    ui->nameEdit->clear();
    ui->typeQsk->clear();
    ui->explianEdit->clear();
    ui->addrEdit->clear();
    ui->manEdit->clear();
    ui->phoneEdit->clear();
    ui->funcEdit->clear();
    ui->taxEdit->clear();
    ui->bankCardEdit->clear();
    ui->bankEdit->clear();
    ui->bankNameEdit->clear();
    ui->manEdit->clear();
}
void SupplieForm::setButtonEnabled(bool b){
    if(b){
        ui->editButton->setEnabled(b);
        ui->delButton->setEnabled(b);
        if(statusEdit == addFlag || statusEdit == editFlag)
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

void SupplieForm::refreshData(){
    QList<SupplieBean *> listBean=SupplieDAO::querySupplieAll();
    QStandardItemModel *model;
    model = new QStandardItemModel(listBean.size(),2);
    model->setHeaderData(0, Qt::Horizontal, tr("Supplie ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Supplie Name"));

    int j=0;
    for(int i=0;i<listBean.size();i++){
        QStandardItem *itemId = new QStandardItem(listBean.at(i)->supplieCode());
        QStandardItem *itemName = new QStandardItem(listBean.at(i)->supplieName());

        model->setItem(i,0,itemId);
        model->setItem(i,1,itemName);


    }
    ui->treeView->setModel(model);

}

void SupplieForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void SupplieForm::on_newButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"newButton");

    setInputEnabled(true);
    statusEdit = addFlag;
    ui->saveButton->setEnabled(true);
    setInputClear();
}

void SupplieForm::on_editButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"editButton");

    setInputEnabled(true);
    ui->codeEdit->setEnabled(false);
    statusEdit = editFlag;
    ui->saveButton->setEnabled(true);
}

void SupplieForm::on_saveButton_clicked()
{
    if(ui->codeEdit->text().trimmed().length()<1){
        QMessageBox::warning(this,"提示","请输入供应商编码",QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;
    }
    if(ui->nameEdit->text().trimmed().length()<1){
        QMessageBox::warning(this,"提示","请输入供应商名称",QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;
    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"saveButton");

    if(statusEdit == addFlag){
        SupplieBean *bean=new SupplieBean;
        bean->setSupplieName(ui->nameEdit->text().trimmed());
        bean->setSupplieCode(ui->codeEdit->text().trimmed());
        bean->setSupplieType(ui->typeQsk->text().trimmed());
        bean->setSupplieExplian(ui->explianEdit->text().trimmed());
        if(ui->statusCheckBox->isChecked()){
            bean->setStatus(0);
        }else bean->setStatus(1);
        bean->setBank(ui->bankEdit->text().trimmed());
        bean->setBankCard(ui->bankCardEdit->text().trimmed());
        bean->setBankName(ui->bankNameEdit->text().trimmed());
        bean->setAddr(ui->addrEdit->text().trimmed());
        bean->setLinkman(ui->manEdit->text().trimmed());
        bean->setLinkFunc(ui->funcEdit->text().trimmed());
        bean->setLinkPhone(ui->phoneEdit->text().trimmed());
        bean->setMemo(ui->memoEdit->text().trimmed());
        bean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        QDateTime d=QDateTime::currentDateTime();
        bean->setCreated(d);
        bean->setUpdated(d);
        int status=SupplieDAO::createSupplie(bean);
        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("New Supplie error"),QMessageBox::Ok );
        }
    }else if(statusEdit == editFlag){
        SupplieBean *bean=new SupplieBean;
        bean->setSupplieCode(ui->codeEdit->text().trimmed());
        bean->setSupplieName(ui->nameEdit->text().trimmed());
        bean->setSupplieType(ui->typeQsk->text().trimmed());
        bean->setSupplieExplian(ui->explianEdit->text().trimmed());
        if(ui->statusCheckBox->isChecked()){
            bean->setStatus(0);
        }else bean->setStatus(1);
        bean->setBank(ui->bankEdit->text().trimmed());
        bean->setBankCard(ui->bankCardEdit->text().trimmed());
        bean->setBankName(ui->bankNameEdit->text().trimmed());
        bean->setAddr(ui->addrEdit->text().trimmed());
        bean->setLinkman(ui->manEdit->text().trimmed());
        bean->setLinkFunc(ui->funcEdit->text().trimmed());
        bean->setLinkPhone(ui->phoneEdit->text().trimmed());
        bean->setMemo(ui->memoEdit->text().trimmed());

        bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        bean->setSupplieId(m_id.toInt());
        QDateTime d=QDateTime::currentDateTime();
        bean->setUpdated(d);
        int status=SupplieDAO::updateSupplie(bean);
        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
            setButtonEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("Update Supplie error"),QMessageBox::Ok );
        }

    }
    refreshData();
    limitsInit();
}

void SupplieForm::on_delButton_clicked()
{
    m_id = ui->codeEdit->text().trimmed();
    if(m_id.length() < 1){
        QMessageBox::information(this,"提示","未选择行,不能删除");
        return ;
    }
    if(RdDAO::getRdsCountByVen(m_id) > 0){
        QMessageBox::information(this,"提示","此供应商已产生业务数据,不能删除",QMessageBox::Ok);
        ui->delButton->setEnabled(false);
        return ;
    }
    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        //写入操作日志
        HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"delButton");

        SupplieBean *bean = new SupplieBean;
        bean->setSupplieId(m_id.toInt());
        int status = SupplieDAO::delSupplie(bean);
        if(status > 0){
            m_id = "";
            setInputClear();
            setButtonEnabled(false);
            refreshData();

        }

    }

}

void SupplieForm::on_treeView_clicked(const QModelIndex &index)
{
    setInputEnabled(false);
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
    QString str=ui->treeView->model()->data(ui->treeView->model()->index(index.row(),0)).toString();
    m_id=str;
    SupplieBean *bean=new SupplieBean;
    bean=SupplieDAO::getSupplieByCode(str);
    ui->codeEdit->setText(bean->supplieCode());
    ui->nameEdit->setText(bean->supplieName());
    ui->explianEdit->setText(bean->supplieExplian());
    SupplieTypeBean *typeBean = SupplieTypeDAO::getTypeById(bean->supplieType());
    if(typeBean){
        ui->typeQsk->setText(bean->supplieType() + " - " + typeBean->typeName());
    }else{
        ui->typeQsk->setText(bean->supplieType());
    }
    if(bean->status() == 0){
        ui->statusCheckBox->setChecked(true);
    }else ui->statusCheckBox->setChecked(false);

    ui->addrEdit->setText(bean->addr());
    ui->memoEdit->setText(bean->memo());
    ui->phoneEdit->setText(bean->linkPhone());
    ui->taxEdit->setText(bean->tax());
    ui->manEdit->setText(bean->linkman());
    ui->funcEdit->setText(bean->linkFunc());
    ui->bankEdit->setText(bean->bank());
    ui->bankCardEdit->setText(bean->bankCard());
    ui->bankNameEdit->setText(bean->bankName());
    limitsInit();

}
