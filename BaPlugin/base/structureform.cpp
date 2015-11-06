#include "structureform.h"
#include "ui_structureform.h"
#include "haokeapp.h"
#include "base/structuredialog.h"
#include <QMessageBox>
#include "baplugin.h"
StructureForm::StructureForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StructureForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    m_typeId = "";
    m_id = "";
    init();
}

StructureForm::~StructureForm()
{
    delete ui;
}

void StructureForm::init(){
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

void StructureForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout,mWinId.toInt(),mWinTitle);
}

void StructureForm::setButtonEnabled(bool b){
    if(b){
        ui->editButton->setEnabled(b);
        ui->delButton->setEnabled(b);

    }else{
        ui->editButton->setEnabled(false);
        ui->delButton->setEnabled(false);
    }
    limitsInit();
}
void StructureForm::refreshData(){
    ui->tableView->setModel(StructureDAO::querySqlModelStructureByType(m_typeId));
}

void StructureForm::on_newButton_clicked()
{
    StructureDialog *sDialog = new StructureDialog(this);
    int result = sDialog->exec();
}

void StructureForm::on_editButton_clicked()
{
    if(LimitsCommon::getUserRoleLimits(HaoKeApp::getInstance()->getUserId(),"editButton",7)){
        StructureDialog *pDlg = new StructureDialog(m_id,this);
        int result = pDlg->exec();
        if(result == QDialog::Accepted){
            refreshData();
        }else{
            refreshData();
        }
        delete pDlg;
    }
}

void StructureForm::on_delButton_clicked()
{
    if(m_id.length() < 1){
        QMessageBox::information(this,"提示","没有选定行,不能删除",QMessageBox::Ok);
        ui->editButton->setEnabled(false);
        ui->delButton->setEnabled(false);

        return ;
    }
    StructureBean *bean = StructureDAO::getStructureByPsCode(m_id);
    if(QMessageBox::warning(this, "提示","是否删除此菜品成本卡:" + bean->productName() ,QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){

        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int result = StructureDAO::delStructure(bean);
        result = result + StructureDAO::delStructuresByCode(m_id);
        if(result > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            refreshData();
            m_id = "";
            ui->delButton->setEnabled(false);
            ui->editButton->setEnabled(false);

        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::critical(this,"错误","删除错误",QMessageBox::Ok);
        }

    }
}

void StructureForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void StructureForm::on_treeView_clicked(const QModelIndex &index)
{
    QString str = ui->treeView->model()->data(index).toString();
    m_typeId = str.mid(1,str.indexOf(")")-1);
    ui->tableView->setModel(StructureDAO::querySqlModelStructureByType(m_typeId));

    ui->editButton->setEnabled(false);
    ui->delButton->setEnabled(false);
}

void StructureForm::on_queryButton_clicked()
{
    QString type="";
    QStringList l = ui->typeComboBox->currentText().split("-");
    if(l.length()>0){
        type=l.at(0).trimmed();
    }
    ui->tableView->setModel(StructureDAO::querySqlModelStructureBy(type,ui->nameEdit->text(),ui->pinyinEdit->text()));
}

void StructureForm::on_tableView_doubleClicked(const QModelIndex &index)
{
    m_id = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString();
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    if(LimitsCommon::getUserRoleLimits(HaoKeApp::getInstance()->getUserId(),"editButton",7)){
        StructureDialog *pDlg = new StructureDialog(m_id,this);
        int result = pDlg->exec();
        if(result == QDialog::Accepted){
            refreshData();
        }else{
            refreshData();
        }
        delete pDlg;
    }
}

void StructureForm::on_tableView_clicked(const QModelIndex &index)
{
    m_id=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString();
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    limitsInit();
}
