#include <QMessageBox>
#include "dishesdialog.h"
#include "ui_dishesdialog.h"
#include "common/common.h"
#include "bean/DishesBean.h"
#include "bean/TypeBean.h"
#include "dao/dishesdao.h"
#include "dao/typedao.h"
#include "system/limitscommon.h"
#include "haokeapp.h"
#include "baplugin.h"
DishesDialog::DishesDialog(int status,QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DishesDialog)
{

    ui->setupUi(this);
    pinying = new PinYinUtils();
    editStatus = status;
    m_id=id;
    init();
    if(status == editFlag){
        this->setWindowTitle(tr("Edit Dishes"));
        getDishes(id);
        ui->codeEdit->setEnabled(false);

    }else if(status == addFlag){
        this->setWindowTitle(tr("Add Dishes"));

        //ui->codeEdit->setText(getCodeMaxId());
        mTypeId = id;
        ui->codeEdit->setText(getCodeByTypeId(mTypeId));
        TypeBean *type=new TypeBean;
        type=TypeDAO::getTypeById(mTypeId);
        ui->statusCheckBox->setChecked(true);
        if(type->typeEnd())
            ui->qksearcheditbox->setText(type->typeId()+" - "+type->typeName());
        else{
            QList<TypeBean *> listBean=TypeDAO::queryTypeBy(id);
            if(listBean.size() > 0){
                ui->qksearcheditbox->setText(listBean.at(0)->typeId()+" - "+listBean.at(0)->typeName());
            }
        }

    }


}

DishesDialog::~DishesDialog()
{
    delete ui;
}

QString DishesDialog::getCodeMaxId(){
    int maxId = DishesDAO::getMaxId().toInt() + 1;
    QString strCode = "";
    for(int i=0;i<5-QString::number(maxId).length();i++){
        strCode = strCode + "0";
    }
    strCode = strCode + QString::number(maxId);
    return strCode;

}

QString DishesDialog::getCodeByTypeId(QString type){
    QString strCode = "";
    if(type.length() < 1){
        type = "01";
    }
    int maxId = DishesDAO::getByTypeCount(type) + 1;
    if(type.length()>=5){
        strCode = type + QkStringUtils::numberToString(maxId,1);
    }else{
        strCode = type + QkStringUtils::numberToString(maxId,4);
    }
    return strCode;
}

void DishesDialog::getDishes(QString id){
    DishesBean *bean=new DishesBean;
    bean=DishesDAO::getDishesById(id);
    if(bean == NULL){
        QMessageBox::information(this,"提示","此菜品不存在！");
        return ;
    }
    m_id=id;
    ui->codeEdit->setText(bean->productCode());
    ui->nameEdit->setText(bean->productName());
    ui->pinyinEdit->setText(bean->pinyinCode());

    ui->enEdit->setText(bean->enName());

    TypeBean *type=new TypeBean;
    type=TypeDAO::getTypeById(bean->typeId());
    QString typeName=bean->typeId()+" - "+type->typeName();
    ui->qksearcheditbox->setText(typeName);
    mTypeId = ui->qksearcheditbox->text();
    for(int i = 0 ; i < ui->pUnitComboBox->count(); i++ ){
        if(ui->pUnitComboBox->itemText(i).trimmed() == bean->purchaseUnit()){
            ui->pUnitComboBox->setCurrentIndex(i);
        }
    }

    for(int i = 0 ; i < ui->sUnitComboBox->count(); i++ ){
        if(ui->sUnitComboBox->itemText(i).trimmed() == bean->stockUnit()){
            ui->sUnitComboBox->setCurrentIndex(i);
        }
    }
    ui->puStSpinBox->setValue(bean->puStUnit());
    ui->styleEdit->setText(bean->style());
    ui->priceSpinBox->setValue(bean->price1());
    ui->priceSpinBox2->setValue(bean->price2());
    ui->priceSpinBox3->setValue(bean->price3());
    ui->mPriceSpinBox->setValue(bean->mPrice1());
    ui->mPriceSpinBox2->setValue(bean->mPrice2());
    ui->mPriceSpinBox3->setValue(bean->mPrice3());
    ui->discCheckBox->setChecked(bean->isDisc());
    ui->tempCheckBox->setChecked(bean->isTempDishes());
    ui->confCheckBox->setChecked(bean->isWeighingConf());
    ui->pricesCheckBox->setChecked(bean->isCurrentPrices());
    ui->padCheckBox->setChecked(bean->isDownPad());
    ui->pieceCheckBox->setChecked(bean->isPieceDishes());
    ui->marketCheckBox->setChecked(bean->isMarketing());
    ui->purchaseCheckBox->setChecked(bean->isPurchase());
    ui->setCheckBox->setChecked(bean->isSet());
    ui->discSpinBox->setValue(bean->lowDiscount());
    ui->puPriceSpinBox->setValue(bean->puPrice());
    if(bean->status() == 0){
        ui->statusCheckBox->setChecked(true);
    }else ui->statusCheckBox->setChecked(false);

}
void DishesDialog::init(){
    QList<UnitBean *> uListBean = CommonDAO::queryUnit();
    for(int i = 0; i< uListBean.size(); i++){
        ui->pUnitComboBox->addItem(uListBean.at(i)->unitName());
        ui->sUnitComboBox->addItem(uListBean.at(i)->unitName());
    }

    QList<TypeBean *> listBean=TypeDAO::queryTypeByEnd();

    ui->qksearcheditbox->setListModel(true);
    QStringList sList;
    for(int i=0;i<listBean.size();i++){
        sList<< listBean.at(i)->typeId()+" - "+ listBean.at(i)->typeName();

    }
    ui->qksearcheditbox->setItems(sList);
    ui->addButton->setEnabled(false);

}

