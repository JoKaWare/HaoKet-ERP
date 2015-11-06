#include "recoveraccountdialog.h"
#include "ui_recoveraccountdialog.h"
#include "haokeapp.h"
#include "dao/faaccntdao.h"
#include "bean/FaSubsidiaryBean.h"

RecoverAccountDialog::RecoverAccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecoverAccountDialog)
{
    ui->setupUi(this);
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/image/cancel_48.png"), QSize(), QIcon::Normal, QIcon::Off);
    ui->cancelBtn->setIcon(icon1);
    ui->cancelBtn->setIconSize(QSize(24, 24));
    ui->cancelBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/image/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
    ui->okBtn->setIcon(icon2);
    ui->okBtn->setIconSize(QSize(24, 24));
    ui->okBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    QString htmlText = "<html><head/><body><p><span style=' font-weight:600; color:#ff0000;'>%1</span></p></body></html>";
    mAccntMonth = HaoKeApp::getInstance()->getOperateDate().month();
    ui->label->setText(htmlText.arg("当前记帐月:" + QString::number(mAccntMonth) + "月"));

    FaWayBean *bean = FaAccntDAO::getFayWay();
    mWayId = 0;
    if(bean && bean->wayName().length() > 1){
        mWayName = bean->wayName();
        mWayId = bean->wayId();

    }

}

RecoverAccountDialog::~RecoverAccountDialog()
{
    delete ui;
}

void RecoverAccountDialog::on_cancelBtn_clicked()
{
    this->reject();
}

