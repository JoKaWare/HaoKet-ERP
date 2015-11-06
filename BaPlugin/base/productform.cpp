#include "productform.h"
#include "ui_productform.h"
#include "haokeapp.h"
#include "productdialog.h"
#include "invdialog.h"
#include "dao/rddao.h"
#include "dao/basedao.h"
#include <QMessageBox>
#include "baplugin.h"
ProductForm::ProductForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    init();
    ui->treeView->expandAll();
}

ProductForm::~ProductForm()
{
    delete ui;
}

void ProductForm::init(){
    mWinId = HaoKeApp::baSubId() + BaPlugin::baProSWinId();
    mWinTitle = "浏览商品";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");
    setInputEnabled(false);
    setButtonEnabled(false);
    mId="";
    QList<ProductTypeBean *> listFirstBean=ProductTypeDAO::queryTypeByFirst();
    QList<ProductTypeBean *> listBean=ProductTypeDAO::queryType();
    QStandardItemModel *model;
    QIcon typeIcon;
    typeIcon.addFile(QString::fromUtf8(":/image/class_24.png"), QSize(), QIcon::Normal, QIcon::Off);

    model = new QStandardItemModel(listFirstBean.size(),1);
    model->setHeaderData(0, Qt::Horizontal, tr("Prodcut Type"));
    for(int i=0;i<listBean.size();i++){
        QString str = ""+listBean.at(i)->typeId() + " - " + listBean.at(i)->typeName();
        ui->typeComboBox->addItem(str);
    }
    int j=0;
    for(int i=0;i<listBean.size();i++){
        if(listBean.at(i)->typeGrade()==1){
            QString str="("+listBean.at(i)->typeId()+") "+listBean.at(i)->typeName();
            QStandardItem *item = new QStandardItem(str);
            item->setText(str);
            for(int k=0;k<listBean.size();k++){
                if(listBean.at(k)->typeGrade()==2){
                    QString str1="(" + listBean.at(k)->typeId() + ") " + listBean.at(k)->typeName();
                    if(listBean.at(i)->typeId().contains(listBean.at(k)->typeSuperior())){
                        QStandardItem *childItem = new QStandardItem(str1);
                        for(int h = 0;h < listBean.size() ; h++ ){
                            if(listBean.at(h)->typeGrade()==3){
                                QString str2="("+listBean.at(h)->typeId()+") "+listBean.at(h)->typeName();
                                if(listBean.at(k)->typeId().contains(listBean.at(h)->typeSuperior())){
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
            j=j+1;
        }
    }

    ui->treeView->setModel(model);
    refreshData();

}

void ProductForm::setInputEnabled(bool b){

}

void ProductForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout,mWinId.toInt(),mWinTitle);
}
void ProductForm::setButtonEnabled(bool b){

    if(b){
        ui->editButton->setEnabled(b);
        ui->delButton->setEnabled(b);

    }else{
        ui->editButton->setEnabled(false);

        ui->delButton->setEnabled(false);
    }
    limitsInit();
}

void ProductForm::refreshData(){
    ui->tableView->setModel(ProductDAO::querySqlModelProductByType(mTypeCode));

    ui->tableView->setColumnWidth(0,40);
    ui->tableView->setColumnWidth(1,80);
    ui->tableView->setColumnWidth(2,120);
    ui->tableView->setColumnWidth(3,80);
    ui->tableView->setColumnWidth(4,80);
    ui->tableView->setColumnWidth(5,80);
    ui->tableView->setColumnWidth(6,60);
    ui->tableView->setColumnWidth(7,60);
    ui->tableView->setColumnWidth(8,60);
    ui->tableView->setColumnWidth(9,60);
    ui->tableView->setColumnWidth(10,60);
    ui->tableView->setColumnWidth(11,60);
    ui->tableView->setColumnWidth(12,60);
    ui->tableView->setColumnWidth(13,60);
    ui->tableView->setColumnWidth(14,60);
    ui->tableView->setColumnWidth(15,60);
    ui->tableView->setColumnWidth(16,60);
    ui->tableView->setColumnWidth(17,60);
    ui->tableView->setColumnWidth(18,60);
    ui->tableView->setColumnWidth(19,60);
    ui->tableView->setColumnWidth(20,60);
    ui->tableView->setColumnWidth(21,60);
    ui->tableView->setColumnWidth(22,60);
    ui->tableView->setColumnWidth(23,60);
    ui->tableView->setColumnWidth(24,60);
    ui->tableView->setColumnWidth(25,60);

}

void ProductForm::on_newButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"newButton");

    InvDialog *pDlg = new InvDialog(addFlag,mTypeCode,this);
    int result = pDlg->exec();
    if(result == QDialog::Accepted){
        refreshData();
    }else{
        refreshData();
    }
    delete pDlg;
}

void ProductForm::on_editButton_clicked()
{
    if(mId.length() < 1){
        QMessageBox::information(this,"提示","没有选定行,不能修改",QMessageBox::Ok);
        ui->editButton->setEnabled(false);
        ui->delButton->setEnabled(false);

        return ;
    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"editButton");

    ProductDialog *pDlg = new ProductDialog(editFlag,mId,this);
    int result = pDlg->exec();
    if(result == QDialog::Accepted){
        refreshData();
    }else{
        refreshData();
    }
    delete pDlg;
}

void ProductForm::on_delButton_clicked()
{
    if(mId.length() < 1){
        QMessageBox::information(this,"提示","没有选定行,不能删除",QMessageBox::Ok);
        ui->editButton->setEnabled(false);
        ui->delButton->setEnabled(false);

        return ;
    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"delButton");

    ProductBean *bean = new ProductBean;
    bean->setId(mId.toInt());
    bean = ProductDAO::getProductById(mId);
    if(RdDAO::getRdsCountByPr(bean->productCode()) > 0){
        QMessageBox::information(this,"提示","此产品已产生业务数据,不能删除",QMessageBox::Ok);
        ui->delButton->setEnabled(false);
        return ;
    }
    if(QMessageBox::warning(this, "提示","是否删除此商品:" + bean->productName() ,QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){

        bean->setId(mId.toInt());
        int result = ProductDAO::delProduct(bean);
        if(result > 0){
            refreshData();
            mId = "";
            ui->delButton->setEnabled(false);
            ui->editButton->setEnabled(false);

        }else{
            QMessageBox::critical(this,"错误","删除错误",QMessageBox::Ok);
        }

    }
    delete bean;

}

void ProductForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void ProductForm::on_treeView_clicked(const QModelIndex &index)
{
    QString str = ui->treeView->model()->data(index).toString();
    mTypeCode = str.mid(1,str.indexOf(")")-1);

    ui->tableView->setModel(ProductDAO::querySqlModelProductByType(mTypeCode));
    ui->editButton->setEnabled(false);
    ui->delButton->setEnabled(false);
}

void ProductForm::on_queryButton_clicked()
{
    QString type="";
    QStringList l = ui->typeComboBox->currentText().split("-");
    if(l.length()>0){
        type=l.at(0).trimmed();
    }
    ui->tableView->setModel(ProductDAO::querySqlModelProductBy(type,ui->nameEdit->text().trimmed(),ui->pinyinEdit->text().trimmed()));
}

void ProductForm::on_tableView_doubleClicked(const QModelIndex &index)
{
    mId = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    if(LimitsCommon::getUserRoleLimits(HaoKeApp::getInstance()->getUserId(),"editButton",mWinId.toInt())){
        InvDialog *pDlg = new InvDialog(editFlag,mId,this);
        int result = pDlg->exec();
        if(result == QDialog::Accepted){
            refreshData();
        }else{
            refreshData();
        }
        delete pDlg;
    }
}

void ProductForm::on_tableView_clicked(const QModelIndex &index)
{
    mId=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    limitsInit();
}