void DishesDialog::limitsInit(){
    BaPlugin::authority(ui->gridLayout_3,mWinId.toInt(),mWinTitle);
}

void DishesDialog::setInputEnable(bool b){
    ui->codeEdit->setEnabled(b);
    ui->nameEdit->setEnabled(b);
    //ui->assistedEdit->setEnabled(b);
    ui->enEdit->setEnabled(b);
    ui->pinyinEdit->setEnabled(b);
    ui->sUnitComboBox->setEnabled(b);

    ui->puStSpinBox->setEnabled(b);
    ui->pUnitComboBox->setEnabled(b);
    ui->styleEdit->setEnabled(b);
    ui->qksearcheditbox->setEnabled(b);
    ui->priceSpinBox->setEnabled(b);
    ui->priceSpinBox2->setEnabled(b);
    ui->priceSpinBox3->setEnabled(b);
    ui->mPriceSpinBox->setEnabled(b);
    ui->mPriceSpinBox2->setEnabled(b);
    ui->mPriceSpinBox3->setEnabled(b);
    ui->confCheckBox->setEnabled(b);
    ui->discCheckBox->setEnabled(b);
    ui->padCheckBox->setEnabled(b);
    ui->setCheckBox->setEnabled(b);
    ui->marketCheckBox->setEnabled(b);
    ui->purchaseCheckBox->setEnabled(b);
    ui->pieceCheckBox->setEnabled(b);
    ui->pricesCheckBox->setEnabled(b);
    ui->tempCheckBox->setEnabled(b);
    ui->discSpinBox->setEnabled(b);
    ui->statusCheckBox->setEnabled(b);
    ui->puPriceSpinBox->setEnabled(b);
}
void DishesDialog::on_cancelButton_clicked()
{
    this->accept();
}

