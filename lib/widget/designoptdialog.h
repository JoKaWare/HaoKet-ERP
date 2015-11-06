#ifndef DESIGNOPTDIALOG_H
#define DESIGNOPTDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include "lib_global.h"
#include "bean/ReportFormatBean.h"
#include "dao/reportdao.h"

namespace Ui {
class DesignOptDialog;
}

class LIBSHARED_EXPORT DesignOptDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DesignOptDialog(QWidget *parent = 0);
    ~DesignOptDialog();
    void setPrintData(int id,QString winId,QString title,QString data);
    void setPrintData(int id,QString winId,QString title,QString data,QString data2);
    int getPrintId(){return mPrintId;}
private slots:
    void on_cancelBtn_clicked();

    void on_OkBtn_clicked();
    void sDelPrint();

private:
    Ui::DesignOptDialog *ui;
    QStandardItemModel *mModel;
    int mPrintId;
    QString mPrintWinId;
    QString mPrintTitle;
    QString mPrintFormatData;
    QString mPrintFormatData2;
    void setupContextMenu();
    void init();

};

#endif // DESIGNOPTDIALOG_H
