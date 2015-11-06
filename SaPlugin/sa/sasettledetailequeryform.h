#ifndef SASETTLEDETAILEQUERYFORM_H
#define SASETTLEDETAILEQUERYFORM_H
#include "widget/singlequeryform.h"
class SaSettleDetaileQueryForm : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit SaSettleDetaileQueryForm(QWidget *parent = 0);
    SaSettleDetaileQueryForm(QString bus_type,QWidget *parent = 0);
    
signals:

private slots:
    void sTableClicked(QString no);
    
};

#endif // SASETTLEDETAILEQUERYFORM_H
