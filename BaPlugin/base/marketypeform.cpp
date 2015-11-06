#include <QMessageBox>
#include <QTime>
#include "marketypeform.h"
#include "ui_marketypeform.h"
#include "haokeapp.h"
#include "common/common.h"
#include "bean/MarketTypeBean.h"
#include "dao/markettypedao.h"
#include "system/limitscommon.h"
#include "baplugin.h"
MarkeTypeForm::MarkeTypeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarkeTypeForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,5);
    init();
}

MarkeTypeForm::~MarkeTypeForm()
{
    delete ui;
}
void MarkeTypeForm::init(){
    setInputEnabled(false);
    setButtonEnabled(false);
    m_id="";
    refreshData();

}

void MarkeTypeForm::setInputEnabled(bool b){
    ui->nameEdit->setEnabled(b);
    ui->dateTimeEdit->setEnabled(b);
    ui->aliaEdit->setEnabled(b);
    ui->memoEdit->setEnabled(b);

}
void MarkeTypeForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}

void MarkeTypeForm::setButtonEnabled(bool b){

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
void MarkeTypeForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void MarkeTypeForm::on_newButton_clicked()
{
    statusEdit = addFlag;
    setInputEnabled(true);
    ui->dateTimeEdit->clear();
    ui->nameEdit->clear();
    ui->saveButton->setEnabled(true);
}

void MarkeTypeForm::refreshData(){
    QList<MarketTypeBean *> listBean=MarketTypeDAO::queryMarketType();
    QStandardItemModel *model;
    model = new QStandardItemModel(listBean.size(),3);
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Market Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Market Time"));
    int j=0;
    for(int i=0;i<listBean.size();i++){
        QStandardItem *itemId = new QStandardItem(QString::number(listBean.at(i)->marketTypeId()));
        QStandardItem *itemName = new QStandardItem(listBean.at(i)->marketTypeName());
        QStandardItem *itemEx = new QStandardItem(listBean.at(i)->marketTypeStart());
        model->setItem(i,0,itemId);
        model->setItem(i,1,itemName);
        model->setItem(i,2,itemEx);

    }
    ui->tableView->setModel(model);

}

void MarkeTypeForm::on_saveButton_clicked()
{
    if(ui->nameEdit->text().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Market Type name"),QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;
    }
    if(ui->dateTimeEdit->text().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Market Type start time"),QMessageBox::Ok );
        ui->dateTimeEdit->setFocus();
        return ;
    }
    if(statusEdit == addFlag){
        MarketTypeBean *bean=new MarketTypeBean;
        bean->setMarketTypeName(ui->nameEdit->text().trimmed());
        bean->setMarketTypeStart(ui->dateTimeEdit->text().trimmed());
        bean->setMarketTypeAlia(ui->aliaEdit->text().trimmed());
        bean->setMemo(ui->memoEdit->document()->toPlainText());
        int status=MarketTypeDAO::createMarketType(bean);
        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("New Market Type error"),QMessageBox::Ok );
        }


    }else if(statusEdit == editFlag){
        if(m_id.trimmed().length()<1){
            QMessageBox::warning(this, tr("Prompt"),tr("Please select Market Type"),QMessageBox::Ok );
            return ;
        }
        MarketTypeBean *bean=new MarketTypeBean(0);
        bean->setMarketTypeId(m_id.toInt());
        bean->setMarketTypeName(ui->nameEdit->text().trimmed());
        bean->setMarketTypeStart(ui->dateTimeEdit->text().trimmed());
        bean->setMarketTypeAlia(ui->aliaEdit->text().trimmed());
        bean->setMemo(ui->memoEdit->document()->toPlainText());
        int status=MarketTypeDAO::updateMarketType(bean);
        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
            setButtonEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("Update Market Type error"),QMessageBox::Ok );
        }
    }
    refreshData();
}

void MarkeTypeForm::on_tableView_clicked(const QModelIndex &index)
{
    setInputEnabled(false);
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
    QString str=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    m_id=str;
    MarketTypeBean *dBean=MarketTypeDAO::getMarketTypeById(m_id);
    ui->nameEdit->setText(dBean->marketTypeName());
    QTime t=QTime::fromString(dBean->marketTypeStart());
    ui->dateTimeEdit->setTime(t);
    ui->aliaEdit->setText(dBean->marketTypeAlia());
    ui->memoEdit->setPlainText(dBean->memo());
    limitsInit();
}

void MarkeTypeForm::on_editButton_clicked()
{
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);
    statusEdit = editFlag;
}

void MarkeTypeForm::on_delButton_clicked()
{
    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        /*
        QList<SaleBean *> sBeanList = SaleDAO::querySaleByMarket(m_id.toInt());
        if(sBeanList.size() > 0 ){
            QMessageBox::critical(this, tr("Error"),tr("市别已使用,不能删除"),QMessageBox::Ok );
            return;
        }
        */
        MarketTypeBean *bean=new MarketTypeBean(0);
        bean->setMarketTypeName(ui->nameEdit->text().trimmed());
        bean->setMarketTypeStart(ui->dateTimeEdit->text().trimmed());
        bean->setMarketTypeId(m_id.toInt());
        int status=MarketTypeDAO::delMarketType(bean);
        if(status>0){
            m_id = "";
            ui->dateTimeEdit->clear();
            ui->nameEdit->setText("");
            ui->aliaEdit->clear();
            ui->memoEdit->clear();
            refreshData();
            setInputEnabled(false);
            ui->delButton->setEnabled(false);
            ui->editButton->setEnabled(false);

        }
    }
}
