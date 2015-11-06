#include "invdialog.h"
#include "ui_invdialog.h"
#include <QMessageBox>
#include "common/qkstringutils.h"
#include "haokeapp.h"
#include "baplugin.h"
InvDialog::InvDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InvDialog)
{
    ui->setupUi(this);
    init();
}

InvDialog::~InvDialog()
{
    delete ui;
}

InvDialog::InvDialog(int status, QString id, QWidget *parent):
    QDialog(parent),
    ui(new Ui::InvDialog)
{
    ui->setupUi(this);
    pinying = new PinYinUtils();
    mEditStatus = status;
    mId = id;
    init();
    if(status == editFlag){
        this->setWindowTitle(tr("Edit Product"));
        getProduct(id);
        ui->codeEdit->setEnabled(false);
        ui->uCodeButton->setEnabled(false);

    }else if(status == addFlag){
        this->setWindowTitle(tr("Add Product"));

        //ui->codeEdit->setText(getCodeMaxId());
        mTypeId = id;
        ui->codeEdit->setText(getCodeByTypeId(mTypeId));
        ProductTypeBean *type = new ProductTypeBean;
        type = ProductTypeDAO::getTypeById(mId);

        if(type){
            if(type->typeEnd())
                ui->typeQkSearchEditbox->setText(type->typeId()+" - "+type->typeName());
            else{
                QList<ProductTypeBean *> listBean = ProductTypeDAO::queryTypeBy(id);
                if(listBean.size() > 0){
                    ui->typeQkSearchEditbox->setText(listBean.at(0)->typeId()+" - "+listBean.at(0)->typeName());
                }
            }
        }

    }

}

void InvDialog::init(){
    mWinId = HaoKeApp::baSubId() + BaPlugin::baProWinId();
    mWinTitle = "商品资料";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");

    QList<UnitBean *> uListBean = CommonDAO::queryUnit();
    for(int i = 0; i< uListBean.size(); i++){
        ui->pUnitComboBox->addItem(uListBean.at(i)->unitName());
    }

    QList<ProductTypeBean *> listBean = ProductTypeDAO::queryTypeByEnd();

    ui->typeQkSearchEditbox->setListModel(true);
    QStringList sList;
    for(int i=0;i<listBean.size();i++){
        sList<< listBean.at(i)->typeId()+" - "+ listBean.at(i)->typeName();

    }
    ui->typeQkSearchEditbox->setItems(sList);
    ui->addButton->setEnabled(false);
}

QString InvDialog::getCodeMaxId(){
    int maxId = ProductDAO::getMaxId().toInt() + 1;
    QString strCode = "";
    for(int i=0;i<5-QString::number(maxId).length();i++){
        strCode = strCode + "0";
    }
    strCode = strCode + QString::number(maxId);
    return strCode;
}
QString InvDialog::getCodeByTypeId(QString type){
    QString strCode = "";
    if(type.length() < 1){
        type = "01";
    }
    int maxId = ProductDAO::getByTypeCount(type) + 1;
    if(type.length()>=5){
        strCode = type + QkStringUtils::numberToString(maxId,1);
    }else{
        strCode = type + QkStringUtils::numberToString(maxId,4);
    }
    return strCode;
}
void InvDialog::getProduct(QString id){
    ProductBean *bean = ProductDAO::getProductById(id);

    if(bean == NULL){
        QMessageBox::critical(this,"提示","此原料" + id + " 不存在");
    }
    ui->codeEdit->setText(bean->productCode());
    ui->codeEdit->setEnabled(false);
    ui->nameEdit->setText(bean->productName());
    ui->pinyinEdit->setText(bean->pinyinCode());
    ui->assistedEdit->setText(bean->productNo());
    ui->styleEdit->setText(bean->style());
    mTypeId = bean->typeId();
    ProductTypeBean *tBean = ProductTypeDAO::getTypeById(bean->typeId());
    if(tBean != NULL)
        ui->typeQkSearchEditbox->setText(tBean->typeId() + " - " + tBean->typeName());
    else
        ui->typeQkSearchEditbox->setText(bean->typeId());
    for(int i = 0 ; i < ui->pUnitComboBox->count(); i++ ){
        if(ui->pUnitComboBox->itemText(i) == bean->purchaseUnit()){
            ui->pUnitComboBox->setCurrentIndex(i);
        }
    }

    ui->mPriceSpinBox->setValue(bean->puPrice());
    ui->lowSumSpinBox->setValue(bean->lowSum());
    ui->topSumSpinBox->setValue(bean->topSum());
    ui->memoEdit->setText(bean->memo());

    ui->sPucgaseCheckBox->setChecked(bean->isPosPurchase());
    ui->sDownCheckBox->setChecked(bean->isPosDown());
    ui->sConCheckBox->setChecked(bean->isSaleConsumption());
    ui->wConfCheckBox->setChecked(bean->isWeighingConf());
    ui->isImeiChk->setChecked(bean->isImei());
    ui->saleCheckBox->setChecked(bean->isSale());
    ui->purchaseCheckBox->setChecked(bean->isPurchase());
    ui->comsumeCheckBox->setChecked(bean->isComsume());

    delete bean;


}
void InvDialog::setInputEnable(bool b){
    ui->codeEdit->setEnabled(b);
    if(mEditStatus == addFlag && b){
        ui->uCodeButton->setEnabled(true);
    }else ui->uCodeButton->setEnabled(false);
    ui->nameEdit->setEnabled(b);
    ui->assistedEdit->setEnabled(b);
    ui->pinyinEdit->setEnabled(b);
    ui->pUnitComboBox->setEnabled(b);
    ui->styleEdit->setEnabled(b);
    ui->isImeiChk->setEnabled(b);
    ui->typeQkSearchEditbox->setEnabled(b);
    ui->lowSumSpinBox->setEnabled(b);
    ui->topSumSpinBox->setEnabled(b);
    ui->mPriceSpinBox->setEnabled(b);
    ui->memoEdit->setEnabled(b);
    ui->sPucgaseCheckBox->setEnabled(b);
    ui->sDownCheckBox->setEnabled(b);
    ui->wConfCheckBox->setEnabled(b);
    ui->sConCheckBox->setEnabled(b);

    ui->saleCheckBox->setEnabled(b);
    ui->purchaseCheckBox->setEnabled(b);
    ui->comsumeCheckBox->setEnabled(b);


}