void RecoverAccountDialog::on_okBtn_clicked()
{
    if(QMessageBox::warning(this,"提示","是否对" + QString::number(mAccntMonth)+ "月单据恢复记帐？",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        if(mWayId == 1){
            reAccntFIFO();
        }else if(mWayId == 2){
            reAccntMACost();
        }



    }
}

void RecoverAccountDialog::reAccntMACost(){
    QString htmlText = "<html><head/><body><p><span style=' font-weight:600; color:#ff0000;'>%1</span></p></body></html>";

    QDate loginDate = HaoKeApp::getInstance()->getOperateDate();
    int endDay = loginDate.daysInMonth();
    //QMessageBox::information(this,"",QString::number(endDay));
    QDate endDate = QDate::QDate(loginDate.year(),loginDate.month(),endDay);
    QDate startDate = QDate::QDate(loginDate.year(),loginDate.month(),1);
    QList<FaSubsidiaryBean *> faList = FaAccntDAO::queryFaSubsidiaryByEndDate(endDate);
    if(faList.size() > 0 ){
        QString noteInfo = endDate.toString("yyyy-MM-dd") + " 之后还有单据没有恢复记帐,不能恢复记帐";
        ui->noteLabel->setText(htmlText.arg(noteInfo));
        QMessageBox::critical(this,"警告",endDate.toString("yyyy-MM-dd") + " 之后还有单据没有恢复记帐,不能恢复记帐");
        return ;
    }
    QList<FaSubsidiaryBean *> faAtList = FaAccntDAO::queryFaSubsidiaryByDate(startDate,endDate);
    if(faAtList.size() < 1 ){
        QString noteInfo = QString::number(mAccntMonth) + "月没有记帐数据,不能恢复记帐";
        ui->noteLabel->setText(htmlText.arg(noteInfo));
        QMessageBox::critical(this,"警告",QString::number(mAccntMonth) + "月没有记帐数据,不能恢复记帐");
        return ;
    }else{
        QString info = "开始恢复记帐";
        ui->noteLabel->setText(htmlText.arg(info));
        // 开始恢复记帐
        for(int i = 0; i < faAtList.size(); i++ ){

            //出入库恢复记帐
            DBManager::getDBManager()->getGoinDBConnection().transaction();
            QString sql = "DELETE FROM fa_subsidiary WHERE id=" + QString::number(faAtList.at(i)->id());
            logger()->debug(sql);
            QueryRunner query = QueryRunner();
            int result = query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
            sql = "UPDATE rd_record SET accounter='' WHERE rd_no='" + faAtList.at(i)->vouchNo() + "'";
            int uResult = query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
            logger()->debug(sql);
            sql = "UPDATE rd_records SET is_account=false "
                    " WHERE rd_no='" + faAtList.at(i)->vouchNo() + "' AND product_code='" + faAtList.at(i)->productCode() + "'";
            int uRdsResult = query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
            logger()->debug(sql);
            if(result > 0 && uResult > 0 && uRdsResult > 0){
                DBManager::getDBManager()->getGoinDBConnection().commit();
                QString noteInfo = "入库单据：" + faAtList.at(i)->vouchNo() + " 商品:" + faAtList.at(i)->productCode() + " 恢复记帐成功";
                QApplication::processEvents();
                ui->noteLabel->setText(htmlText.arg(noteInfo));
            }else{
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QString noteInfo = "入库单据：" + faAtList.at(i)->vouchNo() + " 商品:" + faAtList.at(i)->productCode() + " 单据恢复记帐出错";
                ui->noteLabel->setText(htmlText.arg(noteInfo));
                QMessageBox::critical(this,"错误","入库单据：" + faAtList.at(i)->vouchNo() + " 商品:" + faAtList.at(i)->productCode() + " 恢复记帐出错");
                return ;
            }

        }
        info = "结束恢复记帐";
        ui->noteLabel->setText(htmlText.arg(info));
        ui->endLabel->setText(htmlText.arg(QString::number(mAccntMonth) + "月恢复记帐成功"));
        // 结束恢复记帐

    }
}

void RecoverAccountDialog::reAccntFIFO(){

    QString htmlText = "<html><head/><body><p><span style=' font-weight:600; color:#ff0000;'>%1</span></p></body></html>";

    QDate loginDate = HaoKeApp::getInstance()->getOperateDate();
    int endDay = loginDate.daysInMonth();
    //QMessageBox::information(this,"",QString::number(endDay));
    QDate endDate = QDate::QDate(loginDate.year(),loginDate.month(),endDay);
    QDate startDate = QDate::QDate(loginDate.year(),loginDate.month(),1);
    QList<FaSubsidiaryBean *> faList = FaAccntDAO::queryFaSubsidiaryByEndDate(endDate);
    if(faList.size() > 0 ){
        QString noteInfo = endDate.toString("yyyy-MM-dd") + " 之后还有单据没有恢复记帐,不能恢复记帐";
        ui->noteLabel->setText(htmlText.arg(noteInfo));
        QMessageBox::critical(this,"警告",endDate.toString("yyyy-MM-dd") + " 之后还有单据没有恢复记帐,不能恢复记帐");
        return ;
    }
    QList<FaSubsidiaryBean *> faAtList = FaAccntDAO::queryFaSubsidiaryByDate(startDate,endDate);
    if(faAtList.size() < 1 ){
        QString noteInfo = QString::number(mAccntMonth) + "月没有记帐数据,不能恢复记帐";
        ui->noteLabel->setText(htmlText.arg(noteInfo));
        QMessageBox::critical(this,"警告",QString::number(mAccntMonth) + "月没有记帐数据,不能恢复记帐");
        return ;
    }else{
        QApplication::setOverrideCursor(Qt::WaitCursor);
        ui->okBtn->setEnabled(false);
        QString info = "开始恢复记帐";
        ui->noteLabel->setText(htmlText.arg(info));
        // 开始恢复记帐
        for(int i = 0; i < faAtList.size(); i++ ){
            if(faAtList.at(i)->rdFlag() == 1){
                //入库恢复记帐


                DBManager::getDBManager()->getGoinDBConnection().transaction();
                if(faAtList.at(i)->vouchType() == "14"){
                    //先进先出 采购退货 恢复批次结存数量
                    QList<FaSubsidiaryBean *> faReList = FaAccntDAO::queryFIFOFaSubsidiaryReByBottom(faAtList.at(i)->whCode(), faAtList.at(i)->productCode());

                    if(faReList.size() < 1){
                        QString noteInfo = "采购退货红字入库单据：" + faAtList.at(i)->vouchNo() + " 商品:" + faAtList.at(i)->productCode() + " 恢复记帐失败，没有找到批次商品";
                        ui->noteLabel->setText(htmlText.arg(noteInfo));
                        ui->okBtn->setEnabled(true);
                        QApplication::restoreOverrideCursor();
                        logger()->error(noteInfo);
                        QMessageBox::critical(this,"警告",noteInfo);
                        return ;
                    }
                    //先进先出 采购退货 退回数量
                    double batch_in = faAtList.at(i)->inQuantity();
                    int reResult = 0;
                    int fifo_i = 0 ;
                    while( qAbs(batch_in) > 0  ){
                        if(faReList.size() > fifo_i){
                            //批次结存数量
                            double amount = faReList.at(fifo_i)->inQuantity()-faReList.at(fifo_i)->batchAmount();
                            if(amount >= qAbs(batch_in)){
                                faReList.at(fifo_i)->setBatchAmount(faReList.at(fifo_i)->batchAmount() + qAbs(batch_in));
                                reResult = FaAccntDAO::updateSubsidiary(faReList.at(fifo_i));
                                fifo_i = fifo_i + 1;
                                batch_in = 0 ;
                            }else{
                                batch_in = batch_in + amount;
                                faReList.at(fifo_i)->setBatchAmount(faReList.at(fifo_i)->batchAmount() + amount);
                                reResult = FaAccntDAO::updateSubsidiary(faReList.at(fifo_i));
                                fifo_i = fifo_i + 1;
                            }
                        }else{
                            QString noteInfo = "采购退货红字入库单据：" + faAtList.at(i)->vouchNo() + " 商品:" + faAtList.at(i)->productCode() + " 恢复记帐失败，批次商品到尾！";
                            ui->noteLabel->setText(htmlText.arg(noteInfo));
                            ui->okBtn->setEnabled(true);
                            QApplication::restoreOverrideCursor();
                            logger()->error(noteInfo);
                            QMessageBox::critical(this,"警告",noteInfo);
                            return ;

                        }
                    }

                }
                QString sql = "DELETE FROM fa_subsidiary WHERE id=" + QString::number(faAtList.at(i)->id());
                logger()->debug(sql);
                QueryRunner query = QueryRunner();
                int result = query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
                sql = "UPDATE rd_record SET accounter='' WHERE rd_no='" + faAtList.at(i)->vouchNo() + "'";
                int uResult = query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
                logger()->debug(sql);
                sql = "UPDATE rd_records SET is_account=false "
                        " WHERE rd_no='" + faAtList.at(i)->vouchNo() + "' AND product_code='" + faAtList.at(i)->productCode() + "'";
                int uRdsResult = query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
                logger()->debug(sql);
                if(result > 0 && uResult > 0 && uRdsResult > 0){
                    DBManager::getDBManager()->getGoinDBConnection().commit();
                    QString noteInfo = "入库单据：" + faAtList.at(i)->vouchNo() + " 商品:" + faAtList.at(i)->productCode() + " 恢复记帐成功";
                    QApplication::processEvents();
                    ui->noteLabel->setText(htmlText.arg(noteInfo));
                }else{
                    DBManager::getDBManager()->getGoinDBConnection().rollback();
                    QString noteInfo = "入库单据：" + faAtList.at(i)->vouchNo() + " 商品:" + faAtList.at(i)->productCode() + " 单据恢复记帐出错";
                    ui->noteLabel->setText(htmlText.arg(noteInfo));
                    ui->okBtn->setEnabled(true);
                    QApplication::restoreOverrideCursor();
                    QMessageBox::critical(this,"错误","入库单据：" + faAtList.at(i)->vouchNo() + " 商品:" + faAtList.at(i)->productCode() + " 恢复记帐出错");
                    return ;
                }
            }else{
                //出库恢复记帐

                //先进先出 恢复批次结存数量
                QList<FaSubsidiaryBean *> faReList = FaAccntDAO::queryReFIFOFaSubsidiaryByDvId(faAtList.at(i)->dvId());

                if(faReList.size() < 1){
                    QString noteInfo = "出库单据：" + faAtList.at(i)->vouchNo() + " 商品:" + faAtList.at(i)->productCode() + " 恢复记帐失败，没有找到批次商品";
                    ui->noteLabel->setText(htmlText.arg(noteInfo));
                    ui->okBtn->setEnabled(true);
                    QApplication::restoreOverrideCursor();
                    QMessageBox::critical(this,"警告",noteInfo);
                    return ;
                }
                DBManager::getDBManager()->getGoinDBConnection().transaction();
                int fifo_i = 0;
                //先进先出 退回数量
                double batch_out = faAtList.at(i)->outQuantity();
                int reResult = 0;
                faReList.at(fifo_i)->setBatchAmount(faReList.at(fifo_i)->batchAmount() + batch_out);
                reResult = FaAccntDAO::updateSubsidiary(faReList.at(fifo_i));

                QString sql = "DELETE FROM fa_subsidiary WHERE id=" + QString::number(faAtList.at(i)->id());
                logger()->debug(sql);
                QueryRunner query = QueryRunner();
                int result = query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
                sql = "UPDATE rd_record SET accounter='' WHERE rd_no='" + faAtList.at(i)->vouchNo() + "'";
                int uResult = query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
                logger()->debug(sql);
                sql = "UPDATE rd_records SET is_account=false "
                        " WHERE rd_no='" + faAtList.at(i)->vouchNo() + "' AND product_code='" + faAtList.at(i)->productCode() + "'";
                int uRdsResult = query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
                logger()->debug(sql);
                if(reResult>0 && result > 0 && uResult > 0 && uRdsResult > 0){
                    DBManager::getDBManager()->getGoinDBConnection().commit();
                    QString noteInfo = "出库单据：" + faAtList.at(i)->vouchNo() + " 商品:" + faAtList.at(i)->productCode() + " 恢复记帐成功";
                    QApplication::processEvents();
                    ui->noteLabel->setText(htmlText.arg(noteInfo));
                }else{
                    DBManager::getDBManager()->getGoinDBConnection().rollback();
                    QString noteInfo = "出库单据：" + faAtList.at(i)->vouchNo() + " 商品:" + faAtList.at(i)->productCode() + " 单据恢复记帐出错";
                    ui->noteLabel->setText(htmlText.arg(noteInfo));
                    ui->okBtn->setEnabled(true);
                    QApplication::restoreOverrideCursor();
                    QMessageBox::critical(this,"错误","出库单据：" + faAtList.at(i)->vouchNo() + " 商品:" + faAtList.at(i)->productCode() + " 恢复记帐出错");
                    return ;
                }
            }

        }
        info = "结束恢复记帐";
        ui->noteLabel->setText(htmlText.arg(info));
        ui->endLabel->setText(htmlText.arg(QString::number(mAccntMonth) + "月恢复记帐成功"));
        ui->okBtn->setEnabled(true);
        QApplication::restoreOverrideCursor();
        // 结束恢复记帐

    }
}
