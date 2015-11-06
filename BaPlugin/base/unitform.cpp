#include "unitform.h"
#include "ui_unitform.h"
#include <QMessageBox>
#include "system/limitscommon.h"
#include "baplugin.h"
#include "haokeapp.h"
#include "bean/UnitBean.h"
#include "dao/unitdao.h"

UnitForm::UnitForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UnitForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,2);
    ui->splitter->setStretchFactor(1,5);
    init();
    refreshData();
}

UnitForm::~UnitForm()
{
    delete ui;
}

void UnitForm::init(){
    mWinId = HaoKeApp::baSubId() + BaPlugin::baUnitWinId();
    mWinTitle = "单位";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");

    setInputEnabled(false);
    setButtonEnabled(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void UnitForm::refreshData(){
    QList<UnitBean *> listBean=UnitDAO::queryUnit();
    QStandardItemModel *model;
    model = new QStandardItemModel(listBean.size(),3);
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Unit Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Translated Unit"));

    for(int i=0;i<listBean.size();i++){
        QStandardItem *itemId = new QStandardItem(QString::number(listBean.at(i)->id()));
        QStandardItem *itemName = new QStandardItem(listBean.at(i)->unitName());
        QStandardItem *itemEx = new QStandardItem(listBean.at(i)->translatedUnit());
        model->setItem(i,0,itemId);
        model->setItem(i,1,itemName);
        model->setItem(i,2,itemEx);

    }
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,60);
    ui->tableView->setColumnWidth(1,80);
    ui->tableView->setColumnWidth(2,80);
}

void UnitForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}

void UnitForm::setInputEnabled(bool b){
    ui->nameEdit->setEnabled(b);
    ui->captionEdit->setEnabled(b);
}

void UnitForm::setButtonEnabled(bool b){

    if(b){
        ui->editButton->setEnabled(b);
        ui->delButton->setEnabled(false);
        if(m_status == addFlag || m_status == editFlag)
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

void UnitForm::on_tableView_clicked(const QModelIndex &index)
{
    setInputEnabled(false);
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
    QString str=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    m_id=str;
    UnitBean *bean = UnitDAO::getUnit(m_id);
    ui->nameEdit->setText(bean->unitName());
    ui->captionEdit->setText(bean->translatedUnit());
    limitsInit();
}

void UnitForm::on_newButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"newButton");

    m_status = addFlag;
    setButtonEnabled(true);
    setInputEnabled(true);
    ui->editButton->setEnabled(false);
    ui->captionEdit->clear();
    ui->nameEdit->clear();
}

void UnitForm::on_editButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"editButton");

    m_status = editFlag;
    ui->editButton->setEnabled(false);
    ui->saveButton->setEnabled(true);
    setInputEnabled(true);
}

void UnitForm::on_saveButton_clicked()
{
    if(ui->nameEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Unit name"),QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;

    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"saveButton");

    if(m_status == addFlag){
        UnitBean *bean = new UnitBean();
        bean->setUnitName(ui->nameEdit->text().trimmed());
        bean->setTranslatedUnit(ui->captionEdit->text().trimmed());
        int result = UnitDAO::createUnit(bean);
        if(result > 0){
            QMessageBox::information(this,tr("Prompt"),tr("Unit Save Success"));
            refreshData();
            setButtonEnabled(false);
            setInputEnabled(false);
        }else{
            QMessageBox::information(this,tr("Prompt"),tr("Unit Save Error"));
        }
    }else if(m_status == editFlag){
        UnitBean *bean = new UnitBean();
        bean->setId(m_id.toInt());
        bean->setUnitName(ui->nameEdit->text().trimmed());
        bean->setTranslatedUnit(ui->captionEdit->text().trimmed());
        int result = UnitDAO::updateUnit(bean);
        if(result > 0){
            QMessageBox::information(this,tr("Prompt"),tr("Unit Update Success"));
            refreshData();
            setButtonEnabled(false);
            setInputEnabled(false);
        }else{
            QMessageBox::information(this,tr("Prompt"),tr("Unit Update Error"));
        }
    }

}

void UnitForm::on_delButton_clicked()
{
    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),
                            QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        //写入操作日志
        HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"delButton");

        UnitBean *bean = UnitDAO::getUnit(m_id);
        int result = UnitDAO::delUnit(bean);
        if(result > 0){
            m_id = "";
            ui->nameEdit->clear();
            ui->captionEdit->clear();
            setButtonEnabled(false);
            setInputEnabled(false);
            refreshData();

        }
    }
}

void UnitForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}
