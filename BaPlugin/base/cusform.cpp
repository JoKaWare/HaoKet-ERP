#include "cusform.h"
#include "ui_cusform.h"
#include "haokeapp.h"
#include "widget/foottablemodel.h"
#include "widget/hierarchicalheaderview.h"
#include "cusdialog.h"
#include "dao/basedao.h"
#include "baplugin.h"

CusForm::CusForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CusForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    init();
    ui->treeView->expandAll();
}

CusForm::~CusForm()
{
    delete ui;
}

void CusForm::init(){
    mId="";
    mWinId = HaoKeApp::baSubId() + BaPlugin::baCusSWinId();
    mWinTitle = "浏览客户资料";
    setInputEnabled(false);
    setButtonEnabled(false);

    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");

    QList<CustomerTypeBean *> listFirstBean = CustomerTypeDAO::queryTypeByFirst();
    QList<CustomerTypeBean *> listBean = CustomerTypeDAO::queryType();
    QStandardItemModel *model;
    QIcon typeIcon;
    typeIcon.addFile(QString::fromUtf8(":/image/class_24.png"), QSize(), QIcon::Normal, QIcon::Off);

    model = new QStandardItemModel(listFirstBean.size(),1);
    model->setHeaderData(0, Qt::Horizontal, tr("Customer Type"));
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
    QString tmp_sql_f = " id,cus_code,cus_name,cus_alias,cus_type,pinyin_code,area_city,trade,address,post,cus_reg_code"
            ",cus_bank,cus_account,corporate,licence_sdate,licence_edate,dev_date,email,contacts,tel,fax,phone"
            ",cus_address,cus_person,is_credit,cus_cre_grade,cus_cre_line,cus_cre_date,is_shop,memo ";
    mSql1 = "SELECT " + tmp_sql_f + " FROM ba_customer WHERE cus_type LIKE ? ORDER BY cus_code ASC";
    mSql2 = "SELECT " + tmp_sql_f + " FROM ba_customer WHERE cus_name LIKE ? AND cus_type LIKE ? "
            " AND pinyin_code LIKE ? ORDER BY cus_code ASC";
    childItemProperties listItem[] = {
            { "id","ID","ID", 0,60, true, true },
            { "cus_code","客户编码","客户编码", 1,80, true, true },
            { "cus_name","客户名称","客户名称", 2,180, true, false },
            { "cus_alias","客户别名","客户别名", 3,80, true, false },
            { "cus_type","客户分类","客户分类", 4, 120,true, true },
            { "pinyin_code","拼音简码","拼音简码", 5,80, true, false },
            { "area_city","地区","地区", 6,60, true, false },
            { "trade","所属行业","所属行业", 7,60, true, false },
            { "address","地址","地址", 8,100, true, false },
            { "post","邮政编码","邮政编码", 9,60, true, false },
            { "cus_reg_code","纳税人登记号","纳税人登记号", 10,100, true, false },
            { "cus_bank","开户银行","开户银行", 11,100, true, false },
            { "cus_account","银行账号","银行账号", 12,100, true, false },
            { "corporate","法人","法人", 13,100, true, false },
            { "licence_sdate","营业执照生效日期","营业执照生效日期", 14,100, true, false },
            { "licence_edate","营业执照到期日期","营业执照到期日期", 15,100, true, false },
            { "dev_date","发展日期","发展日期", 16,100, true, false },
            { "email","Email地址","Email地址", 17,100, true, false },
            { "contacts","联系人","联系人", 18,100, true, false },
            { "tel","电话","电话", 19,100, true, false },
            { "fax","传真","传真", 20,100, true, false },
            { "phone","手机","手机", 21,100, true, false },
        { "cus_address","发货地址","发货地址", 22,120, true, false },
        { "cus_person","专管业务员编码","专管业务员编码", 23,80, true, false },
        { "is_credit","是否控制信用额度","是否控制信用额度", 24,80, true, false },
        { "cus_cre_grade","信用等级","信用等级", 25,80, true, false },
        { "cus_cre_line","信用额度","信用额度", 26,80, true, false },
        { "cus_cre_date","信用期限","信用期限", 27,80, true, false },
        { "is_shop","是否门店","是否门店", 28,80, true, false },

        { "memo","备注","备注", 29,180, true, false }
    };

    int size = sizeof(listItem) / sizeof(listItem[0]);
    for(int i = 0 ; i < size ; i++){
        mListChildItem << listItem[i];
    }
    refreshData();
    connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT (sortByColumn(int)));

}


void CusForm::sortByColumn(int column){
    //ui->tableView->sortByColumn(column,Qt::DescendingOrder);
    //ui->tableView->model()->sort(column,Qt::DescendingOrder);

}
void CusForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout,mWinId.toInt(),mWinTitle);
}
void CusForm::setButtonEnabled(bool b){

    if(b){
        ui->editButton->setEnabled(b);
        ui->delButton->setEnabled(b);

    }else{
        ui->editButton->setEnabled(false);

        ui->delButton->setEnabled(false);
    }
    limitsInit();
}

void CusForm::setInputEnabled(bool b){

}
void CusForm::refreshData(){

    QVector<QVariant> v;
    v.append(mTypeCode + "%");
    sQuery(mSql1,v);
    for (int i = 0; i < mListChildItem.size(); i++){
        if(!mListChildItem[i].visible)ui->tableView->setColumnHidden(mListChildItem[i].id,true);
        ui->tableView->setColumnWidth(mListChildItem[i].id,mListChildItem[i].width);

    }

}

