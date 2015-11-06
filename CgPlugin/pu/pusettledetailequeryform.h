#ifndef PUSETTLEDETAILEQUERYFORM_H
#define PUSETTLEDETAILEQUERYFORM_H
#include "widget/singlequeryform.h"

class PuSettleDetaileQueryForm : public SingleQueryForm
{
    Q_OBJECT
public:
    explicit PuSettleDetaileQueryForm(QWidget *parent = 0);
    
signals:

private slots:
    void sTableClicked(QString no);
    
};

#endif // PUSETTLEDETAILEQUERYFORM_H
