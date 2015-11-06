#include <QMessageBox>
#include "tasteform.h"
#include "ui_tasteform.h"
#include "haokeapp.h"
#include "bean/TasteBean.h"
#include "dao/tastedao.h"
#include "system/limitscommon.h"
#include "baplugin.h"
TasteForm::TasteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TasteForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    init();
    refreshData();
}

TasteForm::~TasteForm()
{
    delete ui;
}

void TasteForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void TasteForm::init(){
    setInputEnabled(false);
    setButtonEnabled(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void TasteForm::refreshData(){
    QList<TasteBean *> listBean=TasteDAO::queryTaste();
    QStandardItemModel *model;
    model = new QStandardItemModel(listBean.size(),3);
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Taste Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Taste Caption"));

    for(int i=0;i<listBean.size();i++){
        QStandardItem *itemId = new QStandardItem(QString::number(listBean.at(i)->id()));
        QStandardItem *itemName = new QStandardItem(listBean.at(i)->tasteName());
        QStandardItem *itemEx = new QStandardItem(listBean.at(i)->tasteCaption());
        model->setItem(i,0,itemId);
        model->setItem(i,1,itemName);
        model->setItem(i,2,itemEx);

    }
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,60);
    ui->tableView->setColumnWidth(1,120);
    ui->tableView->setColumnWidth(2,240);
}

void TasteForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}

void TasteForm::setInputEnabled(bool b){
    ui->nameEdit->setEnabled(b);
    ui->captionEdit->setEnabled(b);
}

void TasteForm::setButtonEnabled(bool b){

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

void TasteForm::on_newButton_clicked()
{
    m_status = addFlag;
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"newButton");

    setButtonEnabled(true);
    setInputEnabled(true);
    ui->editButton->setEnabled(false);
    ui->captionEdit->clear();
    ui->nameEdit->clear();
}

void TasteForm::on_saveButton_clicked()
{
    if(ui->nameEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Taste name"),QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;

    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"saveButton");

    if(m_status == addFlag){
        TasteBean *bean = new TasteBean();
        bean->setTasteName(ui->nameEdit->text().trimmed());
        bean->setTasteCaption(ui->captionEdit->text().trimmed());
        int result = TasteDAO::createTaste(bean);
        if(result > 0){
            QMessageBox::information(this,tr("Prompt"),tr("Taste Save Success"));
            refreshData();
            setButtonEnabled(false);
            setInputEnabled(false);
        }else{
            QMessageBox::information(this,tr("Prompt"),tr("Taste Save Error"));
        }
    }else if(m_status == editFlag){
        TasteBean *bean = new TasteBean();
        bean->setId(m_id.toInt());
        bean->setTasteName(ui->nameEdit->text().trimmed());
        bean->setTasteCaption(ui->captionEdit->text().trimmed());
        int result = TasteDAO::updateTaste(bean);
        if(result > 0){
            QMessageBox::information(this,tr("Prompt"),tr("Taste Update Success"));
            refreshData();
            setButtonEnabled(false);
            setInputEnabled(false);
        }else{
            QMessageBox::information(this,tr("Prompt"),tr("Taste Update Error"));
        }
    }
}

void TasteForm::on_editButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"editButton");

    m_status = editFlag;
    ui->editButton->setEnabled(false);
    ui->saveButton->setEnabled(true);
    setInputEnabled(true);
}

void TasteForm::on_tableView_clicked(const QModelIndex &index)
{

    setInputEnabled(false);
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
    QString str=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    m_id=str;
    TasteBean *bean = TasteDAO::getTaste(m_id);
    ui->nameEdit->setText(bean->tasteName());
    ui->captionEdit->setText(bean->tasteCaption());
    limitsInit();
}

void TasteForm::on_delButton_clicked()
{
    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),
                            QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        TasteBean *bean = TasteDAO::getTaste(m_id);
        //写入操作日志
        HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"delButton");

        int result = TasteDAO::delTaste(bean);
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