QSqlQuery CusForm::sqlQuery(QString sql,QVector<QVariant> qvar){
    QSqlQuery query(DBManager::getDBManager()->getGoinDBConnection());
    //query.setForwardOnly(true);
    query.prepare(sql);

    for(int i =0 ; i < qvar.size(); i++ ){
        query.addBindValue(qvar[i]);
    }

    if(!query.exec()){
       QSqlError error = query.lastError() ;
       Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
       logger->error(sql);
       logger->error(error.text());
       QMessageBox::critical(this,"错误",error.text());
    }else{
       //model->setQuery(query);
       //model->setHeaderData(0, Qt::Horizontal, tr("id"));
    }
    return query;
}
void CusForm::on_newButton_clicked()
{
    CusDialog *cusDlg = new CusDialog(addFlag,mTypeCode,this);
    if(cusDlg->exec()== QDialog::Accepted){
        QVector<QVariant> v;
        v.append(mTypeCode + "%");
        sQuery(mSql1,v);
    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"newButton");

}

void CusForm::on_editButton_clicked()
{
    CusDialog *cusDlg = new CusDialog(editFlag,mId,this);
    if(cusDlg->exec()== QDialog::Accepted){
        QVector<QVariant> v;
        v.append(mTypeCode + "%");
        sQuery(mSql1,v);
    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"editButton");


}

void CusForm::on_delButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"delButton");

    if(mId.length() < 1){
        QMessageBox::information(this,"提示","没有选定行,不能删除",QMessageBox::Ok);
        ui->editButton->setEnabled(false);
        ui->delButton->setEnabled(false);

        return ;
    }

    if(BaseDAO::getRdByCus(mCusCode.trimmed()) > 0){
        QMessageBox::information(this,"提示","已产生业务数据,不能删除",QMessageBox::Ok);
        ui->delButton->setEnabled(false);
        return ;
    }
    CustomerBean *bean = CustomerDAO::getCusById(mId);

    if(QMessageBox::warning(this, "提示","是否删除此客户:" + bean->cusName() ,QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){

        bean->setId(mId.toInt());
        int result = CustomerDAO::delCus(bean);
        if(result > 0){
            QVector<QVariant> v;
            v.append(mTypeCode + "%");
            sQuery(mSql1,v);
            ui->editButton->setEnabled(false);
            ui->delButton->setEnabled(false);
            mId = "";
            ui->delButton->setEnabled(false);
            ui->editButton->setEnabled(false);

        }else{
            QMessageBox::critical(this,"错误","删除错误",QMessageBox::Ok);
        }

    }
    delete bean;
}

void CusForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void CusForm::on_queryButton_clicked()
{
    QVector<QVariant> v;
    QString type="";
    QStringList l = ui->typeComboBox->currentText().split("-");
    if(l.length()>0){
        type=l.at(0).trimmed();
    }
    v.append("%" + ui->nameEdit->text().trimmed() + "%");
    v.append(type + "%");
    v.append("%" + ui->pinyinEdit->text() + "%");
    sQuery(mSql2,v);
}

void CusForm::sQuery(QString sql,QVector<QVariant> qvar)
{
    QApplication::setOverrideCursor(Qt::WaitCursor);

    QSqlQuery query(DBManager::getDBManager()->getGoinDBConnection());
    //query.setForwardOnly(true);
    query.prepare(sql);

    for(int i =0 ; i < qvar.size(); i++ ){
        query.addBindValue(qvar[i]);
    }

    if(!query.exec()){
       QSqlError error = query.lastError() ;
       Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
       logger->error(sql);
       logger->error(error.text());
       QMessageBox::critical(this,"错误",error.text());
    }{
        QSqlQueryModel *sqlModel = new QSqlQueryModel(ui->tableView);
        sqlModel->setQuery(query);
        for (int i = 0; i < mListChildItem.size(); i++){
            sqlModel->setHeaderData(i,Qt::Horizontal,mListChildItem[i].cnName);
        }
        sqlModel->sort(6,Qt::DescendingOrder);
        QSortFilterProxyModel *sortModel = new QSortFilterProxyModel(ui->tableView);
        sortModel->setSourceModel(sqlModel);
        ui->tableView->setModel(sortModel);
    }
    QApplication::restoreOverrideCursor();
}

void CusForm::on_treeView_doubleClicked(const QModelIndex &index)
{

}

void CusForm::on_treeView_clicked(const QModelIndex &index)
{
    QString str = ui->treeView->model()->data(index).toString();
    mTypeCode = str.mid(1,str.indexOf(")")-1);
    QVector<QVariant> v;
    v.append(mTypeCode + "%");
    sQuery(mSql1,v);
    ui->editButton->setEnabled(false);
    ui->delButton->setEnabled(false);
}

void CusForm::on_tableView_clicked(const QModelIndex &index)
{
    mId = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    mCusCode = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString();
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    limitsInit();
}

void CusForm::on_tableView_doubleClicked(const QModelIndex &index)
{
    if(LimitsCommon::getUserRoleLimits(HaoKeApp::getInstance()->getUserId(),"editButton",mWinId.toInt())){
        CusDialog *cusDlg = new CusDialog(editFlag,mId,this);
        if(cusDlg->exec()== QDialog::Accepted){

            QVector<QVariant> v;
            v.append(mTypeCode + "%");
            sQuery(mSql1,v);

        }
    }
}
