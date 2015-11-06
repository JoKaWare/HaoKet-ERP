#include <QMessageBox>
#include <QStandardItemModel>
#include "areaform.h"
#include "dao/areadao.h"
#include "bean/AreaBean.h"
#include "ui_areaform.h"
#include "haokeapp.h"
#include "bean/DinnerBean.h"
#include "dao/dinnerdao.h"
#include "system/limitscommon.h"
#include "baplugin.h"
AreaForm::AreaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AreaForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,5);
    init();
}

AreaForm::~AreaForm()
{
    delete ui;
}

void AreaForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void AreaForm::init(){
    setInputEnabled(false);
    setButtonEnabled(false);
    m_id="";
    mWinId = HaoKeApp::baSubId() + BaPlugin::baAreaWinId();
    mWinTitle = "餐厅区域";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");

    refreshData();

}

void AreaForm::setInputEnabled(bool b){
    ui->nameEdit->setEnabled(b);
    ui->explianEdit->setEnabled(b);

}

void AreaForm::setButtonEnabled(bool b){

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

void AreaForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}

void AreaForm::on_newButton_clicked()
{
    setInputEnabled(true);
    statusEdit= addFlag;
    ui->saveButton->setEnabled(true);
    ui->nameEdit->setText("");
    ui->explianEdit->setText("");
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"newButton");

}

void AreaForm::on_editButton_clicked()
{
    setInputEnabled(true);
    statusEdit = editFlag;
    ui->saveButton->setEnabled(true);
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"editButton");

}

void AreaForm::on_saveButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"saveButton");
    if(ui->nameEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Dinner Area name"),QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;
    }
    if(statusEdit== addFlag){
        AreaBean *bean=new AreaBean(0);
        bean->setAreaName(ui->nameEdit->text().trimmed());
        bean->setAreaExplian(ui->explianEdit->text().trimmed());
        int status=AreaDAO::createArea(bean);
        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("New Dinner Area error"),QMessageBox::Ok );
        }

    }else if(statusEdit == editFlag){
        if(m_id.trimmed().length()<1){
            QMessageBox::warning(this, tr("Prompt"),tr("Please select Dinner Area"),QMessageBox::Ok );
            return ;
        }
        AreaBean *bean=new AreaBean(0);
        bean->setAreaId(m_id.toInt());
        bean->setAreaName(ui->nameEdit->text().trimmed());
        bean->setAreaExplian(ui->explianEdit->text().trimmed());
        int status=AreaDAO::updateArea(bean);

        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
            setButtonEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("Update Dinner Area error"),QMessageBox::Ok );
        }
    }
    refreshData();
}

void AreaForm::refreshData(){
    QList<AreaBean *> listBean=AreaDAO::queryArea();
    QStandardItemModel *model;
    model = new QStandardItemModel(listBean.size(),3);
    model->setHeaderData(0, Qt::Horizontal, tr("Area ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Area Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Area Explian"));
    int j=0;
    for(int i=0;i<listBean.size();i++){
        QStandardItem *itemId = new QStandardItem(QString::number(listBean.at(i)->areaId()));
        QStandardItem *itemName = new QStandardItem(listBean.at(i)->areaName());
        QStandardItem *itemEx = new QStandardItem(listBean.at(i)->areaExplian());
        model->setItem(i,0,itemId);
        model->setItem(i,1,itemName);
        model->setItem(i,2,itemEx);

    }
    ui->treeView->setModel(model);
}

void AreaForm::on_treeView_clicked(const QModelIndex &index)
{
    setInputEnabled(false);
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
    QString str=ui->treeView->model()->data(ui->treeView->model()->index(index.row(),0)).toString();
    m_id=str;
    AreaBean *dBean=AreaDAO::getAreaById(m_id);
    ui->nameEdit->setText(dBean->areaName());
    ui->explianEdit->setText(dBean->areaExplian());

    limitsInit();
}

void AreaForm::on_delButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"delButton");

    QList<DinnerBean *> listBean=DinnerDAO::queryDinnerByAreaId(m_id);
    if(listBean.size()>0){
        QMessageBox::warning(this, tr("Prompt"),tr("Not be deleted.In this area there is a dining table"),QMessageBox::Ok );
        return ;
    }
    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        AreaBean *bean=new AreaBean(0);
        bean->setAreaName(ui->nameEdit->text().trimmed());
        bean->setAreaExplian(ui->explianEdit->text().trimmed());
        bean->setAreaId(m_id.toInt());
        int status=AreaDAO::delArea(bean);
        if(status>0){
            m_id = "";
            ui->explianEdit->setText("");
            ui->nameEdit->setText("");
            refreshData();
            setInputEnabled(false);
            ui->delButton->setEnabled(false);
            ui->editButton->setEnabled(false);

        }
    }

}
