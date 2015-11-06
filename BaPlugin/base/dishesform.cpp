#include <QMessageBox>
#include "dishesform.h"
#include "ui_dishesform.h"
#include "haokeapp.h"
#include "dishesdialog.h"
#include "common/common.h"
#include "system/limitscommon.h"
#include "dao/rddao.h"
#include "baplugin.h"
DishesForm::DishesForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DishesForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    m_typeId = "";
    m_id = "";
    init();
}

DishesForm::~DishesForm()
{
    delete ui;
}

void DishesForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void DishesForm::init(){
    setButtonEnabled(false);

    QList<TypeBean *> listFirstBean=TypeDAO::queryTypeByFirst();
    QList<TypeBean *> listBean=TypeDAO::queryType();
    QStandardItemModel *model;
    model = new QStandardItemModel(listFirstBean.size(),1);
    model->setHeaderData(0, Qt::Horizontal, tr("Dishes Type"));
    QIcon typeIcon;
    typeIcon.addFile(QString::fromUtf8(":/image/class_24.png"), QSize(), QIcon::Normal, QIcon::Off);
    int j = 0;

    for(int i=0;i<listBean.size();i++){
        QString str=""+listBean.at(i)->typeId()+" - "+listBean.at(i)->typeName();
        ui->typeComboBox->addItem(str);
    }
    for(int i=0;i<listBean.size();i++){
        if(listBean.at(i)->typeGrade()==1){
            QString str="("+listBean.at(i)->typeId()+") "+listBean.at(i)->typeName();
            QStandardItem *item = new QStandardItem(str);
            item->setText(str);
            for(int k=0;k<listBean.size();k++){
                if(listBean.at(k)->typeGrade()==2){
                    QString str1="("+listBean.at(k)->typeId()+") "+listBean.at(k)->typeName();
                    if(listBean.at(i)->typeId().contains(listBean.at(k)->typeSuperior())){
                        QStandardItem *childItem = new QStandardItem(str1);
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

void DishesForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}

void DishesForm::setButtonEnabled(bool b){
    if(b){
        ui->editButton->setEnabled(b);
        ui->delButton->setEnabled(b);

    }else{
        ui->editButton->setEnabled(false);
        ui->delButton->setEnabled(false);
    }
    limitsInit();
}

void DishesForm::refreshData(){

    ui->tableView->setModel(DishesDAO::querySqlModelDishesByType(m_typeId));
    ui->tableView->setColumnWidth(0,40);
    ui->tableView->setColumnWidth(1,60);
    ui->tableView->setColumnWidth(2,160);
    ui->tableView->setColumnWidth(3,60);
    ui->tableView->setColumnWidth(4,100);
    ui->tableView->setColumnWidth(5,100);
    ui->tableView->setColumnWidth(6,60);
    ui->tableView->setColumnWidth(7,40);
    ui->tableView->setColumnWidth(8,60);
    ui->tableView->setColumnWidth(9,60);
    ui->tableView->setColumnWidth(10,60);
    ui->tableView->setColumnWidth(11,60);
    ui->tableView->setColumnWidth(12,60);
    ui->tableView->setColumnWidth(13,60);
    ui->tableView->setColumnWidth(14,60);
    ui->tableView->setColumnWidth(15,40);
    ui->tableView->setColumnWidth(16,90);
    ui->tableView->setColumnWidth(17,60);
    ui->tableView->setColumnWidth(18,60);
    ui->tableView->setColumnWidth(19,60);
    ui->tableView->setColumnWidth(20,60);
    ui->tableView->setColumnWidth(21,90);
    ui->tableView->setColumnWidth(22,60);
    ui->tableView->setColumnWidth(23,90);
    ui->tableView->setColumnWidth(24,90);
}
void DishesForm::on_newButton_clicked()
{


    DishesDialog *dDialog = new DishesDialog(addFlag,m_typeId,this);
    int status = dDialog->exec();

    if(status == QDialog::Rejected){

        refreshData();

    }else{
        refreshData();
    }

}

void DishesForm::on_editButton_clicked()
{
    DishesDialog *dDialog = new DishesDialog(editFlag,m_id,this);
    int status=dDialog->exec();
    if(status==QDialog::Rejected){

        refreshData();
        dDialog->close();
    }else{
        refreshData();
    }
}

void DishesForm::on_delButton_clicked()
{
    if(m_id.length() < 1){
        QMessageBox::information(this,"提示","没有选定行,不能删除",QMessageBox::Ok);
        ui->editButton->setEnabled(false);
        ui->delButton->setEnabled(false);

        return ;
    }
    DishesBean *bean=new DishesBean;
    bean = DishesDAO::getDishesById(m_id);
    if(RdDAO::getRdsCountByPr(bean->productCode()) > 0){
        QMessageBox::information(this,"提示","此产品已产生业务数据,不能删除",QMessageBox::Ok);
        ui->delButton->setEnabled(false);
        return ;
    }
    if(QMessageBox::warning(this, tr("Prompt"),"是否删除此菜品:" + bean->productName(),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        /*
        QList<SalesBean *> sBeanList = SaleDAO::querySaleByDishes(m_id.trimmed());
        if(sBeanList.size() > 0){
            QMessageBox::critical(this, tr("Error"),"此菜品已在销售中使用,不能删除",QMessageBox::Ok );
            return;
        }
        */
        if(m_id.toInt()>0){

            bean->setId(m_id.toInt());
            int status = DishesDAO::delDishes(bean);
            if(status > 0){
                m_id = "";
                ui->delButton->setEnabled(false);
                ui->editButton->setEnabled(false);

                refreshData();
            }else{
                QMessageBox::critical(this, tr("Error"),tr("Delete Dishes error"),QMessageBox::Ok );

            }
        }
    }
    delete bean;
}

void DishesForm::on_tableView_clicked(const QModelIndex &index)
{
    m_id=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    limitsInit();
}

void DishesForm::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString id=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    if(LimitsCommon::getUserRoleLimits(HaoKeApp::getInstance()->getUserId(),"editButton",7)){
        DishesDialog *dDialog=new DishesDialog(editFlag,id,this);
        int status=dDialog->exec();
        if(status==QDialog::Rejected){

            refreshData();
            dDialog->close();
        }else{
            refreshData();
        }
    }
}

void DishesForm::on_treeView_clicked(const QModelIndex &index)
{
    QString str=ui->treeView->model()->data(index).toString();
    QString typeId=str.mid(1,str.indexOf(")")-1);
    m_typeId=typeId;
    ui->tableView->setModel(DishesDAO::querySqlModelDishesByType(m_typeId));
    ui->editButton->setEnabled(false);
    ui->delButton->setEnabled(false);

}

void DishesForm::on_queryButton_clicked()
{
    QString type="";
    QStringList l = ui->typeComboBox->currentText().split("-");
    if(l.length()>0){
        type=l.at(0).trimmed();
    }
    ui->tableView->setModel(DishesDAO::querySqlModelDishesBy(type,ui->nameEdit->text().trimmed(),ui->pinyinEdit->text().trimmed()));
    ui->editButton->setEnabled(false);
    ui->delButton->setEnabled(false);
}