void DishesDialog::on_saveButton_clicked()
{
    if(ui->codeEdit->text().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Dishes code"),QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;
    }
    if(ui->nameEdit->text().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Dishes name"),QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;
    }
    if(ui->pinyinEdit->text().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Dishes pinyin code"),QMessageBox::Ok );
        ui->pinyinEdit->setFocus();
        return ;
    }
    if(ui->qksearcheditbox->text().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Dishes Type"),QMessageBox::Ok );
        ui->qksearcheditbox->setFocus();
        return ;
    }
    if(editStatus == addFlag){

        if(DishesDAO::getByCodeCount(ui->codeEdit->text().trimmed())>0){
            QMessageBox::critical(this, tr("Error"),tr("菜品编码已存在，不能处理"),QMessageBox::Ok );
            return ;
        }
        DishesBean *bean=new DishesBean;

        bean->setProductCode(ui->codeEdit->text().trimmed());
        bean->setProductName(ui->nameEdit->text().trimmed());
        bean->setPinyinCode(ui->pinyinEdit->text().trimmed());
        bean->setAssistedCode("");
        bean->setEnName(ui->enEdit->text().trimmed());
        bean->setUnit(ui->sUnitComboBox->currentText());
        bean->setPurchaseUnit(ui->pUnitComboBox->currentText());
        bean->setStockUnit(ui->sUnitComboBox->currentText());
        if(ui->puStSpinBox->value() <= 0)
            bean->setPuStUnit(1);
        else bean->setPuStUnit(ui->puStSpinBox->value());
        bean->setEatType("");
        bean->setTypeId(ui->qksearcheditbox->text());
        bean->setStyle(ui->styleEdit->text());
        bean->setIsRaw(false);
        bean->setPrice1(ui->priceSpinBox->value());
        bean->setPrice2(ui->priceSpinBox2->value());
        bean->setPrice3(ui->priceSpinBox3->value());
        bean->setPuPrice(ui->puPriceSpinBox->value());
        bean->setMPrice1(ui->mPriceSpinBox->value());
        bean->setMPrice2(ui->mPriceSpinBox2->value());
        bean->setMPrice3(ui->mPriceSpinBox3->value());
        bean->setIsCurrentPrices(ui->pricesCheckBox->isChecked());
        bean->setIsDisc(ui->discCheckBox->isChecked());
        bean->setIsDownPad(ui->padCheckBox->isChecked());
        bean->setIsMarketing(ui->marketCheckBox->isChecked());
        bean->setIsPurchase(ui->purchaseCheckBox->isChecked());
        bean->setIsPieceDishes(ui->pieceCheckBox->isChecked());
        bean->setIsSet(ui->setCheckBox->isChecked());
        bean->setIsTempDishes(ui->tempCheckBox->isChecked());
        bean->setIsWeighingConf(ui->confCheckBox->isChecked());
        bean->setLowDiscount(ui->discSpinBox->value());
        bean->setCreated(QDateTime::currentDateTime());
        bean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        if(ui->statusCheckBox->isChecked())
            bean->setStatus(0);
        else bean->setStatus(1);
        int status=DishesDAO::createDishes(bean);
        if(status>0){
            setInputEnable(false);
            ui->saveButton->setEnabled(false);
            ui->addButton->setEnabled(true);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("New Dishes error"),QMessageBox::Ok );
            return;
        }
    }else if(editStatus == editFlag){
        DishesBean *bean=new DishesBean;
        bean->setId(m_id.toInt());
        bean->setProductCode(ui->codeEdit->text().trimmed());
        bean->setProductName(ui->nameEdit->text().trimmed());
        bean->setPinyinCode(ui->pinyinEdit->text().trimmed());
        bean->setAssistedCode("");
        bean->setEnName(ui->enEdit->text().trimmed());
        bean->setUnit(ui->sUnitComboBox->currentText());
        bean->setPurchaseUnit(ui->pUnitComboBox->currentText());
        bean->setStockUnit(ui->sUnitComboBox->currentText());
        if(ui->puStSpinBox->value() <= 0)
            bean->setPuStUnit(1);
        else bean->setPuStUnit(ui->puStSpinBox->value());
        bean->setEatType("");
        bean->setTypeId(ui->qksearcheditbox->text());
        bean->setStyle(ui->styleEdit->text());
        bean->setPrice1(ui->priceSpinBox->value());
        bean->setPrice2(ui->priceSpinBox2->value());
        bean->setPrice3(ui->priceSpinBox3->value());
        bean->setPuPrice(ui->puPriceSpinBox->value());
        bean->setMPrice1(ui->mPriceSpinBox->value());
        bean->setMPrice2(ui->mPriceSpinBox2->value());
        bean->setMPrice3(ui->mPriceSpinBox3->value());
        bean->setIsCurrentPrices(ui->pricesCheckBox->isChecked());
        bean->setIsDisc(ui->discCheckBox->isChecked());
        bean->setIsDownPad(ui->padCheckBox->isChecked());
        bean->setIsMarketing(ui->marketCheckBox->isChecked());
        bean->setIsPurchase(ui->purchaseCheckBox->isChecked());
        bean->setIsPieceDishes(ui->pieceCheckBox->isChecked());
        bean->setIsSet(ui->setCheckBox->isChecked());
        bean->setIsTempDishes(ui->tempCheckBox->isChecked());
        bean->setIsWeighingConf(ui->confCheckBox->isChecked());
        bean->setLowDiscount(ui->discSpinBox->value());
        if(ui->statusCheckBox->isChecked())
            bean->setStatus(0);
        else bean->setStatus(1);
        int status=DishesDAO::updateDishes(bean);
        if(status>0){
            setInputEnable(false);
            ui->saveButton->setEnabled(false);
            ui->addButton->setEnabled(true);

        }else{
            QMessageBox::critical(this, tr("Error"),tr("Edit Dishes error"),QMessageBox::Ok );
            return;
        }
    }
}

void DishesDialog::on_addButton_clicked()
{
    setInputEnable(true);
    clearInput();
    editStatus = addFlag;
    mTypeId = ui->qksearcheditbox->text();
    //ui->codeEdit->setText(getCodeMaxId());
    ui->codeEdit->setText(getCodeByTypeId(mTypeId));
    ui->saveButton->setEnabled(true);

}

void DishesDialog::clearInput(){
    ui->codeEdit->clear();
    ui->nameEdit->clear();
    //ui->assistedEdit->clear();
    ui->enEdit->clear();
    ui->pinyinEdit->clear();
    //ui->typeComboBox->clear();
    //ui->unitComboBox->clear();
    ui->styleEdit->clear();
    ui->discSpinBox->clear();
    ui->priceSpinBox->clear();\
    ui->priceSpinBox2->clear();
    ui->priceSpinBox3->clear();
    ui->mPriceSpinBox->clear();
    ui->mPriceSpinBox2->clear();
    ui->mPriceSpinBox3->clear();

    ui->confCheckBox->setChecked(false);
    ui->discCheckBox->setChecked(false);
    ui->padCheckBox->setChecked(false);
    ui->setCheckBox->setChecked(false);
    ui->marketCheckBox->setChecked(false);
    ui->tempCheckBox->setChecked(false);
    ui->pieceCheckBox->setChecked(false);
    ui->pricesCheckBox->setChecked(false);
}

void DishesDialog::on_nameEdit_textChanged(const QString &arg1)
{

    ui->pinyinEdit->setText(pinying->String2Alpha(arg1));
}
