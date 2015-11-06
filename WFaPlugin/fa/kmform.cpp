#include "kmform.h"
#include "ui_kmform.h"
#include "bean/KmCodeBean.h"
#include "dao/kmcodedao.h"
#include "wfaplugin.h"
#include "haokeapp.h"
KmForm::KmForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KmForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    init();
    ui->treeView->expandAll();
}

KmForm::~KmForm()
{
    delete ui;
}

void KmForm::init(){
    setInputEnabled(false);
    setButtonEnabled(false);
    mId="";
    mWinId = HaoKeApp::faSubId() + WFaPlugin::kmWinId();
    mWinTitle = "客户分类";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::faSubId().toInt(),mWinId.toInt(),0,"");

    ui->propertyCmb->addItem("借");
    ui->propertyCmb->addItem("贷");
    refreshData();
}

void KmForm::refreshData(){
    QList<KmCodeBean *> listFirstBean = KmCodeDAO::queryKmCodeFirst();
    QList<KmCodeBean *> listBean = KmCodeDAO::queryKmCode();
    QStandardItemModel *model;
    model = new QStandardItemModel(listFirstBean.size(),1);
    model->setHeaderData(0, Qt::Horizontal, "科目");

    int j=0;
    for(int i=0;i<listBean.size();i++){
        if(listBean.at(i)->grade()==1){
            QString str="("+listBean.at(i)->kmCode()+") "+listBean.at(i)->kmName();
            QStandardItem *item = new QStandardItem();
            item->setText(str);
            for(int k=0;k<listBean.size();k++){
                if(listBean.at(k)->grade()==2){
                    QString str1="("+listBean.at(k)->kmCode()+") "+listBean.at(k)->kmName();
                    int len = listBean.at(i)->kmCode().trimmed().length();
                    if(listBean.at(i)->kmCode().contains(listBean.at(k)->kmCode().mid(0,len))){
                        QStandardItem *childItem = new QStandardItem(str1);
                        for(int h = 0;h < listBean.size() ; h++ ){
                            if(listBean.at(h)->grade()==3){
                                QString str2="("+listBean.at(h)->kmCode()+") "+listBean.at(h)->kmName();
                                len = listBean.at(k)->kmCode().trimmed().length();
                                if(listBean.at(k)->kmCode().contains(listBean.at(h)->kmCode().mid(0,len))){
                                    QStandardItem *childItem3 = new QStandardItem(str2);
                                    childItem->appendRow(childItem3);
                                }

                            }
                        }
                        item->appendRow(childItem);
                    }
                }
            }
            model->setItem(j, 0, item);
            j = j + 1;
        }
    }

    ui->treeView->setModel(model);
}
void KmForm::limitsInit(){
    WFaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}

void KmForm::setInputEnabled(bool b){
    ui->nameEdit->setEnabled(b);
    ui->codeEdit->setEnabled(b);

    ui->isEndChk->setEnabled(b);
    ui->isCusChk->setEnabled(b);
    ui->isSupChk->setEnabled(b);
    ui->isCashChk->setEnabled(b);
    ui->isBankChk->setEnabled(b);
    ui->explianEdit->setEnabled(b);
    ui->sCodeEdit->setEnabled(b);
}