void InvDialog::clearInput(){
    ui->codeEdit->clear();
    ui->nameEdit->clear();
    ui->assistedEdit->clear();
    ui->pinyinEdit->clear();

    ui->styleEdit->clear();
    ui->lowSumSpinBox->clear();
    ui->topSumSpinBox->clear();
    ui->mPriceSpinBox->clear();
    ui->memoEdit->clear();


}

void InvDialog::on_cancelButton_clicked()
{
    this->accept();
}

void InvDialog::on_saveButton_clicked()
{
    if(ui->codeEdit->text().length()<1){
        QMessageBox::warning(this, "提示","请输入原料编码",QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;
    }
    if(ui->nameEdit->text().length()<1){
        QMessageBox::warning(this, "提示","请输入原料名称",QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;
    }
    if(ui->pinyinEdit->text().length()<1){
        QMessageBox::warning(this, "提示","请输入拼音简码",QMessageBox::Ok );
        ui->pinyinEdit->setFocus();
        return ;
    }
    if(ui->typeQkSearchEditbox->text().length() < 1){
        QMessageBox::warning(this, "提示","请输入原料类别",QMessageBox::Ok );
        ui->typeQkSearchEditbox->setFocus();
        return ;
    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"saveButton");

    if(mEditStatus == addFlag){
        if(ProductDAO::getByCodeCount(ui->codeEdit->text().trimmed())>0){
            QMessageBox::critical(this, "错误","原料编码已存在，不能处理",QMessageBox::Ok );

            return ;
        }


        QList<WareHouseBean *> whBeanList = WareDAO::queryWarehouse();
        QString whCode = "";
        if( whBeanList.size() > 0 ){
            whCode = whBeanList.at(0)->whCode();
        }else{
            QMessageBox::critical(this, "错误","没有创建仓库,不能添加商品",QMessageBox::Ok );
            return ;
        }

        ProductBean *pBean = new ProductBean;
        pBean->setProductCode(ui->codeEdit->text().trimmed());
        pBean->setProductName(ui->nameEdit->text().trimmed());
        pBean->setProductNo(ui->assistedEdit->text().trimmed());
        pBean->setPinyinCode(ui->pinyinEdit->text().trimmed());
        pBean->setTypeId(ui->typeQkSearchEditbox->text());
        pBean->setStyle(ui->styleEdit->text().trimmed());
        pBean->setPurchaseUnit(ui->pUnitComboBox->currentText());
        pBean->setStockUnit(ui->pUnitComboBox->currentText());
        pBean->setDoseUnit(ui->pUnitComboBox->currentText());
        pBean->setIsImei(ui->isImeiChk->isChecked());
        pBean->setPuStUnit(1);
        pBean->setStDoUnit(1);
        pBean->setPuPrice(ui->mPriceSpinBox->value());
        pBean->setLowSum(ui->lowSumSpinBox->value());
        pBean->setTopSum(ui->topSumSpinBox->value());
        pBean->setSupplierId(0);

        pBean->setMemo(ui->memoEdit->text());

        pBean->setIsPosPurchase(ui->sPucgaseCheckBox->isChecked());
        pBean->setIsPosDown(ui->sDownCheckBox->isChecked());
        pBean->setIsSaleConsumption(ui->sConCheckBox->isChecked());
        //pBean->setIsRaw(ui->rawCheckBox->isChecked());
        pBean->setIsRaw(true);
        pBean->setIsSale(ui->saleCheckBox->isChecked());
        pBean->setIsPurchase(ui->purchaseCheckBox->isChecked());
        pBean->setIsWeighingConf(ui->wConfCheckBox->isChecked());
        pBean->setIsComsume(ui->comsumeCheckBox->isChecked());
        pBean->setStatus(0);
        pBean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        QDateTime time = QDateTime::currentDateTime();
        pBean->setCreated(time);

        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int result = ProductDAO::createProduct(pBean);

        StockBean *stBean = new StockBean;
        stBean->setWhCode(whCode);
        stBean->setPositionCode("");
        stBean->setProductCode(pBean->productCode());
        stBean->setStyle(pBean->style());
        stBean->setUnit(pBean->stockUnit());
        stBean->setSum(0);
        stBean->setCanSum(0);
        stBean->setReadySum(0);
        stBean->setStatus(0);
        int stResult = StockDAO::createStock(stBean);
        if(result > 0 && stResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            setInputEnable(false);
            ui->addButton->setEnabled(true);
            ui->saveButton->setEnabled(false);

        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::critical(this, "错误","新建原料信息出错!",QMessageBox::Ok );
            return;
        }
    }else if(mEditStatus == editFlag){
        if(mId.length() < 1){
            QMessageBox::critical(this, "错误","无此原料信息,不能修改!",QMessageBox::Ok );
            return ;
        }
        ProductBean *pBean = ProductDAO::getProductById(mId);
        if(pBean == NULL){
            QMessageBox::critical(this, "错误","无此原料信息,不能修改!",QMessageBox::Ok );
            return ;
        }
        pBean->setProductName(ui->nameEdit->text().trimmed());
        pBean->setProductNo(ui->assistedEdit->text().trimmed());
        pBean->setPinyinCode(ui->pinyinEdit->text().trimmed());
        pBean->setTypeId(ui->typeQkSearchEditbox->text());
        pBean->setStyle(ui->styleEdit->text().trimmed());
        pBean->setPurchaseUnit(ui->pUnitComboBox->currentText());
        pBean->setStockUnit(ui->pUnitComboBox->currentText());
        pBean->setDoseUnit(ui->pUnitComboBox->currentText());
        pBean->setPuStUnit(1);
        pBean->setStDoUnit(1);
        pBean->setPuPrice(ui->mPriceSpinBox->value());
        pBean->setLowSum(ui->lowSumSpinBox->value());
        pBean->setTopSum(ui->topSumSpinBox->value());
        pBean->setSupplierId(0);

        pBean->setMemo(ui->memoEdit->text());

        pBean->setIsPosPurchase(ui->sPucgaseCheckBox->isChecked());
        pBean->setIsPosDown(ui->sDownCheckBox->isChecked());
        pBean->setIsSaleConsumption(ui->sConCheckBox->isChecked());
        pBean->setIsImei(ui->isImeiChk->isChecked());
        pBean->setIsSale(ui->saleCheckBox->isChecked());
        pBean->setIsPurchase(ui->purchaseCheckBox->isChecked());
        pBean->setIsWeighingConf(ui->wConfCheckBox->isChecked());
        pBean->setIsComsume(ui->comsumeCheckBox->isChecked());
        pBean->setStatus(0);
        pBean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        QDateTime time = QDateTime::currentDateTime();
        pBean->setCreated(time);

        int result = ProductDAO::updateProduct(pBean);
        if(result > 0){
            setInputEnable(false);
            ui->addButton->setEnabled(true);
            ui->saveButton->setEnabled(false);

        }else{
            QMessageBox::critical(this, "错误","修改原料信息出错!",QMessageBox::Ok );
            return;
        }

    }
}

void InvDialog::on_addButton_clicked()
{
    mEditStatus = addFlag;
    clearInput();
    setInputEnable(true);
    mTypeId = ui->typeQkSearchEditbox->text();
    //ui->codeEdit->setText(getCodeMaxId());
    ui->codeEdit->setText(getCodeByTypeId(mTypeId));
    ui->saveButton->setEnabled(true);
}

void InvDialog::on_nameEdit_textChanged(const QString &arg1)
{
    //ui->pinyinEdit->setText(pinying->String2Alpha(arg1));
    ui->pinyinEdit->setText(PinYinUtils::getAllFirstLetter(arg1));
}

void InvDialog::on_uCodeButton_clicked()
{
    if(mEditStatus == addFlag){
        mTypeId = ui->typeQkSearchEditbox->text();
        ui->codeEdit->setText(getCodeByTypeId(mTypeId));
    }else
        ui->uCodeButton->setEnabled(false);
}