void KmForm::setButtonEnabled(bool b){
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

void KmForm::on_newButton_clicked()
{
    mEditStatus = addFlag;
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->nameEdit->clear();
    ui->explianEdit->clear();
    ui->isEndChk->setCheckable(true);
    ui->sCodeEdit->setText(ui->codeEdit->text());
}

void KmForm::on_editButton_clicked()
{
    mEditStatus = editFlag;
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->codeEdit->setEnabled(false);

}

void KmForm::on_saveButton_clicked()
{
    if(ui->nameEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, "提示","请输入科目名称",QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;

    }
    if(ui->codeEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, "提示","请输入科目编码",QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;

    }

    if(mEditStatus == addFlag){

        KmCodeBean *bean=new KmCodeBean;

        bean->setKmCode(ui->codeEdit->text().trimmed());
        KmCodeBean *kmBean= KmCodeDAO::getKmCode(bean->kmCode());
        if(kmBean && kmBean->kmName().length() > 1){
            QMessageBox::critical(this, "错误","科目编码已存在",QMessageBox::Ok );
            ui->codeEdit->setFocus();
            return ;
        }
        bean->setKmName(ui->nameEdit->text().trimmed());
        bean->setKmExplain(ui->explianEdit->text().trimmed());
        bean->setCode(ui->sCodeEdit->text().trimmed());
        bean->setIsEnd(ui->isEndChk->isChecked());
        bean->setIsCus(ui->isCusChk->isChecked());
        bean->setIsSup(ui->isSupChk->isChecked());
        bean->setIsCash(ui->isCashChk->isChecked());
        bean->setIsBank(ui->isBankChk->isChecked());
        if(ui->propertyCmb->currentText()=="借"){
            bean->setProperty(0);
        }else bean->setProperty(1);
        if(ui->codeEdit->text().trimmed().length()<4){
            bean->setGrade(1);
        }else{
            if(ui->codeEdit->text().trimmed().length() < 7)bean->setGrade(2);
            else if (ui->codeEdit->text().trimmed().length() < 10)bean->setGrade(3);
            else bean->setGrade(4);
            int len = ui->codeEdit->text().length() - (bean->grade()-1)*3;
            QString supCode = ui->codeEdit->text().mid(0,len);
            KmCodeBean *supKmBean = KmCodeDAO::getKmCode(supCode);
            if(supKmBean && supKmBean->kmCode().length() > 1){

            }else{
                QMessageBox::critical(this, "错误","上级科目" + supCode + "不存在",QMessageBox::Ok );
                return ;
            }
        }
        int status = KmCodeDAO::createKmCode(bean);
        if(status > 0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);

        }else{
            QMessageBox::critical(this, "错误","新增科目保存错误",QMessageBox::Ok );
        }

    }else if(mEditStatus == editFlag){
        KmCodeBean *bean=new KmCodeBean;
        bean->setKmCode(ui->codeEdit->text().trimmed());
        bean->setKmName(ui->nameEdit->text().trimmed());
        bean->setKmExplain(ui->explianEdit->text().trimmed());
        bean->setCode(ui->sCodeEdit->text().trimmed());
        bean->setIsEnd(ui->isEndChk->isChecked());
        bean->setIsCus(ui->isCusChk->isChecked());
        bean->setIsSup(ui->isSupChk->isChecked());
        bean->setIsCash(ui->isCashChk->isChecked());
        bean->setIsBank(ui->isBankChk->isChecked());
        if(ui->propertyCmb->currentText()=="借"){
            bean->setProperty(0);
        }else bean->setProperty(1);
        if(ui->codeEdit->text().trimmed().length()<4){
            bean->setGrade(1);
        }else{
            if(ui->codeEdit->text().trimmed().length() < 7)bean->setGrade(2);
            else if (ui->codeEdit->text().trimmed().length() < 10)bean->setGrade(3);
            else bean->setGrade(4);

        }
        int status = KmCodeDAO::updateKmCode(bean);
        if(status > 0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);

        }else{
            QMessageBox::critical(this, "错误","修改科目保存错误",QMessageBox::Ok );
        }
    }
    refreshData();
    ui->treeView->expandAll();
    limitsInit();
}

void KmForm::on_delButton_clicked()
{
    if(QMessageBox::warning(this,"提示","是否删除？",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        KmCodeBean *kmBean= KmCodeDAO::getKmCode(ui->codeEdit->text());
        if(!kmBean || kmBean->kmName().length() < 1){
            QMessageBox::critical(this, "错误","科目编码不存在,不能删除",QMessageBox::Ok );

            return ;
        }
        int result = KmCodeDAO::delKmCode(kmBean);
        if(result > 0 ){
            ui->codeEdit->clear();
            ui->nameEdit->clear();
            ui->sCodeEdit->clear();
            refreshData();
            ui->treeView->expandAll();
            limitsInit();
            QMessageBox::information(this, "提示","删除成功！",QMessageBox::Ok );
            return ;
        }else{
            QMessageBox::critical(this, "错误","删除出错！",QMessageBox::Ok );
            return ;
        }

    }
}

void KmForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void KmForm::on_treeView_clicked(const QModelIndex &index)
{
    setInputEnabled(false);
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
    QString str = ui->treeView->model()->data(index).toString();
    mId = str.mid(1,str.indexOf(")")-1);

    KmCodeBean *dBean = KmCodeDAO::getKmCode(mId);
    ui->sCodeEdit->setText(dBean->code());
    ui->codeEdit->setText(dBean->kmCode());
    ui->nameEdit->setText(dBean->kmName());
    ui->explianEdit->setText(dBean->kmExplain());
    ui->isEndChk->setChecked(dBean->isEnd());
    ui->isCusChk->setChecked(dBean->isCus());
    ui->isSupChk->setChecked(dBean->isSup());
    ui->isCashChk->setChecked(dBean->isCash());
    ui->isBankChk->setChecked(dBean->isBank());
    if(dBean->property()==0){
        ui->propertyCmb->setCurrentIndex(0);
    }else ui->propertyCmb->setCurrentIndex(1);
    limitsInit();
}
